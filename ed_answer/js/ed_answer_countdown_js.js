(function ($) {
  Drupal.behaviors.ed_answer = {
    attach: function (context, settings) {

      var deadline = 0;

      try {
        deadline = Drupal.settings.ed_answer_countdown.deadline;
      } catch (e) {

      }

      var countDownDate = new Date(deadline + ' 00:00:00').getTime();

      var userToUTC = new Date().getTimezoneOffset() * 60000;
      var tallinnToUTC = new Date(deadline + ' 00:00:00').getTimezoneOffset() * 60000;

      // Update the count down every 1 second
      var x = setInterval(function () {

        var now = new Date().getTime();

        var distance = (countDownDate + tallinnToUTC) - (now + userToUTC);

        var days = Math.floor(distance / (1000 * 60 * 60 * 24));
        var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
        var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
        var seconds = Math.floor((distance % (1000 * 60)) / 1000);

        document.getElementById("strict_countdown").innerHTML = days + Drupal.t("d ") + hours + Drupal.t("h ")
          + minutes + Drupal.t("m ") + seconds + Drupal.t("s ");

        if (distance < 0) {
          clearInterval(x);
          document.getElementById("strict_countdown").innerHTML = Drupal.t("EXPIRED");
        }
      }, 1000);


    }
  }

})(jQuery);
