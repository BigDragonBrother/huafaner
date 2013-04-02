<?php

class Tools {

    static public function getValue($key, $defaultValue = false) {
        if (!isset($key) OR empty($key) OR !is_string($key))
            return false;
        $ret = (isset($_POST[$key]) ? $_POST[$key] : (isset($_GET[$key]) ? $_GET[$key] : $defaultValue));

        if (is_string($ret) === true)
            $ret = urldecode(preg_replace('/((\%5C0+)|(\%00+))/i', '', urlencode($ret)));
        return !is_string($ret) ? $ret : stripslashes($ret);
    }

    /**
     *
     *  从一个二维数组中取出一列或多列的值组成一个新的数组     *  @String	$keyname为string型(即一个列名称) 返回一维数组
     *  @array	$keyname为array型(即多个列名称) 返回二维数组
     *  @array	$keyname为默认(即不输入列名称) 返回二维数组
     *
     */
    static public function array_arrange($array, $keynames = array(), $is_unique = false) {
        $result = array();
        if (!is_array($array) || count($array) == 0)
            return $result;

        //若keyname为数组型 则构建result数组结构
        if (is_array($keynames)) {
            //若keynames为空数组 则用原数组的所有列名称填充keynames
            if (count($keynames) == 0) {
                foreach ($array as $key => $value) {
                    $keynames = array_merge($keynames, array_keys($value));
                }
            }
            $keynames = array_unique($keynames);
            //初始化result结构
            foreach ($keynames as $key_kn => $value_kn) {
                $result = array_merge($result, array($value_kn => array()));
            }
        }

        //为result赋值
        foreach ($array as $key => $value) {
            if (is_array($keynames)) {
                foreach ($keynames as $key_kn => $value_kn) {
                    if (array_key_exists($value_kn, $value) && !($is_unique && in_array($value[$value_kn], $result[$value_kn])))
                        $result[$value_kn][] = $value[$value_kn];
                }
            }
            else if (array_key_exists($keynames, $value) && !($is_unique && in_array($value[$keynames], $result)))
                $result[] = $value[$keynames];
        }
        return $result;
    }

    /**
     *
     *  产生对象数组
     *  @array	$rowArray:	从数据库中取出的多条数据组成的数组     *  @Class	$infoClass	info类     *  @array	$mapArray		info 类的相关属性做为key值,分别对应$rowArray中数据的相应列,
     *  @String	$keyName		$rowArray中某一列名称
     *  @boolean	$onlyKey		$keyName是否为$rowArray中主键列名称：true是，false不是
     *  @return	array 	$objArray	由info对象组成的数据     *
     */
    public static function createObjectArray($rowArray, $infoClass, $mapArray, $keyName = 'id', $onlyKey = true) {
        $objArray = array();

        if (!empty($rowArray)) {
            foreach ($rowArray as $valArray) {
                $objInfo = new $infoClass();

                if (array_key_exists($valArray[$keyName], $objArray) && $onlyKey)
                    continue;
                foreach ($mapArray as $propertyName => $arrangeName) {
                    $objInfo->$propertyName = $valArray[$arrangeName];
                }
                if ($onlyKey) {
                    $objArray[$valArray[$keyName]] = $objInfo;
                } else {
                    $objArray[$valArray[$keyName]][] = $objInfo;
                }
            }
        }
        return $objArray;
    }

    static public function redirect($url, $baseUri = __PS_BASE_URI__) {
        if (isset($_SERVER['HTTP_REFERER']) AND ($url == $_SERVER['HTTP_REFERER']))
            header('Location: ' . $_SERVER['HTTP_REFERER']);
        else
            header('Location: ' . $baseUri . $url);
        exit;
    }

    static public function redirectLink($url) {
        header('Location: ' . $url);
        exit;
    }

    static public function redirectLogin($url) {
        $js = "<script>top.location.href='" . $url . "'</script>";
        echo $js;
    }

    static public function isSubmit($submit) {
        return (
                isset($_POST[$submit]) OR isset($_POST[$submit . '_x']) OR isset($_POST[$submit . '_y'])
                OR isset($_GET[$submit]) OR isset($_GET[$submit . '_x']) OR isset($_GET[$submit . '_y'])
                );
    }

