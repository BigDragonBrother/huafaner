<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/blogBll.inc';

$blog=blogBll::get_blog(Tools::getValue('id'));
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>花范儿花店-你的花你的范儿</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <script type="text/javascript" src="script/jquery-1.7.1.min.js"></script>
        <script type="text/javascript" src="script/layout.js"></script>
        <script type="text/javascript" src="script/Library-min.js"></script>
        <script type="text/javascript" src="script/main.js"></script>
        <script src="http://tjs.sjs.sinajs.cn/open/api/js/wb.js?appkey=2995335930" type="text/javascript" charset="utf-8"></script>
    </head>
    <body>
        <?php include_once PATH_INC . '/head.inc'; ?>
        <div class="ind_main">
          <h2><?php echo $blog['blog_title']; ?></h2>
            <div class="clause">
                <?php echo $blog['blog_content']; ?>
            </div>
        </div>
        <div class="clearer"></div>
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>