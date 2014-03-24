<?php

  /**
   * @file
   * ed_learning_resource.pages_default.inc
   */

  /**
   * Implements hook_default_page_manager_handlers().
   */
  function ed_answer_default_page_manager_handlers() {
    $export = array();

    /*$ed_answer_node_edit_handler = _ed_answer_edit_page_handler();
    $export['node_edit_panel_ed_answer'] = $ed_answer_node_edit_handler;*/
    $ed_answer_node_view_handler = _ed_answer_view_page_handler();
    $export['node_view_panel_ed_answer'] = $ed_answer_node_view_handler;

    return $export;
  }
    // NODE ADD/EDIT BEGINS
  /*function _ed_answer_edit_page_handler(){
  
    return $handler;

  }*/
function _ed_answer_view_page_handler() {
  $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context_7';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 8;
$handler->conf = array(
  'title' => 'Answer',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(
    0 => array(
      'identifier' => 'Node from Node (on Node: Task [field_ref_to_task])',
      'keyword' => 'node_2',
      'name' => 'entity_from_field:field_ref_to_task-node-node',
      'delta' => 0,
      'context' => 'argument_entity_id:node_1',
      'id' => 1,
    ),
  ),
  'access' => array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'ed_answer' => 'ed_answer',
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
$display->title = '%node_2:title - Answer';
$display->uuid = 'be8f3bc1-1095-49b7-90f2-76ac8ca5d509';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-313d9f6b-1646-4938-9ef6-db5c5961343c';
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
  $pane->uuid = '313d9f6b-1646-4938-9ef6-db5c5961343c';
  $display->content['new-313d9f6b-1646-4938-9ef6-db5c5961343c'] = $pane;
  $display->panels['bottom'][0] = 'new-313d9f6b-1646-4938-9ef6-db5c5961343c';
  $pane = new stdClass();
  $pane->pid = 'new-59acd81c-77d3-40c5-8dea-a7f1430de2f6';
  $pane->panel = 'bottom';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '59acd81c-77d3-40c5-8dea-a7f1430de2f6';
  $display->content['new-59acd81c-77d3-40c5-8dea-a7f1430de2f6'] = $pane;
  $display->panels['bottom'][1] = 'new-59acd81c-77d3-40c5-8dea-a7f1430de2f6';
  $pane = new stdClass();
  $pane->pid = 'new-48ee673e-dc41-4af8-a2dd-051420fb7ae8';
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
  $pane->uuid = '48ee673e-dc41-4af8-a2dd-051420fb7ae8';
  $display->content['new-48ee673e-dc41-4af8-a2dd-051420fb7ae8'] = $pane;
  $display->panels['left'][0] = 'new-48ee673e-dc41-4af8-a2dd-051420fb7ae8';
  $pane = new stdClass();
  $pane->pid = 'new-9ca4bfb7-974e-4722-80ec-4257e3f20766';
  $pane->panel = 'left';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:ed-answer-actions-container';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
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
  $pane->uuid = '9ca4bfb7-974e-4722-80ec-4257e3f20766';
  $display->content['new-9ca4bfb7-974e-4722-80ec-4257e3f20766'] = $pane;
  $display->panels['left'][1] = 'new-9ca4bfb7-974e-4722-80ec-4257e3f20766';
  $pane = new stdClass();
  $pane->pid = 'new-66a19de6-0a71-4343-b582-a2cd93c27015';
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
  $pane->uuid = '66a19de6-0a71-4343-b582-a2cd93c27015';
  $display->content['new-66a19de6-0a71-4343-b582-a2cd93c27015'] = $pane;
  $display->panels['right'][0] = 'new-66a19de6-0a71-4343-b582-a2cd93c27015';
  $pane = new stdClass();
  $pane->pid = 'new-2865f515-bb1b-41b7-9f72-267c223d5827';
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
    'format' => 'long',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2865f515-bb1b-41b7-9f72-267c223d5827';
  $display->content['new-2865f515-bb1b-41b7-9f72-267c223d5827'] = $pane;
  $display->panels['right'][1] = 'new-2865f515-bb1b-41b7-9f72-267c223d5827';
  $pane = new stdClass();
  $pane->pid = 'new-1a691a16-c105-4ecd-b673-9ae8463ef72f';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1a691a16-c105-4ecd-b673-9ae8463ef72f';
  $display->content['new-1a691a16-c105-4ecd-b673-9ae8463ef72f'] = $pane;
  $display->panels['right'][2] = 'new-1a691a16-c105-4ecd-b673-9ae8463ef72f';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-48ee673e-dc41-4af8-a2dd-051420fb7ae8';
$handler->conf['display'] = $display;

  return $handler;
}
