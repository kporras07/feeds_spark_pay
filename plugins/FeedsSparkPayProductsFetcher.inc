<?php

/**
 * @file
 * Spark Pay Products Feeds Fetcher.
 */

/**
 * {@inheritdoc}
 */
class FeedsSparkPayProductsFetcher extends FeedsSparkPayBaseFetcher {

  /**
   * Implements FeedsSparkPayBaseFetcher::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $form['e_product_type'] = array(
      '#type' => 'textfield',
      '#title' => t('Product Type'),
      '#description' => t('Product type to import'),
      '#default_value' => isset($this->config['e_product_type']) ? $this->config['e_product_type'] : '',
      '#maxlength' => 255,
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * Define default configuration.
   */
  public function configDefaults() {
    $defaults = parent::configDefaults();
    $defaults['e_product_type'] = '';
    return $defaults;
  }

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $this->getConfig();
    $source_config['resource'] = 'products';
    $fetcher_result = new FeedsSparkPayProductsFetcherResult($source_config);
    return $fetcher_result;
  }

}
