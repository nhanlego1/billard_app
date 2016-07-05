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

  // Exported menu link: main-menu_cp-nht-thng-tin-clb:app/setting.
  $menu_links['main-menu_cp-nht-thng-tin-clb:app/setting'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/setting',
    'router_path' => 'app/setting',
    'link_title' => 'Cập nhật thông tin CLB',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_cp-nht-thng-tin-clb:app/setting',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
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
  // Exported menu link: main-menu_qun-l-bn:app/tables/manager.
  $menu_links['main-menu_qun-l-bn:app/tables/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/tables/manager',
    'router_path' => 'app/tables/manager',
    'link_title' => 'Quản lý Bàn',
    'options' => array(
      'identifier' => 'main-menu_qun-l-bn:app/tables/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-chi-ph:app/fee/manager.
  $menu_links['main-menu_qun-l-chi-ph:app/fee/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/fee/manager',
    'router_path' => 'app/fee/manager',
    'link_title' => 'Quản lý chi phí',
    'options' => array(
      'identifier' => 'main-menu_qun-l-chi-ph:app/fee/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
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
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-ha-n:app/order.
  $menu_links['main-menu_qun-l-ha-n:app/order'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/order',
    'router_path' => 'app/order',
    'link_title' => 'Quản lý hóa đơn',
    'options' => array(
      'identifier' => 'main-menu_qun-l-ha-n:app/order',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_qun-l-kho-v-thc-n:app/cook-table/manager.
  $menu_links['main-menu_qun-l-kho-v-thc-n:app/cook-table/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/cook-table/manager',
    'router_path' => 'app/cook-table/manager',
    'link_title' => 'Quản lý kho và thực đơn',
    'options' => array(
      'identifier' => 'main-menu_qun-l-kho-v-thc-n:app/cook-table/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-ngi-dng:account/manager.
  $menu_links['main-menu_qun-l-ngi-dng:account/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'account/manager',
    'router_path' => 'account/manager',
    'link_title' => 'Quản lý người dùng',
    'options' => array(
      'identifier' => 'main-menu_qun-l-ngi-dng:account/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-nhn-vin:app/staff/manager.
  $menu_links['main-menu_qun-l-nhn-vin:app/staff/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'app/staff/manager',
    'router_path' => 'app/staff/manager',
    'link_title' => 'Quản lý nhân viên',
    'options' => array(
      'identifier' => 'main-menu_qun-l-nhn-vin:app/staff/manager',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_qun-l-thu-chi:fee/day/manager.
  $menu_links['main-menu_qun-l-thu-chi:fee/day/manager'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'fee/day/manager',
    'router_path' => 'fee/day/manager',
    'link_title' => 'Quản lý thu chi',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_qun-l-thu-chi:fee/day/manager',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cập nhật thông tin CLB');
  t('Dashboard');
  t('Quản lý Bàn');
  t('Quản lý chi phí');
  t('Quản lý công nợ');
  t('Quản lý hóa đơn');
  t('Quản lý kho và thực đơn');
  t('Quản lý người dùng');
  t('Quản lý nhân viên');
  t('Quản lý thu chi');

  return $menu_links;
}
