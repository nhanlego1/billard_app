<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/13/16
 * Time: 3:26 PM
 * To change this template use File | Settings | File Templates.
 */
?>
<script type="text/javascript">

</script>
<div id="print-wrapper">
  <div class="header-print">
    <i>Ngày <?php print date('d', time()); ?> tháng <?php print date('m', time()); ?>
      năm <?php print date('Y', time()); ?> - <?php print date('H:i:s') ?></i>
  </div>
  <div class="header-info-print">
    <p style="font-size: 32px"><strong><?php print variable_get('name') ?></strong></p>

    <p><?php print variable_get('site_address'); ?></p>

    <p><?php print variable_get('site_email'); ?></p>

    <p><?php print variable_get('site_phone'); ?></p>
  </div>
  <div class="bill-info-print">
    <h4><strong><?php print t('Hóa đơn') ?></strong></h4>

    <h2><strong><?php print $order->id; ?></strong></h2>

  </div>
  <div class="items-info">
    <h3><strong><?php print $table->name; ?></strong></h3>

    <p>Khách hàng: <strong><?php print $order->customer; ?></strong></p>

    <p>Thời gian bắt đầu: <?php print date('H:i', $order->start) ?></p>

    <p>Thời gian kết thúc: <?php print date('H:i', $order->end) ?></p>

    <p>Thời gian sử dụng: <?php print $order->time_use; ?></p>
  </div>
  <table>
    <tr>
      <td><?php print t('Tiền giờ'); ?></td>
      <td>x</td>
      <td><?php print $order->time_use; ?></td>
      <td><?php print number_format($table->price) ?>đ</td>
      <td><?php print number_format(app_get_current_total_per_time($order->time_use, $table->price)) ?>đ</td>
    </tr>
    <?php if ($items): ?>
      <?php foreach ($items as $item): ?>
        <tr>
          <td><?php print $item->cook_tables->name; ?></td>
          <td>x</td>
          <td><?php print $item->quantity; ?></td>
          <td><?php print number_format($item->cook_tables->price) ?>đ</td>
          <td><?php print number_format($item->total_amount) ?>đ</td>
        </tr>
      <?php endforeach; ?>
    <?php endif; ?>
  </table>
  <div class="total-print">
    <div class="item-amount">
      <label> Tổng cộng:</label>
      <span><?php print number_format($order->total_amount) ?> đ</span>
    </div>
    <div class="item-amount">
      <label> Giảm giá:</label>
      <span><?php print $order->promotion ?> %</span>
    </div>
    <div class="item-amount">
      <label> Tổng thanh toán:</label>
      <span><?php print number_format($order->total_all_amount) ?> đ</span>
    </div>
    <?php if ($order->debt == 1): ?>
      <div class="item-amount">
        <label> Trả trước:</label>
        <span><?php print number_format($order->paid) ?> đ</span>
      </div>
      <div class="item-amount">
        <label> Nợ:</label>
        <span><?php print number_format($order->exist_amount) ?> đ</span>
      </div>
    <?php endif; ?>
    <?php if($order->table_type > 0 && $order->number_customer > 0): ?>
        <div class="line-item-header">&nbsp;</div>
      <div class="item-amount">
        <label> Loại bàn:</label>
        <span><?php print t('Bàn 4 bi / 3C / dù'); ?></span>
      </div>
      <div class="item-amount">
        <label> Số khách tham gia:</label>
        <span><?php print $order->number_customer; ?></span>
      </div>
      <div class="item-amount">
        <label> Số tiền cho mỗi khách:</label>
        <span><?php print number_format($order->total_all_amount / $order->number_customer); ?> đ</span>
      </div>
    <?php endif; ?>
  </div>

  <div class="footer-info">
    <p><i>Cám ơn quý khách đã ủng hộ <?php print variable_get('name', 'Câu lạc bộ Bida Phi Hùng') ?></i></p>

    <p><i>Chúc quý khác có buổi giải trí vui vẻ và thoải mái </i></p>

    <p><i>Hẹn gặp lại quý khách </i></p>
  </div>

</div>
<div class="print-button"><a onClick="window.print();" class="action" href="#">In hóa đơn</a></div>