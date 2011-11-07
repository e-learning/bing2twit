<?php

session_start();
require_once('../lib/twitteroauth/twitteroauth.php');
require_once('config.php');

/* Get user access tokens out of the session. */
$access_token = $_SESSION['access_token'];

/* Create a TwitterOauth object with consumer/user tokens. */
$connection = new TwitterOAuth(CONSUMER_KEY, CONSUMER_SECRET, $access_token['oauth_token'], $access_token['oauth_token_secret']);

$content = $connection->get('account/verify_credentials');

$lat = $_POST['lat'];
$lng = $_POST['lng'];
$place = $_POST['text'];

$connection->post('statuses/update', array('status' => 'POI: latitide: '.$lat.', longitude: '.$lng.', place: '.$place));

include('maps.html');

