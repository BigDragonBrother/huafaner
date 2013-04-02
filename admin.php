<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>运营后台登录</title>
<link href="style/global.css" rel="stylesheet" type="text/css" />
<link href="style/index.css" rel="stylesheet" type="text/css" />
<script language="javascript" src="script/jquery-1.7.1.min.js"></script>
<script language="javascript" src="script/layout.js"></script>
<script type="text/javascript" src="script/admin.js" ></script>
<script language="javascript" src="script/Library-min.js"></script>
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
