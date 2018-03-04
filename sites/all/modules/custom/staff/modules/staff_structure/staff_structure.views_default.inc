<?php
/**
 * @file
 * staff_structure.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function staff_structure_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'staff';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'staff';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quản lý nhân viên';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links"><li><a href="/staff/add">Thêm nhân viên</a></li></ul>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Staff: Staff ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'staff';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'Mã NV';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Staff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'staff';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Tên NV';
  /* Field: Staff: Card_id */
  $handler->display->display_options['fields']['card_id']['id'] = 'card_id';
  $handler->display->display_options['fields']['card_id']['table'] = 'staff';
  $handler->display->display_options['fields']['card_id']['field'] = 'card_id';
  $handler->display->display_options['fields']['card_id']['label'] = 'CMND';
  $handler->display->display_options['fields']['card_id']['precision'] = '0';
  /* Field: Staff: Birthday */
  $handler->display->display_options['fields']['birthday']['id'] = 'birthday';
  $handler->display->display_options['fields']['birthday']['table'] = 'staff';
  $handler->display->display_options['fields']['birthday']['field'] = 'birthday';
  $handler->display->display_options['fields']['birthday']['label'] = 'Ngày sinh';
  /* Field: Staff: Phone */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'staff';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  $handler->display->display_options['fields']['phone']['label'] = 'Điện thoại';
  /* Field: Staff: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'staff';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['label'] = 'Địa chỉ';
  /* Field: Staff: Startdate */
  $handler->display->display_options['fields']['startdate']['id'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['table'] = 'staff';
  $handler->display->display_options['fields']['startdate']['field'] = 'startdate';
  $handler->display->display_options['fields']['startdate']['label'] = 'Ngày vào làm';
  /* Field: Staff: Staff ID */
  $handler->display->display_options['fields']['id_1']['id'] = 'id_1';
  $handler->display->display_options['fields']['id_1']['table'] = 'staff';
  $handler->display->display_options['fields']['id_1']['field'] = 'id';
  $handler->display->display_options['fields']['id_1']['label'] = 'Operations';
  $handler->display->display_options['fields']['id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['id_1']['alter']['text'] = '<a href="/staff/edit/[id]">Cập nhật</a> | <a href="/staff/delete/[id]">Xóa</a>';
  $handler->display->display_options['fields']['id_1']['separator'] = '';
  /* Filter criterion: Staff: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'staff';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Tên NV';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Staff: Phone */
  $handler->display->display_options['filters']['phone']['id'] = 'phone';
  $handler->display->display_options['filters']['phone']['table'] = 'staff';
  $handler->display->display_options['filters']['phone']['field'] = 'phone';
  $handler->display->display_options['filters']['phone']['operator'] = 'contains';
  $handler->display->display_options['filters']['phone']['exposed'] = TRUE;
  $handler->display->display_options['filters']['phone']['expose']['operator_id'] = 'phone_op';
  $handler->display->display_options['filters']['phone']['expose']['label'] = 'Điện thoại';
  $handler->display->display_options['filters']['phone']['expose']['operator'] = 'phone_op';
  $handler->display->display_options['filters']['phone']['expose']['identifier'] = 'phone';
  $handler->display->display_options['filters']['phone']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'app/staff/manager';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Quản lý nhân viên';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['staff'] = $view;

  return $export;
}
