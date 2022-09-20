<?php

/**
 * @file
 * Admin settings for eDidaktikum module.
 */

function edidaktikum_home_page_admin_form() {
  $form = array();

  $form['ed_home_page_intro_notification_message'] = [
    '#type' => 'fieldset',
    '#title' => 'Front page message',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  ];

  $form['ed_home_page_intro_notification_message']['ed_home_page_intro_notification_message'] = [
    '#type' => 'textarea',
    '#title' => t('Message to be displayed on front page'),
    '#description' => t('If this is empty there will be no messages displayed on front page'),
    '#default_value' => variable_get('ed_home_page_intro_notification_message', ''),
    '#required' => FALSE,
  ];

  $form['ed_home_page_intro_notification_message']['ed_show_home_page_intro_notification_message'] = [
    '#type' => 'checkbox',
    '#title' => t('Show notification message on the front page'),
    '#description' => t('If this is checked and message text is not empty, then notification will be displayed.'),
    '#default_value' => variable_get('ed_show_home_page_intro_notification_message', FALSE),
    '#required' => FALSE,
  ];

  $form['ed_home_page_what_text'] = array(
      '#type' => 'textarea',
      '#title' => t('Text to be displayed in What is eDidaktikum section'),
      '#default_value' => variable_get('ed_home_page_what_text', ''),
      '#required' => TRUE,
  );

  $form['ed_home_page_dashboard_text'] = array(
      '#type' => 'textarea',
      '#title' => t('Text to be displayed in Dashboard section'),
      '#default_value' => variable_get('ed_home_page_dashboard_text', ''),
      '#required' => TRUE,
  );

  $form['ed_home_page_groups_text'] = array(
      '#type' => 'textarea',
      '#title' => t('Text to be displayed in Groups and Courses section'),
      '#default_value' => variable_get('ed_home_page_groups_text', ''),
      '#required' => TRUE,
  );

  $form['ed_home_page_collections_text'] = array(
      '#type' => 'textarea',
      '#title' => t('Text to be displayed in Collections section'),
      '#default_value' => variable_get('ed_home_page_collections_text', ''),
      '#required' => TRUE,
  );

  return system_settings_form($form);
}

function edidaktikum_contact_page_admin_form() {
  $form = array();
  $contacts_text = variable_get('ed_contact_page_contacts_text', '');
  $logos_text = variable_get('ed_contact_page_logos_text', '');
  $form['ed_contact_page_contacts_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Contact page contacts text'),
    '#default_value' => (is_array($contacts_text) && isset($contacts_text['value'])) ? $contacts_text['value'] : $contacts_text,
    '#description' => t('Contacts text to display on contact page.'),
    '#required' => FALSE,
  );
  if (is_array($contacts_text) && isset($contacts_text['format'])) {
    $form['ed_contact_page_contacts_text']['#format'] = $contacts_text['format'];
  }
  $form['ed_contact_page_logos_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Contact page logos text'),
    '#default_value' => (is_array($logos_text) && isset($logos_text['value'])) ? $logos_text['value'] : $logos_text,
    '#description' => t('Logos text to display on contact page.'),
    '#required' => FALSE,
  );
  if (is_array($logos_text) && isset($logos_text['format'])) {
    $form['ed_contact_page_logos_text']['#format'] = $logos_text['format'];
  }
  return system_settings_form($form);
}

/**
 * eDidaktikum FAQ admin page.
 */
function edidaktikum_faq_page_admin_form() {
  $form = array();
  $faq_text = variable_get('ed_faq_page_text', '');
  $form['ed_faq_page_text'] = array(
    '#type' => 'text_format',
    '#title' => t('FAQ page text'),
    '#default_value' => (is_array($faq_text) && isset($faq_text['value'])) ? $faq_text['value'] : $faq_text,
    '#description' => t('Text to display on FAQ page.'),
    '#required' => FALSE,
  );
  if (is_array($faq_text) && isset($faq_text['format'])) {
    $form['ed_faq_page_text']['#format'] = $faq_text['format'];
  }

  return system_settings_form($form);
}


/**
 * eDidaktikum Privacy Policy admin page.
 */
