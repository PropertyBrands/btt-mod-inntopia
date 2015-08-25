<?php

function inntopia_preprocess_inntopia_responsive_commerce_form(&$vars) {
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_js(drupal_get_path('module', 'inntopia').'/js/jquery.inntopia.js');
}

function inntopia_preprocess_inntopia_responsive_commerce_widget(&$vars) {
  drupal_add_js('//code.jquery.com/jquery-2.1.1.min.js', array('scope' => 'footer'));
  drupal_add_js('//code.jquery.com/ui/1.10.3/jquery-ui.js', array('scope' => 'footer'));
  drupal_add_js('//www.inntopia.travel/public/ecommwidget.js', array('scope' => 'footer'));
  if(empty($vars['salesid'])) {
    $vars['salesid'] =  variable_get('inntopia_salesid', '');
  }
}