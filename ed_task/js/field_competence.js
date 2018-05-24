(function($) {
  Drupal.behaviors.edTaskFieldCompetence = {
    'attach': function(context) {
      var fieldSelector = '#edit-ed-field-competence';
      var fieldInputSelector = fieldSelector + ' input[type="checkbox"]';
      var fieldTermReferenceTreeLevelSelector = fieldSelector + ' ul.term-reference-tree-level';
      var fieldTermReferenceTreeLevelChildSelector = fieldTermReferenceTreeLevelSelector + ' > li';
      var groupInputSelector = 'select[name="og_group_ref[und][0][default][]"]';

      $(groupInputSelector, context).on('change', function() {
        var _groups = $(this);
        var _competences = $(fieldInputSelector);

        $.post( Drupal.settings.basePath + Drupal.settings.pathPrefix + 'clusters/get/groups_competences', { groups: _groups.val() }, function(data) {
          $(fieldTermReferenceTreeLevelChildSelector).removeClass('competence-tree-hidden');
          _competences.closest('li').addClass('competence-hidden');
          _competences.removeClass('competence-allowed');

          if ( data && data.competences ) {
            $.each(data.competences, function(key, single) {
              var competence = _competences.filter('[value="' + single + '"]');
              if ( competence ) {
                competence.closest('li').removeClass('competence-hidden');
                competence.addClass('competence-allowed');
              }
            });
            // Hide any trees that have none of allowed inputs
            $(fieldTermReferenceTreeLevelSelector).each(function() {
              if ( $(this).find('input[type="checkbox"].competence-allowed').length < 1 ) {
                $(this).parent('li').addClass('competence-tree-hidden');
              }
            });
          }
          // Uncheck any competences that are no longer allowed
          _competences.filter(':checked:not(.competence-allowed)').prop('checked', false);
        });
      });

      // Set timeout to trigger the initial "change" event on group input
      var timeoutId = setTimeout(function() {
        timeoutId = null;
        $(groupInputSelector).trigger('change');
      }, 1000);
      $(groupInputSelector).one('change', function() {
        if ( timeoutId ) {
          clearTimeout(timeoutId);
        }
      });
    }
  };
})(jQuery);
