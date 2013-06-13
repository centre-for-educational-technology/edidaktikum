(function ($){
  Drupal.behaviors.ed_answer = {
    attach: function(context, settings){
      $('.category-container', context).find('a').wrap('<li />');
      $('.competence-container', context).find('a').wrap('<li />');
    }
  }
})(jQuery)
