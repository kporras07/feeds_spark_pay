<?php

/**
 * @file
 * AmeriCommerce Products FeedsParser.
 */

/**
 * {@inheritdoc}
 */
class FeedsSparkPayProductsParser extends FeedsSparkPayBaseParser {
  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $json = $fetcher_result->getRaw();
    $result = new FeedsParserResult($json['products']);
    $result->title = t('Products');
    $result->link = $fetcher_result->getBaseUrl() . '/api/v1/' . $fetcher_result->getResource() . '.json';
    return $result;
  }

  /**
   * Implements FeedsParser::getMappingSources().
   */
  public function getMappingSources() {
    return FALSE;
  }

}
