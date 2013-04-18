<?php
include_once PATH_BLL.'/subBll.inc';
include_once PATH_BLL.'/prodBll.inc';

$sub_id=Tools::getValue('id');
if($sub_id)
{
    $sub=subBll::getByid($sub_id);
    $sub_tag=subBll::getTagsBysubid($sub_id);;
}
else
{
    $sub=false;
    $sub_tag=array();
}
?>
<div class="title">
    <h2>发布活动</h2><span>以下均为必填项</span>
</div>
<div class="content">
	<div class="con_list">
        <span class="con_tit">活动名称：</span>
        <p><input id="sub_name" value="<?php echo $sub?$sub['sub_name']:''; ?>" class="same" type="text" /></p>
        <div class="error">请输入活动名称！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">活动描述：</span>
        <p><textarea id="sub_desc" cols="" rows="" class="textarea"><?php echo $sub?$sub['sub_desc']:''; ?></textarea></p>
        <div class="error">请输入活动描述！</div>
    </div>
    <div class="con_list">
        <span class="con_tit">活动标签：</span>
        <p><input id="sub_tag" class="same" type="text" /></p>
        <div class="error">请输入活动标签！</div>
    </div>
    <div class="con_list">
    	<span class="con_tit">活动图片：</span>
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
    	<input type="button" value="发 布" class="loginbtn" onclick="sub_add('pub','<?php echo $sub?$sub['sub_id']:''; ?>')"/>
        <input type="button" value="取 消" class="loginbtn" />
    </div>
</div>
<!-- 弹出层 活动图片 -->
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