<?php
/**
 * @file
 * ed_portfolio.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ed_portfolio_default_page_manager_handlers() {
  $export = array();
  $ed_portfolio_node_edit_handler = _ed_portfolio_node_edit_page_handler();
  $export['node_edit_panel_ed_portfolio'] = $ed_portfolio_node_edit_handler;
  $ed_portfolio_node_view_handler = _ed_portfolio_node_view_page_handler();
  $export['node_view_panel_ed_portfolio'] = $ed_portfolio_node_view_handler;
  return $export;
}

function _ed_portfolio_node_edit_page_handler() {
 $handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_edit_panel_ed_portfolio';
$handler->task = 'node_edit';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 2;
$handler->conf = array(
  'title' => 'Portfolio',
  'no_blocks' => 0,
  'pipeline' => 'mlpanels_renderer_standard',
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
            'ed_portfolio' => 'ed_portfolio',
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
$display->uuid = '363a1662-77e7-4650-8418-16c33abd61ac';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3dd72395-6e05-485a-a129-795a800bf841';
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
  $pane->locks = array();
  $pane->uuid = '3dd72395-6e05-485a-a129-795a800bf841';
  $display->content['new-3dd72395-6e05-485a-a129-795a800bf841'] = $pane;
  $display->panels['bottom'][0] = 'new-3dd72395-6e05-485a-a129-795a800bf841';
  $pane = new stdClass();
  $pane->pid = 'new-c58f061d-abed-4201-ba3b-7f1daa2643f9';
  $pane->panel = 'left';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_portfolio_field_items';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mlpanels' => array(
      'und' => array(
        'label' => '',
        'formatter' => '',
        'context' => 'argument_node_edit_1',
        'override_title' => 1,
        'override_title_text' => 'Porftolio items',
      ),
      'et' => array(
        'label' => '',
        'formatter' => '',
        'context' => 'argument_node_edit_1',
        'override_title' => 1,
        'override_title_text' => 'Portfolio objektid',
      ),
      'en' => array(
        'label' => '',
        'formatter' => '',
        'context' => 'argument_node_edit_1',
        'override_title' => 1,
        'override_title_text' => 'Portfolio items',
      ),
    ),
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Porftolio items',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c58f061d-abed-4201-ba3b-7f1daa2643f9';
  $display->content['new-c58f061d-abed-4201-ba3b-7f1daa2643f9'] = $pane;
  $display->panels['left'][0] = 'new-c58f061d-abed-4201-ba3b-7f1daa2643f9';
  $pane = new stdClass();
  $pane->pid = 'new-c87ae23b-88e7-45f3-89d7-293c185075b6';
  $pane->panel = 'left';
  $pane->type = 'form';
  $pane->subtype = 'form';
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
  $pane->uuid = 'c87ae23b-88e7-45f3-89d7-293c185075b6';
  $display->content['new-c87ae23b-88e7-45f3-89d7-293c185075b6'] = $pane;
  $display->panels['left'][1] = 'new-c87ae23b-88e7-45f3-89d7-293c185075b6';
  $pane = new stdClass();
  $pane->pid = 'new-e90cabdd-ad4b-4b4f-a6fb-68fd80ba2ad4';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mlpanels' => array(
      'und' => array(
        'label' => '',
        'formatter' => '',
        'context' => 'argument_node_edit_1',
        'override_title' => 0,
        'override_title_text' => '',
      ),
      'et' => array(
        'label' => '',
        'formatter' => '',
        'context' => 'argument_node_edit_1',
        'override_title' => 1,
        'override_title_text' => 'Kaanepilt',
      ),
      'en' => array(
        'label' => '',
        'formatter' => '',
        'context' => 'argument_node_edit_1',
        'override_title' => 1,
        'override_title_text' => 'Featured image',
      ),
    ),
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
  $pane->uuid = 'e90cabdd-ad4b-4b4f-a6fb-68fd80ba2ad4';
  $display->content['new-e90cabdd-ad4b-4b4f-a6fb-68fd80ba2ad4'] = $pane;
  $display->panels['right'][0] = 'new-e90cabdd-ad4b-4b4f-a6fb-68fd80ba2ad4';
  $pane = new stdClass();
  $pane->pid = 'new-303d2871-f3e1-4f7c-970b-8450197faa39';
  $pane->panel = 'right';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:ed_field_cover_image';
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
  $pane->uuid = '303d2871-f3e1-4f7c-970b-8450197faa39';
  $display->content['new-303d2871-f3e1-4f7c-970b-8450197faa39'] = $pane;
  $display->panels['right'][1] = 'new-303d2871-f3e1-4f7c-970b-8450197faa39';
  $pane = new stdClass();
  $pane->pid = 'new-64e07df5-b3e3-403a-9d0b-a8ad3d806df6';
  $pane->panel = 'top';
  $pane->type = 'node_group_breadcrumbs';
  $pane->subtype = 'node_group_breadcrumbs';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '64e07df5-b3e3-403a-9d0b-a8ad3d806df6';
  $display->content['new-64e07df5-b3e3-403a-9d0b-a8ad3d806df6'] = $pane;
  $display->panels['top'][0] = 'new-64e07df5-b3e3-403a-9d0b-a8ad3d806df6';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-c87ae23b-88e7-45f3-89d7-293c185075b6';
$handler->conf['display'] = $display;


return $handler;

}

function _ed_portfolio_node_view_page_handler(){
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'node_view_panel_context_6';
$handler->task = 'node_view';
$handler->subtask = '';
$handler->handler = 'panel_context';
$handler->weight = 7;
$handler->conf = array(
  'title' => 'portfolio',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '.language-switcher-locale-url{
      display: none;
  }

  .search-form{
      display: none;
  }

  .nav-collapse{
      display: none;
  }

  .footer-links{
      display: none;
  }
  ',
  'contexts' => array(),
  'relationships' => array(
    0 => array(
      'identifier' => 'User from Node (on node.node_author)',
      'keyword' => 'user',
      'name' => 'entity_from_schema:uid-node-user',
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
            'ed_portfolio' => 'ed_portfolio',
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
$display->title = '%user:ed_field_full_name - %node:title';
$display->uuid = '42b871d3-112e-41eb-84c6-799eb6d5a5a7';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b9d40aae-b9cb-4b03-99ad-c2de01d43f2b';
  $pane->panel = 'bottom';
  $pane->type = 'node_comment_form';
  $pane->subtype = 'node_comment_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'anon_links' => 0,
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
  $pane->uuid = 'b9d40aae-b9cb-4b03-99ad-c2de01d43f2b';
  $display->content['new-b9d40aae-b9cb-4b03-99ad-c2de01d43f2b'] = $pane;
  $display->panels['bottom'][0] = 'new-b9d40aae-b9cb-4b03-99ad-c2de01d43f2b';
  $pane = new stdClass();
  $pane->pid = 'new-742f8313-ebb9-4d3e-8ded-c7ebbff1d134';
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
  $pane->uuid = '742f8313-ebb9-4d3e-8ded-c7ebbff1d134';
  $display->content['new-742f8313-ebb9-4d3e-8ded-c7ebbff1d134'] = $pane;
  $display->panels['bottom'][1] = 'new-742f8313-ebb9-4d3e-8ded-c7ebbff1d134';
  $pane = new stdClass();
  $pane->pid = 'new-8d4cd923-897f-435d-a389-ff01fc43295a';
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
  $pane->uuid = '8d4cd923-897f-435d-a389-ff01fc43295a';
  $display->content['new-8d4cd923-897f-435d-a389-ff01fc43295a'] = $pane;
  $display->panels['left'][0] = 'new-8d4cd923-897f-435d-a389-ff01fc43295a';
  $pane = new stdClass();
  $pane->pid = 'new-ea30164d-3d19-474c-8790-cfc46d2a1210';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_portfolio_field_items';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entities_table',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 0,
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
  $pane->uuid = 'ea30164d-3d19-474c-8790-cfc46d2a1210';
  $display->content['new-ea30164d-3d19-474c-8790-cfc46d2a1210'] = $pane;
  $display->panels['left'][1] = 'new-ea30164d-3d19-474c-8790-cfc46d2a1210';
  $pane = new stdClass();
  $pane->pid = 'new-21e64707-bf5d-4970-a7c7-a69791feee14';
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
  $pane->uuid = '21e64707-bf5d-4970-a7c7-a69791feee14';
  $display->content['new-21e64707-bf5d-4970-a7c7-a69791feee14'] = $pane;
  $display->panels['right'][0] = 'new-21e64707-bf5d-4970-a7c7-a69791feee14';
  $pane = new stdClass();
  $pane->pid = 'new-e6012102-27f0-415d-86ad-21cb53619c96';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:ed_field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->uuid = 'e6012102-27f0-415d-86ad-21cb53619c96';
  $display->content['new-e6012102-27f0-415d-86ad-21cb53619c96'] = $pane;
  $display->panels['right'][1] = 'new-e6012102-27f0-415d-86ad-21cb53619c96';
  $pane = new stdClass();
  $pane->pid = 'new-d04aeefe-66b8-4000-988c-67746d8f39dc';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd04aeefe-66b8-4000-988c-67746d8f39dc';
  $display->content['new-d04aeefe-66b8-4000-988c-67746d8f39dc'] = $pane;
  $display->panels['right'][2] = 'new-d04aeefe-66b8-4000-988c-67746d8f39dc';
  $pane = new stdClass();
  $pane->pid = 'new-77783557-6cb2-47e6-9602-e3d319d00361';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '77783557-6cb2-47e6-9602-e3d319d00361';
  $display->content['new-77783557-6cb2-47e6-9602-e3d319d00361'] = $pane;
  $display->panels['right'][3] = 'new-77783557-6cb2-47e6-9602-e3d319d00361';
  $pane = new stdClass();
  $pane->pid = 'new-042e7bcf-8056-426b-b9c1-9db5939cfbca';
  $pane->panel = 'right';
  $pane->type = 'node_updated';
  $pane->subtype = 'node_updated';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '042e7bcf-8056-426b-b9c1-9db5939cfbca';
  $display->content['new-042e7bcf-8056-426b-b9c1-9db5939cfbca'] = $pane;
  $display->panels['right'][4] = 'new-042e7bcf-8056-426b-b9c1-9db5939cfbca';
  $pane = new stdClass();
  $pane->pid = 'new-e1e89129-6e28-44fb-941d-091f0ad8b35e';
  $pane->panel = 'top';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:ed_field_full_name';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_entity_from_schema:uid-node-user_1',
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
  $pane->uuid = 'e1e89129-6e28-44fb-941d-091f0ad8b35e';
  $display->content['new-e1e89129-6e28-44fb-941d-091f0ad8b35e'] = $pane;
  $display->panels['top'][0] = 'new-e1e89129-6e28-44fb-941d-091f0ad8b35e';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = 'new-8d4cd923-897f-435d-a389-ff01fc43295a';
$handler->conf['display'] = $display;

  return $handler;
}

