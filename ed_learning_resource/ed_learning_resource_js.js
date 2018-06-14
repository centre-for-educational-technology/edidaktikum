(function ($){

  //Hide or show ed-field-external-res-url field depending on which type of resource is selected
  Drupal.behaviors.ed_learning_resource = {
    attach: function (context, settings){

         var methodical_resource_tax_id = null;
      var best_practice_tax_id = null;

      try{
        methodical_resource_tax_id = Drupal.settings.ed_learning_resource.methodical_resource_tax_id
      }catch(e){

      }

      try{
        best_practice_tax_id = Drupal.settings.ed_learning_resource.best_practice_tax_id
      }catch(e){

      }

      if(methodical_resource_tax_id != null){
        if($("#edit-ed-learning-resource-type-und").val() == methodical_resource_tax_id || $("#edit-ed-learning-resource-type-und").val() == best_practice_tax_id){
          $("#edit-ed-field-external-res-url").show();
        }else{
          $("#edit-ed-field-external-res-url").hide();
        }

        $("#edit-ed-learning-resource-type-und").change(function() {
          var val = $(this).val();
          console.log(val);
          if($("#edit-ed-learning-resource-type-und").val() == methodical_resource_tax_id || $("#edit-ed-learning-resource-type-und").val() == best_practice_tax_id){
            $("#edit-ed-field-external-res-url").show();
          }
          else  {
            $("#edit-ed-field-external-res-url").hide();
          }
        });

      }


    },


  }
})(jQuery);
