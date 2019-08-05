<?php

/**
 * Plugin definition.
 */
$plugin = [
  'title' => t('Create or update task answer'),
  'description' => t('Create or update task answer'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Node'),
  'defaults' => [],
];

/**
 * Render callback.
 */
function ed_task_create_update_answer_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }

  $node = $context->data;
  $accont = $GLOBALS['user']; // TODO Might make sense to clone

  if ($node->type !== 'ed_task') {
    return FALSE;
  }

  if (!ed_task_can_user_answer_task($node, $accont)) {
    return FALSE;
  }

  $content = [];

  $is_strict_submission = _is_strict_submission($node->nid);
  if($is_strict_submission){



    if(_is_task_answered($node->nid)){
      if(!_is_late_submission($node->nid)){
        $content = ed_task_make_edit_answer_button($node, $content);
      }
    }else{
      if(!_is_late_submission($node->nid)){
        $content = ed_task_make_answer_button($node, $content);
      }
    }

    $settings = array('deadline' => date('Y-m-d', strtotime('+1 day', strtotime(_get_due_date($node)))));

    drupal_add_js(array('ed_answer_countdown' => $settings), array('type' => 'setting'));

    drupal_add_js(drupal_get_path('module', 'ed_answer') . '/js/ed_answer_countdown_js.js');

  }else{

    if(_is_task_answered($node->nid)){
      $content = ed_task_make_edit_answer_button($node, $content);
    }else{
      $content = ed_task_make_answer_button($node, $content);
    }


  }



  if($is_strict_submission){
    $content['strict'] = [
      '#type' => 'item',
      '#markup' => t('You cannot answer/edit this task after the deadline'),
      '#prefix' => '<div class="text-danger">',
      '#suffix' => '</div>',
    ];

    $content['strict_countdown'] = [
      '#type' => 'item',
      '#prefix' => '<h3><div id="strict_countdown">',
      '#suffix' => '</div></h3>',
    ];
  }

  $module = 'ed_task';
  $block = new stdClass();
  $block->module = $module;
  $block->title = FALSE;

  $block->content = drupal_render($content);
  return $block;
}

function ed_task_make_answer_button($node, $content){
  $options = array(
    'attributes' => array('class' => 'btn btn-success price-btn'),
    'query' => array(
      'field_ref_to_task' => $node->nid,
    ),
  );

  $content['ed_task_answer'] = [
    '#type' => 'item',
    '#title' => '',
    '#markup' => l(t('Answer'), 'node/add/ed-answer', $options),
    '#prefix' => '<div class="answer">',
    '#suffix' => '</div>',
  ];

  return $content;
}


function ed_task_make_edit_answer_button($node, $content){
  $content['ed_task_answer'] = [
    '#type' => 'item',
    '#title' => '',
    '#markup' => l(t('Edit'), 'node/'.  _get_answer_from_task($node->nid).'/edit', ['attributes'=> ['class' => 'btn btn-success price-btn',]]),
    '#prefix' => '<div class="answer edit-answer">',
    '#suffix' => '</div>',
  ];

  return $content;
}

/**
 * Edit form.
 */
function ed_task_create_update_answer_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Edit form submit callback.
 */
function ed_task_create_update_answer_content_type_edit_form_submit($form, &$form_state) {
}
