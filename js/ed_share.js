window.fbAsyncInit = function() {
  FB.init({
    appId            : '199652200236343',
    autoLogAppEvents : true,
    xfbml            : true,
    version          : 'v2.5'
  });
  FB.AppEvents.logPageView();
};

(function(d, s, id){
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) {return;}
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));


window.twttr = (function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0],
    t = window.twttr || {};
  if (d.getElementById(id)) return t;
  js = d.createElement(s);
  js.id = id;
  js.src = "https://platform.twitter.com/widgets.js";
  fjs.parentNode.insertBefore(js, fjs);

  t._e = [];
  t.ready = function(f) {
    t._e.push(f);
  };

  return t;
}(document, "script", "twitter-wjs"));

(function(d){
  var f = d.getElementsByTagName('SCRIPT')[0], p = d.createElement('SCRIPT');
  p.type = 'text/javascript';
  p.async = true;
  p.src = '//assets.pinterest.com/js/pinit.js';
  f.parentNode.insertBefore(p, f);
}(document));



function postToPinterest(media){
  PinUtils.pinOne({
    media: media,
  });
}




// Facebook sharing button handler
function postToFeed(title, desc, url, image) {

  //window.open('https://www.facebook.com/sharer.php?title='+title+'&description='+desc+'&u='+url+'&picture='+image, 'Share', 'scrollbars=yes,resizable=yes,toolbar=no,menubar=no,scrollbars=no,location=no,directories=no,width=300, height=300, top=300, left=300' );


  FB.ui({
    method: 'share_open_graph',
    action_type: 'og.shares',
    action_properties: JSON.stringify({
      object: {
        'og:url': url,
        'og:title': title,
        'og:description': desc,
        'og:image': image
      }
    })
  });
}



(function ($) {
  Drupal.behaviors.ed_share = {
    attach: function(context, settings) {
      $('.share_facebook').click(function () {
        elem = $(this);
        postToFeed(elem.data('title'), elem.data('desc'), elem.prop('href'), elem.data('image'));

        return false;
      });

      $('.share_pinterest').click(function () {
        elem = $(this);
        postToPinterest(elem.data('media'));

        return false;
      });

    }
  };
})(jQuery);

