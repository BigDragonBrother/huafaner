<?php
include_once 'conf.inc';
include_once PATH_LIB.'/tools.inc';
include_once PATH_LIB.'/CreatMiniature.inc';

if ($_FILES["pic"]["error"] > 0) 
{
    echo json_encode("上传失败");
    return;
}

$pic_type=strtolower(substr(strrchr($_FILES["pic"]["name"], '.'), 1));
if(!in_array($pic_type, Conf::$picArr))
{
    echo json_encode("图片格式不对");
    return;
}

$pic_name=  'picture/'.date("YmdGis",time()).'.'.$pic_type;
if(count($_POST)>0)
{
    if($_POST['pic_path']=="blog")
        $pic_name= 'picture/blog/'.date("YmdGis",time()).'.'.$pic_type;
}
//$mini_pic_name='picture/'.date("YmdGis",time());
if(move_uploaded_file($_FILES["pic"]["tmp_name"], $pic_name))
{
    //if(Tools::getValue('pic_path')!==''&  file_exists(Tools::getValue('pic_path')))
    //{
    //    unlink(Tools::getValue('pic_path'));
    //}
    
    if (Tools::getValue('pic_type') != 'sub') {
        $cm = new CreatMiniature();
        $cm->SetVar($pic_name, 'file');
        //$cm->PRorate($mini_pic_name . '_310.' . $pic_type, 900, 858);
        //$cm->PRorate($mini_pic_name . '_270.' . $pic_type, 810, 774);
        //$cm->PRorate($mini_pic_name . '_94.' . $pic_type, 282, 270);
    }
    echo json_encode($pic_name);
    return;
}
else
{
    echo false;   
}

?>

