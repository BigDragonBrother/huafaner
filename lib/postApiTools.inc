<?php
abstract class postApiTools
{
	protected $urlKey;
	protected $baseUrl;
	protected $dataArr;
	protected $sendType;
	protected $assemType;
	protected $timeOut;
	protected $logFile;
	protected $result;
	protected $errMsg;
	
	public function __construct($urlKey, $baseUrl, $dataArr, $sendType, $assemType = 0, $timeOut = 0, $logFile)
	{
		$this->urlKey = $urlKey;
		$this->baseUrl = $baseUrl;
		$this->dataArr = $dataArr;
		$this->sendType = $sendType;
		$this->assemType = $assemType;
		$this->timeOut = $timeOut;
		$this->logFile = $logFile;
	}
	
	protected function assemData()
	{
		if (is_array($this->dataArr) && count($this->dataArr))
		{
			foreach ($this->dataArr as $key => $val)
			{
				$this->baseUrl = sprintf($this->baseUrl, $val);
			}
			return $this->baseUrl;
		}
		else
		{
			$this->errMsg = '[urlKey:'.$this->urlKey.']'.' data is not array or no data!';
		}
	}
	
	/*public function sendData()
	{
		switch($this->sendType)
		{
			case 'GET':
				if ($this->assemType == 0)
				{
					$this->assemData();
				}
				else
				{
					$assemFunc = 'assemData'.$this->assemType;
					if (method_exists($this, $assemFunc))
					{
						$this->$assemFunc();
					}
					else
					{
						$this->errMsg = $assemFunc.' is not exist!';
					}
				}
				if (!$this->errMsg)
				{
					$this->result = Tools::getfile($this->baseUrl, Conf::$api_timeout);
				}
				break;
			case 'POST':
				if ($this->assemType == 0)
				{
					$this->assemData();
				}
				else
				{
					$assemFunc = 'assemData'.$this->assemType;
					if (method_exists($this, $assemFunc))
					{
						$this->$assemFunc();
					}
					else
					{
						$this->errMsg = $assemFunc.' is not exist!';
					}
				}
				if (!$this->errMsg)
				{
					$this->result = Tools::myPost($this->baseUrl, $this->dataArr);
				}
				break;
			default:
				break;
		}
	}*/
	
	public function sendData()
	{
		if ($this->assemType == 0)
		{
			$this->assemData();
		}
		else
		{
			$assemFunc = 'assemData'.$this->assemType;
			if (method_exists($this, $assemFunc))
			{
				$this->$assemFunc();
			}
			else
			{
				$this->errMsg = '[urlKey:'.$this->urlKey.'][param:'.json_encode($this->dataArr).'] '.$assemFunc.' is not exist!';
			}
		}
		if (!$this->errMsg)
		{
			$this->result = self::mySend($this->baseUrl, $this->dataArr, $this->sendType, $this->timeOut);
		}
	}
	
	public function getResult()
	{
		
		if ($this->result && !$this->errMsg)
		{
			switch ($this->result)
			{
				case 11:
					$this->errMsg = '[urlKey:'.$this->urlKey.'][param:'.json_encode($this->dataArr).']  no send type!';
					self::logger($this->logFile, $this->errMsg);
					return -1;
					break;
				default:
					$this->dataProc();
					return $this->result;
					break;
			}
		}
		else if (!$this->result && !$this->errMsg)
		{
			$this->errMsg = '[urlKey:'.$this->urlKey.'][param:'.json_encode($this->dataArr).']'.' no data or timeout!';
			self::logger($this->logFile, $this->errMsg);
			return -1;
		}
		else if ($this->errMsg)
		{
			self::logger($this->logFile, $this->errMsg);
			return -1;
		}
	}
	
	public static function logger($file, $data)
	{
		$inPutTime = time();
		if ($fp = fopen($file, 'a')) 
		{
			$startTime = microtime(true);
			do 
			{
				$canWrite = flock($fp, LOCK_EX);
				if (!$canWrite)
				{
					usleep(1);
				}

			} while ((!$canWrite) && ((microtime(true) - $startTime) < 1000));
			if ($canWrite)
			{
				fwrite($fp, date('Y-m-d H:i:s', $inPutTime).' '.$data."\r\n");
				flock($fp, LOCK_UN);
			}
			fclose ($fp);
		}
	}
	
	abstract protected function dataProc();
	
	public static function mySend($baseUrl, $dataArr = array(), $sendType, $timeOut = 0)
	{
		switch ($sendType)
		{
			case 'GET':
				$opts = array('http' =>
							array(
								'method' => 'GET',
							)
						);
				break;
			case 'POST':
				$postData = array();
				$opts = array('http' =>
							array(
								'method' => 'POST',
								'header'  => 'Content-type: application/x-www-form-urlencoded',
							)
						);
				if (count($dataArr))
				{
					$postData = http_build_query($dataArr);
					$opts['http']['content'] = $postData;
				}
				else
				{
					return 11;
				}
				break;
			default:
				return 10;
				break;
		}
		if ($timeOut !== 0)
		{
			$opts['http']['timeout'] = $timeOut;
		}
		$context = stream_context_create($opts);
		if ($baseUrl)
		{
			$result = file_get_contents($baseUrl, false, $context);
		}
		return $result;
	}
}
?>