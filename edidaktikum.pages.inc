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
  if (variable_get('ed_home_page_intro_image_url')) {
    $content['intro']['image'] = array(
      '#type' => 'markup',
      '#markup' => '<img src="'.variable_get('ed_home_page_intro_image_url', '').'" />',
    );
  }
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

  if (module_exists('ed_news')) {
    $latest_news = ed_news_get_latest_news();
    if (!empty($latest_news)) {
      $content['latest-content']['news'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'latest-news',
        ),
      );
      $content['latest-content']['news']['title'] = array(
        '#type' => 'markup',
        '#markup' => '<h1>' . t('News') .'</h1>',
      );
      $content['latest-content']['news']['content'] = node_view($latest_news, 'front');
    }
  }

  if (module_exists('ed_event')) {
    $latest_event = ed_event_get_latest_event();
    if (!empty($latest_event)) {
      $content['latest-content']['event'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'latest-event',
        ),
      );
      $content['latest-content']['event']['title'] = array(
        '#type' => 'markup',
        '#markup' => '<h1>' . t('Event') .'</h1>',
      );
      $content['latest-content']['event']['content'] = node_view($latest_event, 'front');
    }
  }
  if (module_exists('ed_learning_resource')) {
    $latest_resource = _ed_learning_resource_get_latest();
    if (!empty($latest_resource)) {
      $content['latest-content']['resource'] = array(
        '#type' => 'container',
        '#attributes' => array(
          'id' => 'latest-resource',
        ),
      );
      $content['latest-content']['resource']['title'] = array(
        '#type' => 'markup',
        '#markup' => '<h1>' . t('Learning Resource') . '</h1>',
      );
      $content['latest-content']['resource']['content'] = node_view($latest_resource, 'front');
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

/**
 * eDidaktikum contact page.
 */
function edidaktikum_contact_page() {

  drupal_set_title(t('Contact Us'));

  $content['contacts'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contacts',
    ),
  );
  $content['contacts']['contacts-text'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contacts-text',
    ),
  );
  $contacts_text = variable_get('ed_contact_page_contacts_text', '');
  if (is_array($contacts_text)) {
    $contacts_text = check_markup($contacts_text['value'], $contacts_text['format']);
  }
  $content['contacts']['contacts-text']['text'] = array(
    '#type' => 'markup',
    '#markup' => $contacts_text,
  );
  $content['contacts']['logos-text'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'logos-text',
    ),
  );
  $logos_text = variable_get('ed_contact_page_logos_text', '');
  if (is_array($logos_text)) {
    $logos_text = check_markup($logos_text['value'], $logos_text['format']);
  }
  $content['contacts']['logos-text']['text'] = array(
    '#type' => 'markup',
    '#markup' => $logos_text,
  );

  return $content;
}

