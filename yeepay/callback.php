<?php

/*
 * @Description �ױ�֧��B2C����֧���ӿڷ��� 
 * @V3.0
 * @Author rui.xin
 */
 
include 'yeepayCommon.php';	
include_once '../conf.inc';
include_once PATH_BLL.'/orderBll.inc';
include_once PATH_LIB . '/tools.inc';
	
#	ֻ��֧���ɹ�ʱ�ױ�֧���Ż�֪ͨ�̻�.
##֧���ɹ��ص������Σ�����֪ͨ������֧����������е�p8_Url�ϣ�������ض���;��������Ե�ͨѶ.

#	�������ز���.
$return = getCallBackValue($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType,$hmac);

#	�жϷ���ǩ���Ƿ���ȷ��True/False��
$bRet = CheckHmac($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType,$hmac);
#	���ϴ���ͱ�������Ҫ�޸�.
	 	
#	У������ȷ.
if($bRet)
{
	if($r1_Code=="1")
	{
	#	���׳ɹ�	
	#	��Ҫ�ȽϷ��صĽ�����̼����ݿ��ж����Ľ���Ƿ���ȣ�ֻ����ȵ�����²���Ϊ�ǽ��׳ɹ�.
	#	������Ҫ�Է��صĴ������������ƣ����м�¼�������Դ����ڽ��յ�֧�����֪ͨ���ж��Ƿ���й�ҵ���߼�������Ҫ�ظ�����ҵ���߼�������ֹ��ͬһ�������ظ��������������.      	  	
		//1������֧��ҳ�淵�أ�2������֧������������
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