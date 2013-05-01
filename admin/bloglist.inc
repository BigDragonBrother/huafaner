<?php
include_once PATH_BLL.'/blogBll.inc';

$blog_list=blogBll::getList();
?>
<div class="title"><h2>维护博客</h2></div>
<div class="content">
    <table class="list">
        <tr>
            <th>编号</th>
            <th>博客标题</th>
            <th>发表日期</th>
            <th>修改日期</th>
            <th>操作</th>
        </tr>
        <?php
        foreach ($blog_list as $k => $v) {
        ?>
        <tr>
            <td><?php echo $v['blog_id']; ?></td>
            <td><?php echo $v['blog_title']; ?></td>
            <td><?php echo $v['cdate']; ?></td>
            <td><?php echo $v['udate']; ?></td>
            <td>
                <a href="admin.php?k=blog&id=<?php echo $v['blog_id']; ?>">修改</a>
            </td>
        </tr>
        <?php
        }
        ?>
</table>
</div>