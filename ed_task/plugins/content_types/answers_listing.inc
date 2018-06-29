<?php

/**
 * Plugin definition.
 */
$plugin = [
  'title' => t('Task answers listing'),
  'description' => t('Task answers listing'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Node'),
  'defaults' => [],
];

/**
 * Render callback.
 */
function ed_task_answers_listing_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }

  $node = $context->data;
  $accont = $GLOBALS['user']; // TODO Might make sense to clone
  $content = [];

  // Show owner answer info
  if ($node->uid === $accont->uid && $node->type === 'ed_task') {
    $content['ed_task_answers_listing']['answers-heading'] = [
      '#type' => 'markup',
      '#markup' => t('Answers'),
      '#prefix' => '<h3>',
      '#suffix' => '</h3>',
    ];

    $content['ed_task_answers_listing']['answers-by-groups'] = [
      '#type' => 'markup',
      '#markup' => t('Answers by groups'),
      '#prefix' => '<h4>',
      '#suffix' => '</h4>',
    ];
    $listing_items = [];
    if (isset($node->og_group_ref[LANGUAGE_NONE]) && is_array($node->og_group_ref[LANGUAGE_NONE])) {
      $group_ids = $node->og_group_ref[LANGUAGE_NONE];
    }
    if (!empty($group_ids)) {
      // TODO Might make sense to use metadata wrapper
      $groups = node_load_multiple(array_map(function($element) { return $element['target_id']; }, $group_ids));
    }
    if (!empty($groups)) {
      foreach ($groups as $group) {
        $listing_items[] = l($group->title, 'node/' . $group->nid . '/task-manager');
      }
    }
    $content['ed_task_answers_listing']['answers-by-groups-listing'] = [
      '#theme' => 'item_list',
      '#items' => $listing_items,
    ];

    if (isset($node->{ED_FIELD_TO_GROUP_MEMBER}[LANGUAGE_NONE]) && is_array($node->{ED_FIELD_TO_GROUP_MEMBER}[LANGUAGE_NONE])) {
      $user_ids = $node->{ED_FIELD_TO_GROUP_MEMBER}[LANGUAGE_NONE];
    }
    if (!empty($user_ids)) {
      // TODO Might make sense to use metadata wrapper
      $users = user_load_multiple(array_map(function($element) { return $element['target_id']; }, $user_ids));
    }
    $rows = [];

    if (!empty($users)) {
      $i_number = 1;
      foreach ($users as $user) {
        $answer = _get_user_answer_from_task($node->nid, $user->uid);
        $rows[] = [
          'data' => [
            'number' => $i_number,
            'name' =>  edidaktikum_get_full_name_for_user_account($user),
            'answer' => [
              'data' => ($answer) ? l('&nbsp;', 'node/' . $answer->nid, ['html' => TRUE,]) : '',
              'class' => ($answer) ? 'answered' : 'unanswered',
            ],
            'submitted' => ($answer) ? format_date($answer->created, 'medium') : '',
          ],
        ];
        $i_number++;
      }
    }

    if (!empty($rows)) {
      $content['ed_task_answers_listing']['answers-by-users'] = [
        '#type' => 'markup',
        '#markup' => t('Answers by users'),
        '#prefix' => '<h4>',
        '#suffix' => '</h4>',
      ];
      // TODO Check if this is needed
      drupal_add_css(drupal_get_path('module', 'ed_cluster').'/task_manager.css');
      $content['ed_task_answers_listing']['answers-by-users-table'] = [
        '#theme' => 'table',
        '#rows'=> $rows,
        '#header' => ['#', t('Name'), t('Answer'), t('Submitted'),],
      ];
    }
  }

  $module = 'ed_task';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Task answers listing');

  $block->content = drupal_render($content);
  return $block;
}

/**
 * Edit form.
 */
function ed_task_answers_listing_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Edit form submit callback.
 */
function ed_task_answers_listing_content_type_edit_form_submit($form, &$form_state) {
}
