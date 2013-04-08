(function ($) {


    $(document).ready(function() {

        //Drupal.behaviors.myModule = function(context) {
            
        var eventsInline = [
                {"date": "1365161300000", "type": "meeting", "title": "Project A meeting", "description": "Lorem Ipsum dolor set", "url": "http://www.event1.com/" }
        ];
        
        $.ajax({
            url: '/drupalprojects/edidaktikum/events/get/events',
            dataType: 'json',
            type: 'GET',
            success: function(response) {
                console.log(response);
                //alert(JSON.stringify(response));
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
