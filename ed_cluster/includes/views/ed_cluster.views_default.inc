<?php
/**
 * Implements hook_views_default_views().
 */
function ed_cluster_views_default_views_alter(&$views){
  $view = new view();
  $view->name = 'og_members_admin';
  $view->description = '';
  $view->tag = 'og';
  $view->base_table = 'users';
  $view->human_name = 'OG members admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OG members admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'veel';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Taasta algseis';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteeri';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Suurenevalt';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Vähenevalt';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Objekte lehel';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Kõik -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« esimene';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ eelmine';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'järgmine ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'viimane »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'ed_field_full_name' => 'ed_field_full_name',
    'state' => 'state',
    'og_roles' => 'og_roles',
    'created' => 'created',
    'og_membership_request' => 'og_membership_request',
    'access' => 'access',
    'login' => 'login',
    'edit_membership' => 'edit_membership',
    'delete_membership' => 'edit_membership',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = 'ed_field_full_name';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ed_field_full_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_roles' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'og_membership_request' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_membership' => array(
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'delete_membership' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: OG membership: Group membership overview */
  $handler->display->display_options['header']['og_membership_overview']['id'] = 'og_membership_overview';
  $handler->display->display_options['header']['og_membership_overview']['table'] = 'og_membership';
  $handler->display->display_options['header']['og_membership_overview']['field'] = 'og_membership_overview';
  $handler->display->display_options['header']['og_membership_overview']['manager'] = 1;
  $handler->display->display_options['header']['og_membership_overview']['total_members_1'] = 0;
  $handler->display->display_options['header']['og_membership_overview']['total_members_2'] = 0;
  $handler->display->display_options['header']['og_membership_overview']['total_members_3'] = 0;
  $handler->display->display_options['header']['og_membership_overview']['total_members'] = 1;
  $handler->display->display_options['header']['og_membership_overview']['total_content'] = 1;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a href="'.url('node').'/%2"><i class="fa fa-arrow-circle-o-left"></i> '.t('Back to group page').'</a> ';
  $handler->display->display_options['footer']['area_text_custom']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No people found matching the search criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Bulk operations: OG membership */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_og_membership';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::og_set_state_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::og_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::og_membership_delete_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: Full Name */
  $handler->display->display_options['fields']['ed_field_full_name']['id'] = 'ed_field_full_name';
  $handler->display->display_options['fields']['ed_field_full_name']['table'] = 'field_data_ed_field_full_name';
  $handler->display->display_options['fields']['ed_field_full_name']['field'] = 'ed_field_full_name';
  $handler->display->display_options['fields']['ed_field_full_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ed_field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['ed_field_full_name']['alter']['path'] = '/user/[uid]';
  /* Field: OG membership: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'og_membership';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['state']['label'] = 'Staatus';
  /* Field: OG membership: OG user roles in group */
  $handler->display->display_options['fields']['og_roles']['id'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_roles']['field'] = 'og_roles';
  $handler->display->display_options['fields']['og_roles']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['og_roles']['label'] = 'Roles';
  $handler->display->display_options['fields']['og_roles']['type'] = 'ul';
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['created']['label'] = 'Member since';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: OG membership: Request message */
  $handler->display->display_options['fields']['og_membership_request']['id'] = 'og_membership_request';
  $handler->display->display_options['fields']['og_membership_request']['table'] = 'field_data_og_membership_request';
  $handler->display->display_options['fields']['og_membership_request']['field'] = 'og_membership_request';
  $handler->display->display_options['fields']['og_membership_request']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['og_membership_request']['label'] = 'Liitumissõnum';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['date_format'] = 'time ago';
  /* Field: OG membership: Edit link */
  $handler->display->display_options['fields']['edit_membership']['id'] = 'edit_membership';
  $handler->display->display_options['fields']['edit_membership']['table'] = 'og_membership';
  $handler->display->display_options['fields']['edit_membership']['field'] = 'edit_membership';
  $handler->display->display_options['fields']['edit_membership']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['edit_membership']['label'] = '';
  $handler->display->display_options['fields']['edit_membership']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_membership']['destination'] = TRUE;
  /* Field: OG membership: Delete link */
  $handler->display->display_options['fields']['delete_membership']['id'] = 'delete_membership';
  $handler->display->display_options['fields']['delete_membership']['table'] = 'og_membership';
  $handler->display->display_options['fields']['delete_membership']['field'] = 'delete_membership';
  $handler->display->display_options['fields']['delete_membership']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['fields']['delete_membership']['label'] = '';
  $handler->display->display_options['fields']['delete_membership']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: OG membership: Group_type */
  $handler->display->display_options['arguments']['group_type']['id'] = 'group_type';
  $handler->display->display_options['arguments']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['group_type']['field'] = 'group_type';
  $handler->display->display_options['arguments']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['group_type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['group_type']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['group_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['group_type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['group_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['group_type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['group_type']['limit'] = '0';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Kõik';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $translatables['og_members_admin'] = array(
    '<a href="'.url('node').'/%2"><i class="fa fa-arrow-circle-o-left"></i> '.t('Back to group page').'</a> ',
  );



  $views[$view->name] = $view;

  return $views;
}


/**
 * Implements hook_views_default_views_alter().
 */
//function ed_cluster_views_default_views_alter(&$views) {
//  if (array_key_exists('og_members_admin', $views)) {
//    $handler =& $views['og_members_admin']->display['default']->handler;
//	  /* Footer: Global: Unfiltered text */
//	  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
//	  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
//	  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
//	  $handler->display->display_options['footer']['area_text_custom']['empty'] = TRUE;
//	  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a href="'.url('node').'/%2"><i class="fa fa-arrow-circle-o-left"></i> '.t('Back to group page').'</a> ';
//	  $handler->display->display_options['footer']['area_text_custom']['tokenize'] = TRUE;
//	  $translatables['og_members_admin'] = array(
//        '<a href="'.url('node').'/%2"><i class="fa fa-arrow-circle-o-left"></i> '.t('Back to group page').'</a> ',
//	  );
//	  /* Field: User: Last access */
//    $handler->display->display_options['fields']['access']['id'] = 'access';
//    $handler->display->display_options['fields']['access']['table'] = 'users';
//    $handler->display->display_options['fields']['access']['field'] = 'access';
//    $handler->display->display_options['fields']['access']['date_format'] = 'time ago';
//    /* Field: User: Last login */
//    $handler->display->display_options['fields']['login']['id'] = 'login';
//    $handler->display->display_options['fields']['login']['table'] = 'users';
//    $handler->display->display_options['fields']['login']['field'] = 'login';
//    $handler->display->display_options['fields']['login']['date_format'] = 'time ago';
//
//
//	/* Note: if more element_column_label == FALSE members are added, they need to be moved too to prevent the wildcard column from being created too early */
//    if (isset($handler->display->display_options['fields']['edit_membership'])) {
//		/* Move edit to the end */
//		$tmp_edit_membership = $handler->display->display_options['fields']['edit_membership'];
//		unset($handler->display->display_options['fields']['edit_membership']);
//		$handler->display->display_options['fields']['edit_membership'] = $tmp_edit_membership;
//    }
//
//	if (isset($handler->display->display_options['fields']['delete_membership'])) {
//		/* Move delete to the end */
//		$tmp_delete_membership = $handler->display->display_options['fields']['delete_membership'];
//		unset($handler->display->display_options['fields']['delete_membership']);
//		$handler->display->display_options['fields']['delete_membership'] = $tmp_delete_membership;
//	}
//
//  }
//
//  if (array_key_exists('og_members', $views)) {
//    $handler =& $views['og_members']->display['default']->handler;
//    $handler->display->display_options['pager']['options']['items_per_page'] = '0';
//    //Sort group members alphabetically
//    unset($handler->display->display_options['sorts']['created']);
//    $handler->display->display_options['sorts']['name']['id'] = 'name';
//    $handler->display->display_options['sorts']['name']['table'] = 'users';
//    $handler->display->display_options['sorts']['name']['field'] = 'name';
//  }
//
//}

