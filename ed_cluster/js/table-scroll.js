(function($) {
  Drupal.behaviors.ed_cluster = {
    'attach': function(context) {

      //Table with fixed left column used by Task manager
      $('body.page-node-task-manager .table-responsive').scroll(function(e) {

        $('table.scroll thead').css("left", -$(".table-responsive").scrollLeft());
        $('table.scroll thead th:nth-child(1)').css("left", $(".table-responsive").scrollLeft());
        $('table.scroll tbody td:nth-child(1)').css("left", $(".table-responsive").scrollLeft());
      });
    }
  }
})(jQuery);


