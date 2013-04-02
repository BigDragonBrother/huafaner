<?php
include_once 'conf.inc';
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/prodBll.inc';

$dict_list=prodBll::getDict();
$prod_type=Tools::getValue('type');
$prod_tag=Tools::getValue('tag');

if($prod_type==''&$prod_tag=='')
{
    $prod_list=prodBll::getProdTopN(50);    
}
elseif ($prod_type!='') {
    $prod_list=prodBll::getProdByType($prod_type);
}
elseif ($prod_tag!='') {
    $prod_list=prodBll::getProdByTag($prod_tag);
    $tag=prodBll::getProdTag($prod_tag);
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>花范儿--列表</title>
<link href="style/global.css" rel="stylesheet" type="text/css" />
<link href="style/index.css" rel="stylesheet" type="text/css" />
<script language="javascript" src="script/jquery-1.7.1.min.js"></script>
<script language="javascript" src="script/layout.js"></script>
<script language="javascript" src="script/list.js"></script>
</head>
<body>
<!-- 网站头部 -->
<?php include_once PATH_INC . '/head.inc'; ?>
<!-- 列表分类 -->
<div class="ind_main">
    <div class="species line_ser">
        <h3>标签</h3>
        <dl class="w_890">
            <?php
                foreach ($dict_list as $k => $v) {
                    if($v['dict_type']=="tag_2")
                    {
                        echo "<dd><a href=\"javascript:void(0)\" onclick=\"list_add('",$v['dict_id'],"','",$v['dict_name'],"')\">",$v['dict_name'],"</a></dd>";
                    }
                }
            ?>
        </dl>
    </div>
    <div class="pick">
        <input type="hidden" id="search_list" value="<?php echo $prod_tag; ?>"/>
        <dl id="pick_list">
            <?php
                if($prod_tag!='')
                {
                    echo '<dd class="add" value="'.$prod_tag.'">'.$tag[0]['dict_name'].'<a href="javascript:void(0)" onclick="list_remove(this);" class="remove"></a></dd>';
                }
            ?>
        </dl>
    </div>
    <div class="detailed_info pad30" style="<?php echo count($prod_list)?"display:none":""; ?>">
        <p>没有符合条件的商品，<a href="list.php">继续逛逛吧</a></p>
        <a href="index.php" class="home">回到首页</a>
    </div>

    <dl class="list_con mat_top">
        <?php
        foreach ($prod_list as $k => $v) 
        {
        ?>
            <dd>
                <p>
                    <a href="prod.php?id=<?php echo $v['prod_id']; ?>" target="_blank">
                        <img src="<?php echo $v['pic_path']; ?>" title="<?php echo $v['prod_title']; ?>" style="width:310px;height:296px;"/>
                    </a>
                </p>
                <div class="title">
                    <div class="tit_price">
                        <h3>
                            <a href="prod.php?id=<?php echo $v['prod_id']; ?>" target="_blank">
                                <?php echo substr($v['prod_name'],0,50); ?>
                            </a>
                        </h3>
                        <p class="price_con">
                            ¥ <?php echo number_format($v['prod_sale_price'], 1); ?>
                        </p>
                    </div>
                    <div class="btn_y"><a href="prod.php?id=<?php echo $v['prod_id']; ?>" target="_blank">立即购买</a></div>
                    <a class="full"></a>
                </div>        
            </dd>
        <?php
        }
        ?>
    </dl>
</div>

<!-- 网站底部 -->
<?php include_once PATH_INC . '/foot.inc'; ?>
</body>
</html>
