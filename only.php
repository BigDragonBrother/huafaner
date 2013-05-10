<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/prodBll.inc';

$only_prod_list=prodBll::getOnlyprods(3);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title>独一无二-花范儿花店</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="script/layout.js"></script>
        <script language="javascript" src="script/jquery.jqtransform.js"></script>
        <script language="javascript" src="script/Library-min.js"></script>
        <script language="javascript" src="script/main.js"></script>
        <script language="javascript">
            $(function(){
                $('form').jqTransform({imgPath:'images'});
            });
        </script>
    </head>

    <body>
        <!-- 网站头部 -->
        <?php include_once PATH_INC . '/head.inc'; ?>
        
        <!-- 独一无二 -->
        <div class="content" style="margin-top:15px;">
            <h1>定制独一无二的花，回答完问题就可以</h1>
            <div class="detailed_info">
            <div class="info pad_bot">
                <ol>
                    <li>您想把这份独一无二的花礼送给谁？<a name="only_cust_l"></a></li>
                    <li>
                        <input class="inputtext sty500 lh45" value="请把答案写在这里（如：一个我暗恋的女孩子或一个我重要客户）" type="text" name="only_cust" id="only_cust"/>
                        <div class="error lh45" id="only_cust_error" style="display:none">请填写答案！</div>
                        <div class="error lh45" id="only_cust_error1" style="display:none">50个字足够表达了，精简一下吧！</div>
                    </li>
                    <li>TA喜欢风格是什么呢？<a name="only_style_l"></a></li>
                    <li><input class="inputtext sty500 lh45" value="请把答案写在这里（如：田园风或欧美绚丽风）" type="text" name="only_style" id="only_style">
                        <div class="error lh45" id="only_style_error" style="display:none">请填写答案！</div>
                        <div class="error lh45" id="only_style_error1" style="display:none">50个字足够表达了，精简一下吧！</div>
                    </li>
                    <li>TA您想表达什么感情呢？<a name="only_emotion_l"></a></li>
                    <li>
                        <textarea class="inputtext sty500 h130" id="only_emotion" name="only_emotion">请把答案写在这里</textarea>
                        <div class="error lh45" id="only_emotion_error" style="display:none">请填写答案！</div>
                        <div class="error lh45" id="only_emotion_error1" style="display:none">300字都够写2条微博了，您的感情应该可以表达清楚了！</div>
                    </li>
                    <li>请您选择一下花礼的类型吧！<span>（卖花姑娘不好当啊，真的不能砍价哦！）</span></li>
                    <li>
                        <?php
                            foreach($only_prod_list as $k=>$v)
                            {
                                $style='';
                                //if($k==0) $style='selecthua';
                                if($k==2) $style='selnone';
                                $picname_arr=explode('.',$v['pic_path']);
                                ?>
                                    <div class="selhua <?php echo $style; ?>" value="<?php echo $v['prod_id'] ?>">
                                        <img src="<?php echo $picname_arr[0].'_310.'.$picname_arr[1]; ?>" style="width:263px;height:320px;"/>
                                        <div class="poad">
                                            <b><?php echo $v['prod_name']; ?></b><i>￥<?php echo number_format($v['prod_origin_price'],1); ?></i>
                                        </div>
                                    </div>
                                <?php
                            }
                        ?>
                        <!--<div class="selhua selecthua" value="41">
                            <img src="images/dy1.gif" />
                            <div class="poad">
                                <b>普通花束</b><i>￥600.0</i>
                            </div>
                        </div>
                        <div class="selhua" value="45">
                            <img src="images/dy2.gif" />
                            <div class="poad">
                                <b>普通花束</b><i>￥600.0</i>
                            </div>
                        </div>
                        <div class="selhua selnone" value="48">
                            <img src="images/dy1.gif" />
                            <div class="poad">
                                <b>普通花束</b><i>￥600.0</i>
                            </div>
                        </div>
                    -->
                    </li>
                </ol>
                <div class="clearer"></div>
                <div class="tips red line" id="only_prod_error" style="display:none">亲，我们给您做什么类型的花呢，您赶紧选择吧！</div>
                <div class="clearer"></div>
                <div class="error lh45" id="only_ok_error" style="display:none">预订失败！</div>
                <input type="hidden" id="only_buyafterlogin" value="0" />
                <div class="btn"><div>为了保密我们将不会在订单中显示本页的内容，请放心</div>
                    <a href="javascript:void(0)" onclick="onlyok()" class="sty170"><p>回答完了，提交</p></a></div>
            </div>
        </div>
    </div>
        <!--
        <div class="content" style="margin-top:15px;">
            <h1>一些定制花礼</h1>
            <div class="custom_content">
                <div class="pageLeft" id="pageLeft"></div>
                <div class="pageRight" id="pageRight"></div>
                <div class="cus_main">
                    <dl class="customcon" id="customcon">
                        <dd>
                            <div class="custom">
                                <div class="custom_img"><a href="详情页.html"><img src="images/n2.jpg" /></a></div>
                                <div class="custom_info">
                                    <div class="shares">
                                        <a href="#" class="sina" title="新浪"></a>
                                        <a href="#" class="qq" title="QQ"></a>
                                        <a href="#" class="renren" title="人人"></a>
                                        <a href="#" class="dou" title="豆瓣"></a>
                                        <a href="#" class="tui" title="堆"></a>
                                    </div>
                                    <div class="custom_tit"><a href="#">相聚初夏</a></div>
                                </div>
                            </div>
                        </dd>
                    </dl>
                    <dl class="customcon_t" id="customcon_t"></dl>
                </div>
            </div>
        </div>
    -->
        <div class="clearer"></div>
        <!--  网站底部  -->
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>
