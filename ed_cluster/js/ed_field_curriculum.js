(function($) {
  Drupal.behaviors.ed_field_curriculum = {
    'attach': function(context) {
      $('select[name="ed_field_university[und][]"]', context).on('change', function() {
        var selected = $(this).val();

        $('select[name="ed_field_curriculum[und][]"]').find('option').each(function() {
          var ckey = $(this).val();
          if (ckey === '_none') return;

          var ukey = Drupal.settings.edidaktikum.curriculum_university_data[ckey];
          if (ukey !== undefined && $.inArray(ukey.toString(), selected) != -1) {
            $(this).prop('disabled', false).show();
          } else {
            $(this).prop('disabled', true).hide();
          }
        });
      });
      $('select[name="ed_field_university[und][]"]').trigger('change');
    }
  };
})(jQuery);
