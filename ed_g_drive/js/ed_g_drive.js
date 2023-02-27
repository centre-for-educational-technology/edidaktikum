(function ($) {

  $(document).on('click', '.ed_g_drive_file_btn', function () {
    loadPicker($(this).attr('order'));
  });


  $(document).on('click', '.ed_g_drive_file_btn_delete', function () {
    deleteFile($(this));
  });


  function deleteFile(thisObj) {
    var thisOrder = thisObj.attr('order');

    $("input[name='ed_g_drive_file[und][" + thisOrder + "][name]']").val('');
    $("input[name='ed_g_drive_file[und][" + thisOrder + "][url]']").val('');
    $("input[name='ed_g_drive_file[und][" + thisOrder + "][mime]']").val('');

    //thisObj.closest('.ed_g_drive_file_btn_wrapper').html('<div class="ed_g_drive_file_btn_wrapper"><input onclick="return false" class="ed_g_drive_file_btn btn form-submit" order="'+thisOrder+'" type="submit" id="edit-ed-g-drive-file-und-0-delete" name="op" value="Lisa"></div>');

    thisObj.closest('.ed_g_drive_file_btn_wrapper').html('<div class="ed_g_drive_file_btn_wrapper"><button class="ed_g_drive_file_btn btn btn-success form-submit" order="' + thisOrder + '" type="submit" id="edit-ed-g-drive-file-und-0-delete" name="op"><span class="icon glyphicon glyphicon-plus" aria-hidden="true"></span> Lisa</div>');

    return false;
  }

  const SCOPES = 'https://www.googleapis.com/auth/drive.metadata.readonly';
  const CLIENT_ID = '762863496631-79oga7v1ccsv6p695hac5s15hedprfls.apps.googleusercontent.com';
  const API_KEY = 'AIzaSyA7o1ExzW39ToUv7DaXiR-J0rX3ILByTzk';
  const APP_ID = '762863496631';

  var orderItem;

  let tokenClient;
  let accessToken = null;
  let pickerInited = false;
  let gisInited = false;

  /**
   * Callback after api.js is loaded.
   */
  function gapiLoaded() {
    window.gapi.load('client:picker', initializePicker);
  }

  /**
   * Callback after the API client is loaded. Loads the
   * discovery doc to initialize the API.
   */
  async function initializePicker() {
    await window.gapi.client.load('https://www.googleapis.com/discovery/v1/apis/drive/v3/rest');
    pickerInited = true;
    maybeEnableButtons();
  }

  /**
   * Callback after Google Identity Services are loaded.
   */
  function gisLoaded() {

    tokenClient = google.accounts.oauth2.initTokenClient({
      client_id: CLIENT_ID,
      scope: SCOPES,
      callback: '', // defined later
    });
    gisInited = true;
    maybeEnableButtons();
  }

  /**
   * Enables user interaction after all libraries are loaded.
   */
  function maybeEnableButtons() {
    if (pickerInited && gisInited) {
      document.getElementsByName('ed_g_drive_file_btn').forEach((button) => {
        button.disabled = false;
      });
    }
  }


  /**
   * Google API Loader script to load the google.picker script.
   * @param order
   */
  function loadPicker(order) {
    orderItem = order;
    gapiLoaded();
    gisLoaded();

    tokenClient.callback = async (response) => {
      if (response.error !== undefined) {
        throw (response);
      }
      accessToken = response.access_token;
      await createPicker();
    };

    if (accessToken === null) {
      // Prompt the user to select a Google Account and ask for consent to share their data
      // when establishing a new session.
      tokenClient.requestAccessToken({prompt: 'consent'});
    } else {
      // Skip display of account chooser and consent dialog for an existing session.
      tokenClient.requestAccessToken({prompt: ''});
    }
  }

  /**
   * Create and render a Picker object
   */
  function createPicker() {
    const view = new google.picker.View(google.picker.ViewId.DOCS);
    view.setMimeTypes('image/png,image/jpeg,image/jpg,application/pdf,application/vnd.openxmlformats-officedocument.wordprocessingml.document,application/msword,application/vnd.openxmlformats-officedocument.spreadsheetml.sheet,application/vnd.ms-excel,application/vnd.openxmlformats-officedocument.presentationml.presentation,application/vnd.ms-powerpoint');
    const picker = new google.picker.PickerBuilder()
      .enableFeature(google.picker.Feature.NAV_HIDDEN)
      .setDeveloperKey(API_KEY)
      .setAppId(APP_ID)
      .setOAuthToken(accessToken)
      .addView(view)
      .addView(new google.picker.DocsUploadView())
      .setCallback(pickerCallback)
      .build();
    picker.setVisible(true);
  }


  /**
   * A callback implementation.
   * @param data
   */
  function pickerCallback(data) {
    if (data.action === google.picker.Action.PICKED) {

      $("input[name='ed_g_drive_file[und][" + orderItem + "][name]']").val(data.docs[0].name);
      $("input[name='ed_g_drive_file[und][" + orderItem + "][url]']").val(data.docs[0].url);
      $("input[name='ed_g_drive_file[und][" + orderItem + "][mime]']").val(data.docs[0].iconUrl);


      $("input[name='ed_g_drive_file[und][" + orderItem + "][url]']").parents().eq(2).find('.ed_g_drive_file_btn_wrapper').html('<div class="ed_g_drive_file_btn_wrapper"><button onclick="return false" class="ed_g_drive_file_btn_delete btn btn-danger form-submit icon-before" order="' + orderItem + '" type="submit" id="edit-ed-g-drive-file-und-0-delete" name="op"><span class="icon glyphicon glyphicon-trash" aria-hidden="true"></span> Kustuta</button>' + ' <a href="' + data.docs[0].url + '">' + data.docs[0].name + '</a> <img src="' + data.docs[0].iconUrl + '"></div>');

      //$("input[name='ed_g_drive_file[und]["+orderItem+"][url]']").closest('td').append('<a href="'+data.docs[0].url+'">'+data.docs[0].name+' <img src="'+data.docs[0].iconUrl+'"></a>');
    }
  }


})(jQuery);

