<?php

/**
 * @file
 * Admin settings for Collections part of eDidaktikum module
 */

/**
 * A form build callback for collections administration.
 */
function ed_collection_draft_collections_page_admin_form(){
  $form = array();
  $nids = ed_get_drafts_by_node_type('ed_collection');

  if(!$nids){
    $form['form']['draft_collections'] = array(
      '#type' => 'markup',
      '#markup' => '<h2>' . t('No Draft Collections Found') . '</h2>',
    );
    return $form;
  }

  $nodes = node_load_multiple($nids);
  $options = array();
  foreach($nodes as $node){
    $options[$node->nid] = l($node->title, 'node/' . $node->nid)
      . " - "
      . $node->name
      . " - "
      . format_date($node->created,'custom','d/m/Y');
  }
  $form['form']['collections'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose Collections to be published'),
    '#options' => $options,
  );

  $form['form']['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Publish'),
  );

  return $form;
}

/**
 * A validation callback for collections administration.
 */
function ed_collection_draft_collections_page_admin_form_validate($form, &$form_state) {
  $checked = array_values(array_unique($form_state['values']['collections']));

  if (count($checked) < 1 || (count($checked) == 1 && $checked[0] == 0)) {
    form_set_error('collections', t('No collections selected.'));
  }
}

/**
 * A submit callback for collections administration.
 */
function ed_collection_draft_collections_page_admin_form_submit($form, &$form_state) {
  foreach ($form_state['values']['collections'] as $key => $nid) {
    if ($nid !== 0) {
      $node = node_load($nid);
      if ($node) {
        $node->status = NODE_PUBLISHED;
        node_save($node);
      }
    }
  }

  drupal_set_message(t('Checked nodes have been published.'));
}

