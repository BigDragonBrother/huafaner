<?php
include_once PATH_LIB . '/tools.inc';
include_once PATH_BLL . '/cookieBll.inc';

class loginBll
{

    public static function doLogin()
    {
        $user = trim(filter_input(INPUT_POST, 'txtUsername', FILTER_SANITIZE_STRING));
        $pass = filter_input(INPUT_POST, 'txtPassword', FILTER_SANITIZE_STRING);
        
        if (LDAP::link(Conf::$ldap_server['server'], $email, $pass))
        {
            $user_arr = LDAP::find($user);
            cookieBll::setLoginCookie($user, $email, $user_arr[0]);
            $returnURL = urldecode($_GET['ReturnUrl']);
            if (empty($returnURL))
                $returnURL = 'index.php';
            Tools::redirectLink($returnURL);
            exit;
        }else
            echo Tools::alert("员工邮箱不存在或密码输入错误！", "history.back(-1);");
    }

    public static function doLogout()
    {
        $cookieSet = Conf::$cookieSet;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        $expire = time() - 3600;
        setcookie("dduser", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("ddemail", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("ddnickname", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);

        setcookie("email", 0, $expire, $cookieSet["path"], '.dangdang.com', $secure);
        setcookie("nickname", 0, $expire, $cookieSet["path"], '.dangdang.com', $secure);

        setcookie("ltime", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        setcookie("axdata", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        //setcookie("permission",0,$expire, $cookieSet["path"], $cookieSet["domain"], $secure);

        $LOGIN_URL = Conf::$urlSet["loginurl"];
        $ReturnUrl = urlencode(Conf::$urlSet["homepage"]);
        Tools::redirectLink($LOGIN_URL . $ReturnUrl);
    }

}

?>