<?php
/**
 * @file twitter_pull.api.php
 * API for Twitter Pull module
 */

/**
 * Alter tweets alter pulling.
 *
 * @param $twitkey
 *   The twitter search key.
 * @param $num_items
 *   The number of tweets to display.
 * @param $tweets
 *   Array of tweet objects.
 */
function hook_twitter_pull_tweets_alter($twitkey, $num_tweets, &$tweets) {
  foreach (array_keys($tweets) as $k) {
    $tweet = &$tweets[$k];
    if (strpos($tweet->userphoto, 'http://a0.twimg.com/') === 0) {
      $tweet->userphoto = str_replace('http://a0.twimg.com/', 'https://twimg0-a.akamaihd.net/', $tweet->userphoto);
    }
  }
}
