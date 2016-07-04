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
function cook_table_add_form($form, &$form_state, $entity)
{
  global $user;
  if (isset($entity)) {
    $form_state['cook_table'] = $entity;
  }
  $form['cook_table'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0
  );
  $form['cook_table']['uid'] = array(
    '#type' => 'hidden',
    '#value' => isset($entity->uid) ? $entity->uid : $user->uid
  );
  $form['cook_table']['cook_name'] = array(
    '#title' => t('Tên thức uống'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#require' => true,
  );
  $form['cook_table']['price'] = array(
    '#type' => 'textfield',
    '#title' => t('Giá bán (VND)'),
    '#default_value' => isset($entity->price) ? $entity->price : '',
    '#require' => true,
  );
  $form['cook_table']['stock'] = array(
    '#type' => 'textfield',
    '#title' => t('Tồn kho'),
    '#default_value' => isset($entity->stock) ? $entity->stock : '',
    '#require' => true,
  );

  $form['cook_table']['created'] = array(
    '#type' => 'hidden',
    '#value' => isset($entity->created_at) ? $entity->created_at : REQUEST_TIME,
  );
  $form['cook_table']['changed'] = array(
    '#type' => 'hidden',
    '#value' => REQUEST_TIME,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Lưu thực đơn')
  );
  return $form;
}

/**
 * Implement hook_form_validate()
 * validate price for cook_table
 */

function cook_table_add_form_validate($form, &$form_state)
{
  if (empty($form_state['values']['cook_name'])) {
    form_set_error('name', t('Vui lòng nhập tên thực đơn.'));
  }
  if (cook_table_get_cook_table('name', $form_state['values']['cook_name']) && empty($form_state['cook_table'])) {
    form_set_error('cook_name',t('Thực đơn đã tồn tại trong hệ thống. Bạn nên cân nhắc khi thêm.'));
  }
  if (empty($form_state['values']['price'])) {
    form_set_error('price', t('Vui lòng nhập giá cho thực đơn.'));
  }
  if (!is_numeric($form_state['values']['price'])) {
    form_set_error('price', t('Giá tiền không được chứa chữ cái hay ký tự đặc biệt.'));
  }
}

/**
 * Implement hook_form_submit()
 * Save cook_table
 */

function cook_table_add_form_submit($form, &$form_state)
{
  //check is_new or update
  // dsm($form_state);
  if (isset($form_state['cook_table']) && !empty($form_state['cook_table'])) {
    $entity = $form_state['cook_table'];
    $entity->name = $form_state['values']['cook_name'];
    $entity->price = $form_state['values']['price'];
    $entity->stock = !empty($form_state['values']['stock']) ? $form_state['values']['stock'] : 0;
    $entity->changed = $form_state['values']['changed'];
    if (cook_table_save($entity)) {
      drupal_set_message(t('Thực đơn ' . $form_state['values']['cook_name'] . ' đã được cập nhật thành công.'), 'status');
      $form_state['redirect'] = 'app/cook-table/manager';
    } else {
      drupal_set_message(t('Thực đơn ' . $form_state['values']['cook_name'] . ' không được cập nhật thành công. Vui lòng thử lại.'), 'error');
    }
  } else {
    $entity = new stdClass();
    $entity->uid = $form_state['values']['uid'];
    $entity->name = $form_state['values']['cook_name'];
    $entity->price = $form_state['values']['price'];
    $entity->stock = !empty($form_state['values']['stock']) ? $form_state['values']['stock'] : 0;
    $entity->created = date('Y-m-d H:i:s',$form_state['values']['created']);
    $entity->changed = date('Y-m-d H:i:s',$form_state['values']['changed']);
    if (cook_table_create($entity)) {
      drupal_set_message(t('Thực đơn ' . $form_state['values']['cook_name'] . ' đã được tạo thành công.'), 'status');
      $form_state['redirect'] = 'app/cook-table/manager';
    } else {
      drupal_set_message(t('Thực đơn ' . $form_state['values']['cook_name'] . ' không được tạo thành công. Vui lòng thử lại.'), 'error');
    }
  }

}

/**
 * Implement hook_form()
 * Form delete cook_table
 */
function cook_table_delete_form($form, &$form_state, $entity)
{
  $form_state['cook_table'] = $entity;
  $form['title'] = array(
    '#markup' => t('<h3>Bạn có muốn xóa @title không ?</h3>', array('@title' => $entity->name)),
  );
  $form['cancel'] = array(
    '#markup' => '<div class="cancel-link">' . l('Cancel', 'app/cook-table/manager', array('attributes' => array('id' => 'edit-cancel'))) . '</div>'
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
function cook_table_delete_form_submit($form, &$form_state)
{
  $entity = $form_state['cook_table'];
  cook_table_delete($entity->id);
  drupal_set_message(t('@title đã được xóa thành công.', array('@title' => $entity->name)), 'status');
  $form_state['redirect'] = 'app/cook-table/manager';
}