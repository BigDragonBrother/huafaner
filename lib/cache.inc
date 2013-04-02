<?

$cache_active = true;
$cache_folder = "./cache/";

//cache files
class  acmeCache{

	static function fetch($name, $refreshSeconds = 3600){
		$cacheContent = "";
		if(!$GLOBALS['cache_active']) return false;
		if(!$refreshSeconds) $refreshSeconds = 60;
		$cacheFile = acmeCache::cachePath($name);
		if(file_exists($cacheFile) and
				((time()-filemtime($cacheFile))< $refreshSeconds))
			$cacheContent = file_get_contents($cacheFile);
		return $cacheContent;
	}

	static function save($name, $cacheContent,$expiration=300){
		if(!$GLOBALS['cache_active']) return;
		$cacheFile = acmeCache::cachePath($name);
		acmeCache::savetofile($cacheFile, $cacheContent);
	}

	// for internal use
	// ====================
	static function cachePath($name){
		$cacheFolder = $GLOBALS['cache_folder'];
		if(!$cacheFolder) $cacheFolder = trim($_SERVER['DOCUMENT_ROOT'],'/').'/cache/';
		return $cacheFolder . md5(strtolower(trim($name))) . '.cache';
	}

	static function savetofile($filename, $data){
		//$dir = trim(dirname($filename),'/').'/';
		//acmeCache::forceDirectory($dir);
		$file = fopen($filename, 'w');
		fwrite($file, $data); fclose($file);
	}

	static function forceDirectory($dir){ // force directory structure
		return is_dir($dir) or (acmeCache::forceDirectory(dirname($dir)) and mkdir($dir, 0777));
	}

}



//cache object
class qdbmCache{

	static function fetch($key, $refreshSeconds = 3600){
		$cacheContent = "";
		if(!$GLOBALS['cache_active']) return false;
		if(!$refreshSeconds) $refreshSeconds = 60;
		$cacheFile = qdbmCache::cachePath();
		if(file_exists($cacheFile))
		{
			$id = dba_open($cacheFile, "c", "qdbm");
			if (!$id) {
				echo $cacheFile." fetch dba_open failed\n";
				exit;
			}

			if (dba_exists($key."_TIME",$id)){
				$cache_time = unserialize(dba_fetch($key."_TIME",$id));
				if(time()<$cache_time+$refreshSeconds){
					if (dba_exists($key, $id)) {
						$cacheContent = dba_fetch($key, $id);
					}
				}
			}
			dba_close($id);
		}
		return unserialize($cacheContent);
	}

	static function save($key, $cacheContent,$expiration=300){
		if(!$GLOBALS['cache_active']) return;
		$cacheFile = qdbmCache::cachePath();
		qdbmCache::savetofile($cacheFile,$key, $cacheContent);
		qdbmCache::savetofile($cacheFile,$key."_TIME",time());
	}

	// for internal use
	// ====================
	static function cachePath(){
		$cacheFolder = $GLOBALS['cache_folder'];
		if(!$cacheFolder) $cacheFolder = trim($_SERVER['DOCUMENT_ROOT'],'/').'/cache/';
		return $cacheFolder . 'cache.db';
	}

	static function savetofile($filename, $key,$data){
		//$dir = trim(dirname($filename),'/').'/';
		//qdbmCache::forceDirectory($dir);
		$id = dba_open($filename, "c", "qdbm");
		if (!$id) {
			echo $filename." save dba_open failed\n";
			exit;
		}
		dba_replace($key, serialize($data), $id);
		dba_close($id);
	}

	static function forceDirectory($dir){ // force directory structure
		return is_dir($dir) or (qdbmCache::forceDirectory(dirname($dir)) and mkdir($dir, 0777));
	}

}

class memCache
{
	static public function getMemcached()
	{
		static $instance;
		if (!is_object($instance)) {

			$instance = new Memcached();
			$data = Conf::$memCacheHost;
			$instance->addServers($data);
	    }
		return $instance;
	}

	static public function save($key,$value,$expiration=300)
	{
		//loger::write($key);
		self::getMemcached()->set($key,$value,$expiration);
	}

	static public function fetch($key,$expiration=300)
	{
		return self::getMemcached()->get($key);
	}

	static public function delete($key)
	{
		return self::getMemcached()->delete($key);
	}

        static public function flush()
        {
            return self::getMemcached()->flush();
        }

}


/**************************
*
*根据url 返回 url 指向的 html 代码.
*
**************************/
function getHtmlbyUrl($url)
{
	return file_get_contents($url);

	/*
	$handle = fopen($url,"rb");
	$contents = "";
	do {
		$data = fread($handle, 8192);
		if (strlen($data) == 0) {
			break;
		}
		$contents .= $data;
	} while(true);
	fclose ($handle);
	return $contents;
	*/

}

/**************************
*
*根据url 返回 url 指向的 html 代码.
* 带 cacch
**************************/
function getCatchHtmlbyUrl($url)
{
	$result = acmeCache::fetch($url,3600);
	if(!$result){
		$result = getHtmlByUrl($url);
		acmeCache::save($url,$result);
	}
	/*else
	{
		echo('cached result</br>');
	}
	*/
	return $result;
}

?>