    static public function throwError($errno, $message, $errfile, $errline) {
        $error_page = "/error.php";
        $error_url = $error_page;
        if (Conf::$isDebug) {
            $error_url .= "?REDIRECT_ERROR_NOTES=error: [$errno]$message";
            $error_url .= "<br>file: " . $errfile . "<br>line: " . $errline;
        }
        self::redirectLink($error_url);
        exit;
    }

    static public function get_user_ip() {
        $user_IP = (isset($_SERVER["HTTP_VIA"])) ? $_SERVER["HTTP_X_FORWARDED_FOR"] : $_SERVER["REMOTE_ADDR"];
        return $user_IP;
    }

    //给用户产生一个独一无二的令牌号    static public function genToken($len = 32, $md5 = true) {
        # Seed random number generator
        # Only needed for PHP versions prior to 4.2
        mt_srand((double) microtime() * 1000000);
        # Array of characters, adjust as desired
        $chars = array(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

        # Array indice friendly number of chars;
        $numChars = count($chars) - 1;
        $token = '';

        # Create random token at the specified length
        for ($i = 0; $i < $len; $i++)
            $token .= $chars[mt_rand(0, $numChars)];

        # Should token be run through md5?
        if ($md5) {

            # Number of 32 char chunks
            $chunks = ceil(strlen($token) / 32);
            $md5token = '';

            # Run each chunk through md5
            for ($i = 1; $i <= $chunks; $i++)
                $md5token .= md5(substr($token, $i * 32 - 32, 32));

            # Trim the token
            $token = substr($md5token, 0, $len);
        }
        return $token;
    }

    static public function myencode($html) {


        $len = strlen($html);
        $output = '';

        for ($i = 0; $i < $len; $i++) {
            $ch = $html[$i];
            $ch2 = ord($ch);
            if (($ch2 < 0x20) && ($ch2 != 0x0D) && ($ch2 != 0x0A) && ($ch2 != 0x09))
                continue;
            if ($ch == '%') {
                $output .= '%037';
            } else if (ord($ch) > 126) {
                $output .= '%' . ord($ch);
            } else
                $output .= $ch;
        }
        return $output;
    }

    static public function mydecode($html) {


        $len = strlen($html);
        $output = '';

        for ($i = 0; $i < $len; $i++) {
            $ch = $html[$i];
            if ($ch == '%') {
                $code = substr($html, $i + 1, 3);
                if ($code == '037') {
                    $output .= '%';
                    $i = $i + 3;
                } else {
                    $output .= chr($code);
                    $i = $i + 3;
                }
            } else
                $output .= $ch;
        }
        return $output;
    }

    static public function getCurrentPageUrl() {

        $pageURL = 'http';
        if (isset($_SERVER["HTTPS"]) && $_SERVER["HTTPS"] == "on") {
            $pageURL .= "s";
        }
        $pageURL .= "://";
        $pageURL .= isset($_SERVER['HTTP_X_FORWARDED_HOST']) ? $_SERVER['HTTP_X_FORWARDED_HOST'] : (isset($_SERVER['HTTP_HOST']) ? $_SERVER['HTTP_HOST'] : '');
        $pageURL .= $_SERVER["REQUEST_URI"];

        return $pageURL;
    }

    public static function truncate($instr, $len = 22, $po = 1) {
        $newstr;
        $pot = '';
        if ($po) {
            $pot = "...";
        }
        if (strlen($instr) > $len) {
            $newstr = self::msubstr($instr, 0, $len);
            $newstr = str_replace(" ", "&nbsp;", $newstr) . $pot;
            return $newstr;
        } else {
            return str_replace(" ", "&nbsp;", $instr);
        }
    }

    private static function msubstr($str, $start, $len) {

        $tmpstr = "";
        $strlen = $start + $len;
        for ($i = $start; $i < $strlen; $i++) {

            if (ord($str[$i]) > 0x80) {
                if ($i + 1 < $strlen) {
                    $tmpstr .= substr($str, $i, 2);
                }

                $i++;
            } else {
                $tmpstr .= substr($str, $i, 1);
            }
        }
        return $tmpstr;
    }

/// 是否需要mydecode
    public static function is_mydecode($is, $str) {
        if ($is)
            return mydecode($str);
        else {
            $str = @iconv('UTF-8', 'GBK' . '//IGNORE', $str); //过滤掉错误字符,防止xml解析错误
            return $str;
        }
    }

