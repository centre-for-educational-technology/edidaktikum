<?php
/**
 * @file
 * ed_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ed_news_default_page_manager_handlers() {
  $export = array();
  $ed_news_node_edit_handler = _ed_news_node_edit_page_handler();
  $export['node_edit_panel_ed_news'] = $ed_news_node_edit_handler;
  $ed_news_node_view_handler = _ed_news_node_view_page_handler();
  $export['node_view_panel_ed_news'] = $ed_news_node_view_handler;
  return $export;
}

function _ed_news_node_view_page_handler() {
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 2;
$handler->conf = array(
  'title' => 'News',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'ed_news' => 'ed_news',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  ),
);
$display = new panels_display();
$display->layout = 'twocol_stacked';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'top' => NULL,
    'left' => NULL,
    'right' => NULL,
    'bottom' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '30bb6180-2448-4c8d-86e9-031560956b4f';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ee50e36f-ab44-4092-b598-d8fcaa45c345';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_excerpt';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ee50e36f-ab44-4092-b598-d8fcaa45c345';
  $display->content['new-ee50e36f-ab44-4092-b598-d8fcaa45c345'] = $pane;
  $display->panels['left'][0] = 'new-ee50e36f-ab44-4092-b598-d8fcaa45c345';
  $pane = new stdClass();
  $pane->pid = 'new-463a7d08-9c1d-44db-94ad-b19b243ff941';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '463a7d08-9c1d-44db-94ad-b19b243ff941';
  $display->content['new-463a7d08-9c1d-44db-94ad-b19b243ff941'] = $pane;
  $display->panels['left'][1] = 'new-463a7d08-9c1d-44db-94ad-b19b243ff941';
  $pane = new stdClass();
  $pane->pid = 'new-183642c9-6cf7-4f73-ac6a-f4b2cd5036ee';
  $pane->panel = 'right';
  $pane->type = 'node_author';
  $pane->subtype = 'node_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 1,
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '183642c9-6cf7-4f73-ac6a-f4b2cd5036ee';
  $display->content['new-183642c9-6cf7-4f73-ac6a-f4b2cd5036ee'] = $pane;
  $display->panels['right'][0] = 'new-183642c9-6cf7-4f73-ac6a-f4b2cd5036ee';
  $pane = new stdClass();
  $pane->pid = 'new-70f94782-02e2-41f1-be58-9147e77c8626';
  $pane->panel = 'right';
  $pane->type = 'node_created';
  $pane->subtype = 'node_created';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'long',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '70f94782-02e2-41f1-be58-9147e77c8626';
  $display->content['new-70f94782-02e2-41f1-be58-9147e77c8626'] = $pane;
  $display->panels['right'][1] = 'new-70f94782-02e2-41f1-be58-9147e77c8626';
  $pane = new stdClass();
  $pane->pid = 'new-48c4f402-78fa-41f1-8f48-67751e7a94fe';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:og_group_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '48c4f402-78fa-41f1-8f48-67751e7a94fe';
  $display->content['new-48c4f402-78fa-41f1-8f48-67751e7a94fe'] = $pane;
  $display->panels['right'][2] = 'new-48c4f402-78fa-41f1-8f48-67751e7a94fe';
  $pane = new stdClass();
  $pane->pid = 'new-2b58f896-5c72-4f7a-a6a0-13fee081c820';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_to_group_member';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2b58f896-5c72-4f7a-a6a0-13fee081c820';
  $display->content['new-2b58f896-5c72-4f7a-a6a0-13fee081c820'] = $pane;
  $display->panels['right'][3] = 'new-2b58f896-5c72-4f7a-a6a0-13fee081c820';
  $pane = new stdClass();
  $pane->pid = 'new-256f75e8-3c22-41ea-8a7a-8433975da194';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_tags';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '256f75e8-3c22-41ea-8a7a-8433975da194';
  $display->content['new-256f75e8-3c22-41ea-8a7a-8433975da194'] = $pane;
  $display->panels['right'][4] = 'new-256f75e8-3c22-41ea-8a7a-8433975da194';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;


	return $handler;
}

function _ed_news_node_edit_page_handler() {
 $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_edit_panel_ed_news';
$handler->task = 'node_edit';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 1;
$handler->conf = array(
  'title' => 'News',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
  'access' => array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'ed_news' => 'ed_news',
          ),
        ),
        'context' => 'argument_node_edit_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  ),
);
$display = new panels_display();
$display->layout = 'twocol_stacked';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'top' => NULL,
    'left' => NULL,
    'right' => NULL,
    'bottom' => NULL,
  ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '35d14526-01fe-4c84-8e5d-3ed7c8b928f9';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2f1da98c-60e3-42e9-94ed-b36fff951362';
  $pane->panel = 'left';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f1da98c-60e3-42e9-94ed-b36fff951362';
  $display->content['new-2f1da98c-60e3-42e9-94ed-b36fff951362'] = $pane;
  $display->panels['left'][0] = 'new-2f1da98c-60e3-42e9-94ed-b36fff951362';
  $pane = new stdClass();
  $pane->pid = 'new-e4092675-47b6-4b1c-8f4a-9ac66fa7fc24';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_excerpt';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e4092675-47b6-4b1c-8f4a-9ac66fa7fc24';
  $display->content['new-e4092675-47b6-4b1c-8f4a-9ac66fa7fc24'] = $pane;
  $display->panels['left'][1] = 'new-e4092675-47b6-4b1c-8f4a-9ac66fa7fc24';
  $pane = new stdClass();
  $pane->pid = 'new-3aee5951-f1d1-4b1f-be36-679f36547b90';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3aee5951-f1d1-4b1f-be36-679f36547b90';
  $display->content['new-3aee5951-f1d1-4b1f-be36-679f36547b90'] = $pane;
  $display->panels['left'][2] = 'new-3aee5951-f1d1-4b1f-be36-679f36547b90';
  $pane = new stdClass();
  $pane->pid = 'new-3855b807-e0e1-45c7-accf-421f7e27cd13';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3855b807-e0e1-45c7-accf-421f7e27cd13';
  $display->content['new-3855b807-e0e1-45c7-accf-421f7e27cd13'] = $pane;
  $display->panels['left'][3] = 'new-3855b807-e0e1-45c7-accf-421f7e27cd13';
  $pane = new stdClass();
  $pane->pid = 'new-bb9fca4c-321c-4cfc-b8b6-cbe630f2f27a';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:group_content_access';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'bb9fca4c-321c-4cfc-b8b6-cbe630f2f27a';
  $display->content['new-bb9fca4c-321c-4cfc-b8b6-cbe630f2f27a'] = $pane;
  $display->panels['left'][4] = 'new-bb9fca4c-321c-4cfc-b8b6-cbe630f2f27a';
  $pane = new stdClass();
  $pane->pid = 'new-a57f17ad-fb95-4c44-8979-7478c01ada36';
  $pane->panel = 'left';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a57f17ad-fb95-4c44-8979-7478c01ada36';
  $display->content['new-a57f17ad-fb95-4c44-8979-7478c01ada36'] = $pane;
  $display->panels['left'][5] = 'new-a57f17ad-fb95-4c44-8979-7478c01ada36';
  $pane = new stdClass();
  $pane->pid = 'new-029f5ed3-8165-4e42-9f0b-a6c90acbe626';
  $pane->panel = 'left';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '029f5ed3-8165-4e42-9f0b-a6c90acbe626';
  $display->content['new-029f5ed3-8165-4e42-9f0b-a6c90acbe626'] = $pane;
  $display->panels['left'][6] = 'new-029f5ed3-8165-4e42-9f0b-a6c90acbe626';
  $pane = new stdClass();
  $pane->pid = 'new-359ba692-2431-4ff3-844c-eb2e99c41eac';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '359ba692-2431-4ff3-844c-eb2e99c41eac';
  $display->content['new-359ba692-2431-4ff3-844c-eb2e99c41eac'] = $pane;
  $display->panels['right'][0] = 'new-359ba692-2431-4ff3-844c-eb2e99c41eac';
  $pane = new stdClass();
  $pane->pid = 'new-27c47974-f356-4150-b976-d58feee205ad';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:og_group_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '27c47974-f356-4150-b976-d58feee205ad';
  $display->content['new-27c47974-f356-4150-b976-d58feee205ad'] = $pane;
  $display->panels['right'][1] = 'new-27c47974-f356-4150-b976-d58feee205ad';
  $pane = new stdClass();
  $pane->pid = 'new-1bef597a-613c-4173-96a7-081ae0b1b539';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_to_group_member';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1bef597a-613c-4173-96a7-081ae0b1b539';
  $display->content['new-1bef597a-613c-4173-96a7-081ae0b1b539'] = $pane;
  $display->panels['right'][2] = 'new-1bef597a-613c-4173-96a7-081ae0b1b539';
  $pane = new stdClass();
  $pane->pid = 'new-a9d34ce5-b20c-41a1-a06f-a72775808b12';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_tags';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a9d34ce5-b20c-41a1-a06f-a72775808b12';
  $display->content['new-a9d34ce5-b20c-41a1-a06f-a72775808b12'] = $pane;
  $display->panels['right'][3] = 'new-a9d34ce5-b20c-41a1-a06f-a72775808b12';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;

  return $handler;
}

