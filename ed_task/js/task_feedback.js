(function ($) {
  Drupal.behaviors.ed_task_feedback = {
    attach: function (context, settings) {


      Object.keys(Drupal.settings.ed_task).forEach(function (key, index) {


        var group = Drupal.settings.ed_task[key].group;

        var satisf = 0;

        try {
          satisf = Drupal.settings.ed_task[key].satisf
        } catch (e) {

        }


        var difficulty = 0;

        try {
          difficulty = Drupal.settings.ed_task[key].difficulty
        } catch (e) {

        }

        var emotions = 0;
        try {
          emotions = Drupal.settings.ed_task[key].emotions
        } catch (e) {

        }


        //Satisf chart
        var mySatisfChart = new Chart($('#animated-chart-satisf-' + group), {
          type: 'bar',
          data: {
            datasets: [{
              data: [satisf.first, satisf.second, satisf.third, satisf.fourth, satisf.fifth],
              backgroundColor: "#1abc9c",
              borderWidth: 0, //this will hide border
            }],
            labels: [1, 2, 3, 4, 5]
          },
          options: {
            legend: {
              display: false
            },
            responsive: true,
            scales: {
              yAxes: [{
                display: true,
                ticks: {
                  suggestedMin: 0,
                  stepSize: 5
                }
              }]
            }
          }
        });


        //Diff chart
        var myDiffChart = new Chart($('#animated-chart-diff-' + group), {
          type: 'bar',
          data: {
            datasets: [{
              data: [difficulty.first, difficulty.second, difficulty.third, difficulty.fourth, difficulty.fifth],
              backgroundColor: "#1abc9c",
              borderWidth: 0, //this will hide border
            }],
            labels: [1, 2, 3, 4, 5]
          },
          options: {
            legend: {
              display: false
            },
            responsive: true,
            scales: {
              yAxes: [{
                display: true,
                ticks: {
                  suggestedMin: 0,
                  stepSize: 5
                }
              }]
            }
          }
        });

        //Emotions chart
        var myDoughnutChart = new Chart($('#animated-chart-emotions-' + group), {
          type: 'horizontalBar',
          data: {
            datasets: [{
              data: [(emotions) && emotions.curiosity !== undefined ? emotions.curiosity : 0,
                (emotions) && emotions.confusion !== undefined ? emotions.confusion : 0,
                (emotions) && emotions.anxiety !== undefined ? emotions.anxiety : 0,
                (emotions) && emotions.boredom !== undefined ? emotions.boredom : 0,
                (emotions) && emotions.surprise !== undefined ? emotions.surprise : 0,
                (emotions) && emotions.frustration !== undefined ? emotions.frustration : 0,
                (emotions) && emotions.enjoyment !== undefined ? emotions.enjoyment : 0
              ],
              backgroundColor: "#1abc9c",
              borderWidth: 0, //this will hide border
            }],
            labels: [Drupal.t('Uudishimu'), Drupal.t('Segadus'), Drupal.t('Ärevus'), Drupal.t('Igavus'), Drupal.t('Üllatus'), Drupal.t('Frustratsioon'), Drupal.t('Rõõm')]
          },
          options: {
            legend: {
              display: false
            },
            responsive: true,
            scales: {
              xAxes: [{
                display: true,
                ticks: {
                  suggestedMin: 0,
                  stepSize: 5
                }
              }]
            }
          }
        });


      });


    }
  };
})(jQuery);

function sum(obj) {
  var sum = 0;
  for (var el in obj) {
    if (obj.hasOwnProperty(el)) {
      sum += parseFloat(obj[el]);
    }
  }
  return sum;
}
