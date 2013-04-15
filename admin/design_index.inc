<?php
include_once PATH_BLL.'/prodBll.inc';
include_once PATH_BLL.'/subBll.inc';
$prod_list =prodBll::getProdTopN(100);
$sub_list=subBll::getSubList();
?>
<div class="title">
	<h2>首页维护</h2>
	<span class="btn_top">
    	<input type="button" value="预 览" class="loginbtn" />
    	<input type="button" value="提 交" class="loginbtn" />
    </span>
</div>
<div class="content">
	<div class="block">
    	<h3>导航维护</h3>
        <div class="imgpic sty500">
        	<a href="javascript:void(0)" onclick="pic='_nav';Popup.popping('add_pic',true)">
                <img id="pic_nav" alt="点击上传图片" style="height:143px;width:500px;" src=""/>
            </a>
        </div>
    </div>
    <div class="clearer"></div>
    <div class="block">
    	<h3>海报维护</h3>
        <div class="poster" id="poster_1">
            <div class="imgpic sty500">
                <a href="javascript:void(0)" onclick="poster_cur=$(this).parent().parent().attr('id');Popup.popping('add_poster',true)">
                    <img id="pic_poster" alt="点击上传图片" style="height:143px;width:500px;" src=""/>
                </a>
            </div>
            <div class="operating">
                <input type="button" value="增加海报" class="loginbtn" onclick="design_add_poster(this)" />
                <input type="button" value="删除此海报" class="loginbtn" onclick="poster_cur=$(this).parent().parent().attr('id');Popup.popping('del_poster',true)" />
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
            </div>
        </div>
    </div>
    <div class="clearer"></div>
    <div class="block">
    	<h3>最新设计</h3>
        <div class="new_design">
            <div class="imgpic sty300">
                <a href="javascript:void(0)" onclick="pic='_file_poster1';Popup.popping('file_poster',true)">
                    <img id="pic_file_poster1" alt="点击上传图片" style="height:143px;width:300px;" src=""/>
                </a>
                <input type="hidden" id="desc_file_poster1" value="" />
                <input type="hidden" id="prod_file_poster1" value="" />
            </div>
            <div class="imgpic sty300">
                <a href="javascript:void(0)" onclick="pic='_file_poster2';Popup.popping('file_poster',true)">
                    <img id="pic_file_poster2" alt="点击上传图片" style="height:143px;width:300px;" src=""/>
                </a>
                <input type="hidden" id="desc_file_poster2" value="" />
                <input type="hidden" id="prod_file_poster2" value="" />
            </div>
        </div>
        <div class="clearer"></div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com1';Popup.popping('file_com',true)">
                    <img id="pic_file_com1" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com2';Popup.popping('file_com',true)">
                    <img id="pic_file_com2" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com3';Popup.popping('file_com',true)">
                    <img id="pic_file_com3" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
    </div>
    <div class="clearer"></div>
    <div class="block">
    	<h3>经典热卖</h3>
        <div class="new_design">
            <div class="imgpic sty300">
                <a href="javascript:void(0)" onclick="pic='_file_poster3';Popup.popping('file_poster',true)">
                    <img id="pic_file_poster3" alt="点击上传图片" style="height:143px;width:300px;" src=""/>
                </a>
                <input type="hidden" id="desc_file_poster3" value="" />
                <input type="hidden" id="prod_file_poster3" value="" />
            </div>
            <div class="imgpic sty300">
                <a href="javascript:void(0)" onclick="pic='_file_poster4';Popup.popping('file_poster',true)">
                    <img id="pic_file_poster4" alt="点击上传图片" style="height:143px;width:300px;" src=""/>
                </a>
                <input type="hidden" id="desc_file_poster4" value="" />
                <input type="hidden" id="prod_file_poster4" value="" />
            </div>
        </div>
        <div class="clearer"></div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com4';Popup.popping('file_com',true)">
                    <img id="pic_file_com4" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com5';Popup.popping('file_com',true)">
                    <img id="pic_file_com5" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com6';Popup.popping('file_com',true)">
                    <img id="pic_file_com6" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
        <div class="clearer"></div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com7';Popup.popping('file_com',true)">
                    <img id="pic_file_com7" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com8';Popup.popping('file_com',true)">
                    <img id="pic_file_com8" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />                    
            </div>
        </div>
        <div class="file_com">
            <div class="imgpic sty196">
                <a href="javascript:void(0)" onclick="prod_cur='_file_com9';Popup.popping('file_com',true)">
                    <img id="pic_file_com9" alt="选择商品" style="height:143px;width:196px;" src=""/>
                </a>
            </div>
            <div class="mobile">
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_poster',true)" />
            </div>
        </div>
    </div>
</div>
<div class="clearer"></div>
<div class="btn_submit">
    <input type="button" value="预 览" class="loginbtn" />
    <input type="button" value="提 交" class="loginbtn" onclick="design_index_commit()" />
</div>


<!-- 弹出层 导航维护 -->
<div class="popping sty500" id="add_pic" style="display:none;">
	<div class="popping_title">
    	<h2>导航维护</h2>
        <div class="closed" onclick="Popup.closed('add_pic')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
        <form id="form_pic_nav" name="form_pic_nav" action="picupload.php" method="post" enctype="multipart/form-data">
        	<div class="con_list">
                <span class="pop_tit">选择文件：</span>
                <p><input id="pic" name="pic" type="file" /></p></div>
            <div class="pop_submit">
                <input type="button" value="上 传" class="loginbtn" onclick="fileupload('form_pic_nav');Popup.closed('add_pic')" />
                <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('add_pic')" />
            </div>
        </form>
    </div>
