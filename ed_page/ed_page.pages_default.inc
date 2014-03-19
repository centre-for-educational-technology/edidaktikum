<?php

  /**
   * @file
   * ed_page.pages_default.inc
   */

  /**
   * Implements hook_default_page_manager_handlers().
   */
  function ed_page_default_page_manager_handlers() {
    $export = array();

    /*$ed_page_node_edit_handler = _ed_page_edit_page_handler();
    $export['node_edit_panel_ed_page'] = $ed_page_node_edit_handler;*/
    $ed_page_node_view_handler = _ed_page_view_page_handler();
    $export['node_view_panel_ed_page'] = $ed_page_node_view_handler;

    return $export;
  }
    // NODE ADD/EDIT BEGINS
/*function _ed_page_edit_page_handler(){

  return $handler;

}*/
function _ed_page_view_page_handler() {
  $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context_3';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 4;
$handler->conf = array(
  'title' => 'page',
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
            'ed_page' => 'ed_page',
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
$display->uuid = 'b110e860-f554-4837-807b-c76b8e131fae';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-36b75570-7fff-48b5-b731-c125fe688396';
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
  $pane->uuid = '36b75570-7fff-48b5-b731-c125fe688396';
  $display->content['new-36b75570-7fff-48b5-b731-c125fe688396'] = $pane;
  $display->panels['bottom'][0] = 'new-36b75570-7fff-48b5-b731-c125fe688396';
  $pane = new stdClass();
  $pane->pid = 'new-d2ded442-3db6-4732-94b7-cc9be5b9b894';
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
  $pane->uuid = 'd2ded442-3db6-4732-94b7-cc9be5b9b894';
  $display->content['new-d2ded442-3db6-4732-94b7-cc9be5b9b894'] = $pane;
  $display->panels['bottom'][1] = 'new-d2ded442-3db6-4732-94b7-cc9be5b9b894';
  $pane = new stdClass();
  $pane->pid = 'new-33e24a4a-4fcf-4b74-8d52-58daae620d88';
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
  $pane->uuid = '33e24a4a-4fcf-4b74-8d52-58daae620d88';
  $display->content['new-33e24a4a-4fcf-4b74-8d52-58daae620d88'] = $pane;
  $display->panels['left'][0] = 'new-33e24a4a-4fcf-4b74-8d52-58daae620d88';
  $pane = new stdClass();
  $pane->pid = 'new-27d94e1d-3a2f-4647-9001-187914f34278';
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
  $pane->uuid = '27d94e1d-3a2f-4647-9001-187914f34278';
  $display->content['new-27d94e1d-3a2f-4647-9001-187914f34278'] = $pane;
  $display->panels['right'][0] = 'new-27d94e1d-3a2f-4647-9001-187914f34278';
  $pane = new stdClass();
  $pane->pid = 'new-216006f6-7ae6-4eb4-aba6-8ac57f7c984f';
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
  $pane->uuid = '216006f6-7ae6-4eb4-aba6-8ac57f7c984f';
  $display->content['new-216006f6-7ae6-4eb4-aba6-8ac57f7c984f'] = $pane;
  $display->panels['right'][1] = 'new-216006f6-7ae6-4eb4-aba6-8ac57f7c984f';
  $pane = new stdClass();
  $pane->pid = 'new-672cd2cc-7cf8-4d9e-ac20-77fd37f54ef6';
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
  $pane->uuid = '672cd2cc-7cf8-4d9e-ac20-77fd37f54ef6';
  $display->content['new-672cd2cc-7cf8-4d9e-ac20-77fd37f54ef6'] = $pane;
  $display->panels['right'][2] = 'new-672cd2cc-7cf8-4d9e-ac20-77fd37f54ef6';
  $pane = new stdClass();
  $pane->pid = 'new-2bdfc60e-91a8-4cda-96a2-bbb3865ba4ae';
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
  $pane->uuid = '2bdfc60e-91a8-4cda-96a2-bbb3865ba4ae';
  $display->content['new-2bdfc60e-91a8-4cda-96a2-bbb3865ba4ae'] = $pane;
  $display->panels['right'][3] = 'new-2bdfc60e-91a8-4cda-96a2-bbb3865ba4ae';
  $pane = new stdClass();
  $pane->pid = 'new-e3ce06e4-6553-40eb-9cbd-81ff3fce5e73';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_page_tags';
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
  $pane->uuid = 'e3ce06e4-6553-40eb-9cbd-81ff3fce5e73';
  $display->content['new-e3ce06e4-6553-40eb-9cbd-81ff3fce5e73'] = $pane;
  $display->panels['right'][4] = 'new-e3ce06e4-6553-40eb-9cbd-81ff3fce5e73';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-33e24a4a-4fcf-4b74-8d52-58daae620d88';
$handler->conf['display'] = $display;

  return $handler;
}

