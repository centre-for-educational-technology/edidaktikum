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

      $rows []= [
        'data' => [
          'type' => $shared_node_type_name,
          'title' => l($node_title, 'node/' . $node->nid),
          'author' => l(edidaktikum_get_full_name_for_user_account($user), 'user/' . $user->uid),
          'date' => format_date($node->created, 'short'),
        ],
      ];
    }

    $content['pager_table'] = [
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => [
        t('Type'),
        t('Title'),
        t('Author'),
        t('Date')
      ]
    ];
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

/**
 * Menu callback; Retrieve a JSON object containing autocomplete suggestions for existing users.
 */
function ed_cluster_user_autocomplete($string = '') {
  $matches = array();
  if ($string) {
    //$result = db_select('users')->fields('users', array('name'))->condition('name', db_like($string) . '%', 'LIKE')->range(0, 10)->execute();
    $query = db_select('users')
      ->fields('users', array('name'));
    $query->fields('fn', array('ed_field_full_name_value'));
    $query->join('field_data_ed_field_full_name', 'fn', 'users.uid = fn.entity_id');
    $query->condition('fn.ed_field_full_name_value', '%' . db_like($string) . '%', 'LIKE')
      ->range(0, 10);
    $result = $query->execute();
    foreach ($result as $user) {
      $matches[$user->name] = check_plain($user->ed_field_full_name_value);
    }
  }

  drupal_json_output($matches);
}

/**
 * Grouop file listing page handler.
 * @param  object $gnode Group node object
 * @return array         Page according to Form API
 */
function ed_cluster_file_listing_from_group($gnode) {
  $content = [];
  $type = 'ed_file';

  if (node_access('create', $type) && og_is_member('node', $gnode->nid)) {
    $destination = _ed_cluster_destination_for_group_node_type($gnode, $type);

    $type_dashed = str_replace('_', '-', $type);
    $content['add-new-container'] = [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['ed-add-new-node', 'ed-add-new-'.$type_dashed,],
      ],
    ];
    $content['add-new-container']['add-new-link'] = [
      '#type' => 'markup',
      '#markup' => l(t('Add new'), 'node/add/' . $type_dashed,
      [
        'query' => [
          'og_group_ref' => $gnode->nid,
          'destination' => $destination,
        ],
        'attributes' => [
          'class' => 'btn btn-success',
          ]
        ]
      ),
    ];
  }

  if (isset($gnode->ed_g_drive_file[LANGUAGE_NONE]) && is_array($gnode->ed_g_drive_file[LANGUAGE_NONE]) && count($gnode->ed_g_drive_file[LANGUAGE_NONE])) {
    $header = [
      [
        'data' => '',
      ],
      [
        'data' => t('Title'),
      ],
    ];
    $rows = [];

    $content['heading_g_drive'] = [
      '#markup' => '<h3>' . t('Google Drive files') . '</h3>',
    ];

    foreach($gnode->ed_g_drive_file[LANGUAGE_NONE] as $single) {
      $rows[] = [
        'data' => [
          'icon' => '<img src="' . $single['mime']. '" alt="icon">',
          'title' => l($single['name'], $single['url'], [
            'attributes' => [
              'target' => '_blank',
            ],
          ]),
        ],
      ];
    }

    $content['table_g_drive'] = [
      '#theme' => 'table',
      '#attributes' => [
        'class' => ['ed-g-drive-files-table',],
      ],
      '#rows' => $rows,
      '#header' => $header,
    ];
  }

  $header = [
    [
      'data' => t('Title'),
      'field' => 'n.title',
      'sort' => 'asc',
    ],
    [
      'data' => t('Creator'),
    ],
    [
      'data' => t('Changed'),
      'field' => 'n.changed',
      'sort' => 'desc',
    ],
  ];
  $rows = [];

  $content_nids = _ed_get_group_content_by_type_with_table_sort($gnode->nid, $type, $header);

  if ($content_nids && is_array($content_nids) && count($content_nids) > 0) {
    $nodes = node_load_multiple($content_nids);

    foreach($nodes as $node) {
      $creator = user_load($node->uid);
      $rows[] = [
        'data' => [
          'title' => l($node->title, 'node/' . $node->nid),
          'creator' => l(edidaktikum_get_full_name_for_user_account($creator), 'user/' . $creator->uid),
          'changed' => format_date($node->changed, 'short'),
        ],
      ];
    }
  }

  if (!empty($rows)) {
    $content['heading_table'] = [
      '#markup' => '<h3>' . t('Files') . '</h3>',
    ];
    $content['table'] = [
      '#theme' => 'table',
      '#attributes' => [
        'class' => ['ed-files-table',],
      ],
      '#rows' => $rows,
      '#header' => $header,
    ];
    $content['pager'] = ['#theme' => 'pager',];
  }

  return $content;
}
