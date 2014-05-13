<?php

/**
 * @file
 * Page callbacks for ed_cluster module.
 */

/**
 * Shows shaed with me dashboard page.
 */
function ed_cluster_to_group_member_page() {
  menu_tree_set_path('main-menu', 'dashboard');

  $content = array();

  $account = $GLOBALS['user'];
  $query = db_select('node', 'n')
    ->extend('PagerDefault')
    ->limit(ed_get_paging_nr());
  $query->join('field_data_ed_field_to_group_member', 'tgm', 'n.nid = tgm.entity_id');
  $query->fields('n', array('nid'))
    ->addTag('node_access')
    ->condition('tgm.ed_field_to_group_member_target_id', $account->uid)
    ->orderBy('n.created', 'DESC');

  $nids = $query->execute()->fetchCol();

  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);
  }

  if (!empty($nodes)) {
    foreach ($nodes as $node) {
      $user = user_load($node->uid);
      
      $node_title = edidaktikum_get_node_title($node);
      $shared_node_type_name = edidaktikum_get_node_type_name($node->type);

      $rows[] = array(
        'data' => t('!user shared @node_type_name !node @time', array(
          '!user' => l(edidaktikum_get_full_name_for_user_account($user), 'user/' . $user->uid),
          '@node_type_name' => $shared_node_type_name,
          '!node' => l($node_title, 'node/' . $node->nid),
          '@time' => format_date($node->created, 'full') ,
        )),
      );
    }

    $content['nodes-listing']['list'] = array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#attributes' => array(
        'class' => array('ed-shared-nodes-listing'),
      ),
      '#items' => $rows,
    );
    $content['nodes-listing']['pager'] = array(
      '#theme' => 'pager',
      '#weight' => 5,
    );
  }

  return $content;
}

/**
 * Serves JSON array of events for calendar.
 *
 * @param $gnode
 *   Group node
 *
 * @return JSON encoded string
 */
function ed_cluster_get_group_events_ajax($gnode) {
  $query = db_select('node', 'n');
  $query->join('og_membership', 'ogm', "n.nid = ogm.etid AND ogm.entity_type = 'node'");
  $query->fields('n', array('nid'))
    ->condition('n.status', 1)
    ->condition('n.type', 'ed_event')
    ->condition('ogm.gid', $gnode->nid)
    ->condition('n.nid', $gnode->nid, '!=')
    ->addTag('node_access')
    ->range()
    ->orderBy('n.created', 'DESC');
  $events = $query->execute()->fetchCol();

  $results = array();
  foreach ($events as $event_nid) {
    $event = node_load($event_nid);
    $excerpt_field = field_get_items('node', $event, 'ed_field_excerpt');
    $start_field = field_get_items('node', $event, 'ed_event_field_start');
    $end_field = field_get_items('node', $event, 'ed_event_field_end');
    $results[] = array(
      "date" => $start_field[0]['value'] . "000",
      "enddate" => $end_field[0]['value'] . "000",
      "type" => $event->type,
      "title" => $event->title,
      "description" => $excerpt_field[0]['safe_value'],
      "url" => 'node/'.$event->nid,
    );
  }
  drupal_json_output($results);
}

