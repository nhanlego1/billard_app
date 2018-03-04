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
function staff_add_form($form, &$form_state, $entity)
{
  global $user;
  if (isset($entity)) {
    $form_state['staff'] = $entity;
  }
  $form['staff'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0
  );
  $form['staff']['uid'] = array(
    '#type' => 'hidden',
    '#value' => isset($entity->uid) ? $entity->uid : $user->uid
  );
  $form['staff']['name'] = array(
    '#title' => t('Tên nhân viên'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. Nguyễn Thị A'))
  );
  $form['staff']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Điện thoại'),
    '#default_value' => isset($entity->phone) ? $entity->phone : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. 09123456789'))
  );
  $form['staff']['card_id'] = array(
    '#type' => 'textfield',
    '#title' => t('CMND'),
    '#default_value' => isset($entity->card_id) ? $entity->card_id : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. 0123456789'))
  );
  $form['staff']['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Địa chỉ'),
    '#default_value' => isset($entity->address) ? $entity->address : '',
    '#require' => FALSE,
    '#attributes' => array('placeholder' => t('Ex. Cần Giờ, HCM'))
  );
  $form['staff']['birthday'] = array(
    '#type' => 'date_popup',
    '#title' => t('Ngày sinh'),
    '#default_value' => isset($entity->birthday) ? $entity->birthday : '',
    '#require' => FALSE,
    '#attributes' => array('placeholder' => t('Ex. 1990-06-01')),
    '#date_format' => 'd/m/Y',
    '#date_label_position' => 'within',
    '#date_increment' => 15,
    '#date_year_range' => '-90:+0',
  );
  $form['staff']['startdate'] = array(
    '#type' => 'date_popup',
    '#title' => t('Ngày bắt đầu làm việc'),
    '#default_value' => isset($entity->startdate) ? $entity->startdate : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. 1990-06-01')),
    '#date_format' => 'd/m/Y',
    '#date_label_position' => 'within',
    '#date_increment' => 15,
    '#date_year_range' => '-90:+0',
  );

  $form['staff']['created'] = array(
    '#type' => 'hidden',
    '#value' => isset($entity->created_at) ? $entity->created_at : REQUEST_TIME,
  );
  $form['staff']['changed'] = array(
    '#type' => 'hidden',
    '#value' => REQUEST_TIME,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu Nhân viên')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for staff
 */

function staff_add_form_validate($form, &$form_state)
{
  if (empty($form_state['values']['name'])) {
    form_set_error('name', t('Vui lòng nhập tên NV.'));
  }
  if (staff_get_staff('name', $form_state['values']['name']) && empty($form_state['staff'])) {
    form_set_error('name', t('NV ' . $form_state['values']['name'] . ' đã tồn tại trong hệ thống. Bạn nên cân nhắc khi thêm.'));
  }
  if (empty($form_state['values']['card_id'])) {
    form_set_error('price', t('Vui lòng nhập CMND.'));
  }
  if (empty($form_state['values']['phone'])) {
    form_set_error('price', t('Vui lòng nhập điện thoại.'));
  }
  if (!is_numeric($form_state['values']['phone'])) {
    form_set_error('price', t('Điện thoại không được chứa chữ cái hay ký tự đặc biệt.'));
  }
  if (!is_numeric($form_state['values']['card_id'])) {
    form_set_error('price', t('CMND không được chứa chữ cái hay ký tự đặc biệt.'));
  }
}

/**
 * Implement hook_form_submit()
 * Save staff
 */

function staff_add_form_submit($form, &$form_state)
{
  //check is_new or update
  // dsm($form_state);
  if (isset($form_state['staff']) && !empty($form_state['staff'])) {
    $entity = $form_state['staff'];
    $entity->uid = $form_state['values']['uid'];
    $entity->name = $form_state['values']['name'];
    $entity->phone = $form_state['values']['phone'];
    $entity->card_id = $form_state['values']['card_id'];
    $entity->address = $form_state['values']['address'];
    $entity->birthday = $form_state['values']['birthday'];
    $entity->startdate = $form_state['values']['startdate'];
    $entity->changed = $form_state['values']['changed'];
    if (staff_save($entity)) {
      drupal_set_message(t('Nhân viên ' . $form_state['values']['name'] . ' đã được cập nhật thành công.'), 'status');
      $form_state['redirect'] = 'app/staff/manager';
    } else {
      drupal_set_message(t('Nhân viên ' . $form_state['values']['name'] . ' không được cập nhật thành công. Vui lòng thử lại.'), 'error');
    }
  } else {
    $entity = new stdClass();
    $entity->uid = $form_state['values']['uid'];
    $entity->name = $form_state['values']['name'];
    $entity->phone = $form_state['values']['phone'];
    $entity->card_id = $form_state['values']['card_id'];
    $entity->address = $form_state['values']['address'];
    $entity->birthday = $form_state['values']['birthday'];
    $entity->startdate = $form_state['values']['startdate'];
    $entity->created = $form_state['values']['created'];
    $entity->changed = $form_state['values']['changed'];
    if (staff_create($entity)) {
      drupal_set_message(t('Nhân viên ' . $form_state['values']['name'] . ' đã được tạo thành công.'), 'status');
      $form_state['redirect'] = 'app/staff/manager';
    } else {
      drupal_set_message(t('Nhân viên ' . $form_state['values']['name'] . ' không được tạo thành công. Vui lòng thử lại.'), 'error');
    }
  }

}

/**
 * Implement hook_form()
 * Form delete staff
 */
function staff_delete_form($form, &$form_state, $entity)
{
  $form_state['staff'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Bạn có muốn xóa @title không ?</h3>', array('@title' => $entity->name)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'app/staff/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
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
function staff_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['staff'];
  staff_delete($entity->id);
  drupal_set_message(t('@title đã được xóa thành công.', array('@title' => $entity->name)), 'status');
  $form_state['redirect'] = 'app/staff/manager';
}