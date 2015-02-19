<?php
/**
 * @file
 * Admin settings form.
 */

/**
 * Generate admin setting form.
 */
function maxymiser_admin_form() {
  $form = array();

  $form['maxymiser_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => maxymiser_get_url(),
    '#size' => 255,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#element_validate' => array('_maxymiser_admin_form_url_validate'),
    '#description' => t('Enter the full URL provided by Maxymiser. EG. http://service.maxymiser.net/cdn/YOUR_SITE_ID/js/mmcore.js'),
  );

  $form['maxymiser_exclude_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude tracking on specified pages'),
    '#default_value' => maxymiser_get_exclude_paths(),
  );

  $role_options = array_map('check_plain', user_roles());
  $form['maxymiser_exclude_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Exclude tracking for specified roles'),
    '#default_value' => maxymiser_get_exclude_roles(),
    '#options' => $role_options,
    '#description' => t('If none of the roles are selected, all users will be tracked.'),
  );

  return system_settings_form($form);
}

/**
 * Validate Maxymiser url.
 */
function _maxymiser_admin_form_url_validate($element, &$form_state) {
  if (!empty($element['#value']) && !valid_url($element['#value'])) {
    form_error($element, t('%url is not a valid url', array(
      '%url' => $element['#value'],
    )));
  }
}
