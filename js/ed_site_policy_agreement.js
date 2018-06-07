(function ($) {
  Drupal.behaviors.ed_policy_agreement = {
    attach: function(context, settings) {
      var policyAgreementSelector = 'input[name="policy_agreement"]';
      var submitSelector = 'button[type="submit"][name="op"]';

      if (!$(policyAgreementSelector, context).is(':checked')) {
        $(submitSelector, context).prop('disabled', true);
      }

      $(policyAgreementSelector, context).on('change', function() {
        if ($(this).is(':checked')) {
          $(submitSelector, context).prop('disabled', false);
        } else {
          $(submitSelector, context).prop('disabled', true);
        }
      });
    }
  };
})(jQuery);
