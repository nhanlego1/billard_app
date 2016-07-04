<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/9/16
 * Time: 2:19 PM
 * To change this template use File | Settings | File Templates.
 */
function stock_add_form($form, &$form_state){
  $form['cook_table'] = array(
    '#type' => 'select',
    '#title'=> t('Thực đơn'),
    '#options' => app_get_cook_table_array(),
  );
  $form['qty'] = array(
    '#type'=>'textfield',
    '#title' => t('Số lượng'),
    '#default_value'=> 1,
  );
  $form['submit'] = array(
    '#type'=>'submit',
    '#value' => 'Nhập kho'
  );
  return $form;
}

/**
 * @param $form
 * @param $form_state
 * Form validate
 */
function stock_add_form_validate($form, &$form_state){
  if(empty($form_state['values']['cook_table'])){
    form_set_error('cook_table',t('Vui lòng chọn thực đơn'));
  }
  if(empty($form_state['values']['qty']) || $form_state['values']['qty'] < 1 ){
    form_set_error('qty',t('Số lượng phải lớn hon 1 đơn vị'));
  }
}

/**
 * @param $form
 * @param $form_state
 * Form submit
 */
function stock_add_form_submit($form, &$form_state){
  $cook = cook_table_load($form_state['values']['cook_table']);
  $qty = $form_state['values']['qty'];
  app_stock_in($qty, $cook);
  drupal_set_message(t('Nhập kho cho '.$cook->name.' thành công.'));
  $form_state['redirect'] = 'app/cook-table/manager';
}