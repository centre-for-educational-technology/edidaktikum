<?php
function _ed_blog_installed_fields(){
  $fields = array();
  /*
  $fields['ed_blog_tags'] = array(
    'field_name' => 'ed_blog_tags',
	  'label' => t('Tags'),
	  'type' => 'taxonomy_term_reference',
	  'cardinality' => FIELD_CARDINALITY_UNLIMITED,
	  'settings' => array(
	    'allowed_values' => array(
	      array(
		      'vocabulary' => 'ed_blog_tags_voc',
		    ),
	    ),
	  ),
  );*/
  return $fields;
}
function _ed_blog_installed_instances() {
  $instances['ed_blog_content'] = array(
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
  $instances['ed_blog_tags'] = array(
    'field_name' => 'field_tags',
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
  $instances['ed_field_competence'] = array(
    'field_name' => 'ed_field_competence',
    'entity_type' => 'node',
      'bundle' => 'ed_blog',
      'label' => t('Add competence'),
      'description' => '',
      'widget' => array(
        'type' => 'term_reference_tree',
        'settings' => array(
          'start_minimized' => TRUE,
          'leaves_only' => TRUE,
          'select_parents' => FALSE,
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

  return $instances;
}
