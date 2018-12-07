(function ($){
  Drupal.behaviors.ed_answer = {
    attach: function(context, settings){

      $( "#highlight-comment" )
        .closest( ".comment" )
        .css( "background-color", "rgba(254, 63, 76, .3)" )
        .css( "padding", "10px" )
        .css( "margin", "10px" )
    }
  }
})(jQuery);