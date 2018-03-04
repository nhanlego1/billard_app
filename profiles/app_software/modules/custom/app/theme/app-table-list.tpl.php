<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/10/16
 * Time: 5:57 PM
 * To change this template use File | Settings | File Templates.
 */

?>
<script type="text/javascript">
  setInterval(function(){
    jQuery(".loading").show();
    window.location.reload();
  }, 120000);
</script>
<div class="large-12 list-table columns">
  <table class="table-list-wrapper">
    <tr>
      <th>Mã bàn</th>
      <th>Tên bàn</th>
      <th>Trạng thái</th>
      <th>Thời gian bắt đầu</th>
      <th>Thời gian sử dụng</th>
      <th>Tiền /h</th>
      <th>Tồng cộng</th>
      <th>Hoạt động</th>
      <th>Chuyển bàn</th>
      <th>Thực đơn</th>
      <th>Nhập lại giờ</th>
      <th>Hủy</th>
    </tr>
    <tbody>
    <?php if ($tables): ?>
      <?php foreach ($tables as $key => $table): ?>
        <tr class="table-<?php print $table->id; ?> <?php if ($table->order): ?> active <?php endif; ?>"
            data="<?php print $table->id; ?>">
          <td><?php print $table->id; ?></td>
          <td><?php print $table->name; ?></td>
          <td>
            <?php if ($table->order): ?>
              <?php print t('Đang hoạt động'); ?>
            <?php else: ?>
              <?php print t('Không hoạt động'); ?>
            <?php endif; ?>
          </td>
          <td>
            <?php if ($table->order): ?>
              <?php print date('H:i', $table->order->start); ?>
            <?php else: ?>
              <?php print t('00:00'); ?>
            <?php endif; ?>
          </td>
          <td>
            <?php if ($table->order): ?>
              <?php print $table->time_use; ?>
            <?php else: ?>
              <?php print t('00:00'); ?>
            <?php endif; ?>
          </td>
          <td><?php print number_format($table->price); ?> đ</td>
          <td><?php print $table->current_amount; ?> đ</td>
          <td>
            <?php if ($table->order): ?>
              <a id="edit-cancel" data="<?php print $table->id ?>" class="ctools-use-modal"
                 href="/app/order/bill/<?php print $table->id ?>/nojs"><?php print t('Thanh toán') ?></a>
            <?php else: ?>
              <a class="action" data="<?php print $table->id ?>" href="#"><?php print t('Bắt đầu') ?></a>
            <?php endif; ?>
          </td>
          <td>
            <?php if ($table->order): ?>
              <a class="ctools-use-modal" href="/app/table/change/<?php print $table->id ?>/nojs"><img width="30"
                                                                                                       height="auto"
                                                                                                       src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/forward.gif"/></a>
            <?php else: ?>
              <img width="30" height="auto"
                   src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/forward.gif"/>
            <?php endif; ?>
          </td>
          <td>
            <?php if ($table->order): ?>
              <a class="ctools-use-modal" href="/app/food/add/<?php print $table->id ?>/nojs"><img width="30"
                                                                                                   height="auto"
                                                                                                   src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/list-add.gif"/></a>
            <?php else: ?>
              <img width="30" height="auto"
                   src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/list-add.gif"/>
            <?php endif; ?>
          </td>
          <td>
            <?php if ($table->order): ?>
              <a id="edit-cancel" class="ctools-use-modal"
                 href="/app/hour/change/<?php print $table->id ?>/nojs"><?php print t('Nhập lại giờ') ?></a>
            <?php else: ?>
              <?php print t('Nhập lại giờ') ?>
            <?php endif; ?>
          </td>
          <td>
            <?php if ($table->order): ?>
              <a data="<?php print $table->order->id ?>" class="cancel-table">
                <img width="20"
                     height="auto"
                     src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/delete-icon.gif"/>
              </a>
            <?php else: ?>
              <img width="20"
                   height="auto"
                   src="<?php print base_path() . drupal_get_path('module', 'app') ?>/image/delete-icon.gif"/>
            <?php endif; ?>

          </td>
        </tr>
      <?php endforeach; ?>
    <?php endif; ?>
    </tbody>
  </table>
</div>