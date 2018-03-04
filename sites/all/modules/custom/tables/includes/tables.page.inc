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
function tables_add_form($form, &$form_state, $entity)
{
  global $user;
  if (isset($entity)) {
    $form_state['tables'] = $entity;
  }
  $form['tables'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0
  );
  $form['tables']['uid'] = array(
    '#type' => 'hidden',
    '#value' => isset($entity->uid) ? $entity->uid : $user->uid
  );
  $form['tables']['name'] = array(
    '#title' => t('Tên bàn'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. Bàn 1'))
  );
  $form['tables']['price'] = array(
    '#type' => 'textfield',
    '#title' => t('Giá tiền / giờ (VND)'),
    '#default_value' => isset($entity->price) ? $entity->price : '',
    '#require' => true,
    '#attributes' => array('placeholder' => t('Ex. 45000'))
  );

  $form['tables']['created'] = array(
    '#type' => 'hidden',
    '#value' => isset($entity->created_at) ? $entity->created_at : REQUEST_TIME,
  );
  $form['tables']['changed'] = array(
    '#type' => 'hidden',
    '#value' => REQUEST_TIME,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu bàn')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for tables
 */

function tables_add_form_validate($form, &$form_state)
{
  if (empty($form_state['values']['name'])) {
    form_set_error('name', t('Vui lòng nhập tên Bàn.'));
  }
  if (tables_get_tables('name', $form_state['values']['name']) && empty($form_state['tables'])) {
    form_set_error('name',t('Bàn '.$form_state['values']['name'].' đã tồn tại trong hệ thống. Bạn nên cân nhắc khi thêm.'));
  }
  if (empty($form_state['values']['price'])) {
    form_set_error('price', t('Vui lòng nhập giá cho Bàn.'));
  }
  if (!is_numeric($form_state['values']['price'])) {
    form_set_error('price', t('Giá tiền không được chứa chữ cái hay ký tự đặc biệt.'));
  }
}

/**
 * Implement hook_form_submit()
 * Save tables
 */

function tables_add_form_submit($form, &$form_state)
{
  //check is_new or update
  // dsm($form_state);
  if (isset($form_state['tables']) && !empty($form_state['tables'])) {
    $entity = $form_state['tables'];
    $entity->name = $form_state['values']['name'];
    $entity->price = $form_state['values']['price'];
    $entity->changed = $form_state['values']['changed'];
    if (tables_save($entity)) {
      drupal_set_message(t('Bàn ' . $form_state['values']['name'] . ' đã được cập nhật thành công.'), 'status');
      $form_state['redirect'] = 'app/tables/manager';
    } else {
      drupal_set_message(t('Bàn ' . $form_state['values']['name'] . ' không được cập nhật thành công. Vui lòng thử lại.'), 'error');
    }
  } else {
    $entity = new stdClass();
    $entity->uid = $form_state['values']['uid'];
    $entity->name = $form_state['values']['name'];
    $entity->price = $form_state['values']['price'];
    $entity->created = $form_state['values']['created'];
    $entity->changed = $form_state['values']['changed'];
    if (tables_create($entity)) {
      drupal_set_message(t('Bàn ' . $form_state['values']['name'] . ' đã được tạo thành công.'), 'status');
      $form_state['redirect'] = 'app/tables/manager';
    } else {
      drupal_set_message(t('Bàn ' . $form_state['values']['name'] . ' không được tạo thành công. Vui lòng thử lại.'), 'error');
    }
  }

}

/**
 * Implement hook_form()
 * Form delete tables
 */
function tables_delete_form($form, &$form_state, $entity)
{
  $form_state['tables'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Bạn có muốn xóa @title không ?</h3>', array('@title' => $entity->name)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'app/tables/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
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
function tables_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['tables'];
  tables_delete($entity->id);
  drupal_set_message(t('@title đã được xóa thành công.', array('@title' => $entity->name)), 'status');
  $form_state['redirect'] = 'app/tables/manager';
}