<div class="reg_short">
    <?php 
        if(strpos($_SERVER['PHP_SELF'],'register.php')>0)
        {
            echo '<p>已经是花范儿会员，现在<a href="login.php">登录</a></p>';
        }
        else
        {
            echo '<p>还不是花范儿会员，立即<a href="register.php">注册</a></p>';
        }
    ?>
    <p>或者</p>
    <p>您也可以使用第三方账号登录：</p>    
    <wb:login-button type="2,2" onlogin="login" onlogout="logout" class="reg_sina"></wb:login-button>
    <!--<p><a href="javascript:void(0)" class="reg_sina">使用新浪微博登录</a></p>-->
    <p onclick="tqq()"><a href="javascript:void(0)" class="reg_qq">使用腾讯微博登录</a></p>                
    <p><a href="#" class="reg_renren">使用人人账号登录</a></p>
</div>
<script>
T.init({
    appkey:<?php echo Conf::$appkey['qq']?>
});

function tqq()
{
	T.login(function (loginStatus) {
        alert(loginStatus.nick);
    },function (loginError) {
        alert(loginError.message);
});	
}

function login(o) {
    alert(o.screen_name)
}
 
function logout() {
    alert('logout');
}
</script>