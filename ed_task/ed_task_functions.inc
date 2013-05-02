<?php
function _ed_task_installed_fields() {
  $fields['ed_task_due_date'] = array(
    'field_name' => 'ed_task_due_date',
    'label' => t('Due Date'),
    'type' => 'date',
    'cardinality' => 1,
    'settings' => array(
      'input_format' => 'd.m.Y',
      'granularity' => array('year', 'month', 'day'),
    ),
  );

  $fields['ed_task_to_user'] = array(
    'field_name' => 'ed_task_to_user',
    'label' => t('to user'),
    'type' => 'user_reference',
    'settings' => array(
      'referenceable_roles' => array('2' => '2', '3' => '3'),
      'referenceable_status' => array('1' => '1','0'=>'0'),
    ),
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'default_widget' => 'user_reference_autocomplete',
    'default_formatter' => 'user_reference_plain',    //user_reference_default, user_reference_uid, user_reference_path

  );

  return $fields;
}

function _ed_task_installed_instances() {
  $instances['ed_field_content'] = array(
    'field_name' => 'ed_field_content',
    'label' => t('Description'),
    'description' => '',
    'settings' => array(
      'text_processing' => TRUE,
    ),
    'widget' => array(
      'settings' => array(
        'rows' => 30,
      ),
    ),
    'required' => TRUE,
    'display' => array(
      'featured' => array(
        'label' => 'hidden',
        'type' => 'text_default',
      ),
    ),
  );

  $instances['ed_task_due_date'] = array(
    'field_name' => 'ed_task_due_date',
    'label' => 'Due Date',
    'description' => '',
    'widget' => array(
      'type' => 'date_popup',
      'weight' => 4,
      'settings' => array(
        'input_format' => 'd.m.Y',
        'increment' => '1',
      ),
    ),
    'display' => array(
      'default' => array(
        'weight' => 4,
        'label' => 'inline',
        'type' => 'date',
      ),
    ),
    'settings' => array(
      'default_value' => 'now',
    ),
  );

  $instances['ed_task_to_user'] = array(
    'field_name' => 'ed_task_to_user',
    'label' => t('To users: '),
    'description' => '',
    'required' => 0,
    'widget' => array(
      'weight' => 2,
      'type' => 'user_reference_autocomplete',
      'module' => 'user_reference',
      'active' => 1,
      'settings' => array(
        'autocomplete_match' => 'contains'
      ),
    ),
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'format' => 'default'
      ),
    ),
  );

  $instances['ed_field_category'] = array(
    'field_name' => 'ed_field_category',
    'label' => t('category'),
    'description' => '',
    'widget' => array(
      'type' => 'term_reference_tree',
      'settings' => array(
        'select_parents' => TRUE,
      ),
    ),
    'required' => TRUE,
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'term_reference_tree',
        'settings' => array(),
      ),
    ),
  );
  return $instances;
}
