(function ($){
  Drupal.behaviors.ed_answer = {
    attach: function(context, settings){
      $('.category-container', context).find('a').wrap('<li />');
      $('.competence-container', context).find('a').wrap('<li />');

      var initial_difficulty_feedb = 1;
      var initial_time_eff_feedb = 1;
      var initial_satisf_feedb = 4;

      try{
        initial_difficulty_feedb = Drupal.settings.ed_answer.initial_difficulty_feedb
      }catch(e){

      }

      try{
        initial_time_eff_feedb = Drupal.settings.ed_answer.initial_time_eff_feedb
      }catch(e){

      }

      try{
        initial_satisf_feedb = Drupal.settings.ed_answer.initial_satisf_feedb
      }catch(e){

      }



      $("#edit-ed-field-difficulty-feedb-und").each(function() {
        var radios = $(this).find(":radio");
        $("<div id='slider'></div>").slider({
          min: parseInt(radios.first().val(), 10),
          max: parseInt(radios.last().val(), 10),
          value: initial_difficulty_feedb,
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
            //XXX FOR SOME INSTANCES NEED TO USE .uiSlider INSTEAD OF .slider
            var opt = $(this).data().slider.options;

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
          value: initial_time_eff_feedb,
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
          //XXX FOR SOME INSTANCES NEED TO USE .uiSlider INSTEAD OF .slider
          var opt = $(this).data().slider.options;

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




      $("#edit-ed-field-satisf-feedb-und:radio[value="+initial_satisf_feedb+"]").hover(function() {
        $(this).css("filter","grayscale(0)")
      });



    }
  }
})(jQuery);