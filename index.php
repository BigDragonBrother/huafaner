<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/prodBll.inc';
include_once PATH_BLL . '/blogBll.inc';
$blog_list = blogBll::getTopN(2);
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
        <!-- 海报区 -->
        <div class="ind_banner">
            <div class="banner_bj clearer">
                <div class="banner_l">
            
            <div class="demo">
                <div class="num">
                    <?php
                        foreach ($design['poster'] as $k => $v) {
                            if($k==0)
                                echo '<a class="cur">',$k+1,'</a>';
                            else
                                echo '<a class="">',$k+1,'</a>';
                        }
                    ?>
                </div>
                <ul>
                    <?php 
                        foreach ($design['poster'] as $k => $v) {
                    ?>
                    <li <?php echo $k==0?'style="display: block;"':''; ?>>
                        <a href="sub.php?id=<?php echo $v['poster_sub']; ?>">
                            <img src="<?php echo $v['poster_pic'] ?>" style="width:729px;height:366px;"/>
                        </a>
                    </li>
                    <?php
                        }
                    ?>
                </ul>
            </div>
        
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
                    <p>
                        <a href="prod.php?id=<?php echo $design['file_poster'][0]['poster_prod']; ?>">
                            <img src="<?php echo $design['file_poster'][0]['poster_pic']; ?>" style="width:477px;height:320px;"/>
                        </a>
                    </p>
                    <div class="title"><span><?php echo $design['file_poster'][0]['poster_desc']; ?></span></div>
                </li>
                <li>
                    <p>
                        <a href="prod.php?id=<?php echo $design['file_poster'][1]['poster_prod']; ?>">
                            <img src="<?php echo $design['file_poster'][1]['poster_pic']; ?>" style="width:477px;height:320px;"/>
                        </a>
                    </p>
                    <div class="title"><span><?php echo $design['file_poster'][1]['poster_desc']; ?></span></div>
                </li>
            </ul>
        </div>
        <div class="ind_main">
            <dl class="ind_con">
                <?php
                    for($i=0;$i<=2;$i++)
                    {
                        $prod_com=prodBll::getProdPicByid($design['prod'][$i]['prod_id']);
                ?>
                        <dd>
                            <p>
                                <a href="prod.php?id=<?php echo $prod_com['prod_id']; ?>">
                                    <img src="<?php echo $prod_com['list_pic']; ?>" style="width:310px;height:296px;"/>
                                </a>
                            </p>
                            <div class="title"><span><?php echo $prod_com['prod_name']; ?></span></div>
                        </dd>
                <?php
                    }
                ?>
            </dl>
        </div>
        <!-- 经典热卖 -->
        <div class="ind_main">
            <h2><span class="blue">经典</span>热卖</h2>
            <ul class="ind_rec">
                <li>
                    <p>
                        <a href="prod.php?id=<?php echo $design['file_poster'][2]['poster_prod']; ?>">
                            <img src="<?php echo $design['file_poster'][2]['poster_pic']; ?>" style="width:477px;height:320px;"/>
                        </a>
                    </p>
                    <div class="title"><span><?php echo $design['file_poster'][2]['poster_desc']; ?></span></div>
                </li>
                <li>
                    <p>
                        <a href="prod.php?id=<?php echo $design['file_poster'][3]['poster_prod']; ?>">
                            <img src="<?php echo $design['file_poster'][3]['poster_pic']; ?>" style="width:477px;height:320px;"/>
                        </a>
                    </p>
                    <div class="title"><span><?php echo $design['file_poster'][3]['poster_desc']; ?></span></div>
                </li>
            </ul>
        </div>
        <div class="ind_main">
            <dl class="ind_con">
                <?php
                    for($i=3;$i<=8;$i++)
                    {
                        $prod_com=prodBll::getProdPicByid($design['prod'][$i]['prod_id']);
                ?>
                        <dd>
                            <p>
                                <a href="prod.php?id=<?php echo $prod_com['prod_id']; ?>">
                                    <img src="<?php echo $prod_com['list_pic']; ?>" style="width:310px;height:296px;"/>
                                </a>
                            </p>
                            <div class="title"><span><?php echo $prod_com['prod_name']; ?></span></div>
                        </dd>
                <?php
                    }
                ?>
            </dl>
        </div>
        <!-- 花范儿故事 -->
        <div class="ind_main">
            <h2><span class="orange">花范儿</span>故事</h2>
            <?php
            foreach ($blog_list as $k => $v) {
            ?>
                <div class="story">
                    <div class="story_img">
                        <a href="blog.php?id=<?php echo $v['blog_id'];?>"><img src="images/a8.jpg" /></a>
                    </div>
                    <div class="story_con">
                        <h2><a href="blog.php?id=<?php echo $v['blog_id'];?>"><?php echo $v['blog_title']; ?></a></h2>
                        <p></p>
                    </div>
                </div>
            <?php
            }
            ?>
        </div>
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>