(function ($) {
    Drupal.behaviors.ed_dashboard_discover = {
        attach: function(context, settings) {
                    $('.ed-saved-searches', context).find('.ed-remove-search').on('click', function(e) {
                        e.preventDefault();
                        var confirmation = confirm(Drupal.t('Are you sure?'));

                        if (true == confirmation) {
                            $.ajax({
                                url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'dashboard/search/delete/' + $(this).data('id'),
                                dataType: 'json',
                                type: 'POST',
                                success: function(response) {
                                    console.log(response);
                                    $(e.target).parent().remove();
                                }
                            });
                        }
                    });
                }
    };
})(jQuery);

