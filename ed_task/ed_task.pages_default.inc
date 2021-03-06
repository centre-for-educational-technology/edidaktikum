<?php

/**
 * Implements hook_default_page_manager_handlers().
 */
function ed_task_default_page_manager_handlers() {
  $export = array();

  $ed_task_node_edit_handler = _ed_task_edit_page_handler();
  $export['node_edit_panel_ed_task'] = $ed_task_node_edit_handler;

  $ed_task_node_view_handler = _ed_task_view_page_handler();
  $export['node_view_panel_ed_task'] = $ed_task_node_view_handler;

  return $export;
}

function _ed_task_edit_page_handler(){
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_ed_task';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Task add/edit',
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
              'ed_task' => 'ed_task',
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
  $display->uuid = '3afa48d2-22f2-4f1f-aef4-76c6b51fa5c7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_ed_task';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6e4112a8-7f42-453c-8585-be543679052d';
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
  $pane->uuid = '6e4112a8-7f42-453c-8585-be543679052d';
  $display->content['new-6e4112a8-7f42-453c-8585-be543679052d'] = $pane;
  $display->panels['bottom'][0] = 'new-6e4112a8-7f42-453c-8585-be543679052d';
  $pane = new stdClass();
  $pane->pid = 'new-3b6c1b7d-8f96-4063-a520-239b6f1535cf';
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
  $pane->uuid = '3b6c1b7d-8f96-4063-a520-239b6f1535cf';
  $display->content['new-3b6c1b7d-8f96-4063-a520-239b6f1535cf'] = $pane;
  $display->panels['left'][0] = 'new-3b6c1b7d-8f96-4063-a520-239b6f1535cf';
  $pane = new stdClass();
  $pane->pid = 'new-2823d0b1-f3a7-4391-ae4f-09ffcd9bd882';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2823d0b1-f3a7-4391-ae4f-09ffcd9bd882';
  $display->content['new-2823d0b1-f3a7-4391-ae4f-09ffcd9bd882'] = $pane;
  $display->panels['left'][1] = 'new-2823d0b1-f3a7-4391-ae4f-09ffcd9bd882';
  $pane = new stdClass();
  $pane->pid = 'new-8228e046-82bb-4b4f-bb5b-325d2b373f46';
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
  $pane->css = array(
    'css_id' => 'category',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = '';
  $pane->uuid = '8228e046-82bb-4b4f-bb5b-325d2b373f46';
  $display->content['new-8228e046-82bb-4b4f-bb5b-325d2b373f46'] = $pane;
  $display->panels['left'][2] = 'new-8228e046-82bb-4b4f-bb5b-325d2b373f46';
  $pane = new stdClass();
  $pane->pid = 'new-6b75772d-0168-459a-87c8-e0ac9a732ee6';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_competence';
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
  $pane->css = array(
    'css_id' => 'competence',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '6b75772d-0168-459a-87c8-e0ac9a732ee6';
  $display->content['new-6b75772d-0168-459a-87c8-e0ac9a732ee6'] = $pane;
  $display->panels['left'][3] = 'new-6b75772d-0168-459a-87c8-e0ac9a732ee6';
  $pane = new stdClass();
  $pane->pid = 'new-2c635194-0bd5-4ecc-b0ee-89c85fcd00d8';
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
  $pane->uuid = '2c635194-0bd5-4ecc-b0ee-89c85fcd00d8';
  $display->content['new-2c635194-0bd5-4ecc-b0ee-89c85fcd00d8'] = $pane;
  $display->panels['left'][4] = 'new-2c635194-0bd5-4ecc-b0ee-89c85fcd00d8';
  $pane = new stdClass();
  $pane->pid = 'new-40984bb6-3f74-42f8-9b1b-1301cb73b048';
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
  $pane->uuid = '40984bb6-3f74-42f8-9b1b-1301cb73b048';
  $display->content['new-40984bb6-3f74-42f8-9b1b-1301cb73b048'] = $pane;
  $display->panels['left'][5] = 'new-40984bb6-3f74-42f8-9b1b-1301cb73b048';
  $pane = new stdClass();
  $pane->pid = 'new-306a1777-b6fa-42a1-9630-616fffd188ac';
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
  $pane->uuid = '306a1777-b6fa-42a1-9630-616fffd188ac';
  $display->content['new-306a1777-b6fa-42a1-9630-616fffd188ac'] = $pane;
  $display->panels['left'][6] = 'new-306a1777-b6fa-42a1-9630-616fffd188ac';
  $pane = new stdClass();
  $pane->pid = 'new-c6d22f20-ae9d-4329-a64b-f0d81cf81cb6';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_g_drive_file';
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
  $pane->uuid = 'c6d22f20-ae9d-4329-a64b-f0d81cf81cb6';
  $display->content['new-c6d22f20-ae9d-4329-a64b-f0d81cf81cb6'] = $pane;
  $display->panels['left'][7] = 'new-c6d22f20-ae9d-4329-a64b-f0d81cf81cb6';
  $pane = new stdClass();
  $pane->pid = 'new-3da6e304-e42f-4f10-afdf-2353f735b874';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_task_due_date';
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
  $pane->uuid = '3da6e304-e42f-4f10-afdf-2353f735b874';
  $display->content['new-3da6e304-e42f-4f10-afdf-2353f735b874'] = $pane;
  $display->panels['right'][0] = 'new-3da6e304-e42f-4f10-afdf-2353f735b874';
  $pane = new stdClass();
  $pane->pid = 'new-4f159b28-8c80-488d-baee-a0e8f7401787';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_task_field_strict_sub';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4f159b28-8c80-488d-baee-a0e8f7401787';
  $display->content['new-4f159b28-8c80-488d-baee-a0e8f7401787'] = $pane;
  $display->panels['right'][1] = 'new-4f159b28-8c80-488d-baee-a0e8f7401787';
  $pane = new stdClass();
  $pane->pid = 'new-4dea264f-0d82-4b61-b92f-8fd33f1ee297';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_task_field_auto_accept';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4dea264f-0d82-4b61-b92f-8fd33f1ee297';
  $display->content['new-4dea264f-0d82-4b61-b92f-8fd33f1ee297'] = $pane;
  $display->panels['right'][2] = 'new-4dea264f-0d82-4b61-b92f-8fd33f1ee297';
  $pane = new stdClass();
  $pane->pid = 'new-9083ef3b-869b-41b0-aa20-3c691356508d';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_task_field_max_points';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '9083ef3b-869b-41b0-aa20-3c691356508d';
  $display->content['new-9083ef3b-869b-41b0-aa20-3c691356508d'] = $pane;
  $display->panels['right'][3] = 'new-9083ef3b-869b-41b0-aa20-3c691356508d';
  $pane = new stdClass();
  $pane->pid = 'new-30666dae-916d-4428-a22d-3316e72be85a';
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
  $pane->position = 4;
  $pane->locks = '';
  $pane->uuid = '30666dae-916d-4428-a22d-3316e72be85a';
  $display->content['new-30666dae-916d-4428-a22d-3316e72be85a'] = $pane;
  $display->panels['right'][4] = 'new-30666dae-916d-4428-a22d-3316e72be85a';
  $pane = new stdClass();
  $pane->pid = 'new-9d0c4772-6f2d-4fee-857f-595978e53100';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '9d0c4772-6f2d-4fee-857f-595978e53100';
  $display->content['new-9d0c4772-6f2d-4fee-857f-595978e53100'] = $pane;
  $display->panels['right'][5] = 'new-9d0c4772-6f2d-4fee-857f-595978e53100';
  $pane = new stdClass();
  $pane->pid = 'new-47602f6b-3af9-4366-9673-3967f361961f';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_task_field_study_group';
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
  $pane->uuid = '47602f6b-3af9-4366-9673-3967f361961f';
  $display->content['new-47602f6b-3af9-4366-9673-3967f361961f'] = $pane;
  $display->panels['right'][6] = 'new-47602f6b-3af9-4366-9673-3967f361961f';
  $pane = new stdClass();
  $pane->pid = 'new-1d408b21-7027-4c38-b99f-f159789e08ec';
  $pane->panel = 'top';
  $pane->type = 'node_group_breadcrumbs';
  $pane->subtype = 'node_group_breadcrumbs';
  $pane->shown = FALSE;
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
  $pane->uuid = '1d408b21-7027-4c38-b99f-f159789e08ec';
  $display->content['new-1d408b21-7027-4c38-b99f-f159789e08ec'] = $pane;
  $display->panels['top'][0] = 'new-1d408b21-7027-4c38-b99f-f159789e08ec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;


  return $handler;
}

function _ed_task_view_page_handler() {
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_ed_task';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Task/Assignment',
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
              'ed_task' => 'ed_task',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'robots' => array(
          'value' => array(
            'noindex' => 'noindex',
            'nofollow' => 'nofollow',
            'noarchive' => 'noarchive',
            'nosnippet' => 'nosnippet',
            'noodp' => 'noodp',
            'noydir' => 'noydir',
            'noimageindex' => 'noimageindex',
            'notranslate' => 'notranslate',
            'index' => 0,
            'follow' => 0,
          ),
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'bootstrap_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'right' => array(
        'column_type' => 'col-lg',
        'column_size' => '4',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
      'bottom' => NULL,
      'left' => array(
        'column_type' => 'col-lg',
        'column_size' => '8',
        'offset_type' => 'col-lg-offset',
        'offset_size' => '0',
      ),
    ),
    'left' => array(
      'style' => 'bootstrap_region',
    ),
    'right' => array(
      'style' => 'bootstrap_region',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '64e54c32-6f59-4660-b37a-4b0199c1f96b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_ed_task';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f0d171c4-77f9-4c55-96e3-cfeeb69d1be1';
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
  $pane->uuid = 'f0d171c4-77f9-4c55-96e3-cfeeb69d1be1';
  $display->content['new-f0d171c4-77f9-4c55-96e3-cfeeb69d1be1'] = $pane;
  $display->panels['left'][0] = 'new-f0d171c4-77f9-4c55-96e3-cfeeb69d1be1';
  $pane = new stdClass();
  $pane->pid = 'new-c896b79f-9f81-4a9f-82d0-94a417d73676';
  $pane->panel = 'left';
  $pane->type = 'answers_listing';
  $pane->subtype = 'answers_listing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c896b79f-9f81-4a9f-82d0-94a417d73676';
  $display->content['new-c896b79f-9f81-4a9f-82d0-94a417d73676'] = $pane;
  $display->panels['left'][1] = 'new-c896b79f-9f81-4a9f-82d0-94a417d73676';
  $pane = new stdClass();
  $pane->pid = 'new-10c67705-7b9b-4b88-85de-62f1633955f4';
  $pane->panel = 'left';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '10c67705-7b9b-4b88-85de-62f1633955f4';
  $display->content['new-10c67705-7b9b-4b88-85de-62f1633955f4'] = $pane;
  $display->panels['left'][2] = 'new-10c67705-7b9b-4b88-85de-62f1633955f4';
  $pane = new stdClass();
  $pane->pid = 'new-7d202452-60d3-459d-af5b-10c6a811b063';
  $pane->panel = 'left';
  $pane->type = 'node_comments';
  $pane->subtype = 'node_comments';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mode' => '1',
    'comments_per_page' => '50',
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
  $pane->uuid = '7d202452-60d3-459d-af5b-10c6a811b063';
  $display->content['new-7d202452-60d3-459d-af5b-10c6a811b063'] = $pane;
  $display->panels['left'][3] = 'new-7d202452-60d3-459d-af5b-10c6a811b063';
  $pane = new stdClass();
  $pane->pid = 'new-9a38bb42-ae28-44a3-b86f-cddc16d75ab3';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_g_drive_file';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'ed_g_drive_file_default',
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
  $pane->uuid = '9a38bb42-ae28-44a3-b86f-cddc16d75ab3';
  $display->content['new-9a38bb42-ae28-44a3-b86f-cddc16d75ab3'] = $pane;
  $display->panels['left'][4] = 'new-9a38bb42-ae28-44a3-b86f-cddc16d75ab3';
  $pane = new stdClass();
  $pane->pid = 'new-7982b34c-46e6-45bd-be7d-87057d460a36';
  $pane->panel = 'right';
  $pane->type = 'create_update_answer';
  $pane->subtype = 'create_update_answer';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7982b34c-46e6-45bd-be7d-87057d460a36';
  $display->content['new-7982b34c-46e6-45bd-be7d-87057d460a36'] = $pane;
  $display->panels['right'][0] = 'new-7982b34c-46e6-45bd-be7d-87057d460a36';
  $pane = new stdClass();
  $pane->pid = 'new-6467d0c9-05f4-43fb-a1b4-6846a485e5ae';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6467d0c9-05f4-43fb-a1b4-6846a485e5ae';
  $display->content['new-6467d0c9-05f4-43fb-a1b4-6846a485e5ae'] = $pane;
  $display->panels['right'][1] = 'new-6467d0c9-05f4-43fb-a1b4-6846a485e5ae';
  $pane = new stdClass();
  $pane->pid = 'new-544f9b21-e827-4c35-9ccd-08f2060ab34d';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_task_due_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mlpanels' => array(
      'und' => array(
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
          'show_remaining_days' => 1,
        ),
        'context' => 'argument_entity_id:node_1',
        'override_title' => 0,
        'override_title_text' => '',
        'override_title_heading' => 'h2',
      ),
    ),
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
      'show_remaining_days' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '544f9b21-e827-4c35-9ccd-08f2060ab34d';
  $display->content['new-544f9b21-e827-4c35-9ccd-08f2060ab34d'] = $pane;
  $display->panels['right'][2] = 'new-544f9b21-e827-4c35-9ccd-08f2060ab34d';
  $pane = new stdClass();
  $pane->pid = 'new-fcca2c2e-1e28-4ef8-a20f-47bfe27b20f6';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_task_field_max_points';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'number_integer',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'thousand_separator' => '',
      'prefix_suffix' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'fcca2c2e-1e28-4ef8-a20f-47bfe27b20f6';
  $display->content['new-fcca2c2e-1e28-4ef8-a20f-47bfe27b20f6'] = $pane;
  $display->panels['right'][3] = 'new-fcca2c2e-1e28-4ef8-a20f-47bfe27b20f6';
  $pane = new stdClass();
  $pane->pid = 'new-f14e3593-36f4-4302-9b04-988d6bdf00cd';
  $pane->panel = 'right';
  $pane->type = 'node_created';
  $pane->subtype = 'node_created';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mlpanels' => array(
      'und' => array(
        'format' => 'short',
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
        'override_title_text' => 'Published: ',
        'override_title_heading' => 'h2',
      ),
    ),
    'format' => 'short',
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
    'override_title_text' => 'Published: ',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'f14e3593-36f4-4302-9b04-988d6bdf00cd';
  $display->content['new-f14e3593-36f4-4302-9b04-988d6bdf00cd'] = $pane;
  $display->panels['right'][4] = 'new-f14e3593-36f4-4302-9b04-988d6bdf00cd';
  $pane = new stdClass();
  $pane->pid = 'new-261d1c02-6fb3-4a60-97c5-8dc2769d6659';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '261d1c02-6fb3-4a60-97c5-8dc2769d6659';
  $display->content['new-261d1c02-6fb3-4a60-97c5-8dc2769d6659'] = $pane;
  $display->panels['right'][5] = 'new-261d1c02-6fb3-4a60-97c5-8dc2769d6659';
  $pane = new stdClass();
  $pane->pid = 'new-b06389a8-899d-4fbb-a512-97488a560ec7';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_competence';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'b06389a8-899d-4fbb-a512-97488a560ec7';
  $display->content['new-b06389a8-899d-4fbb-a512-97488a560ec7'] = $pane;
  $display->panels['right'][6] = 'new-b06389a8-899d-4fbb-a512-97488a560ec7';
  $pane = new stdClass();
  $pane->pid = 'new-7503f22f-6df5-43b5-a3cd-0e53fb50da39';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:og_group_ref';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'og_list_default',
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '7503f22f-6df5-43b5-a3cd-0e53fb50da39';
  $display->content['new-7503f22f-6df5-43b5-a3cd-0e53fb50da39'] = $pane;
  $display->panels['right'][7] = 'new-7503f22f-6df5-43b5-a3cd-0e53fb50da39';
  $pane = new stdClass();
  $pane->pid = 'new-da69989a-e578-4ffa-9d08-b5a40e37b897';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'da69989a-e578-4ffa-9d08-b5a40e37b897';
  $display->content['new-da69989a-e578-4ffa-9d08-b5a40e37b897'] = $pane;
  $display->panels['right'][8] = 'new-da69989a-e578-4ffa-9d08-b5a40e37b897';
  $pane = new stdClass();
  $pane->pid = 'new-468214dc-b274-43ed-8363-9659133b0384';
  $pane->panel = 'right';
  $pane->type = 'node_author';
  $pane->subtype = 'node_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mlpanels' => array(
      'und' => array(
        'link' => 1,
        'context' => 'argument_entity_id:node_1',
        'override_title' => 0,
        'override_title_text' => 'Assigned by: ',
        'override_title_heading' => 'h2',
      ),
    ),
    'link' => 1,
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => 'Assigned by: ',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '468214dc-b274-43ed-8363-9659133b0384';
  $display->content['new-468214dc-b274-43ed-8363-9659133b0384'] = $pane;
  $display->panels['right'][9] = 'new-468214dc-b274-43ed-8363-9659133b0384';
  $pane = new stdClass();
  $pane->pid = 'new-52e4e35c-e8a4-4b4f-aba7-d86042c29024';
  $pane->panel = 'top';
  $pane->type = 'node_group_breadcrumbs';
  $pane->subtype = 'node_group_breadcrumbs';
  $pane->shown = FALSE;
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
  $pane->uuid = '52e4e35c-e8a4-4b4f-aba7-d86042c29024';
  $display->content['new-52e4e35c-e8a4-4b4f-aba7-d86042c29024'] = $pane;
  $display->panels['top'][0] = 'new-52e4e35c-e8a4-4b4f-aba7-d86042c29024';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;





  return $handler;
}
