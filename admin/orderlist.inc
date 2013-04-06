<?php 
include_once PATH_BLL.'/orderBll.inc';
//include_once PATH_SMS.'/sms.php';

$page_num=Tools::getValue('page_num')?Tools::getValue('page_num'):1;
$where="";
if(Tools::getValue('order_id'))
    $where = " and order_id = ".Tools::getValue('order_id');
if(Tools::getValue('cust_id'))
    $where = $where." and cust_id=".Tools::getValue('cust_id');
if(Tools::getValue('order_mobile'))
    $where = $where." and order_mobile ='".Tools::getValue('order_mobile')."'";
if(Tools::getValue('cust_mobile'))
    $where = $where." and cust_mobile ='".Tools::getValue('cust_mobile')."'";
if(Tools::getValue('order_status'))
    $where = $where." and order_status =".Tools::getValue('order_status');
if(Tools::getValue('book_date_low'))
    $where = $where." and book_date >=".Tools::getValue('book_date_low');
if(Tools::getValue('book_date_high'))
    $where = $where." and book_date >=".Tools::getValue('book_date_high');
if($where!="")
    $where = "where ".substr($where,4);

$order_list = orderBll::getOrders($where,$page_num,Conf::$pageSet['page_size']);
?>
<div class="title"><h2>详单查询</h2></div>
<div class="content">
    <dl class="locate">
        <dd>
            <label>订单编号</label>
            <input id="order_id" class="same" type="text" value="<?php echo Tools::getValue('order_id');?>"/>
        </dd>
        <dd>
            <label>订花人ID</label>
            <input id="cust_id" class="same" type="text" value="<?php echo Tools::getValue('cust_id');?>"/>
        </dd>
        <dd>
            <label>订购人电话</label>
            <input id="order_mobile" class="same" type="text" value="<?php echo Tools::getValue('order_mobile');?>"/>
        </dd>
        <dd>
            <label>收花人电话</label>
            <input id="cust_mobile" class="same" type="text" value="<?php echo Tools::getValue('cust_mobile');?>"/>
        </dd>
        <dd>
            <label>订单状态</label>
            <select id="order_status" name="order_status">
                <option value="" selected="">全部</option>
                <?php
                foreach (Conf::$order_status as $k => $v) {
                    if(Tools::getValue('order_status')!=''&$k==Tools::getValue('order_status'))
                        echo '<option value="',$k,'" selected>',$v,'</option>';
                    else
                        echo '<option value="',$k,'">',$v,'</option>';
                }
                ?>
            </select>
        </dd>
        <dd class="sty290">
            <label>送花时间</label>
            <input id="book_date_low" class="same sty85" type="text" value="<?php echo Tools::getValue('book_date_low');?>"/>
            <span>至</span>
            <input id="book_date_high" class="same sty85" type="text" value="<?php echo Tools::getValue('book_date_high');?>"/>
        </dd>
        <dt>
            <input type="button" value="查 询" class="loginbtn" onclick="orderlistsearch()" />
            <input type="button" value="清 空" class="loginbtn" onclick="orderlistclean()"/>
        </dt>
    </dl>
    <div class="clearer"></div>
    <table class="list">
        <tr>
            <th>订单编号</th>
            <th>商品名称</th>
            <th>商品分类</th>
            <th>金额</th>
            <th>送达日期</th>
            <th>送花人姓名</th>
            <th>收花人姓名</th>
            <th>手机</th>
            <th>状态</th>
            <th>操作</th>
        </tr>
        <?php
            foreach ($order_list as $k => $v) {
                echo "<tr><td>",$v['order_id'],"</td>";
                echo "<td>",$v['prod_name'],"</td>";
                echo "<td>",$v['prod_type'],"</td>";
                echo "<td>￥",$v['prod_sale_price'],"</td>";
                echo "<td>",$v['book_date'],"</td>";
                echo "<td>",$v['order_name'],"</td>";
                echo "<td>",$v['cust_name'],"</td>";
                echo "<td>",$v['cust_mobile'],"</td>";
                echo "<td>",Conf::$order_status[$v['order_status']],"</td>";
                echo "<td>";
                switch ($v['order_status']) {
                    case 10:
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'confirm_rmb\',true)">确认到款</a>';
                        echo '<a href="admin.php?k=order&id=',$v['order_id'],'">修改</a>';
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'cancel\',true)">取消</a>';
                        break;
                    case 20:
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'orders\',true)">确认订单</a>';
                        echo '<a href="admin.php?k=order&id=',$v['order_id'],'">修改</a>';
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'cancel\',true)">取消</a>';
                        break;
                    case 30:
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'print\',true)">打印发货单</a>';
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'cancel\',true)">取消</a>';
                        break;
                    case 40:
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'shipments\',true)">确认发货</a>';
                        break;
                    case 50:
                        echo '<a href="javascript:void(0)" onclick="Popup.popping(\'success\',true)">确认成功</a>';
                        break;
                    case 60:
                        //echo '<a href="javascript:void(0)" onclick="Popup.popping(\'upload\',true)">上传商品图</a>';
                        break;
                    default:
                        break;
                }
                echo "</td></tr>";
            }
        ?>
        <tr>
            <td colspan="10" class="bjnone">
                <div class="pages">
                    <a href="admin.php?k=orderlist">首页</a>
                    <a href="admin.php?k=orderlist&page_num=<?php echo $page_num+1; ?>">下一页</a>
                    <a href="admin.php?k=orderlist&page_num=<?php echo $page_num-1; ?>">上一页</a>
                </div>
            </td>
        </tr>
    </table>
