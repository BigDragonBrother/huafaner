<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/orderBll.inc';

$order_id = Tools::getValue('id');
if ($order_id == '') {
    Tools::redirectLink(Conf::$urlSet['homepage']);
} else {
    $order = orderBll::getOrder($order_id);
}
if (count($order) == 0) {
    Tools::redirectLink(Conf::$urlSet['homepage']);
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=gbk" />
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
    </head>
    <body>
        <?php
        if ($order['payment'] == '网银支付，支付宝') {
            ?>
            <form id="pay" name="pay" action="alipay/alipayto.php" method="post">
                <input type="hidden" id="order_id" value="<?php echo $order['order_id']; ?>"></input>
                <input type="hidden" id="subject" value="<?php echo $order['prod_name']; ?>"></input>
                <input type="hidden" id="total_fee" value="<?php echo $order['total']; ?>"></input>
            </form>
        <?php
    }
    if ($order['payment'] == '银行转账') {
        
    }
    ?>
</body>
<script>
    $(document).ready(function() { 
        document.pay.submit();
});
</script>

