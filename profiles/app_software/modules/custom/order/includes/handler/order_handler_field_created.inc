<?php

class order_handler_field_created extends views_handler_field {
  function render($values) {
    $output = '';
    if (isset($values->created)) {
       $output = date('d/m/Y H:i:s',$values->created);
        }
    return $output;
  }
}