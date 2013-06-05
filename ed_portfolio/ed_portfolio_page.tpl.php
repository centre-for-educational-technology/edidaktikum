<?php

/**
 * @file
 * Portfolio view.
 */

?>

<!-- Navbar -->
<div id="navbar" class="navbar navbar-medium navbar-inverse navbar-static-top">
	<div class="navbar-inner">
		<div class="container">
			<a class="brand" href="<?php print $front_page ?>">
                <?php print $site_name ?>
            </a>
		</div>
	</div>
</div>

<?php print drupal_render($node_view); ?>

