/*(function ($){

  Drupal.behaviors.ed_task = {
    attach: function(context, settings){
      $('#kategooria', context).find('label[for="edit-ed-field-category-und"]').on('click', function(){
        alert("test");
      })
    }
  }
})(jQuery);*/

(function ($){

  Drupal.behaviors.ed_task = {
    attach: function(context, settings){
      $('#category', context).find('label[for="edit-ed-field-category-und"]').on('click', function(){
        $('#edit-ed-field-category-und').slideToggle("slow");
      })
      $('#competence', context).find('label[for="edit-ed-field-competence-und"]').on('click', function(){
        $('#edit-ed-field-competence-und').slideToggle("slow");
      })
    }
  }
})(jQuery)