    public static function getMediumName($m_code) {
        return isset(Conf::$mediumName[$m_code]) ? Conf::$mediumName[$m_code] : "";
    }

    public static function getfile($url, $timeout = 10) {
        ini_set('user_agent', 'Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; Win64; x64; .NET CLR 2.0.50727; SLCC1; Media Center PC 5.0; .NET CLR 3.0.30618; .NET CLR 3.5.30729)');

        $content = file_get_contents($url);
        if (FALSE == $content) {
            if (function_exists('curl_init')) {
                $curl = curl_init();
                curl_setopt($curl, CURLOPT_URL, $url);
                curl_setopt($curl, CURLOPT_USERAGENT, 'Mozilla/5.0 (X11; U; Linux i686; zh-CN; rv:1.9.1.2) Gecko/20090729 Firefox/3.5.2 GTB5');
                curl_setopt($curl, CURLOPT_HEADER, 0);
                curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
                curl_setopt($curl, CURLOPT_TIMEOUT, $timeout);
                $tmpInfo = curl_exec($curl);
                curl_close($curl);
                if (FALSE !== stristr($tmpInfo, "HTTP/1.1 200 OK")) { //正确返回数据
                    return $tmpInfo;
                } else {
                    return FALSE;
                }
            } else {
                // Non-CURL based version...
                /*
                  $context =
                  array('http' =>
                  array('method' => 'GET',
                  'header' => 'Content-type: application/x-www-form-urlencoded'."\r\n".
                  'User-Agent: Mozilla/5.0 (X11; U; Linux i686; zh-CN; rv:1.9.1.2) Gecko/20090729 Firefox/3.5.2 GTB5'."\r\n".
                  'Content-length: 0'),
                  'content' => ""));
                  $contextid=stream_context_create($context);
                  $sock=fopen($url, 'r', false, $contextid);
                  if ($sock) {
                  $tmpInfo='';
                  while (!feof($sock))
                  $tmpInfo.=fgets($sock, 4096);

                  fclose($sock);
                  return $tmpInfo;
                  }else{
                  return FALSE;
                  } */
                return false;
            }
        } else {
            return $content;
        }
    }

    public static function alert($value, $JSCode = "") {
        if (!headers_sent())
            header('Content-Type: text/html; charset=gb2312');
        $Js = "<script language=javascript encode='gbk'>";
        $value = $value;
        if (!empty($value))
            $Js.="alert('" . $value . "');\r\n";
        $Js.=$JSCode . "\r\n";
        $Js.="</script>";
        return $Js;
    }

    public static function displayPrice($price) {
        return sprintf("%01.2f", $price);
    }

    public static function addCatepathZero($cpath) {
        $result = $cpath;
        $arr_cat = explode('.', $cpath);
        for ($i = 0; $i < 6 - count($arr_cat); $i++) {
            $cpath.=".00";
        }
        return $cpath;
    }

    public static function truncate_single_word($instr, $len = 22, $po = 1) {
        $newstr;
        $pot = '';
        if ($po) {
            $pot = "<span class='dot'>...</span>";
        }
        if (strlen($instr) > $len) {
            $newstr = self::msubstr_single_word($instr, 0, $len);
            //$newstr = str_replace(" ","&nbsp;",$newstr).$pot;
            $newstr = str_replace(" ", "&nbsp;", $newstr);
            return $newstr;
        } else {
            return str_replace(" ", "&nbsp;", $instr);
        }
    }

