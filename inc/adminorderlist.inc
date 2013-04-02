<?php 
include_once PATH_BLL.'/orderBll.inc';
include_once PATH_SMS.'/sms.php';

$order_list=  orderBll::getOrders();
?>
<fieldset id="prod_list" class="fieldset">
    <legend>订单列表</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td>订单编号</td>
            <td>独一无二订单号</td>
            <td>商品编号</td>
            <td>商品名称</td>
            <td>收花人姓名/电话</td>
            <td>订单总额</td>
            <td>送达地区</td>
            <td>送达日期</td>
            <td>订单状态</td>
            <td>操作</td>
        </tr>
        <?php
        foreach($order_list as $k=>$v)
        {
            $op="";
            if($v['order_status']==10)
            {
                $op="<a href='admin.php?k=adminorder&id=".$v['order_id']."'>修改订单</a>|<a href='javascript:void(0)' onclick='order_op(20,".$v['order_id'].")'>确认到款</a>|<a href='javascript:void(0)' onclick='order_op(0,".$v['order_id'].")'>取消订单</a>";
            }
            if($v['order_status']==20)
            {
                $op="<a href='javascript:void(0)' onclick='order_op(30,".$v['order_id'].")'>确认订单</a>|<a href='javascript:void(0)' onclick='order_op(0,".$v['order_id'].")'>取消订单</a>";
            }
            if($v['order_status']==30)
            {
                $op="<a href='print_doc.php?id=".$v['order_id']."' target='blank'>打印发货单</a>|<a href='javascript:void(0)' onclick='order_op(40,".$v['order_id'].")'>确认发货</a>|<a href='javascript:void(0)' onclick='order_op(0,".$v['order_id'].")'>取消订单</a>";
            }
            if($v['order_status']==40)
            {
                $op="<a href='javascript:void(0)' onclick='order_op(50,".$v['order_id'].")'>确认成功</a>|<a href='javascript:void(0)' onclick='order_op(0,".$v['order_id'].")'>取消订单</a>";
            }
            echo "<tr><td><a href='admin.php?k=adminorder&id=".$v['order_id']."'>",$v['order_id'],"</a></td>
            <td>",$v['only_order_id'],"</td>
            <td>",$v['prod_id'],"</td>
            <td>",$v['prod_name'],"</td>
            <td>",$v['cust_name'],"/",$v['cust_mobile'],"</td>
            <td>",$v['total'],"</td>
            <td>",$v['cust_town'],"</td>
            <td>",$v['book_date'],$v['book_time'],"</td>
            <td>",Conf::$order_status[$v['order_status']],"</td>
            <td>",$op,"</td></tr>";
        }
        ?>
        
    </table>
</fieldset>

