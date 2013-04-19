<?php
include_once PATH_BLL.'/prodBll.inc';
include_once PATH_BLL.'/subBll.inc';
$prod_list =prodBll::getProdTopN(100);
$sub_list=subBll::getAllSub();
?>
<div class="title">
	<h2>专题活动页维护</h2>
	<span class="btn_top">
    	<input type="button" value="预 览" class="loginbtn" />
    	<input type="button" value="提 交" class="loginbtn" />
    </span>
</div>
<div class="content">
    <div class="block">
        <?php
            for ($i=1; $i<=6 ; $i++) { 
        ?>
        <div class="poster" id="poster_<?php echo $i; ?>">
            <div class="imgpic sty500">
                <a href="javascript:void(0)" onclick="poster_cur=$(this).parent().parent().attr('id');Popup.popping('add_poster',true)">
                    <img id="pic_poster" alt="点击上传专题图片" style="height:143px;width:500px;" src=""/>
                </a>
            </div>
            <div class="operating">
                <input type="button" value="置 顶" class="loginbtn" onclick="Popup.popping('top_special',true)" />
                <input type="button" value="前 移" class="loginbtn" onclick="Popup.popping('forward_special',true)" />
                <input type="button" value="后 移" class="loginbtn" onclick="Popup.popping('forward_special',true)" />
            </div>
        </div>
        <?php
            }
        ?>
    </div>
</div>
<div class="clearer"></div>
<div class="btn_submit">
    <input type="button" value="预 览" class="loginbtn" />
    <input type="button" value="提 交" class="loginbtn" onclick="design_sublist_commit()"/>
</div>

<!-- 弹出层 置顶 -->
<div class="popping sty350" id="top_special" style="display:none;">
	<div class="popping_title">
    	<h2>置顶</h2>
        <div class="closed" onclick="Popup.closed('top_special')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
    	<div class="pop_infocon">
        	<h3>您确定是将此位置上移一个么？</h3>
     	</div>
         
        <div class="pop_submit_con">
            <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('top_special')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('top_special')" />
        </div>
    </div>
</div>
<!-- 弹出层 移动前后 -->
<div class="popping sty350" id="forward_special" style="display:none;">
	<div class="popping_title">
    	<h2>上移</h2>
        <div class="closed" onclick="Popup.closed('forward_special')"><a href="javascript:void(0)">×</a></div>
    </div>
    <div class="popping_content">
    	<div class="pop_infocon">
        	<h3>您确定是将此位置上移一个么？</h3>
     	</div>
         
        <div class="pop_submit_con">
            <input type="button" value="确 定" class="loginbtn" onclick="Popup.closed('forward_special')" />
            <input type="button" value="取 消" class="loginbtn" onclick="Popup.closed('forward_special')" />
        </div>
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