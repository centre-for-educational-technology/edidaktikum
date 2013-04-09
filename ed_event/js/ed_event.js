(function ($) {


    $(document).ready(function() {

        $.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'events/get/events',
            dataType: 'json',
            type: 'GET',
            success: function(response) {
                $("#events_calendar").eventCalendar({
                    jsonData: response,
                    onlyOneDescription: false,
                    showDescription: true,
                    eventsScrollable: true
                });
            }   
            
        });
        
    });
 
})(jQuery);
