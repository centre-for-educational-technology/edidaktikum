(function($) {


      $(document).on('click', '.ed_g_drive_file_btn', function(){
        loadPicker($(this).attr('order'));
      });


      $(document).on('click', '.ed_g_drive_file_btn_delete', function(){
        deleteFile($(this));
      });


      function deleteFile(thisObj) {
        var thisOrder = thisObj.attr('order');

        $("input[name='ed_g_drive_file[und]["+thisOrder+"][name]']").val('');
        $("input[name='ed_g_drive_file[und]["+thisOrder+"][url]']").val('');
        $("input[name='ed_g_drive_file[und]["+thisOrder+"][mime]']").val('');

        //thisObj.closest('.ed_g_drive_file_btn_wrapper').html('<div class="ed_g_drive_file_btn_wrapper"><input onclick="return false" class="ed_g_drive_file_btn btn form-submit" order="'+thisOrder+'" type="submit" id="edit-ed-g-drive-file-und-0-delete" name="op" value="Lisa"></div>');

        thisObj.closest('.ed_g_drive_file_btn_wrapper').html('<div class="ed_g_drive_file_btn_wrapper"><button class="ed_g_drive_file_btn btn btn-success form-submit" order="'+thisOrder+'" type="submit" id="edit-ed-g-drive-file-und-0-delete" name="op"><span class="icon glyphicon glyphicon-plus" aria-hidden="true"></span> Lisa</div>');

        return false;
      }

      // The Browser API key obtained from the Google API Console.
      // Replace with your own Browser API key, or your own key.
      var developerKey = 'AIzaSyA7o1ExzW39ToUv7DaXiR-J0rX3ILByTzk';

      // The Client ID obtained from the Google API Console. Replace with your own Client ID.
      var clientId = "762863496631-10pmpv9toajbkk0lf0nsf74c8071ab1e.apps.googleusercontent.com"

      // Replace with your own project number from console.developers.google.com.
      // See "Project number" under "IAM & Admin" > "Settings"
      var appId = "762863496631";

      // Scope to use to access user's Drive items.
      var scope = ['https://www.googleapis.com/auth/drive.readonly'];

      var pickerApiLoaded = false;
      var oauthToken;
      var orderItem;

      // Use the Google API Loader script to load the google.picker script.
      function loadPicker(order) {
        orderItem = order;
        gapi.load('auth', {'callback': onAuthApiLoad});
        gapi.load('picker', {'callback': onPickerApiLoad});
      }

      function onAuthApiLoad() {
        window.gapi.auth.authorize(
          {
            'client_id': clientId,
            'scope': scope,
            'immediate': false
          },
          handleAuthResult);
      }

      function onPickerApiLoad() {
        pickerApiLoaded = true;
        //Causes picker 2 times load
        //createPicker();
      }

      function handleAuthResult(authResult) {
        if (authResult && !authResult.error) {
          oauthToken = authResult.access_token;
          createPicker();
        }
      }

      // Create and render a Picker object for searching images.
      function createPicker() {
        if (pickerApiLoaded && oauthToken) {
          var view = new google.picker.View(google.picker.ViewId.DOCS);
          var picker = new google.picker.PickerBuilder()
            .enableFeature(google.picker.Feature.NAV_HIDDEN)
            .setAppId(appId)
            .setOAuthToken(oauthToken)
            .addView(view)
            .addView(new google.picker.DocsUploadView())
            .setDeveloperKey(developerKey)
            .setCallback(pickerCallback)
            .build();
          picker.setVisible(true);
        }
      }



      // A callback implementation.
      function pickerCallback(data) {
        if (data.action == google.picker.Action.PICKED) {

          $("input[name='ed_g_drive_file[und]["+orderItem+"][name]']").val(data.docs[0].name);
          $("input[name='ed_g_drive_file[und]["+orderItem+"][url]']").val(data.docs[0].url);
          $("input[name='ed_g_drive_file[und]["+orderItem+"][mime]']").val(data.docs[0].iconUrl);


          $("input[name='ed_g_drive_file[und]["+orderItem+"][url]']").parents().eq(2).find('.ed_g_drive_file_btn_wrapper').html('<div class="ed_g_drive_file_btn_wrapper"><input onclick="return false" class="ed_g_drive_file_btn_delete btn form-submit" order="'+orderItem+'" type="submit" id="edit-ed-g-drive-file-und-0-delete" name="op" value="Kustuta">'+' <a href="'+data.docs[0].url+'">'+data.docs[0].name+'</a> <img src="'+data.docs[0].iconUrl+'"></div>');

          //$("input[name='ed_g_drive_file[und]["+orderItem+"][url]']").closest('td').append('<a href="'+data.docs[0].url+'">'+data.docs[0].name+' <img src="'+data.docs[0].iconUrl+'"></a>');
        }
      }






})(jQuery);

