<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns:wb="http://open.weibo.com/wb">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>花范儿--注册</title>
<link href="style/global.css" rel="stylesheet" type="text/css" />
<link href="style/index.css" rel="stylesheet" type="text/css" />
<script language="javascript" src="script/jquery-1.7.1.min.js"></script>
<script language="javascript" src="script/layout.js"></script>
<script language="javascript" src="script/login.js"></script>
<script src="http://tjs.sjs.sinajs.cn/open/api/js/wb.js?appkey=2995335930" type="text/javascript" charset="utf-8"></script>
<script src="//mat1.gtimg.com/app/openjs/openjs.js"></script>
</head>

<body>
<!-- 网站头部 -->
<?php include_once PATH_INC . '/head.inc'; ?>
<!-- 注册 -->
<div class="reg_login_main">
	<div class="reg_main">
      <div class="reg_l">
      	<h1>注册成为花范儿会员</h1>
        <div class="reg_cont">
            <div class="reg_input">
            	<dl>
                	<dd><div class="reg_tit">
                            <label>邮箱</label>
                            <span class="reg_error" id="reg_email_error" style="display:none">邮箱格式错误</span>
                        </div>
                    	<p><input name="reg_email" id="reg_email" type="text" class="rl_input" tabindex="1"/></p>
                    </dd>
                    <dd><div class="reg_tit"><label>密码</label>
                        <!--<span class="strength"><i>密码强度</i><em class="str_0"></em></span>-->
                        <span class="reg_error" id="reg_pwd_error" style="display:none">密码长度不够6位</span>
                        </div>
                    	<p><input name="reg_pwd" id="reg_pwd" type="password" class="rl_input" tabindex="2"/></p>
                    </dd>
                    <dd><div class="reg_tit"><label>姓名</label></div>
                        <span class="reg_error" id="reg_name_error" style="display:none">姓名不能为空</span>
                    	<p><input name="reg_name" id="reg_name" type="text" class="rl_input" tabindex="3"/></p>
                    </dd>
                    <dd><div class="reg_tit"><label>手机</label>
                        <span class="reg_error" id="reg_mobile_error" style="display:none">手机号码格式错误</span></div>
                    	<p><input name="reg_mobile" id="reg_mobile" type="text" onkeydown="EnterReg(event,'<?php echo Tools::getValue('id')?Tools::getValue('id'):0; ?>')" class="rl_input" tabindex="4"/></p>
                    </dd>
                    <dd><input name="reg_license" id="reg_license" type="checkbox" value="" checked class="mr5" tabindex="5"/>
                        <label>我已阅读并同意<a href="service.php">《服务条款》</a></label></dd>
                    <dd>
                        <a href="javascript:void(0)" class="btn_reg" tabindex="6" onclick="Register('<?php echo Tools::getValue('id'); ?>')">
                            立即注册
                        </a>
                        <div class="reg_tit">
                            <span id="reg_error1" class="reg_error" style="display:none">注册失败</span>
                            <span id="reg_error2" class="reg_error" style="display:none">此账号已被注册</span>
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
