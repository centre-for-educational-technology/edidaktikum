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
    /*$ed_file_node_view_handler = _ed_file_view_page_handler();
    $export['node_view_panel_ed_file'] = $ed_file_node_view_handler;*/

    return $export;
  }
    // NODE ADD/EDIT BEGINS
function _ed_file_edit_page_handler(){
  $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_edit_panel_context_2';
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
$display->content = array();
$display->panels = array();
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e8fa5dc0-2d37-435a-9c8b-39c4b7e08577';
  $display->content['new-e8fa5dc0-2d37-435a-9c8b-39c4b7e08577'] = $pane;
  $display->panels['middle'][0] = 'new-e8fa5dc0-2d37-435a-9c8b-39c4b7e08577';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3708583d-4d6c-4929-8233-6dbf6adf8914';
  $display->content['new-3708583d-4d6c-4929-8233-6dbf6adf8914'] = $pane;
  $display->panels['middle'][1] = 'new-3708583d-4d6c-4929-8233-6dbf6adf8914';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'abef8d49-e388-461a-b217-1352076c0e2d';
  $display->content['new-abef8d49-e388-461a-b217-1352076c0e2d'] = $pane;
  $display->panels['middle'][2] = 'new-abef8d49-e388-461a-b217-1352076c0e2d';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a4e764de-c787-4a14-8b6a-99d767bbfb07';
  $display->content['new-a4e764de-c787-4a14-8b6a-99d767bbfb07'] = $pane;
  $display->panels['middle'][3] = 'new-a4e764de-c787-4a14-8b6a-99d767bbfb07';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '08b5c091-810e-4270-918b-09506d055190';
  $display->content['new-08b5c091-810e-4270-918b-09506d055190'] = $pane;
  $display->panels['middle'][4] = 'new-08b5c091-810e-4270-918b-09506d055190';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '0fc1d094-08e8-484d-afb8-2b7b4cc0c328';
  $display->content['new-0fc1d094-08e8-484d-afb8-2b7b4cc0c328'] = $pane;
  $display->panels['middle'][5] = 'new-0fc1d094-08e8-484d-afb8-2b7b4cc0c328';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '1b31f919-ac73-482b-b61d-bb98d509b5c5';
  $display->content['new-1b31f919-ac73-482b-b61d-bb98d509b5c5'] = $pane;
  $display->panels['middle'][6] = 'new-1b31f919-ac73-482b-b61d-bb98d509b5c5';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '389461ac-6bf0-4ba2-87fa-87e412e449cf';
  $display->content['new-389461ac-6bf0-4ba2-87fa-87e412e449cf'] = $pane;
  $display->panels['middle'][7] = 'new-389461ac-6bf0-4ba2-87fa-87e412e449cf';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-e8fa5dc0-2d37-435a-9c8b-39c4b7e08577';
$handler->conf['display'] = $display;

  return $handler;

}
 /*
function _ed_file_view_page_handler() {

  return $handler;
}
*/
