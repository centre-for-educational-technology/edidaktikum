<?php

function _ed_answer_installed_instances() {

  $instances['ed_answer_content'] = array(
    'field_name' => 'ed_field_content',
    'label' => t('Content'),
    'description' => '',
    'settings' => array(
      'text_processing' => TRUE,
    ),
    'widget' => array(
      'settings' => array(
        'rows' => 20,
      ),
    ),
    'required' => TRUE,
  );

  $instances[ED_FIELD_TO_GROUP_MEMBER] = array(
    'field_name' => ED_FIELD_TO_GROUP_MEMBER,
    'label' => 'Specify user',
    'description' => '',
    'widget' => array(
      'type' => 'options_select',
      'module' => 'options',
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => TRUE,
        ),
        'module' => 'entityreference',
      ),
      'teaser' => array(
        'type' => 'hidden',
        'label' => 'hidden',
      ),
      'featured' => array(
        'type' => 'hidden',
        'label' => 'hidden',
      ),
      'front' => array(
        'type' => 'hidden',
        'label' => 'hidden',
      ),
      'dashboard' => array(
        'type' => 'hidden',
        'label' => 'hidden',
      ),
    ),
    'required' => 0,
    'default_value' => NULL,
  );

  return $instances;
}

/**
 * Returns comment instances to be installed.
 */
function _ed_answer_installed_comment_instances() {
  $instances['ed_field_private_comment'] = array(
    'field_name' => 'ed_field_private_comment',
    'label' => 'Private comment',
    'widget' => array(
      'weight' => 2,
      'type' => 'options_onoff',
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'hidden',
      ),
    ),
  );
  
  return $instances;
}

