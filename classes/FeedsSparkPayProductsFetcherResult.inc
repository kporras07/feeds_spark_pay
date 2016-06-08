<?php

/**
 * @file
 * FeedsSparkPayProductsFetcherResult class.
 */

/**
 * {@inheritdoc}
 */
class FeedsSparkPayProductsFetcherResult extends FeedsSparkPayBaseFetcherResult {

  protected $productType;

  /**
   * Constructor.
   */
  public function __construct($source_config = NULL) {
    parent::__construct($source_config);
    if (is_array($source_config)) {
      if (isset($source_config['e_product_type'])) {
        $this->productType = $source_config['e_product_type'];
      }
    }
  }

  /**
   * Overrides FeedsFetcherResult::getRaw().
   */
  public function getRaw() {
    $this->setQueryParameter('expand', 'pictures,attributes');
    $this->setQueryParameter('e_product_type', $this->productType);
    $products = $this->requestAllPages();
    return $products;
  }

}
