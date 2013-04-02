<?php 
    $user= userBll::getUserByid($_COOKIE['user_id']);
?>
<div class="content" style="margin-top:15px;">
    <h1>个人资料</h1>
    <div class="detailed_info">
        <form>
            <div class="edit">
                <h4 class="line">注册信息</h4>
                <ul>
                    <li>
                        <label>登录名：</label>
                        <span><?php echo $_COOKIE['user_name']; ?></span>
                        <p><a href="user.php?m=user_name">修改登录名</a></p>
                    </li>
                    <li>
                        <label>密码：</label>
                        <span>***********</span>
                        <p><a href="user.php?m=user_pwd">修改密码</a></p>
                    </li>
                </ul>
                <!--
                <h4 class="line">个人信息</h4>
                <ul>
                    <li>
                        <label>手机：</label>
                        <span><?php echo isset($_COOKIE['user_mobile']) ? $_COOKIE['user_mobile'] : '&nbsp;'; ?></span>
                        <p><a href="javascript:void(0)" onclick="$('#user_mobile_edit').toggle()">修改手机</a></p>

                    </li>
                    <li>
                        <label>邮箱：</label>
                        <span><?php echo isset($_COOKIE['user_email']) ? $_COOKIE['user_email'] : '&nbsp;'; ?></span>
                        <p><a href="javascript:void(0)" onclick="$('#user_email_edit').toggle()">修改昵称</a></p>
                    </li>
                </ul>
                -->
                <h4 class="line">提醒通知</h4>
                <dl class="line">
                    <dd>
                        <input name="inform_order" id="inform_order" type="checkbox" value="" <?php echo $user['inform_order']?'checked':''; ?>></input>
                        <label>订单处理通知</label>
                    </dd>
                    <dd>
                        <input name="inform_newprod" id="inform_newprod" type="checkbox" value="" <?php echo $user['inform_newprod']?'checked':''; ?> />
                        <label>新品上架通知</label>
                    </dd>
                    <dd>
                        <input name="inform_web" id="inform_web" type="checkbox" value="" <?php echo $user['inform_web']?'checked':''; ?>/>
                        <label>网站更新通知</label>
                    </dd>
                </dl>
            </div>
            <div class="error" id="inform_result" style="display:none">更新失败</div>
            <div class="error" id="inform_result1" style="display:none">更新成功</div>
            <div class="buys"><a href="javascript:void(0)" onclick="Edit_inform()" class="sty113"><p class="sty113">保   存</p></a></div>
        </form>
    </div>
</div>
<div class="clearer"></div>
