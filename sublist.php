<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/subBll.inc';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>花范儿--专题活动</title>
<link href="style/global.css" rel="stylesheet" type="text/css" />
<link href="style/index.css" rel="stylesheet" type="text/css" />
<script language="javascript" src="script/jquery-1.7.1.min.js"></script>
<script language="javascript" src="script/layout.js"></script>
</head>
<body>
<!-- 网站头部 -->
<?php include_once PATH_INC . '/head.inc'; ?>
<!-- 专题详情 -->
<div class="ind_main">
	<h2>专题活动</h2>
</div>
<?php
    $d_var=designBll::get_design('sublist');
    $design=json_decode($d_var['d_var'],true);
    
    foreach ($design['poster'] as $k => $v) 
    {
        if($v['poster_pic']==""||$v['poster_sub']=="undefined")
            continue;
        $sub=subBll::getByid($v['poster_sub']);
?>
<div class="ind_main mb_15">
    <div class="hurdle">
    	<!-- 左侧专题图片 -->
		<div class="hurdle_l">
        	<img src="<?php echo $v['poster_pic']; ?>" style="width:628px;height:195px"/>
        </div>
        <!-- 右侧专题基本信息 -->
        <div class="hurdle_r">
            <h2><?php echo $sub['sub_name']; ?></h2>
            <p class="text_label">标签：
                <?php
                    echo $sub['sub_tag'];
                    //$tags = subBll::getSubTagBySubid($v['poster_sub']);
                    //foreach ($tags as $k => $value) {
                    //    echo "<a href=\"#\">&lt;",$value['dict_name'],"&gt;</a>";
                    //}
                ?>
            </p>
            <p class="text_h"><?php echo $sub['sub_desc']; ?></p>
            <div class="share_sub">
            	<p><span>分享：</span>
                    <a class="sina" href="#" title="新浪"></a>
                    <a class="qq" href="#" title="QQ"></a>
                    <a class="renren" href="#" title="人人"></a>
                    <a class="douban" href="#" title="豆瓣"></a>
                </p>
            	<div class="btn_info"><a href="sub.php?id=<?php echo $sub['sub_id']; ?>">查看详情</a></div>
            </div>
        </div>
    </div>    
</div>
<?php
    }
?>
<!-- 网站底部 -->
<?php include_once PATH_INC . '/foot.inc'; ?>
</body>
</html>
