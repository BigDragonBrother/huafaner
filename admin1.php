
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
    <head>
        <title>后台管理</title>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <script type="text/javascript" src="script/jquery.1.3.2.js"></script>
        <script type="text/javascript" src="script/jquery.form.2.43.js"></script>
        <script type="text/javascript" src="script/admin.js" ></script>
        <link rel="stylesheet" type="text/css" href="style/admin.css"/>
        <link href="style/jquery.ui.theme.css" rel="stylesheet" type="text/css"/>
        <link href="style/jquery.ui.datepicker.css" rel="stylesheet" type="text/css"/>
        <script language="javascript" src="script/jquery.ui.core.min.js"></script>
        <script language="javascript" src="script/jquery.ui.datepicker.js"></script>
        <link href="css/global.css" rel="stylesheet" type="text/css" />
        <link href="css/index.css" rel="stylesheet" type="text/css" />
        <script language="javascript" src="js/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="js/layout.js"></script>
        <script language="javascript">
            $(function(){
                var options= {
                    //changeMonth: true, //显示月份下拉框
                    //changeYear: true, //显示年份下拉框
                    dateFormat: 'yy-mm-dd',  //日期格式，自己设置
                    buttonImage: 'image/calendar.gif',  //按钮的图片路径，自己设置
                    buttonImageOnly: true,  //Show an image trigger without any button.
                    showOn: 'both',//触发条件，both表示点击文本域和图片按钮都生效
                    yearRange: '2012:2040',//年份范围
                    clearText:'清除',
                    closeText:'关闭',
                    prevText:'<',
                    nextText:'>',
                    currentText:"now",
                    monthNames:['1月','2月','3月','4月','5月','6月','7月','8月','9月','10月','11月','12月'],
                    dayNamesMin:['日','一','二','三','四','五','六'],
                    showMonthAfterYear: true,
                    defaultDate: 0 //设置当前日期
                };
                $(".datepicker").datepicker(options);
                var today = new Date();
                //$(".datepicker").val(today.getFullYear()+"-"+(today.getMonth()+1)+"-"+today.getDate());
            });
        </script>
    </head>
    <body>
    <div class="header">
        <div class="logo">
            <img src="images/logo.jpg" />
            <h1>花范儿业务管理系统</h1>
        </div>
        <div class="login">您好，欢迎使用花范儿业务管理系统！<span><a href="index.html">请登录&gt;&gt;</a></span></div>
    </div>
        <?php
            include_once "conf.inc";
            include_once PATH_LIB . '/tools.inc';

            if(!isset($_COOKIE['adminuser']))
            {
                include_once PATH_INC.'/adminlogin.inc';
                return;    
            }

            $page = Tools::getValue('k');
            if (!file_exists(PATH_INC . '/' . $page . '.inc')) {
                $page = 'welcome';
            }
        ?>
        <table id="main" width="100%" height="100%"  boder="0">
            <tr>
                <td width="150px" valign="top"><?php include_once PATH_INC . '/adminmenu.inc'; ?></td>
                <td width="5px" bgcolor="blue"></td>
                <td width="100%" valign="top"><?php include_once PATH_INC . '/' . $page . '.inc'; ?></td>
            </tr>
        </table>
    </body>
</html>

