<?php

/**
 * Implements hook_views_default_views_alter().
 */
function ed_cluster_views_default_views_alter(&$views) {
  if (array_key_exists('og_members_admin', $views)) {
    $handler =& $views['og_members_admin']->display['default']->handler;
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
    if (isset($handler->display->display_options['fields']['edit_membership'])) {
      $tmp_edit_membership = $handler->display->display_options['fields']['edit_membership'];
      unset($handler->display->display_options['fields']['edit_membership']);
      $handler->display->display_options['fields']['edit_membership'] = $tmp_edit_membership;
    }
  }
}
