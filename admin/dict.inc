<?php 
include_once PATH_BLL.'/prodBll.inc';

$prod_type_list=  prodBll::getDict();
?>
<fieldset class="fieldset">
    <legend>字典添加</legend>
    <div>
        <select id="dict_type">
            <?php
                foreach (Conf::$dict_type as $k => $v) {
                    echo "<option value=\"",$k,"\">",$v,"</option>";
                }
            ?>
        </select>
        <input type="textbox" id="dict_name"/>
        <input type="button" value="确定" 
        onclick="dict_add()"/>
    </div>
    <div>
        <table>
            <tr><td>编号</td><td>类型</td><td>名称</td><td>操作</td></tr>
            <?php
            foreach($prod_type_list as $k=>$v)
            {
                echo '<tr><td>'.$v['dict_id'].'</td><td>'.Conf::$dict_type[$v['dict_type']].'</td><td>'.$v['dict_name'].'</td><td><a onclick="Prod_type_del('.$v['dict_id'].')">删除</a></td>';
            }
            ?>
        </table>
    </div>
</fieldset>

