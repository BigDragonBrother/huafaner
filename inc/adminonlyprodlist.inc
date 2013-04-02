<?php
include_once PATH_BLL.'/prodBll.inc';

$prod_list=prodBll::getallOnlyprods();
?>
<fieldset id="prod_list" class="fieldset">
    <legend>商品列表</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td>商品编号</td>
            <td>展示顺序</td>
            <td>商品名称</td>
            <td>现价</td>
            <td>商品类型</td>
            <td>上架状态</td>
            <td>操作</td>
        </tr>

        <?php
        foreach($prod_list as $k=>$v)
        {
            $prod_onshelf=Conf::$prod_onshelf_status[$v['prod_onshelf_type']];
            $prod_onshelf_op = $v['prod_onshelf_type']==1?"下架":"上架";
            echo "<tr><td>".$v['prod_id']."</td><td>".$v['prod_show_seq']."</td><td>".$v['prod_name']."</td><td>".$v['prod_sale_price']."<td>".Conf::$prod_cat[$v['prod_cat']]."</td><td>".
                    "</td><td>".$prod_onshelf.
                    " </td><td><a href=\"javascript:void(0)\" onclick='prod_onshelf(".$v['prod_id'].','.$v['prod_onshelf_type'].")'>".
                    $prod_onshelf_op."</a>|<a href=\"admin.php?k=adminonlyprod&id=".$v['prod_id']."\">修改</a></td></tr>";
        }
        ?>

    </table>
</fieldset>
