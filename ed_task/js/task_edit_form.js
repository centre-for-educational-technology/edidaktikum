(function($) {
  Drupal.behaviors.edTaskEditForm = {
    'attach': function(context) {
      var fieldToGroupMemberSelector = '#edit-ed-field-to-group-member-und';
      var fieldCurriculumSelector = '#edit-ed-task-field-study-group-und';

      $(fieldToGroupMemberSelector, context).on('change', function() {
        if($(this).val()[0] !== '_none'){
          $(fieldCurriculumSelector).prop('disabled', 'disabled');
        } else {
          $(fieldCurriculumSelector).prop('disabled', false);
        }
      });



      if($(fieldToGroupMemberSelector).val() != null && $(fieldToGroupMemberSelector).val() !== '_none'){
        $(fieldCurriculumSelector).prop('disabled', 'disabled');
      }
    }
  };
})(jQuery);
