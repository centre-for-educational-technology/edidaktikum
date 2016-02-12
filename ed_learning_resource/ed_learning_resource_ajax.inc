<?php


// Get "Category" Vocabulary ID.
function _ed_get_vid() {
  $vocab = taxonomy_vocabulary_machine_name_load('ed_category');
  $vid = $vocab->vid;
  return $vid;
}

function ed_learning_resource_dynamic_sections($form, &$form_state, $no_js_use = FALSE) {

  drupal_set_title(t('Learning Resources'));

  $form['#attached']['css'][] = drupal_get_path('module', 'ed_learning_resource') . '/ajax.css';
  //$form['#attached']['js'] = array(drupal_get_path('module', 'ed_learning_resource') . '/ajax.js',);

  $form['content_sort_select'] = array(
    '#type' => 'select',
    '#options' => drupal_map_assoc(array(t('Latest First'), t('Earliest First'), t('Title'))),
    /*'#ajax' => array(
      'wrapper' => 'selection-fieldset-wrapper',
      'callback' => 'ed_learning_resource_dynamic_sections_select_callback',
    ),*/
  );

  $form['sorting_type_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sort'),
    '#attributes' => array('class' => array('next-button')),
    '#limit_validation_errors' => array(),
    '#validate' => array(),
  );

  if ($no_js_use) {
    unset($form['content_sort_select']['#ajax']);
  }
  $term_reference_tree_path = drupal_get_path('module', 'term_reference_tree');
  $form['category'] = array(
    '#type' => 'checkbox_tree',
    '#title' => t('Category'),
    '#vocabulary' => _ed_get_vid(),
    '#parent_tid' => 0,
    '#value_key' => 'tid',
    '#max_choices' => 999,
    '#leaves_only' => 0,
    '#start_minimized' => FALSE,
    '#depth' => 0,
    '#select_parents' => TRUE,
    '#attached' => array(
      'js' => array($term_reference_tree_path . '/term_reference_tree.js'),
      'css' => array($term_reference_tree_path . '/term_reference_tree.css'),
    ),
    '#attributes' => array('class' => array('field-widget-term-reference-tree')),
    '#element_validate' => array('_term_reference_Tree_widget_validate'),
    '#value' => array(),
    '#filter_view' => '',
    '#max_depth' => '',
    '#field_name' => '',
    '#token_display' => '',
    '#prefix' => '<div id="category-wrapper">',
  );

  $form['content_sort_category'] = array(
    '#type' => 'submit',
    '#value' => t('Sort by Category'),
    '#validate' => array(),
    '#limit_validation_errors' => array(),
    '#suffix' => '</div>',
  );

  $form['selection_fieldset'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div id="selection-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  if( !empty($form_state['values']['category'])) {

    $cat = $form_state['values']['category'];
    $help = array();
    $help = (array_values_recursive($cat));
    $form_state['input'] = array();

    if(!empty($help)) {
      $resources = _ed_get_resources_category($help);
    }
    else{
      form_set_error('selection_fieldset', 'Please select a category');
    }
    if(!empty($resources)) {
      $nodes = node_load_multiple($resources);
      $build = node_view_multiple($nodes);
      $build['pager'] = array(
        '#theme' => 'pager',
        '#weight' => 5,
      );
      $build['pager'] = array('#theme' => 'pager');
      $form['selection_fieldset']['resources'] = $build;

      return $form;
    }
    else{
      $form['selection_fieldset']['resources'] = array(
        '#type' => 'markup',
        '#markup' => '<h3>' . t('Learning resources not found') .'</h3>',
      );

      return $form;
    }

  }

  if( !empty($form_state['values']['content_sort_select'])) {
    $form_state['input'] = array();
    $selection_type = $form_state['values']['content_sort_select'];

    switch($selection_type) {
      case t('Latest First'):
        $resources = _ed_get_resources_date();
        if( !empty( $resources ) ) {
          $nodes = node_load_multiple($resources);
          $build = node_view_multiple($nodes);
          $build['pager'] = array(
            '#theme' => 'pager',
            '#weight' => 5,
          );
          $build['pager'] = array('#theme' => 'pager');
          $form['selection_fieldset']['resources'] = $build;
        }
        break;
      case t('Earliest First'):
        $resources = _ed_get_resources_date_asc();
        if( !empty( $resources ) ) {
          $nodes = node_load_multiple($resources);
          $build = node_view_multiple($nodes);
          $build['pager'] = array(
            '#theme' => 'pager',
            '#weight' => 5,
          );
          $build['pager'] = array('#theme' => 'pager');
          $form['selection_fieldset']['resources'] = $build;
        }
        break;
      case t('Title'):
        $resources = _ed_get_resources_title();
        if( !empty( $resources ) ) {
          $nodes = node_load_multiple($resources);
          $build = node_view_multiple($nodes);
          $build['pager'] = array(
            '#theme' => 'pager',
            '#weight' => 5,
          );
          $build['pager'] = array('#theme' => 'pager');
          $form['selection_fieldset']['resources'] = $build;
        }
        break;
    }
  }
  else {
    $resources = _ed_get_resources_date();
    if( !empty( $resources ) ) {
      $nodes = node_load_multiple($resources);
      $build = node_view_multiple($nodes);
      $build['pager'] = array(
        '#theme' => 'pager',
        '#weight' => 5,
      );
      //$build['pager'] = array('#theme' => 'pager');
      $form['selection_fieldset']['resources'] = $build;
    }
  }

  return $form;

}

