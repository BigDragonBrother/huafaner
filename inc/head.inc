<!-- 网站头部 -->
<div class="header_top">
    <div class="header">
        <div class="logo"><a href="index.php"><img src="images/logo.jpg"  alt="返回花范儿首页" title="返回花范儿首页" /></a></div>
        <div class="top_banner"><img src="images/banner.jpg" /></div>
    </div>
</div>
<!-- 菜单导航 -->
<?php
    $url = array_reverse(split('/', $_SERVER['PHP_SELF']));
    $file_name = $url[0];
?>
<div class="nav" style="<?php echo $file_name=='login.php'||$file_name=='register.php'?"display:none":""; ?>">
    <div class="nav_login">
        <ul class="nav_more">
            <li class="<?php echo $file_name=='index.php'?"selected":""; ?>">
                <a href="index.php">首页</a></li>
            <li class="nav_line"></li>
            <li class="<?php echo ($file_name=='list.php'&Tools::getValue('type')=='')||$file_name=='prod.php'?"selected":""; ?>">
                <a href="list.php">那些花</a></li>
            <li class="nav_s <?php echo $file_name=='list.php'&Tools::getValue('type')=='11'?"selected":""; ?>">
                <a href="list.php?type=11">鲜花</a></li>
            <li class="nav_s <?php echo $file_name=='only.php'?"selected":""; ?>">
                <a href="only.php">故事订花</a></li>
            <li class="nav_s <?php echo $file_name=='list.php'&Tools::getValue('type')=='13'?"selected":""; ?>">
                <a href="list.php?type=13">植物</a></li>
            <li class="nav_line"></li>
            <li class="<?php echo $file_name=='sub.php?id=7'?"selected":""; ?>">
                <a href="sublist.php">专题活动</a></li>
            <li class="nav_line"></li>
            <li><a href="http://blog.huafaner.com" target="_blank">花范儿故事</a></li>
        </ul>
        <div class="tel"><img src="images/tel.gif" alt="010-64361192" title="010-64361192" /></div>
        <div class="login" style="<?php echo isset($_COOKIE['user_name'])?"display:none":""; ?>">
            <a href="register.php">注册</a><span class="point"></span><a href="login.php">登录</a>
        </div>
        <div class="login pos_re" style="<?php echo isset($_COOKIE['user_name'])?"":"display:none"; ?>">
            <div class="logins">
                <?php
                    if(isset($_COOKIE['user_name']))
                    {
                        $user_name = $_COOKIE['user_name'];
                        //$username_arr = explode('@',$_COOKIE['user_name']);
                        //if(count($username_arr)==2)
                        //{
                        //    $user_name=$username_arr[0];
                        //}
                        //else
                        //{
                        //    $user_name=substr($_COOKIE['user_name'],0,2).'*******'.substr($_COOKIE['user_name'],9,2);
                        //}
                        if(strlen($user_name)>12)
                        {
                            echo substr($user_name,0,12),'...';
                        }
                        else
                        {
                            echo $user_name;
                        }
                    }
                ?>
            </div>
            <div class="logininfo">
                <ul>
                    <li><a href="user.php?m=user_info">个人资料</a></li>
                    <li><a href="user.php?m=user_order">我的订单</a></li>
                    <li><a href="user.php?m=user_addr">收花地址</a></li>
                    <li><a href="user.php?m=user_coupon">我的礼券</a></li>
                    <li><a href="user.php?m=user_like">我的最爱</a></li>
                    <li><a href="javascript:void(0)" onclick="Logout()">退出</a></li>
                </ul>
            </div>
        </div>
    </div>
</div>