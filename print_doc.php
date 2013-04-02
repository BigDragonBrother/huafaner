<?php
include_once 'conf.inc';
include_once PATH_LIB.'/tools.inc';
include_once PATH_BLL.'/orderBll.inc';

$order_id=Tools::getValue('id');
$order=orderBll::getOrder($order_id);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title></title>
<link href="style/global.css" rel="stylesheet" type="text/css" />
<link href="style/print.css" rel="stylesheet" type="text/css" />
<script language="javascript" src="script/jquery-1.7.1.min.js"></script>
</head>

<body>
<!--startprint-->
<div class="print">
	<div class="print_logo">
	  <img src="images/logo.gif" />
    </div>
    <div class="print_order">
      <h2><label>订单号：</label><p><?php echo $order['order_id']; ?></p></h2>
      <h3><label>订购时间：</label><p><?php echo $order['cdate']; ?></p></h3>
    </div>
    <div class="print_list">
    	<table width="100%">
          <tr>
            <td class="sty">收花人姓名</td>
            <td class="sty_l sty1"><?php echo $order['cust_name']; ?></td>
            <td class="sty">收花人电话</td>
            <td class="sty_l sty1"><?php echo $order['cust_mobile']; ?></td>
          </tr>
          <tr>
            <td class="sty">收花人地址</td>
            <td colspan="3" class="sty_l"><?php echo $order['cust_province'],',',$order['cust_city'],',',$order['cust_town'],',',$order['cust_address'],',',$order['cust_zip']; ?></td>
          </tr>
          <tr>
            <td class="sty">花礼名称</td>
            <td colspan="3" class="sty_l"><?php echo $order['prod_name']; ?></td>
          </tr>
          <tr>
            <td class="sty">送达时间</td>
            <td colspan="3" class="sty_l"><?php echo $order['book_date'],' ',$order['book_time']; ?></td>
          </tr>
        </table>
    </div>
    <div class="signature"><label>收花人签字：</label></div>
    <!--<div class="print_order">
    <h2><label>订购电话：</label><p>010-64361192</p></h2>
    <h2>www.huafaner.com</h2>
    <h3><label>官方微博：</label><p>@花范儿花店(sina微博)</p></h3>
    </div>-->
    <div class="print_list">花有品人有范儿 传情达意尽在花范儿</div>
    <div class="print_list">www.huafaner.com</div>
    <!--endprint-->
</div>

</body>
</html>
