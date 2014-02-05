<?php

/**
 * @file
 * Page callbacks for ed_learning_resource module.
 */

function ed_learning_resource_type_listing($type) {
  menu_tree_set_path('main-menu', 'resources');
  $content = array();
  
  // Need to check if that belongs to types
  $term = taxonomy_term_load($type);

  if (!($term && 'ed_learning_resource_type_voc' == $term->vocabulary_machine_name)) {
    return $content;
  }

  $content['recources-by-type'] = array(
    '#type' => 'markup',
    '#markup' => t('Learning resources by type: @type', array('@type' => $term->name)),
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
  );
  
  $query = db_select('node', 'n')
    ->extend('PagerDefault') 
    ->limit(ed_get_paging_nr());
  $query->join('field_data_ed_learning_resource_type', 'lrt', 'n.nid = lrt.entity_id AND lrt.ed_learning_resource_type_value = :type', array(':type' => $type));
  $query->fields('n', array('nid'))
    ->condition('n.status', 1)
    ->condition('n.type', 'ed_learning_resource')
    ->addTag('node_access')
    ->orderBy('n.created', 'DESC');

  $nids = $query->execute()->fetchCol();
  
  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);
    $build = node_view_multiple($nodes);
    $build['pager'] = array(
      '#theme' => 'pager',
      '#weight' => 5,
    );
    $content['resources'] = $build;
  }

  return $content;
}

function ed_learning_resource_language_listing($language) {
  menu_tree_set_path('main-menu', 'resources');
  $content = array();

  $term = taxonomy_term_load($language);

  if (!($term && 'ed_learning_resource_language_voc' == $term->vocabulary_machine_name)) {
    return $content;
  }

  $content['recources-by-language'] = array(
    '#type' => 'markup',
    '#markup' => t('Learning resources by language: @language', array('@language' => $term->name)),
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
  );

  $query = db_select('node', 'n')
    ->extend('PagerDefault') 
    ->limit(ed_get_paging_nr());
  $query->join('field_data_ed_learning_resource_language', 'lrt', 'n.nid = lrt.entity_id AND lrt.ed_learning_resource_language_value = :language', array(':language' => $language));
  $query->fields('n', array('nid'))
    ->condition('n.status', 1)
    ->condition('n.type', 'ed_learning_resource')
    ->addTag('node_access')
    ->orderBy('n.created', 'DESC');

  $nids = $query->execute()->fetchCol();
  
  if (!empty($nids)) {
    $nodes = node_load_multiple($nids);
    $build = node_view_multiple($nodes);
    $build['pager'] = array(
      '#theme' => 'pager',
      '#weight' => 5,
    );
    $content['resources'] = $build;
  }

  return $content;
}