function ed_learning_resource_dynamic_sections_submit($form, &$form_state) {

  switch($form_state['triggering_element']['#value']) {
    case t('Sort'):
      $form_state['values']['content_sort_select'] = $form_state['input']['content_sort_select'];
    case t('Sort by Category'):

      $form_state['values']['category'] = $form_state['input']['category'];

    default:
      $form_state['rebuild'] = TRUE;

  }
}


function ed_learning_resource_dynamic_sections_select_callback($form, $form_state) {
  //$form_state['rebuild'] = TRUE;


  return $form['selection_fieldset'];

}


// Database and helper functions.

function _ed_get_resources_date_asc() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', 'ed_learning_resource');
  $query->orderBy('n.created', 'ASC');
  $query = $query->extend('PagerDefault')->limit(2);     // Small number for testing purposes.
  $nids = $query->execute()->fetchCol();

  return $nids;
}
function _ed_get_resources_date() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', 'ed_learning_resource');
  $query->orderBy('n.created', 'DESC');
  $query = $query->extend('PagerDefault')->limit(2);     // Small number for testing purposes.
  $nids = $query->execute()->fetchCol();

  return $nids;
}
function _ed_get_resources_title() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', 'ed_learning_resource');
  $query->orderBy('n.title', 'ASC');
  $query = $query->extend('PagerDefault')->limit(2);     // Small number for testing purposes.
  $nids = $query->execute()->fetchCol();

  return $nids;
}

function _ed_get_resources_category($help) {
  $query = db_select('node', 'n');
  $query->join('field_data_ed_field_category', 'cat', 'n.nid = cat.entity_id');
  $query->fields('n', array('nid'))
        ->condition('type', 'ed_learning_resource')
        ->condition('cat.ed_field_category_tid', $help, "IN");
  $query = $query->extend('PagerDefault')->limit(2);     // Small number for testing purposes.
  $result = $query->execute()->fetchCol();

  return $result;
}

// Get all existing values from a tree type array.
function array_values_recursive($array) {
  $arrayValues = array();
  foreach ($array as $value) {
    if (is_scalar($value) OR is_resource($value)) {
      $arrayValues[] = $value;
    }
    elseif (is_array($value)) {
      $arrayValues = array_merge($arrayValues, array_values_recursive($value));
    }
  }
  return $arrayValues;
}
