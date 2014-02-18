<?php

  /**
   * @file
   * ed_learning_resource.pages_default.inc
   */

  /**
   * Implements hook_default_page_manager_handlers().
   */
  function ed_blog_default_page_manager_handlers() {
    $export = array();

    $ed_blog_node_edit_handler = _ed_blog_edit_page_handler();
    $export['node_edit_panel_ed_blog'] = $ed_blog_node_edit_handler;
    $ed_blog_node_view_handler = _ed_blog_view_page_handler();
    $export['node_view_panel_ed_blog'] = $ed_blog_node_view_handler;

    return $export;
  }
    // NODE ADD/EDIT BEGINS
  function _ed_blog_edit_page_handler(){
    $handler = new stdClass();
    $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
    $handler->api_version = 1;
    $handler->name = 'node_edit_panel_context';
    $handler->task = 'node_edit';
    $handler->subtask = '';
    $handler->handler = 'panel_context';
    $handler->weight = 1;
    $handler->conf = array(
      'title' => 'Blog',
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
                'ed_blog' => 'ed_blog',
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
    $display->content = array();
    $display->panels = array();
      $pane = new stdClass();
      $pane->pid = 'new-1';
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
      $display->content['new-1'] = $pane;
      $display->panels['left'][0] = 'new-1';
      $pane = new stdClass();
      $pane->pid = 'new-2';
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
      $display->content['new-2'] = $pane;
      $display->panels['left'][1] = 'new-2';
      $pane = new stdClass();
      $pane->pid = 'new-3';
      $pane->panel = 'left';
      $pane->type = 'entity_form_field';
      $pane->subtype = 'node:ed_blog_tags';
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
      $display->content['new-3'] = $pane;
      $display->panels['left'][2] = 'new-3';
      $pane = new stdClass();
      $pane->pid = 'new-4';
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
      $pane->position = 3;
      $pane->locks = array();
      $display->content['new-4'] = $pane;
      $display->panels['left'][3] = 'new-4';
      $pane = new stdClass();
      $pane->pid = 'new-5';
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
      $pane->position = 4;
      $pane->locks = array();
      $display->content['new-5'] = $pane;
      $display->panels['left'][4] = 'new-5';
      $pane = new stdClass();
      $pane->pid = 'new-6';
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
      $pane->position = 5;
      $pane->locks = array();
      $display->content['new-6'] = $pane;
      $display->panels['left'][5] = 'new-6';
      $pane = new stdClass();
      $pane->pid = 'new-7';
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
      $pane->position = 0;
      $pane->locks = array();
      $display->content['new-7'] = $pane;
      $display->panels['right'][0] = 'new-7';
    $display->hide_title = PANELS_TITLE_FIXED;
    $display->title_pane = 'new-1';
    $handler->conf['display'] = $display;

        return $handler;

      }

      function _ed_blog_view_page_handler() {
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context_2';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 3;
$handler->conf = array(
  'title' => 'blog',
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
            'ed_blog' => 'ed_blog',
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
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1';
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
  $display->content['new-1'] = $pane;
  $display->panels['bottom'][0] = 'new-1';
  $pane = new stdClass();
  $pane->pid = 'new-2';
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
  $display->content['new-2'] = $pane;
  $display->panels['bottom'][1] = 'new-2';
  $pane = new stdClass();
  $pane->pid = 'new-3';
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
  $display->content['new-3'] = $pane;
  $display->panels['left'][0] = 'new-3';
  $pane = new stdClass();
  $pane->pid = 'new-4';
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
  $display->content['new-4'] = $pane;
  $display->panels['right'][0] = 'new-4';
  $pane = new stdClass();
  $pane->pid = 'new-5';
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
  $display->content['new-5'] = $pane;
  $display->panels['right'][1] = 'new-5';
  $pane = new stdClass();
  $pane->pid = 'new-6';
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
  $display->content['new-6'] = $pane;
  $display->panels['right'][2] = 'new-6';
  $pane = new stdClass();
  $pane->pid = 'new-7';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_blog_tags';
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
  $pane->position = 3;
  $pane->locks = array();
  $display->content['new-7'] = $pane;
  $display->panels['right'][3] = 'new-7';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;

    return $handler;
  }
