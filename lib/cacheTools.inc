<?php
class cacheTools
{
	public static function set($paramArr = array(), $priKey = array(), $content = array(), $lifeTime = 0, $type)
	{
		$type = strtolower($type);
		switch ($type)
		{
			case 'mem':
				memCacheTools::setCacheHost(Conf::$memCacheHost);
				$result = memCacheTools::set($paramArr, $priKey, $content, $lifeTime);
				break;
			case 'file':
				fileCacheTools::setCacheDir(PATH_CACHE);
				$result = fileCacheTools::set($paramArr, $priKey, $content, $lifeTime);
				break;
			default:
				$result = false;
				break;
		}
		return $result;
	}
	
	public static function get($paramArr = array(), $priKey = array(), $type)
	{
		$type = strtolower($type);
		switch ($type)
		{
			case 'mem':
				memCacheTools::setCacheHost(Conf::$memCacheHost);
				$result = memCacheTools::get($paramArr, $priKey);
				break;
			case 'file':
				fileCacheTools::setCacheDir(PATH_CACHE);
				$result = fileCacheTools::get($paramArr, $priKey);
				break;
			default:
				$result = false;
				break;
		}
		return $result;
	}
}

function __autoload($class)
{
	$file = PATH_LIB . '/cache/'.$class.'.inc';
	if (is_file($file))
	{
		include_once($file);
	}
}
?>