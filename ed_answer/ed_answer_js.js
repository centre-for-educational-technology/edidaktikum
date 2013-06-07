(function ($){
  Drupal.behaviors.ed_answer = {
    attach: function(context, settings){
      //alert("tere");
      $('.category-container', context).find('a').wrap('<li />');
    }
  }
})(jQuery)
