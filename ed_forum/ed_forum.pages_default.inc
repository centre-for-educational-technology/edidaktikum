<?php

  /**
   * @file
   * ed_forum.pages_default.inc
   */

  /**
   * Implements hook_default_page_manager_handlers().
   */
  function ed_forum_default_page_manager_handlers() {
    $export = array();

    /*$ed_forum_node_edit_handler = _ed_forum_edit_page_handler();
    $export['node_edit_panel_ed_forum'] = $ed_forum_node_edit_handler;*/
    $ed_forum_node_view_handler = _ed_forum_view_page_handler();
    $export['node_view_panel_ed_forum'] = $ed_forum_node_view_handler;

    return $export;
  }
    // NODE ADD/EDIT BEGINS
/*function _ed_forum_edit_page_handler(){

  return $handler;

}*/
function _ed_forum_view_page_handler() {
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
      'title' => 'forum',
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
                          'ed_forum' => 'ed_forum',
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
          'bottom' => array(
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
      'bottom' => array(
          'style' => 'bootstrap_region',
      ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '25f0030a-ac10-4fd6-9387-7262b343748b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9df63b12-41ab-412f-a6c5-c5b990a93c6b';
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
  $pane->uuid = '9df63b12-41ab-412f-a6c5-c5b990a93c6b';
  $display->content['new-9df63b12-41ab-412f-a6c5-c5b990a93c6b'] = $pane;
  $display->panels['left'][0] = 'new-9df63b12-41ab-412f-a6c5-c5b990a93c6b';
  $pane = new stdClass();
  $pane->pid = 'new-aa11cd1e-39bc-4884-a7f8-84bcc072cae0';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'aa11cd1e-39bc-4884-a7f8-84bcc072cae0';
  $display->content['new-aa11cd1e-39bc-4884-a7f8-84bcc072cae0'] = $pane;
  $display->panels['left'][1] = 'new-aa11cd1e-39bc-4884-a7f8-84bcc072cae0';
  $pane = new stdClass();
  $pane->pid = 'new-17273904-ae82-49dc-88fc-0a8d3ae56602';
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
  $pane->uuid = '17273904-ae82-49dc-88fc-0a8d3ae56602';
  $display->content['new-17273904-ae82-49dc-88fc-0a8d3ae56602'] = $pane;
  $display->panels['left'][2] = 'new-17273904-ae82-49dc-88fc-0a8d3ae56602';
  $pane = new stdClass();
  $pane->pid = 'new-73aa1a16-95de-4e8c-b1ce-7fb784b412df';
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
  $pane->uuid = '73aa1a16-95de-4e8c-b1ce-7fb784b412df';
  $display->content['new-73aa1a16-95de-4e8c-b1ce-7fb784b412df'] = $pane;
  $display->panels['right'][0] = 'new-73aa1a16-95de-4e8c-b1ce-7fb784b412df';
  $pane = new stdClass();
  $pane->pid = 'new-af73c39c-777d-4418-8cd6-2775fbe9c86a';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'af73c39c-777d-4418-8cd6-2775fbe9c86a';
  $display->content['new-af73c39c-777d-4418-8cd6-2775fbe9c86a'] = $pane;
  $display->panels['right'][1] = 'new-af73c39c-777d-4418-8cd6-2775fbe9c86a';
  $pane = new stdClass();
  $pane->pid = 'new-b925ecbd-2361-4ec9-a2ee-bbcb9640ba0a';
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
  $pane->uuid = 'b925ecbd-2361-4ec9-a2ee-bbcb9640ba0a';
  $display->content['new-b925ecbd-2361-4ec9-a2ee-bbcb9640ba0a'] = $pane;
  $display->panels['right'][2] = 'new-b925ecbd-2361-4ec9-a2ee-bbcb9640ba0a';
  $pane = new stdClass();
  $pane->pid = 'new-8765ba53-b15b-4ab2-b705-4261d3696a3a';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '8765ba53-b15b-4ab2-b705-4261d3696a3a';
  $display->content['new-8765ba53-b15b-4ab2-b705-4261d3696a3a'] = $pane;
  $display->panels['right'][3] = 'new-8765ba53-b15b-4ab2-b705-4261d3696a3a';
  $pane = new stdClass();
  $pane->pid = 'new-0455d6db-21fb-454d-a658-016f1c8a5ddf';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '0455d6db-21fb-454d-a658-016f1c8a5ddf';
  $display->content['new-0455d6db-21fb-454d-a658-016f1c8a5ddf'] = $pane;
  $display->panels['right'][4] = 'new-0455d6db-21fb-454d-a658-016f1c8a5ddf';
  $pane = new stdClass();
  $pane->pid = 'new-7550057d-88fc-4c22-89cb-576ad874b823';
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
  $pane->uuid = '7550057d-88fc-4c22-89cb-576ad874b823';
  $display->content['new-7550057d-88fc-4c22-89cb-576ad874b823'] = $pane;
  $display->panels['top'][0] = 'new-7550057d-88fc-4c22-89cb-576ad874b823';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9df63b12-41ab-412f-a6c5-c5b990a93c6b';
  $handler->conf['display'] = $display;





  return $handler;
}

