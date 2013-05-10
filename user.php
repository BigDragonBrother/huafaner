<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/userBll.inc';

$model = Tools::getValue("m");
if (!file_exists(PATH_INC . "/$model.inc")) {
    $model = "user_info";
}

if($model!='user_forgetpwd')
{
    if (!$_COOKIE['user_id']) 
    {
        Tools::redirectLink(Conf::$urlSet['homepage']);
    }
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>用户管理-花范儿花店</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="script/jquery.jqtransform.js"></script>
        <script language="javascript" src="script/Library-min.js"></script>
        <script language="javascript" src="script/layout.js"></script>
        <script language="javascript" src="script/jquery.ui.datepicker.js"></script>
        <script language="javascript" src="script/user.js"></script>
        <script language="javascript" src="script/order.js"></script>
        <script language="javascript">
            $(function(){
                $('form').jqTransform({imgPath:'images'});
            });
        </script>
    </head>
    <body>
        <?php
        include_once PATH_INC . '/head.inc';
        include_once PATH_INC . "/$model.inc";
        include_once PATH_INC . '/foot.inc';
        ?>
    </body>
</html>

