<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';

$prod_id=Tools::getValue('prod_id');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>花范儿--登录</title>
<link href="style/global.css" rel="stylesheet" type="text/css" />
<link href="style/index.css" rel="stylesheet" type="text/css" />
<script language="javascript" src="script/jquery-1.7.1.min.js"></script>
<script language="javascript" src="script/layout.js"></script>
<script language="javascript" src="script/login.js"></script>
</head>

<body>
<!-- 网站头部 -->
<?php include_once PATH_INC . '/head.inc'; ?>
<!-- 注册 -->
<div class="reg_login_main">
    <div class="reg_main">
      <div class="reg_l">
        <h1>花范儿会员登录</h1>
        <div class="reg_cont">
            <div class="reg_input">
                <dl>
                    <dd>
                        <div class="reg_tit">
                            <label>邮箱</label><span class="reg_error" id="login_email_error" style="display:none">请输入邮箱</span>
                        </div>
                        <p><input name="login_email" id="login_email" type="text" class="rl_input" /></p>
                    </dd>
                    <dd>
                        <div class="reg_tit">
                            <label>密码</label>
                            <span class="reg_error" id="login_pwd_error" style="display:none">请输入密码</span>
                        </div>
                        <p><input name="login_pwd" id="login_pwd" type="password" onkeydown="EnterLogin(event,'<?php echo $prod_id?$prod_id:'0'; ?>')" class="rl_input" /></p>
                    </dd>
                    <dd><input name="" type="checkbox" value="" class="mr5" /><label>下次自动登录</label>
                        <a href="user.php?m=user_forgetpwd" class="fl_r">忘记密码?</a></dd>
                    <dd>
                        <a href="javascript:void(0)" class="btn_reg" onclick="Login(<?php echo $prod_id; ?>)">登&nbsp;&nbsp; 录</a>
                        <div class="reg_tit">
                            <span class="reg_error" id="login_error" style="display:none">用户名密码错误</span>
                        </div>
                    </dd>
                </dl>
            </div>
            
            <?php include_once PATH_INC.'/reg.inc' ?>
         </div>
      </div>
    </div>    
</div>
<div class="reg_login_bot"></div>
<?php include_once PATH_INC . '/foot.inc';?>
</body>
</html>
