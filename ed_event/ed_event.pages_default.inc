<?php
/**
 * @file
 * ed_event.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ed_event_default_page_manager_handlers() {
  $export = array();
  $ed_event_node_edit_handler = _ed_event_node_edit_page_handler();
  $export['node_edit_panel_ed_event'] = $ed_event_node_edit_handler;
  $ed_event_node_view_handler = _ed_event_node_view_page_handler();
  $export['node_view_panel_ed_event'] = $ed_event_node_view_handler;
  return $export;
}

function _ed_event_node_edit_page_handler() {
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_edit_panel_ed_event';
$handler->task = 'node_edit';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Event',
  'no_blocks' => 0,
  'pipeline' => 'standard',
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
            'ed_event' => 'ed_event',
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
$display->uuid = '4e9c128b-43f6-4920-b9dc-eb97554f7dfa';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-724e83bd-436a-495e-b270-55b2003236b5';
  $pane->panel = 'bottom';
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
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = '724e83bd-436a-495e-b270-55b2003236b5';
  $display->content['new-724e83bd-436a-495e-b270-55b2003236b5'] = $pane;
  $display->panels['bottom'][0] = 'new-724e83bd-436a-495e-b270-55b2003236b5';
  $pane = new stdClass();
  $pane->pid = 'new-b6f0d23a-b93e-46b3-a2b9-afe7b1b0ab05';
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
  $pane->uuid = 'b6f0d23a-b93e-46b3-a2b9-afe7b1b0ab05';
  $display->content['new-b6f0d23a-b93e-46b3-a2b9-afe7b1b0ab05'] = $pane;
  $display->panels['left'][0] = 'new-b6f0d23a-b93e-46b3-a2b9-afe7b1b0ab05';
  $pane = new stdClass();
  $pane->pid = 'new-33c5e280-f3bc-459a-9b2b-b35ce3dca615';
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
  $pane->uuid = '33c5e280-f3bc-459a-9b2b-b35ce3dca615';
  $display->content['new-33c5e280-f3bc-459a-9b2b-b35ce3dca615'] = $pane;
  $display->panels['left'][1] = 'new-33c5e280-f3bc-459a-9b2b-b35ce3dca615';
  $pane = new stdClass();
  $pane->pid = 'new-ba9eae7b-a76b-49a2-a938-e27afa2f5152';
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
  $pane->uuid = 'ba9eae7b-a76b-49a2-a938-e27afa2f5152';
  $display->content['new-ba9eae7b-a76b-49a2-a938-e27afa2f5152'] = $pane;
  $display->panels['left'][2] = 'new-ba9eae7b-a76b-49a2-a938-e27afa2f5152';
  $pane = new stdClass();
  $pane->pid = 'new-ad87586e-be3a-48bc-811f-389c1a37e0d9';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_event_field_start';
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
  $pane->uuid = 'ad87586e-be3a-48bc-811f-389c1a37e0d9';
  $display->content['new-ad87586e-be3a-48bc-811f-389c1a37e0d9'] = $pane;
  $display->panels['left'][3] = 'new-ad87586e-be3a-48bc-811f-389c1a37e0d9';
  $pane = new stdClass();
  $pane->pid = 'new-9195d21a-4ff2-40e3-9ecf-c591426f9588';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_event_field_end';
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
  $pane->uuid = '9195d21a-4ff2-40e3-9ecf-c591426f9588';
  $display->content['new-9195d21a-4ff2-40e3-9ecf-c591426f9588'] = $pane;
  $display->panels['left'][4] = 'new-9195d21a-4ff2-40e3-9ecf-c591426f9588';
  $pane = new stdClass();
  $pane->pid = 'new-caf67a40-deb5-4529-9173-fa38dfc7e337';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 5;
  $pane->locks = '';
  $pane->uuid = 'caf67a40-deb5-4529-9173-fa38dfc7e337';
  $display->content['new-caf67a40-deb5-4529-9173-fa38dfc7e337'] = $pane;
  $display->panels['left'][5] = 'new-caf67a40-deb5-4529-9173-fa38dfc7e337';
  $pane = new stdClass();
  $pane->pid = 'new-b9163d6c-817a-42f3-9d9b-47d377a842c7';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'b9163d6c-817a-42f3-9d9b-47d377a842c7';
  $display->content['new-b9163d6c-817a-42f3-9d9b-47d377a842c7'] = $pane;
  $display->panels['left'][6] = 'new-b9163d6c-817a-42f3-9d9b-47d377a842c7';
  $pane = new stdClass();
  $pane->pid = 'new-742516c0-19e4-4f0c-b96a-8bf692594a1f';
  $pane->panel = 'left';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '742516c0-19e4-4f0c-b96a-8bf692594a1f';
  $display->content['new-742516c0-19e4-4f0c-b96a-8bf692594a1f'] = $pane;
  $display->panels['left'][7] = 'new-742516c0-19e4-4f0c-b96a-8bf692594a1f';
  $pane = new stdClass();
  $pane->pid = 'new-0a46f0c8-0b6b-4dfe-a787-1f0bf6ae8c0a';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '0a46f0c8-0b6b-4dfe-a787-1f0bf6ae8c0a';
  $display->content['new-0a46f0c8-0b6b-4dfe-a787-1f0bf6ae8c0a'] = $pane;
  $display->panels['left'][8] = 'new-0a46f0c8-0b6b-4dfe-a787-1f0bf6ae8c0a';
  $pane = new stdClass();
  $pane->pid = 'new-f8ada430-f76b-4f91-8e55-b6ec66fefcf4';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->locks = '';
  $pane->uuid = 'f8ada430-f76b-4f91-8e55-b6ec66fefcf4';
  $display->content['new-f8ada430-f76b-4f91-8e55-b6ec66fefcf4'] = $pane;
  $display->panels['right'][0] = 'new-f8ada430-f76b-4f91-8e55-b6ec66fefcf4';
  $pane = new stdClass();
  $pane->pid = 'new-8180321a-1569-448c-9b04-25dfc7ece524';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_event_field_location';
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
  $pane->uuid = '8180321a-1569-448c-9b04-25dfc7ece524';
  $display->content['new-8180321a-1569-448c-9b04-25dfc7ece524'] = $pane;
  $display->panels['right'][1] = 'new-8180321a-1569-448c-9b04-25dfc7ece524';
  $pane = new stdClass();
  $pane->pid = 'new-64f4749b-4f57-4b03-baf4-e808695152d0';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_event_field_url';
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
  $pane->uuid = '64f4749b-4f57-4b03-baf4-e808695152d0';
  $display->content['new-64f4749b-4f57-4b03-baf4-e808695152d0'] = $pane;
  $display->panels['right'][2] = 'new-64f4749b-4f57-4b03-baf4-e808695152d0';
  $pane = new stdClass();
  $pane->pid = 'new-c624ff51-5fe3-4870-892b-1a97cc70b258';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:og_group_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->locks = '';
  $pane->uuid = 'c624ff51-5fe3-4870-892b-1a97cc70b258';
  $display->content['new-c624ff51-5fe3-4870-892b-1a97cc70b258'] = $pane;
  $display->panels['right'][3] = 'new-c624ff51-5fe3-4870-892b-1a97cc70b258';
  $pane = new stdClass();
  $pane->pid = 'new-feb49865-6f3b-4101-9e9e-4cb62574fcaa';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'feb49865-6f3b-4101-9e9e-4cb62574fcaa';
  $display->content['new-feb49865-6f3b-4101-9e9e-4cb62574fcaa'] = $pane;
  $display->panels['right'][4] = 'new-feb49865-6f3b-4101-9e9e-4cb62574fcaa';
  $pane = new stdClass();
  $pane->pid = 'new-3fdc0192-0102-4fba-899d-aa1ced9b6fc1';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '3fdc0192-0102-4fba-899d-aa1ced9b6fc1';
  $display->content['new-3fdc0192-0102-4fba-899d-aa1ced9b6fc1'] = $pane;
  $display->panels['right'][5] = 'new-3fdc0192-0102-4fba-899d-aa1ced9b6fc1';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;


  return $handler;
}

function _ed_event_node_view_page_handler() {
  $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_ed_event';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 1;
$handler->conf = array(
  'title' => 'Event',
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
            'ed_event' => 'ed_event',
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
$display->uuid = 'b5bd1180-e27d-406d-a4ca-caed244baee5';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-65a79a85-9e1c-4fb0-b6c9-af7abccd5305';
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
  $pane->uuid = '65a79a85-9e1c-4fb0-b6c9-af7abccd5305';
  $display->content['new-65a79a85-9e1c-4fb0-b6c9-af7abccd5305'] = $pane;
  $display->panels['left'][0] = 'new-65a79a85-9e1c-4fb0-b6c9-af7abccd5305';
  $pane = new stdClass();
  $pane->pid = 'new-993d7b4f-350a-454c-9c8a-df9c7d9ecdc3';
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
  $pane->uuid = '993d7b4f-350a-454c-9c8a-df9c7d9ecdc3';
  $display->content['new-993d7b4f-350a-454c-9c8a-df9c7d9ecdc3'] = $pane;
  $display->panels['left'][1] = 'new-993d7b4f-350a-454c-9c8a-df9c7d9ecdc3';
  $pane = new stdClass();
  $pane->pid = 'new-5f9064fc-a8ef-43fb-9179-0a3f79ef7e05';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'term_reference_tree',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5f9064fc-a8ef-43fb-9179-0a3f79ef7e05';
  $display->content['new-5f9064fc-a8ef-43fb-9179-0a3f79ef7e05'] = $pane;
  $display->panels['right'][0] = 'new-5f9064fc-a8ef-43fb-9179-0a3f79ef7e05';
  $pane = new stdClass();
  $pane->pid = 'new-eb858b25-9457-4317-a3ac-968a686f98c7';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_event_field_url';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'url_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '80',
      'nofollow' => 0,
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'eb858b25-9457-4317-a3ac-968a686f98c7';
  $display->content['new-eb858b25-9457-4317-a3ac-968a686f98c7'] = $pane;
  $display->panels['right'][1] = 'new-eb858b25-9457-4317-a3ac-968a686f98c7';
  $pane = new stdClass();
  $pane->pid = 'new-11bc5b8b-f483-4dd8-b3f2-bdf6788e5bdb';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_event_field_location';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '11bc5b8b-f483-4dd8-b3f2-bdf6788e5bdb';
  $display->content['new-11bc5b8b-f483-4dd8-b3f2-bdf6788e5bdb'] = $pane;
  $display->panels['right'][2] = 'new-11bc5b8b-f483-4dd8-b3f2-bdf6788e5bdb';
  $pane = new stdClass();
  $pane->pid = 'new-66ece00e-119e-4552-8f3b-6bd569d401dc';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_event_field_start';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_repeat_rule' => 'show',
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
  $pane->uuid = '66ece00e-119e-4552-8f3b-6bd569d401dc';
  $display->content['new-66ece00e-119e-4552-8f3b-6bd569d401dc'] = $pane;
  $display->panels['right'][3] = 'new-66ece00e-119e-4552-8f3b-6bd569d401dc';
  $pane = new stdClass();
  $pane->pid = 'new-77097ba0-5957-42aa-bd2e-736ebd5c194d';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_event_field_end';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_repeat_rule' => 'show',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '77097ba0-5957-42aa-bd2e-736ebd5c194d';
  $display->content['new-77097ba0-5957-42aa-bd2e-736ebd5c194d'] = $pane;
  $display->panels['right'][4] = 'new-77097ba0-5957-42aa-bd2e-736ebd5c194d';
  $pane = new stdClass();
  $pane->pid = 'new-f17215b9-b41e-4bb5-bf22-32672b89bd5f';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f17215b9-b41e-4bb5-bf22-32672b89bd5f';
  $display->content['new-f17215b9-b41e-4bb5-bf22-32672b89bd5f'] = $pane;
  $display->panels['right'][5] = 'new-f17215b9-b41e-4bb5-bf22-32672b89bd5f';
  $pane = new stdClass();
  $pane->pid = 'new-4e6e5418-02bf-4b70-b063-dca6024e01f8';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '4e6e5418-02bf-4b70-b063-dca6024e01f8';
  $display->content['new-4e6e5418-02bf-4b70-b063-dca6024e01f8'] = $pane;
  $display->panels['right'][6] = 'new-4e6e5418-02bf-4b70-b063-dca6024e01f8';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-eb858b25-9457-4317-a3ac-968a686f98c7';
$handler->conf['display'] = $display;

  return $handler;
}
