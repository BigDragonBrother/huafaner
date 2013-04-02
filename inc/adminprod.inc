
<?php 
include_once PATH_BLL.'/prodBll.inc';

$prod_type_list=  prodBll::getDict("prod_type");
$tag_1_list=  prodBll::getDict("tag_1");
$tag_2_list=  prodBll::getDict("tag_2");
$tag_3_list=  prodBll::getDict("tag_3");
$prod_id=Tools::getValue('id');
if($prod_id)
{
    $prod=prodBll::getProdByid($prod_id);
    $prod_pic=prodBll::getProdPicByprodid($prod_id);
    $prod_tag=prodBll::getTagsByprodid($prod_id);
}
else
{
    $prod=false;
    $prod_tag=array();
}
?>
<!--商品基本信息-->
<fieldset id="prod_main" class="fieldset">
    <legend>1.基本信息</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td align="right">商品编号：</td>
            <td><?php echo $prod?$prod_id:'（系统自动生成，发布生效）'; ?></td>
        </tr>
        <tr>
            <td align="right">商品展示序号：</td>
            <td><input id="prod_show_seq" size="5" type="textbox" value="<?php echo $prod?$prod['prod_show_seq']:'0'; ?>"/>
            （序号越大展示越靠前）
            </td>
        </tr>
        <tr>
            <td align="right">是否发布到首页：</td>
            <td><input id="prod_index_show" name="prod_index_show" type="checkbox" <?php echo $prod&$prod['prod_index_show']?"checked":"";?> />
            </td>
        </tr>
        <tr>
            <td align="right">商品名称：</td>
            <td><input id="prod_name" size="50" type="textbox" value="<?php echo $prod?$prod["prod_name"]:''; ?>"/></td>
        </tr>
        <tr>
            <td align="right">商品副标题：</td>
            <td><input id="prod_title" size="50" type="textbox" value="<?php echo $prod?$prod["prod_title"]:''; ?>"/></td>
        </tr>
        <tr>
            <td align="right">原价：</td>
            <td><input id="prod_origin_price" size="10" type="textbox" value="<?php echo $prod?$prod["prod_origin_price"]:''; ?>"/>元</td>
        </tr>
        <tr>
            <td align="right">现价：</td>
            <td><input id="prod_sale_price" size="10" type="textbox" value="<?php echo $prod?$prod["prod_sale_price"]:''; ?>"/>元</td>
        </tr>
        <tr>
            <td align="right">类型：</td>
            <td>
                <select id="prod_type" name="prod_type">
                    <?php
                    foreach($prod_type_list as $k=>$v)
                    {
                        if($prod&$prod['prod_type']===$v['dict_id'])
                        {
                            echo '<option selected= "selected" value="'.$v['dict_id'].'">'.$v['dict_name'].'</option>';
                        }
                        else
                        {
                            echo '<option value="'.$v['dict_id'].'">'.$v['dict_name'].'</option>';
                        }
                    }
                    ?>
                </select>
                <a href="admin.php?k=admindict" target="_blank">增加类型</a>
            </td>
        </tr>
        <tr>
            <td align="right">标签：</td>
            <td>
                <?php 
                    foreach ($tag_2_list as $k => $v) 
                    {
                        if($prod&in_array($v['dict_id'],$prod_tag))
                        {
                            echo "<input name=\"prod_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\" checked=\"checked\" >",$v['dict_name'],"</input>";
                        }
                        else
                        {
                            echo "<input name=\"prod_tag\" type=\"checkbox\" value=\"",$v['dict_id'],"\">",$v['dict_name'],"</input>";
                        }
                    }
                ?>

            </td>
        </tr>
    </table>
</fieldset>

