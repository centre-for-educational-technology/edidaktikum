(function($) {
    Drupal.behaviors.ed_cluster = {
        'attach': function(context) {
            $('select[name="og_group_ref[und][0][default][]"]', context).on('change', function() {
                var _groups = $(this);
                var _users = $('select[name="ed_field_to_group_member[und][]"]');
                $.post( Drupal.settings.basePath + Drupal.settings.pathPrefix + 'clusters/get/groups_members', { groups: $(this).val() }, function(data) {
                    var currently_selected = _users.val();
                    _users.empty();
                    if (data) {
                        $.each(data, function(key, single) {
                            if ($.inArray(single.value, currently_selected) != -1) {
                                _users.append('<option value="'+single.value+'" selected="selected">'+single.name+'</option>');
                            } else {
                                _users.append('<option value="'+single.value+'">'+single.name+'</option>');
                            }
                        });
                    }
                });
            });
          $('select[name="og_group_ref[und][0][default][]"]').trigger('change');
        }
    }
})(jQuery);

