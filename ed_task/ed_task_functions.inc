<?php
function _ed_task_installed_fields() {
  $fields['ed_task_due_date'] = array(
    'field_name' => 'ed_task_due_date',
    'label' => t('Due Date'),
    'type' => 'datestamp',
    'cardinality' => 1,
    'settings' => array(
      'input_format' => 'd.m.Y',
      'granularity' => array('year', 'month', 'day'),
    ),
  );
  $fields['ed_field_competence'] = array(
    'field_name' => 'ed_field_competence',
    'type' => 'taxonomy_term_reference',
    'entity_types' => array('node'),
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'settings' => array(
      'allowed_values' => array(
        array(
          'vocabulary' => 'ed_competence_voc',
          'parent' => 0,
        ),
      ),
    ),
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
  $instances['ed_field_competence'] = array(
    'field_name' => 'ed_field_competence',
    'label' => t('Competence'),
    'description' => '',
    'widget' => array(
      'type' => 'term_reference_tree',
      'settings' => array(
        'start_minimized' => TRUE,
        'select_parents' => TRUE,
      ),
    ),
    'required' => FALSE,
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'type' => 'term_reference_tree',
        'settings' => array(),
      ),
    ),
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
