<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/userBll.inc';

if (isset($_COOKIE['user_id'])) {
    $user = userBll::getUserByid($_COOKIE['user_id']);
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>呼朋唤友-花范儿花店</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="script/layout.js"></script>
        <script language="javascript" src="script/Library-min.js"></script>
        <script language="javascript" src="script/main.js"></script>
        <script language="javascript" src="script/jquery.jqtransform.js"></script>
        <script language="javascript">
            $(function(){
                $('form').jqTransform({imgPath:'images'});
                
                if(!getCookie('user_id'))
                {
                    Popup.popping('boolean_login',true);
                }
            });
        </script>
    </head>

    <body>
        <!-- 网站头部 -->
        <?php include_once PATH_INC . '/head.inc'; ?>
        <script>
            $('#friend').attr('class','select');
        </script>

<!-- 邀请好友 -->
<div class="content" style="margin-top:15px;">
    <h1>邀请好友现金券赠送中</h1>
    <div class="invite_con">
        <div class="invite line">
            <h4>邀请好友 共赏花事</h4>
            <div class="clearer"></div>
            <div class="invite_l">
                <dl>
                    <dt>
                        <?php 
                         if($user['user_invite']<5)
                            {
                                echo "还差".(5-$user['user_invite'])."个人哦";
                            }
                        ?></dt>
                    <dd class="rate_<?php 
                    if(!$user['user_invite'])
                        echo 0;
                    else
                        echo $user['user_invite']<=5?$user['user_invite']:5; ?>">
                </dd>
                <!-- 设置rate_0至rate_5会有不同的进度条显示 -->
                </dl>
                <div class="sum">￥20</div>
                <dl>
                    <dt><?php echo $user['user_invite']>=5&$user['user_invite']<10?"还差".(10-$user['user_invite'])."个人哦":""; ?></dt>
                    <dd class="rate_<?php 
                    $speed=0;
                    if($user['user_invite']>=5) 
                        $speed=$user['user_invite']-5;
                    if($speed>5)
                        $speed=5;
                    echo $speed;
                    ?>"></dd>
                </dl>
                <div class="sum">￥50</div>
            </div>
            <div class="invite_r">
                <h6>活动细则</h6>
                <p>邀请5位好友加入花范儿赏花会将获20元现金券一张</p>
                <p>邀请10位好友加入花草集市赏花会将获50元现金券一张</p>
                <p>您可以在<span class="green"><a href="user.php?m=user_coupon">”我的礼券”</a></span>中查询获得的优惠券这些优惠券可以在订单提交过程中使用</p>
            </div>
        </div>
        <div class="link">
            <h4>您的特别邀请链接</h4>
            <h5>复制此链接到微博或者直接发给朋友</h5>
            <div class="clearer"></div>
            <div class="link_text">
                <input name="user_url" id="user_url" class="input_hui" type="text" value="<?php echo $user?Conf::$urlSet['registerurl'].'&id='.$user['user_link']:''; ?>" />
                <div class="btn_center mat_top"><a class="sty120" href="javascript:void(0)" onclick="setCopy()"><p>复制链接</p></a></div>
            </div>
            <div class="clearer"></div>
            <div class="invite_ico">
                <p>您的朋友通过此链接注册成功后，您即可得到优惠券赶快将消息传播出去吧</p>
                <div class="share">
                    <a href="javascript:void((function(s,d,e,r,l,p,t,z,c){var%20f='http://v.t.sina.com.cn/share/share.php?appkey=<?php echo Conf::$appkey['sina'] ?>',u=z||d.location,p=['&url=',e(u),'&title=',e(t||d.title),'&source=',e(r),'&sourceUrl=',e(l),'&content=',c||'gb2312','&pic=',e(p||'')].join('');function%20a(){if(!window.open([f,p].join(''),'mb',['toolbar=0,status=0,resizable=1,width=440,height=430,left=',(s.width-440)/2,',top=',(s.height-430)/2].join('')))u.href=[f,p].join('');};if(/Firefox/.test(navigator.userAgent))setTimeout(a,0);else%20a();})(screen,document,encodeURIComponent,'','','图片链接','#花范儿花店#跟我一起逛逛花范儿看看那些美丽的花草','<?php echo Conf::$urlSet['loginurl'], '?id=', $user['user_link'] ?>','gb2312'));" class="sina">分享至微博</a>
                    <a href="javascript:void(0)" onclick="postToWb('<?php echo Conf::$appkey['qq']; ?>','<?php echo Conf::$urlSet['loginurl'], '?id=', $user['user_link'] ?>','跟我一起逛逛花范儿看看那些美丽的花草');return false;" class="qq" title="QQ"></a>
                    <a href="javascript:void((function(s,d,e){if(/renren\.com/.test(d.location))return;var f='http://share.renren.com/share/buttonshare?link=',u='<?php echo Conf::$urlSet['loginurl'], '?id=', $user['user_link'] ?>',l=d.title,p=[e(u),'&title=',e(l)].join('');function%20a(){if(!window.open([f,p].join(''),'xnshare',['toolbar=0,status=0,resizable=1,width=626,height=436,left=',(s.width-626)/2,',top=',(s.height-436)/2].join('')))u.href=[f,p].join('');};if(/Firefox/.test(navigator.userAgent))setTimeout(a,0);else%20a();})(screen,document,encodeURIComponent));" class="renren" title="人人"></a>
                    <a href="javascript:void(function(){var d=document,e=encodeURIComponent,s1=window.getSelection,s2=d.getSelection,s3=d.selection,s=s1?s1():s2?s2():s3?s3.createRange().text:'',r='http://www.douban.com/recommend/?url='+e(d.location.href)+'&title='+e(d.title)+'&sel='+e(s)+'&v=1',x=function(){if(!window.open(r,'douban','toolbar=0,resizable=1,scrollbars=yes,status=1,width=450,height=330'))location.href=r+'&r=1'};if(/Firefox/.test(navigator.userAgent)){setTimeout(x,0)}else{x()}})()" class="dou" title="豆瓣"></a>
                </div>
        </div>
    </div>
    </div>
</div>
<div class="clearer"></div>


        <!--  网站底部  -->
        <?php include_once PATH_INC . '/foot.inc'; ?>

    </body>

</html>

