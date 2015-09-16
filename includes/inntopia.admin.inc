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
  $form['inntopia_currency_symbol'] = array(
    '#type' => 'textfield',
    '#title' => t('Currency Symbol'),
    '#size' => 12,
    '#description' => t('Applies to price display in sub-domain enabled Inntopia implementations.'),
    '#default_value' => variable_get('inntopia_currency_symbol', '$')
  );
  $form['innotopia_form_blocks'] = array(
    '#type' => 'select',
    '#title' => t('How many Inntopia widget blocks?'),
    '#options' => array_combine(range(1,20),range(1,20)),
    '#description' => t('The number of global Inntopia search widget blocks to make available for individual configuration and placement.'),
    '#default_value' => variable_get('innotopia_form_blocks', 1)
  );

  $form['inntopia_child_note'] = array(
    '#type' => 'textfield',
    '#title' => t('Child Description'),
    '#size' => 30,
    '#description' => t('The instructions to go with the number of children (eg. "18 and under").'),
    '#default_value' => variable_get('inntopia_child_note', 'Age 18 and under')
  );

//  $form['inntopia_destinations'] = array(
//    '#type' => 'select',
//    '#title' => t('Destinations'),
//    '#multiple' => TRUE,
//    '#options' => _inntopia_get_destination_options(),
//    '#size' => 16,
//    '#description' => t('Select one or more destinations here to limit destination search options in global widgets.'),
//    '#default_value' => variable_get('inntopia_destinations', array())
//  );
  return system_settings_form($form);
}