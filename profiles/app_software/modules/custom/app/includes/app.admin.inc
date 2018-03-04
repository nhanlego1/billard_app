<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/16/16
 * Time: 3:42 PM
 * To change this template use File | Settings | File Templates.
 */
/**
 * Implement hook_form
 * Add form setting for customer
 */
function app_setting_form($form, &$form_state){
   $form['name'] = array(
     '#type'=>'textfield',
     '#default_value'=> variable_get('name','Tên CLB Bida'),
   );
  $form['site_address'] = array(
    '#type' => 'textfield',
    '#default_value'=> variable_get('site_address','Địa chỉ hoạt động'),
  );
  $form['site_email'] = array(
    '#type' => 'textfield',
    '#default_value'=> variable_get('site_email','Email CLB'),
  );
  $form['site_phone'] = array(
    '#type' => 'textfield',
    '#default_value'=> variable_get('site_phone','Điện thoại CLB'),
  );

   return system_settings_form($form);
}