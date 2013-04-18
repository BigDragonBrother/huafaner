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

//$prod_list=  prodBll::getProds();
?>
<div class="title">
    <h2>发布专题</h2><span>以下均为必填项</span>
</div>
<div class="content">
    <div class="con_list">
        <span class="con_tit">专题名称：</span>
        <p><input name="" class="same" type="text" /></p>
        <div class="error">请输入专题名称！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">专题描述：</span>
        <p><textarea name="" cols="" rows="" class="textarea"></textarea></p>
        <div class="error">请输入专题描述！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">专题标签：</span>
        <p><input name="" class="same" type="text" /></p>
        <div class="error">请输入专题标签！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">专题图片：</span>
        <div class="imgpic">
            <a href="javascript:void(0)" onclick="Popup.popping('add_pic',true)">列表页</a>
        </div>
        <div class="imgpic">
            <a href="javascript:void(0)" onclick="Popup.popping('add_pic',true)">详情面图</a>
        </div>
        <div class="error">请上传首页图片/列表页图片/详情页图片！</div>
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
                    <li><span>商品名称</span><a href="#">×</a></li>
                    <li><span>商品名称</span><a href="#">×</a></li>
                    <li><span>商品名称</span><a href="#">×</a></li>
                    <li><span>商品名称</span><a href="#">×</a></li>
                    <li><span>商品名称</span><a href="#">×</a></li>
                </ul>
            </div>
        </div>
    </div>
    <div class="con_list">
        <span class="con_tit">上线时间：</span>
        <div class="radio_list">
            <p>
                <label for="a1"><input name="toptime" checked="checked" id="a1" type="radio" value="0" />立即上架</label>
            </p>
            <p>
                <label for="a2"><input name="toptime" id="a2" type="radio" value="1" />设定</label>
                <input name="" class="same sty120" type="text" />
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
                <th></th>
                <th>商品编号</th>
                <th>商品名称</th>
                <th>商品分类</th>
                <th>价格</th>
                <th>上架时间</th>
                <th>状态</th>
                <th>操作</th>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00001</td>
                <td>花间酒</td>
                <td>普通商品</td>
                <td>￥598</td>
                <td>2012-09-09 10:00:11</td>
                <td>出售中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00002</td>
                <td>花间酒</td>
                <td>定制商品</td>
                <td>￥422</td>
                <td>2012-09-09 10:00:11</td>
                <td>仓库中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00003</td>
                <td>花间酒</td>
                <td>普通商品</td>
                <td>￥643</td>
                <td>2012-09-09 10:00:11</td>
                <td>仓库中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00004</td>
                <td>花间酒</td>
                <td>定制商品</td>
                <td>￥754</td>
                <td>2012-09-09 10:00:11</td>
                <td>出售中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00005</td>
                <td>花间酒</td>
                <td>普通商品</td>
                <td>￥598</td>
                <td>2012-09-09 10:00:11</td>
                <td>出售中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00006</td>
                <td>花间酒</td>
                <td>普通商品</td>
                <td>￥346</td>
                <td>2012-09-09 10:00:11</td>
                <td>仓库中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00007</td>
                <td>花间酒</td>
                <td>定制商品</td>
                <td>￥598</td>
                <td>2012-09-09 10:00:11</td>
                <td>出售中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00008</td>
                <td>花间酒</td>
                <td>普通商品</td>
                <td>￥598</td>
                <td>2012-09-09 10:00:11</td>
                <td>出售中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00009</td>
                <td>花间酒</td>
                <td>普通商品</td>
                <td>￥598</td>
                <td>2012-09-09 10:00:11</td>
                <td>出售中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
              <tr>
                <td><input type="checkbox" name="sub" /></td>
                <td>00010</td>
                <td>花间酒</td>
                <td>普通商品</td>
                <td>￥598</td>
                <td>2012-09-09 10:00:11</td>
                <td>出售中</td>
                <td><a href="#">选择此商品</a></td>
              </tr>
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
         <div class="con_list"><span class="pop_tit">选择文件：</span><p><input name="" class="" type="file" /></p><div class="error">文件格式错误！</div></div>
         
        <div class="pop_submit">
            <input type="button" value="上 传" class="loginbtn" onclick="Popup.closed('add_pic')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('add_pic')" />
        </div>
    </div>
</div>





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

