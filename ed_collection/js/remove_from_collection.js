(function ($) {
    Drupal.behaviors.remove_from_collection = {
        attach: function(context, settings) {
            if (Drupal.settings.ed_collection.canUpdate !== true ) {
                return;
            }

            $('.single-remove-from-collection').show().on('click', function(e) {
                e.preventDefault();
                var that = this,
                    confirmation = confirm(Drupal.t('Are you sure?'));

                if (true != confirmation) {
                    return false;
                }

                $.ajax({
                    url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/remove/' + $(this).data('nid') + '/from/' + Drupal.settings.ed_collection.collectionNid,
                    dataType: 'json',
                    type: 'POST',
                    cache: false,
                    success: function(response) {
                        if (true == response.success) {
                            $(that).parents('.node').remove();
                        }
                    }
                });
            });
        }
    };
})(jQuery);

