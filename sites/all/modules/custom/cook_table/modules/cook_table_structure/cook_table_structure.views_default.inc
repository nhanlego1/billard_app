<?php
/**
 * @file
 * cook_table_structure.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cook_table_structure_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cook_table';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'cook_table';
  $view->human_name = 'Cook Table';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quản lý kho và thực đơn';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links">
<li><a href="/cook-table/add">Nhập thực đơn</a></li>
<li><a href="/stock/add">Nhập kho</a></li>
<li><a href="/app/stock-in">Quản lý nhập kho</a></li>
<li><a href="/app/stock-out">Quản lý xuất kho</a></li>
</ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Cook Table: Cook table ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'cook_table';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'ID';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Cook Table: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'cook_table';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Tên thực đơn';
  /* Field: Cook Table: Price */
  $handler->display->display_options['fields']['price']['id'] = 'price';
  $handler->display->display_options['fields']['price']['table'] = 'cook_table';
  $handler->display->display_options['fields']['price']['field'] = 'price';
  $handler->display->display_options['fields']['price']['label'] = 'Giá bán';
  $handler->display->display_options['fields']['price']['precision'] = '0';
  $handler->display->display_options['fields']['price']['suffix'] = ' đ';
  /* Field: Cook Table: Stock */
  $handler->display->display_options['fields']['stock']['id'] = 'stock';
  $handler->display->display_options['fields']['stock']['table'] = 'cook_table';
  $handler->display->display_options['fields']['stock']['field'] = 'stock';
  $handler->display->display_options['fields']['stock']['label'] = 'Tồn kho';
  $handler->display->display_options['fields']['stock']['precision'] = '0';
  $handler->display->display_options['fields']['stock']['separator'] = '';
  /* Field: Cook Table: Cook table ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'cook_table';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'Operator';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a class="action" href="/cook-table/edit/[id]"> Edit</a> <a id="edit-cancel" href="/cook-table/delete/[id]"> Delete</a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  /* Filter criterion: Cook Table: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'cook_table';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Tên thực đơn';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Cook Table: Price */
  $handler->display->display_options['filters']['price']['id'] = 'price';
  $handler->display->display_options['filters']['price']['table'] = 'cook_table';
  $handler->display->display_options['filters']['price']['field'] = 'price';
  $handler->display->display_options['filters']['price']['exposed'] = TRUE;
  $handler->display->display_options['filters']['price']['expose']['operator_id'] = 'price_op';
  $handler->display->display_options['filters']['price']['expose']['label'] = 'Giá tiền';
  $handler->display->display_options['filters']['price']['expose']['operator'] = 'price_op';
  $handler->display->display_options['filters']['price']['expose']['identifier'] = 'price';
  $handler->display->display_options['filters']['price']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'app/cook-table/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Quản lý kho và thực đơn';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cook_table'] = $view;

  return $export;
}
