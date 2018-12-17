(function ($){
  Drupal.behaviors.ed_answer = {
    attach: function(context, settings){

      $( "#highlight-comment" )
        .closest( ".comment" )
        .css( "background-color", "rgba(51, 122, 183, .3)" )
        .css( "padding", "10px" )
        .css( "margin", "10px" )
    }
  }
})(jQuery);