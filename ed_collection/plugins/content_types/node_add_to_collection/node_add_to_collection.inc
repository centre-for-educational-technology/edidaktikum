<?php

if (module_exists('ed_learning_resource')) {
  /**
   * Plugin definition.
   */
  $plugin = array(
    'title' => t('eDidaktikum add node to or remove node from collection'),
    'description' => t('Provides adding to and removing from collection functionality'),
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

  

  $current_collections = ed_collection_learning_resource_collections($node->nid);
  $potential_collections = ed_collection_user_collections();

  $can_add = count($current_collections) < count($potential_collections);
  $can_remove = count($current_collections) > 0;

  if ($can_add) {
    drupal_add_js(drupal_get_path('module', 'ed_collection') . '/js/add_to_collections.js', 'file');
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
      '#markup' => '<a href="#add-to-collection-modal" data-toggle="modal" data-nid="' . $node->nid . '"><i class="fa fa-plus-square-o"></i> ' . t('Add to collection') . '</a>',
    );
  }

  if ($can_remove) {
      drupal_add_js(drupal_get_path('module', 'ed_collection') . '/js/remove_from_collection.js', 'file');
      $modal_markup = '<div id="remove-from-collection-modal" class="modal hide fade" tabindex="-1" role="dialog" aria-labelledby="remove-from-collection-label" aria-hidden="true">'
      . '<div class="modal-header">'
      . '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">x</button>'
      . '<h3 id="remove-from-collection-modal-label">' . t('Remove from collection') . '</h3>'
      . '</div>'
      . '<div class="modal-body">'
      . '</div>'
      . '<div class="modal-footer">'
      . '<button class="btn" data-dismiss="modal" aria-hidden="true">' . t('Close') . '</button>'
      . '<button class="btn btn-primary" disabled="disabled">' . t('Remove from collection') . '</button>'
      . '</div>'
      . '</div>';
    $content['remove_from_collection']['modal'] = array(
      '#type' => 'markup',
      '#markup' => $modal_markup,
    );
    
    $content['remove_from_collection']['link'] = array(
      '#type' => 'markup',
      '#markup' => '<a href="#remove-from-collection-modal" data-toggle="modal" data-nid="' . $node->nid . '"><i class="fa fa-plus-square-o"></i> ' . t('Remove from collection') . '</a>',
    );
  }

  

  $module = 'ed_collection';
  $block = new stdClass();
  $block->module = $module;

  if (ed_collection_teacher_or_admin_is_logged_in()) {
    $block->title = t('Collection');
    $block->content = drupal_render($content);
  }

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

