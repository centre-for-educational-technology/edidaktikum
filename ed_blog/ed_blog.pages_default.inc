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
$display->uuid = '608f4c9f-bfbf-4339-81b4-f798a6e8f8db';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a7d77b1c-3cfb-4c1b-a6bb-0df3b960e928';
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
  $pane->uuid = 'a7d77b1c-3cfb-4c1b-a6bb-0df3b960e928';
  $display->content['new-a7d77b1c-3cfb-4c1b-a6bb-0df3b960e928'] = $pane;
  $display->panels['left'][0] = 'new-a7d77b1c-3cfb-4c1b-a6bb-0df3b960e928';
  $pane = new stdClass();
  $pane->pid = 'new-3cd1e8bb-3355-415e-a91f-d1f5ca87062e';
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
  $pane->uuid = '3cd1e8bb-3355-415e-a91f-d1f5ca87062e';
  $display->content['new-3cd1e8bb-3355-415e-a91f-d1f5ca87062e'] = $pane;
  $display->panels['left'][1] = 'new-3cd1e8bb-3355-415e-a91f-d1f5ca87062e';
  $pane = new stdClass();
  $pane->pid = 'new-c2eaf533-efee-4746-ab59-2624f580dc1d';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_blog_tags';
  $pane->shown = FALSE;
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
  $pane->uuid = 'c2eaf533-efee-4746-ab59-2624f580dc1d';
  $display->content['new-c2eaf533-efee-4746-ab59-2624f580dc1d'] = $pane;
  $display->panels['left'][2] = 'new-c2eaf533-efee-4746-ab59-2624f580dc1d';
  $pane = new stdClass();
  $pane->pid = 'new-0e7654b5-a484-4c51-b490-ea92832e0e81';
  $pane->panel = 'left';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '0e7654b5-a484-4c51-b490-ea92832e0e81';
  $display->content['new-0e7654b5-a484-4c51-b490-ea92832e0e81'] = $pane;
  $display->panels['left'][3] = 'new-0e7654b5-a484-4c51-b490-ea92832e0e81';
  $pane = new stdClass();
  $pane->pid = 'new-8c6c2cd5-c733-494a-aaab-7954c9370ba2';
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
  $pane->uuid = '8c6c2cd5-c733-494a-aaab-7954c9370ba2';
  $display->content['new-8c6c2cd5-c733-494a-aaab-7954c9370ba2'] = $pane;
  $display->panels['left'][4] = 'new-8c6c2cd5-c733-494a-aaab-7954c9370ba2';
  $pane = new stdClass();
  $pane->pid = 'new-b9849780-c9f7-472e-8d88-150a85d0da79';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'b9849780-c9f7-472e-8d88-150a85d0da79';
  $display->content['new-b9849780-c9f7-472e-8d88-150a85d0da79'] = $pane;
  $display->panels['left'][5] = 'new-b9849780-c9f7-472e-8d88-150a85d0da79';
  $pane = new stdClass();
  $pane->pid = 'new-59746148-3eb0-4e7a-afe5-429f788a44ca';
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
  $pane->uuid = '59746148-3eb0-4e7a-afe5-429f788a44ca';
  $display->content['new-59746148-3eb0-4e7a-afe5-429f788a44ca'] = $pane;
  $display->panels['left'][6] = 'new-59746148-3eb0-4e7a-afe5-429f788a44ca';
  $pane = new stdClass();
  $pane->pid = 'new-a5fff736-f936-4002-a598-3dbff3de1b8d';
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
  $pane->uuid = 'a5fff736-f936-4002-a598-3dbff3de1b8d';
  $display->content['new-a5fff736-f936-4002-a598-3dbff3de1b8d'] = $pane;
  $display->panels['right'][0] = 'new-a5fff736-f936-4002-a598-3dbff3de1b8d';
  $pane = new stdClass();
  $pane->pid = 'new-f95257e9-fef6-48fb-9b3b-29cf8360767a';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f95257e9-fef6-48fb-9b3b-29cf8360767a';
  $display->content['new-f95257e9-fef6-48fb-9b3b-29cf8360767a'] = $pane;
  $display->panels['right'][1] = 'new-f95257e9-fef6-48fb-9b3b-29cf8360767a';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-a7d77b1c-3cfb-4c1b-a6bb-0df3b960e928';
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
$display->uuid = 'd387306d-88dd-4dec-ac4c-36996368700e';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-115cf630-394a-4d2d-aee8-c1900a2145b9';
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
  $pane->uuid = '115cf630-394a-4d2d-aee8-c1900a2145b9';
  $display->content['new-115cf630-394a-4d2d-aee8-c1900a2145b9'] = $pane;
  $display->panels['bottom'][0] = 'new-115cf630-394a-4d2d-aee8-c1900a2145b9';
  $pane = new stdClass();
  $pane->pid = 'new-1fa108a3-421f-46c5-91be-e00784a14359';
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
  $pane->uuid = '1fa108a3-421f-46c5-91be-e00784a14359';
  $display->content['new-1fa108a3-421f-46c5-91be-e00784a14359'] = $pane;
  $display->panels['bottom'][1] = 'new-1fa108a3-421f-46c5-91be-e00784a14359';
  $pane = new stdClass();
  $pane->pid = 'new-2e3bd3e6-9c02-4f9e-9c03-8ca3f04a6767';
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
  $pane->uuid = '2e3bd3e6-9c02-4f9e-9c03-8ca3f04a6767';
  $display->content['new-2e3bd3e6-9c02-4f9e-9c03-8ca3f04a6767'] = $pane;
  $display->panels['left'][0] = 'new-2e3bd3e6-9c02-4f9e-9c03-8ca3f04a6767';
  $pane = new stdClass();
  $pane->pid = 'new-28e8767e-ff3c-4b98-b5c9-86be68949baa';
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
  $pane->uuid = '28e8767e-ff3c-4b98-b5c9-86be68949baa';
  $display->content['new-28e8767e-ff3c-4b98-b5c9-86be68949baa'] = $pane;
  $display->panels['right'][0] = 'new-28e8767e-ff3c-4b98-b5c9-86be68949baa';
  $pane = new stdClass();
  $pane->pid = 'new-87ad28df-4d39-4b63-8189-37546da7b995';
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
  $pane->uuid = '87ad28df-4d39-4b63-8189-37546da7b995';
  $display->content['new-87ad28df-4d39-4b63-8189-37546da7b995'] = $pane;
  $display->panels['right'][1] = 'new-87ad28df-4d39-4b63-8189-37546da7b995';
  $pane = new stdClass();
  $pane->pid = 'new-a477a39d-f0a2-4201-be2a-afe9282ba014';
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
  $pane->uuid = 'a477a39d-f0a2-4201-be2a-afe9282ba014';
  $display->content['new-a477a39d-f0a2-4201-be2a-afe9282ba014'] = $pane;
  $display->panels['right'][2] = 'new-a477a39d-f0a2-4201-be2a-afe9282ba014';
  $pane = new stdClass();
  $pane->pid = 'new-6ba47d7c-8e69-4d1d-88ed-131974f01094';
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
  $pane->uuid = '6ba47d7c-8e69-4d1d-88ed-131974f01094';
  $display->content['new-6ba47d7c-8e69-4d1d-88ed-131974f01094'] = $pane;
  $display->panels['right'][3] = 'new-6ba47d7c-8e69-4d1d-88ed-131974f01094';
  $pane = new stdClass();
  $pane->pid = 'new-5db6ad76-5637-4a5d-9aba-0cf477953476';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_blog_tags';
  $pane->shown = FALSE;
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
  $pane->uuid = '5db6ad76-5637-4a5d-9aba-0cf477953476';
  $display->content['new-5db6ad76-5637-4a5d-9aba-0cf477953476'] = $pane;
  $display->panels['right'][4] = 'new-5db6ad76-5637-4a5d-9aba-0cf477953476';
  $pane = new stdClass();
  $pane->pid = 'new-3f189add-f44c-4d5f-9248-73f388e3b218';
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
  $pane->uuid = '3f189add-f44c-4d5f-9248-73f388e3b218';
  $display->content['new-3f189add-f44c-4d5f-9248-73f388e3b218'] = $pane;
  $display->panels['right'][5] = 'new-3f189add-f44c-4d5f-9248-73f388e3b218';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;

    return $handler;
  }
