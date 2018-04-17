(function ($) {
  Drupal.behaviors.ed_dashboard_student = {
    attach: function(context, settings) {

      console.log('hello');
      // $.ajax({
      //   url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'dashboard/student',
      //   dataType: 'json',
      //   type: 'POST',
      //   success: function(response) {
      //     if (true == response.success) {
      //
      //
      //       $('#table').bootstrapTable({
      //         data: response.data
      //       });
      //
      //
      //     }
      //   }
      // });

    }
  };
})(jQuery);

