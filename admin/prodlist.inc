<?php
include_once PATH_BLL.'/prodBll.inc';
$prod_type_list=  prodBll::getDict('prod_type');
$page_num=Tools::getValue('page_num')?Tools::getValue('page_num'):1;
$where="";
if(Tools::getValue('prod_name'))
    $where = " and prod_name like '%".Tools::getValue('prod_name')."%'";
if(Tools::getValue('prod_type'))
    $where = $where." and prod_type=".Tools::getValue('prod_type');
if(Tools::getValue('prod_onshelf_time_low'))
    $where = $where." and prod_onshelf_time >='".Tools::getValue('prod_onshelf_time_low')."'";
if(Tools::getValue('prod_onshelf_time_high'))
    $where = $where." and prod_onshelf_time <='".Tools::getValue('prod_onshelf_time_high')."'";
if(Tools::getValue('prod_sale_price_low'))
    $where = $where." and prod_sale_price >=".Tools::getValue('prod_sale_price_low');
if(Tools::getValue('prod_sale_price_high'))
    $where = $where." and prod_sale_price <=".Tools::getValue('prod_sale_price_high');
if($where!="")
    $where = "where ".substr($where,4);
$prod_list=prodBll::getProds($where,$page_num,Conf::$pageSet['page_size']);
?>
<div class="title"><h2>维护商品</h2></div>
<div class="content">
    <dl class="locate">
        <dd>
            <label>商品名称</label>
            <input id="prod_name" class="same" type="text" value="<?php echo Tools::getValue('prod_name');?>"/>
        </dd>
        <dd>
            <label>商品分类</label>
            <select id="prod_type" name="prod_type">
                <option selected>全部</option>
                <?php 
                    foreach ($prod_type_list as $k => $v) {
                        if(Tools::getValue('prod_type')==$v['dict_id'])
                        {
                            echo '<option value="',$v['dict_id'],'" selected>',$v['dict_name'],'</option>';
                        }
                        else
                        {
                            echo '<option value="',$v['dict_id'],'">',$v['dict_name'],'</option>';   
                        }
                    }
                ?>
            </select>
        </dd>
        <dd class="sty290">
            <label>上架时间</label>
            <input id="prod_onshelf_time_low" class="same sty85" type="text" value="<?php echo Tools::getValue('prod_onshelf_time_low');?>" />
            <span>至</span>
            <input id="prod_onshelf_time_high" class="same sty85" type="text" value="<?php echo Tools::getValue('prod_onshelf_time_high');?>"/>
        </dd>
        <dd class="sty290">
            <label>商品价格</label>
            <input id="prod_sale_price_low" class="same sty85" type="text" value="<?php echo Tools::getValue('prod_sale_price_low');?>"/>
            <span>至</span>
            <input id="prod_sale_price_high" class="same sty85" type="text" value="<?php echo Tools::getValue('prod_sale_price_high');?>"/>
        </dd>
        <dt>
            <input type="button" value="查 询" class="loginbtn" onclick="prodlistsearch()"/>
            <input type="button" value="清 空" class="loginbtn" onclick="prodlistclean()"/>
        </dt>
    </dl>
    <div class="clearer"></div>
        <table class="list">
            <tr>
                <th></th>
                <th>商品编号</th>
                <th>商品名称</th>
                <th>商品分类</th>
                <th>价格</th>
                <th>上架时间</th>
                <th>有效期</th>
                <th>备货期</th>
                <th>状态</th>
                <th>操作</th>
            </tr>
            <?php
            foreach($prod_list as $k=>$v)
            {
                $prod_onshelf=Conf::$prod_onshelf_status[$v['prod_onshelf_type']];
                $prod_onshelf_op = $v['prod_onshelf_type']==1?"下架":"上架";
                foreach ($prod_type_list as $a => $b) {
                    if($b['dict_id']==$v['prod_type'])
                        $prod_type = $b['dict_name'];
                }
            ?>
            <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td><?php echo $v['prod_id']; ?></td>
                <td><?php echo $v['prod_name']; ?></td>
                <td><?php echo $prod_type; ?></td>
                <td>￥<?php echo $v['prod_sale_price']; ?></td>
                <td><?php echo $v['prod_onshelf_time']; ?></td>
                <td><?php echo $v['prod_date_range']; ?></td>
                <td><?php echo $v['prod_stock_up']; ?></td>
                <td><?php echo $prod_onshelf; ?></td>
                <td>
                    <a href="admin.php?k=prod&id=<?php echo $v['prod_id']; ?>">修改</a>
                    <a href="javascript:void(0)" onclick="prod_onshelf(<?php echo $v['prod_id'],',',$v['prod_onshelf_type'];?>)">
                        <?php echo $prod_onshelf_op; ?>
                    </a>
                </td>
            </tr>
            <?php
            }
            ?>
            <tr>
                <td colspan="10" class="bjnone">
                    <div class="selbox">
                        <input class="inputcheckbox" type="checkbox" id="ckAll"><label for="ckAll">全选</label>
                        <input type="button" value="上架" class="tbend" />
                        <input type="button" value="下架" class="tbend" />
                    </div>
                    <div class="pages">
                        <a href="admin.php?k=prodlist">首页</a>
                        <a href="admin.php?k=prodlist&page_num=<?php echo $page_num+1; ?>">下一页</a>
                        <a href="admin.php?k=prodlist&page_num=<?php echo $page_num-1; ?>">上一页</a>
                    </div>
                </td>
            </tr>
        </table>
    </div>
</div>