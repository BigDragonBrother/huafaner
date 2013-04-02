<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/orderBll.inc';

if (!isset($_COOKIE['user_id'])) {
    Tools::redirectLink(Conf::$urlSet['homepage']);
}

$order_id = Tools::getValue('id');
if ($order_id == '') {
    Tools::redirectLink(Conf::$urlSet['homepage']);
}

$order = orderBll::getOrder($order_id);
$type=Tools::getValue('type');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>花范儿</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="script/layout.js"></script>
        <script language="javascript" src="script/main.js"></script>
    </head>

    <body>
        <?php include_once PATH_INC . '/head.inc'; ?>
        <div class="ind_main">
            <h1>提交成功</h1>
            <div class="detailed_info"> 
                <?php
                if (empty($order)) {
                    ?>
                    <div class="success line_ser">
                        <h3>此订单号不存在！</h3>
                    </div>
                    <?php
                } 
                elseif($type=="success")
                {
                    echo "<div class = \"success line_ser\"><h3>您的订单".$order_id."已经支付成功，我们将会尽快确认处理订单并按时送达！</h3></div><div class=\"buy_pay mat_b20\"></div>";
                }
                elseif($type=="fail")
                {
                    echo "<div class = \"success line_ser\"><h3>您的订单".$order_id."支付失败，请进入‘我的订单’重新支付或电话联系客服！</h3></div><div class=\"buy_pay mat_b20\"></div>";
                }
                elseif ($order['payment'] == "银行转账") {
                    ?>
                    <div class = "success line_ser">
                        <h3>订单<?php echo $order_id; ?>已经提交成功，您需要支付<b class = "green">￥<?php echo $order['total']; ?>元</b></h3>
                        <p>款项到达花范儿账户后，我们将会为您安排订单生产，请您及时完成付款</p>
                    </div>
                    <div class="buy_pay mat_b20"></div>
                    <?php
                } else {
                    ?>

                    <div class = "success line_ser">
                        <h3>订单<?php echo $order_id; ?>已经提交成功，您需要支付<b class = "green">￥<?php echo $order['total'];
                ?>元</b></h3>
                        <p>如果您在<b class="green">24小时内</b>还没有完成支付，我们将无法保证为您及时完成订单哦！</p>
                    <div class="buy_pay mat_b20">
                        <?php 
                        $pd_frpid=split("，",$order['payment']);
                        $path = "p2_Order=".$order['order_id']."&p3_Amt=".$order['total']."&pd_FrpId=".Conf::$banks[$pd_frpid[1]];
                        ?>
                        <a href="yeepay/req.php?<?php echo $path; ?>" class="sty113">
                            <p>立即支付</p>
                        </a>
                    </div>
                    </div>
                <?php } ?>
                <div class="tip">您可以在<a href="user.php?m=user_order"><span class="green">'我的订单'</span></a>中查看或取消您的订单</div>
            </div>
        </div>
        </div>
        <div class="clearer"></div>
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>

