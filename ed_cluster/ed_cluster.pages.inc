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
      
      $node_title = $node->title;
      if ('ed_aswer' == $node->type) {
        $title = ed_answer_get_answer_title($node);
      }

      $shared_node_type_name = t('content');
      switch ($node->type) {
        case "ed_blog":
          $shared_node_type_name = t('blog post');
          break;
        case "ed_bookmark":
          $shared_node_type_name = t('bookmark');
          break;
        case "ed_event":
          $shared_node_type_name = t('event');
          break;
        case "ed_news":
          $shared_node_type_name = t('news');
          break;
        case "ed_learning_resource":
          $shared_node_type_name = t('learning resource');
          break;
        case "ed_page":
          $shared_node_type_name = t('page');
          break;
        case "ed_forum":
          $shared_node_type_name = t('discussion');
          break;
        case "ed_file":
          $shared_node_type_name = t('file');
          break;
        case "ed_portfolio":
          $shared_node_type_name = t('portfolio');
          break;
        case "ed_task":
          $shared_node_type_name = t('task');
          break;
        case "ed_answer":
          $shared_node_type_name = t('answer');
          break;
      }

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

