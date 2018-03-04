<?php
/**
 * Created by JetBrains PhpStorm.
 * User: admin
 * Date: 6/11/16
 * Time: 8:47 PM
 * To change this template use File | Settings | File Templates.
 */
?>
<div class="billing=wrapper">
  <h2>Thanh toán hóa đơn</h2>

  <div style="border-bottom: 1px solid #c3c3c3" class="header-billing-info">
    <h3><?php print $table->name ?></h3>
    <p><i>Ngày <?php print date('d/m/Y',$order->start) ?></i></p>
    <p><i>Thời gian bắt đầu: </i><?php print date('H:i', $order->start); ?></p>
    <p><i>Thời gian kết thúc: </i><?php print date('H:i', time()) ?></p>
    <p><i>Thời gian sử dụng: </i><?php print app_time_in_use($table) ?></p>
  </div>
  <div class="items-list-billing">
    <?php if ($items): ?>
      <h3>Thực đơn</h3>
      <table>
        <tr>
          <th>ID</th>
          <th>Thực đơn</th>
          <th>đơn giá</th>
          <th>Số lượng</th>
          <th>Tổng cộng</th>
        </tr>
        <tbody>
        <?php foreach ($items as $item): ?>
            <tr>
              <td><?php print $item->id ?></td>
              <td><?php print $item->cook_table_items->name; ?></td>
              <td><?php print number_format($item->cook_table_items->price); ?> đ</td>
              <td><?php print $item->quantity; ?></td>
              <td><?php print number_format($item->total_amount); ?> đ</td>
            </tr>
        <?php endforeach; ?>
        </tbody>
      </table>
    <?php endif; ?>
  </div>
  <div class="total-amount" style="border-bottom: 1px solid #c3c3c3; margin-top: 20px">
    <h5>Tiền /h: <?php print number_format($table->price) ?> đ</h5>
    <h3>Tổng cộng: <?php print number_format(app_get_current_total($table)) ?> đ</h3>
  </div>
</div>