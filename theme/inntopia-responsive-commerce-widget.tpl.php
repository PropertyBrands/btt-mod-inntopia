<script>
  var inntopiaVariables = {
    salesId: <?php print $salesid; ?>, //replace '000000' with your salesId
    widgetType: <?php print $supplierid ? '3' : '1'; ?>, //Select one of the following: 1=lodging search,  2=activity search, 3=hotel/location lodging search
    productSuperCategoryId: null, //required for widgetType: 2. Refer to http://www.inntopia.com/inntopia/templates/reports/productcategories_RAW.xml
    widgetLayout: 'horizontal', //Select one of the following: 'horizontal' or 'vertical'
    supplierId: <?php print $supplierid ?: 'null'; ?>, //required for widgetType: 3
    productCategoryId: 117, //optional for widgetType: 2. to http://www.inntopia.com/inntopia/templates/reports/productcategories_RAW.xml
    startDateLabel: 'Starting', //for activity search labels
    arrivalDateLabel: 'Arrival', //for lodging search labels
    departureDateLabel: 'Departure', //for lodging search labels
    adultLabel: 'Adults', //for lodging search labels
    childLabel: 'Children', //for lodging search labels
    buttonText: 'Check Availability', //button text for all widget types
    domain: 'www.inntopia.travel', //update with your custom domain, if available
    language: 'en-US' //only en-US currently supported for this widget
    forcechoice: <?php print $forcechoice ?: 'null'; ?> //only en-US currently supported for this widget
  };
</script>
<div id="inntopiaWidget"></div>
