<?php

if (module_exists('ed_learning_resource')) {
  /**
   * Plugin definition.
   */
  $plugin = array(
    'title' => t('eDidaktikum add node to collection'),
    'description' => t('Provides adding to collection functionality'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'category' => t('Node'),
    'defaults' => array(
    ),
  );
}

/**
 * Render callback.
 */
function ed_collection_node_add_to_collection_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }

  $node = $context->data;

  /*
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
   */
  
  drupal_add_js(drupal_get_path('module', 'ed_collection') . '/js/add_to_collection.js', 'file');
  $modal_markup = '<div id="add-to-collection-modal" class="modal hide fade" tabindex="-1" role="dialog" aria-labelledby="add-to-collection-label" aria-hidden="true">'
    . '<div class="modal-header">'
    . '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">x</button>'
    . '<h3 id="add-to-collection-modal-label">' . t('Add to collection') . '</h3>'
    . '</div>'
    . '<div class="modal-body">'
    . '</div>'
    . '<div class="modal-footer">'
    . '<button class="btn" data-dismiss="modal" aria-hidden="true">' . t('Close') . '</button>'
    . '<button class="btn btn-primary" disabled="disabled">' . t('Add to collection') . '</button>'
    . '</div>'
    . '</div>';
  $content['add_to_collection']['modal'] = array(
    '#type' => 'markup',
    '#markup' => $modal_markup,
  );

  $content['add_to_collection']['link'] = array(
    '#type' => 'markup',
    '#markup' => '<a href="#add-to-collection-modal" data-toggle="modal" data-nid="' . $node->nid . '">' . t('Add to collection') . '</a>',
  );

  $module = 'ed_collection';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Add node to collection');

  $block->content = drupal_render($content);
  return $block;
}

/**
 * Edit form.
 */
function ed_collection_node_add_to_collection_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Edit form submit callback.
 */
function ed_collection_node_add_to_collection_content_type_edit_form_submit($form, &$form_state) {
}

