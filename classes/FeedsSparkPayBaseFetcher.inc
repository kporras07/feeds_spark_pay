<?php

/**
 * @file
 * AmeriCommerce Feeds Fetcher.
 */

/**
 * {@inheritdoc}
 */
abstract class FeedsSparkPayBaseFetcher extends FeedsFetcher {
  /**
   * Overrides parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = array();

    $form['base_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Base URL'),
      '#description' => t('Base URL for API requests'),
      '#default_value' => isset($this->config['base_url']) ? $this->config['base_url'] : '',
      '#maxlength' => 255,
      '#required' => TRUE,
    );

    $form['auth_token'] = array(
      '#type' => 'textfield',
      '#title' => t('Authentication Token'),
      '#description' => t('Used to authenticate the API requests'),
      '#default_value' => isset($this->config['auth_token']) ? $this->config['auth_token'] : '',
      '#maxlength' => 36,
      '#required' => TRUE,
    );

    $form['count'] = array(
      '#type' => 'textfield',
      '#title' => t('Number of items to get per request during one import'),
      '#description' => t('How many items do you need to import per request? Recommended <= 100'),
      '#default_value' => isset($this->config['count']) ? $this->config['count'] : '',
      '#maxlength' => 3,
      '#required' => TRUE,
    );

    $form['maximum_pages'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum requests to do per import'),
      '#description' => t('Set this to a right amount to avoid php timeouts'),
      '#default_value' => isset($this->config['maximum_pages']) ? $this->config['maximum_pages'] : '',
      '#maxlength' => 2,
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * Overrides parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    // Cleanup.
    array_walk($values, 'trim');
  }

  /**
   * Define default configuration.
   */
  public function configDefaults() {
    return array(
      'base_url' => '',
      'auth_token' => '',
      'count' => '',
      'maximum_pages' => '',
    );
  }

}
