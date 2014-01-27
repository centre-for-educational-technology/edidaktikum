(function($) {

    jQuery(document).ready(function() {

        if (Drupal.settings.edidaktikum !== undefined && Drupal.settings.edidaktikum !== null && Drupal.settings.edidaktikum.ed_uservoice_api_key !== undefined && Drupal.settings.edidaktikum !== null)  {
            UserVoice=window.UserVoice||[];
            (function(){
                var uv=document.createElement('script');
                uv.type='text/javascript';
                uv.async=true;
                uv.src='//widget.uservoice.com/'+Drupal.settings.edidaktikum.ed_uservoice_api_key+'.js'
                var s=document.getElementsByTagName('script')[0];
                s.parentNode.insertBefore(uv,s)
            })();

            UserVoice.push(['addTrigger', {
                trigger_style: 'tab',
                locale: Drupal.settings.edidaktikum.locale,
            }]);

            if (Drupal.settings.edidaktikum.authenticated !== undefined && Drupal.settings.edidaktikum.authenticated !== null && Drupal.settings.edidaktikum.authenticated == true) {
                UserVoice.push(['identify', {
                    email: Drupal.settings.edidaktikum.email,
                    name: Drupal.settings.edidaktikum.name,
                    created_at: Drupal.settings.edidaktikum.created_at,
                    id: Drupal.settings.edidaktikum.uid
                  }
                ]);
            }
        }

    });

})(jQuery);
