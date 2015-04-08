(function ($) {
    Drupal.behaviors.ed_portfolio_progress_bar = {
        attach: function(context, settings) {            
            $('.field-name-ed-portfolio-show-comp-profile').html('<a href="'+Drupal.settings.ed_portfolio.nid+'/competency-profile"><div class="progress"></div></a>');
            $.each(Drupal.settings.ed_portfolio.profile, function(index, value){
                $('.progress').append('<div class="bar" style="width:'+value.count*100+'%;background-image:none; background-color:'+value.color+';margin:0;border-radius:0;"></div>');  
            });          
        }
    };
})(jQuery);

