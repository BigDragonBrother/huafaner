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
$where="";
$page_num=1;
$prod_list=prodBll::getProds($where,$page_num,Conf::$pageSet['page_size']);
?>
<div class="title">
    <h2>发布专题</h2><span>以下均为必填项</span>
</div>
<div class="content">
    <div class="con_list">
        <span class="con_tit">专题名称：</span>
        <p><input id="sub_name" value="<?php echo $sub?$sub['sub_name']:''; ?>" class="same" type="text" /></p>
        <div class="error">请输入专题名称！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">专题描述：</span>
        <p><textarea id="sub_desc" cols="" rows="" class="textarea"><?php echo $sub?$sub['sub_desc']:''; ?></textarea></p>
        <div class="error">请输入专题描述！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">专题标签：</span>
        <p><input id="sub_tag" class="same" type="text" /></p>
        <div class="error">请输入专题标签！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">专题图片：</span>
        <div class="imgpic">
            <a href="javascript:void(0)" onclick="pic='_sub_list';$('#pic').val('');Popup.popping('add_pic',true);">
                <img id="pic_sub_list" style="width:150px;height:143px;" alt="列表页" src="<?php echo $sub?$sub['sub_pic_list']:''; ?>"/>
            </a>
        </div>
        <div class="imgpic">
            <a href="javascript:void(0)" onclick="pic='_sub';$('#pic').val('');Popup.popping('add_pic',true);">
                <img id="pic_sub" style="width:150px;height:143px;" alt="详情页" src="<?php echo $sub?$sub['sub_pic']:''; ?>"/>
            </a>
        </div>
        <div class="error">请上传列表页图片/详情页图片！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">选择商品：</span>
        <div class="pad_l120">
            <div class="tag_info">
                <p><input name="" class="same" type="text" onclick="Popup.popping('sel_product',true)" /></p>
            </div>
            <div class="clearer"></div>
            <div class="tag_info">
                <ul>
                    <li><span>商品名称</span><a href="#">×</a></li>
                </ul>
            </div>
        </div>
    </div>
    <div class="con_list">
        <span class="con_tit">上线时间：</span>
        <div class="radio_list">
            <p>
                <label for="a1">
                    <input name="sub_on" checked="checked" id="a1" type="radio" value="1" />立即上架
                </label>
            </p>
            <p>
                <label for="a2">
                    <input name="sub_on" <?php echo $sub&$sub['sub_on']==2?'checked="checked"':''; ?> id="a2" type="radio" value="2" />设定
                </label>
                <input id="sub_start" class="same sty85" type="text" value="<?php echo $sub?$sub['sub_start']:''; ?>"/>
                <span class="note">上架</span>
            </p>
        </div>
    </div>
    <div class="btn_submit">
        <input type="button" value="发 布" class="loginbtn" />
        <input type="button" value="取 消" class="loginbtn" />
    </div>
</div>

<!-- 弹出层 选择商品 -->
<div class="popping sty980" id="sel_product" style="display:none;">
    <div class="popping_title">
        <h2>选择商品</h2>
        <div class="closed" onclick="Popup.closed('sel_product')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="content">
            <dl class="locate">
                <dd><label>商品名称</label><input name="" class="same" type="text" /></dd>
                <dd class="sty230"><label>商品分类</label>
                    <select id="" name="">
                        <option value="全部" selected="">全部</option>
                        <option value="普通商品">普通商品普通商品</option>
                        <option value="定制商品">定制商品</option>
                    </select>
                </dd>
                <dd class="sty230"><label>商品状态</label>
                    <select id="" name="">
                        <option value="全部" selected="">全部</option>
                        <option value="普通商品">普通商品普通商品</option>
                        <option value="定制商品">定制商品</option>
                    </select>
                </dd>
                <dt>
                    <input type="button" value="查 询" class="loginbtn" />
                    <input type="button" value="重 置" class="loginbtn" />
                </dt>
            </dl>
            <div class="clearer"></div>
            <table class="list">
                <tr>
                    <th></th><th>商品编号</th><th>商品名称</th><th>商品分类</th>
                    <th>价格</th><th>上架时间</th><th>状态</th><th>操作</th>
                </tr>
                <?php
                foreach ($prod_list as $k => $v) {
                ?>
                    <tr>
                        <td><input type="checkbox" name="sub" /></td>
                        <td><?php echo $v['prod_id']; ?></td>
                        <td><?php echo $v['prod_name']; ?></td>
                        <td><?php echo $v['prod_type']; ?></td>
                        <td><?php echo $v['prod_sale_price']; ?></td>
                        <td><?php echo $v['prod_onshelf_time']; ?></td>
                        <td><?php echo $v['prod_onshelf_type']; ?></td>
                        <td><a href="#">选择此商品</a></td>
                    </tr>
                <?php
                }
                ?>
                <tr>
                    <td colspan="8" class="bjnone">
                        <div class="pages">
                            <a href="#">首页</a><a href="#">下一页</a><a href="#">上一页</a><a href="#">尾页</a>
                        </div>
                    </td>
                </tr>
            </table>
        </div>
        <div class="pop_submit">
            <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('sel_product')" />
        </div>
    </div>
</div>

<!-- 弹出层 专题图片 -->
<div class="popping sty500" id="add_pic" style="display:none;">
    <div class="popping_title">
        <h2>上传图片</h2>
        <div class="closed" onclick="Popup.closed('add_pic')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
        <form id="pic_sub_form" name="pic_sub_form" action="picupload.php" method="post" enctype="multipart/form-data">
            <div class="con_list">
                <span class="pop_tit">选择文件：</span>
                <p>
                    <input type="file" id="pic" name="pic" onchange=""/>
                </p>
                <div class="error">文件格式错误！</div>
            </div>
            <div class="pop_submit">
                <input type="button" value="上 传" class="loginbtn" onclick="fileupload('pic_sub_form');Popup.closed('add_pic')" />
                <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('add_pic')" />
            </div>
        </form>
    </div>
</div>