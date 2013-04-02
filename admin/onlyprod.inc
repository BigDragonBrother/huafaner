<?php 
include_once PATH_BLL.'/prodBll.inc';

$prod_type_list=  prodBll::getDict("prod_type");
$prod_id=Tools::getValue('id');
if($prod_id)
{
    $prod=prodBll::getProdByid($prod_id);
    $prod_pic=prodBll::getProdPicByprodid($prod_id);
}
else
{
    $prod=false;
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
            <td align="right">商品名称：</td>
            <td><input id="prod_name" size="50" type="textbox" value="<?php echo $prod?$prod["prod_name"]:''; ?>"/></td>
        </tr>
        <tr>
            <td align="right">原价：</td>
            <td><input id="prod_origin_price" size="10" type="textbox" value="<?php echo $prod?$prod["prod_origin_price"]:''; ?>"/>元</td>
        </tr>
        <tr>
            <td align="right">上传图片：</td>
            <td>
                <form id="pic0" name="pic0" action="picupload.php" method="post" enctype="multipart/form-data">   
                    <input type="hidden" value="<?php echo count($prod_pic)>0?$prod_pic[0]['pic_path']:''; ?>" id="pic_path" name="pic_path"></input>
                    <image id="pic_yulan" name="pic_yulan" src="<?php echo count($prod_pic)>0?$prod_pic[0]['pic_path']:''; ?>" style="width:95px;height: 90px;boder:1px"/>
                    <input type="file" id="pic" name="pic" onchange="fileupload('pic0')"/>
                </form>
            </td>
        </tr>
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
<input type="button" class="button" onclick="<?php echo $prod?'Only_add('.$prod_id.')':'Only_add()'; ?>" value="发   布">


