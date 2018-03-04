<?php
/**
 * @file
 * app_structure.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function app_structure_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_cp-nht-thng-tin-clb:admin/app/setting.
  $menu_links['main-menu_cp-nht-thng-tin-clb:admin/app/setting'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/app/setting',
    'router_path' => 'admin/app/setting',
    'link_title' => 'Cập nhật thông tin CLB',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_cp-nht-thng-tin-clb:admin/app/setting',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_dashboard:<front>.
  $menu_links['main-menu_dashboard:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_dashboard:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-bn:admin/tables/manager.
  $menu_links['main-menu_qun-l-bn:admin/tables/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/tables/manager',
    'router_path' => 'admin/tables/manager',
    'link_title' => 'Quản lý Bàn',
    'options' => array(
      'identifier' => 'main-menu_qun-l-bn:admin/tables/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-cng-n:app/order/debt.
  $menu_links['main-menu_qun-l-cng-n:app/order/debt'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/order/debt',
    'router_path' => 'app/order/debt',
    'link_title' => 'Quản lý công nợ',
    'options' => array(
      'identifier' => 'main-menu_qun-l-cng-n:app/order/debt',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-n-hng:app/order.
  $menu_links['main-menu_qun-l-n-hng:app/order'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/order',
    'router_path' => 'app/order',
    'link_title' => 'Quản lý đơn hàng',
    'options' => array(
      'identifier' => 'main-menu_qun-l-n-hng:app/order',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-nhn-vin:admin/staff/manager.
  $menu_links['main-menu_qun-l-nhn-vin:admin/staff/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/staff/manager',
    'router_path' => 'admin/staff/manager',
    'link_title' => 'Quản lý nhân viên',
    'options' => array(
      'identifier' => 'main-menu_qun-l-nhn-vin:admin/staff/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-thc-n:admin/cook-table/manager.
  $menu_links['main-menu_qun-l-thc-n:admin/cook-table/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/cook-table/manager',
    'router_path' => 'admin/cook-table/manager',
    'link_title' => 'Quản lý Thực đơn',
    'options' => array(
      'identifier' => 'main-menu_qun-l-thc-n:admin/cook-table/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cập nhật thông tin CLB');
  t('Dashboard');
  t('Quản lý Bàn');
  t('Quản lý Thực đơn');
  t('Quản lý công nợ');
  t('Quản lý nhân viên');
  t('Quản lý đơn hàng');

  return $menu_links;
}
