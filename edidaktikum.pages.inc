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
  
  $content['intro-text']['text'] = array(
    '#type' => 'markup',
    '#markup' => '<div class="login-intro-text">'.variable_get('ed_home_page_intro_text', '').'</div>',
  );

  if(!(user_is_logged_in())){
    $content['login'] = Array(
      '#type' => 'markup',
      '#markup' => '<div class="login-center">'.l(t('Sign in / Register'), 'user').'</div>',
    );
  }

  $content['intro'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'intro',
    ),
  );
  
  $content['intro']['image'] = array(
    '#type' => 'markup',
    '#markup' => '<div id="img"></div>',
  );

  
  $content['intro']['intro-text'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'intro-text',
    ),
  );

  $content['latest-content'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'latest-content',
    ),
  );

  if (module_exists('ed_news')) {
    $news = node_load(variable_get('news_to_front'));
    if (!empty($news)) {
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
      $content['latest-content']['news']['content'] = node_view($news, 'front');
    }
  }

  if (module_exists('ed_event')) {
    $event = node_load(variable_get('event_to_front'));
    if (!empty($event)) {
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
      $content['latest-content']['event']['content'] = node_view($event, 'front');
    }
  }
  if (module_exists('ed_learning_resource')) {
    $resource = node_load(variable_get('resource_to_front'));
      if (!empty($resource)) {
        $content['latest-content']['resource'] = array(
          '#type' => 'container',
          '#attributes' => array(
           'id' => 'promoted-resource',
          ),
        );
        $content['latest-content']['resource']['title'] = array(
          '#type' => 'markup',
          '#markup' => '<h1>' . t('Learning Resource') . '</h1>',
        );
        $content['latest-content']['resource']['content'] = node_view($resource, 'front');
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

/**
 * eDidaktikum FAQ page.
 */
function edidaktikum_faq_page() {

  drupal_set_title(t('FAQ'));

  $content['faq'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'faq',
    ),
  );
  $content['faq']['faq-text'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'faq-text',
    ),
  );
  $faq_text = variable_get('ed_faq_page_text', '');
  if (is_array($faq_text)) {
    $faq_text = check_markup($faq_text['value'], $faq_text['format']);
  }
  $content['faq']['faq-text']['text'] = array(
    '#type' => 'markup',
    '#markup' => $faq_text,
  );

  return $content;
}

