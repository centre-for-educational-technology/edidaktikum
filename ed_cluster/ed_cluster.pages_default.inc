<?php
/**
 * @file
 * ed_cluster.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ed_cluster_default_page_manager_handlers() {
  $export = array();
  $ed_cluster_node_view_handler = _ed_cluster_node_view_page_handler();
  $export['node_view_panel_ed_cluster'] = $ed_cluster_node_view_handler;
  return $export;
}

function _ed_cluster_node_view_page_handler() {
	$handler = new stdClass();
	$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
	$handler->api_version = 1;
	$handler->name = 'node_view_panel_ed_cluster';
	$handler->task = 'node_view';
	$handler->subtask = '';
	$handler->handler = 'panel_context';
	$handler->weight = 0;
	$handler->conf = array(
			'title' => 'Group',
			'no_blocks' => 0,
			'pipeline' => 'mlpanels_renderer_standard',
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
													'ed_cluster' => 'ed_cluster',
											),
									),
									'context' => 'argument_entity_id:node_1',
									'not' => FALSE,
							),
					),
					'logic' => 'and',
			),
			'body_classes_to_remove' => '',
			'body_classes_to_add' => '',
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
	$display->uuid = '95058aa2-b6c0-4958-a96a-37bb484fca78';
	$display->content = array();
	$display->panels = array();
	$pane = new stdClass();
	$pane->pid = 'new-08c3ffc0-dd35-45c9-8222-28c8b8cbdf1c';
	$pane->panel = 'left';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:ed_field_course_aim';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'title',
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
	$pane->uuid = '08c3ffc0-dd35-45c9-8222-28c8b8cbdf1c';
	$display->content['new-08c3ffc0-dd35-45c9-8222-28c8b8cbdf1c'] = $pane;
	$display->panels['left'][0] = 'new-08c3ffc0-dd35-45c9-8222-28c8b8cbdf1c';
	$pane = new stdClass();
	$pane->pid = 'new-af5a9791-c50a-46d4-8d73-ab01f139ae9f';
	$pane->panel = 'left';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:ed_field_learning_outcomes';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'title',
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
	$pane->position = 1;
	$pane->locks = array();
	$pane->uuid = 'af5a9791-c50a-46d4-8d73-ab01f139ae9f';
	$display->content['new-af5a9791-c50a-46d4-8d73-ab01f139ae9f'] = $pane;
	$display->panels['left'][1] = 'new-af5a9791-c50a-46d4-8d73-ab01f139ae9f';
	$pane = new stdClass();
	$pane->pid = 'new-6f0d3a40-c971-47bd-869e-0cc1fdc95109';
	$pane->panel = 'left';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:ed_field_assessment_method';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'title',
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
	$pane->position = 2;
	$pane->locks = array();
	$pane->uuid = '6f0d3a40-c971-47bd-869e-0cc1fdc95109';
	$display->content['new-6f0d3a40-c971-47bd-869e-0cc1fdc95109'] = $pane;
	$display->panels['left'][2] = 'new-6f0d3a40-c971-47bd-869e-0cc1fdc95109';
	$pane = new stdClass();
	$pane->pid = 'new-15a57ea3-fa61-4f54-a609-b712e3a80a82';
	$pane->panel = 'left';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:ed_field_excerpt';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'title',
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
	$pane->position = 3;
	$pane->locks = array();
	$pane->uuid = '15a57ea3-fa61-4f54-a609-b712e3a80a82';
	$display->content['new-15a57ea3-fa61-4f54-a609-b712e3a80a82'] = $pane;
	$display->panels['left'][3] = 'new-15a57ea3-fa61-4f54-a609-b712e3a80a82';
	$pane = new stdClass();
	$pane->pid = 'new-e8fe714d-381b-48b7-b826-61485c013db6';
	$pane->panel = 'left';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:ed_field_content';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'title',
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
	$pane->position = 4;
	$pane->locks = array();
	$pane->uuid = 'e8fe714d-381b-48b7-b826-61485c013db6';
	$display->content['new-e8fe714d-381b-48b7-b826-61485c013db6'] = $pane;
	$display->panels['left'][4] = 'new-e8fe714d-381b-48b7-b826-61485c013db6';
	$pane = new stdClass();
	$pane->pid = 'new-030b5adf-405a-4192-8bd2-d6bd26073760';
	$pane->panel = 'left';
	$pane->type = 'views_panes';
	$pane->subtype = 'og_nodes-panel_pane_1';
	$pane->shown = FALSE;
	$pane->access = array();
	$pane->configuration = array(
			'context' => array(
					0 => 'argument_entity_id:node_1',
			),
			'override_title' => 1,
			'override_title_text' => 'Group content',
	);
	$pane->cache = array();
	$pane->style = array(
			'settings' => NULL,
	);
	$pane->css = array();
	$pane->extras = array();
	$pane->position = 5;
	$pane->locks = '';
	$pane->uuid = '030b5adf-405a-4192-8bd2-d6bd26073760';
	$display->content['new-030b5adf-405a-4192-8bd2-d6bd26073760'] = $pane;
	$display->panels['left'][5] = 'new-030b5adf-405a-4192-8bd2-d6bd26073760';
	$pane = new stdClass();
	$pane->pid = 'new-74a8940e-b7da-4b0b-b852-6ffba5e5a599';
	$pane->panel = 'left';
	$pane->type = 'entity_field_extra';
	$pane->subtype = 'node:ed_cluster_content';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'view_mode' => 'full',
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
	$pane->position = 6;
	$pane->locks = array();
	$pane->uuid = '74a8940e-b7da-4b0b-b852-6ffba5e5a599';
	$display->content['new-74a8940e-b7da-4b0b-b852-6ffba5e5a599'] = $pane;
	$display->panels['left'][6] = 'new-74a8940e-b7da-4b0b-b852-6ffba5e5a599';
	$pane = new stdClass();
	$pane->pid = 'new-dad41d08-1ee0-41ca-8e99-448fb1b3aeda';
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
	$pane->uuid = 'dad41d08-1ee0-41ca-8e99-448fb1b3aeda';
	$display->content['new-dad41d08-1ee0-41ca-8e99-448fb1b3aeda'] = $pane;
	$display->panels['right'][0] = 'new-dad41d08-1ee0-41ca-8e99-448fb1b3aeda';
	$pane = new stdClass();
	$pane->pid = 'new-ae8af9c4-7416-4e87-8a82-6422e2eb96c0';
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
	$pane->uuid = 'ae8af9c4-7416-4e87-8a82-6422e2eb96c0';
	$display->content['new-ae8af9c4-7416-4e87-8a82-6422e2eb96c0'] = $pane;
	$display->panels['right'][1] = 'new-ae8af9c4-7416-4e87-8a82-6422e2eb96c0';
	$pane = new stdClass();
	$pane->pid = 'new-25378e99-e400-47b0-a09c-17da593e9134';
	$pane->panel = 'right';
	$pane->type = 'node_create_links';
	$pane->subtype = 'node_create_links';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'mlpanels' => array(
					'und' => array(
							'context' => 'argument_entity_id:node_1',
							'override_title' => 1,
							'override_title_text' => 'Add New:',
							'field_name' => 'og_group_ref',
							'types' => array(
									'ed_blog' => 'ed_blog',
									'ed_bookmark' => 'ed_bookmark',
									'ed_forum' => 'ed_forum',
									'ed_learning_resource' => 'ed_learning_resource',
									'ed_page' => 'ed_page',
									'ed_task' => 'ed_task',
									'ed_event' => 'ed_event',
									'ed_news' => 'ed_news',
							),
					),
					'en' => array(
							'context' => 'argument_entity_id:node_1',
							'override_title' => 1,
							'override_title_text' => 'Add New:',
							'field_name' => 'og_group_ref',
							'types' => array(
									'ed_blog' => 'ed_blog',
									'ed_bookmark' => 'ed_bookmark',
									'ed_event' => 'ed_event',
									'ed_forum' => 'ed_forum',
									'ed_learning_resource' => 'ed_learning_resource',
									'ed_news' => 'ed_news',
									'ed_page' => 'ed_page',
									'ed_task' => 'ed_task',
							),
					),
					'et' => array(
							'context' => 'argument_entity_id:node_1',
							'override_title' => 1,
							'override_title_text' => 'Lisa Uus:',
							'field_name' => 'og_group_ref',
							'types' => array(
									'ed_blog' => 'ed_blog',
									'ed_bookmark' => 'ed_bookmark',
									'ed_event' => 'ed_event',
									'ed_forum' => 'ed_forum',
									'ed_learning_resource' => 'ed_learning_resource',
									'ed_news' => 'ed_news',
									'ed_page' => 'ed_page',
									'ed_task' => 'ed_task',
							),
					),
			),
			'context' => 'argument_entity_id:node_1',
			'override_title' => 1,
			'override_title_text' => 'Add New:',
			'field_name' => 'og_group_ref',
			'types' => array(
					'ed_blog' => 'ed_blog',
					'ed_bookmark' => 'ed_bookmark',
					'ed_forum' => 'ed_forum',
					'ed_learning_resource' => 'ed_learning_resource',
					'ed_page' => 'ed_page',
					'ed_task' => 'ed_task',
					'ed_event' => 'ed_event',
					'ed_news' => 'ed_news',
			),
	);
	$pane->cache = array();
	$pane->style = array(
			'settings' => NULL,
	);
	$pane->css = array();
	$pane->extras = array();
	$pane->position = 2;
	$pane->locks = '';
	$pane->uuid = '25378e99-e400-47b0-a09c-17da593e9134';
	$display->content['new-25378e99-e400-47b0-a09c-17da593e9134'] = $pane;
	$display->panels['right'][2] = 'new-25378e99-e400-47b0-a09c-17da593e9134';
	$pane = new stdClass();
	$pane->pid = 'new-f853f79a-6565-438e-bc11-c9cfef3de8f1';
	$pane->panel = 'right';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:group_group';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'hidden',
			'formatter' => 'og_group_subscribe',
			'formatter_settings' => array(
					'field_name' => '0',
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
	$pane->locks = '';
	$pane->uuid = 'f853f79a-6565-438e-bc11-c9cfef3de8f1';
	$display->content['new-f853f79a-6565-438e-bc11-c9cfef3de8f1'] = $pane;
	$display->panels['right'][3] = 'new-f853f79a-6565-438e-bc11-c9cfef3de8f1';
	$pane = new stdClass();
	$pane->pid = 'new-d3c51f6a-14d6-48b1-b1e7-9db7c93255d6';
	$pane->panel = 'right';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:ed_field_university';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'title',
			'formatter' => 'i18n_list_default',
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
	$pane->position = 4;
	$pane->locks = array();
	$pane->uuid = 'd3c51f6a-14d6-48b1-b1e7-9db7c93255d6';
	$display->content['new-d3c51f6a-14d6-48b1-b1e7-9db7c93255d6'] = $pane;
	$display->panels['right'][4] = 'new-d3c51f6a-14d6-48b1-b1e7-9db7c93255d6';
	$pane = new stdClass();
	$pane->pid = 'new-d83b78b9-9fbf-4197-8979-ef4f98dc4c96';
	$pane->panel = 'right';
	$pane->type = 'entity_field';
	$pane->subtype = 'node:ed_field_course_code';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'label' => 'title',
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
	$pane->position = 5;
	$pane->locks = array();
	$pane->uuid = 'd83b78b9-9fbf-4197-8979-ef4f98dc4c96';
	$display->content['new-d83b78b9-9fbf-4197-8979-ef4f98dc4c96'] = $pane;
	$display->panels['right'][5] = 'new-d83b78b9-9fbf-4197-8979-ef4f98dc4c96';
	$pane = new stdClass();
	$pane->pid = 'new-c0582149-90a0-4c69-86d9-389873db534d';
	$pane->panel = 'right';
	$pane->type = 'views_panes';
	$pane->subtype = 'og_members-panel_pane_1';
	$pane->shown = TRUE;
	$pane->access = array();
	$pane->configuration = array(
			'context' => array(
					0 => 'argument_entity_id:node_1',
			),
			'override_title' => 0,
			'override_title_text' => 'Members',
	);
	$pane->cache = array();
	$pane->style = array(
			'settings' => NULL,
	);
	$pane->css = array();
	$pane->extras = array();
	$pane->position = 6;
	$pane->locks = '';
	$pane->uuid = 'c0582149-90a0-4c69-86d9-389873db534d';
	$display->content['new-c0582149-90a0-4c69-86d9-389873db534d'] = $pane;
	$display->panels['right'][6] = 'new-c0582149-90a0-4c69-86d9-389873db534d';
	$display->hide_title = PANELS_TITLE_FIXED;
	$display->title_pane = '0';
	$handler->conf['display'] = $display;

}

