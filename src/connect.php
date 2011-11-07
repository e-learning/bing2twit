<?php

/**
 * @file
 * Send user to get a request token.
 */

require_once('config.php');

/* Build an image link to start the redirect process. */
$content = '<a href="./redirect.php"><img src="./images/lighter.png" alt="Sign in with Twitter"/></a>';
 
/* Include HTML to display on the page. */
include('html.inc');
