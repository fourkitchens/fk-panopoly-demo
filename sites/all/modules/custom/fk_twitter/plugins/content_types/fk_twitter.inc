<?php

$plugin = array(
  'title' => t('4K Twitter Block.'),
  'single' => TRUE,
  'category' => array(t('4K'), -9),
  'edit form' => 'fk_twitter_pane_content_type_edit_form',
  'render callback' => 'fk_twitter_pane_content_type_render'
);

function fk_twitter_pane_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['fk_twitter_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter account'),
    '#default_value' => $conf['fk_twitter_account'],
    '#description' => t('The twitter account to pull tweets for.'),
  );
  $form['fk_twitter_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Tweet limit'),
    '#default_value' => isset($conf['fk_twitter_limit']) ? $conf['fk_twitter_limit'] : 5,
    '#description' => t('The number of tweets to display.'),
    '#element_validate' => array('element_validate_integer_positive'),
  );

  return $form;
}

function fk_twitter_pane_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf']['fk_twitter_account'] = $form_state['values']['fk_twitter_account'];
  $form_state['conf']['fk_twitter_limit'] = $form_state['values']['fk_twitter_limit'];
}

function fk_twitter_pane_content_type_render($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = '';

  $key = (strpos($conf['fk_twitter_account'], '@') === 0 ? '' : '@') .
    $conf['fk_twitter_account'];

  $block->content = twitter_pull_render($key, NULL, $conf['fk_twitter_limit']);

  return $block;
}