function edidaktikum_pp_page_admin_form() {
	$form = array();
	$pp_text = variable_get('ed_pp_page_text', '');
	$form['ed_pp_page_text'] = array(
			'#type' => 'text_format',
			'#title' => t('Privacy Policy page text'),
			'#default_value' => (is_array($pp_text) && isset($pp_text['value'])) ? $pp_text['value'] : $pp_text,
			'#description' => t('Text to display on Privacy Policy page.'),
			'#required' => FALSE,
	);
	if (is_array($pp_text) && isset($pp_text['format'])) {
		$form['ed_pp_page_text']['#format'] = $pp_text['format'];
	}

	return system_settings_form($form);
}

function edidaktikum_configuration_page_admin_form(){
  $form['form']['ed_paging'] = array(
    '#type' => 'textfield',
    '#title' => t('Paging'),
    '#description' => t('How many elements per page'),
    '#default_value' => variable_get('ed_paging'),
    '#required' => TRUE,
  );
  $form['form']['ed_grid_paging'] = array(
    '#type' => 'textfield',
    '#title' => t('Paging in grids'),
    '#description' => t('How many elements per grid based pages. Should be divideable by 4'),
    '#default_value' => variable_get('ed_grid_paging', 20),
    '#required' => TRUE,
  );
  $form['ed_uservoice_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('UserVoice API KEY'),
    '#description' => t('The API KEY to be used with UserVoice service'),
    '#default_value' => variable_get('ed_uservoice_api_key'),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
function edidaktikum_statistics_page_admin_form(){
  $form = array();
  $form['user-table-heading'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>'.t('Users').'</h2>',
  );
  $form['user-table'] = array(
    '#theme' => 'table',
    '#header' => array(t('Role'), t('Qt.')),
    '#rows' => array(
      array(t('Teacher'), get_teacher_qt()),
      array(t('Student'), get_student_qt()),
      array(t('Total'), get_user_qt()),
    ),
  );
  $form['content-table-heading'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>'.t('Content Types').'</h2>',
  );
  $form['content-table'] = array(
    '#theme' => 'table',
    '#header' => array(t('Content Type'), t('Qt.')),
    '#rows' => array(
      array(t('Groups'),get_cluster_qt()),
      array(t('Subgroups'),get_subgroups_qt()),
      array(t('Learning Resources'),get_lr_qt()),
      array(t('News'),get_news_qt()),
      array(t('Events'),get_event_qt()),
      array(t('Given Tasks'),get_task_qt()),
    ),
  );
  return $form;
}

//function get_task_qt(){
//  $query = db_select('node', 'n')
//    ->fields('n', array('nid'))
//    ->addTag('node_access')
//    ->condition('type', 'ed_task');
//
//  return $query->countQuery()->execute()->fetchField();
//}

function get_event_qt(){
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->addTag('node_access')
    ->condition('type', 'ed_event');

  return $query->countQuery()->execute()->fetchField();
}

function get_news_qt(){
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->addTag('node_access')
    ->condition('type', 'ed_news');

  return $query->countQuery()->execute()->fetchField();
}

//function get_lr_qt(){
//  $query = db_select('node', 'n')
//    ->fields('n', array('nid'))
//    ->addTag('node_access')
//    ->condition('type', 'ed_learning_resource');
//
//  return $query->countQuery()->execute()->fetchField();
//}

/**
 * Returns a number of students.
 * Student is any user of the system that has no other roles assigned.
 */
//function get_student_qt(){
//  $query = db_select('users', 'u');
//  $query->leftJoin('users_roles', 'ur', 'ur.uid = u.uid');
//  $query->leftJoin('role', 'r', 'r.rid = ur.rid');
//  $query->fields('u', array('uid'))
//    ->condition('u.uid', 0, '!=')
//    ->isNull('r.name');
//
//  return $query->countQuery()->execute()->fetchField();
//}

function get_subgroups_qt(){
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->addTag('node_access')
    ->condition('type', 'ed_subgroup');

  return $query->countQuery()->execute()->fetchField();
}

//function get_teacher_qt(){
//  $query = db_select('users', 'u');
//  $query->join('users_roles', 'ur', 'ur.uid = u.uid');
//  $query->join('role', 'r', 'r.rid = ur.rid');
//  $query->condition('r.name' , 'teacher')
//    ->addTag('node_access');
//  $query->fields('u',array('uid'));
//
//  return $query->countQuery()->execute()->fetchField();
//}

function get_user_qt(){
  return get_teacher_qt() + get_student_qt();
}

//function get_cluster_qt(){
//  $query = db_select('node', 'n')
//    ->fields('n', array('nid'))
//    ->addTag('node_access')
//    ->condition('type', 'ed_cluster');
//
//  return $query->countQuery()->execute()->fetchField();
//}
