(function ($) {
    Drupal.behaviors.add_to_collections = {
        attach: function(context, settings) {
                    $('#add-to-collection-modal').find('button.btn-primary').on('click', function() {
                        $(this).prop('disabled', true);
                    });

                    $('#add-to-collection-modal').on('shown', function() {
                        var that = this,
                            nid = $(this).next('a').data('nid');
                        $.ajax({
                            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/user/load/' + nid,
                            dataType: 'json',
                            type: 'POST',
                            success: function(response) {
                                if (true == response.success) {
                                    if ( response.data ) {
                                        $(that).find('button.btn-primary').prop('disabled', false);
                                        $(that).find('.modal-body').append('<select name="collections" multiple="multiple" style="width:100%;"></select>');
                                        var collectionsElement = $(that).find('select[name="collections"]');
                                        $.each(response.data, function(key, single) {
                                            collectionsElement.append('<option value="' + single.nid + '">' + single.title + '</option>');
                                        });
                                    }
                                }
                            }
                        });
                    }).on('hidden', function() {
                        $(this).find('button.btn-primary').prop('disabled', true);
                        $(this).find('select[name="collections"]').remove();
                    });
                }
    };
})(jQuery);

