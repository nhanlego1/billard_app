<?php
class OrderViewsController extends EntityDefaultViewsController {
  function views_data() {
    $data = parent::views_data();
    if ($this->info['base table'] == 'order') {
      $data['order']['created'] = array(
        'title' => t('Created'),
        'help' => 'Order Created date',
        'field' => array(
          'handler' => 'order_handler_field_created',
          'click sortable' => TRUE,
        ),
      );
      $data['order']['created'] = array(
        'title' => t('Changed'),
        'help' => 'Order Changed date',
        'field' => array(
          'handler' => 'order_handler_field_changed',
          'click sortable' => TRUE,
        ),
      );
    }
    return $data;
  }
}