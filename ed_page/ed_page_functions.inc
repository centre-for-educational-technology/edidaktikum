<?php
function _ed_page_installed_fields(){
  $fields['ed_page_tags'] = array(
    'field_name' => 'ed_page_tags',
	  'label' => t('Tags'),
	  'type' => 'taxonomy_term_reference',
	  'cardinality' => FIELD_CARDINALITY_UNLIMITED,
	  'settings' => array(
	    'allowed_values' => array(
	      array(
		      'vocabulary' => 'ed_page_tags_voc',
		    ),
	    ),
	  ),
  );
  return $fields;
}
function _ed_page_installed_instances() {
  $instances['ed_page_content'] = array(
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
  $instances['ed_page_tags'] = array(
    'field_name' => 'ed_page_tags',
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

  return $instances;
}