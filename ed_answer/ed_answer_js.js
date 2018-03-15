(function ($){
  Drupal.behaviors.ed_answer = {
    attach: function(context, settings){
      $('.category-container', context).find('a').wrap('<li />');
      $('.competence-container', context).find('a').wrap('<li />');


      $("#edit-ed-field-difficulty-feedb-und").each(function() {
        var radios = $(this).find(":radio");
        $("<div id='slider'></div>").slider({
          min: parseInt(radios.first().val(), 10),
          max: parseInt(radios.last().val(), 10),
          value: Drupal.settings.ed_answer.initial_difficulty_feedb,
          slide: function(event, ui) {
            radios.filter("[value=" + ui.value + "]").click();
          }
        }).each(function() {

            //
            // Add labels to slider whose values
            // are specified by min, max and whose
            // step is set to 1
            //

            // Get the options for this slider
            var opt = $(this).data().uiSlider.options;

            // Get the number of possible values
            var vals = opt.max - opt.min;


            // Space out values
            for (var i = 0; i <= vals; i++) {

              var el = $('<label>'+(i+1)+'</label>').css('left',(i/vals*100)+'%');

              $(this).append(el);

            }

          })
          .appendTo(this);


        $(this).find(".radio").hide();
      });



      $("#edit-ed-field-time-eff-feedb-und").each(function() {
        var radios = $(this).find(":radio");
        $("<div id='slider'></div>").slider({
          min: parseInt(radios.first().val(), 10),
          max: parseInt(radios.last().val(), 10),
          value: Drupal.settings.ed_answer.initial_time_eff_feedb,
          slide: function(event, ui) {
            radios.filter("[value=" + ui.value + "]").click();
          }
        }).each(function() {

          //
          // Add labels to slider whose values
          // are specified by min, max and whose
          // step is set to 1
          //

          // Get the options for this slider
          var opt = $(this).data().uiSlider.options;

          // Get the number of possible values
          var vals = opt.max - opt.min;


          // Space out values
          for (var i = 0; i <= vals; i++) {

            var el = $('<label>'+(i+1)+'</label>').css('left',(i/vals*100)+'%');

            $(this).append(el);

          }

        })
          .appendTo(this);


        $(this).find(".radio").hide();
      });



      var selected_satisf = Drupal.settings.ed_answer.initial_satisf_feedb;

      $("#edit-ed-field-satisf-feedb-und:radio[value="+selected_satisf+"]").hover(function() {
        $(this).css("filter","grayscale(0)")
      });



    }
  }
})(jQuery);