<?php 
include_once PATH_BLL.'/prodBll.inc';

$dict_list=  prodBll::getDict();
$dict_type=Tools::getValue('dict_type')?Tools::getValue('dict_type'):"prod_type";
?>

<input type="hidden" id="dict_del_id" value=""/>
<?php
//Edit the prod_type
if($dict_type=="prod_type")
{
?>
<div class="title"><h2>维护商品分类</h2></div>
<div class="content">
    <div class="block">
        <h3>添加/编辑商品分类</h3>
        <div class="con_list">
            <span class="con_tit">商品分类名称：</span>
            <p>
                <input id="dict_name" class="same" type="text" />
                <input id="dict_desc" class="same" type="hidden" />
            </p>
            <div class="error">类别名称不能重复！</div>
        </div>
        <div class="btn_sub">
            <input type="button" value="保 存" class="loginbtn" onclick="dict_add('prod_type')" />
            <input type="button" value="取 消" class="loginbtn" onclick="$('#dict_prod_type').val('')"/>
        </div>
    </div>
    <div class="clearer"></div>
    <div class="block">
        <h3>商品分类列表</h3>
        <table class="list">
            <tr>
            <th>类别编号</th>
            <th>商品分类</th>
            <th>操作</th>
            </tr>
            <?php
            foreach($dict_list as $k=>$v)
            {
                if($v['dict_type']!="prod_type")
                    continue;
            ?>
                <tr>
                    <td><?php echo $v['dict_id'];?></td>
                    <td><?php echo $v['dict_name'];?></td>
                    <td>
                        <a href="javascript:void(0)" onclick="$('#dict_del_id').val('<?php echo $v['dict_id'];?>');Popup.popping('dict_del',true);">删除</a>
                    </td>
            <?php
            }
            ?>
     </table>
    </div>
</div>
<?php
}

//Edit the prod_care_desc
if($dict_type=="prod_care_desc")
{
?>
<div class="title"><h2>维护保养说明</h2></div>
<div class="content">
    <div class="block">
        <h3>添加/编辑保养说明</h3>
        <div class="con_list">
            <span class="con_tit">保养说明名称：</span>
            <p><input id="dict_name" class="same" type="text" value=""/></p>
            <div class="error">类别名称不能重复！</div>
        </div>
        <div class="con_list">
            <span class="con_tit">保养说明内容：</span>
            <p>
              <textarea id="dict_desc" class="textarea"></textarea>
          </p>
            <div class="error">类别名称不能重复！</div>
         </div>
        <div class="btn_sub">
            <input type="button" value="保 存" class="loginbtn" onclick="dict_add('prod_care_desc')"/>
            <input type="button" value="取 消" class="loginbtn" onclick="$('#dict_name').val('');$('#dict_desc').val('');"/>
        </div>
    </div>
    <div class="clearer"></div>
    <div class="block">
        <h3>保养说明列表</h3>
        <table class="list">
            <tr>
            <th style="width:100px">保养说明编号</th>
            <th style="width:100px">保养说明名称</th>
            <th>保养说明内容</th>
            <th style="width:100px">操作</th>
            </tr>
            <?php
            foreach($dict_list as $k=>$v)
            {
                if($v['dict_type']!="prod_care_desc")
                    continue;
            ?>
                <tr>
                    <td><?php echo $v['dict_id'];?></td>
                    <td><?php echo $v['dict_name'];?></td>
                    <td><?php echo $v['dict_desc'];?></td>
                    <td>
                        <a href="javascript:void(0)" onclick="$('#dict_view_name').text('<?php echo $v['dict_name'];?>');$('#dict_view_desc').text('<?php echo $v['dict_desc'];?>');Popup.popping('dict_view',true)">查看</a>
                        <a href="javascript:void(0)" onclick="$('#dict_edit_id').val('<?php echo $v['dict_id'];?>');$('#dict_edit_name').val('<?php echo $v['dict_name'];?>');$('#dict_edit_desc').val('<?php echo $v['dict_desc'];?>');Popup.popping('dict_editor',true);">修改</a>
                        <a href="javascript:void(0)" onclick="$('#dict_del_id').val('<?php echo $v['dict_id'];?>');Popup.popping('dict_del',true);">删除</a>
                    </td>
                </tr>
            <?php
            }
            ?>
        </table>
    </div>
</div>
<!-- 弹出层 查看 -->
<div class="popping sty500" id="dict_view" style="display:none;">
    <div class="popping_title">
        <h2>查看</h2>
        <div class="closed" onclick="Popup.closed('dict_view')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="con_list">
            <span class="pop_tit">保养说明名称：</span>
            <p class="sty370" id="dict_view_name"></p>
        </div>
         <div class="con_list">
            <span class="pop_tit">保养说明内容：</span>
            <p class="sty370" id="dict_view_desc"></p>
        </div>
    </div>
</div>
<!-- 弹出层 修改 -->
<div class="popping sty500" id="dict_editor" style="display:none;">
    <div class="popping_title">
        <h2>查看</h2>
        <div class="closed" onclick="Popup.closed('dict_editor')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
        <div class="status">
            <div class="con_list">
                <span class="pop_tit">保养说明名称：</span>
                <p>
                    <input id="dict_edit_name" class="same" value="" type="text" />
                    <input id="dict_edit_id" class="same" value="" type="hidden" />
                </p>
            </div>
            <div class="con_list">
                <span class="pop_tit">保养说明内容：</span>
                <p>
                    <!--<input id="dict_edit_desc" class="same" value="" type="text" />-->
                    <textarea id="dict_edit_desc" class="textarea"></textarea>
                </p>
            </div>
            <div class="pop_submit">
                <input type="button" value="确 定" class="loginbtn" onclick="dict_update('prod_care_desc');Popup.closed('dict_editor')" />
                <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('dict_editor')" />
            </div>
         </div>
    </div>
</div>
<?php
}

