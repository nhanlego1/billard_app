<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/16/16
 * Time: 3:51 PM
 * To change this template use File | Settings | File Templates.
 */

/**
 * Implement ctool modal
 * CHange table
 */
function app_change_table($table, $ajax){
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_add_js('ajax-responder');

    $form_state = array(
      'table' => $table,
      'ajax' => TRUE,
      'title' => t('Chuyển bàn'),
    );
    // a form in a modal popup.
    $output = ctools_modal_form_wrapper('app_change_table_form', $form_state);
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
      $output = $form_state['ajax_commands'];
    }
    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('app_change_table_form');
  }
}


/**
 * Implement hook_form
 * Form change table
 */
function app_change_table_form($form, &$form_state){
  $table = $form_state['table'];

  $form['tables'] = array(
    '#type' => 'select',
    '#title' =>t('Chọn bàn'),
    '#options' => app_get_table_array($table),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' =>'Chuyển bàn'
  );
  return $form;
}

/**
 * Implement hook_form_submit
 * Form change table
 */
function app_change_table_form_submit($form, &$form_state){
  $table = $form_state['table'];
  $newtable = $form_state['values']['tables'];
  $order = app_check_table_ready($table);
  $order->table_id = $newtable;
  order_save($order);
  //update order_item
  $items = app_get_item_list($table, $order);
  foreach($items as $item){
    $item->table_id = $newtable;
    order_item_save($item);
  }

  // Tell the browser to close the modal.
  $form_state['ajax_commands'][] = ctools_ajax_command_reload();
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
}


/**
 * Implement ctool modal
 * CHange hour
 */
function app_change_hour($table, $ajax){
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_add_js('ajax-responder');

    $form_state = array(
      'table' => $table,
      'ajax' => TRUE,
      'title' => t('Nhập lại giờ'),
    );
    // a form in a modal popup.
    $output = ctools_modal_form_wrapper('app_change_hour_form', $form_state);
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
      $output = $form_state['ajax_commands'];
    }
    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('app_change_hour_form');
  }
}


/**
 * Implement hook_form
 * Form change hour
 */
function app_change_hour_form($form, &$form_state){
  $table = $form_state['table'];

  $form['hour'] = array(
    '#type' => 'textfield',
    '#title' =>t('Nhập lại giờ'),
    '#attributes' =>array('placeholder'=>t(date('H:i',time()))),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' =>'Lưu'
  );
  return $form;
}

/**
 * Implement hook_form_submit
 * Form change hour
 */
function app_change_hour_form_submit($form, &$form_state){
  $table = $form_state['table'];
  $newhour = $form_state['values']['hour'];
  $newdate = date('Y-m-d',time()).' '.$newhour.':00';
  $newchange = strtotime($newdate);
  $order = app_check_table_ready($table);
  $order->start = $newchange;
  order_save($order);
  // Tell the browser to close the modal.
  $form_state['ajax_commands'][] = ctools_ajax_command_reload();
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
}


/**
 * Implement ctool modal
 * CHange hour
 */
function app_food_add($table, $ajax){
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_add_js('ajax-responder');

    $form_state = array(
      'table' => $table,
      'ajax' => TRUE,
      'title' => t('Nhập thực đơn'),
    );
    // Use ctools to generate ajax instructions for the browser to create
    // a form in a modal popup.
    $output = ctools_modal_form_wrapper('app_food_add_form', $form_state);
    // If the form has been submitted, there may be additional instructions
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
      $output = $form_state['ajax_commands'];
    }
    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('app_food_add_form');
  }
}
/**
 * Implement ctool modal
 * CHange hour
 */
function app_order_bill($table, $ajax){
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_add_js('ajax-responder');

    $form_state = array(
      'table' => $table,
      'ajax' => TRUE,
      'title' => t('Nhập thực đơn'),
    );
    // Use ctools to generate ajax instructions for the browser to create
    // a form in a modal popup.
    $output = ctools_modal_form_wrapper('app_order_bill_form', $form_state);
    // If the form has been submitted, there may be additional instructions
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
      $output = $form_state['ajax_commands'];
    }
    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('app_order_bill_form');
  }
}
/**
 * Print bill for order
 */
function app_print_view($order){
  drupal_add_css(drupal_get_path('module','app').'/css/app.css');
  $table = tables_load($order->table_id);
  $items = app_get_item_list($table, $order);
  if($items){
    foreach($items as $item){
      $item->cook_tables = cook_table_load($item->cook_table);
    }
  }

  $total = app_get_current_total($table);
  $time_use = app_time_in_use($table);
  return theme('app_print_order',array('table'=>$table, 'order'=>$order,'items'=>$items,'time_use'=>$time_use,'total'=>$total));
}


/**
 * Billing for table
 */

