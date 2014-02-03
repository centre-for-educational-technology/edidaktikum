<?php

/**
 * @file
 * Page callbacks for ed_news module.
 */

/**
 * Displays a listing page for ed_news nodes.
 */
function ed_news_listing_page() {
  drupal_add_feed('news/rss', t('Latest news'));

  $content = array();

  if(node_access('create', 'ed_news')){
    $content['add-new'] = array(
      '#type' => 'link',
      '#title' => t('Add new news'),
      '#href' => 'node/add/ed-news',
      '#prefix' => '<div class="ed-add-new-node ed-add-new-news">',
      '#suffix' => '</div>',
    );
  }

  // Latest news within a container
  $latest = ed_news_get_latest_news();
  if (!empty($latest)) {
    $content['latest-news'] = node_view($latest, 'teaser');
  }

  // Old news within a container
  $query = db_select('node', 'n')
    ->extend('PagerDefault')
    ->fields('n', array('nid'))
    ->condition('n.status', 1)
    ->condition('n.type', 'ed_news')
    ->addTag('node_access')
    ->limit(ed_get_paging_nr())
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

