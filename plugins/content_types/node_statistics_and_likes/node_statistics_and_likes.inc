<?php

if (module_exists('statistics')) {
  /**
   * Plugin definition.
   */
  $plugin = array(
    'title' => t('eDidaktikum node statistics and likes'),
    'description' => t('Shows statistics and likes count.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'category' => t('Node'),
    'defaults' => array(
    ),
  );
}

/**
 * Render callback.
 */
function edidaktikum_node_statistics_and_likes_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }

  $node = $context->data;

  $node_views_counter = db_select('node_counter', 'nc')
    ->fields('nc', array('totalcount', 'daycount'))
    ->condition('nid', $node->nid)
    ->execute()->fetchAssoc();
  if (!$node_views_counter) {
    $node_views_counter = array('totalcount' => 0, 'daycount' => 0);
  }

  $content['statistics'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('ed-node-statistics'),
    ),
  );

  $content['statistics']['views'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="ed-node-statistics-views">',
    '#markup' => '<i class="fa fa-eye"></i>' . t('@totalcount views (@daycount today)', array('@totalcount' => $node_views_counter['totalcount'], '@daycount' => $node_views_counter['daycount'])),
    '#suffix' => '</div>',
  );

  $likes_count = db_select('ed_node_like', 'enl')
      ->fields('enl', array('uid'))
      ->condition('enl.nid', $node->nid)
      ->countQuery()->execute()->fetchField();

  $content['statistics']['likes'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="ed-node-statistics-likes">',
    '#markup' => '<span class="ed-likes-count">' . t('@count likes', array('@count' => $likes_count)) . '</span>',
    '#suffix' => '</div>',
  );

  if (user_is_logged_in()) {
    drupal_add_js(drupal_get_path('module', 'edidaktikum') . '/js/ed_likes.js', 'file');
    $content['statistics']['likes']['#markup'] = '<a href="#" data-id="' . $node->nid . '"><i class="fa fa-heart"></i></a>' . $content['statistics']['likes']['#markup'];
  } else {
    $content['statistics']['likes']['#markup'] = '<i class="fa fa-heart"></i>' . $content['statistics']['likes']['#markup'];
  }

  $module = 'edidaktikum';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Node statistics');

  $block->content = drupal_render($content);
  return $block;
}

/**
 * Edit form.
 */
function edidaktikum_node_statistics_and_likes_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Edit form submit callback.
 */
function edidaktikum_node_statistics_and_likes_content_type_edit_form_submit($form, &$form_state) {
}
