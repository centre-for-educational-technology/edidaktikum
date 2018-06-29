<?php

/**
 * Plugin definition.
 */
$plugin = [
  'title' => t('Shows delete when answer task removed.'),
  'description' => t('Shows delete when answer task removed.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Node'),
  'defaults' => [],
];

/**
 * Render callback.
 */
function ed_answer_actions_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }

  $node = $context->data;

  if ($node->type !== 'ed_answer') {
    return FALSE;
  }

  $content = [];

  // Add delete link if task has been removed and user can delete
  if (node_access('delete', $node) && empty($node->field_ref_to_task[LANGUAGE_NONE])) {
    $content['ed-answer-actions-container'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('ed-node-actions-container'),
      ),
      '#weight' => 10,
    );
    $content['ed-answer-actions-container']['delete'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Delete'), 'node/' . $node->nid . '/delete', array(
        'attributes' => array(
          'class' => 'ed-node-delete-button',
        ),
      )),
    );
  }

  $module = 'ed_answer';
  $block = new stdClass();
  $block->module = $module;
  $block->title = FALSE;

  $block->content = drupal_render($content);
  return $block;
}

/**
 * Edit form.
 */
function ed_answer_actions_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Edit form submit callback.
 */
function ed_answer_actions_content_type_edit_form_submit($form, &$form_state) {
}
