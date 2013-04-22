<?php

/**
 * @file
 * Admin settings for eDidaktikum module.
 */

function edidaktikum_home_page_admin_form() {
  $form = array();
  $form['ed_home_page_intro_image_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Home page intro image URL'),
    '#default_value' => variable_get('ed_home_page_intro_image_url', ''),
    '#description' => t("Intro image to display in home page."),
    '#required' => FALSE,
  );
  $form['ed_home_page_intro_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Home page intro text'),
    '#default_value' => variable_get('ed_home_page_intro_text', ''),
    '#description' => t("Intro text to display in home page."),
    '#required' => FALSE,
  );
  $form['ed_home_page_tour_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Home page tour text'),
    '#default_value' => variable_get('ed_home_page_tour_text', ''),
    '#description' => t("Tour text to display in home page."),
    '#required' => FALSE,
  );
  return system_settings_form($form);
}

function edidaktikum_contact_page_admin_form() {
  $form = array();
  $form['ed_contact_page_contacts_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Contact page contacts text'),
    '#default_value' => variable_get('ed_contact_page_contacts_text'),
    '#description' => t('Contacts text to display on contact page.'),
    '#required' => FALSE,
  );
  $form['ed_contact_page_logos_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Contact page logos text'),
    '#default_value' => variable_get('ed_contact_page_logos_text'),
    '#description' => t('Logos text to display on contact page.'),
    '#required' => FALSE,
  );
  return system_settings_form($form);
}

