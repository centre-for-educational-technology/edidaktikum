(function ($) {
    Drupal.behaviors.remove_from_collection = {
        attach: function(context, settings) {
            $('.single-remove-from-collection').on('click', function(e) {
                e.preventDefault();
                var confirmation = confirm(Drupal.t('Are you sure?'));

                if (true != confirmation) {
                    return false;
                }

                $.ajax({
                    url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/remove/' + $(this).data('nid') + '/from/' + Drupal.settings.ed_collection.collectionNid,
                    dataType: 'json',
                    type: 'POST',
                    cache: false,
                    success: function(response) {
                        console.log(response);
                    }
                });
            });
        }
    };
})(jQuery);

