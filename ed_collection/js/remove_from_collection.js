(function ($) {
  Drupal.behaviors.removeFromCollection = {
    attach: function(context, settings) {
      function add_spinner(element) {
        $(element).append('<i class="fa fa-spinner fa-spin" aria-hidden="true"></i>');
      }

      function remove_spinner(element) {
        $(element).find('i.fa.fa-spinner.fa-spin').remove();
      }

      if ( Drupal.settings.ed_collection.canUpdate) {
        $('.single-remove-from-collection').show().on('click', function(e) {
          e.preventDefault();

          if (!confirm(Drupal.t('Are you sure?'))) {
            return;
          }

          var that = this,
            nid = $(that).data('nid');

          $(that).prop('disabled', true);
          add_spinner(that);

          $.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/remove/' + nid + '/from/' + Drupal.settings.ed_collection.collectionNid,
            dataType: 'json',
            type: 'POST',
            data: {},
            cache: false,
            success: function(response) {
              $(that).prop('disabled', false);
              remove_spinner(that);

              if (true == response.success) {
                $('#node-' + nid).hide(function() {
                  $(this).remove();
                });
              }
            }
          });
        });
      }
    }
  };
})(jQuery);
