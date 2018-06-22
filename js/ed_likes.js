(function ($) {
Drupal.behaviors.ed_likes = {
  attach: function(context, settings) {
    $('.ed-node-statistics', context).find('.ed-node-statistics-likes a').on('click', function(e) {
      e.preventDefault();

      $.ajax({
        url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'node/' + $(this).data('id') + '/edidaktikum/action/like',
        dataType: 'json',
        type: 'POST',
        success: function(response) {
          if (true == response.success) {
            console.log('erfe');
            $(e.currentTarget).parent().find('span.ed-likes-count').html( Drupal.t('@count likes', { '@count': response.count }));
          }
        }
      });
    });
  }
};
})(jQuery);

