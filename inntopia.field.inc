<?php
/**
 * Thanks very much to example.module
 */

/**
 * Implements hook_field_formatter_info().
 *
 * We need to tell Drupal that we have two different types of formatters
 * for this field. One will change the text color, and the other will
 * change the background color.
 *
 * @see field_example_field_formatter_view()
 */
function inntopia_field_formatter_info() {
  return array(
    'responsive_commerce_form' => array(
      'label' => t('Responsive Commerce Form'),
      'field types' => array('inntopia_widget'),
    ),
    'responsive_commerce_link' => array(
      'label' => t('Responsive Commerce Link'),
      'field types' => array('inntopia_widget'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 *
 * Two formatters are implemented.
 * - field_example_simple_text just outputs markup indicating the color that
 *   was entered and uses an inline style to set the text color to that value.
 * - field_example_color_background does the same but also changes the
 *   background color of div.region-content.
 *
 * @see field_example_field_formatter_info()
 */
function inntopia_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  foreach ($items as $delta => $item) {
    switch($display['type']) {
      case 'responsive_commerce_form':
        $element[$delta] = drupal_get_form('inntopia_responsive_commerce_form', $item);
        break;
      case 'responsive_commerce_widget':
        $element[$delta] = array(
          '#theme' => 'inntopia_responsive_commerce_widget',
          '#settings' => $item,
        );
        break;
      case 'responsive_commerce_link':
        $element[$delta] = array(
          '#theme' => 'inntopia_responsive_commerce_widget',
          '#settings' => $item,
        );
        break;
    }
  }
  return $element;
}

/**
 * Implements hook_field_info().
 *
 * Provides the description of the field.
 */
function inntopia_field_info() {
  return array(
    // We name our field as the associative name of the array.
    'inntopia_widget' => array(
      'label' => t('Inntopia Widget'),
      'description' => t('Inntopia search widget with options for supplier, package, dates, etc.'),
      'default_widget' => 'inntopia_widget',
      'default_formatter' => 'responsive_commerce_widget',
      'instance_settings' => array(
        'as_link' => FALSE,
        'label' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_field_is_empty().
 *
 * hook_field_is_emtpy() is where Drupal asks us if this field is empty.
 * Return TRUE if it does not contain data, FALSE if it does. This lets
 * the form API flag an error when required fields are empty.
 */
function inntopia_field_is_empty($item, $field) {
  return empty($item['salesid']) && empty($item['supplierid']) && empty($item['packageid']) && empty($item['arrivaldate']) && empty($item['departuredate']) && empty($item['calltoaction']);
}

/**
 * Implements hook_field_widget_info().
 *
 * Three widgets are provided.
 * - A simple text-only widget where the user enters the '#ffffff'.
 * - A 3-textfield widget that gathers the red, green, and blue values
 *   separately.
 * - A farbtastic colorpicker widget that chooses the value graphically.
 *
 * These widget types will eventually show up in hook_field_widget_form,
 * where we will have to flesh them out.
 *
 * @see inntopia_field_widget_form()
 */
function inntopia_field_widget_info() {
  return array(
    'inntopia_widget' => array(
      'label' => t('Responsive Commerce Options'),
      'field types' => array('inntopia_widget'),
    ),
  );
}

function inntopia_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach($items as &$item) {
    $item = array_filter($item);
  }
}

/**
 * Implements hook_field_widget_form().
 *
 * hook_widget_form() is where Drupal tells us to create form elements for
 * our field's widget.
 *
 * We provide one of three different forms, depending on the widget type of
 * the Form API item provided.
 *
 * The 'field_example_colorpicker' and 'field_example_text' are essentially
 * the same, but field_example_colorpicker adds a javascript colorpicker
 * helper.
 *
 * field_example_3text displays three text fields, one each for red, green,
 * and blue. However, the field type defines a single text column,
 * rgb, which needs an HTML color spec. Define an element validate
 * handler that converts our r, g, and b fields into a simulated single
 * 'rgb' form element.
 */
function inntopia_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element)  {
  $element = _inntopia_widget_form_add_fields($element, $items[$delta], TRUE);
  $element['#type'] = 'fieldset';
  $element['#title'] = t('Inntopia Widget Settings');
  $element['#attributes']['class'][] = 'inntopia-widget-settings';
  return $element;
}