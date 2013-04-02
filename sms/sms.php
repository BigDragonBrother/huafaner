<?php
set_time_limit(0);

header("Content-Type: text/html; charset=UTF-8");

define('SCRIPT_ROOT',  dirname(__FILE__).'/');
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

//亲爱的沈国龙,您的订单10053已经提交,金额418,网银支付,支付宝,请您尽快付款,以便我们安排生产【花范儿】
function huafaner_sendSMS($type,$order_name,$order_id,$order_mobile,$total,$payment)
{
	global $client;
	//提交订单
	if($type==1)
	{
		if($order_mobile==''||$order_name==''||$order_id==''||$total==''||$payment=='')
			return 99;
		$pay=split("，",$payment);
		if(count($pay)==2)
			$str=$pay[0]."(".$pay[1].")";
		else
			$str=$payment;
		$statusCode = $client->sendSMS(array($order_mobile),"亲爱的".$order_name.",您的订单".$order_id."已经提交,金额".$total.",".$str.",请您尽快付款,以便我们安排生产【花范儿】");
	}
	//发货
	if($type==2)
	{
		if($order_mobile==''||$order_name==''||$order_id=='')
			return 99;
		$statusCode = $client->sendSMS(array($order_mobile),"亲爱的".$order_name.",您的订单".$order_id."已经发出,收花人签收后我们会短信通知您,祝您愉快!【花范儿】");	
	}
	//收货
	if($type==3)
	{
		if($order_mobile==''||$order_name==''||$order_id=='')
			return 99;
		$statusCode = $client->sendSMS(array($order_mobile),"亲爱的".$order_name.",您的订单".$order_id."已经确认签收,如有其它需要欢迎致电或登录网站!【花范儿】");	
	}
	
	return $statusCode;
}
?>
