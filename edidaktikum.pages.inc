<?php

/**
 * @file
 * Page callbacks for eDidaktikum module.
 */


/**
 * eDidaktikum home page.
 */
function edidaktikum_home_page() {

  drupal_set_title('');

  return [];
}

/**
 * eDidaktikum contact page.
 */
function edidaktikum_contact_page() {

  drupal_set_title(t('Contact Us'));

  $content['contacts'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contacts',
    ),
  );
  $content['contacts']['contacts-text'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'contacts-text',
    ),
  );
  $contacts_text = variable_get('ed_contact_page_contacts_text', '');
  if (is_array($contacts_text)) {
    $contacts_text = check_markup($contacts_text['value'], $contacts_text['format']);
  }
  $content['contacts']['contacts-text']['text'] = array(
    '#type' => 'markup',
    '#markup' => $contacts_text,
  );
  $content['contacts']['logos-text'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'logos-text',
    ),
  );
  $logos_text = variable_get('ed_contact_page_logos_text', '');
  if (is_array($logos_text)) {
    $logos_text = check_markup($logos_text['value'], $logos_text['format']);
  }
  $content['contacts']['logos-text']['text'] = array(
    '#type' => 'markup',
    '#markup' => $logos_text,
  );

  return $content;
}

/**
 * eDidaktikum FAQ page.
 */
function edidaktikum_faq_page() {
	drupal_goto('https://edidaktikum.uservoice.com');
	/*drupal_set_title(t('FAQ'));

	$content['faq'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'faq',
		),
	);
	$content['faq']['faq-text'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'faq-text',
		),
	);
	$faq_text = variable_get('ed_faq_page_text', '');
	if (is_array($faq_text)) {
		$faq_text = check_markup($faq_text['value'], $faq_text['format']);
	}
	$content['faq']['faq-text']['text'] = array(
		'#type' => 'markup',
		'#markup' => $faq_text,
	);

	return $content;*/
}


/**
 * eDidaktikum Privacy Policy page.
 */
function edidaktikum_pp_page() {

	drupal_set_title(t('Privacy Policy'));

	$content['pp'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'pp',
		),
	);
	$content['pp']['pp-text'] = array(
		'#type' => 'container',
		'#attributes' => array(
			'id' => 'pp-text',
		),
	);
	$pp_text = variable_get('ed_pp_page_text', '');
	if (is_array($pp_text)) {
		$pp_text = check_markup($pp_text['value'], $pp_text['format']);
	}
	$content['pp']['pp-text']['text'] = array(
		'#type' => 'markup',
		'#markup' => $pp_text,
	);

	return $content;
}



/**
 * eDidaktikum For schools page.
 */
function edidaktikum_schools_page() {

	drupal_set_title(t('Schools'));

  return [];
}
