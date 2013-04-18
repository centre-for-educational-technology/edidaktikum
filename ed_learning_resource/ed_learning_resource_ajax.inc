<?php

function ed_learning_resource_dynamic_sections($form, &$form_state, $no_js_use = FALSE){
  drupal_set_title(t('Learning Resources'));
  $form['#attached']['css'] = array(drupal_get_path('module', 'ed_learning_resource') . '/ajax.css',);

  $form['#attached']['js'] = array(drupal_get_path('module', 'ed_learning_resource') . '/ajax.js',);

  /*$form['description'] = array(
    '#type' => 'markup',
    '#markup' => '<div>' . t('TESTESTESTESTESTT') . '</div>',
  );*/

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
