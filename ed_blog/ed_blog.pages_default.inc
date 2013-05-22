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
    /*$ed_blog_node_view_handler = _ed_blog_view_page_handler();
    $export['node_view_panel_ed_blog'] = $ed_blog_node_view_handler;*/

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
    $pane->panel = 'bottom';
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
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['bottom'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
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
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['bottom'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
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
    $display->content['new-3'] = $pane;
    $display->panels['left'][0] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
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
    $display->content['new-4'] = $pane;
    $display->panels['left'][1] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
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
    $display->content['new-5'] = $pane;
    $display->panels['right'][0] = 'new-5';
    $display->hide_title = PANELS_TITLE_FIXED;
    $display->title_pane = 'new-3';
    $handler->conf['display'] = $display;

    return $handler;

  }
/*
  function _ed_blog_view_page_handler() {

  }*/
