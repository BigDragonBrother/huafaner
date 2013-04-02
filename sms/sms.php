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

//�װ��������,���Ķ���10053�Ѿ��ύ,���418,����֧��,֧����,�������츶��,�Ա����ǰ�����������������
function huafaner_sendSMS($type,$order_name,$order_id,$order_mobile,$total,$payment)
{
	global $client;
	//�ύ����
	if($type==1)
	{
		if($order_mobile==''||$order_name==''||$order_id==''||$total==''||$payment=='')
			return 99;
		$pay=split("��",$payment);
		if(count($pay)==2)
			$str=$pay[0]."(".$pay[1].")";
		else
			$str=$payment;
		$statusCode = $client->sendSMS(array($order_mobile),"�װ���".$order_name.",���Ķ���".$order_id."�Ѿ��ύ,���".$total.",".$str.",�������츶��,�Ա����ǰ�����������������");
	}
	//����
	if($type==2)
	{
		if($order_mobile==''||$order_name==''||$order_id=='')
			return 99;
		$statusCode = $client->sendSMS(array($order_mobile),"�װ���".$order_name.",���Ķ���".$order_id."�Ѿ�����,�ջ���ǩ�պ����ǻ����֪ͨ��,ף�����!����������");	
	}
	//�ջ�
	if($type==3)
	{
		if($order_mobile==''||$order_name==''||$order_id=='')
			return 99;
		$statusCode = $client->sendSMS(array($order_mobile),"�װ���".$order_name.",���Ķ���".$order_id."�Ѿ�ȷ��ǩ��,����������Ҫ��ӭ�µ���¼��վ!����������");	
	}
	
	return $statusCode;
}
?>
