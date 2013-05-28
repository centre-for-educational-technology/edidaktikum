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
  $fields['to_user'] = array(
    'translatable' => '0',
    'entity_types' => array(),
    'settings' => array(
      'target_type' => 'user',
      'handler' => 'fullname',
      'handler_settings' => array(
        'target_bundles' => array(),
        'sort' => array(
          'type' => 'none',
        ),
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
      ),
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
      'module' => 'field_sql_storage',
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_to_user' => array(
              'target_id' => 'field_to_user_target_id',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_to_user' => array(
              'target_id' => 'field_to_user_target_id',
            ),
          ),
        ),
      ),
    ),
    'foreign keys' => array(
      'node' => array(
        'table' => 'node',
        'columns' => array(
          'target_id' => 'nid',
        ),
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        'target_id',
      ),
    ),
    'field_name' => 'field_to_user',
    'type' => 'entityreference',
    'module' => 'entityreference',
    'active' => '1',
    'locked' => '0',
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'deleted' => '0',
    'columns' => array(
      'target_id' => array(
        'description' => 'The id of the target entity.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ),
    'bundles' => array(
      'node' => array(
        'ed_task',
      ),
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

  $instances['to_user'] = array(
    'label' => 'to user',
    'widget' => array(
      'type' => 'entityreference_autocomplete_tags',
      'weight' => '8',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'size' => 60,
        'path' => '',
      ),
      'module' => 'entityreference',
    ),
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'entityreference_label',
        'settings' => array(
          'link' => FALSE,
        ),
        'module' => 'entityreference',
        'weight' => 9,
      ),
      'teaser' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
      'featured' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
      'front' => array(
        'type' => 'hidden',
        'label' => 'above',
        'settings' => array(),
        'weight' => 0,
      ),
    ),
    'required' => FALSE,
    'description' => '',
    'field_name' => 'field_to_user',
    'entity_type' => 'node',
    'bundle' => 'ed_task',
    'deleted' => '0',
    'default_value' => NULL,
  );
  return $instances;
}
