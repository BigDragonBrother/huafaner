<?php
include_once PATH_BLL . '/prodBll.inc';

$prod_list = prodBll::getLikeByuserid($_COOKIE['user_id']);
?>
<div class="content" style="margin-top:15px;">
    <h1>我的最爱</h1>
    <div class="detailed_info">
        <?php
        foreach ($prod_list as $k => $v) {
            ?>
            <div class="love_box">
                <div class="love_img">
                    <a href="prod.php?id=<?php echo $v['prod_id']?>">
                        <img src="<?php echo $v['pic_path']?>" />
                    </a>
                    <div class="partake part_none">
                        <a class="sina" title="新浪" href="#"></a>
                        <a class="qq" title="QQ" href="#"></a>
                        <a class="renren" title="人人" href="#"></a>
                        <a class="dou" title="豆瓣" href="#"></a>
                    </div>
                </div>
                <dl class="love_tit">
                    <dt>
                    <a href="prod.php?id=<?php echo $v['prod_id']?>">
                        <?php echo $v['prod_name']?>
                    </a>
                    </dt>
                    <dd class="love_like">
                        <a class="plus plus_select" title="喜欢"><?php echo $v['prod_like']?></a>
                    </dd>
                </dl>
            </div>
            <?php
        }
        ?>
    </div>
</div>
<div class="clearer"></div>

