(function ($) {


    $(document).ready(function() {

        $.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + Drupal.settings.edidaktikum.ed_cluster_group_events_ajax_url,
            dataType: 'json',
            type: 'GET',
            success: function(response) {
                $("#group_events_calendar").eventCalendar({
                    jsonData: response,
                    onlyOneDescription: false,
                    showDescription: true,
                    eventsScrollable: true
                });
            }   
            
        });
        
    });
 
})(jQuery);
