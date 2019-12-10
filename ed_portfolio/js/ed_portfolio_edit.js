(function ($) {
  Drupal.behaviors.ed_portfolio = {
    attach: function(context, settings) {
      function add_spinner(modal) {
        $(modal).find('.modal-body').append('<i class="fa fa-spinner fa-spin" aria-hidden="true"></i>');
      }

      function remove_spinner(modal) {
        $(modal).find('.modal-body').find('i.fa.fa-spinner.fa-spin').remove();
      }

      // Add modal part
      var addModalElement = $('#add-to-collection-modal'),
      addNid = addModalElement.next('a').data('nid');

      addModalElement.find('button.btn-primary').on('click', function() {
        var collectionsElement = addModalElement.find('select[name="collections"]'),
        selectedCollections = collectionsElement.val();

        if ( !selectedCollections ) {
          return false;
        }

        $(this).prop('disabled', true);
        collectionsElement.prop('disabled', true);

        $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/user/add/' + addNid,
          dataType: 'json',
          type: 'POST',
          data: { selected_collections : selectedCollections },
          cache: false,
          success: function(response) {
            if (true == response.success) {
              addModalElement.modal('hide');
            }
          }
        });
      });

      addModalElement.on('show.bs.modal', function() {
        var that = this;

        add_spinner(that);

        $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/user/load/' + addNid,
          dataType: 'json',
          type: 'POST',
          cache: false,
          success: function(response) {
            remove_spinner(that);

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

      // Remove modal part
      var removeModalElement = $('#remove-from-collection-modal'),
      removeNid = removeModalElement.next('a').data('nid');

      removeModalElement.find('button.btn-primary').on('click', function() {
        var collectionsElement = removeModalElement.find('select[name="collections"]'),
        selectedCollections = collectionsElement.val();

        if ( !selectedCollections ) {
          return false;
        }

        $(this).prop('disabled', true);
        collectionsElement.prop('disabled', true);

        $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/learning_resource/remove/' + removeNid,
          dataType: 'json',
          type: 'POST',
          data: { selected_collections : selectedCollections },
          cache: false,
          success: function(response) {
            if (true == response.success) {
              removeModalElement.modal('hide');
            }
          }
        });
      });

      removeModalElement.on('show.bs.modal', function() {
        var that = this;

        add_spinner(that);

        $.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'collections/learning_resource/load/' + removeNid,
          dataType: 'json',
          type: 'POST',
          cache: false,
          success: function(response) {
            remove_spinner(that);

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