    private static function msubstr_single_word($str, $start, $len) {

        $tmpstr = "";
        $strlen = $start + $len;
        for ($i = $start; $i < $strlen; $i++) {

            if (ord($str[$i]) > 0x80) {
                if ($i + 1 < $strlen) {
                    $tmpstr .= substr($str, $i, 2);
                }
                $i++;
            } else {

                $tmpstr .= substr($str, $i, 1);
                //单词修正
                if ($i == $strlen - 1) {
//					echo ($i+1).":".strlen($str)."/".  strlen($tmpstr)."--";
                    $limit_length = strlen($str) - strlen($tmpstr);
                    for ($j = $i + 1; $j < strlen($str); $j++) {
                        if (ord($str[$j]) > 0x80) {
                            break;
                        }

                        else
                            $tmpstr .= substr($str, $j, 1);
                        if ($str[$j] == " ") {
                            break;
                        }
                    }
                }
            }
        }
        return $tmpstr;
    }

    public static function fixDataListColumn($key, $num) {
        if (array_key_exists($key, Conf::$dataListColumn_showtype)) {
            switch (Conf::$dataListColumn_showtype[$key]) {
                case "保留两位小数":
                    $num = number_format($num, 2);
                    break;
                case "千分位，保留整数":
                    $num = number_format($num);
                    break;
                case "千分位，保留两位小数":
                    $num = number_format($num, 2);
                    break;
                case "百分数，保留两位小数":
                    $num = number_format($num * 100, 2) . '%';
                    break;
                case "百分数，保留一位小数":
                    $num = number_format($num * 100, 1) . '%';
                    break;
            }
        }
        return $num;
    }

    //html的head部分插入js内容
    public static function head_insert($html, $js) {
        $res = $html;
        preg_match("/<head(.*?)>([\S\s]*?)<\/head>/is", $html, $out);
        if ($out && count($out) >= 2) {
            $res_str = '<head' . $out[1] . ">\r\r" . $js . "\r" . $out[2] . '</head>';
            $res = preg_replace("/<head.*?>(.*?)<\/head>/is", $res_str, $html);
        }
        return $res;
    }

    //html的body部分插入js内容
    public static function body_insert($html, $js) {
        $res = $html;
        preg_match("/<body(.*?)>/is", $html, $out);
        //var_dump($out);
        if ($out && count($out) >= 1) {
            $res_str = '<body' . $out[1] . ">\r\r" . $js;
            $res = preg_replace("/<body.*?>/is", $res_str, $html);
        }
        return $res;
    }

    //判断是否是utf8编码 Returns true if $string is valid UTF-8 and false otherwise.
    static function isUtf8($string) {
        // From http://w3.org/International/questions/qa-forms-utf-8.html
        return preg_match('%^(?:
        [\x09\x0A\x0D\x20-\x7E] # ASCII
        | [\xC2-\xDF][\x80-\xBF] # non-overlong 2-byte
        | \xE0[\xA0-\xBF][\x80-\xBF] # excluding overlongs
        | [\xE1-\xEC\xEE\xEF][\x80-\xBF]{2} # straight 3-byte
        | \xED[\x80-\x9F][\x80-\xBF] # excluding surrogates
        | \xF0[\x90-\xBF][\x80-\xBF]{2} # planes 1-3
        | [\xF1-\xF3][\x80-\xBF]{3} # planes 4-15
        | \xF4[\x80-\x8F][\x80-\xBF]{2} # plane 16
        )*$%xs', $string);
    }

    //使用post方式发出请求
    public static function myPost($url, $param) {
        $post_data = "";
        $o = "";
        foreach ($param as $k => $v) {
            $o.= "$k=" . urlencode($v) . "&";
        }
        $post_data = substr($o, 0, -1);
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt($ch, CURLOPT_HEADER, 0);
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        //为了支持cookie
        //curl_setopt($ch, CURLOPT_COOKIEJAR, 'cookie.txt');
        curl_setopt($ch, CURLOPT_POSTFIELDS, $post_data);
        $result = curl_exec($ch);
        return $result;
    }

    //检查email地址是否合法
    public static function checkEmail($inAddress) 
    {
        return (ereg("^([a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-])+", $inAddress));
    }

    //检查手机号是否合法    public static function checkMobile($str)
    {
        return preg_match("/^1[0-9]{2}[0-9]{8}$/", $str);
    }
    
    public static function miniPic($pic,$new_w,$new_h)
    {
        
    }

}

?>