</div>
<!-- 弹出层 上传海报 -->
<div class="popping sty500" id="add_poster" style="display:none;">
	<div class="popping_title">
    	<h2>上传海报</h2>
        <div class="closed" onclick="Popup.closed('add_poster')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
        <form id="form_pic_poster" name="form_pic_poster" action="picupload.php" method="post" enctype="multipart/form-data">
    	    <div class="con_list">
                <span class="pop_tit">选择文件：</span>
                <p><input id="pic" name="pic" type="file" /></p>
            </div>
            <div class="con_list">
                <span class="pop_tit">选择专题：</span>
                <div class="pad_l120">
                    <div class="sel_com">
                            <input name="poster_sub" type="radio" value="1" />
                            <div class="img_com">sub1</div>
                    </div>
                    <div class="sel_com">
                            <input name="poster_sub" type="radio" value="2" />
                            <div class="img_com">sub2</div>
                    </div>
                    <?php
                        foreach ($sub_list as $k => $v) {
                    ?>
                        <div class="sel_com">
                            <input name="poster_sub" type="radio" value="<?php echo $v['sub_id']; ?>" />
                            <div class="img_com"><?php echo $v['sub_name']; ?></div>
                        </div>
                    <?php
                        }
                    ?>
                </div>
            </div>
            <div class="pop_submit">
                <input type="button" value="上 传" class="loginbtn" onclick="fileupload('form_pic_poster');Popup.closed('add_poster')" />
                <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('add_poster')" />
            </div>
        </form>
    </div>
</div>
<!-- 弹出层 上传小海报 -->
<div class="popping sty600" id="file_poster" style="display:none;">
	<div class="popping_title">
    	<h2>上传小海报</h2>
        <div class="closed" onclick="Popup.closed('file_poster')"><a href="javascript:void(0)">×</a></div>
    </div>
     <div class="content">
        <form id="form_pic_file_poster" name="form_pic_file_poster" action="picupload.php" method="post" enctype="multipart/form-data">
        <div class="con_list">
            <span class="con_tit">上传图片：</span>
            <p><input id="pic" name="pic" type="file" /></p>
        </div>
        </form>
        <div class="con_list">
            <span class="con_tit">图片描述：</span>
            <p><input id="file_poster_desc" class="same" type="text" /></p>
        </div>
        <div class="con_list">
        	<span class="con_tit">选择商品：</span>
        	<div class="pad_l120">
                <?php
                    foreach ($prod_list as $k => $v) {
                ?>
                    <div class="sel_com">
                        <input name="file_poster_prods" type="radio" value="<?php echo $v['prod_id']; ?>" />
                        <div class="img_com"><?php echo $v['prod_name']; ?></div>
                    </div>
                <?php
                    }
                ?>
            </div>
        </div>
     </div>
    <div class="pop_submit_con">
        <input type="button" value="确 定" class="loginbtn" onclick="fileupload('form_pic_file_poster');Popup.closed('file_poster')" />
        <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('file_poster')" />
    </div>
</div>
<!-- 弹出层 商品上传 -->
<div class="popping sty500" id="file_com" style="display:none;">
	<div class="popping_title">
    	<h2>商品上传</h2>
        <div class="closed" onclick="Popup.closed('file_com')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="pop_infocon">
        <div class="pad_20">
            <?php
                foreach ($prod_list as $k => $v) {
            ?>
                <div class="sel_com wid33">
                    <input name="file_com_prods" type="radio" value="<?php echo $v['prod_id']; ?>" />
                    <div class="img_com"><?php echo $v['prod_name']; ?></div>
                </div>
            <?php
                }
            ?>
            </div>
        </div>
     <div class="clearer"></div>
    <div class="pop_submit_con">
        <input type="button" value="确 定" class="loginbtn" onclick="design_add_prod();Popup.closed('file_com')" />
        <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('file_com')" />
    </div>
</div>
<!-- 弹出层 删除海报 -->
<div class="popping sty350" id="del_poster" style="display:none;">
    <div class="popping_title">
        <h2>删除海报</h2>
        <div class="closed" onclick="Popup.closed('del_poster')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="pop_infocon">
            <h3>你确定是要删除此海报么？</h3>
        </div>
    <div class="pop_submit_con">
        <input type="button" value="确 定" class="loginbtn" onclick="$('#'+poster_cur).remove();Popup.closed('del_poster')" />
        <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('del_poster')" />
    </div>
</div>
<!-- 弹出层 移动前后 -->
<div class="popping sty350" id="forward_poster" style="display:none;">
    <div class="popping_title">
        <h2>上移</h2>
        <div class="closed" onclick="Popup.closed('forward_poster')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
         <div class="status">
            <div class="img_icon"><img src="images/icon1.gif" /></div>
            <div class="popping_content">
                <h3>您确定是将此位置上移一个么？</h3> 
                <div class="pop_submit pad_none">
                    <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('forward_poster')" />
                    <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('forward_poster')" />
                </div>
            </div>
         </div>
    </div>
    <div class="popping_title">
        <h2>上移成功</h2>
        <div class="closed" onclick="Popup.closed('forward_poster')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
            <div class="pop_infocon">
                <h3>此海报已经上移成功！</h3>
            </div>
            <div class="pop_submit_con">
                <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('forward_poster')" />
                <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('forward_poster')" />
            </div>
    </div>
</div>