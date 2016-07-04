<?php
/**
 * @file
 * app_structure.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function app_structure_user_default_roles() {
  $roles = array();

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 3,
  );

  // Exported role: seller.
  $roles['seller'] = array(
    'name' => 'seller',
    'weight' => 4,
  );

  return $roles;
}
