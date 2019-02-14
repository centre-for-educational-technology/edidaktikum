(function ($) {
  Drupal.behaviors.ed_cluster_tooltip = {
    attach: function(context, settings) {


      $('[data-toggle="tooltip"]').tooltip();

    }
  };
})(jQuery);