<div class="content" style="margin-top:15px;">
	<h1>个人资料</h1>
	<div class="detailed_info">
    	<form>
        <div class="edit">
            <h4 class="line">修改登录名</h4>
            <dl class="input_list">
                <dd>
                    <label for="b1"  class="textleft">当前登录名：</label>
                    <em id="user_name"><?php echo $_COOKIE['user_name']; ?></em>
                </dd>
                <dd>
                    <label for="b2" class="textleft">登录密码：</label>
                    <input name="user_pwd" type="password" id="user_pwd" class="inputtext sty160" />
                    <div class="error" id="user_pwd_error" style="display:none">请输入登录密码</div>
                </dd>
                <dd>
                    <label for="b2" class="textleft">新登录名：</label>
                    <input name="user_name_new" type="text" id="user_name_new" class="inputtext sty160" />
                    <div class="error" id="user_name_new_error" style="display:none">请输入新的登录名</div>
                    <div class="error" id="user_name_new_error1" style="display:none">登录名已被占用</div>
                    <div class="error" id="user_name_new_error2" style="display:none">登录名必须是邮箱或者手机号</div>
                    <div class="error" id="user_name_new_error3" style="display:none">新登录名更新失败</div>
                </dd>
            </dl>
            <div class="error" id="user_name_success" style="display:none">新登录名更新成功</div>
            <div class="editbuy pl140">
                <a href="javascript:void(0)" onclick="Edit_name()" class="sty120">
                    <p>保  存</p>
                </a>
            </div>
        </div>
        </form>
    </div>
</div>
<div class="clearer"></div>
