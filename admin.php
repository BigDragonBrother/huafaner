<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>运营后台登录</title>
<link href="style/css/global.css" rel="stylesheet" type="text/css" />
<link href="style/css/index.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="script/jquery.1.3.2.js"></script>
<script type="text/javascript" src="script/jquery.form.2.43.js"></script>
<script type="text/javascript" src="script/admin.js" ></script>
<script language="javascript" src="script/layout.js"></script>
<script language="javascript" src="script/Library-min.js"></script>
<link href="style/jquery.ui.theme.css" rel="stylesheet" type="text/css"/>
<link href="style/jquery.ui.datepicker.css" rel="stylesheet" type="text/css"/>
<script language="javascript" src="script/jquery.ui.core.min.js"></script>
<script language="javascript" src="script/jquery.ui.datepicker.js"></script>
<script language="javascript">
$(function(){
    var options= {
        //changeMonth: true, //显示月份下拉框
        //changeYear: true, //显示年份下拉框
        dateFormat: 'yy-mm-dd',  //日期格式，自己设置
        buttonImage: 'image/calendar.gif',  //按钮的图片路径，自己设置
        buttonImageOnly: true,  //Show an image trigger without any button.
        showOn: 'both',//触发条件，both表示点击文本域和图片按钮都生效
        yearRange: '2013:2040',//年份范围
        clearText:'清除',
        closeText:'关闭',
        prevText:'',
        nextText:'',
        currentText:"now",
        monthNames:['1月','2月','3月','4月','5月','6月','7月','8月','9月','10月','11月','12月'],
        dayNamesMin:['日','一','二','三','四','五','六'],
        showMonthAfterYear: true,
        defaultDate: 0 //设置当前日期
    };
    $(".sty85").datepicker(options);
});
</script>
<link rel="shortcut icon" href="images/favicon.ico" />
</head>
<body>
    <!-- 网站头部 -->
    <div class="header">
    	<div class="logo">
        	<img src="images/logo.jpg" />
        	<h1>花范儿业务管理系统</h1>
        </div>
        <div class="login">您好，欢迎使用花范儿业务管理系统！
            <span>
                <?php 
                if(!isset($_COOKIE['adminuser']))
                {
                ?>
                    <a href="admin.php">请登录</a>
                <?php 
                }
                else
                {
                ?>
                    <a href="javascript:void(0)" onclick="adminlogout()">退出登陆</a>
                <?php    
                }
                ?>
            </span>
        </div>
    </div>
    <?php
        ob_start();
        include_once "conf.inc";
        include_once PATH_LIB . '/tools.inc';

        if(!isset($_COOKIE['adminuser']))
        {
            include_once PATH_ADMIN.'/login.inc';
            return;    
        }

        $page = Tools::getValue('k');
        if (!file_exists(PATH_ADMIN . '/' . $page . '.inc')) {
            $page = 'welcome';
        }
    ?>
    <!-- 网站主体 -->
    <div class="bodymain">
        <!-- 左侧菜单 -->
        <div class="main_left">
            <?php include_once PATH_ADMIN . '/menu.inc'; ?>
        </div>
        <div class="main_right">
            <?php include_once PATH_ADMIN . '/' . $page . '.inc'; ?>
        </div>
    </div>
</body>
</html>