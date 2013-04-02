<?php

/*
 * @Description 易宝支付B2C在线支付接口范例 
 * @V3.0
 * @Author rui.xin
 */
 
include 'yeepayCommon.php';	
include_once '../conf.inc';
include_once PATH_BLL.'/orderBll.inc';
include_once PATH_LIB . '/tools.inc';
	
#	只有支付成功时易宝支付才会通知商户.
##支付成功回调有两次，都会通知到在线支付请求参数中的p8_Url上：浏览器重定向;服务器点对点通讯.

#	解析返回参数.
$return = getCallBackValue($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType,$hmac);

#	判断返回签名是否正确（True/False）
$bRet = CheckHmac($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType,$hmac);
#	以上代码和变量不需要修改.
	 	
#	校验码正确.
if($bRet)
{
	if($r1_Code=="1")
	{
	#	交易成功	
	#	需要比较返回的金额与商家数据库中订单的金额是否相等，只有相等的情况下才认为是交易成功.
	#	并且需要对返回的处理进行事务控制，进行记录的排它性处理，在接收到支付结果通知后，判断是否进行过业务逻辑处理，不要重复进行业务逻辑处理，防止对同一条交易重复发货的情况发生.      	  	
		//1：在线支付页面返回；2：在线支付服务器返回
		if($r9_BType=="1"||$r9_BType=="2")
		{
			$status=orderBll::order_pay($r6_Order);
			orderBll::yeepay_log($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType);
		}
		Tools::redirectLink(Conf::$urlSet['domain'].'orderok.php?id='.$r6_Order.'&type=success');
	}
	else
	{
		Tools::redirectLink(Conf::$urlSet['domain'].'orderok.php?id='.$r6_Order.'&type=fail');	
	}
}
else
{
	Tools::redirectLink(Conf::$urlSet['domain'].'orderok.php?id='.$r6_Order.'&type=fail');
}
   
?>
<html>
<head>
<title></title>
</head>
<body>
</body>
</html>