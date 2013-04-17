<?php 
include_once PATH_BLL.'/orderBll.inc';

$order=orderBll::getOrder(Tools::getValue('id'));
if($order['only_order_id']>0)
    $only_order=orderBll::getOnlyOrder($order['only_order_id']);
?>
<div class="title"><h2>修改订单</h2></div>
<div class="content bot_b">
    <div class="con_list pad_n">
        <span class="con_tit">订单编号：</span>
        <p><?php echo $order['order_id']; ?></p>
        <input type="hidden" value="<?php echo $order['order_id']; ?>" id="order_id"/>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">订单状态：</span>
        <p><?php echo Conf::$order_status[$order['order_status']]; ?></p>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">订单来源：</span>
        <p>网站/APP</p>
    </div>
    <div class="speed">
        <div class="no5"></div>
        <dl>
            <dd class="speed_select">提交订单<p><?php echo $order['cdate']; ?></p></dd>
            <dd class="speed_select">完成支付<p><?php echo $order['pay_date']; ?></p></dd>
            <dd class="speed_select">订单确认<p><?php echo $order['confirm_date']; ?></p></dd>
            <dd class="speed_select">订单发货<p><?php echo $order['send_date']; ?></p></dd>
            <dd>订单完成/取消<p><?php echo $order['cancel_date'],$order['finish_date']; ?></p></dd>
        </dl>
      </div>
</div>
<div class="content bot_b">
    <div class="con_list">
        <span class="con_tit">收花人姓名：</span>
        <p><input id="cust_name" value="<?php echo $order['cust_name']; ?>" class="same" type="text" /></p>
        <div class="error">收花人姓名不能为空！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">收花人地址：</span>
        <p>
            <select id="cust_province">
                <option value="北京">北京</option>
            </select>
        </p>
        <p>
            <select id="cust_city">
                <option value="北京">北京</option>
            </select>
        </p>
        <p>
            <select id="cust_town">
                <option value="">请选择地区</option>
                <option value="东城" <?php echo $order['cust_town']=="东城"?"selected":""; ?>>东城</option>
                <option value="西城" <?php echo $order['cust_town']=="西城"?"selected":""; ?>>西城</option>
                <option value="朝阳" <?php echo $order['cust_town']=="朝阳"?"selected":""; ?>>朝阳</option>
                <option value="丰台" <?php echo $order['cust_town']=="丰台"?"selected":""; ?>>丰台</option>
                <option value="石景山" <?php echo $order['cust_town']=="石景山"?"selected":""; ?>>石景山</option>
                <option value="海淀" <?php echo $order['cust_town']=="海淀"?"selected":""; ?>>海淀</option>
                <option value="门头沟" <?php echo $order['cust_town']=="门头沟"?"selected":""; ?>>门头沟</option>
                <option value="房山" <?php echo $order['cust_town']=="房山"?"selected":""; ?>>房山</option>
                <option value="通州" <?php echo $order['cust_town']=="通州"?"selected":""; ?>>通州</option>
                <option value="顺义" <?php echo $order['cust_town']=="顺义"?"selected":""; ?>>顺义</option>
                <option value="昌平" <?php echo $order['cust_town']=="昌平"?"selected":""; ?>>昌平</option>
                <option value="大兴" <?php echo $order['cust_town']=="大兴"?"selected":""; ?>>大兴</option>
                <option value="怀柔" <?php echo $order['cust_town']=="怀柔"?"selected":""; ?>>怀柔</option>
                <option value="平谷" <?php echo $order['cust_town']=="平谷"?"selected":""; ?>>平谷</option>
                <option value="密云" <?php echo $order['cust_town']=="密云"?"selected":""; ?>>密云</option>
                <option value="延庆" <?php echo $order['cust_town']=="延庆"?"selected":""; ?>>延庆</option>
                <option value="开发区" <?php echo $order['cust_town']=="开发区"?"selected":""; ?>>开发区</option>
            </select>
        </p>
        <p>
            <input id="cust_address" value="<?php echo $order['cust_address']; ?>" class="same" type="text" />
        </p>
        <div class="error">收花人地址不能为空！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">收花人电话：</span>
        <p><input id="cust_mobile" class="same" type="text" value="<?php echo $order['cust_mobile']; ?>"/></p>
        <div class="error">收花人电话不能为空！</div>
    </div>
