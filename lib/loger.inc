<?php
/**
 * class shopInfo
 *
 * п╢хуж╬
 *
 * @author:
*/
class loger  {

	public static function write($message) {
		$filename =sprintf(Conf::$log_path."app%s.log", date('Ymd')) ;
		$dir = '/'.trim(dirname($filename),'/').'/';
		loger::forceDirectory($dir);
		if($fd = @fopen($filename, "a")) {
			$file_size=filesize($filename);
			if($file_size<=1000000000) {
				$date = date("Y-m-d H:i:s",time());
				$str =  $date ." ". $message ."\r\n" ;
				fputs($fd, $str);
		//	fwrite($fd, $str);
			}
			fclose($fd);
		}
	}


	public static function writeobj($obj){
		self::write(__FUNCTION__.print_r($obj,true));
	}

       static function forceDirectory($dir){ // force directory structure
		return is_dir($dir) or (loger::forceDirectory(dirname($dir)) and mkdir($dir, 0777));
	}

}

?>