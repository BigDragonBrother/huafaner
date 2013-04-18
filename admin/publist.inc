<?php
include_once PATH_BLL.'/subBll.inc';

$sub_list=subBll::getList('pub');
?>
<div class="title"><h2>维护活动</h2></div>
<div class="content">
    <dl class="locate">
        <dd><label>编号</label><input name="" class="same" type="text" /></dd>
        <dd><label>状态</label>
            <select id="" name="">
                <option value="全部" selected="">全部</option>
                <option value="普通商品">普通商品普通商品</option>
                <option value="定制商品">定制商品</option>
            </select>
        </dd>
        <dd class="sty290"><label>活动日期</label><input name="" class="same sty85" type="text" value="2013-03-01" /><span>至</span><input name="" class="same sty85" type="text" /></dd>
        <dt>
            <input type="button" value="查 询" class="loginbtn" />
            <input type="button" value="清 空" class="loginbtn" />
        </dt>
    </dl>
    <div class="clearer"></div>
    <table class="list">
        <tr>
            <th>编号</th>
            <th>活动名称</th>
            <th>上线日期</th>
            <th>状态</th>
            <th>专题描述</th>
            <th>操作</th>
        </tr>
        <?php
        foreach ($sub_list as $k => $v) {
            if($v['sub_on']==1)
            {
                $op="下线";
                $sub_on="活动中";
            }
            else
            {
                $op="上线";
                $sub_on="已下线";
            }
        ?>
        <tr>
            <td><?php echo $v['sub_id']; ?></td>
            <td><?php echo $v['sub_name']; ?></td>
            <td><?php echo $v['sub_start']; ?></td>
            <td><?php echo $sub_on; ?></td>
            <td><?php echo $v['sub_desc']; ?></td>
            <td>
                <a href="javascript:void(0)" onclick="Popup.popping('downline',true)"><?php echo $op; ?></a>
                <a href="admin.php?k=pub&id=<?php echo $v['sub_id']; ?>">修改</a>
            </td>
        </tr>
        <?php
        }
        ?>
        <tr>
            <td colspan="6" class="bjnone">
                <div class="pages">
                    <a href="#">首页</a><a href="#">下一页</a><a href="#">上一页</a><a href="#">尾页</a>
                </div>
            </td>
        </tr>
</table>
</div>
<!-- 弹出层 下线 -->
<div class="popping sty350" id="downline" style="display:none;">
    <div class="popping_title">
        <h2>下线</h2>
        <div class="closed" onclick="Popup.closed('downline')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
        <div class="pop_infocon">
            <h3>你确定要将此活动下线？</h3>
        </div>
        <div class="pop_submit_con">
            <input type="button" value="保 存" class="loginbtn" onclick="Popup.closed('downline')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('downline')" />
        </div>
    </div>
</div>