<!--商品详细信息-->
<fieldset id="prod_detail" class="fieldset">
    <legend>2.详细信息</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td align="right">图片：</td>
            <td>
                <table>
                    <tr>
                        <td>列表页图</td>
                        <td>
                            <form id="pic0" name="pic0" action="picupload.php" method="post" enctype="multipart/form-data">   
                                <input type="hidden" value="<?php echo count($prod_pic)>0?$prod_pic[0]['pic_path']:''; ?>" id="pic_path" name="pic_path"></input>
                                <image id="pic_yulan" name="pic_yulan" src="<?php echo count($prod_pic)>0?$prod_pic[0]['pic_path']:''; ?>" style="width:95px;height: 90px;boder:1px"/>
                                <input type="file" id="pic" name="pic" onchange="fileupload('pic0')"/>
                            </form>
                        </td>
                    </tr>
                    <tr>
                        <td>缩略图</td>
                        <td>
                            <form id="pic1" name="pic1" action="picupload.php" method="post" enctype="multipart/form-data">   
                                <input type="hidden" value="<?php echo count($prod_pic)>1?$prod_pic[1]['pic_path']:''; ?>" id="pic_path" name="pic_path"></input>
                                <image id="pic_yulan" name="pic_yulan" src="<?php echo count($prod_pic)>1?$prod_pic[1]['pic_path']:''; ?>" style="width:95px;height: 90px;boder:1px"/>
                                <input type="file" id="pic" name="pic" onchange="fileupload('pic1')"/>
                            </form>
                        </td>
                    </tr>
                    <tr>
                        <td>详情图</td>
                        <td>
                            <form id="pic2" name="pic2" action="picupload.php" method="post" enctype="multipart/form-data">   
                                <input type="hidden" value="<?php echo count($prod_pic)>2?$prod_pic[2]['pic_path']:''; ?>" id="pic_path" name="pic_path"></input>
                                <image id="pic_yulan" name="pic_yulan" src="<?php echo count($prod_pic)>2?$prod_pic[2]['pic_path']:''; ?>" style="width:95px;height: 90px;boder:1px"/>
                                <input type="file" id="pic" name="pic" onchange="fileupload('pic2')"/>
                            </form>
                        </td>
                    </tr>
                </table>
            </td>
        </tr>
        <tr>
            <td align="right" valign="top">花材花语：</td>
            <td><textarea id="prod_medium" rows="5" cols="60" wrap="virtual"><?php echo $prod?$prod["prod_medium"]:''; ?></textarea></td>
        </tr>
        <tr><td align="right" valign="top">设计寄语：</td><td><textarea id="prod_word" rows="5" cols="60" wrap="virtual"><?php echo $prod?$prod["prod_word"]:''; ?></textarea></td></tr>
        <tr><td align="right" valign="top">规格：</td><td><textarea id="standards" rows="5" cols="60" wrap="virtual"><?php echo $prod?$prod["standards"]:''; ?></textarea></td></tr>
    </table>
</fieldset>

<!--商品其他信息-->
<fieldset id="prod_detail" class="fieldset">
    <legend>3.其他信息</legend>
    <table style="position:relative;left: 10px">
        <tr>
            <td align="right">备货周期：</td>
            <td><input id="prod_stock_up" size="10" type="textbox" value="<?php echo $prod?$prod["prod_stock_up"]:''; ?>" />天
            </td>
        </tr>
        <tr>
            <td align="right">销售时限：</td>
            <td><input id="prod_date_range" size="10" type="textbox" value="<?php echo $prod?$prod["prod_date_range"]:''; ?>">天(自上架之日起x天为有效销售时限，超出时限将自动下架）</td>
        </tr>
        <tr><td align="right" valign="top">保养说明：</td><td><textarea id="prod_area_range" rows="5" cols="60" wrap="virtual"><?php echo $prod?$prod["prod_area_range"]:''; ?></textarea></td></tr>
        <tr><td align="right" valign="top">订购说明：</td><td><textarea id="prod_freight"  rows="5" cols="60" wrap="virtual"><?php echo $prod?$prod["prod_freight"]:''; ?></textarea></td></tr>
        <tr><td align="right" valign="top">配送说明：</td><td><textarea id="prod_desc" rows="5" cols="60" wrap="virtual"><?php echo $prod?$prod["prod_desc"]:''; ?></textarea></td></tr>
        <tr>
            <td align="right" valign="top">上架时间：</td>
            <td>
                <input type="radio" name="prod_onshelf_type" value="1" <?php echo $prod&$prod['prod_onshelf_type']=='1'?'checked':''; ?>>立即上架<br>
                <input type="radio" name="prod_onshelf_type" value="2" <?php echo $prod&$prod['prod_onshelf_type']=='2'?'checked':''; ?>>设定
                <input type="text" id="datepicker" name="datepicker" class="datepicker"/>
                <select id="datet" name="datet">
                    <option value="0">0</option>
                    <option value="1">1</option>
                    <option value="2">2</option>
                    <option value="3">3</option>
                    <option value="4">4</option>
                    <option value="5">5</option>
                    <option value="6">6</option>
                    <option value="7">7</option>
                    <option value="8">8</option>
                    <option value="9">9</option>
                    <option value="10">10</option>
                    <option value="11">11</option>
                    <option value="12">12</option>
                    <option value="13">13</option>
                    <option value="14">14</option>
                    <option value="15">15</option>
                    <option value="16">16</option>
                    <option value="17">17</option>
                    <option value="18">18</option>
                    <option value="19">19</option>
                    <option value="20">20</option>
                    <option value="21">21</option>
                    <option value="22">22</option>
                    <option value="23">23</option>
                    <option value="24">24</option>
                </select>
                上架销售<br>
                <input type="radio" name="prod_onshelf_type" value="3" <?php echo $prod&$prod['prod_onshelf_type']=='3'?'checked':''; ?>>放入仓库
            </td>
        </tr>
    </table>
</fieldset>
<input type="button" class="button" onclick="<?php echo $prod?'Prod_add('.$prod_id.')':'Prod_add()'; ?>" value="发   布">
