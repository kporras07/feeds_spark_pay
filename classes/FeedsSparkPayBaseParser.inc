<?php

/**
 * @file
 * AmeriCommerce Base FeedsParser.
 */

/**
 * {@inheritdoc}
 */
abstract class FeedsSparkPayBaseParser extends FeedsParser {
  /**
   * Override parent::getMappingSources().
   */
  public function getMappingSources() {
    return FALSE;
  }

}
