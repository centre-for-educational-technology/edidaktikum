
(function ($){

  Drupal.behaviors.ed_task = {
    attach: function(context, settings){
      $('#edit-ed-field-category', context).find('label[for="edit-ed-field-category-und"]').once('my-helper', function(){$('#edit-ed-field-category', context).find('label[for="edit-ed-field-category-und"]').on('click', function(){
        $('#edit-ed-field-category-und').slideToggle("slow");
      })})
      $('#edit-ed-field-competence', context).find('label[for="edit-ed-field-competence-und"]').once('my-helper', function(){$('#edit-ed-field-competence', context).find('label[for="edit-ed-field-competence-und"]').on('click', function(){
        $('#edit-ed-field-competence-und').slideToggle("slow");
      })})
    }
  }

  // Take off overflow hidden used in front page parallax
  $(function() {
    if( $("body").hasClass("not-front") ) {
      $('html').css("overflow", "visible");
    }
  });



})(jQuery)
