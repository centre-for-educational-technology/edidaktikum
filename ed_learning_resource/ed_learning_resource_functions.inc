<?php

/*
 * @return array
 *   Returns an array to be used in field_create_field()
 */
function _ed_learning_resource_installed_fields() {

  //Learning Resource "Methodological Guide" field
  $fields['ed_learning_resource_mg'] = array(
    'field_name' => 'ed_learning_resource_mg',
	  'label' => t('Methodological Guide'),
	  'type' => 'text_long',
	  'module' => 'text',
	  'translatable' => '1',
	  'foreign keys' => array(
  	  'format' => array(
	      'columns' => array(
		      'format' => 'format',
		    ),
		    'table' => 'filter_format',
	    ),
	  ),
	  'indexes' => array(
	    'format' => array(
	      0 => 'format',
	    ),
	  ),
  );

  //Learning Resource "Type" field
  $fields['ed_learning_resource_type'] = array(
    'field_name' => 'ed_learning_resource_type',
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
	    'allowed_values_function' => '_ed_learning_resource_type_list',
	  ),
  );

  // Learning Resource "Language" field
  $fields['ed_learning_resource_language'] = array(
    'field_name' => 'ed_learning_resource_language',
	  'label' => t('Language'),
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
	    'allowed_values_function' => '_ed_learning_resource_language_list',
	  ),
  );

  // Learning Resource "Creating Time" field
  $fields['ed_learning_resource_date'] = array(
    'field_name' => 'ed_learning_resource_date',
	  'label' => t('Creating Time'),
	  'type' => 'date',
	  'cardinality' => 1,
	  'settings' => array(
	    'input_format' => 'd.m.Y',
      'granularity' => array('year', 'month', 'day'),
	  ),
  );

  // Learning Resource "Tags" field
  $fields['ed_learning_resource_tags'] = array(
    'field_name' => 'ed_learning_resource_tags',
	  'label' => t('Tags'),
	  'type' => 'taxonomy_term_reference',
	  'cardinality' => FIELD_CARDINALITY_UNLIMITED,
	  'settings' => array(
	    'allowed_values' => array(
	      array(
		      'vocabulary' => 'ed_learning_resource_tags_voc',
		      'parent' => 0,
		    ),
	    ),
	  ),
  );

  // Learning Resource "Author" field
  $fields['ed_learning_resource_authors'] = array(
    'field_name' => 'ed_learning_resource_authors',
	  'label' => t('Author'),
	  'type' => 'taxonomy_term_reference',
	  'cardinality' => FIELD_CARDINALITY_UNLIMITED,
	  'settings' => array(
	    'allowed_values' => array(
	      array(
	        'vocabulary' => 'ed_learning_resource_authors_voc',
		      'parent' => 0,
		    ),
	    ),
	  ),
  );

  // Learning Resource "Additional Requirements" field
  $fields['ed_learning_resource_add_req'] = array(
    'field_name' => 'ed_learning_resource_add_req',
	  'label' => t('Additional Requirements'),
	  'type' => 'text_long',
	  'module' => 'text',
	  'foreign keys' => array(
	    'format' => array(
	      'columns' => array(
		      'format' => 'format',
		    ),
		    'table' => 'filter_format',
	    ),
	  ),
	  'indexes' => array(
	    'format' => array(
	        0 => 'format',
	    ),
	  ),
  );
  return $fields;
}

/*
 * @return array
 *   Returns an array to be used in field_create_instance().
 */

