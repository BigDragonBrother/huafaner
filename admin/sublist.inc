<?php
include_once PATH_BLL.'/subBll.inc';

$sub_list=subBll::getAllSub();
?>
<fieldset id="prod_list" class="fieldset">
    <legend>专题列表</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td>专题编号</td>
            <td>展示顺序</td>
            <td>专题名称</td>
            <td>开始时间</td>
            <td>结束时间</td>
            <td>操作</td>
        </tr>

        <?php
        foreach($sub_list as $k=>$v)
        {
            echo "<tr><td>".$v['sub_id']."</td><td>".$v['sub_show_seq']."</td><td>".$v['sub_name']."</td><td>".
                 $v['sub_start']."</td><td>".$v['sub_end'].
                 " </td><td><a href=\"admin.php?k=adminsub&id=".$v['sub_id']."\">修改</a></td></tr>";
        }
        ?>

    </table>
</fieldset>
