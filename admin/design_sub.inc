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
        <div class="poster">
            <div class="imgpic sty500">
                <!-- <a href="javascript:void(0)" onclick="Popup.popping('add_poster',true)">点击上传专题图片</a> -->
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
    <input type="button" value="提 交" class="loginbtn" />
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