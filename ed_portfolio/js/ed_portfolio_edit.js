(function ($) {
  Drupal.behaviors.ed_portfolio = {
    attach: function (context, settings) {

      var keys = [];

      if ($('.progress').length) {


        try {
          keys = Drupal.settings.ed_portfolio;
        } catch (e) {

        }

        for (var key in keys) {

          if (keys.hasOwnProperty(key)) {

            if ($('#progress-' + key).length) {

              var bar = new ProgressBar.Line('#progress-' + key, {
                strokeWidth: 4,
                easing: 'easeInOut',
                duration: 4000,
                color: '#ff9f00',
                trailWidth: 4,
                svgStyle: {width: '100%', height: '100%'},
                from: {color: '#ff9f00'},
                to: {color: '#1abc9c'},
              });
              bar.animate(keys[key]);  // Value from 0.0 to 1.0
            }


          }
        }


      }

    }
  };
})(jQuery);
