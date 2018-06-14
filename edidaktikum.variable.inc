<?php

/**
 * @file
 * Variable definitions for eDidaktikum module.
 */

function edidaktikum_variable_info($options) {
  $variables['ed_contact_page_contacts_text'] = array(
    'type' => 'text_format',
    'title' => t('Contact page contacts text', array(), $options),
    'description' => t('Contacts text to display on contact page.', array(), $options),
    'required' => FALSE,
    'group' => 'edidaktikum_settings',
  );
  $variables['ed_contact_page_logos_text'] = array(
    'type' => 'text_format',
    'title' => t('Contact page logos text', array(), $options),
    'description' => t('Logos text to display on contact page.', array(), $options),
    'required' => FALSE,
    'group' => 'edidaktikum_settings',
  );
  $variables['ed_faq_page_text'] = array(
    'type' => 'string',
    'title' => t('FAQ page text', array(), $options),
    'description' => t('Text to display on FAQ page.', array(), $options),
    'required' => FALSE,
    'group' => 'edidaktikum_settings',
  );
	$variables['ed_pp_page_text'] = array(
			'type' => 'string',
			'title' => t('Privacy Policy page text', array(), $options),
			'description' => t('Text to display on Privacy Policy page.', array(), $options),
			'required' => FALSE,
			'group' => 'edidaktikum_settings',
	);
  $variables['ed_home_page_intro_notification_message'] = array(
    'type' => 'string',
    'title' => t('Message to be displayed on front page', array(), $options),
    'description' => t('If this is empty there will be no messages displayed on front page', array(), $options),
    'required' => FALSE,
    'group' => 'edidaktikum_settings',
  );

  $variables['ed_home_page_what_text'] = array(
      'type' => 'string',
      'title' => t('Text to be displayed in What is eDidaktikum section', array(), $options),
      'required' => TRUE,
      'group' => 'edidaktikum_settings',
  );

  $variables['ed_home_page_dashboard_text'] = array(
      'type' => 'string',
      'title' => t('Text to be displayed in Dashboard section', array(), $options),
      'required' => TRUE,
      'group' => 'edidaktikum_settings',
  );

  $variables['ed_home_page_groups_text'] = array(
      'type' => 'string',
      'title' => t('Text to be displayed in Groups and Courses section', array(), $options),
      'required' => TRUE,
      'group' => 'edidaktikum_settings',
  );

  $variables['ed_home_page_collections_text'] = array(
      'type' => 'string',
      'title' => t('Text to be displayed in Collections section', array(), $options),
      'required' => TRUE,
      'group' => 'edidaktikum_settings',
  );



  return $variables;
}

function edidaktikum_variable_group_info() {
  $groups['edidaktikum_settings'] = array(
    'title' => t('eDidaktikum settings'),
    'description' => t('eDidaktikum settings'),
    'access' => 'administer site configuration',
    'path' => array('admin/config/edidaktikum/home-page', 'admin/config/edidaktikum/contact-page'),
  );
  return $groups;
}
