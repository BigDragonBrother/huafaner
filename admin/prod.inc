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
<div class="title">
    <h2>发布商品</h2>
    <span>以下均为必填项</span>
</div>
<div class="content">
    <div class="con_list">
        <span class="con_tit">商品名称：</span>
        <p><input id="prod_name" value="<?php echo $prod?$prod["prod_name"]:''; ?>" class="same" type="text" /></p>
        <div class="error">请输入商品名称！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">商品副标题：</span>
        <p><input id="prod_title" value="<?php echo $prod?$prod["prod_title"]:''; ?>" class="same" type="text" /></p>
        <div class="error">请输入商品副标题！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">商品分类：</span>
        <p>
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
        </p>
        <span class="linka">
            <a href="admin.php?k=admindict" target="_blank">增加类型</a>
            <!--<a href="javascript:void(0)" onclick="Popup.popping('add_sort',true)">添加分类</a>-->
        </span>
        <div class="error">请选择商品类型！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">商品价格：</span>
        <p><input id="prod_sale_price" value="<?php echo $prod?$prod["prod_sale_price"]:''; ?>" class="same" type="text" /></p>
        <span class="note">元</span>
        <div class="error">请输入商品价格！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">商品图片：</span>
        <div class="imgpic">
            <a href="javascript:void(0)" onclick="Popup.popping('add_pic',true)">列表图</a>
        </div>
        <div class="imgpic">
            <a href="javascript:void(0)" onclick="Popup.popping('add_pic',true)">详情图</a>
        </div>
        <div class="error">请上传列表图/详情图！</div>                
    </div>
    <div class="con_list">
        <span class="con_tit">设计灵感：</span>
        <p>
            <textarea id="prod_word" cols="" rows="" class="textarea"><?php echo $prod?$prod["prod_word"]:''; ?></textarea>
        </p>
        <div class="error">请输入设计灵感！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">花语：</span>
        <p>
            <textarea id="prod_medium" cols="" rows="" class="textarea"><?php echo $prod?$prod["prod_medium"]:''; ?></textarea>
        </p>
        <div class="error">请输入花语！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">规格：</span>
        <p>
            <textarea id="standards" cols="" rows="" class="textarea"><?php echo $prod?$prod["standards"]:''; ?></textarea>
        </p>
        <div class="error">请输入规格！</div>
    </div>
    <div class="con_list"><span class="con_tit">保养说明：</span>
        <p>
            <select id="" name="">
                <option value="请选择保养说明" selected="">请选择保养说明</option>
                <option value="花束保养说明">花束保养说明</option>
                <option value="瓶花保养说明">瓶花保养说明</option>
                <option value="花盒保养说明">花盒保养说明</option>
                <option value="多肉保养说明">多肉保养说明</option>
            </select>
        </p>
        <div class="error">请输入保养说明！</div>
    </div>
    <div class="con_list"><span class="con_tit">订购说明：</span>
        <p>
            <select id="" name="">
                <option value="请选择订购说明" selected="">请选择订购说明</option>
                <option value="鲜花订购说明">鲜花订购说明</option>
                <option value="多肉订购说明">多肉订购说明</option>
            </select>
        </p>
        <div class="error">请输订购养说明！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">标签：</span>
        <div class="pad_l120">
            <div class="tag_info"><p><input name="" class="same" type="text" /></p><div class="error">请输入订购说明！</div></div>
            <div class="clearer"></div>
            <div class="tag_info"><p>常用标签：</p><a href="javascript:void(0)" onclick="Popup.popping('add_tag',true)">添加标签</a></div>
            <div class="tag_info">
                <ul>
                    <li>+爱情</li>
                    <li>+暗恋</li>
                    <li>+表白</li>
                    <li>+求婚</li>
                    <li>+兄弟基情</li>
                    <li>+闺蜜蜜糖</li>
                    <li>+友情</li>
                    <li>+生日祝福</li>
                    <li>+家居</li>
                    <li>+爱情</li>
                    <li>+暗恋</li>
                    <li>+表白</li>
                    <li>+求婚</li>
                    <li>+兄弟基情</li>
                    <li>+闺蜜蜜糖</li>
                    <li>+友情</li>
                    <li>+生日祝福</li>
                    <li>+家居</li>
                </ul>
            </div>
        </div>
    
    </div>            
    <div class="con_list">
        <span class="con_tit">备货期：</span>
        <p>
            <input id="prod_stock_up" class="same sty60" type="text" value="<?php echo $prod?$prod["prod_stock_up"]:''; ?>"/>
        </p>
        <span class="note">天</span>
        <div class="error">请输入备货天数！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">有效期：</span>
        <p>
            <input id="prod_date_range" value="<?php echo $prod?$prod["prod_date_range"]:''; ?>" class="same sty60" type="text" />
        </p>
        <span class="note">天</span>
        <div class="error">请输入有效期天数！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">上架时间：</span>
        <div class="radio_list">
            <p><label for="a1"><input name="toptime" checked="checked" id="a1" type="radio" value="0" />立即上架</label></p>
            <p><label for="a2"><input name="toptime" id="a2" type="radio" value="1" />设定</label><input name="" class="same sty120" type="text" /><span class="note">上架</span></p>
            <p><label for="a3"><input name="toptime" id="a3" type="radio" value="2" />放入仓库</label></p>
        </div>
    </div>
    <div class="btn_submit">
        <input type="button" value="发 布" onclick="<?php echo $prod?'Prod_add('.$prod_id.')':'Prod_add()'; ?>"  class="loginbtn" />
        <input type="button" value="取 消" class="loginbtn" />
    </div>
</div>


<!-- 弹出层 分类 -->
<div class="popping sty500" id="add_sort" style="display:none;">
    <div class="popping_title">
        <h2>取消订单</h2>
        <div class="closed" onclick="Popup.closed('add_sort')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="con_list"><span class="pop_tit">分类名称：</span><p><input name="" class="same" type="text" /></p><div class="error">名称重复请重新命名！</div></div>
         
        <div class="pop_submit">
            <input type="button" value="保 存" class="loginbtn" onclick="Popup.closed('add_sort')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('add_sort')" />
        </div>
    </div>
</div>
<!-- 弹出层 标签 -->
<div class="popping sty500" id="add_tag" style="display:none;">
    <div class="popping_title">
        <h2>取消订单</h2>
        <div class="closed" onclick="Popup.closed('add_tag')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="con_list"><span class="pop_tit">分类名称：</span><p><input name="" class="same" type="text" /></p><div class="error">名称重复请重新命名！</div></div>
         
        <div class="pop_submit">
            <input type="button" value="保 存" class="loginbtn" onclick="Popup.closed('add_tag')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('add_tag')" />
        </div>
    </div>
</div>
<!-- 弹出层 商品图片 -->
<div class="popping sty500" id="add_pic" style="display:none;">
    <div class="popping_title">
        <h2>上传图片</h2>
        <div class="closed" onclick="Popup.closed('add_pic')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="con_list"><span class="pop_tit">选择文件：</span><p><input name="" class="" type="file" /></p><div class="error">文件格式错误！</div></div>
         
        <div class="pop_submit">
            <input type="button" value="上 传" class="loginbtn" onclick="Popup.closed('add_pic')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('add_pic')" />
        </div>
    </div>
</div>
