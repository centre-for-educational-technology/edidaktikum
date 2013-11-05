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

  return $instances;
}
