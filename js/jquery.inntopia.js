(function($) {
  Drupal.behaviors.inntopiaWidget = {
    attach: function(context, settings) {
      $('.inntopia-responsive-commerce-form', context).once('inntopiaWidget', function () {
        var widget = this;
        $('.inntopia-date[name=arrivaldate], .inntopia-date[name=departuredate], .inntopia-date[name=startdate]', this).datepicker({
          dateFormat: 'mm/dd/yy',
          numberOfMonths: 1,
          stepMonths: 1,
          showOn: 'both',
          minDate: 1,
          maxDate: 365,
          changeMonth: true,
          changeYear: true,
          buttonImage: '/sites/all/themes/sas7/images/cal-icon-18.png',
          buttonImageOnly: true
        });
        $('.inntopia-date[name=departuredate]', widget).datepicker('option', 'beforeShow', function(input, inst) {
            if($('.inntopia-date[name=arrivaldate]', widget).val()) {
              return {
                minDate: $('.inntopia-date[name=arrivaldate]', widget).datepicker("getDate"),
                disabled: false
              };
            } else {
              return {disabled: true};
            }
          }
        );
      });
    }
  };
  Drupal.behaviors.inntopiaItinerary = {
    attach: function(context, settings) {
      $('.inntopia-itinerary-js', context).once('inntopiaItinerary', function () {
        if(settings.inntopia && settings.inntopia.salesid  && settings.inntopia.host && $.cookie('sessionId')) {
          $.getJSON('https://' + settings.inntopia.host + '/Ecomm/widgets/itinerary/json/c0984597-9ffb-40ca-9af8-8a9ba1bff595' + $.cookie('sessionId'), null, function(data) {
            // Need cross origin policy to continue dev/testing
          });
        }
      });
    }
  };
})(jQuery);