(function ($) {
    Drupal.behaviors.remove_from_collections = {
        attach: function(context, settings) {
                    var modalElement = $('#remove-from-collection-modal'),
                        nid = modalElement.next('a').data('nid');



                    modalElement.find('button.btn-primary').on('click', function() {
                        var collectionsElement = modalElement.find('select[name="collections"]'),
                            selectedCollections = collectionsElement.val();

                        if ( !selectedCollections ) {
                            return false;
                        }

                        $(this).prop('disabled', true);
                        collectionsElement.prop('disabled', true);

                        $.ajax({
                            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/learning_resource/remove/' + nid,
                            dataType: 'json',
                            type: 'POST',
                            data: { selected_collections : selectedCollections },
                            cache: false,
                            success: function(response) {
                                if (true == response.success) {
                                    modalElement.modal('hide');
                                }
                            }
                        });
                    });

                    modalElement.on('show.bs.modal', function() {
                        var that = this;

                        $.ajax({
                            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/learning_resource/load/' + nid,
                            dataType: 'json',
                            type: 'POST',
                            cache: false,
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
                    }).on('hidden.bs.modal', function() {
                        $(this).find('button.btn-primary').prop('disabled', true);
                        $(this).find('select[name="collections"]').remove();
                    });
                }
    };
})(jQuery);
