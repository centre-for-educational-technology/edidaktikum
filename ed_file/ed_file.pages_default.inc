<?php

  /**
   * @file
   * ed_bookmark.pages_default.inc
   */

  /**
   * Implements hook_default_page_manager_handlers().
   */
  function ed_file_default_page_manager_handlers() {
    $export = array();

    $ed_file_node_edit_handler = _ed_file_edit_page_handler();
    $export['node_edit_panel_ed_file'] = $ed_file_node_edit_handler;
    $ed_file_node_view_handler = _ed_file_view_page_handler();
    $export['node_view_panel_ed_file'] = $ed_file_node_view_handler;

    return $export;
  }
    // NODE ADD/EDIT BEGINS
function _ed_file_edit_page_handler(){
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_ed_file';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
      'title' => 'File',
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
                          'ed_file' => 'ed_file',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
      'style_settings' => array(
          'default' => NULL,
          'middle' => NULL,
      ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '58cf8418-527d-4888-acf7-6b5ddba9815e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_ed_file';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-977626f9-3d1a-402d-9401-1a9bf0b6e822';
  $pane->panel = 'middle';
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
  $pane->uuid = '977626f9-3d1a-402d-9401-1a9bf0b6e822';
  $display->content['new-977626f9-3d1a-402d-9401-1a9bf0b6e822'] = $pane;
  $display->panels['middle'][0] = 'new-977626f9-3d1a-402d-9401-1a9bf0b6e822';
  $pane = new stdClass();
  $pane->pid = 'new-e8fa5dc0-2d37-435a-9c8b-39c4b7e08577';
  $pane->panel = 'middle';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e8fa5dc0-2d37-435a-9c8b-39c4b7e08577';
  $display->content['new-e8fa5dc0-2d37-435a-9c8b-39c4b7e08577'] = $pane;
  $display->panels['middle'][1] = 'new-e8fa5dc0-2d37-435a-9c8b-39c4b7e08577';
  $pane = new stdClass();
  $pane->pid = 'new-3708583d-4d6c-4929-8233-6dbf6adf8914';
  $pane->panel = 'middle';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_file_field_file_upload';
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
  $pane->uuid = '3708583d-4d6c-4929-8233-6dbf6adf8914';
  $display->content['new-3708583d-4d6c-4929-8233-6dbf6adf8914'] = $pane;
  $display->panels['middle'][2] = 'new-3708583d-4d6c-4929-8233-6dbf6adf8914';
  $pane = new stdClass();
  $pane->pid = 'new-abef8d49-e388-461a-b217-1352076c0e2d';
  $pane->panel = 'middle';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_file_folder_ref';
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
  $pane->uuid = 'abef8d49-e388-461a-b217-1352076c0e2d';
  $display->content['new-abef8d49-e388-461a-b217-1352076c0e2d'] = $pane;
  $display->panels['middle'][3] = 'new-abef8d49-e388-461a-b217-1352076c0e2d';
  $pane = new stdClass();
  $pane->pid = 'new-a4e764de-c787-4a14-8b6a-99d767bbfb07';
  $pane->panel = 'middle';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a4e764de-c787-4a14-8b6a-99d767bbfb07';
  $display->content['new-a4e764de-c787-4a14-8b6a-99d767bbfb07'] = $pane;
  $display->panels['middle'][4] = 'new-a4e764de-c787-4a14-8b6a-99d767bbfb07';
  $pane = new stdClass();
  $pane->pid = 'new-08b5c091-810e-4270-918b-09506d055190';
  $pane->panel = 'middle';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '08b5c091-810e-4270-918b-09506d055190';
  $display->content['new-08b5c091-810e-4270-918b-09506d055190'] = $pane;
  $display->panels['middle'][5] = 'new-08b5c091-810e-4270-918b-09506d055190';
  $pane = new stdClass();
  $pane->pid = 'new-0fc1d094-08e8-484d-afb8-2b7b4cc0c328';
  $pane->panel = 'middle';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '0fc1d094-08e8-484d-afb8-2b7b4cc0c328';
  $display->content['new-0fc1d094-08e8-484d-afb8-2b7b4cc0c328'] = $pane;
  $display->panels['middle'][6] = 'new-0fc1d094-08e8-484d-afb8-2b7b4cc0c328';
  $pane = new stdClass();
  $pane->pid = 'new-2f5dd0ba-5d02-4e6a-9263-229f1f76898b';
  $pane->panel = 'middle';
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
  $pane->uuid = '2f5dd0ba-5d02-4e6a-9263-229f1f76898b';
  $display->content['new-2f5dd0ba-5d02-4e6a-9263-229f1f76898b'] = $pane;
  $display->panels['middle'][7] = 'new-2f5dd0ba-5d02-4e6a-9263-229f1f76898b';
  $pane = new stdClass();
  $pane->pid = 'new-1b31f919-ac73-482b-b61d-bb98d509b5c5';
  $pane->panel = 'middle';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '1b31f919-ac73-482b-b61d-bb98d509b5c5';
  $display->content['new-1b31f919-ac73-482b-b61d-bb98d509b5c5'] = $pane;
  $display->panels['middle'][8] = 'new-1b31f919-ac73-482b-b61d-bb98d509b5c5';
  $pane = new stdClass();
  $pane->pid = 'new-389461ac-6bf0-4ba2-87fa-87e412e449cf';
  $pane->panel = 'middle';
  $pane->type = 'form';
  $pane->subtype = 'form';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '389461ac-6bf0-4ba2-87fa-87e412e449cf';
  $display->content['new-389461ac-6bf0-4ba2-87fa-87e412e449cf'] = $pane;
  $display->panels['middle'][9] = 'new-389461ac-6bf0-4ba2-87fa-87e412e449cf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e8fa5dc0-2d37-435a-9c8b-39c4b7e08577';
  $handler->conf['display'] = $display;




  return $handler;

}
 
function _ed_file_view_page_handler() {
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 9;
  $handler->conf = array(
      'title' => 'File',
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
                          'ed_file' => 'ed_file',
                      ),
                  ),
                  'context' => 'argument_entity_id:node_1',
                  'not' => FALSE,
              ),
          ),
          'logic' => 'and',
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
          'left' => array(
              'column_type' => 'col-lg',
              'column_size' => '8',
              'offset_type' => 'col-lg-offset',
              'offset_size' => '0',
          ),
          'right' => array(
              'column_type' => 'col-lg',
              'column_size' => '4',
              'offset_type' => 'col-lg-offset',
              'offset_size' => '0',
          ),
          'bottom' => NULL,
      ),
      'left' => array(
          'style' => 'bootstrap_region',
      ),
      'right' => array(
          'style' => 'bootstrap_region',
      ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '31ac4f59-3d6e-4885-adbd-8e7bbed59b84';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c8237c04-423e-44f5-84e3-f6e796b7bf1d';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_file_field_file_upload';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_default',
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
  $pane->uuid = 'c8237c04-423e-44f5-84e3-f6e796b7bf1d';
  $display->content['new-c8237c04-423e-44f5-84e3-f6e796b7bf1d'] = $pane;
  $display->panels['left'][0] = 'new-c8237c04-423e-44f5-84e3-f6e796b7bf1d';
  $pane = new stdClass();
  $pane->pid = 'new-34f9b091-c812-4a8f-b744-9386a2220bad';
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
  $pane->uuid = '34f9b091-c812-4a8f-b744-9386a2220bad';
  $display->content['new-34f9b091-c812-4a8f-b744-9386a2220bad'] = $pane;
  $display->panels['right'][0] = 'new-34f9b091-c812-4a8f-b744-9386a2220bad';
  $pane = new stdClass();
  $pane->pid = 'new-5c3c8584-f40b-430e-bfc1-132ece3a9db9';
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
      'formatter_settings' => array(
          'linked' => 1,
          'token_display_selected' => '',
          'token_display_unselected' => '',
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
  $pane->uuid = '5c3c8584-f40b-430e-bfc1-132ece3a9db9';
  $display->content['new-5c3c8584-f40b-430e-bfc1-132ece3a9db9'] = $pane;
  $display->panels['right'][1] = 'new-5c3c8584-f40b-430e-bfc1-132ece3a9db9';
  $pane = new stdClass();
  $pane->pid = 'new-99eb758e-36f1-4170-837e-9e4fb5ad991b';
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
  $pane->uuid = '99eb758e-36f1-4170-837e-9e4fb5ad991b';
  $display->content['new-99eb758e-36f1-4170-837e-9e4fb5ad991b'] = $pane;
  $display->panels['right'][2] = 'new-99eb758e-36f1-4170-837e-9e4fb5ad991b';
  $pane = new stdClass();
  $pane->pid = 'new-3dd1d884-3083-4c71-8ac0-8c53ebe7d639';
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
  $pane->uuid = '3dd1d884-3083-4c71-8ac0-8c53ebe7d639';
  $display->content['new-3dd1d884-3083-4c71-8ac0-8c53ebe7d639'] = $pane;
  $display->panels['right'][3] = 'new-3dd1d884-3083-4c71-8ac0-8c53ebe7d639';
  $pane = new stdClass();
  $pane->pid = 'new-c9966862-2198-47bd-9cae-975a40e12159';
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
  $pane->uuid = 'c9966862-2198-47bd-9cae-975a40e12159';
  $display->content['new-c9966862-2198-47bd-9cae-975a40e12159'] = $pane;
  $display->panels['right'][4] = 'new-c9966862-2198-47bd-9cae-975a40e12159';
  $pane = new stdClass();
  $pane->pid = 'new-c067447b-805c-4d44-992c-a27f4ee47aa2';
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
      'formatter_settings' => array(
          'linked' => 1,
          'token_display_selected' => '',
          'token_display_unselected' => '',
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
  $pane->uuid = 'c067447b-805c-4d44-992c-a27f4ee47aa2';
  $display->content['new-c067447b-805c-4d44-992c-a27f4ee47aa2'] = $pane;
  $display->panels['right'][5] = 'new-c067447b-805c-4d44-992c-a27f4ee47aa2';
  $pane = new stdClass();
  $pane->pid = 'new-ad2b19c3-f484-4bce-8a4a-56b0fd81f46a';
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
  $pane->uuid = 'ad2b19c3-f484-4bce-8a4a-56b0fd81f46a';
  $display->content['new-ad2b19c3-f484-4bce-8a4a-56b0fd81f46a'] = $pane;
  $display->panels['top'][0] = 'new-ad2b19c3-f484-4bce-8a4a-56b0fd81f46a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;




  return $handler;
}

