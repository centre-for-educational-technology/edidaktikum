jQuery(function($){
   $.fn.eventCalendar.defaults = {
    eventsjson: 'js/events.json',
    eventsLimit: 4,
    monthNames: [ "Jaanuar", "Veebruar", "Märts", "Aprill", "Mai", "Juuni",
        "Juuli", "August", "September", "Oktoober", "November", "Detsember" ],
    dayNames: [ 'Pühapäev','Esmaspäev','Teisipäev','Kolmapäev',
        'Neljapäev','Reede','Laupäev' ],
    dayNamesShort: [ 'P','E','T','K', 'N','R','L' ],
    txt_noEvents: "Sellel perioodil ei ole ühtegi sündmust",
    txt_SpecificEvents_prev: "",
    txt_SpecificEvents_after: " sündmused:",
    txt_next: "järgnev",
    txt_prev: "eelnev",
    txt_NextEvents: "Järgmised sündmused:",
    txt_GoToEventUrl: "Vaata sündmust",
    showDayAsWeeks: true,
    startWeekOnMonday: true,
    showDayNameInCalendar: true,
    showDescription: false,
    onlyOneDescription: true,
    openEventInNewWindow: false,
    eventsScrollable: false,
    jsonDateFormat: 'timestamp', // you can use also "human" 'YYYY-MM-DD HH:MM:SS'
    moveSpeed: 500, // speed of month move when you clic on a new date
    moveOpacity: 0.15, // month and events fadeOut to this opacity
    jsonData: "",   // to load and inline json (not ajax calls)
    cacheJson: true, // if true plugin get a json only first time and after plugin filter events
                    // if false plugin get a new json on each date change
    locale: 'et'
    };
});