</div>
<div class="content bot_b">
    <div class="con_list pad_n">
        <span class="con_tit">订花人姓名：</span>
        <p><?php echo $order['order_name']; ?></p>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">会员账号：</span>
        <p><?php echo $order['user_name']; ?></p>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">手机号：</span>
        <p><?php echo $order['order_mobile']; ?></p>
    </div>
</div>
<div class="content bot_b">
    <div class="con_list pad_n">
        <span class="con_tit">商品名称：</span>
        <p><?php echo $order['prod_name']; ?></p>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">商品分类：</span>
        <p><?php echo $order['dict_name']; ?></p>
    </div>
    <div class="pad_l120">
        <img src="<?php echo $order['pic_path']; ?>">
    </div>
</div>
<div class="content bot_b">
    <div class="con_list">
        <span class="con_tit">送花日期：</span>
        <p><input id="book_date" class="same sty85" type="text" value="<?php echo $order['book_date'];?>"/></p>
        <div class="error">送花日期不能为空！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">卡片类型：</span>
        <p>
            <select id="book_card">
                <option value="不需要卡片" <?php echo $order['book_card']=="不需要卡片"?"selected":"";?>>不需要卡片</option>
                <option value="我要一张空白卡片" <?php echo $order['book_card']=="我要一张空白卡片"?"selected":""; ?>>我要一张空白卡片</option>
                <option value="我要一张代写卡片" <?php echo $order['book_card']=="我要一张代写卡片"?"selected":""; ?>>我要一张代写卡片</option>
            </select>
        </p>
    </div>
    <div class="con_list">
        <span class="con_tit">卡片内容：</span>
        <p><textarea id="book_card_content" name="" cols="" rows="" class="textarea"><?php echo $order['book_card_content']; ?></textarea></p>
        <div class="error">卡片内容不能为空！</div>
    </div>
    <!--<div class="con_list">
        <span class="con_tit">落款：</span>
        <p><input id="order_sign" class="same" type="text" value="<?php echo $order['order_sign'];?>" /></p>
        <label for="a2">
            <input name="" class="inputcheckbox" id="a2" type="checkbox" value="" />匿名送花
        </label>
    </div>-->
    <div class="con_list">
        <span class="con_tit">订单备注：</span>
        <p><textarea id="remarks" cols="" rows="" class="textarea"><?php echo $order['remarks'];?></textarea></p>
    </div>
</div>
<div class="content">
    <div class="con_list pad_n">
        <span class="con_tit">商品金额：</span>
        <p>$<?php echo $order['prod_sale_price']; ?></p>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">优惠券ID：</span>
        <p><?php echo $order['coupon_id']; ?></p>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">优惠券金额：</span>
        <p><?php echo $order['coupon_amount'];?></p>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">订单金额：</span>
        <p><?php echo $order['total'];?></p>
    </div>
    <div class="con_list">
        <span class="con_tit">实付金额：</span>
        <p><input id="total_pay" class="same" type="text" value="<?php echo $order['total_pay'];?>"/></p>
        <div class="error">金额不能为空/金额格式不正确！</div>
    </div>
    <div class="con_list pad_n">
        <span class="con_tit">付款方式：</span>
        <p><?php echo $order['payment'];?></p>
    </div>
</div>
<div class="btn_submit">
    <input type="button" value="保 存" class="loginbtn" onclick="order_update()"/>
    <input type="button" value="返 回" class="loginbtn" onclick="javascript:history.go(-1);"/>
</div>