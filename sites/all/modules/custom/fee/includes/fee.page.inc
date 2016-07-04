<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/9/16
 * Time: 2:19 PM
 * To change this template use File | Settings | File Templates.
 */
/**
 * Implement hook_form()
 * Form add order
 */
function fee_add_form($form, &$form_state, $entity)
{
  global $user;

  $form['fee'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0
  );

  $form['fee']['fee_total'] = array(
    '#title' => t('Tổng chi phí'),
    '#type' => 'textfield',
    '#require' => true,
  );
  $form['fee']['fee_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Ngày'),
    '#default_value' => 'now',
    '#require' => FALSE,
    '#date_format' => 'Y-m-d',
    '#date_label_position' => 'within',
    '#date_increment' => 15,
    '#date_year_range' => '-3:+10',
  );
  $form['fee']['reason'] = array(
    '#type' => 'textarea',
    '#title' => t('Lý do'),
    '#require' => true,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu chi phí')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for fee
 */

function fee_add_form_validate($form, &$form_state)
{
  if (empty($form_state['values']['fee_total'])) {
    form_set_error('fee_total', t('Vui lòng nhập chi phí.'));
  }

  if (empty($form_state['values']['fee_date'])) {
    form_set_error('fee_date', t('Vui lòng chọn ngày.'));
  }
  if (empty($form_state['values']['reason'])) {
    form_set_error('reason', t('Vui lòng nhập lý do chi.'));
  }

}

/**
 * Implement hook_form_submit()
 * Save fee
 */

function fee_add_form_submit($form, &$form_state)
{
    global $user;
    $entity = new stdClass();
    $entity->uid = $user->uid;
    $entity->fee_total = $form_state['values']['fee_total'];
    $entity->fee_date = strtotime($form_state['values']['fee_date']);
    $entity->reason = $form_state['values']['reason'];
    $entity->created = REQUEST_TIME;
    $entity->changed = REQUEST_TIME;
    if (fee_create($entity)) {
      drupal_set_message(t('Phí đã được tạo thành công.'), 'status');
      $form_state['redirect'] = 'app/fee/manager';
    } else {
      drupal_set_message(t('Phí không được tạo thành công. Vui lòng thử lại.'), 'error');
    }
}

/**
 * Implement hook_form()
 * Form delete fee
 */
function fee_delete_form($form, &$form_state, $entity)
{
  $form_state['fee'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Bạn có muốn xóa @title không ?</h3>', array('@title' => $entity->reason)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'app/fee/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete')
  );
  return $form;

}

/**
 * Implement hook_form_submit
 * Delete drink
 */
function fee_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['fee'];
  fee_delete($entity->id);
  drupal_set_message(t('@title đã được xóa thành công.', array('@title' => $entity->reason)), 'status');
  $form_state['redirect'] = 'app/fee/manager';
}