<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/prodBll.inc';
include_once PATH_BLL . '/subBll.inc';

$sub_id = Tools::getValue('id');
$sina_pic_share="";
$qq_pic_share="";
if ($sub_id) {
    $sub = subBll::getByid($sub_id);
    $prod_list = prodBll::getProdByids($sub['prod_id_list']);
    $sina_pic_share=Conf::$pic_path.$sub['sub_pic'];
    $qq_pic_share=$sina_pic_share;
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <title><?php echo $sub['sub_name']; ?>-专题活动-花范儿</title>
        <link href="style/global.css" rel="stylesheet" type="text/css" />
        <link href="style/index.css" rel="stylesheet" type="text/css" />
        <script language="javascript" src="script/jquery-1.7.1.min.js"></script>
        <script language="javascript" src="script/layout.js"></script>
        <script language="javascript" src="script/jquery.jqtransform.js"></script>
        <script type="text/javascript" src="script/main.js"></script>
        <script type="text/javascript" src="script/Library-min.js"></script>
    </head>
    <body>
        <?php include_once PATH_INC . '/head.inc'; ?>
        <!-- 海报区 -->
        <div class="ind_banner">
            <div class="banner_bj clearer">
                  <img src="<?php echo $sub['sub_pic']; ?>" />
            </div>
        </div>
        <!-- 商品列表 -->
        <div class="ind_main">
            <dl class="list_con">
                <?php
                foreach ($prod_list as $k => $v) 
                {
                ?>
                    <dd>
                        <p>
                            <a href="prod.php?id=<?php echo $v[0]; ?>" target="_blank">
                                <img src="<?php echo $v['pic_path']; ?>" style="width:310px;height:296px;"/>
                            </a>
                        </p>
                        <div class="title">
                            <div class="tit_price">
                                <h3>
                                    <a href="prod.php?id=<?php echo $v[0]; ?>" target="_blank">
                                        <?php echo $v['prod_name']; ?>
                                    </a>
                                </h3>
                                <p class="price_con">
                                    ¥<?php echo number_format($v['prod_sale_price'], 1); ?>
                                </p>
                            </div>
                            <div class="btn_y"><a href="prod.php?id=<?php echo $v[0]; ?>" target="_blank">立即购买</a></div>
                            <a class="full"></a>
                        </div>        
                    </dd>
                <?php
                }
                ?>
            </dl>
        </div>
        <div class="clearer"></div>
        <!--  网站底部  -->
        <?php include_once PATH_INC . '/foot.inc'; ?>

    </body>

</html>

