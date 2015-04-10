<?php
/**
 * @file
 * ed_subgroup.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ed_subgroup_default_page_manager_handlers() {
  $export = array();
  $ed_subgroup_node_view_handler = _ed_subgroup_node_view_page_handler();
  $export['node_view_panel_ed_subgroup'] = $ed_subgroup_node_view_handler;
  return $export;
}
function _ed_subgroup_node_view_page_handler(){
  $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_ed_subgroup';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 11;
$handler->conf = array(
  'title' => 'Subgroup',
  'no_blocks' => 0,
  'pipeline' => 'mlpanels_renderer_standard',
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
            'ed_subgroup' => 'ed_subgroup',
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
$display->uuid = 'bbd8387d-4d41-42be-9cd7-b631a831d28a';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a42e5147-3e76-4c64-9284-74db08b352cb';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_excerpt';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a42e5147-3e76-4c64-9284-74db08b352cb';
  $display->content['new-a42e5147-3e76-4c64-9284-74db08b352cb'] = $pane;
  $display->panels['left'][0] = 'new-a42e5147-3e76-4c64-9284-74db08b352cb';
  $pane = new stdClass();
  $pane->pid = 'new-11ee5af5-bc39-48e9-b4a0-941ee1afa8a4';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_content';
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
    'override_title' => 1,
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
  $pane->uuid = '11ee5af5-bc39-48e9-b4a0-941ee1afa8a4';
  $display->content['new-11ee5af5-bc39-48e9-b4a0-941ee1afa8a4'] = $pane;
  $display->panels['left'][1] = 'new-11ee5af5-bc39-48e9-b4a0-941ee1afa8a4';
  $pane = new stdClass();
  $pane->pid = 'new-320939b0-650a-4d4e-a304-b3773005c56a';
  $pane->panel = 'left';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:ed_subgroup_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
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
  $pane->uuid = '320939b0-650a-4d4e-a304-b3773005c56a';
  $display->content['new-320939b0-650a-4d4e-a304-b3773005c56a'] = $pane;
  $display->panels['left'][2] = 'new-320939b0-650a-4d4e-a304-b3773005c56a';
  $pane = new stdClass();
  $pane->pid = 'new-b27d0f8c-1246-470b-8910-feca52b97abf';
  $pane->panel = 'right';
  $pane->type = 'node_statistics_and_likes';
  $pane->subtype = 'node_statistics_and_likes';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = 'b27d0f8c-1246-470b-8910-feca52b97abf';
  $display->content['new-b27d0f8c-1246-470b-8910-feca52b97abf'] = $pane;
  $display->panels['right'][0] = 'new-b27d0f8c-1246-470b-8910-feca52b97abf';
  $pane = new stdClass();
  $pane->pid = 'new-9cac6edd-18d7-4506-8db8-11a6fec0c701';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->uuid = '9cac6edd-18d7-4506-8db8-11a6fec0c701';
  $display->content['new-9cac6edd-18d7-4506-8db8-11a6fec0c701'] = $pane;
  $display->panels['right'][1] = 'new-9cac6edd-18d7-4506-8db8-11a6fec0c701';
  $pane = new stdClass();
  $pane->pid = 'new-e6279d0c-43fe-4117-a691-7e9310a6415c';
  $pane->panel = 'right';
  $pane->type = 'node_create_links';
  $pane->subtype = 'node_create_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'types' => array(
      'ed_blog' => 'ed_blog',
      'ed_bookmark' => 'ed_bookmark',
      'ed_event' => 'ed_event',
      'ed_forum' => 'ed_forum',
      'ed_learning_resource' => 'ed_learning_resource',
      'ed_news' => 'ed_news',
      'ed_task' => 'ed_task',
    ),
    'field_name' => 'og_group_ref',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Add New:',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e6279d0c-43fe-4117-a691-7e9310a6415c';
  $display->content['new-e6279d0c-43fe-4117-a691-7e9310a6415c'] = $pane;
  $display->panels['right'][2] = 'new-e6279d0c-43fe-4117-a691-7e9310a6415c';
  $pane = new stdClass();
  $pane->pid = 'new-c19caca0-4d6c-4b71-ac3c-b81b83aff81a';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'og_members-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
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
  $pane->uuid = 'c19caca0-4d6c-4b71-ac3c-b81b83aff81a';
  $display->content['new-c19caca0-4d6c-4b71-ac3c-b81b83aff81a'] = $pane;
  $display->panels['right'][3] = 'new-c19caca0-4d6c-4b71-ac3c-b81b83aff81a';
  $pane = new stdClass();
  $pane->pid = 'new-0ab3b98c-9ff4-4b79-8593-19bf3df5adac';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:group_group';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'og_group_subscribe',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'field_name' => '0',
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
  $pane->uuid = '0ab3b98c-9ff4-4b79-8593-19bf3df5adac';
  $display->content['new-0ab3b98c-9ff4-4b79-8593-19bf3df5adac'] = $pane;
  $display->panels['right'][4] = 'new-0ab3b98c-9ff4-4b79-8593-19bf3df5adac';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-a42e5147-3e76-4c64-9284-74db08b352cb';
$handler->conf['display'] = $display;

  return $handler;
}