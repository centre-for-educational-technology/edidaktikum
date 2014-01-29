<?php

function _ed_bookmark_installed_fields() {
  $fields['ed_bookmark_type'] = array(
    'field_name' => 'ed_bookmark_type',
	  'label' => t('Type'),
	  'type' => 'list_integer',
	  'cardinality' => 1,
	  'foreign keys' => array(),
	  'indexes' => array(
	    'value' => array(
	      0 => 'value',
	    ),
	  ),
	  'module' => 'list',
	  'settings' => array(
	    'allowed_values_function' => '_ed_bookmark_type_list',
	  ),
  );
  $fields['ed_bookmark_tags'] = array(
    'field_name' => 'ed_bookmark_tags',
	  'label' => t('Tags'),
	  'type' => 'taxonomy_term_reference',
	  'cardinality' => FIELD_CARDINALITY_UNLIMITED,
	  'settings' => array(
	    'allowed_values' => array(
	      array(
		      'vocabulary' => 'ed_bookmark_tags_voc',
		    ),
	    ),
	  ),
  );
  $fields['ed_bookmark_url'] = array(
    'field_name' => 'ed_bookmark_url',
    'label' => t('Url'),
    'type' => 'url',
    'cardinality' => 1,
    'locked' => FALSE,
  );
  return $fields;
}

function _ed_bookmark_installed_instances(){
  $instances['ed_bookmark_url'] = array(
    'field_name' => 'ed_bookmark_url',
    'label' => t('URL'),
    'description' => '',
    'settings' => array(
      'title_field' => FALSE,
      'title_fetch' => FALSE,
    ),
    'required' => TRUE,
  );
  $instances['ed_bookmark_tags'] = array(
    'field_name' => 'ed_bookmark_tags',
	  'label' => t('Tags'),
	  'description' => t(''),
	  'type' => 'taxonomy_term_reference',
	  'widget' => array(
	    'type' => 'taxonomy_autocomplete',
	    'weight' => 4,
	  ),
	  'display' => array(
	    'default' => array(
  	    'label' => 'above',
    		'settings' => array(),
    		'weight' => 4,
  	  ),
	  ),
  );
  $instances['ed_bookmark_type'] = array(
    'field_name' => 'ed_bookmark_type',
	  'label' => t('Type'),
	  'description' => t(''),
	  'default_value' => NULL,
	  'display' => array(
	    'default' => array(
	      'label' => 'above',
		    'module' => 'list',
		    'settings' => array(),
		    'type' => 'list_default',
		    'weight' => 3,
	    ),
	    'teaser' => array(
	      'label' => 'inline',
		    'settings' => array(),
		    'type' => 'list_default',
		    'weight' => 1,
	    ),
	  ),
	  'required' => FALSE,
	  'settings' => array(
	    'user_register_form' => FALSE,
	  ),
	  'widget' => array(
	    'active' => 1,
	    'module' => 'options',
	    'settings' => array(),
	    'type' => 'options_select',
	    'weight' => 3,
	  ),
  );
  return $instances;
}

function _ed_bookmark_type_list(){
  $vocab = taxonomy_vocabulary_machine_name_load('ed_bookmark_voc');
  $vid = $vocab->vid;
  $results = db_select('taxonomy_term_data', 't')
    ->fields('t', array('tid', 'name'))
	  ->condition("t.vid", $vid)
	  ->execute();
  $options = array();
  foreach($results as $term) {
	  $options[$term->tid] = $term->name;
  }
  return $options;
}

