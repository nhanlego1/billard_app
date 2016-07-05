<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/9/16
 * Time: 2:19 PM
 * To change this template use File | Settings | File Templates.
 */
function order_debt_form($form, &$form_state, $order){
  $form_state['order'] = $order;
  $form['id'] = array(
    '#type'=>'textfield',
    '#title' => 'Số hóa đơn',
    '#default_value' => $order->id,
    '#attributes'=>array('disabled'=>true),
  );
  $form['date_order'] = array(
    '#type'=>'textfield',
    '#title' => 'Ngày hóa đơn',
    '#default_value' => format_date($order->created,'custom','d/m/Y'),
    '#attributes'=>array('disabled'=>true),
  );
  $form['customer'] = array(
    '#type'=>'textfield',
    '#title' => 'Khách hàng',
    '#default_value' => $order->customer,
    '#attributes'=>array('disabled'=>true),
  );
  $form['total'] = array(
    '#type'=>'textfield',
    '#title' => 'Tổng thanh toán',
    '#default_value' => number_format($order->total_all_amount ).' đ',
    '#attributes'=>array('disabled'=>true),
  );
  $form['debt'] = array(
    '#type'=>'textfield',
    '#title' => 'Khoản nợ',
    '#default_value' => number_format($order->exist_amount).' đ',
    '#attributes'=>array('disabled'=>true),
  );
  $form['paid'] = array(
    '#type'=>'textfield',
    '#title' => 'Trả trước',
    '#default_value' => number_format($order->paid).' đ',
    '#attributes'=>array('disabled'=>true),
  );
  $form['paid_today'] = array(
    '#type'=>'textfield',
    '#title' => 'Thoanh toán',
  );
  $form['submit'] = array(
    '#type'=>'submit',
    '#value'=>'Thanh toán'
  );
  return $form;
}

/**
 * Implement hook_validate
 */
function order_debt_form_validate($form, &$form_state){
  if(empty($form_state['values']['paid_today'])){
   form_set_error('paid_today', t('Vui lòng nhập số tiền thanh toán.'));
  }
}
/**
 * Implement hook_form_submit
 */
function order_debt_form_submit($form, &$form_state){
  $order = $form_state['order'];
  $total = $order->total_all_amount - ($form_state['values']['paid_today'] + $order->paid);
  if($total==0){
    $order->exist_amount = 0;
    $order->paid = $order->total_all_amount;
    $order->debt = 0;
  }else{
    $order->exist_amount = $total;
    $order->paid = $order->total_all_amount - $total;
  }
  order_save($order);
  drupal_set_message(t('Thanh toán thành công.'));
  $form_state['redirect'] = 'app/order/debt';
}