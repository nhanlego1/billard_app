<?php

class order_handler_field_changed extends views_handler_field {
  function render($values) {
    $output = '';
    if (isset($values->changed)) {
       $output = date('d/m/Y H:i:s',$values->changed);
        }
    return $output;
  }
}