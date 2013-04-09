<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/designBll.inc';
include_once PATH_BLL . '/prodBll.inc';

$d_var=designBll::get_design('index');
var_dump($d_var['d_var']);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>花范儿花艺工作室 - 最特别的网络花店_给你惊喜的网络花店_花艺个性设计_花艺量身定制</title>
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
        <!-- 海报区 -->
        <div class="ind_banner">
            <div class="banner_bj clearer">
                <div class="banner_l">
                    <img src="images/a1.jpg" />
                </div>
                <div class="ind_share">
                    <div class="infolist"><img src="images/a2.jpg" /></div>
                    <div class="infolist" style="display:none;"><img src="images/a2_1.jpg" /></div>
                    <ul>
                        <li class="mar_r"><img src="images/weixin.gif" /></li>
                        <li><img src="images/sina.jpg" /></li>
                    </ul>
                </div>
            </div>
        </div>
        <!-- 最新设计 -->
        <div class="ind_main">
            <h2>最新<span class="green">设计</span></h2>
            <ul class="ind_rec">
                <li>
                    <p><a href="#"><img src="images/a3.jpg" /></a></p>
                    <div class="title"><span>雨后</span></div>
                </li>
                <li>
                    <p><a href="#"><img src="images/a4.jpg" /></a></p>
                    <div class="title"><span>Flower Dance 花之舞</span></div>
                </li>
            </ul>
        </div>
        <div class="ind_main">
            <dl class="ind_con">
                <dd>
                    <p><a href="#"><img src="images/a5.jpg" /></a></p>
                    <div class="title"><span>海洋风情多肉桌摆</span></div>        
                </dd>
                <dd>
                    <p><a href="#"><img src="images/a6.jpg" /></a></p>
                    <div class="title"><span>红与绿</span></div> 
                </dd>
                <dd>
                    <p><a href="#"><img src="images/a7.jpg" /></a></p>
                    <div class="title"><span>爱情的香与毒</span></div>
                </dd>
            </dl>
        </div>
        <!-- 经典热卖 -->
        <div class="ind_main">
            <h2><span class="blue">经典</span>热卖</h2>
            <ul class="ind_rec">
                <li>
                    <p><a href="#"><img src="images/a3.jpg" /></a></p>
                    <div class="title"><span>雨后</span></div>
                </li>
                <li>
                    <p><a href="#"><img src="images/a4.jpg" /></a></p>
                    <div class="title"><span>Flower Dance 花之舞</span></div>
                </li>
            </ul>
        </div>
        <div class="ind_main">
            <dl class="ind_con">
                <dd>
                    <p><a href="#"><img src="images/a5.jpg" /></a></p>
                    <div class="title"><span>海洋风情多肉桌摆</span></div>        
                </dd>
                <dd>
                    <p><a href="#"><img src="images/a6.jpg" /></a></p>
                    <div class="title"><span>红与绿</span></div> 
                </dd>
                <dd>
                    <p><a href="#"><img src="images/a7.jpg" /></a></p>
                    <div class="title"><span>爱情的香与毒</span></div>
                </dd>
                <dd>
                    <p><a href="#"><img src="images/a5.jpg" /></a></p>
                    <div class="title"><span>海洋风情多肉桌摆</span></div>        
                </dd>
                <dd>
                    <p><a href="#"><img src="images/a6.jpg" /></a></p>
                    <div class="title"><span>红与绿</span></div> 
                </dd>
                <dd>
                    <p><a href="#"><img src="images/a7.jpg" /></a></p>
                    <div class="title"><span>爱情的香与毒</span></div>
                </dd>
            </dl>
        </div>
        <!-- 花范儿故事 -->
        <div class="ind_main">
            <h2><span class="orange">花范儿</span>故事</h2>
            <div class="story">
                <div class="story_img"><a href="#"><img src="images/a8.jpg" /></a></div>
                <div class="story_con">
                    <h2><a href="#">花范儿故事</a></h2>
                    <p>我们渴望精神共鸣，渴望找到志同道合的朋友，渴望血脉喷张的青春。每个人都是独特的，勇于追求自我，这才是潮流的最好代名词。</p>
                </div>
            </div>
            <div class="story">
                <div class="story_img"><a href="#"><img src="images/a8.jpg" /></a></div>
                <div class="story_con">
                    <h2><a href="#">花范儿故事</a></h2>
                    <p>我们渴望精神共鸣，渴望找到志同道合的朋友，渴望血脉喷张的青春。每个人都是独特的，勇于追求自我，这才是潮流的最好代名词。</p>
                </div>
            </div>
        </div>
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>