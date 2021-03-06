<?php

/**
 * ed_learning_resource.views_default.inc
 */

/**
 * Implements hook_views_default_views():
 */
function ed_learning_resource_views_default_views() {
  $views = array();
  $ed_learning_resource_items_view = _ed_learning_resource_items_view();
  $views['ed_learning_resource_items'] = $ed_learning_resource_items_view;
  return $views;
}

function _ed_learning_resource_items_view() {
  $tax_ids = _ed_learning_resource_get_methodical_and_practice_tax_ids();


  $view = new view();
  $view->name = 'ed_learning_resource_items';
  $view->description = 'Learning Resources to be included in material type Video';
  $view->tag = 'edidaktikum';
  $view->base_table = 'node';
  $view->human_name = 'eDidaktikum Learning Resources to be included in material type Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
      'ed_learning_resource' => 'ed_learning_resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Õppematerjali tüüp (ed_learning_resource_type) */
  $handler->display->display_options['filters']['ed_learning_resource_type_value']['id'] = 'ed_learning_resource_type_value';
  $handler->display->display_options['filters']['ed_learning_resource_type_value']['table'] = 'field_data_ed_learning_resource_type';
  $handler->display->display_options['filters']['ed_learning_resource_type_value']['field'] = 'ed_learning_resource_type_value';
  $handler->display->display_options['filters']['ed_learning_resource_type_value']['value'] = array(
      $tax_ids['methodical_resource_tax_id'] => $tax_ids['methodical_resource_tax_id'],
      $tax_ids['best_practice_tax_id'] => $tax_ids['best_practice_tax_id'],
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
      'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['ed_learning_resource_items'] = array(
      t('Master'),
      t('more'),
      t('Apply'),
      t('Reset'),
      t('Sort by'),
      t('Asc'),
      t('Desc'),
      t('Items per page'),
      t('- All -'),
      t('Offset'),
      t('« first'),
      t('‹ previous'),
      t('next ›'),
      t('last »'),
      t('author'),
      t('Entity Reference'),
  );

  return $view;
}

