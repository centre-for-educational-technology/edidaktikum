<?php

  /**
   * @file
   * ed_learning_resource.pages_default.inc
   */

  /**
   * Implements hook_default_page_manager_handlers().
   */
  function ed_learning_resource_default_page_manager_handlers() {
    $export = array();

    $ed_learning_resource_node_edit_handler = _ed_learning_resource_edit_page_handler();
    $export['node_edit_panel_ed_learning_resource'] = $ed_learning_resource_node_edit_handler;
    $ed_learning_resource_node_view_handler = _ed_learning_resource_view_page_handler();
    $export['node_view_panel_ed_learning_resource'] = $ed_learning_resource_node_view_handler;

    return $export;
  }
  // NODE ADD/EDIT BEGINS
  function _ed_learning_resource_edit_page_handler(){
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_edit_panel_ed_learning_resource';
$handler->task = 'node_edit';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Resource add/edit',
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
            'ed_learning_resource' => 'ed_learning_resource',
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
$display->uuid = '347481cb-a2a4-485a-aee8-eaeecb0b2a3e';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0ea80ae4-a6f3-4353-a16e-c6c730c989cc';
  $pane->panel = 'bottom';
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
  $pane->position = 0;
  $pane->locks = '';
  $pane->uuid = '0ea80ae4-a6f3-4353-a16e-c6c730c989cc';
  $display->content['new-0ea80ae4-a6f3-4353-a16e-c6c730c989cc'] = $pane;
  $display->panels['bottom'][0] = 'new-0ea80ae4-a6f3-4353-a16e-c6c730c989cc';
  $pane = new stdClass();
  $pane->pid = 'new-d3ea2047-db9b-4406-9a65-e0b04d0773da';
  $pane->panel = 'bottom';
  $pane->type = 'form';
  $pane->subtype = 'form';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd3ea2047-db9b-4406-9a65-e0b04d0773da';
  $display->content['new-d3ea2047-db9b-4406-9a65-e0b04d0773da'] = $pane;
  $display->panels['bottom'][1] = 'new-d3ea2047-db9b-4406-9a65-e0b04d0773da';
  $pane = new stdClass();
  $pane->pid = 'new-a726150d-12e3-498d-8d59-aab318f1072e';
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
  $pane->uuid = 'a726150d-12e3-498d-8d59-aab318f1072e';
  $display->content['new-a726150d-12e3-498d-8d59-aab318f1072e'] = $pane;
  $display->panels['left'][0] = 'new-a726150d-12e3-498d-8d59-aab318f1072e';
  $pane = new stdClass();
  $pane->pid = 'new-b22e5ddf-0bb9-496b-be5e-58457da735ee';
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
  $pane->uuid = 'b22e5ddf-0bb9-496b-be5e-58457da735ee';
  $display->content['new-b22e5ddf-0bb9-496b-be5e-58457da735ee'] = $pane;
  $display->panels['left'][1] = 'new-b22e5ddf-0bb9-496b-be5e-58457da735ee';
  $pane = new stdClass();
  $pane->pid = 'new-3f14558c-0a82-4126-848d-4e984931f9b6';
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
  $pane->uuid = '3f14558c-0a82-4126-848d-4e984931f9b6';
  $display->content['new-3f14558c-0a82-4126-848d-4e984931f9b6'] = $pane;
  $display->panels['left'][2] = 'new-3f14558c-0a82-4126-848d-4e984931f9b6';
  $pane = new stdClass();
  $pane->pid = 'new-a8d1474e-e657-4e6a-937b-d5feafbfb869';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_learning_resource_mg';
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
  $pane->uuid = 'a8d1474e-e657-4e6a-937b-d5feafbfb869';
  $display->content['new-a8d1474e-e657-4e6a-937b-d5feafbfb869'] = $pane;
  $display->panels['left'][3] = 'new-a8d1474e-e657-4e6a-937b-d5feafbfb869';
  $pane = new stdClass();
  $pane->pid = 'new-f5ee4e1c-d8b3-40a0-8b0c-1b7a4e7b0342';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_learning_resource_add_req';
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
  $pane->uuid = 'f5ee4e1c-d8b3-40a0-8b0c-1b7a4e7b0342';
  $display->content['new-f5ee4e1c-d8b3-40a0-8b0c-1b7a4e7b0342'] = $pane;
  $display->panels['left'][4] = 'new-f5ee4e1c-d8b3-40a0-8b0c-1b7a4e7b0342';
  $pane = new stdClass();
  $pane->pid = 'new-a455e51d-c6ce-4f9b-b45a-c8dc79430e2a';
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
  $pane->uuid = 'a455e51d-c6ce-4f9b-b45a-c8dc79430e2a';
  $display->content['new-a455e51d-c6ce-4f9b-b45a-c8dc79430e2a'] = $pane;
  $display->panels['right'][0] = 'new-a455e51d-c6ce-4f9b-b45a-c8dc79430e2a';
  $pane = new stdClass();
  $pane->pid = 'new-c070786a-c593-413d-8df5-e229c93e906e';
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
  $pane->uuid = 'c070786a-c593-413d-8df5-e229c93e906e';
  $display->content['new-c070786a-c593-413d-8df5-e229c93e906e'] = $pane;
  $display->panels['right'][1] = 'new-c070786a-c593-413d-8df5-e229c93e906e';
  $pane = new stdClass();
  $pane->pid = 'new-6eb5fc5d-cac9-4053-9199-5590eb5674fc';
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
  $pane->uuid = '6eb5fc5d-cac9-4053-9199-5590eb5674fc';
  $display->content['new-6eb5fc5d-cac9-4053-9199-5590eb5674fc'] = $pane;
  $display->panels['right'][2] = 'new-6eb5fc5d-cac9-4053-9199-5590eb5674fc';
  $pane = new stdClass();
  $pane->pid = 'new-4923c232-2458-462e-975f-4ffe74b83ec4';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_learning_resource_type';
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
  $pane->uuid = '4923c232-2458-462e-975f-4ffe74b83ec4';
  $display->content['new-4923c232-2458-462e-975f-4ffe74b83ec4'] = $pane;
  $display->panels['right'][3] = 'new-4923c232-2458-462e-975f-4ffe74b83ec4';
  $pane = new stdClass();
  $pane->pid = 'new-45e7bfa6-7e98-4e35-ae8e-66eb0873233d';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_learning_resource_language';
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
  $pane->uuid = '45e7bfa6-7e98-4e35-ae8e-66eb0873233d';
  $display->content['new-45e7bfa6-7e98-4e35-ae8e-66eb0873233d'] = $pane;
  $display->panels['right'][4] = 'new-45e7bfa6-7e98-4e35-ae8e-66eb0873233d';
  $pane = new stdClass();
  $pane->pid = 'new-398498c3-e92e-4fc9-9051-27cdb37cbde1';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_learning_resource_date';
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
  $pane->uuid = '398498c3-e92e-4fc9-9051-27cdb37cbde1';
  $display->content['new-398498c3-e92e-4fc9-9051-27cdb37cbde1'] = $pane;
  $display->panels['right'][5] = 'new-398498c3-e92e-4fc9-9051-27cdb37cbde1';
  $pane = new stdClass();
  $pane->pid = 'new-b9a61b66-327c-4069-bd57-544d5abff6eb';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_learning_resource_authors';
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
  $pane->uuid = 'b9a61b66-327c-4069-bd57-544d5abff6eb';
  $display->content['new-b9a61b66-327c-4069-bd57-544d5abff6eb'] = $pane;
  $display->panels['right'][6] = 'new-b9a61b66-327c-4069-bd57-544d5abff6eb';
  $pane = new stdClass();
  $pane->pid = 'new-94fb3c10-99ec-4048-84cf-5319ec188e35';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '94fb3c10-99ec-4048-84cf-5319ec188e35';
  $display->content['new-94fb3c10-99ec-4048-84cf-5319ec188e35'] = $pane;
  $display->panels['right'][7] = 'new-94fb3c10-99ec-4048-84cf-5319ec188e35';
  $pane = new stdClass();
  $pane->pid = 'new-fb2c0137-4787-4e5a-8cd6-3572005d3a98';
  $pane->panel = 'top';
  $pane->type = 'node_group_breadcrumbs';
  $pane->subtype = 'node_group_breadcrumbs';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fb2c0137-4787-4e5a-8cd6-3572005d3a98';
  $display->content['new-fb2c0137-4787-4e5a-8cd6-3572005d3a98'] = $pane;
  $display->panels['top'][0] = 'new-fb2c0137-4787-4e5a-8cd6-3572005d3a98';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;



    return $handler;
  }



  function _ed_learning_resource_view_page_handler() {
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_ed_learning_resource';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Learning Resource',
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
            'ed_learning_resource' => 'ed_learning_resource',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  ),
);
$display = new panels_display();
$display->layout = 'twocol_stacked';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'top' => NULL,
    'right' => array(
      'corner_location' => 'panel',
    ),
    'bottom' => NULL,
    'left' => NULL,
  ),
  'left' => array(
    'style' => 'default',
  ),
  'right' => array(
    'style' => 'rounded_corners',
  ),
);
$display->cache = array();
$display->title = '%node:title';
$display->uuid = 'c7fdf302-eb24-4a49-9d2f-ac5c9f8ead3b';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1772562f-3024-4037-a01b-1e737397a4f4';
  $pane->panel = 'bottom';
  $pane->type = 'node_comment_form';
  $pane->subtype = 'node_comment_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'anon_links' => 0,
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
  $pane->uuid = '1772562f-3024-4037-a01b-1e737397a4f4';
  $display->content['new-1772562f-3024-4037-a01b-1e737397a4f4'] = $pane;
  $display->panels['bottom'][0] = 'new-1772562f-3024-4037-a01b-1e737397a4f4';
  $pane = new stdClass();
  $pane->pid = 'new-81ba9c88-6c4f-42ef-ade4-e9a542d7e958';
  $pane->panel = 'bottom';
  $pane->type = 'node_comments';
  $pane->subtype = 'node_comments';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mode' => '1',
    'comments_per_page' => '10',
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
  $pane->uuid = '81ba9c88-6c4f-42ef-ade4-e9a542d7e958';
  $display->content['new-81ba9c88-6c4f-42ef-ade4-e9a542d7e958'] = $pane;
  $display->panels['bottom'][1] = 'new-81ba9c88-6c4f-42ef-ade4-e9a542d7e958';
  $pane = new stdClass();
  $pane->pid = 'new-2b258397-b17e-4f07-8cd6-ecd8136013a8';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2b258397-b17e-4f07-8cd6-ecd8136013a8';
  $display->content['new-2b258397-b17e-4f07-8cd6-ecd8136013a8'] = $pane;
  $display->panels['left'][0] = 'new-2b258397-b17e-4f07-8cd6-ecd8136013a8';
  $pane = new stdClass();
  $pane->pid = 'new-faad0310-43e5-4277-aa2d-22282cc513cf';
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
  $pane->uuid = 'faad0310-43e5-4277-aa2d-22282cc513cf';
  $display->content['new-faad0310-43e5-4277-aa2d-22282cc513cf'] = $pane;
  $display->panels['left'][1] = 'new-faad0310-43e5-4277-aa2d-22282cc513cf';
  $pane = new stdClass();
  $pane->pid = 'new-7e750ea6-0637-4910-a78d-4eef79622812';
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
  $pane->uuid = '7e750ea6-0637-4910-a78d-4eef79622812';
  $display->content['new-7e750ea6-0637-4910-a78d-4eef79622812'] = $pane;
  $display->panels['right'][0] = 'new-7e750ea6-0637-4910-a78d-4eef79622812';
  $pane = new stdClass();
  $pane->pid = 'new-48b4888a-7871-47cf-9629-8d77e5b10918';
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
  $pane->uuid = '48b4888a-7871-47cf-9629-8d77e5b10918';
  $display->content['new-48b4888a-7871-47cf-9629-8d77e5b10918'] = $pane;
  $display->panels['right'][1] = 'new-48b4888a-7871-47cf-9629-8d77e5b10918';
  $pane = new stdClass();
  $pane->pid = 'new-b432af06-c27b-48ed-a5a9-a771638bd730';
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
  $pane->uuid = 'b432af06-c27b-48ed-a5a9-a771638bd730';
  $display->content['new-b432af06-c27b-48ed-a5a9-a771638bd730'] = $pane;
  $display->panels['right'][2] = 'new-b432af06-c27b-48ed-a5a9-a771638bd730';
  $pane = new stdClass();
  $pane->pid = 'new-1b495c6a-f926-4dcb-b030-c8a60e4a5af6';
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
  $pane->uuid = '1b495c6a-f926-4dcb-b030-c8a60e4a5af6';
  $display->content['new-1b495c6a-f926-4dcb-b030-c8a60e4a5af6'] = $pane;
  $display->panels['right'][3] = 'new-1b495c6a-f926-4dcb-b030-c8a60e4a5af6';
  $pane = new stdClass();
  $pane->pid = 'new-b1bfb519-8007-4780-953a-74c8063845f0';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'b1bfb519-8007-4780-953a-74c8063845f0';
  $display->content['new-b1bfb519-8007-4780-953a-74c8063845f0'] = $pane;
  $display->panels['right'][4] = 'new-b1bfb519-8007-4780-953a-74c8063845f0';
  $pane = new stdClass();
  $pane->pid = 'new-14fbc2ed-c468-45dc-a6ad-b15bb93046a0';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '14fbc2ed-c468-45dc-a6ad-b15bb93046a0';
  $display->content['new-14fbc2ed-c468-45dc-a6ad-b15bb93046a0'] = $pane;
  $display->panels['right'][5] = 'new-14fbc2ed-c468-45dc-a6ad-b15bb93046a0';
  $pane = new stdClass();
  $pane->pid = 'new-f50fe194-7771-42e4-90ec-2c293f4402ca';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_learning_resource_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'list_resource_type',
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'f50fe194-7771-42e4-90ec-2c293f4402ca';
  $display->content['new-f50fe194-7771-42e4-90ec-2c293f4402ca'] = $pane;
  $display->panels['right'][6] = 'new-f50fe194-7771-42e4-90ec-2c293f4402ca';
  $pane = new stdClass();
  $pane->pid = 'new-c4e1c156-b750-4684-b05f-e1d277291d40';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_learning_resource_mg';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'c4e1c156-b750-4684-b05f-e1d277291d40';
  $display->content['new-c4e1c156-b750-4684-b05f-e1d277291d40'] = $pane;
  $display->panels['right'][7] = 'new-c4e1c156-b750-4684-b05f-e1d277291d40';
  $pane = new stdClass();
  $pane->pid = 'new-0c5e6421-d441-4820-a5e1-87f0096f7a15';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_learning_resource_language';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'list_resource_language',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '0c5e6421-d441-4820-a5e1-87f0096f7a15';
  $display->content['new-0c5e6421-d441-4820-a5e1-87f0096f7a15'] = $pane;
  $display->panels['right'][8] = 'new-0c5e6421-d441-4820-a5e1-87f0096f7a15';
  $pane = new stdClass();
  $pane->pid = 'new-61dab973-df4f-4b57-9033-4da34172e8e7';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_learning_resource_authors';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '61dab973-df4f-4b57-9033-4da34172e8e7';
  $display->content['new-61dab973-df4f-4b57-9033-4da34172e8e7'] = $pane;
  $display->panels['right'][9] = 'new-61dab973-df4f-4b57-9033-4da34172e8e7';
  $pane = new stdClass();
  $pane->pid = 'new-5e8bb76e-48b2-45bf-b9f5-0ef0ed6add23';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_learning_resource_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
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
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => 'Time',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '5e8bb76e-48b2-45bf-b9f5-0ef0ed6add23';
  $display->content['new-5e8bb76e-48b2-45bf-b9f5-0ef0ed6add23'] = $pane;
  $display->panels['right'][10] = 'new-5e8bb76e-48b2-45bf-b9f5-0ef0ed6add23';
  $pane = new stdClass();
  $pane->pid = 'new-1bce5e4f-e3fc-4375-8b7a-e9bb6d993fc7';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_learning_resource_add_req';
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
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '1bce5e4f-e3fc-4375-8b7a-e9bb6d993fc7';
  $display->content['new-1bce5e4f-e3fc-4375-8b7a-e9bb6d993fc7'] = $pane;
  $display->panels['right'][11] = 'new-1bce5e4f-e3fc-4375-8b7a-e9bb6d993fc7';
  $pane = new stdClass();
  $pane->pid = 'new-d47cb134-ccd4-4164-b538-c486b16dd7ba';
  $pane->panel = 'right';
  $pane->type = 'node_add_to_collection';
  $pane->subtype = 'node_add_to_collection';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = 'd47cb134-ccd4-4164-b538-c486b16dd7ba';
  $display->content['new-d47cb134-ccd4-4164-b538-c486b16dd7ba'] = $pane;
  $display->panels['right'][12] = 'new-d47cb134-ccd4-4164-b538-c486b16dd7ba';
  $pane = new stdClass();
  $pane->pid = 'new-d8f677f5-e4c9-439b-a555-780ae0627656';
  $pane->panel = 'top';
  $pane->type = 'node_group_breadcrumbs';
  $pane->subtype = 'node_group_breadcrumbs';
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
  $pane->uuid = 'd8f677f5-e4c9-439b-a555-780ae0627656';
  $display->content['new-d8f677f5-e4c9-439b-a555-780ae0627656'] = $pane;
  $display->panels['top'][0] = 'new-d8f677f5-e4c9-439b-a555-780ae0627656';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;

    return $handler;

  }

