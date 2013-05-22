(function ($){

  Drupal.behaviors.ed_learning_resource = {
    attach: function (context, settings){
      $('.pagination', context).find('a').on('click', function(event) {

        event.preventDefault();
        var form = jQuery('form#ed-learning-resource-listing');
        var action = jQuery(this).attr('href');
        if (action != '#') {
          form.attr('action', action);
        }
        form.submit();
      });
    }

  }
})(jQuery);
