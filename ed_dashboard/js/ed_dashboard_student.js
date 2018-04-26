(function ($) {
  Drupal.behaviors.ed_dashboard_student = {
    attach: function(context, settings) {



      $('#student-dash-table').on('load-success.bs.table', function (e, data) {


        $tasks_answered = Math.round(30);

        $tasks_accepted = Math.round(80);

        //
        // $('svg.circular-chart.orange text.percentage').text($tasks_answered+'%');
        //
        // $('svg.circular-chart.orange path.circle').attr("stroke-dasharray", $tasks_answered+", 100");
        //

        // $('svg.circular-chart.green text.percentage').text($tasks_accepted+'%');
        //
        // $('svg.circular-chart.green path.circle').attr("stroke-dasharray", $tasks_accepted+", 100");
        //
        //


        //Chart animation tasks done
        $('svg#animated-chart-done text').text($tasks_answered+'%');

        var count_done = $(('#count-done'));
        $({ Counter: 0 }).animate({ Counter: count_done.text() }, {
          duration: 5000,
          easing: 'linear',
          step: function () {
            count_done.text(Math.ceil(this.Counter)+ "%");
          }
        });

        var s_done = Snap('#animated-chart-done');
        var progress_done = s_done.select('#progress-done');

        progress_done.attr({strokeDasharray: '0, 251.2'});
        Snap.animate(0,251.2*$tasks_answered/100, function( value ) {
          progress_done.attr({ 'stroke-dasharray':value+',251.2'});
        }, 5000);



        //Chart animation success rate
        $('svg#animated-chart-success text').text($tasks_accepted+'%');

        var count_success = $(('#count-success'));
        $({ Counter: 0 }).animate({ Counter: count_success.text() }, {
          duration: 5000,
          easing: 'linear',
          step: function () {
            count_success.text(Math.ceil(this.Counter)+ "%");
          }
        });

        var s_success = Snap('#animated-chart-success');
        var progress_success = s_success.select('#progress-success');

        progress_success.attr({strokeDasharray: '0, 251.2'});
        Snap.animate(0,251.2*$tasks_accepted/100, function( value ) {
          progress_success.attr({ 'stroke-dasharray':value+',251.2'});
        }, 5000);



        //Chart animation satisfaction rate
        $('svg#animated-chart-satisfaction text').text($tasks_accepted+'%');

        var count_satisfaction = $(('#count-satisfaction'));
        $({ Counter: 0 }).animate({ Counter: count_satisfaction.text() }, {
          duration: 5000,
          easing: 'linear',
          step: function () {
            count_satisfaction.text(Math.ceil(this.Counter)+ "%");
          }
        });

        var s_satisfaction = Snap('#animated-chart-satisfaction');
        var progress_satisfaction = s_satisfaction.select('#progress-satisfaction');

        progress_satisfaction.attr({strokeDasharray: '0, 251.2'});
        Snap.animate(0,251.2*$tasks_accepted/100, function( value ) {
          progress_satisfaction.attr({ 'stroke-dasharray':value+',251.2'});
        }, 5000);


        //Task rating
        $('[data-toggle="popover"]').popover({
          "html": true,
          "content": function(){
            var div_id =  "tmp-id-" + $.now();
            return details_in_popup($(this).attr('data-poload'), div_id, $(this).attr('task'));
          }
        });

        function details_in_popup(link, div_id, task){
          $.ajax({
            url: link,
            type: "POST",
            data: {task_id: task},
            dataType: "json",
            success: function(response){
              $('#'+div_id).html("<div class=\"star-rating\">\n" +
                "    <div class=\"back-stars\">\n" +
                "        <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "        <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "        <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "        <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "        <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "        \n" +
                "        <div class=\"front-stars\" style=\"width: "+response.rating+"%\">\n" +
                "            <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "            <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "            <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "            <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "            <i class=\"fa fa-star\" aria-hidden=\"true\"></i>\n" +
                "        </div>\n" +
                "    </div>\n" +
                "</div>    ");
            }
          });
          return '<div id="'+ div_id +'">Loading...</div>';
        }

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

