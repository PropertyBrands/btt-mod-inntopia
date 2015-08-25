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

  variable_get('innotopia_form_blocks', 1);

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
  return system_settings_form($form);
}