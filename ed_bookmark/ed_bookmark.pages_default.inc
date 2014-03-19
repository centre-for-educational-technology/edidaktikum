<?php

  /**
   * @file
   * ed_bookmark.pages_default.inc
   */

  /**
   * Implements hook_default_page_manager_handlers().
   */
  function ed_bookmark_default_page_manager_handlers() {
    $export = array();

    /*$ed_bookmark_node_edit_handler = _ed_bookmark_edit_page_handler();
    $export['node_edit_panel_ed_bookmark'] = $ed_bookmark_node_edit_handler;*/
    $ed_bookmark_node_view_handler = _ed_bookmark_view_page_handler();
    $export['node_view_panel_ed_bookmark'] = $ed_bookmark_node_view_handler;

    return $export;
  }
    // NODE ADD/EDIT BEGINS
/*function _ed_forum_edit_page_handler(){

  return $handler;

}*/
function _ed_bookmark_view_page_handler() {
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context_5';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 6;
$handler->conf = array(
  'title' => 'Bookmark',
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
            'ed_bookmark' => 'ed_bookmark',
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
$display->uuid = 'f687577b-18fd-4d91-83eb-771943bc5942';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0913ff04-2a68-44fd-b42f-4829c4a4db98';
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
  $pane->uuid = '0913ff04-2a68-44fd-b42f-4829c4a4db98';
  $display->content['new-0913ff04-2a68-44fd-b42f-4829c4a4db98'] = $pane;
  $display->panels['bottom'][0] = 'new-0913ff04-2a68-44fd-b42f-4829c4a4db98';
  $pane = new stdClass();
  $pane->pid = 'new-1e45561a-bf46-457a-92fb-26766cf2800e';
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
  $pane->uuid = '1e45561a-bf46-457a-92fb-26766cf2800e';
  $display->content['new-1e45561a-bf46-457a-92fb-26766cf2800e'] = $pane;
  $display->panels['bottom'][1] = 'new-1e45561a-bf46-457a-92fb-26766cf2800e';
  $pane = new stdClass();
  $pane->pid = 'new-62a296d7-9743-4247-922d-b1e45094ced6';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_bookmark_url';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '62a296d7-9743-4247-922d-b1e45094ced6';
  $display->content['new-62a296d7-9743-4247-922d-b1e45094ced6'] = $pane;
  $display->panels['left'][0] = 'new-62a296d7-9743-4247-922d-b1e45094ced6';
  $pane = new stdClass();
  $pane->pid = 'new-b84ea454-33c8-4f5f-9d03-96199e41cf0f';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_bookmark_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'list_default',
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
  $pane->uuid = 'b84ea454-33c8-4f5f-9d03-96199e41cf0f';
  $display->content['new-b84ea454-33c8-4f5f-9d03-96199e41cf0f'] = $pane;
  $display->panels['left'][1] = 'new-b84ea454-33c8-4f5f-9d03-96199e41cf0f';
  $pane = new stdClass();
  $pane->pid = 'new-624a7b04-4d02-4345-870a-a43da7c7a0e4';
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
  $pane->uuid = '624a7b04-4d02-4345-870a-a43da7c7a0e4';
  $display->content['new-624a7b04-4d02-4345-870a-a43da7c7a0e4'] = $pane;
  $display->panels['right'][0] = 'new-624a7b04-4d02-4345-870a-a43da7c7a0e4';
  $pane = new stdClass();
  $pane->pid = 'new-b35b7cd1-70af-4a27-a4c7-1ffb7f3dc44f';
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
  $pane->uuid = 'b35b7cd1-70af-4a27-a4c7-1ffb7f3dc44f';
  $display->content['new-b35b7cd1-70af-4a27-a4c7-1ffb7f3dc44f'] = $pane;
  $display->panels['right'][1] = 'new-b35b7cd1-70af-4a27-a4c7-1ffb7f3dc44f';
  $pane = new stdClass();
  $pane->pid = 'new-757b3ad2-38b9-4290-a76c-eea972425391';
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
  $pane->uuid = '757b3ad2-38b9-4290-a76c-eea972425391';
  $display->content['new-757b3ad2-38b9-4290-a76c-eea972425391'] = $pane;
  $display->panels['right'][2] = 'new-757b3ad2-38b9-4290-a76c-eea972425391';
  $pane = new stdClass();
  $pane->pid = 'new-8530adc3-ceaa-47d7-b5a4-d8ca3b87fa2c';
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
  $pane->uuid = '8530adc3-ceaa-47d7-b5a4-d8ca3b87fa2c';
  $display->content['new-8530adc3-ceaa-47d7-b5a4-d8ca3b87fa2c'] = $pane;
  $display->panels['right'][3] = 'new-8530adc3-ceaa-47d7-b5a4-d8ca3b87fa2c';
  $pane = new stdClass();
  $pane->pid = 'new-973dd29c-b6d8-4ce3-9b07-813ace59c19f';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_bookmark_tags';
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
  $pane->uuid = '973dd29c-b6d8-4ce3-9b07-813ace59c19f';
  $display->content['new-973dd29c-b6d8-4ce3-9b07-813ace59c19f'] = $pane;
  $display->panels['right'][4] = 'new-973dd29c-b6d8-4ce3-9b07-813ace59c19f';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-b84ea454-33c8-4f5f-9d03-96199e41cf0f';
$handler->conf['display'] = $display;

  return $handler;
}
