<?php

/**
 * @file
 * Page callbacks for ed_news module.
 */

/**
 * Displays a listing page for ed_news nodes.
 */
function ed_news_listing_page() {
  $content = array();

  // Latest news within a container
  $latest = ed_news_get_latest_news();
  if (!empty($latest)) {
    $content['latest-news'] = node_view($latest, 'full');
  }

  // Old news within a container
  $query = db_select('node', 'n')
    ->extend('PagerDefault')
    ->fields('n', array('nid'))
    ->condition('n.status', 1)
    ->condition('n.type', 'ed_news')
    ->addTag('node_access')
    ->limit(3)//@todo make limit configurable
    ->orderBy('n.created', 'DESC');

  if (!empty($latest)) {
    $query->condition('n.nid', $latest->nid, '<>');
  }

  $nids = $query->execute()->fetchCol();

  if (!empty($nids)) {
    $content['older-news-heading'] = array(
      '#type' => 'markup',
      '#markup' => '<h2>' . t('Older news') . '</h2>',
    );
    $nodes = node_load_multiple($nids);
    $build = node_view_multiple($nodes);
    $build['pager'] = array(
      '#theme' => 'pager',
      '#weight' => 5,
    );
    $content['old-news'] = $build;
  }

  return $content;
}

