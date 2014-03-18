<?php

if (module_exists('og')) {
  /**
   * Plugins are described by creating a $plugin array which will be used
   * by the system that includes this file.
   */
  $plugin = array(
    'single' => TRUE,
    'title' => t('Node group breadcrumbs'),
    'icon' => 'icon_node.png',
    'description' => t('Breadcrumbs of the node groups.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'category' => t('Node'),
    'defaults' => array(
    ),
  );
}

/**
 * Renders node groups breadcrumbs.
 */
function ed_cluster_node_group_breadcrumbs_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = isset($context->data) ? clone($context->data) : NULL;
  $block = new stdClass();
  $block->module = 'node-group-breadcrumbs';
  $block->delta  = $node->nid;

  $block->title = t('Group breadcrumbs');
  if (empty($node)) {
    $block->content = t('Node group breadcrumbs go here.');
  }
  else if (!empty($node->{OG_AUDIENCE_FIELD}[LANGUAGE_NONE])) {
    $block->content = ed_cluster_node_group_breadcrumbs_render($node, $conf);
    // Update the history table, stating that this user viewed this node.
    node_tag_new($node);
  }

  return $block;
}

/**
 * Defines edit form additions.
 */
function ed_cluster_node_group_breadcrumbs_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Deals with edit form submit.
 */
function ed_cluster_node_group_breadcrumbs_content_type_edit_form_submit($form, &$form_state) {
}

/**
 * Defines a title.
 */
function ed_cluster_node_group_breadcrumbs_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" group breadcrumbs', array('@s' => $context->identifier));
}

/**
 * Really renders node group breadcrumbs (returns rendered HTML).
 */
function ed_cluster_node_group_breadcrumbs_render(&$node, $conf) {
  $output = _ed_cluster_node_group_greadcrumbs($node);

  if (!empty($output)) {
    return drupal_render($output);
  }
  return;
}

