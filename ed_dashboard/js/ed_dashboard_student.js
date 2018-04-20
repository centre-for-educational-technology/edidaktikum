(function ($) {
  Drupal.behaviors.ed_dashboard_student = {
    attach: function(context, settings) {

      $('#student-dash-table').on('load-success.bs.table', function (e, data) {
        console.log(data.stats.tasks_answered);

        $tasks_answered = Math.round(data.stats.tasks_answered);

        $('svg.circular-chart.orange text.percentage').text($tasks_answered+'%');

        $('svg.circular-chart.orange path.circle').attr("stroke-dasharray", $tasks_answered+", 100");



        var chart = $('.single-chart.work path');
        console.log(chart);

        // -> removing the class
        chart.classList.remove("circle");

        // -> triggering reflow /* The actual magic */
        // without this it wouldn't work. Try uncommenting the line and the transition won't be retriggered.
        // Oops! This won't work in strict mode. Thanks Felis Phasma!
        // element.offsetWidth = element.offsetWidth;
        // Do this instead:
        void chart.offsetWidth;

        // -> and re-adding the class
        chart.classList.add("circle");


      });


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

