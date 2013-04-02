<?php
/* 
 * class encrypt
 * 加密类，各种加密解密函数
 * @author lvxin
 * @createdate 2010-04-02 11:52:23
*/
class encrypt {
	/*
	 * function MakeMD5
	 * 进行md5加密
	 * @input string $strArray
	 * @output string
	*/
	static function MakeMD5($strArray) {
		$sb = md5($strArray);
		$sb = pack('H*',$sb);
		return $sb;
	}

	/*
	 * function encryptNET3DES
	 * 对字符串进行类似.net的3DES加密
	 * @input string $key 密钥
	 * @input string $text 需要加密的字符串
	 * @output string
	 *  用例：
		| $strArray是密钥，$text是要加密的字符串                                                 |
		| $key_string = MakeMD5(base64_encode(MakeMD5($strArray)));                     |
		| $encryptstring = base64_encode(encryptNET3DES($key_string,$text));            |
	*/
	static function encryptNET3DES($key,$text) {
		if(empty($text)) return "";
		$td = mcrypt_module_open(MCRYPT_3DES, '', MCRYPT_MODE_ECB, '');
		// Complete the key
		$key_add = 24-strlen($key);
		$key .= substr($key,0,$key_add);
		// Padding the text
		$block = mcrypt_get_block_size('tripledes', 'ecb');
		$len = strlen($text);
		$padding = $block - ($len % $block);
		$text .= str_repeat(chr($padding),$padding);
		$iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_3DES,MCRYPT_MODE_ECB),MCRYPT_RAND);

		mcrypt_generic_init ($td, $key, $iv);
		$encrypt_text = mcrypt_generic ($td, $text);
		mcrypt_generic_deinit($td);
		mcrypt_module_close($td);
		return $encrypt_text;
	}

	/*
	 * function decryptNET3DES
	 * 对.net的3DES加密字符串进行解密
	 * @input string $key 密钥
	 * @input string $text 需要解密的字符串
	 * @output string
	 */
	static  function decryptNET3DES($key,$text) {
		if(empty($text)) return "";
		$td = mcrypt_module_open(MCRYPT_3DES, '', MCRYPT_MODE_ECB, '');

		// 把key值补充完整，在PHP里面如果key值不够24位剩下的会自动补0，但是在.net中，会做一个循环把前面的值补充到后面补够24位，所以这里强制补前面的字符
		$key_add = 24-strlen($key);
		$key .= substr($key,0,$key_add);
		$iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_3DES,MCRYPT_MODE_ECB),MCRYPT_RAND);

		mcrypt_generic_init($td, $key, $iv);
		$decrypt_text = mdecrypt_generic($td, $text);
		mcrypt_generic_deinit($td);
		mcrypt_module_close($td);

		//去掉padding的尾巴，因为.net中默认的padding是PKCS7，而php中默认的padding是zero，所以在.net使用默认的情况下，要将php程序的padding重新设置
		$block = mcrypt_get_block_size('tripledes', 'ecb');
		$packing = ord($decrypt_text{strlen($decrypt_text)-1});
		if($packing and ($packing < $block)) {
			for($P=strlen($decrypt_text)-1; $P>=strlen($decrypt_text)-$packing; $P--) {
				if(ord($decrypt_text{$P}) != $packing) {
					$packing = 0;
				}
			}
		}
		$decrypt_text = substr($decrypt_text,0,strlen($decrypt_text) - $packing);
		return $decrypt_text;
	}
}
?>
