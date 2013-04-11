<?php

/**
 * @file
 * Page callbacks for eDidaktikum module.
 */


/**
 * eDidaktikum home page.
 */
function edidaktikum_home_page() {

  drupal_set_title('');

  $content['intro'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'intro',
    ),
  );
  $content['intro']['image'] = array(
    '#type' => 'markup',
    '#markup' => '<img src="'.variable_get('ed_home_page_intro_image_url', '').'" />',
  );
  $content['intro']['intro-text'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'intro-text',
    ),
  );
  $content['intro']['intro-text']['text'] = array(
    '#type' => 'markup',
    '#markup' => variable_get('ed_home_page_intro_text', ''),
  );

  $content['latest-content'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'latest-content',
    ),
  );
  $content['latest-content']['title'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>' . t('Latest content') .'</h2>',
  );

  if (module_exists('ed_news')) {
    $latest_news = ed_news_get_latest_news();
    if (!empty($latest_news)) {
      $content['latest-content']['latest-news'] = node_view($latest_news, 'teaser');
    }
  }

  if (module_exists('ed_event')) {
    $latest_event = ed_event_get_latest_event();
    if (!empty($latest_event)) {
      $content['latest-content']['latest-event'] = node_view($latest_event, 'teaser');
    }
  }

  $content['tour'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'tour',
    ),
  );
  $content['tour']['text'] = array(
    '#type' => 'markup',
    '#markup' => variable_get('ed_home_page_tour_text', ''),
  );

  return $content;
}

