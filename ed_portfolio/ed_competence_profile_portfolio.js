(function ($) {
    Drupal.behaviors.ed_competence_profile_portfolio = {
        attach: function(context, settings) {
            $('.term-name > a').on('click', function(e){
                e.preventDefault();
                var nexti = $(this).next('i');
                if(nexti.hasClass('fa-angle-down')){
                    nexti.removeClass('fa-angle-down');
                    nexti.addClass('fa-angle-up');
                }else{
                    nexti.removeClass('fa-angle-up');
                    nexti.addClass('fa-angle-down');
                }
                $(this).parent().parent().parent().next('.detailed-view-container').toggle();
            });
        }
    };
})(jQuery);

