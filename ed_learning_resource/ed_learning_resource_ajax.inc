<?php
function _ed_get_vid(){
  $vocab = taxonomy_vocabulary_machine_name_load('ed_category');
  $vid = $vocab->vid;
  return $vid;
}

/*
function ed_learning_resource_block_view($delta = '') {
  $block['subject'] = t('Filter by Category');
  $block['content'] = drupal_render(drupal_get_form('test'));
  return $block;
}*/
/*
function test($form, &$form_state){
  $form['#submit'][] = 'test_submit';
  $term_reference_tree_path = drupal_get_path('module', 'term_reference_tree');
  $form['category'] = array(
    '#type' => 'checkbox_tree',
    '#title' => t(''),
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


  );

  $form['content_sort_category'] = array(
    '#type' => 'submit',
    '#value' => t('Sort by Category'),
    '#validate' => array(),
  );


  if( !empty($form_state['values']['category'])) {
    $cat = $form_state['values']['category'];
    $help = array();
    $help = array_values_recursive($cat);
    $form_state['input'] = array();


    if(!empty($help)){
      $resources = _ed_get_resources_category($help);
    }
    else{
      form_set_error('selection_fieldset', 'Please select a category');
    }
    if(!empty($resources)){
      $nodes = node_load_multiple($resources);
      $build = node_view_multiple($nodes);
      $build['pager'] = array(
        '#theme' => 'pager',
        '#weight' => 5,
      );
      $form['selection_fieldset']['resources'] = $build;
    }
    else{
      $form['selection_fieldset']['resources'] = array(
        '#type' => 'markup',
        '#markup' => '<h3>' . t('Learning resources not found') .'</h3>',
      );
    }
    //print_r($resources);
    return $form;
  }


  return $form;

}

function test_submit($form, &$form_state) {
  switch($form_state['triggering_element']['#value']) {
    case t('Sort'):
      $form_state['values']['content_sort_select'] = $form_state['input']['content_sort_select'];
    case t('Sort by Category'):
      error_log('k2i jala');
      $form_state['values']['category'] = $form_state['input']['category'];
    default:
      $form_state['rebuild'] = TRUE;
  }
}*/

function ed_learning_resource_dynamic_sections($form, &$form_state, $no_js_use = FALSE){
  drupal_set_title(t('Learning Resources'));
  $form['#attached']['css'] = array(drupal_get_path('module', 'ed_learning_resource') . '/ajax.css',);

  $form['#attached']['js'] = array(drupal_get_path('module', 'ed_learning_resource') . '/ajax.js',);



  $form['content_sort_select'] = array(
    '#type' => 'select',
    '#title' => t('Sort By'),
    '#options' => drupal_map_assoc(array(t('Latest First'), t('Earliest First'), t('Title'), t('Likes'))),
    '#ajax' => array(
      'wrapper' => 'selection-fieldset-wrapper',
      'callback' => 'ed_learning_resource_dynamic_sections_select_callback',
    ),
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
    '#suffix' => '</div>',
  );

  $form['content_sort_category'] = array(
    '#type' => 'submit',
    '#value' => t('Sort by Category'),
    '#validate' => array(),
    '#prefix' => '<div id="category-wrapper-submit">',
    '#suffix' => '</div>',
  );


  if( !empty($form_state['values']['category'])) {
    $cat = $form_state['values']['category'];
    $help = array();
    $help = (array_values_recursive($cat));
    $form_state['input'] = array();


    if(!empty($help)){
      $resources = _ed_get_resources_category($help);
    }
    else{
      form_set_error('selection_fieldset', 'Please select a category');
    }
    if(!empty($resources)){
      $nodes = node_load_multiple($resources);
      $build = node_view_multiple($nodes);
      $build['pager'] = array(
        '#theme' => 'pager',
        '#weight' => 5,
      );
      $form['selection_fieldset']['resources'] = $build;
    }
    else{
      $form['selection_fieldset']['resources'] = array(
        '#type' => 'markup',
        '#markup' => '<h3>' . t('Learning resources not found') .'</h3>',
      );
    }
    //print_r($resources);
    return $form;
  }
  $form['selection_fieldset'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div id="selection-fieldset-wrapper">',
    '#suffix' => '</div>',
  );



  if( !empty($form_state['values']['content_sort_select']) ) {
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
          $form['selection_fieldset']['resources'] = $build;
        }
        break;
      case t('Likes'):
        $form['selection_fieldset']['resources'] = array(
          '#type' => 'markup',
          '#markup' => '<h3>' . t('Functionality doesn\'t exist yet') . '</h2>',
        );
        break;
    }
  }
  else{
    $resources = _ed_get_resources_date();
    if( !empty( $resources ) ) {
      $nodes = node_load_multiple($resources);
      $build = node_view_multiple($nodes);
      $build['pager'] = array(
        '#theme' => 'pager',
        '#weight' => 5,
      );
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
      error_log('k2i jala22222');
      $form_state['values']['category'] = $form_state['input']['category'];
    default:
      $form_state['rebuild'] = TRUE;
  }
}

function ed_learning_resource_dynamic_sections_select_callback($form, $form_state) {
  return $form['selection_fieldset'];
}
function _ed_get_resources_date_asc() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', 'ed_learning_resource');
  $query->orderBy('n.created', 'ASC');
  $nids = $query->execute()->fetchCol();

  return $nids;
}
function _ed_get_resources_date() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', 'ed_learning_resource');
  $query->orderBy('n.created', 'DESC');
  $nids = $query->execute()->fetchCol();

  return $nids;
}
function _ed_get_resources_title(){
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', 'ed_learning_resource');
  $query->orderBy('n.title', 'ASC');
  $nids = $query->execute()->fetchCol();

  return $nids;
}

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

function _ed_get_resources_category($help){
  $query = db_select('node', 'n');
  $query->join('field_data_ed_field_category', 'cat', 'n.nid = cat.entity_id');
  $query->fields('n', array('nid'))
        ->condition('type', 'ed_learning_resource')
        ->condition('cat.ed_field_category_tid', $help, "IN");

  $result = $query->execute()->fetchCol();

  return $result;
}
