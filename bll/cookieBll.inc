<?php
include_once (PATH_LIB . "/cookie.inc");
include_once (PATH_LIB . "/tools.inc");

class cookieBll
{

    public static function setLoginCookie($user_id, $user_name)
    {
        $cookieSet = Conf::$cookieSet;
        $_COOKIE['user_id'] = $user_id;
        $_COOKIE['user_name'] = $user_name;
        $_COOKIE['ltime'] = time() + $cookieSet["numlifetime"];
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        setcookie("user_id", $_COOKIE['user_id'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("user_name", $_COOKIE['user_name'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("ltime", $_COOKIE['ltime'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);   
    }
    
    public static function setUsername($user_name)
    {
        $cookieSet = Conf::$cookieSet;
        $_COOKIE['user_name'] = $user_name;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        setcookie("user_name", $_COOKIE['user_name'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
    }
    
    public static function Logout()
    {
        $cookieSet = Conf::$cookieSet;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        $expire = time() - 3600;
        setcookie("user_id", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("user_name", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("user_email", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("user_mobile", 0, $expire, $cookieSet["path"], '.dangdang.com', $secure);
        setcookie("ltime", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
    }
    
    private static function clearCookie()
    {
        $cookieSet = Conf::$cookieSet;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        setcookie("axdata", "", time() - 3600, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("ltime", "", -1, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("vi_domain", "", time() - 3600, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("vi_history", "", time() - 3600, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("vi_history_point", "", time() - 3600, $cookieSet["path"], $cookieSet["domain"], $secure);
    }

    /**
     * 检查cookie是否登陆 返回用户信息对象
     * 根据用户登陆后的cookie生成userInfo对象
     */
    public static function checkLogin()
    {
        $ui = new userModel();

        //判断cookie中是否有dduser值，并且是否正确，决定是否跳转登录界面
        $cookieSet = Conf::$cookieSet;
        $LOGIN_URL = Conf::$urlSet["loginurl"];
        $ReturnUrl = urlencode('http://' . $_SERVER['SERVER_NAME'] . $_SERVER["REQUEST_URI"]);

        if (!empty($_COOKIE['ddemail']))
        {
            $ui->email = $_COOKIE['ddemail'];
            $ui->id = $_COOKIE['dduser'];
            $ui->nickname = $_COOKIE['ddnickname'];
        }
        else
        {
            Tools::redirectLogin($LOGIN_URL . $ReturnUrl);
            exit;
        }

        //判断是否超时，如果超时要重新登录
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        if (isset($_COOKIE['ltime']))
        {
            if ($_COOKIE['ltime'] >= time())
            {
                setcookie("ltime", time() + $cookieSet["numlifetime"], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
            }
            else
            {
                self::clearCookie();
                Tools::redirectLogin($LOGIN_URL . $ReturnUrl);
                exit;
            }
        }
        else
        {
            self::clearCookie();
            Tools::redirectLogin($LOGIN_URL . $ReturnUrl);
            exit;
        }


        $iv = mcrypt_create_iv(mcrypt_get_iv_size(MCRYPT_3DES, MCRYPT_MODE_ECB), MCRYPT_RAND);
        $key = Cookie::MakeMD5(base64_encode(Cookie::MakeMD5($ui->email . COOKIE_CRYPTO_KEY)));
        $axdata = base64_decode($_COOKIE['axdata']);
        $axdata = Cookie::decryptNET3DES($key, $iv, $axdata);

        if ($axdata != $ui->email)
        {
            $expire = time() - 3600;
            setcookie("dduser", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
            setcookie("ddemail", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
            setcookie("ddnickname", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
            setcookie("email", 0, $expire, $cookieSet["path"], '.dangdang.com', $secure);
            setcookie("nickname", 0, $expire, $cookieSet["path"], '.dangdang.com', $secure);
            setcookie("ltime", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
            setcookie("axdata", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
            //setcookie("permission",0,$expire, $cookieSet["path"], $cookieSet["domain"], $secure);
            echo Tools::alert('权限有变更，请重新登录！', "top.location.href='" . $LOGIN_URL . $ReturnUrl . "';");
            exit;
        }

        return $ui;
    }

    public static function setDomaincookie($domain)
    {
        $cookieSet = Conf::$cookieSet;
        $_COOKIE['vi_domain'] = $domain;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        setcookie("vi_domain", $_COOKIE['vi_domain'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
    }

    public static function getDomaincookie()
    {
        $cookieSet = Conf::$cookieSet;
        if (!empty($_COOKIE['vi_domain']) && !empty($_COOKIE['vi_domain']))
        {
            return $_COOKIE['vi_domain'];
        }
        else
            return false;
    }

    public static function setHistorycookie($url)
    {
        $cookieSet = Conf::$cookieSet;
        $_COOKIE['vi_history'] = $url;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        setcookie("vi_history", $_COOKIE['vi_history'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
    }

    public static function setHistoryPointcookie($point)
    {
        $cookieSet = Conf::$cookieSet;
        $_COOKIE['vi_history_point'] = $point;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        setcookie("vi_history_point", $_COOKIE['vi_history_point'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
    }

    public static function getHistorycookie()
    {
        $cookieSet = Conf::$cookieSet;
        if (!empty($_COOKIE['vi_history']) && !empty($_COOKIE['vi_history']))
        {
            return $_COOKIE['vi_history'];
        }
        else
            return false;
    }

    public static function getHistoryPointcookie()
    {
        $cookieSet = Conf::$cookieSet;
        if (!empty($_COOKIE['vi_history_point']) && !empty($_COOKIE['vi_history_point']))
        {
            return $_COOKIE['vi_history_point'];
        }
        else
            return false;
    }

}

?>
