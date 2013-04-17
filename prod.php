<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/prodBll.inc';

$prod_id = Tools::getValue('id');
$prod = prodBll::getProdByid($prod_id);
$prod_pic = prodBll::getProdPicByprodid($prod_id);
$prod_tag=prodBll::getProdTagByprodid($prod_id);
$prod_also_tag=prodBll::prodAlsoTag($prod_id);

$like=array();
if(isset($_COOKIE['user_id']))
{
    $like = prodBll::getLike($_COOKIE['user_id'],$prod_id);
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title><?php echo $prod['prod_name']; ?>-那些花-花范儿花店</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <link href="style/jqzoom.css" rel="stylesheet" type="text/css" />
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="script/layout.js"></script>
        <script language="javascript" src="script/Library-min.js"></script>
        <script language="javascript" src="script/prod.js"></script>
    </head>
    <body>
        <?php include_once PATH_INC . '/head.inc'; ?>
        <!-- 商品详情 -->
        <div class="ind_main">
            <div class="detailed_info">
                <!-- 左侧详情图片 -->
                <div class="det_l">
                    <?php
                        $sina_pic_share="";
                        $qq_pic_share="";
                        foreach ($prod_pic as $k => $v) {
                            if($v['pic_seq']==2)
                            {
                                echo "<img src=\"",$v['pic_path'],"\" style=\"width:583px;\"/>"; 
                                $sina_pic_share=$sina_pic_share.Conf::$pic_path.$v['pic_path']."||";
                                $qq_pic_share=$qq_pic_share.Conf::$pic_path.$v['pic_path']."|";
                            }
                        }
                    ?>
                </div>
                <!-- 右侧详情基本信息 -->
                <div class="det_r">
                    <div class="det_rcon drift line_ser">
                        <h2><?php echo $prod['prod_name']; ?></h2>
                        <p class="text_col">标签：
                        <?php
                            foreach ($prod_tag as $k => $v) {
                                echo '<a href="list.php?tag=',$v['tag_id'],'">&lt;',$v['dict_name'],'&gt;</a>';
                            }
                        ?>
                        </p>
                        <p><?php echo $prod['standards'];?></p>
                        <p>免运费</p>
                        <p><i>¥</i><span><?php echo number_format($prod['prod_sale_price'],1); ?></span></p>
                        <div class="btn_buy" style="<?php echo $prod['prod_onshelf_type']==1?"":"display:none";?>">
                            <a href="javascript:void(0)" onclick="buy(<?php echo $prod_id;?>)">立即购买</a>
                        </div>
                        <div class="btn_none" style="<?php echo $prod['prod_onshelf_type']==1?"display:none":"";?>">
                            <a href="#">暂时缺货</a>
                        </div>
                        <div class="seal" style="<?php echo $prod['prod_onshelf_type']==1?"display:none":"";?>"></div>
                    </div>
                    <!-- 收藏分享 -->
                    <div class="det_rcon line_ser">
                        <div class="favorite">
                            <a href="javascript:void(0)" onclick="prod_like(<?php echo $prod['prod_id']; ?>,<?php echo $prod['prod_like']; ?>);" class="<?php echo empty($like)?"fav_n":"fav_y"; ?>"></a>
                            <span id="prod_like" value="<?php echo empty($like)?0:1; ?>"><?php echo $prod['prod_like']; ?></span>
                            <div class="favorite_tip"><p>喜欢？</p><i>加入我的最爱</i><em></em></div>
                        </div>
                        <p class="det_share">
                            <a href="javascript:void((function(s,d,e,r,l,p,t,z,c){var%20f='http://v.t.sina.com.cn/share/share.php?appkey=<?php echo Conf::$appkey['sina']?>',u=z||d.location,p=['&url=',e(u),'&title=',e(t||d.title),'&source=',e(r),'&sourceUrl=',e(l),'&content=',c||'gb2312','&pic=',e(p||'')].join('');function%20a(){if(!window.open([f,p].join(''),'mb',['toolbar=0,status=0,resizable=1,width=440,height=430,left=',(s.width-440)/2,',top=',(s.height-430)/2].join('')))u.href=[f,p].join('');};if(/Firefox/.test(navigator.userAgent))setTimeout(a,0);else%20a();})(screen,document,encodeURIComponent,'','','<?php echo $sina_pic_share;?>','#花范儿花店#跟我一起逛逛花范儿看看那些美丽的花草',document.location,'utf-8'));" class="det_sina" title="新浪"></a>
                            <a href="javascript:void(0)" onclick="postToWb('<?php echo Conf::$appkey['qq']; ?>','','跟我一起逛逛花范儿看看那些美丽的花草','<?php echo $qq_pic_share; ?>');return false;" class="det_qq" title="腾讯"></a>
                            <a href="javascript:void((function(s,d,e){if(/renren\.com/.test(d.location))return;var f='http://share.renren.com/share/buttonshare?link=',u=d.location,l=d.title+'跟我一起逛逛花范儿看看那些美丽的花草',p=[e(u),'&title=',e(l)].join('');function%20a(){if(!window.open([f,p].join(''),'xnshare',['toolbar=0,status=0,resizable=1,width=626,height=436,left=',(s.width-626)/2,',top=',(s.height-436)/2].join('')))u.href=[f,p].join('');};if(/Firefox/.test(navigator.userAgent))setTimeout(a,0);else%20a();})(screen,document,encodeURIComponent));" class="det_renren" title="人人"></a>
                            <a href="javascript:void(function(){var d=document,e=encodeURIComponent,s1=window.getSelection,s2=d.getSelection,s3=d.selection,s=s1?s1():s2?s2():s3?s3.createRange().text:'',r='http://www.douban.com/recommend/?url='+e(d.location.href)+'&title='+e(d.title+'跟我一起逛逛花范儿看看那些美丽的花草')+'&sel='+e(s)+'&v=1',x=function(){if(!window.open(r,'douban','toolbar=0,resizable=1,scrollbars=yes,status=1,width=450,height=330'))location.href=r+'&r=1'};if(/Firefox/.test(navigator.userAgent)){setTimeout(x,0)}else{x()}})()" class="det_douban" title="豆瓣"></a>
                        </p>  
                    </div>
                    <!-- 设计灵感 -->
                    <div class="det_rcon line_ser">
                        <h3>设计灵感</h3>
                        <p class="text_lin"><?php echo $prod['prod_word']; ?></p>
                    </div>
                    <!-- 花语 -->
                    <div class="det_rcon line_ser">
                        <h3>花语</h3>
                        <p class="text_lin"><?php echo $prod['prod_medium']; ?></p>
                    </div>
                    <!-- 保养说明 -->
                    <div class="det_rcon line_ser">
                        <h3>保养说明</h3>
                        <p class="text_lin"><?php echo $prod['prod_care_desc_dict']; ?></p>
                    </div>
                    <!-- 订购说明 -->
                    <div class="det_rcon line_ser">
                        <h3>订购说明</h3>
                        <p class="text_lin"><?php echo $prod['prod_order_desc_dict']; ?></p>
                    </div>
                    <!-- 您可能也会喜欢喜欢 -->
                    <div class="det_rcon">
                        <h3>您可能也会喜欢</h3>
                        <ul>
                            <?php
                                foreach ($prod_also_tag as $k => $v) {
                                    echo '<li><a href="prod.php?id=',$v['prod_id'],'"><img src="',$v['pic_path'],'" title="',$v['prod_name'],'" style="width:128px;height:122px;" /></a></li>';
                                }
                            ?>
                        </ul>                
                    </div>
                </div>
            </div>    
        </div>
        <?php include_once PATH_INC . '/foot.inc'; ?>
    </body>
</html>