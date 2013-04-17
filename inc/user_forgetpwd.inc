<?php
$user_id=Tools::getValue('user_id');
$user_link=Tools::getValue('user_link');
?>
<!--忘记密码-->
<div class="ind_main" style="<?php echo $user_link==""?"":"display:none;"; ?>" id="forgetpwd">
	<h1>个人资料</h1>
	<div class="detailed_info">
    	<form>
        <div class="edit">
            <h4 class="line">忘记密码</h4>
            <dl class="input_list">
                <dd><label for="b1" class="textleft">注册邮箱：</label>
                    <input name="user_name" type="text" id="user_name" class="inputtext sty200" />
                    <div id="user_name_error" class="error" style="display:none">请填写邮箱或手机号</div>
                    <div id="user_name_error1" class="error" style="display:none">这个账号没有注册过</div>
                    <div id="user_name_error2" class="error" style="display:none">暂不支持手机账号找回密码</div>
                </dd>
            </dl>
            <div class="editbuy pl140"><a href="javascript:void(0)" onclick="forgetpwd(0)" class="sty120"><p>下一步</p></a></div>
        </div>
        </form>
    </div>
</div>
<!--忘记密码1-->
<div class="ind_main" style="display:none;" id="forgetpwd1">
    <h1>个人资料</h1>
    <div class="detailed_info">
        <form>
        <div class="edit">
            <h4 class="line">忘记密码</h4>
            <dl class="input_list pad20">
                <dd id='user_email'>确认邮件已经发送至邮箱：</dd>
            </dl>
            <!--<div class="editbuy pl20"><a href="" class="sty120"><p>查看邮箱</p></a></div>-->
            <div class="clearer"></div>
            <div class="bare line"></div>
            <div class="help_password">
                <p>没有收到确认邮件？</p>
                <p>-试试到邮箱中的垃圾邮件、广告邮件目录中找找</p>
                <p>-或者：<a href="javascript:void(0)" onclick="sendMail($('#user_email').val())">重新发送邮件</a></p>
            </div>
        </div>
        </form>
    </div>
</div>

<!--忘记密码2-->
<div class="ind_main" style="display:none;" id="forgetpwd2">
    <h1>个人资料</h1>
    <div class="detailed_info">
        <form>
        <div class="edit">
            <h4 class="line">忘记密码</h4>
            <dl class="input_list">
                <dd><label class="textleft">您的手机号码：</label><em id="user_name_2"></em></dd>
                <dd class="pl120">
                    <div class="verification"><a href="#" class="sty120"><p>免费获取验证码</p></a></div>
                    <div class="again"><a href="#" class="sty120"><p>59秒可重新发送</p></a></div>
                </dd>
                <dd><label for="b3" class="textleft">验证码：</label><input name="" type="text" id="b3" class="inputtext sty160" /><div class="error">验证码已过期，请重新获取验证码</div></dd>
            </dl>
            <div class="editbuy pl140"><a href="javascript:void(0)" class="sty120"><p>下一步</p></a></div>
        </div>
        </form>
    </div>
</div>

<!--忘记密码3-->
<div class="ind_main" style="<?php echo $user_link==""?"display:none;":""; ?>" id="forgetpwd3">
    <h1>个人资料</h1>
    <div class="detailed_info">
        <form>
        <div class="edit">
            <h4 class="line">重置密码</h4>
            <input type="hidden" id="user_id_reset" value="<?php echo $user_id; ?>" />
            <input type="hidden" id="user_link_reset" value="<?php echo $user_link; ?>" />
            <dl class="input_list">
                <dd>
                    <label for="b1"  class="textleft">新密码：</label>
                    <input name="user_pwd" type="password" id="user_pwd" class="inputtext sty160" />
                    <div id="user_pwd_error" class="error" style="display:none">请填写新密码</div>
                    <div id="user_pwd_error1" class="error" style="display:none">密码必须长于6位</div>
                </dd>
                <dd>
                    <label for="b2" class="textleft">确认新密码：</label>
                    <input name="user_pwd_con" type="password" id="user_pwd_con" class="inputtext sty160" />
                    <div id="user_pwd_con_error" class="error" style="display:none">两次密码输入不一致，请重新输入</div></dd>
            </dl>
            <div class="editbuy pl140">
                <a href="javascript:void(0)" class="sty120" onclick="forgetpwd(3)"><p>确   定</p></a>
            </div>
        </div>
        </form>
    </div>
</div>

<!--忘记密码4-->
<div class="ind_main" style="display:none;" id="forgetpwd4">
    <h1>个人资料</h1>
    <div class="detailed_info">
        <form>
        <div class="edit">
            <h4 class="line">重置密码</h4>
            <ul>
                <li id="reset_success">新密码已经设置成功，请<a href="<?php echo Conf::$urlSet['loginurl']; ?>">登录</a></li>
                <li id="reset_fail">重置密码链接不对或已过期，请<a href="user.php?m=forgetpwd">重新找回密码</a></li>
            </ul>
        </div>
        </form>
    </div>
</div>

<div class="clearer"></div>