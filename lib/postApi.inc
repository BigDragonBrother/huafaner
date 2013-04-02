<?php
class postApi extends postApiTools
{
	public function __construct($urlKey, $baseUrl, $dataArr, $sendType, $assemType = 0, $timeOut, $logFile)
	{
		parent::__construct($urlKey, $baseUrl, $dataArr, $sendType, $assemType, $timeOut, $logFile);
	}
	
	
	public function assemData1()
	{
		if (is_array($this->dataArr) && count($this->dataArr))
		{
			foreach ($this->dataArr as $key => $val)
			{
				$this->baseUrl = sprintf($this->baseUrl, $val);
			}
			return $this->baseUrl;
		}
	}
	
	public function assemData2()
	{
		$this->baseUrl = str_replace('key', 'tech4365', $this->baseUrl);
		foreach ($this->dataArr as $key => $val)
		{
			$this->baseUrl = sprintf($this->baseUrl, $val);
		}
	}
	/*
	 * @针对接入特殊情况处理
	 */
	public function dataProc()
	{
		switch ($this->urlKey)
		{
			case 'api_shopInfo':
				$shopInfo = array();
				$shopInfo_arr = unserialize($this->result);
				$shopInfo['shop_id'] = (isset($shopInfo_arr['shop_id']) && ($shopInfo_arr['shop_id'] != '')) ? $shopInfo_arr['shop_id'] : '--';
				$shopInfo['shop_name'] = (isset($shopInfo_arr['shop_name']) && ($shopInfo_arr['shop_name'] != '')) ? mb_convert_encoding(Tools::truncate($shopInfo_arr['shop_name'], 40, 1) , 'UTF-8', 'GBK'): '--';
				$shopInfo['shop_url'] = (isset($shopInfo_arr['shop_url']) && ($shopInfo_arr['shop_url'] != '')) ? $shopInfo_arr['shop_url'] : '#';
				$shopInfo['product_num'] = (isset($shopInfo_arr['product_num']) && is_numeric($shopInfo_arr['product_num'])) ? number_format($shopInfo_arr['product_num']) : '0';
				$shopInfo['promo_num'] = (isset($shopInfo_arr['promo_num']) && ($shopInfo_arr['promo_num'] != '')) ? number_format($shopInfo_arr['promo_num']) : '0';
				$shopInfo['ad_num'] = (isset($shopInfo_arr['ad_num']) && ($shopInfo_arr['ad_num'] != '') && ($shopInfo_arr['ad_num'] != '-1')) ? number_format($shopInfo_arr['ad_num']) : '0';
				$shopInfo['shop_mark'] = (isset($shopInfo_arr['shop_mark']) && ($shopInfo_arr['shop_mark'] != '') && is_numeric($shopInfo_arr['shop_mark'])) ? $shopInfo_arr['shop_mark'] : '0';
				$shopInfo['question'] = (isset($shopInfo_arr['question']) && ($shopInfo_arr['question'] != '')) ? Tools::truncate($shopInfo_arr['question'], 40, 1) : '';
				$shopInfo['question_url'] = (isset($shopInfo_arr['question_url']) && ($shopInfo_arr['question_url'] != '')) ? $shopInfo_arr['question_url'] : '#';
				$this->result = json_encode($shopInfo);
				break;
			case 'api_shopADInfo':
				$adnum = json_decode($this->result);
				$shopInfo_arr['ad_num'] = $adnum[0]->total;
				$this->result = json_encode($shopInfo_arr);
				break;
			default:
				return 0;
				break;
		}
	}
	
	public static function falseTimeOut($urlKey, $dataArr, $startTime, $endTime, $time, $logFile)
	{
		if ($endTime - $startTime > $time)
		{
			$data = '[urlKey:'.$urlKey.'][param:'.json_encode($dataArr).']'.' false timeout in '.$time.'!';
			self::logger($logFile, $data);
		}
	}
}
?>