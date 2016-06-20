(function ($) {
  Drupal.behaviors.ed_q_portfolio = {
    attach: function(context, settings) {



      //
      //$(document).ajaxSuccess(function() {
      //  $('.competence-desc').slideDown('slow');
      //  $('.competence i').toggleClass("fa-chevron-up fa-chevron-down").once();
      //  console.log("ffff");
      //});
      //
      //
      //


      $('.competence i').once().click(function() {

        $(this).toggleClass("fa-chevron-down fa-chevron-up");

        if($(this).closest('li').hasClass('open')){
          $(this).parent().next().slideUp('slow');
        }else{
          $(this).parent().next().slideDown('slow');

        }

        $(this).closest('li').toggleClass('open');

        return false;
      });

      $('.competence a').once().click(function() {


        if(!$(this).closest("li").hasClass('open')){
          $(this).closest("li").find("i").toggleClass("fa-chevron-down fa-chevron-up");
          $(this).parent().next().slideDown('slow');
          $(this).closest('li').toggleClass('open');
        }

        return false;
      });





      $('.termtext', context).on('click', function(e) {



        //
        //
        ////getting the value from textfield
        //var tid=$(this).data("tid");
        //alert(tid);
        ////passing the value using 'POST' method
        //var post = "&tid="+tid;
        //$.ajax({
        //  'url': 'ed_q_portfolio/add-desc/',
        //  'type': 'POST',
        //  'dataType': 'json',
        //  'data': post
        //});


        //e.preventDefault();
        //var html = '';
        //
        //html +='<div id="myModal1" class="modal hide fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">';
        //html +=  '<div class="modal-header">';
        //html +=  '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>';
        //html +='<h3 id="myModalLabel">Edit Introduction</h3>';
        //html +='</div>';
        //
        //html +='<div class="modal-body">';
        //
        //html +=  '<form id="InfroText" method="POST">';
        //
        //html +=  '<input type="hidden" name="InfroText" value="1">';
        //
        //html +=  '<table>';
        //html +=  '<tbody><tr><td>Title</td><td><input type="text" name="title" id="title" style="width:300px"><span class="hide help-inline">This is required</span></td></tr>';
        //html +='<tr><td>Introudction</td><td><textarea name="contect" style="width:300px;height:100px"></textarea></td></tr>';
        //html +='</tbody></table>';
        //html +='</form>';
        //html +='</div>';
        //html +='<div class="modal-footer">';
        //html +=  '<button class="btn" data-dismiss="modal" aria-hidden="true">Close</button>';
        //html +=  '<button class="btn btn-primary" data-dismiss="modal" id="InfroTextSubmit">Save changes</button>';
        //html +='</div>';
        //html +='</div>';
        //return html;
          //$.ajax({
          //  url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'dashboard/search/delete/' + $(this).data('id'),
          //  dataType: 'json',
          //  type: 'POST',
          //  success: function(response) {
          //    if (true == response.success) {
          //      $(e.currentTarget).parent().remove();
          //    }
          //  }
          //});
      });
    }
  };
})(jQuery);

Drupal.theme.prototype.CToolsModalDialog = function () {
  var html = ''
  html += '  <div id="ctools-modal">'
  html += '    <div class="ctools-modal-content">' // panels-modal-content
  html += '      <div class="modal-header">';
  html += '        <a class="close" href="#">';
  html += '         <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>';
  html += '        </a>';
  html += '        <span id="modal-title" class="modal-title"> </span>';
  html += '      </div>';
  html += '      <div id="modal-content" class="modal-content">';
  html += '      </div>';
  html += '    </div>';
  html += '  </div>';

  return html;
};

