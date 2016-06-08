<?php

/**
 * @file
 * FeedsSparkPayBaseFetcherResult class.
 */

/**
 * {@inheritdoc}
 */
abstract class FeedsSparkPayBaseFetcherResult extends FeedsFetcherResult {
  protected $baseUrl;
  protected $authToken;
  protected $resource;
  protected $count;
  protected $maximumPages;
  protected $query;

  /**
   * Constructor.
   */
  public function __construct($source_config = NULL) {
    if (is_array($source_config)) {
      if (isset($source_config['base_url'])) {
        $this->baseUrl = $source_config['base_url'];
      }
      if (isset($source_config['auth_token'])) {
        $this->authToken = $source_config['auth_token'];
      }
      if (isset($source_config['resource'])) {
        $this->resource = $source_config['resource'];
      }
      if (isset($source_config['count'])) {
        $this->count = $source_config['count'];
      }
      if (isset($source_config['maximum_pages'])) {
        $this->maximumPages = $source_config['maximum_pages'];
      }
    }
    parent::__construct('');
  }

  /**
   * Getter for baseUrl.
   */
  public function getBaseUrl() {
    return $this->baseUrl;
  }

  /**
   * Getter for resource.
   */
  public function getResource() {
    return $this->resource;
  }

  /**
   * Set query parameter.
   */
  public function setQueryParameter($parameter, $value) {
    return $this->query[$parameter] = $value;
  }

  /**
   * Request all pages for given resource.
   *
   * Starting from initialPage until maximum of pages.
   */
  protected function requestAllPages() {
    $actual_page = variable_get('feeds_spark_pay_initial_page_' . $this->resource, 1);
    $results = array($this->resource => array());
    for ($page_count = 0; $page_count < $this->maximumPages; $page_count++) {
      $result = $this->requestPage($actual_page);
      $results[$this->resource] = array_merge($results[$this->resource], $result[$this->resource]);
      if (empty($result['next_page'])) {
        // If no next page; exit.
        break;
      }
      $actual_page++;
    }
    variable_set('feeds_spark_pay_initial_page_' . $this->resource, $actual_page);
    // Request last page.
    $result = $this->requestPage($actual_page);
    $results[$this->resource] = array_merge($results[$this->resource], $result[$this->resource]);
    return $results;
  }

  /**
   * Request a single page indicated by page_number.
   */
  protected function requestPage($page_number) {
    $query = array(
      'count' => $this->count,
      'page' => $page_number,
    );
    $query += $this->query;
    $url = $this->baseUrl . '/api/v1/' . $this->resource . '.json';

    $result = feeds_spark_pay_make_curl_request($url, $query, $this->authToken);
    $json = json_decode($result, TRUE);

    return $json;
  }

}
