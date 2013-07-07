<?php
set_time_limit(0);

header("Content-Type: text/html; charset=UTF-8");

define('SCRIPT_ROOT', dirname(__FILE__).'/');
require_once SCRIPT_ROOT.'include/Client.php';
require_once SCRIPT_ROOT.'../conf.inc';

$gwUrl = Conf::$sms['url'];
$serialNumber = Conf::$sms['serialNumber'];
$password = Conf::$sms['password'];
$sessionKey = Conf::$sms['sessionkey'];
$connectTimeOut = 2;
$readTimeOut = 10;
$proxyhost = false;
$proxyport = false;
$proxyusername = false;
$proxypassword = false;

$client = new Client($gwUrl,$serialNumber,$password,$sessionKey,$proxyhost,$proxyport,$proxyusername,$proxypassword,$connectTimeOut,$readTimeOut);
$client->setOutgoingEncoding("UTF-8");
$content = "再冷漠的姑娘也无法拒绝闪亮的玫瑰！再平淡的生活也需要鲜花的点缀!再羞涩的爱情也需要鲜花的表白！--姑娘可以冷漠，生活可以平淡,但表达爱情必须有自己的范儿!看看【花范儿花店】，让你用花发现爱情和生命中的色彩！--www.huafaner.com.weixin://qr/nHU6NRvEDiVxhwpWnyC4（或在公众账号搜索：花范儿花店）4008-900-512";
$client->sendSMS(array('18618148163'),$content);
?>