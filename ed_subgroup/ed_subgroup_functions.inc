<?php

function _ed_subgroup_installed_instances(){
  $instances = array();
  $instances['ed_subgroup_excerpt'] = array(
    'field_name' => 'ed_field_excerpt',
    'label' => t('Excerpt'),
    'description' => '',
    'required' => TRUE,
    'display' => array(
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'text_trimmed',
        'weight' => 5,
      ),
    ),
  );
  $instances['ed_subgroup_content'] = array(
    'field_name' => 'ed_field_content',
    'label' => t('Content'),
    'description' => '',
    'widget' => array(
      'settings' => array(
        'rows' => 20,
      ),
    ),
    'required' => TRUE,
  );
  return $instances;
}