</div>


<!-- 弹出层 确认到款 -->
<div class="popping sty350" id="confirm_rmb" style="display:none;">
    <div class="popping_title">
        <h2>确认到款</h2>
        <div class="closed" onclick="Popup.closed('confirm_rmb')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <p>订单编号：00001</p>
                <p>金额为：￥827</p>
                <p>您确定已经到款？</p>
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('confirm_rmb')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('confirm_rmb')" />
                </div>
            </div>
         </div>
    </div>
</div>
<!-- 弹出层 确认订单 -->
<div class="popping sty350" id="orders" style="display:none;">
    <div class="popping_title">
        <h2>确认订单</h2>
        <div class="closed" onclick="Popup.closed('orders')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <p>订单编号：00001</p>
                <p>确定要生产此订单？</p>
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('orders')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('orders')" />
                </div>
            </div>
         </div>
    </div>
</div>
<!-- 弹出层 确认发货 -->
<div class="popping sty350" id="shipments" style="display:none;">
    <div class="popping_title">
        <h2>确认发货</h2>
        <div class="closed" onclick="Popup.closed('shipments')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <p>订单编号：00001</p>
                <p>金额为：￥827</p>
                <p>您确定要发货？</p>
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('shipments')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('shipments')" />
                </div>
            </div>
         </div>
    </div>
</div>
<!-- 弹出层 确认成功 -->
<div class="popping sty350" id="success" style="display:none;">
    <div class="popping_title">
        <h2>确认成功</h2>
        <div class="closed" onclick="Popup.closed('success')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <p>订单编号：00001</p>
                <p>您确定要此订单已经成功完成？</p>
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('success')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('success')" />
                </div>
            </div>
         </div>
    </div>
</div>

<!-- 弹出层 取消 -->
<div class="popping sty350" id="cancel" style="display:none;">
    <div class="popping_title">
        <h2>取消</h2>
        <div class="closed" onclick="Popup.closed('cancel')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <h3>您确定要取消此订单？如确定取消请填写取消原因。</h3>
                <p>取消原因：</p>
                <p><textarea class="pop_textarea" rows="" cols="" name=""></textarea></p>
                <div class="error">请输入取消原因</div>
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('cancel')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('cancel')" />
                </div>
            </div>
         </div>
    </div>
</div>
<!-- 弹出层 上传图片 -->
<div class="popping sty500" id="upload" style="display:none;">
    <div class="popping_title">
        <h2>上传图片</h2>
        <div class="closed" onclick="Popup.closed('upload')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="con_list"><span class="pop_tit">选择文件：</span><p><input name="" class="" type="file" /></p><div class="error">文件格式错误！</div></div>
         
        <div class="pop_submit">
            <input type="button" value="上 传" class="loginbtn" onclick="Popup.closed('upload')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('upload')" />
        </div>
    </div>
</div>
<!-- 弹出层 打印发货单 -->
<div class="popping sty900" id="print" style="display:none;">
    <div class="popping_title">
        <h2>打印发货单</h2>
        <div class="closed" onclick="Popup.closed('print')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">        
        
        <div class="print">
            <div class="print_logo">
              <img src="images/logo.jpg" />
            </div>
            <div class="print_order"><h2><label>订单号：</label><p>12345678904564</p></h2><h3><label>订购时间：</label><p>2012-08-29 19:20:58</p></h3></div>
            <div class="print_list">
                <table width="100%">
                  <tr>
                    <td class="sty">收花人姓名</td>
                    <td class="sty_l sty1">大牛</td>
                    <td class="sty">收花人电话</td>
                    <td class="sty_l sty1">12345678907</td>
                  </tr>
                  <tr>
                    <td class="sty">收花人姓名</td>
                    <td class="sty_l sty1">大牛</td>
                    <td class="sty">收花人电话</td>
                    <td class="sty_l sty1">12345678907</td>
                  </tr>
                  <tr>
                    <td class="sty">收花人地址</td>
                    <td colspan="3" class="sty_l">北京市朝阳区朝外大街甲6号万通中心D座23层 , 100020</td>
                  </tr>
                  <tr>
                    <td class="sty">花礼名称</td>
                    <td colspan="3" class="sty_l">花礼名称花礼名称花礼名称花礼名称</td>
                  </tr>
                  <tr>
                    <td class="sty">送花日期</td>
                    <td colspan="3" class="sty_l">2012-08-29 08:00AM--19:00AM</td>
                  </tr>
                </table>
          </div>
            <div class="signature">
                <h2>收花人签字：</h2>
            </div>
            <div class="print_order">
                <h2>
                    <span>花范儿</span>
                    <p>花有品人有范儿，传情达意尽在花范儿</p>
                </h2>
                <h3>
                    <span>欢迎关注花范儿官方微博：@花范儿花店（sina）</span>
                    <p>www.huafaner.com</p>
                </h3>
                
            </div>
        </div>
        
        
        <div class="pop_submit_con">
            <input type="button" value="打 印" class="loginbtn" onclick="Popup.closed('print')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('print')" />
        </div>
        
    </div>
</div>