function app_order_bill_form($form, &$form_state){
  $table = $form_state['table'];
  $order = app_check_table_ready($table);
  $table->order = $order;
  $form_state['tables'] = $table;

  $form['billing_info'] = array(
    '#markup' =>render(app_get_table_item_order_bill($table, $order)),
  );
  $form['table_type'] = array(
    '#type' => 'select',
    '#title' =>t('Loại bàn'),
    '#options' => array(0=>t('Bàn thường'),1=>t('Bàn 4 bi / 3C / dù')),
    '#default_value'=>0
  );
  $form['number_customer'] = array(
    '#type' => 'select',
    '#title' =>t('Số khách tham gia'),
    '#options' => array(0=>t('Bình thường'),2=>2, 3=>3, 4=>4, 5=>5, 6=>6, 7=>7, 8=>8, 9=>9, 10=>10),
    '#default_value'=>0,
    '#states' => array(
      'visible' => array(
        ':input[name="table_type"]' => array('value' => 1),
      ),
    ),
  );
  $form['customer'] = array(
    '#type' => 'textfield',
    '#title' =>t('Khách hàng'),
    '#default_value'=>t('Khách vãng lai')
  );
  $form['staff'] = array(
    '#type' => 'select',
    '#title' =>t('Nhân viên phục vụ'),
    '#options' => staff_get_staff_list(),
  );
  $form['debt'] = array(
    '#type' => 'select',
    '#title' =>t('Ghi nợ'),
    '#options' => array(0=>'Không',1=>'Có'),
  );

  $form['paid'] = array(
    '#type' => 'textfield',
    '#title' =>t('Trả trước'),
    '#default_value'=>app_get_current_total($table),
    '#states' => array(
      'visible' => array(
        ':input[name="debt"]' => array('value' => 1),
      ),
    ),
  );
  $form['amount'] = array(
    '#type' => 'textfield',
    '#title' =>t('Thanh toán'),
    '#default_value'=>app_get_current_total($table),
    '#attributes'=>array('disabled'=>true)
  );
  $form['time_use'] = array(
    '#type' => 'hidden',
    '#value'=> app_time_in_use($table),
  );
  $form['promotion'] = array(
    '#type' => 'select',
    '#title' =>t('Giảm giá'),
    '#options' => array(0=>'0%',5=>'5%',10=>'10%',15=>'15%',20=>'20%',25=>'25%',30=>'30%', 50=>'50%'),
  );
  $form['note'] = array(
    '#type' => 'textarea',
    '#title' =>t('Ghi chú'),
  );
  $form['end'] = array(
    '#type'=>'hidden',
    '#value' =>time(),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' =>'Thanh toán'
  );
  return $form;
}

/**
 * Implement hook_form_validate
 * save order
 */
function app_order_bill_form_validate($form, &$form_state){
  if(empty($form_state['values']['customer'])){
    form_set_error('customer',t('Vui lòng nhập tên khách hàng'));
  }
  if(!is_numeric($form_state['values']['amount'])){
    form_set_error('customer',t('Tổng tiền phải là số.'));
  }
}

/**
 * Implement hook_form_submit
 */
function app_order_bill_form_submit($form, &$form_state){
  $table = $form_state['tables'];
  $order = order_load($table->order->id);
  //check promotion
  $order->table_type = $form_state['values']['table_type'];
  $order->number_customer = $form_state['values']['number_customer'];
  $order->customer = $form_state['values']['customer'];
  $order->staff_id = !empty($form_state['values']['staff']) ? $form_state['values']['staff'] : null;
  $order->total_amount = $form_state['values']['amount'];
  $total = ($form_state['values']['amount'] - ($form_state['values']['amount'] * $form_state['values']['promotion'] / 100));
  if($form_state['values']['debt']==1){
    $order->exist_amount = $total - $form_state['values']['paid'];
    $order->total_all_amount = $total - $form_state['values']['paid'];
  }else{
    $order->exist = 0;
    $order->total_all_amount = $total;
  }
  $order->promotion = $form_state['values']['promotion'];
  $order->total_all_amount = $total;
  $order->paid = $form_state['values']['paid'];
  $order->debt = $form_state['values']['debt'];
  $order->end = $form_state['values']['end'];
  $order->time_use = $form_state['values']['time_use'];
  $order->note = $form_state['values']['note'];
  $order->status = 1;
  $order->changed = time();
  $order = order_save($order);
  //reload and close modal
  $print = render(theme('app_print_review',array('order_id'=>$table->order->id)));
  $form_state['ajax_commands'][] = ajax_command_replace('#app-order-bill-form', $print);
}
/**
 * Get table, item in header order billing
 */
function app_get_table_item_order_bill($table, $order){
  $items = app_get_item_list($table, $order);
  if($items){
    foreach($items as $item){
      $item->cook_table_items = cook_table_load($item->cook_table);
    }
  }
  $total = app_get_current_total($table);
  $time_use = app_time_in_use($table);
  return theme('app_order_billing',array('table'=>$table,'order'=>$order,'items'=>$items,'total'=>$total,'time_use'=>$time_use));
}

/**
 * Function get full page
 */
function app_frontpage(){
  return app_table_list_block();
}
