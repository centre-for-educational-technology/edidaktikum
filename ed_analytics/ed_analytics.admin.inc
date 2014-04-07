<?php

function ed_analytics_settings_admin_form() {
  $form = array();
  $form['form']['ed_analytics_ll_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Learning Locker username'),
    '#default_value' => variable_get('ed_analytics_ll_username'),
    '#description' => t('Username obtained from Learning Locker.'),
    '#required' => TRUE,
  );
  $form['form']['ed_analytics_ll_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Learning Locker password'),
    '#default_value' => variable_get('ed_analytics_ll_password'),
    '#description' => t('Password obtained from Learning Locker.'),
    '#required' => TRUE,
  );
  $form['form']['ed_analytics_ll_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Learning Locker endpoint'),
    '#default_value' => variable_get('ed_analytics_ll_endpoint'),
    '#description' => t('Endpoint URL, where xAPI statements will be sent.'),
    '#required' => TRUE,
  );
  
  
  return system_settings_form($form);
}