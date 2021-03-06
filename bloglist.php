<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/blogBll.inc';

$bloglist=blogBll::getTopN(10);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>花范儿故事-花范儿花店</title>
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
        <div class="blackboard">
            <div class="blak_left">
                <?php
                foreach ($bloglist as $k => $v) 
                {
                    $m="";
                    switch(date('m',strtotime($v['cdate'])))
                    {
                        case '01':$m='JAN';break;
                        case '02':$m='FEB';break;
                        case '03':$m='MAR';break;
                        case '04':$m='APR';break;
                        case '05':$m='MAY';break;
                        case '06':$m='JUN';break;
                        case '07':$m='JUL';break;
                        case '08':$m='AUG';break;
                        case '09':$m='SEP';break;
                        case '10':$m='OCT';break;
                        case '11':$m='NOV';break;
                        case '12':$m='DEC';break;
                        default:break;
                    }
                ?>
                <div class="blak_list">
                    <div class="blak_line"></div>
                    <div class="date">
                        <p><?php echo $m; ?></p>
                        <p class="month"><?php echo date('d',strtotime($v['cdate'])) ?></p>
                    </div>
                    <div class="blak_con">
                        <h2><a href="blog.php?id=<?php echo $v['blog_id']; ?>"><?php echo $v['blog_title']; ?></a></h2>
                        <div class="dtime">
                            <i><?php echo date('H:m:s',strtotime($v['cdate'])) ?></i>/
                            <i>浏览<?php echo $v['blog_view']; ?>次</i>
                        </div>
                        <?php echo $v['blog_content']; ?>
                    </div>
                </div>
                <?php
                }
                ?>
                <div class="clearer"></div>
                <div class="blak_line mar_bot"></div>
                <!-- 分页 
                <div class="pages">
                    <a class="a2">&lt; 上一页</a>
                    <span>1</span>
                    <a href="#">2</a>
                    <a href="#">3</a>
                    <a href="#">4</a>
                    <a href="#">5</a>
                    <em>&hellip;</em>
                    <a href="#">50</a>
                    <a class="a1" href="#">下一页 &gt;</a>
                </div>
                -->
            </div>
            <div class="blak_right">
                <div class="blak_pic"><img src="images/blak_right.gif" /></div>
                <div class="blak_rcon">
                    <p></p>
                    <p class="weibo">微博：<a href="http://weibo.com/floralstyle">@花范儿官方微博</a></p>
                </div>
                <div class="blak_rbot"></div>
            </div>
        </div>
        <div class="clearer"></div>
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>