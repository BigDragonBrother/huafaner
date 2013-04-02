<?php 
include_once PATH_BLL.'/orderBll.inc';

$order=orderBll::getOrder(Tools::getValue('id'));
if($order['only_order_id']>0)
$only_order=orderBll::getOnlyOrder($order['only_order_id']);
?>

<!--商品基本信息-->
<fieldset class="fieldset">
    <legend>订单详情</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td align="right">订单编号：</td>
            <td>
                <?php echo $order['order_id']; ?>
                <input type="hidden" id="order_id" value="<?php echo $order['order_id']; ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">用户id：</td>
            <td><?php echo $order['user_id']; ?></td>
        </tr>
        <tr>
            <td align="right">收花人姓名,电话：</td>
            <td>
                <input type="textbox" id="cust_name" value="<?php echo $order['cust_name'] ?>" />
                <input type="textbox" id="cust_mobile" value="<?php echo $order['cust_mobile'] ?>" />
        </tr>
        <tr>
            <td align="right">收花人地址：</td>
            <td>
                <input type="textbox" id="cust_province" value="<?php echo $order['cust_province'] ?>" />
                <input type="textbox" id="cust_city" value="<?php echo $order['cust_city'] ?>" />
                <input type="textbox" id="cust_town" value="<?php echo $order['cust_town'] ?>" />
                <input type="textbox" id="cust_address" value="<?php echo $order['cust_address'] ?>" />
                <input type="textbox" id="cust_zip" value="<?php echo $order['cust_zip'] ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">订花人姓名,电话：</td>
            <td>
                <input type="textbox" id="order_name" value="<?php echo $order['order_name'] ?>" />
                <input type="textbox" id="order_mobile" value="<?php echo $order['order_mobile'] ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">送花时间：</td>
            <td>
                <input type="textbox" id="book_date" value="<?php echo $order['book_date'] ?>" />
                <input type="textbox" id="book_time" value="<?php echo $order['book_time'] ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">卡片：</td>
            <td>
                <input type="textbox" id="book_card" value="<?php echo $order['book_card'] ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">支付方式：</td>
            <td>
                <input type="textbox" id="payment" value="<?php echo $order['payment'] ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">应付金额：</td>
            <td>
                <input type="textbox" id="total" value="<?php echo $order['total'] ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">配送方式：</td>
            <td><input type="textbox" id="shipping_type" value="<?php echo $order['shipping_type'] ?>" /></td>
        </tr>
        <tr>
            <td align="right">商品id：</td>
            <td><?php echo $order['prod_id']; ?></td>
        </tr>
        <tr>
            <td align="right">商品名称：</td>
            <td><?php echo $order['prod_name']; ?></td>
        </tr>
        <tr>
            <td align="right">礼券id：</td>
            <td><?php echo $order['coupon_id']; ?></td>
        </tr>
        <tr>
            <td align="right">礼券金额：</td>
            <td><?php echo $order['coupon_amount']; ?></td>
        </tr>
        <tr>
            <td align="right">运费：</td>
            <td>
                <input type="textbox" id="shipping_fee" value="<?php echo $order['shipping_fee'] ?>" />
            </td>
        </tr>
        <tr>
            <td align="right">独一无二订单id：</td>
            <td><?php echo $order['only_order_id']; ?></td>
        </tr>
        <tr>
            <td align="right">独一无二_送给谁：</td>
            <td><?php echo $only_order['only_cust']; ?></td>
        </tr>
        <tr>
            <td align="right">独一无二_风格：</td>
            <td><?php echo $only_order['only_style']; ?></td>
        </tr>
        <tr>
            <td align="right">独一无二_感情：</td>
            <td><?php echo $only_order['only_emotion']; ?></td>
        </tr>
        <tr>
            <td align="right">独一无二_花礼类型：</td>
            <td><?php echo $only_order['prod_name']; ?></td>
        </tr>
        <tr><td></td><td><input type="button" onclick="order_update()" value="修改订单"/></td></tr>
    </table>
</fieldset>
