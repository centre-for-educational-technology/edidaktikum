(function($) {
  Drupal.behaviors.ed_cluster = {
    'attach': function(context) {
      $(".group").matchHeight();


      //Alert when clicking on Private groups
      $('.no-access').on( "click", function(e) {
        e.preventDefault();
        swal({
          title: Drupal.t('Access denied'),
          text: Drupal.t('You should join the group first'),
          type: 'error',
          confirmButtonText: Drupal.t('Ok'),
          confirmButtonColor: '#1abc9c'
        })
      });
    }
  }
})(jQuery);

