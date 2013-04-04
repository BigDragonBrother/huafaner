<?php
/* 
 * class encrypt
 * �����࣬���ּ��ܽ��ܺ���
 * @author lvxin
 * @createdate 2010-04-02 11:52:23
*/
class encrypt {
	/*
	 * function MakeMD5
	 * ����md5����
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
	 * ���ַ�����������.net��3DES����
	 * @input string $key ��Կ
	 * @input string $text ��Ҫ���ܵ��ַ���
	 * @output string
	 *  ������
		| $strArray����Կ��$text��Ҫ���ܵ��ַ���                                                 |
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
	 * ��.net��3DES�����ַ������н���
	 * @input string $key ��Կ
	 * @input string $text ��Ҫ���ܵ��ַ���
	 * @output string
	 */
	static  function decryptNET3DES($key,$text) {
		if(empty($text)) return "";
		$td = mcrypt_module_open(MCRYPT_3DES, '', MCRYPT_MODE_ECB, '');

		// ��keyֵ������������PHP�������keyֵ����24λʣ�µĻ��Զ���0��������.net�У�����һ��ѭ����ǰ���ֵ���䵽���油��24λ����������ǿ�Ʋ�ǰ����ַ�
		$key_add = 24-strlen($key);
		$key .= substr($key,0,$key_add);
		$iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_3DES,MCRYPT_MODE_ECB),MCRYPT_RAND);

		mcrypt_generic_init($td, $key, $iv);
		$decrypt_text = mdecrypt_generic($td, $text);
		mcrypt_generic_deinit($td);
		mcrypt_module_close($td);

		//ȥ��padding��β�ͣ���Ϊ.net��Ĭ�ϵ�padding��PKCS7����php��Ĭ�ϵ�padding��zero��������.netʹ��Ĭ�ϵ�����£�Ҫ��php�����padding��������
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