(function ($) {
  Drupal.behaviors.ed_task_feedback = {
    attach: function (context, settings) {


      var satisf = 0;

      try {
        satisf = Drupal.settings.ed_task.satisf
      } catch (e) {

      }


      var difficulty = 0;

      try {
        difficulty = Drupal.settings.ed_task.difficulty
      } catch (e) {

      }

      var emotions = [];
      try {
        emotions = JSON.parse(Drupal.settings.ed_task.emotions)
      } catch (e) {

      }


      //Chart animation satisfaction rate
      $('svg#animated-chart-satisfaction text').text(satisf + '%');

      var count_satisfaction = $(('#count-satisfaction'));
      $({Counter: 0}).animate({Counter: count_satisfaction.text()}, {
        duration: 5000,
        easing: 'linear',
        step: function () {
          count_satisfaction.text(Math.ceil(this.Counter) + "%");
        }
      });

      var s_satisfaction = Snap('#animated-chart-satisfaction');
      var progress_satisfaction = s_satisfaction.select('#progress-satisfaction');

      progress_satisfaction.attr({strokeDasharray: '0, 251.2'});
      Snap.animate(0, 251.2 * satisf / 100, function (value) {
        progress_satisfaction.attr({'stroke-dasharray': value + ',251.2'});
      }, 5000);


      //Chart animation difficulty rate
      $('svg#animated-chart-difficulty text').text(difficulty + '%');

      var count_difficulty = $(('#count-difficulty'));
      $({Counter: 0}).animate({Counter: count_difficulty.text()}, {
        duration: 5000,
        easing: 'linear',
        step: function () {
          count_difficulty.text(Math.ceil(this.Counter) + "%");
        }
      });

      var s_difficulty = Snap('#animated-chart-difficulty');
      var progress_difficulty = s_difficulty.select('#progress-difficulty');

      progress_difficulty.attr({strokeDasharray: '0, 251.2'});
      Snap.animate(0, 251.2 * difficulty / 100, function (value) {
        progress_difficulty.attr({'stroke-dasharray': value + ',251.2'});
      }, 5000);


      //Emotions chart
      var myDoughnutChart = new Chart($('#animated-chart-emotions'), {
        type: 'doughnut',
        data: {
          datasets: [{
            data: [emotions.curiosity, emotions.confusion, emotions.anxiety, emotions.boredom, emotions.surprise, emotions.frustration, emotions.enjoyment],
            backgroundColor: ["#27f59d", "#3399FF", "#FFC575", "#99CC00", "#FF3300", "#944DDB", "#fff45c"],
            borderWidth: 0, //this will hide border
          }],
          labels: [Drupal.t('Uudishimu'), Drupal.t('Segadus'), Drupal.t('Ärevus'), Drupal.t('Igavus'), Drupal.t('Üllatus'), Drupal.t('Frustratsioon'), Drupal.t('Rõõm')]
        },
        options: {
          responsive: true,
        }
      });

    }
  };
})(jQuery);