function _ed_learning_resource_installed_instances() {

  // Learning Resource "Excerpt" instance
  $instances['ed_field_excerpt'] = array(
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

  // Learning Resource "Content" instance
  $instances['ed_field_content'] = array(
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
    'display' => array(
      'featured' => array(
        'label' => 'hidden',
        'type' => 'text_default',
      ),
    ),
  );

  // Learning Resource "Methodological Guide" instance
  $instances['ed_learning_resource_mg'] = array(
    'field_name' => 'ed_learning_resource_mg',
	  'type' => 'text_long',
	  'label' => t('Methodological Guide'),
	  'widget' => array(
	    'settings' => array(
	      'rows' => '5',
	    ),
	    'type' => 'text_textarea',
	    'weight' => 2,
	  ),
	  'display' => array(
	    'default' => array(
	      'label' => 'above',
		    'settings' => array(),
		    'type' => 'text_default',
		    'weight' => 2,
	    ),
	    'teaser' => array(
	      'label' => 'above',
		    'settings' => array(),
		    'type' => 'hidden',
		    'weight' => 2,
	    ),
	  ),
	  'required' => 0,
	  'settings' => array(
	    'text_processing' => '0',
	    'user_register_form' => FALSE,
	  ),
  );

  // Learning Resource "Type" instance
  $instances['ed_learning_resource_type'] = array(
    'field_name' => 'ed_learning_resource_type',
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
	  'required' => 1,
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

  // Learning Resource "Language" instance
  $instances['ed_learning_resource_language'] = array(
    'field_name' => 'ed_learning_resource_language',
  	'label' => t('Language'),
	  'description' => t(''),
	  'default_value' => NULL,
	  'display' => array(
	    'default' => array(
	      'label' => 'above',
		    'module' => 'list',
		    'settings' => array(),
		    'type' => 'list_default',
		    'weight' => 5,
	    ),
	    'teaser' => array(
	      'label' => 'inline',
		    'settings' => array(),
		    'type' => 'list_default',
		    'weight' => 2,
	    ),
	  ),
	  'required' => 1,
	  'settings' => array(
	    'user_register_form' => FALSE,
	  ),
	  'widget' => array(
	    'active' => 1,
	    'module' => 'options',
	    'settings' => array(),
	    'type' => 'options_select',
	    'weight' => 5,
	  ),
  );

  // Learning Resource "Creation Date" instance
  $instances['ed_learning_resource_date'] = array(
    'field_name' => 'ed_learning_resource_date',
	  'label' => 'Creating Time',
	  'description' => t(''),
	  'widget' => array(
	    'type' => 'date_popup',
	    'weight' => 6,
	    'settings' => array(
	      'input_format' => 'd.m.Y',
		  'increment' => '1',
	    ),
	  ),
  	'display' => array(
	    'default' => array(
	      'weight' => 6,
	    ),
	    'teaser' => array(
	      'label' => 'inline',
		    'type' => 'date',
		    'settings' => array(),
		    'weight' => 4,
	    ),
	  ),
	  'settings' => array(
	    'default_value' => 'now',
	  ),
  );

  //Learning Resource "Tags" instance
  $instances['ed_learning_resource_tags'] = array(
    'field_name' => 'ed_learning_resource_tags',
	  'label' => t('Tags'),
	  'description' => t('Separate with commas. E.g. Mathematics, Force training, Jedi Mind Tricks'),
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

  //Learning Resource "Author" instance
  $instances['ed_learning_resource_authors'] = array(
    'field_name' => 'ed_learning_resource_authors',
	  'label' => t('Authors'),
	  'description' => t('Separate with commas. E.g. Mace Windu, Obi-wan Kenobi'),
	  'type' => 'taxonomy_term_reference',
	  'widget' => array(
	    'type' => 'taxonomy_autocomplete',
	    'weight' => 7,
	  ),
	  'display' => array(
	    'default' => array(
	      'label' => 'above',
		  'settings' => array(),
		  'weight' => 7,
	    ),
	    'teaser' => array(
	      'label' => 'inline',
		    'settings' => array(),
		    'type' => 'taxonomy_term_reference',
		    'weight' => 3,
	    ),
	  ),
  );

  //Learning Resource "Additional Requirements" instance
  $instances['ed_learning_resource_add_req'] = array(
    'field_name' => 'ed_learning_resource_add_req',
	  'type' => 'text_long',
	  'label' => t('Additional Requirements'),
	  'widget' => array(
	    'settings' => array(
	      'rows' => 5,
	    ),
	    'type' => 'text_textarea',
	    'weight' => 8,
	  ),
	  'display' => array(
	    'default' => array(
	      'label' => 'above',
		    'settings' => array(),
		    'type' => 'text_default',
		    'weight' => 8,
	    ),
	  ),
	  'required' => 0,
	  'settings' => array(
	    'text_processing' => 0,
	    'user_register_form' => FALSE,
	  ),
  );

  // Learning Resource "Featured Image" instance.
  $instances['ed_field_featured_image'] = array(
    'field_name' => 'ed_field_featured_image',
    'label' => t('Featured Image'),
    'description' => '',
    'settings' => array(
      'file_directory' => 'ed_learning_resource_featured_images'
    ),
    'widget' => array(
      'type' => 'image_image',
    ),
    'required' => FALSE,
  );

  //Learning Resource "Category" instance.
  $instances['ed_field_category'] = array(
    'field_name' => 'ed_field_category',
    'label' => t('Category'),
    'description' => '',
    'widget' => array(
      'type' => 'term_reference_tree',
    ),
    'required' => TRUE,
    'display' => array(
      'default' => array(
        'label' => 'above',
        'type' => 'term_reference_tree',
      ),
    ),
  );

  return $instances;
}

/*
 * @return array
 *   Grabs the list of different learning resource types
 *   from the db(vocabulary).
 */
function _ed_learning_resource_type_list() {
  $vocab = taxonomy_vocabulary_machine_name_load('ed_learning_resource_type_voc');
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

/*
 * @return array
 *   Grabs the list of different learning resource languages
 *   from the db(vocabulary).
 */
function _ed_learning_resource_language_list() {
  $vocab = taxonomy_vocabulary_machine_name_load('ed_learning_resource_language_voc');
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
