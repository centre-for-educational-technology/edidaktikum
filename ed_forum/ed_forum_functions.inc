<?php

function _ed_forum_installed_instances() {
  $instances['ed_forum_content'] = array(
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
