<?php
$dir="picture";

$list = scandir($dir); // 得到该文件下的所有文件和文件夹
foreach($list as $file)
{
	echo $dir,'/',$file;
}
?>