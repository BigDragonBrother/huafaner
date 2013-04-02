<?php
include_once PATH_BLL.'/subBll.inc';
include_once PATH_BLL.'/prodBll.inc';

$sub_id=Tools::getValue('id');
$tag_1_list=  prodBll::getDict("tag_1");
$tag_2_list=  prodBll::getDict("tag_2");
$tag_3_list=  prodBll::getDict("tag_3");
if($sub_id)
{
    $sub=subBll::getSubByid($sub_id);
    $sub_tag=subBll::getTagsBysubid($sub_id);;
}
else
{
    $sub=false;
    $sub_tag=array();
}

$prod_list=  prodBll::getProds();
?>
<fieldset id="prod_main" class="fieldset">
    <legend>专题基本信息</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td align="right">专题编号：</td>
            <td><?php echo $sub?$sub_id:'（系统自动生成，发布生效）'; ?></td>
        </tr>
        <tr>
            <td align="right">专题展示序号：</td>
            <td><input id="sub_show_seq" size="5" type="textbox" value="<?php echo $sub?$sub['sub_show_seq']:'0'; ?>"/>
            （序号越大展示越靠前）
            </td>
        </tr>
        <tr>
            <td align="right">专题名称：</td>
            <td><input id="sub_name" size="50" type="textbox" value="<?php echo $sub?$sub["sub_name"]:''; ?>"/></td>
        </tr>

        <tr>
            <td align="right">说明：</td>
            <td><input id="sub_desc" size="50" type="textbox" value="<?php echo $sub?$sub["sub_desc"]:''; ?>"/></td>
        </tr>
        <tr>
            <td align="right">标签：</td>
            <td>
                <table>
                    <tr>
                        <td>情感标签：</td>
                        <td><?php 
                            foreach ($tag_1_list as $k => $v) {
                                if($sub&in_array($v['dict_id'], $sub_tag))
                                {
                                    echo "<input name=\"sub_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\" checked=\"checked\" >",$v['dict_name'],"</input>";
                                }
                                else
                                {
                                    echo "<input name=\"sub_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\" >",$v['dict_name'],"</input>";
                                }
                            }
                        ?>
                        </td>
                    </tr>
                    <tr>
                        <td>风格标签：</td>
                        <td>
                            <?php 
                            foreach ($tag_2_list as $k => $v) 
                            {
                                if($sub&in_array($v['dict_id'],$sub_tag))
                                {
                                    echo "<input name=\"sub_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\" checked=\"checked\" >",$v['dict_name'],"</input>";
                                }
                                else
                                {
                                    echo "<input name=\"sub_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\">",$v['dict_name'],"</input>";
                                }
                            }
                        ?>
                        </td>
                    </tr>
                    <tr>
                        <td>色彩标签：</td>
                        <td>
                            <?php 
                            foreach ($tag_3_list as $k => $v) 
                            {
                                if($sub&in_array($v['dict_id'],$sub_tag))
                                {
                                    echo "<input name=\"sub_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\" checked=\"checked\" >",$v['dict_name'],"</input>";
                                }
                                else
                                {
                                    echo "<input name=\"sub_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\">",$v['dict_name'],"</input>";
                                }
                            }
                        ?>
                        </td>
                    </tr>
                </table>
            </td>
        </tr>
        
        <tr>
            <td align="right">开始时间：</td>
            <td>
                <input type="text" id="sub_start" name="datepicker" value="<?php echo $sub?$sub["sub_start"]:''; ?>" class="datepicker"/>
            </td>
        </tr>
        <tr>
            <td align="right">结束时间：</td>
            <td>
                <input type="text" id="sub_end" name="datepicker" value="<?php echo $sub?$sub["sub_end"]:''; ?>" class="datepicker"/>
            </td>
        </tr>
        <tr>
            <td align="right">首页图片：</td>
            <td>
                <form id="pic0" name="pic0" action="picupload.php" method="post" enctype="multipart/form-data">   
                    <input type="hidden" value="sub" id="pic_type" name="pic_type"></input>
                    <input type="hidden" value="<?php echo $sub?$sub["sub_pic_main"]:''; ?>" id="pic_path" name="pic_path"></input>
                    <image id="pic_yulan" name="pic_yulan" src="<?php echo $sub?$sub["sub_pic_main"]:''; ?>" style="width:95px;height: 90px;boder:1px"/>
                    <input type="file" id="pic" name="pic" onchange="fileupload('pic0')"/>
                </form>
            </td>
        </tr>
        <tr>
            <td align="right">列表页图片：</td>
            <td>
                <form id="pic1" name="pic1" action="picupload.php" method="post" enctype="multipart/form-data">   
                    <input type="hidden" value="sub" id="pic_type" name="pic_type"></input>
                    <input type="hidden" value="<?php echo $sub?$sub["sub_pic_list"]:''; ?>" id="pic_path" name="pic_path"></input>
                    <image id="pic_yulan" name="pic_yulan" src="<?php echo $sub?$sub["sub_pic_list"]:''; ?>" style="width:95px;height: 90px;boder:1px"/>
                    <input type="file" id="pic" name="pic" onchange="fileupload('pic1')"/>
                </form>
            </td>
        </tr>
        <tr>
            <td align="right">详情页图片：</td>
            <td>
                <form id="pic2" name="pic2" action="picupload.php" method="post" enctype="multipart/form-data">   
                    <input type="hidden" value="sub" id="pic_type" name="pic_type"></input>
                    <input type="hidden" value="<?php echo $sub?$sub["sub_pic"]:''; ?>" id="pic_path" name="pic_path"></input>
                    <image id="pic_yulan" name="pic_yulan" src="<?php echo $sub?$sub["sub_pic"]:''; ?>" style="width:95px;height: 90px;boder:1px"/>
                    <input type="file" id="pic" name="pic" onchange="fileupload('pic2')"/>
                </form>
            </td>
        </tr>
        <tr>
            <td align="right">选择商品：</td>
            <td>
                <span id="prod_id_list"><?php echo $sub?$sub["prod_id_list"]:''; ?></span>
            </td>
        </tr>
        <tr>
            <td></td>
            <td>
            <?php
                foreach($prod_list as $k=>$v)
                {
                    $checked="";
                    if($sub)
                    {
                        if(in_array($v['prod_id'],explode(',',$sub["prod_id_list"])))
                        {
                            $checked="checked";
                        }
                    }
                    
                    $prod_onshelf=Conf::$prod_onshelf_status[$v['prod_onshelf_type']];
                    echo "<input type='checkbox' ",$checked," id=\"prod_",$v['prod_id'],"\" value=\"",$v['prod_id'],"\" onclick='selectProd(this)'>商品id:",$v['prod_id'],".商品名称:",$v['prod_name'],"商品状态:",$prod_onshelf,"</input></br>";
                }
            ?>
            </td>
        </tr>
        <tr>
            <td colspan="2">
            <input type="button" class="button" onclick="sub_add(<?php echo $sub?$sub["sub_id"]:''; ?>)" value="发   布">    
            </td>
        </tr>
    </table>
</fieldset>

