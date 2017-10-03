<?php

/**
 * Implements hook_views_default_views_alter().
 */
function ed_cluster_views_default_views_alter(&$views) {
  if (array_key_exists('og_members_admin', $views)) {
    $handler =& $views['og_members_admin']->display['default']->handler;
	  /* Footer: Global: Unfiltered text */
	  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
	  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
	  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
	  $handler->display->display_options['footer']['area_text_custom']['empty'] = TRUE;
	  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a href="/node/%2"><i class="fa fa-arrow-circle-o-left"></i> '.t('Back to group page').'</a> ';
	  $handler->display->display_options['footer']['area_text_custom']['tokenize'] = TRUE;
	  $translatables['og_members_admin'] = array(
			  t('<a href="/node/%2"><i class="fa fa-arrow-circle-o-left"></i> Back to group page</a> '),
	  );
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
	
	/* Note: if more element_column_label == FALSE members are added, they need to be moved too to prevent the wildcard column from being created too early */
    if (isset($handler->display->display_options['fields']['edit_membership'])) {
		/* Move edit to the end */
		$tmp_edit_membership = $handler->display->display_options['fields']['edit_membership'];
		unset($handler->display->display_options['fields']['edit_membership']);
		$handler->display->display_options['fields']['edit_membership'] = $tmp_edit_membership;
    }
	
	if (isset($handler->display->display_options['fields']['delete_membership'])) {
		/* Move delete to the end */
		$tmp_delete_membership = $handler->display->display_options['fields']['delete_membership'];
		unset($handler->display->display_options['fields']['delete_membership']);
		$handler->display->display_options['fields']['delete_membership'] = $tmp_delete_membership;
	}
	
  }

  if (array_key_exists('og_members', $views)) {
    $handler =& $views['og_members']->display['default']->handler;
    $handler->display->display_options['pager']['options']['items_per_page'] = '0';
    //Sort group members alphabetically
    unset($handler->display->display_options['sorts']['created']);
    $handler->display->display_options['sorts']['name']['id'] = 'name';
    $handler->display->display_options['sorts']['name']['table'] = 'users';
    $handler->display->display_options['sorts']['name']['field'] = 'name';
  }

}

