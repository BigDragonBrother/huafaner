<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/userBll.inc';
include_once PATH_BLL . '/prodBll.inc';
include_once PATH_BLL . '/orderBll.inc';

if (!isset($_COOKIE['user_id'])) {
    echo Tools::redirectLink(Conf::$urlSet['homepage']);
}

$user=  userBll::getUserByid($_COOKIE['user_id']);

$cust_list = userBll::getCustByuserid($_COOKIE['user_id']);
$minicust_list = userBll::getMiniCust($cust_list);

$prod_id = Tools::getValue('id');
if ($prod_id == '') {
    Tools::redirectLink(Conf::$urlSet['homepage']);
} else {
    $prod = prodBll::getProdByid($prod_id);
    if(empty($prod))
    {
        Tools::redirectLink(Conf::$urlSet['homepage']);
    }
}
$prod_pic=prodBll::getProdPic($prod_id,Conf::$prod_pic_seq['列表页']);

$only_order_id = Tools::getValue('only_order_id');

$cnt = Tools::getValue('cnt');
if ($cnt == '') {
    $cnt = 1;
}

$coupons = userBll::getValidCouponByuserid($_COOKIE['user_id'], 1);

$last_order=orderBll::getLastOrderByUserid($_COOKIE['user_id']);
$last_order_payment=0;
if($last_order)
{
    if(strpos($last_order['payment'],"网银支付")==0)
    {
        $last_order_payment=1;
    }
    elseif(strpos($last_order['payment'],"货到付款")==0)
    {
        $last_order_payment=2;
    }
    elseif(strpos($last_order['payment'],"银行转账")==0)
    {
        $last_order_payment=3;
    }
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>花范儿</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <link href="style/jquery.ui.datepicker.css" rel="stylesheet" type="text/css"/>
        <link href="style/jquery.ui.theme.css" rel="stylesheet" type="text/css"/>
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="script/layout.js"></script>
        <script language="javascript" src="script/jquery.jqtransform.js"></script>
        <script language="javascript" src="script/jquery.ui.core.min.js"></script>
        <script language="javascript" src="script/jquery.ui.datepicker.js"></script>
        <script language="javascript" src="script/order.js"></script>
        <script type="text/javascript">
            $(function(){
                $('form').jqTransform({imgPath:'images'});
                
                var today = new Date();
                today.setDate(today.getDate()+1);
                var options= {
                    //changeMonth: true, //显示月份下拉框
                    //changeYear: true, //显示年份下拉框
                    dateFormat: 'yy-mm-dd',  //日期格式，自己设置
                    buttonImage: 'image/calendar.gif',  //按钮的图片路径，自己设置
                    buttonImageOnly: true,  //Show an image trigger without any button.
                    showOn: 'both',//触发条件，both表示点击文本域和图片按钮都生效
                    yearRange: '2012:2040',//年份范围
                    clearText:'清除',
                    closeText:'关闭',
                    prevText:'',
                    nextText:'',
                    currentText:"now",
                    monthNames:['1月','2月','3月','4月','5月','6月','7月','8月','9月','10月','11月','12月'],
                    dayNamesMin:['日','一','二','三','四','五','六'],
                    showMonthAfterYear: true,
                    defaultDate: 0, //设置当前日期
                    minDate: new Date(today.getFullYear(), today.getMonth(), today.getDate()+<?php echo $prod['prod_stock_up']; ?>),
                };
                $("#datepicker").datepicker(options);
            });
        </script>
    </head>
    <body>
        <!--网站头部-->
        <?php include_once PATH_INC . '/head.inc'; ?>
        <!-- 订单信息 -->
        <div class="ind_main">
            <h1>确认您的订单</h1>
            <div class="detailed_info">
                <form>
                    <div class="info">
                        <!--收货地址-->
                        <div class="order line_ser">
                            <a name="order_info_btn" href="javascript:void(0)"></a>
                            <input type="hidden" id="order_info"/>
                            <h4>收花人信息</h4>
                            <div class="info_content">
                                <ul>
                                    <?php
                                        $str = "";
                                        foreach ($minicust_list as $k => $v) 
                                        {
                                            if ($v[0] == "1") 
                                            {
                                                $cust = $v;
                                                $str = "<li class=\"seltectradio\" >
                                                <input name=\"custlist\" checked=\"checked\" type=\"radio\" value=\"$k\" class=\"inputcheckbox\" onclick=\"custlist_add(this)\"/>
                                                <label value=\"$k\" for=\"a1\">$v[1]</label></li>" . $str;
                                            } 
                                            else 
                                            {
                                                $str = $str . "<li class=\"seltectradio\">
                                                <input name=\"custlist\" type=\"radio\" value=\"$k\" class=\"inputcheckbox\" onclick=\"custlist_add(this)\"/>
                                                <label value=\"$k\" for=\"a1\">$v[1]</label></li>";
                                            }
                                        }
                                        echo $str;
                                    ?>
                                    <li class="seltectradio">
                                            <input name="custlist" id="custlist" type="radio" <?php echo count($minicust_list)?"":"checked"; ?> value="0" class="inputcheckbox" onclick="custlist_add(this)"/>
                                            <label for="a2">创建新的收花人信息</label>
                                    </li>
                                </ul>
                                <div class="clearer"></div>
                                <dl class="form_list" id="custlist_add" style="<?php echo count($minicust_list)?"display:none":""; ?>" >
                                        <dd>
                                            <label for="b1">称谓*</label>
                                            <select name="cust_title" id="cust_title">
                                                <option value="0">请选择</option>
                                                <option value="小姐">小姐</option>
                                                <option value="女士">女士</option>
                                                <option value="先生">先生</option>
                                            </select>
                                            <div class="form_error" id="cust_title_error" style="display:none">请选择收花人的称谓</div>
                                        </dd>
                                        <dd>
                                            <label for="b1">姓名*</label>
                                            <input name="cust_name" type="text" id="cust_name" class="inputtext sty160" />
                                            <div class="form_error" id="cust_name_error" style="display:none">请填写收花人姓名</div>
                                        </dd>
                                        <dd>
                                            <label for="b3">省市区县*</label>
                                            <select name="cust_province" id="cust_province" class="">
                                                <option value="0">请选择省</option>
                                                <option value="北京">北京</option>
                                            </select>
                                            <select name="cust_city" id="cust_city" class="">
                                                <option value="0">请选择市</option>
                                                <option value="北京">北京</option>
                                            </select>
                                            <select name="cust_town" id="cust_town" class="">
                                                <option value="0">请选择区</option>
                                                <option value="东城">东城</option>
                                                <option value="西城">西城</option>
                                                <option value="朝阳">朝阳</option>
                                                <option value="丰台">丰台</option>
                                                <option value="石景山">石景山</option>
                                                <option value="海淀">海淀</option>
                                                <option value="门头沟">门头沟</option>
                                                <option value="房山">房山</option>
                                                <option value="通州">通州</option>
                                                <option value="顺义">顺义</option>
                                                <option value="昌平">昌平</option>
                                                <option value="大兴">大兴</option>
                                                <option value="怀柔">怀柔</option>
                                                <option value="平谷">平谷</option>
                                                <option value="密云">密云</option>
                                                <option value="延庆">延庆</option>
                                                <option value="开发区">开发区</option>
                                            </select>                                    
                                            <div class="form_error mar_l" id="cust_province_error" style="display:none">请填写收花人的地址信息</div>
                                        </dd>
                                        <dd>
                                            <label for="b2">详细地址*</label>
                                            <input name="cust_address" id="cust_address" type="text" class="inputtext sty360" />
                                            <div class="form_error" id="cust_address_error" style="display:none">请填写收花人的地址信息</div>
                                        </dd>
                                        <dd>
                                            <label for="b3">联系电话*</label>
                                            <input name="cust_tel" id="cust_tel" type="text" id="b3" class="inputtext sty160" />
                                            <div class="form_error" id="cust_tel_error" style="display:none">请填写收花人的联系电话</div>
                                            <div class="form_error" id="cust_tel_error1" style="display:none">请填入正确的联系电话</div>
                                        </dd>
                                    </dl>
                            </div>
                        </div>

                        <!--卡片-->
                        <div class="order line_ser">
                            <a name="card_btn" href="javascript:void(0)"></a>
                            <h4>
                                <p>选择卡片</p>
                                <div class="form_error" id="book_card_error" style="display:none">请输入卡片留言</div>
                            </h4>
                            <div class="info_content porel">
                                <ul>
                                    <li class="seltectradio"><input name="book_card" type="radio" value="不需要卡片" checked <?php echo $last_order&$last_order['book_card']=="不需要卡片"?"checked":""; ?> id="c1" onclick="$('.greeting_n').hide();$('.greeting_replace').hide();"/><label for="c1">不需要卡片</label></li>
                                    <li class="seltectradio"><input name="book_card" type="radio" value="我要一张空白卡片" <?php echo $last_order&$last_order['book_card']=="我要一张空白卡片"?"checked":""; ?> id="c2" class="greet_replace" /><label for="c2">我要一张空白卡片</label></li>
                                    <li class="seltectradio"><input name="book_card" type="radio" value="我要一张代写卡片" <?php echo $last_order&$last_order['book_card']=="我要一张代写卡片"?"checked":""; ?> id="c3" class="greet_n" /><label for="c3">我要一张代写卡片</label></li>
                                </ul>
                                <div class="greeting_n">
                                    <p>输入卡片留言:</p>
                                    <p><textarea id="book_card_content" name="book_card_content" class="inputtext hw70"></textarea></p>
                                </div>
                                <div class="greeting_replace">
                                    <img src="images/greeting.gif" />
                                </div>
                            </div>
                        </div>

                        <!--支付方式-->
                        <div class="order line_ser">
                            <a name="payment_btn" href="javascript:void(0)"></a>
                            <input type="hidden" id="payment_detail" value="<?php echo $last_order['payment']; ?>"/>
                            <h4>
                                <p>支付方式</p>
                                <div class="form_error" id="payment_error" style="display:none">请选择支付方式</div>
                                <div class="form_error" id="payment_error1" style="display:none">请选择您要在线支付的银行名称</div>
                            </h4>
                            <div class="info_content">
                                <ul>
                                    <li class="seltectradio">
                                        <input id="f1" name="pay_type" <?php echo $last_order_payment==1?"checked":""; ?> type="radio" value="0" class="bank_list"/>
                                        <label for="f1">网银支付</label>
                                        <span class="">(您需要有一张开通网上支付功能的银行卡)</span>
                                    </li>
                                </ul>
                                <dl class="input_list bankpays" style="<?php echo $last_order_payment==1?"display:block;":""; ?> ">
                                <div class="bankpays" style="<?php echo $last_order_payment==1?"display:block;":""; ?> ">
                                    <ul class="bank">
                                        <h5>我们支持以下银行的在线支付：</h5>
                                        <li class="bankpay bank_card bank_card_gs <?php echo strpos($last_order['payment'],"工商银行")>0?"bank_cardhover":""; ?>" title="工商银行"></li>
                                        <li class="bankpay bank_card bank_card_js <?php echo strpos($last_order['payment'],"建设银行")>0?"bank_cardhover":""; ?>" title="建设银行"></li>
                                        <li class="bankpay bank_card bank_card_ny <?php echo strpos($last_order['payment'],"农业银行")>0?"bank_cardhover":""; ?>" title="农业银行"></li>
                                        <li class="bankpay bank_card bank_card_yz <?php echo strpos($last_order['payment'],"邮政储蓄")>0?"bank_cardhover":""; ?>" title="邮政储蓄"></li>
                                        <li class="bankpay bank_card bank_card_zg <?php echo strpos($last_order['payment'],"中国银行")>0?"bank_cardhover":""; ?>" title="中国银行"></li>
                                        <li class="bankpay bank_card bank_card_jt <?php echo strpos($last_order['payment'],"交通银行")>0?"bank_cardhover":""; ?>" title="交通银行"></li>
                                        <li class="bankpay bank_card bank_card_zs <?php echo strpos($last_order['payment'],"招商银行")>0?"bank_cardhover":""; ?>" title="招商银行"></li>
                                        <li class="bankpay bank_card bank_card_gd <?php echo strpos($last_order['payment'],"光大银行")>0?"bank_cardhover":""; ?>" title="光大银行"></li>
                                        <li class="bankpay bank_card bank_card_pf <?php echo strpos($last_order['payment'],"浦发银行")>0?"bank_cardhover":""; ?>" title="浦发银行"></li>
                                        <!--<li class="bankpay bank_card bank_card_hx" title="华夏银行"></li>-->
                                        <li class="bankpay bank_card bank_card_gf <?php echo strpos($last_order['payment'],"广发银行")>0?"bank_cardhover":""; ?>" title="广发银行"></li>
                                        <!--<li class="bankpay bank_card bank_card_zx" title="中信银行"></li>-->
                                        <li class="bankpay bank_card bank_card_xy <?php echo strpos($last_order['payment'],"兴业银行")>0?"bank_cardhover":""; ?>" title="兴业银行"></li>
                                        <li class="bankpay bank_card bank_card_sf <?php echo strpos($last_order['payment'],"深发银行")>0?"bank_cardhover":""; ?>" title="深发银行"></li>
                                        <li class="bankpay bank_card bank_card_ms <?php echo strpos($last_order['payment'],"民生银行")>0?"bank_cardhover":""; ?>" title="民生银行"></li>
                                        <li class="bankpay bank_card bank_card_hz <?php echo strpos($last_order['payment'],"杭州银行")>0?"bank_cardhover":""; ?>" title="杭州银行"></li>
                                        <li class="bankpay bank_card bank_card_sh <?php echo strpos($last_order['payment'],"上海银行")>0?"bank_cardhover":""; ?>" title="上海银行"></li>
                                        <li class="bankpay bank_card bank_card_nb <?php echo strpos($last_order['payment'],"宁波银行")>0?"bank_cardhover":""; ?>" title="宁波银行"></li>
                                        <li class="bankpay bank_card bank_card_pa <?php echo strpos($last_order['payment'],"平安银行")>0?"bank_cardhover":""; ?>" title="平安银行"></li>                
                                    </ul>
                                    <ul class="webpay">
                                        <h5>我们支持以下支付平台：</h5>
                                        <li class="bankpay pay pay_card_yb" title="易宝支付"></li>         
                                  </ul>
                                </div>
                                </dl>
                                <ul>
                                    <li class="seltectradio"><input id="f2" name="pay_type" type="radio" <?php echo $last_order_payment==2?"checked":""; ?> value="1" class="nobanks" />
                                        <label for="f2">货到付款</label>
                                        <span class=""> (您需要在收货时向送货员支付订单款项)</span>
                                    </li>
                                </ul>
                                <ul>
                                    <li class="seltectradio"><input id="f3" name="pay_type" type="radio" <?php echo $last_order_payment==3?"checked":""; ?> value="2" class="bankpay_list" />
                                        <label for="f3">银行转账</label>
                                        <span class="">(您需要先去银行转账，我们收到货款后才能将货发出)</span>
                                    </li>
                                </ul>
                                <dl class="input_list bankpay_con">
                                    <div class="bankpay_con">
                                        <ul class="bank">
                                            <h5>您在银行汇款时请在电汇单的用途栏内注明订单号：</h5>
                                            <table class="wireframe">
                                              <tr>
                                                <td class="text_cen">账户姓名</td>
                                                <td class="text_left">高玮玮</td>
                                                <td class="text_left">高玮玮</td>
                                              </tr>
                                              <tr>
                                                <td class="text_cen">账     号</td>
                                                <td class="text_left">6226 0901 0257 3389</td>
                                                <td class="text_left">6216 6101 0000 8810 133</td>
                                              </tr>
                                              <tr>
                                                <td class="text_cen">开 户 行</td>
                                                <td class="text_left">招商银行北京分行大运村支行</td>
                                                <td class="text_left">中国银行北京分行</td>
                                              </tr>
                                            </table>
                                        </ul>
                                    </div>
                                </dl>
                            </div>
                          </div>
                    
                        <!--商品信息-->
                        <div class="order line_ser">
                            <h4>确认商品</h4>
                            <div class="info_content ">
                                <dl class="input_list">
                                    <table class="list_info">
                                        <tr>
                                            <th class="line_ser">商品</th>
                                            <th class="line_ser">产品描述</th>
                                            <th class="line_ser">价格</th>
                                            <th class="line_ser">数量</th>
                                            <th class="line_ser">小计</th>
                                        </tr>
                                        <tr>
                                            <td>
                                                <span>
                                                    <img src="<?php echo isset($prod_pic)?$prod_pic[0]['pic_path']:''; ?>" style="width:128px;height:122px;" />
                                                </span>
                                            </td>
                                            <td><?php echo $prod['prod_name']; ?></td>
                                            <td>￥<?php echo number_format($prod['prod_sale_price'], 1); ?></td>
                                            <td id="prod_cnt" value="<?php echo $cnt; ?>"><?php echo $cnt; ?></td>
                                            <td id="bargin_price" value="<?php echo $prod['prod_sale_price'] * $cnt; ?>">
                                                ￥<?php echo number_format($prod['prod_sale_price'] * $cnt, 1); ?>
                                            </td>
                                        </tr>
                                  </table>
                                </dl>
                            </div>
                            <div class="submit">
                                <ol class="submit_l">
                                    <li>
                                        <a name="datepicker_btn" href="javascript:void(0)"></a>
                                        <label class="wid"><span>送达日期</span></label>
                                        <input name="datepicker" type="text" id="datepicker" class="inputtext sty160" readonly/>
                                        <div class="form_error" style="line-height:30px" id="datepicker_error" style="display:none">请填写送达日期</div>
                                    </li>
                                </ol>
                            </div>
                        </div>
                        
                        <!--礼券和备注-->
                        <div class="order line_ser">
                            <div class="submit">
                                <ol class="submit_l">
                                    <li><label><h4>使用礼券</h4></label>
                                        <select name="coupons" id="coupons" class="sty360">
                                            <option value="0" name="0">请选择礼券</option>
                                            <?php
                                                foreach ($coupons as $k => $v) 
                                                {
                                                    echo "<option value=", $v['coupon_id'], " name=", $v['coupon_amount'], ">", $v['coupon_name'], "</option>";
                                                }
                                            ?>
                                        </select>
                                        <?php
                                            if(count($coupons)==0)
                                            {
                                                echo '<a href="javascript:void(0)" class="btnj_n">使用</a>';
                                            }
                                            else
                                            {
                                                echo '<a href="javascript:void(0)" onclick="coupon_select()" class="btnj_y">使用</a>';
                                            }
                                        ?>
                                    </li>
                                  <li>
                                        <label><h4>备    注</h4></label><input type="text" id="remarks" class="inputtext sty180" value="关于颜色，花材的要求" />
                                  </li>
                                </ol>
                                <ol class="submit_r">
                                    <li><label>优惠：</label><p id="coupon_amount" value="0.0">￥-0.0</p></li>
                                    <li><label>商品小计：</label><p>￥<?php echo number_format($prod['prod_sale_price'] * $cnt, 1); ?></p></li>
                                    <li><label>您共需支付：</label><p class="green ft_18" id="total_price">￥<?php echo number_format($prod['prod_sale_price'] * $cnt, 1); ?></p></li>
                                </ol>
                            </div>
                        </div>
                    </div>
                        <!--提交订单-->
                    <div class="buys mat_b20">
                        <div id="prod_id" value="<?php echo $prod_id; ?>" style="display:none"></div>
                        <div id="order_quantity" value="<?php echo $cnt; ?>" style="display:none"></div>
                        <div id="only_order_id" value="<?php echo $only_order_id; ?>" style="display:none"></div>
                        <div id="user_id" value="<?php echo $_COOKIE['user_id']; ?>"></div>
                        <a href="javascript:void(0)" onclick="orderok()" class="sty113"><p>提交订单</p></a>
                        <div id="order_error" class="error" style="display:none">下单失败，请联系客服</div>
                    </div>        
                </form>
            </div>
        </div>
        <div class="clearer"></div>
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>