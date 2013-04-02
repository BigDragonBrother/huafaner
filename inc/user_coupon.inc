<div class="content" style="margin-top:15px;">
	<h1>我的礼券</h1>
	<div class="detailed_info">
    	<table class="main_info">
            <tr>
              <th class="line">礼券编号</th>
              <th class="line">礼券名称</th>
              <th class="line">面值</th>
              <th class="line">有效期至</th>
              <th class="line">使用说明</th>
              <th class="line">状态</th>
          </tr>
          <?php
            $coupon=  userBll::getCouponByuserid($_COOKIE['user_id']);
            if(count($coupon)==0)
            {
              echo "<tr><td colspan='6'>您现在还没有礼券，快去邀请朋友加入吧！</td></tr>";
            }
            else
            {
              foreach ($coupon as $k => $v) {
                echo "<tr><td>",$v['coupon_id'],"</td>",
                    "<td>",$v['coupon_name'],"</td>",
                    "<td>",$v['coupon_amount'],"元</td>",
                    "<td>",substr($v['coupon_valid'],0,10),"</td>",
                    "<td>",$v['coupon_desc'],"</td>",
                    "<td>",Conf::$coupon_status[$v['coupon_status']],"</td></tr>";
                  }
            }
          ?>
       </table>
    </div>
</div>
<div class="clearer"></div>
