<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/subBll.inc';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>活动专题-花范儿花店</title>
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
            <a href="sub.php?id=<?php echo $sub['sub_id']; ?>">
        	   <img src="<?php echo $v['poster_pic']; ?>" style="width:628px;height:195px"/>
            </a>
        </div>
        <!-- 右侧专题基本信息 -->
        <div class="hurdle_r">
            <h2><a href="sub.php?id=<?php echo $sub['sub_id']; ?>"><?php echo $sub['sub_name']; ?></a></h2>
            <p class="text_label">标签：
                <?php
                    echo $sub['sub_tag'];
                    //$tags = subBll::getSubTagBySubid($v['poster_sub']);
                    //foreach ($tags as $k => $value) {
                    //    echo "<a href=\"#\">&lt;",$value['dict_name'],"&gt;</a>";
                    //}
                ?>
            </p>
            <p class="text_h">
                <a href="sub.php?id=<?php echo $sub['sub_id']; ?>">
                    <?php echo substr($sub['sub_desc'], 0,85*3) ; ?>
                </a>
            </p>
            <div class="share_sub">
            	<p><span>分享：</span>
                    <a class="sina" href="javascript:void((function(s,d,e,r,l,p,t,z,c){var%20f='http://v.t.sina.com.cn/share/share.php?appkey=<?php echo Conf::$appkey['sina']?>',u=z||d.location,p=['&url=',e(u),'&title=',e(t||d.title),'&source=',e(r),'&sourceUrl=',e(l),'&content=',c||'gb2312','&pic=',e(p||'')].join('');function%20a(){if(!window.open([f,p].join(''),'mb',['toolbar=0,status=0,resizable=1,width=440,height=430,left=',(s.width-440)/2,',top=',(s.height-430)/2].join('')))u.href=[f,p].join('');};if(/Firefox/.test(navigator.userAgent))setTimeout(a,0);else%20a();})(screen,document,encodeURIComponent,'','','<?php echo $v['poster_pic'];?>','#花范儿花店#跟我一起逛逛花范儿看看那些美丽的花草',document.location,'utf-8'));" title="新浪"></a>
                    <a class="qq" href="javascript:void(0)" onclick="postToWb('<?php echo Conf::$appkey['qq']; ?>','','跟我一起逛逛花范儿看看那些美丽的花草','<?php echo $v['poster_pic']; ?>');return false;" title="腾讯"></a>
                    <a class="renren" href="javascript:void((function(s,d,e){if(/renren\.com/.test(d.location))return;var f='http://share.renren.com/share/buttonshare?link=',u=d.location,l=d.title+'跟我一起逛逛花范儿看看那些美丽的花草',p=[e(u),'&title=',e(l)].join('');function%20a(){if(!window.open([f,p].join(''),'xnshare',['toolbar=0,status=0,resizable=1,width=626,height=436,left=',(s.width-626)/2,',top=',(s.height-436)/2].join('')))u.href=[f,p].join('');};if(/Firefox/.test(navigator.userAgent))setTimeout(a,0);else%20a();})(screen,document,encodeURIComponent));" title="人人"></a>
                    <a class="douban" href="javascript:void(function(){var d=document,e=encodeURIComponent,s1=window.getSelection,s2=d.getSelection,s3=d.selection,s=s1?s1():s2?s2():s3?s3.createRange().text:'',r='http://www.douban.com/recommend/?url='+e(d.location.href)+'&title='+e(d.title+'跟我一起逛逛花范儿看看那些美丽的花草')+'&sel='+e(s)+'&v=1',x=function(){if(!window.open(r,'douban','toolbar=0,resizable=1,scrollbars=yes,status=1,width=450,height=330'))location.href=r+'&r=1'};if(/Firefox/.test(navigator.userAgent)){setTimeout(x,0)}else{x()}})()" title="豆瓣"></a>
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
