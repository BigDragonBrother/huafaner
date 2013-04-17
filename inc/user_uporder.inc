<?php
include_once PATH_BLL . '/orderBll.inc';
$order_id = Tools::getValue('id');
if ($order_id == '') {
    Tools::redirectLogin('user.php?m=user_order');
} else {
    $order = orderBll::getOrder($order_id);
}
if (count($order)==0) {
    Tools::redirectLogin(Conf::$urlSet['homepage']);
}
if($order['user_id']!=$_COOKIE['user_id'])
{
    Tools::redirectLogin('user.php?m=user_order');
}
$cust_list = userBll::getCustByuserid($_COOKIE['user_id']);
$minicust_list = userBll::getMiniCust($cust_list);
?>
<div class="content" style="margin-top:15px;">
    <h1>确认您的订单信息</h1>
    <div class="detailed_info">
        <form>
            <div class="order line pad_bot">
                <h4>
                    <b>订单号：<?php echo $order['order_id'], "(", Conf::$order_status[$order['order_status']], ")" ?></b>
                    <div class="pay_er">
                        <?php
                        if($order['payment']!='银行转账'&$order['payment']!='货到付款'&$order['order_status']==10)
                        {
                            $pd_frpid=split("，",$order['payment']);
                            $path = "p2_Order=".$order['order_id']."&p3_Amt=".$order['total']."&pd_FrpId=".Conf::$banks[$pd_frpid[1]];
                            ?>
                                <a href="yeepay/req.php?<?php echo $path; ?>" class="sty90"><p>立即支付</p></a>
                            <?php
                        }
                        ?>
                    </div>
                    <div class="col_er">
                        <?php 
                        if($order['order_status']==10)
                        {
                            ?>
                             <a href="javascript:void(0)" onclick="Popup.popping('boolean',true);$('#cancel_orderid').val(<?php echo $order['order_id'];?>)" class="sty90">
                                <p>取消订单</p>
                             </a>     
                            <?php
                        }
                        ?>
                       
                    </div>
                    <i><a href="user.php?m=user_order">返回我的订单&gt;&gt;</a></i>
                </h4>
            </div>
            <div class="order line" <?php echo $order['order_status']==0?"style='display:none'":""; ?>>
                <div class="speed">
                    <div class="no<?php echo $order['order_status'] / 10; ?>"></div>
                    <dl>
                        <dd <?php echo $order['order_status']/10==1?"class='speed_select'":""; ?>>提交订单</dd>
                        <dd <?php echo $order['order_status']/10==2?"class='speed_select'":""; ?>>完成支付</dd>
                        <dd <?php echo $order['order_status']/10==3?"class='speed_select'":""; ?>>订单确认</dd>
                        <dd <?php echo $order['order_status']/10==4?"class='speed_select'":""; ?>>确认发出</dd>
                        <dd <?php echo $order['order_status']/10==5?"class='speed_select'":""; ?>>完成收花</dd>
                    </dl>
                </div>
            </div>
            <!--收花人信息-->
            <div class="order line">
                <h4>收花人信息</h4>
                <div id="order_info_detail" class="detailed">
                    <?php echo $order['cust_name'],',',$order['cust_title'],',',$order['cust_province'], 
                    ',', $order['cust_city'], ',',$order['cust_town'], ',', $order['cust_address'], 
                    ',',$order['cust_mobile'];?>
                </div>
            </div>

            <!--送花信息-->
            <div class="order line">
                <h4>送花信息</h4>
                <div class="detailed" id="book_info_detail">
                    <ul>
                        <li><label>送花日期：</label><p id="book_date"><?php echo $order['book_date']; ?></p></li>
                        <li><label>卡片：</label><p id="book_card"><?php echo $order['book_card']; ?></p></li>
                        <li><label>卡片内容：</label><p id="book_card_content"><?php echo $order['book_card_content']; ?></p></li>
                    </ul>
                </div>
            </div>

            <!--支付方式-->
            <div class="order line">
                <h4>支付方式</h4>
                <div id="payment_detail" class="detailed"><?php echo $order['payment']; ?></div>
            </div>

            <div class="order line">
                <h4>花礼信息</h4>
                <div class="info_content ">
                    <dl class="input_list">
                        <table class="list_info">
                            <tr>
                                <th class="line">花礼名称</th>
                                <th class="line">现价</th>
                                <th class="line">数量</th>
                                <th class="line">小计</th>
                            </tr>
                            <tr>
                                <td class="text_left"><?php echo $order['prod_name']; ?></td>
                                <td>￥<?php echo number_format($order['prod_sale_price'], 1); ?></td>
                                <td id="prod_cnt" value="<?php echo $order['order_quantity']; ?>"><?php echo $order['order_quantity']; ?></td>
                                <td id="bargin_price" value="<?php echo $order['prod_sale_price'] * $cnt; ?>">
                                    ￥<?php echo number_format($order['prod_sale_price'] * $order['order_quantity'], 1); ?>
                                </td>
                            </tr>
                        </table>
                    </dl>
                </div>
                <div class="submit">
                    <ol class="submit_l">
                    </ol>
                    <ol class="submit_r">
                        <li><label>优惠：</label>
                            <p id="coupon_amount" value="<?php echo $order['coupon_amount']; ?>">￥- <?php echo number_format($order['coupon_amount'], 1); ?></p>
                        </li>
                        <li><label>运费：</label><p id="shipping_fee" value="<?php echo $order['shipping_fee']; ?>">￥<?php echo number_format($order['shipping_fee'], 1); ?></p></li>
                        <li><label>您共需支付：</label>
                            <p class="red" id="total_price">￥<?php echo number_format($order['total'], 1); ?></li>
                    </ol>
                </div>
            </div>
            <div id="prod_id" value="<?php echo $prod_id; ?>" style="display:none"></div>
            <div id="order_quantity" value="<?php echo $cnt; ?>" style="display:none"></div>
            
        </form>
    </div>
</div>

<div class="clearer"></div>
<!-- 弹出层 -->
<div class="popping order_an sty450" id="boolean" style="display:none;">
    <h2><b>取消订单</b><a href="javascript:void(0)" onclick="Popup.closed('boolean')" class="close"></a></h2>
   <div class="order_con">
        <h3>您确定要取消此订单吗？</h3>
        <input type="hidden" id="cancel_orderid" value="" />
        <div class="verification"><a href="javascript:void(0)" onclick="order_cancel($('#cancel_orderid').val())" class="sty90"><p>确 定</p></a></div>
        <div class="again"><a href="javascript:void(0)" onclick="Popup.closed('boolean')" class="sty90"><p>取 消</p></a></div>
    </div>
</div>
