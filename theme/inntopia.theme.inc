<?php

function inntopia_preprocess_inntopia_responsive_commerce_form(&$vars) {
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_css(drupal_get_path('module', 'inntopia').'/css/inntopia.css');
  drupal_add_js(drupal_get_path('module', 'inntopia').'/js/jquery.inntopia.js');
}

function inntopia_preprocess_inntopia_responsive_commerce_itinerary_js(&$vars) {
  drupal_add_library('system', 'jquery.cookie');
  drupal_add_js(drupal_get_path('module', 'inntopia').'/js/jquery.inntopia.js');
  drupal_add_js(
    array('inntopia' => array(
      'salesid' => variable_get('inntopia_salesid', ''),
      'host' => variable_get('inntopia_hostname', 'www.inntopia.travel'),
      'csymbol' => variable_get('inntopia_currency_symbol', '$'),
      'txt' => array(
        'st' => t('Sub-Total'),
        'tot' => t('Total'),
        'tax' => t('Taxes and Fees'),
        'co' => t('Review and Checkout')
      )
    )
  ), array('type' => 'setting'));
  drupal_add_http_header('Access-Control-Allow-Origin', 'https://' . variable_get('inntopia_hostname', 'www.inntopia.travel'));
}

function inntopia_preprocess_inntopia_responsive_commerce_widget(&$vars) {
  drupal_add_css(drupal_get_path('module', 'inntopia').'/css/inntopia.css');
  drupal_add_js('//code.jquery.com/jquery-2.1.1.min.js', array('scope' => 'footer'));
  drupal_add_js('//code.jquery.com/ui/1.10.3/jquery-ui.js', array('scope' => 'footer'));
  drupal_add_js('//www.inntopia.travel/public/ecommwidget.js', array('scope' => 'footer'));
  if(empty($vars['salesid'])) {
    $vars['salesid'] =  variable_get('inntopia_salesid', '');
  }
}