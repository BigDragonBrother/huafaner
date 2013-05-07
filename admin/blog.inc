<?php
include_once (PATH_BLL."/blogBll.inc");
$blog_id=Tools::getValue('id');
if($blog_id)
{
    $blog=blogBll::get_blog($blog_id);
}
else
{
    $blog=false;
}
?>
<div class="content">
	<div class="block">
		博客标题:
        <input id="blog_title" value="<?php echo $blog?$blog["blog_title"]:''; ?>" type="text"/>
	</div>
	<div class="block">
        <form id="pic_blog_index" name="pic_blog_index" action="picupload.php" method="post" enctype="multipart/form-data">
            首页图片:
            <img src="<?php echo $blog?$blog["blog_index"]:''; ?>" id="pic_index" name="pic_index" style="width:219px;height:171px;"/>
            <input type="hidden" id="pic_path" name="pic_path" value="blog" />
            <input type="file" id="pic" name="pic" onchange="pic_blog=0;blogpicupload('pic_blog_index')"/>
        </form>
    </div>
    <div class="block">
        <form id="pic_blog" name="pic_blog" action="picupload.php" method="post" enctype="multipart/form-data">
            上传图片:
            <input type="hidden" id="pic_path" name="pic_path" value="blog" />
            <input type="file" id="pic" name="pic" onchange="pic_blog=1;blogpicupload('pic_blog')"/>
        </form>
    </div>
    <div class="block">
        <textarea name="editor1" id="editor1" class="ckeditor"><?php echo $blog?$blog["blog_content"]:''; ?></textarea>
	</div>
</div>
<div class="btn_submit">
    <input type="button" value="提 交" class="loginbtn" onclick="add_blog(<?php echo $blog?$blog["blog_id"]:''; ?>)" />
</div>

<script type="text/javascript" src="./ckeditor/ckeditor.js"></script>
<script type="text/javascript">
var editor=CKEDITOR.replace("editor1");
var pic_blog="";
function blogpicupload(obj)
{
    var options = {
    dataType:'json', 
    type:'post',
    url:'picupload.php',
    success:blogPicRes,
    error : function(XMLResponse) {  
                    alert(XMLResponse.responseText);  
                    alert('操作失败！');  
    } 
    };
    $('#'+obj).ajaxSubmit(options);
}
function blogPicRes(data)
{
    if(pic_blog==0)
    {
        $('#pic_index').attr("src",data);
    }
    if(pic_blog==1)
    {
        editor.insertHtml('<img src="'+data+'"/>');
    }
}
function add_blog(blog_id)
{
	$.ajax({
            url:"dbport.php",
            data:{
                action:"add_blog",
                blog_id:blog_id,
                blog_title:$('#blog_title').val(),
                blog_index:$('#pic_index').val(),
              	blog_content:editor.getData()
            },
            type: "POST",
            dataType: "json",
            success: function(data)
            {
            	if(data)
            	{
            		alert('文章发表成功');
            	}
           		else
           		{
           			alert('文章发表失败');	
           		}
            }
        });
}
</script>