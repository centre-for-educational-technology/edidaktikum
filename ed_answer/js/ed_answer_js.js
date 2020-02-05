(function ($){
  Drupal.behaviors.ed_answer = {
    attach: function(context, settings){


      $('.category-container', context).find('a').wrap('<li />');
      $('.competence-container', context).find('a').wrap('<li />');


      $('.form-item-ed-field-difficulty-feedb-und input:checked').parent().parent().addClass('active');
      $('.form-item-ed-field-satisf-feedb-und input:checked').parent().parent().addClass('active');
      $('.form-item-ed-field-answer-emotions-und input:checked').parent().parent().addClass('active');

      $('.form-item-ed-field-answer-emotions-und input:checkbox').change(function(){
        $(this).parent().parent().toggleClass('active');
      })



    }
  }
})(jQuery);
