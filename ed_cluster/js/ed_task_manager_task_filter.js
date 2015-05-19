(function($) {
    Drupal.behaviors.ed_cluster = {
        'attach': function(context) {
            $('.ed_filter_tasks').on('click', function(){
                var tasktofilter = $('.ed_task_selection_for_filtering').val();
                var cluster = $('.ed_task_selection_for_filtering').data('cluster');
                var path = 'node/'+cluster+'/task-manager';
                if(tasktofilter!=0){
                    path = path+'?tasknid='+tasktofilter;
                }
                location.href = (Drupal.settings.basePath + path);
            });
        }
    }
})(jQuery);

