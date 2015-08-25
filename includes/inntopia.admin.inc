<?php
function inntopia_admin_general_settings_form($form, &$form_state) {
  $form['inntopia_salesid'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Global Sales ID'),
    '#size' => 12,
    '#description' => t('The salesid parameter to be used by default in Inntopia widgets and links throughout the site.'),
    '#default_value' => variable_get('inntopia_salesid', '')
  );
  $form['inntopia_hostname'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Global Inntopia Hostname'),
    '#size' => 50,
    '#description' => t('The responsive commerce hostname to be used by default in Inntopia widgets and links throughout the site.'),
    '#default_value' => variable_get('inntopia_hostname', 'www.inntopia.travel')
  );
  return system_settings_form($form);
}