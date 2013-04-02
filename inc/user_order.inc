<div class="content" style="margin-top:15px;">
    <h1>我的订单</h1>
    <div class="detailed_info">
        <table class="List">
            <tr class="">
                <th class="line">订单号</th>
                <th class="line">收货人</th>
                <th class="line">商品名称</th>
                <th class="line">订单总额</th>
                <th class="line">订单状态</th>
                <th class="line">下单时间</th>
                <th class="line">操作</th>
            </tr>
            <?php
            include_once PATH_BLL . '/orderBll.inc';
            $pagenum = 1;
            if (Tools::getValue('pagenum') != '') {
                $pagenum = Tools::getValue('pagenum');
            }
            $orders = orderBll::getOrdersByUserid($_COOKIE['user_id'], $pagenum, Conf::$pageSet['page_size']);
            if(count($orders)==0)
            {
                echo "<tr><td align='center'>您暂时还没有订单。</td></tr>";
            }
            foreach ($orders as $k => $v) {
                ?>
                <tr class="lr_color">
                    <td><span class="btn_close" onclick="return showTr('child-<?php echo $v['order_id']; ?>')"></span>
                        <p><a href="user.php?m=user_uporder&id=<?php echo $v['order_id'];?>"><?php echo $v['order_id']; ?></a></p>
                    </td>
                    <td><?php echo $v['cust_name']; ?></td>
                    <td><?php echo $v['prod_name']; ?></td>
                    <td>￥<?php echo round($v['total'], 1); ?></td>
                    <td><?php echo Conf::$order_status[$v['order_status']]; ?></td>
                    <td><?php echo $v['cdate']; ?></td>
                    <form id="pay_<?php echo $v['order_id']; ?>" name="pay_<?php echo $v['order_id']; ?>" action="alipay/alipayto.php" method="post">
                        <input type="hidden" id="order_id" value="<?php echo $v['order_id']; ?>"></input>
                        <input type="hidden" id="subject" value="<?php echo $v['prod_name']; ?>"></input>
                        <input type="hidden" id="total_fee" value="<?php echo $v['total']; ?>"></input>
                    </form>
                    <td>
                        <?php
                        if ($v['order_status'] == 10) {
                            if($v['payment']!='银行转账')
                            {
                                $pd_frpid=split("，",$v['payment']);
                                $path = "p2_Order=".$v['order_id']."&p3_Amt=".$v['total']."&pd_FrpId=".Conf::$banks[$pd_frpid[1]];
                                echo "<a href=\"yeepay/req.php?".$path."\" target=\"blank\">支付</a>";
                            }
                            ?>
                            <a href="user.php?m=user_uporder&id=<?php echo $v['order_id'];?>">修改</a>
                            <a href="javascript:void(0)" onclick="Popup.popping('boolean',true);$('#cancel_orderid').val(<?php echo $v['order_id'];?>)">取消</a>
                            <?php
                        } else {
                            echo "-";
                        }
                        ?>
                    </td>
                </tr>
                <tr id="child-<?php echo $v['order_id']; ?>" class="hid" <?php echo $v['order_status']==0?"style='display:none'":""; ?>>
                    <td colspan="7">
                        <?php
                        if ($v['order_status'] == 10) {
                            ?>
                        <h5>款项到达后，预计1-3天到达，请<a href="yeepay/req.php?<?php echo $path; ?>" target="blank">立即支付</a>。</h5>
                        <?php } ?>
                        <div class="speed">
                            <!--<ul>
                                <li class="paleft">&nbsp;</li>
                                <li>0-1小时</li>
                                <li>0-1小时</li>
                                <li>0-1天</li>
                                <li>1天</li>
                            </ul>-->
                            <div class="no<?php echo $v['order_status'] / 10; ?>"></div>
                            <dl>
                                <dd <?php echo $v['order_status']/10==1?"class='speed_select'":""; ?>>提交订单</dd>
                                <dd <?php echo $v['order_status']/10==2?"class='speed_select'":""; ?>>完成支付</dd>
                                <dd <?php echo $v['order_status']/10==3?"class='speed_select'":""; ?>>订单确认</dd>
                                <dd <?php echo $v['order_status']/10==4?"class='speed_select'":""; ?>>确认发出</dd>
                                <dd <?php echo $v['order_status']/10==5?"class='speed_select'":""; ?>>完成收花</dd>
                            </dl>
                        </div>
                    </td>
                </tr>
                <?php
            }
            ?>
        </table>
        <div class="clearer"></div>
        <!-- 分页 -->
        <div class="pages">
            <a href="user.php?m=user_order&pagenum=<?php echo $pagenum - 1 ? $pagenum - 1 : 1; ?>" class="a1">&lt; 上一页</a>
            <?php
            $order_cnt = orderBll::getOrderCntByUserid($_COOKIE['user_id']);
            $page_cnt = round($order_cnt / Conf::$pageSet['page_size']);
            $page_cnt=$page_cnt?$page_cnt:1;
            
            for ($i = 1; $i <= $page_cnt; $i++) {
                if ($i == $pagenum) {
                    echo "<span>$i</span>";
                } else {
                    echo "<a href=\"user.php?m=user_order&pagenum=$i\">$i</a>";
                }
            }
            ?>
            <a class="a1" href="user.php?m=user_order&pagenum=<?php echo $pagenum + 1 > $page_cnt ? $page_cnt : $pagenum + 1; ?>">下一页 &gt;</a>
            <!--
            <a class="a1" href="">上一页 &gt;</a>
            <span>1</span>
            <a href="#">2</a>
            <a href="#">3</a>
            <a href="#">4</a>
            <a href="#">5</a>
            <em>&hellip;</em>
            <a href="#">50</a>
            <a href="#">51</a>
            <a href="#">52</a>
            <a href="#">53</a>
            <a href="#">54</a>
            <a href="#">55</a>
            <a class="a1" href="#">下一页 &gt;</a>
            -->
        </div>
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


