<?php

/**
 * Plugin definition.
 */
$plugin = [
  'title' => t('Group content paged'),
  'description' => t('Group content paged'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Node'),
  'defaults' => [],
];

/**
 * Render callback.
 */
function ed_subgroup_content_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }

  $node = $context->data;

  if ($node->type !== 'ed_subgroup') {
    return FALSE;
  }

  $content = [];

  //menu_tree_set_path('main-menu', 'clusters');
  $content_nids = _ed_get_group_content($node->nid);
  $nodes = node_load_multiple($content_nids);
  $types = [];
  foreach($nodes as $single){
    $types[] = $single->type;
  }

  if (in_array('ed_task', $types)) {
    array_unshift($types, 'ed_task');
  }
  $types_unique = array_unique($types);
  $options = [
    'attributes' => [],
    'query' => [
      'og_group_ref' => $node->nid,
      'destination' => 'node/'.$node->nid,
    ],
  ];

  // Check if current user is a member of the group
  $is_group_member = og_is_member('node', $node->nid);

  foreach($types_unique as $type){
    $show_link = true;
    if($type!='ed_answer'){
      if($type=='ed_task'){
        if (!ed_task_manager_access('node', $node)) {
          $show_link = false;
        }
      }

      $type_nodes_count = _ed_get_group_content_by_type_count($node->nid, $type);

      $headingmarkup =  _ed_cluster_plural_title_for_group_node_type($type) . ' ('.t('Total') . ': ' . $type_nodes_count . ')';
      if ($show_link) {
        $headingmarkup = l($headingmarkup, _ed_cluster_destination_for_group_node_type($node, $type));
      }

      $content['ed_subgroup_content'][$type]['heading'] = [
        '#type' => 'markup',
        '#prefix' => '<h2 class="' . $type. '">',
        '#markup' => $headingmarkup,
        '#suffix' => '</h2>',
      ];
      // Add new link is only shown to group members
      //if ($is_group_member) {
      //  $node->content['ed_cluster_content'][$type]['heading']['#markup'] .= '<em class="ed-og-add-new">'.l(t('Add new'), 'node/add/'.str_replace('_', '-',$type), $options).'</em>';
      //}
      $last_nodes = _ed_get_last_content_by_type($type, $nodes);
      foreach($last_nodes as $last_node_single){
          $teaser = node_view($last_node_single, 'teaser');
          $content['ed_subgroup_content'][$type][$last_node_single->nid] = $teaser;
      }
    }
  }

  $module = 'ed_subgroup';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Group content paged');

  $block->content = drupal_render($content);
  return $block;
}

/**
 * Edit form.
 */
function ed_subgroup_content_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Edit form submit callback.
 */
function ed_subgroup_content_content_type_edit_form_submit($form, &$form_state) {
}
