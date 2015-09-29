(function($) {
  Drupal.behaviors.inntopiaWidget = {
    attach: function(context, settings) {
      $('.inntopia-responsive-commerce-form', context).once('inntopiaWidget', function () {
        var widget = this;
        $('.inntopia-date[name=arrivaldate], .inntopia-date[name=departuredate], .inntopia-date[name=startdate], .inntopia-date[name=enddate]', this).datepicker({
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
        $('.inntopia-date[name=enddate]', widget).datepicker('option', 'beforeShow', function(input, inst) {
            if($('.inntopia-date[name=startdate]', widget).val()) {
              return {
                minDate: $('.inntopia-date[name=startdate]', widget).datepicker("getDate"),
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
          var tgt = this;
          $.post('https://' + settings.inntopia.host + '/Ecomm/widgets/itinerary/json/' + $.cookie('sessionId'), null, function(data) {
            if(data && data.length) {
              var st = 0, tx = 0;
              $(data).each(function() {
                st += this.Price;
                tx += this.TaxesFees;
                $(tgt).append(
                  $('<div></div>')
                    .addClass('line-item')
                    .append('<span class="location">' + this.LocationName +  '</span>')
                    .append(' - ')
                    .append('<span class="price">' + settings.inntopia.csymbol + this.Price.toFixed(2) +  '</span>')
                    .append('<span class="product">' + this.ProductName +  '</span>')
                    .append('<span class="dates">' + this.ArrivalDate + ' - ' +this.DepartureDate + '</span>')
                );
              });
              $(tgt).append(
                $('<div></div>')
                  .addClass('sub-total')
                  .append('<span class="label">' + settings.inntopia.txt.st + '</span>')
                  .append('<span class="price">' + settings.inntopia.csymbol + st.toFixed(2) +  '</span>')
              );
              $(tgt).append(
                $('<div></div>')
                  .addClass('taxes')
                  .append('<span class="label">' + settings.inntopia.txt.tax + '</span>')
                  .append('<span class="price">' + settings.inntopia.csymbol + tx.toFixed(2) +  '</span>')
              );
              $(tgt).append(
                $('<div></div>')
                  .addClass('total')
                  .append('<span class="label">' + settings.inntopia.txt.tot + '</span>')
                  .append('<span class="price">' + settings.inntopia.csymbol + (tx + st).toFixed(2) +  '</span>')
              );
              $(tgt).append(
                $('<div></div>')
                  .addClass('actions')
                  .append('<a class="checkout" href="https://' + settings.inntopia.host + '/Ecomm/Checkout/Customer/' + settings.inntopia.salesid + '">' + settings.inntopia.txt.co + '</a>')
              );
            }
          }, 'json');
        }
      });
    }
  };
})(jQuery);