if($dict_type=="prod_order_desc")
{
?>
<div class="title"><h2>维护订购说明</h2></div>
<div class="content">
    <div class="block">
        <h3>添加/编辑订购说明</h3>
        <div class="con_list">
            <span class="con_tit">订购说明名称：</span>
            <p><input id="dict_name" class="same" type="text" /></p>
            <div class="error">类别名称不能重复！</div>
        </div>
        <div class="con_list">
            <span class="con_tit">订购说明内容：</span>
            <p>
              <textarea id="dict_desc" class="textarea"></textarea>
          </p>
            <div class="error">订购说明名称不能重复！</div>
         </div>
        <div class="btn_sub">
            <input type="button" value="保 存" class="loginbtn" onclick="dict_add('prod_order_desc')"/>
            <input type="button" value="取 消" class="loginbtn" onclick="$('#dict_name').val('');$('#dict_desc').val('');"/>
        </div>
    </div>
    <div class="clearer"></div>
    <div class="block">
        <h3>订购说明列表</h3>
        <table class="list">
            <tr>
                <th>订购说明编号</th>
                <th>订购说明名称</th>
                <th>订购说明内容</th>
                <th>操作</th>
            </tr>
            <?php
            foreach($dict_list as $k=>$v)
            {
                if($v['dict_type']!="prod_order_desc")
                    continue;
            ?>
                <tr>
                    <td><?php echo $v['dict_id'];?></td>
                    <td><?php echo $v['dict_name'];?></td>
                    <td><?php echo $v['dict_desc'];?></td>
                    <td>
                        <a href="javascript:void(0)" onclick="$('#dict_view_name').text('<?php echo $v['dict_name'];?>');$('#dict_view_desc').text('<?php echo $v['dict_desc'];?>');Popup.popping('dict_view',true)">查看</a>
                        <a href="javascript:void(0)" onclick="$('#dict_edit_id').val('<?php echo $v['dict_id'];?>');$('#dict_edit_name').val('<?php echo $v['dict_name'];?>');$('#dict_edit_desc').val('<?php echo $v['dict_desc'];?>');Popup.popping('dict_editor',true);">修改</a>
                        <a href="javascript:void(0)" onclick="$('#dict_del_id').val('<?php echo $v['dict_id'];?>');Popup.popping('dict_del',true);">删除</a>
                    </td>
                </tr>
            <?php
            }
            ?>
        </table>
    </div>
</div>
<!-- 弹出层 查看 -->
<div class="popping sty500" id="dict_view" style="display:none;">
    <div class="popping_title">
        <h2>查看</h2>
        <div class="closed" onclick="Popup.closed('dict_view')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="con_list">
            <span class="pop_tit">订购说明名称：</span>
            <p class="sty370" id="dict_view_name"></p>
        </div>
         <div class="con_list">
            <span class="pop_tit">订购说明内容：</span>
            <p class="sty370" id="dict_view_desc"></p>
        </div>
    </div>
</div>
<!-- 弹出层 修改 -->
<div class="popping sty500" id="dict_editor" style="display:none;">
    <div class="popping_title">
        <h2>查看</h2>
        <div class="closed" onclick="Popup.closed('dict_editor')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
        <div class="status">
            <div class="con_list">
                <span class="pop_tit">订购说明名称：</span>
                <p>
                    <input id="dict_edit_name" class="same" value="" type="text" />
                    <input id="dict_edit_id" class="same" value="" type="hidden" />
                </p>
            </div>
            <div class="con_list">
                <span class="pop_tit">订购说明内容：</span>
                <p>
                    <!--<input id="dict_edit_desc" class="same" value="" type="text" />-->
                    <textarea id="dict_edit_desc" class="textarea"></textarea>
                </p>
            </div>
            <div class="pop_submit">
                <input type="button" value="确 定" class="loginbtn" onclick="dict_update('prod_order_desc');Popup.closed('dict_editor')" />
                <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('dict_editor')" />
            </div>
         </div>
    </div>
</div>
<?php
}
//Edit the prod_tag
if($dict_type=="prod_tag")
{
?>
<div class="title"><h2>维护商品标签</h2></div>
<div class="content">
    <div class="block">
        <h3>添加/编辑商品标签</h3>
        <div class="con_list">
            <span class="con_tit">标签名称：</span>
            <p>
                <input id="dict_name" class="same" type="text" />
                <input id="dict_desc" class="same" type="hidden" />
            </p>
            <div class="error">标签名称不能重复！</div>
        </div>
        <div class="btn_sub">
            <input type="button" value="保 存" class="loginbtn" onclick="dict_add('prod_tag')"/>
            <input type="button" value="取 消" class="loginbtn" onclick="$('#dict_name').val('');"/>
        </div>
    </div>
    <div class="clearer"></div>
    <div class="block">
        <h3>所有标签</h3>
        <ul>
            <?php
            foreach($dict_list as $k=>$v)
            {
                if($v['dict_type']!="prod_tag")
                    continue;
            ?>
                <li>
                    <p><?php echo $v['dict_name'];?></p>
                    <span>
                        <a href="javascript:void(0)" onclick="$('#dict_edit_name').val('<?php echo $v['dict_name'];?>');$('#dict_edit_id').val('<?php echo $v['dict_id'];?>');Popup.popping('tag_editor',true)">编辑</a>
                        <a href="javascript:void(0)" onclick="$('#dict_del_id').val('<?php echo $v['dict_id'];?>');Popup.popping('dict_del',true);">删除</a>
                    </span>
                </li>
            <?php
            }
            ?>
        </ul>
    </div>
</div>
<!-- 弹出层 编辑 -->
<div class="popping sty350" id="tag_editor" style="display:none;">
    <div class="popping_title">
        <h2>编辑</h2>
        <div class="closed" onclick="Popup.closed('tag_editor')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="con_list">
                <span class="pop_tit">编辑标签：</span>
                <p>
                    <input id="dict_edit_name" class="same" value="" type="text" />
                    <input id="dict_edit_id" class="same" value="" type="hidden" />
                </p>
            </div>
            <div class="pop_submit">
                <input type="button" value="确 定" class="loginbtn" onclick="dict_update('prod_tag');Popup.closed('tag_editor')" />
                <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('tag_editor')" />
            </div>
         </div>
    </div>
</div>
<!-- 弹出层 删除 -->
<div class="popping sty350" id="tag_del" style="display:none;">
    <div class="popping_title">
        <h2>删除</h2>
        <div class="closed" onclick="Popup.closed('tag_del')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <h3>您确定要将此标签删除？</h3> 
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('tag_del')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('tag_del')" />
                </div>
            </div>
         </div>
    </div>
    
    <div class="popping_title">
        <h2>删除成功</h2>
        <div class="closed" onclick="Popup.closed('tag_del')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
            <div class="pop_infocon">
                <h3>此订购说明已经被删除！</h3>
            </div>
            <div class="pop_submit_con">
                <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('tag_del')" />
            </div>
    </div>
    
    <div class="popping_title">
        <h2>删除失败</h2>
        <div class="closed" onclick="Popup.closed('tag_del')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
            <div class="pop_infocon">
                <h3>有在售商品使用此标签，无法删除！</h3>
            </div>
            <div class="pop_submit_con">
                <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('tag_del')" />
            </div>
    </div>
</div>
<?php
}
?>
<!-- 弹出层 删除 -->
<div class="popping sty350" id="dict_del" style="display:none;">
    <div class="popping_title">
        <h2>删除</h2>
        <div class="closed" onclick="Popup.closed('dict_del')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <h3>您确定要将此信息删除？</h3> 
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="dict_del();Popup.closed('dict_del')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('dict_del')" />
                </div>
            </div>
         </div>
    </div>
</div>
<div class="popping sty350" id="tag_del" style="display:none;">
    <div class="popping_title">
        <h2>删除</h2>
        <div class="closed" onclick="Popup.closed('tag_del')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="status_con">
                <h3>您确定要将此标签删除？</h3> 
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('tag_del')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('tag_del')" />
                </div>
            </div>
         </div>
    </div>
</div>