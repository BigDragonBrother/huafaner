<div class="content" style="margin-top:15px;">
	<h1>个人资料</h1>
	<div class="detailed_info">
    	<form>
        <div class="edit">
            <h4 class="line">修改密码</h4>
            <dl class="input_list">
                <dd>
                    <label for="b1"  class="textleft">当前密码：</label>
                    <input name="user_pwd" type="password" id="user_pwd" class="inputtext sty160" />
                    <div class="error" id="user_pwd_error" style="display:none">请输入当前密码</div>
                </dd>
                <dd>
                    <label for="b2" class="textleft">新密码：</label>
                    <input name="user_pwd_new" type="password" id="user_pwd_new" class="inputtext sty160" />
                    <div class="error" id="user_pwd_new_error" style="display:none">请输入新密码</div>
                    <div class="error" id="user_pwd_new_error1" style="display:none">新密码至少六位</div>
                </dd>
                <dd>
                    <label for="b2" class="textleft">确认新密码：</label>
                    <input name="user_pwd_con" type="password" id="user_pwd_con" class="inputtext sty160" />
                    <div class="error" id="user_pwd_con_error" style="display:none">请确认新密码</div>
                    <div class="error" id="user_pwd_con_error1" style="display:none">与新密码不符</div>
                </dd>
            </dl>
            <div class="error" id="user_pwd_result" style="display:none">当前密码输入错误</div>
            <div class="error" id="user_pwd_result1" style="display:none">新密码更新失败</div>
            <div class="error" id="user_pwd_result2" style="display:none">新密码更新成功</div>
            <div class="editbuy pl140">
                <a href="javascript:void(0)" onclick="Edit_pwd()" class="sty120">
                    <p>保  存</p>
                </a>
            </div>
        </div>
        </form>
    </div>
</div>
<div class="clearer"></div>
