<?php

class LDAP
{
    /* ---------------------------------------------------------*\
      | ldap_link($user,$pass)：通过用户名和密码检测是否为当当用户|
      | ldap_find($findstr):通过姓名或者登录名返回用户信息        |
      \*--------------------------------------------------------- */


    /* @通过user和pass判断是否为当当员工并检测登录信息
     * @param user 当当员工用户名，格式为：xxx@dangdang.com
     * @param pass 用户密码
     * @back 返回bool值
     * @author Lvxin
     * @modified  08.06.13
      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     */

    public static function link($server, $user, $pass)
    {
        global $connect, $base_cn;
        $LDAP_SERVER = $server;
        $base_cn = "ou=KeWenDangDang,dc=dangdang,dc=com";
        $connect = ldap_connect($LDAP_SERVER) or die("服务器忙，请稍候再试！");
        return @ldap_bind($connect, $user, $pass);
    }

    /*
      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     */

    /* @通过$findstr返回用户信息
     * @param findstr 当当员工用户名或者姓名，格式为：xxx@dangdang.com或者汉字
     * @back 返回数组，0为姓名，1为用户名，2为部门
     * @author Lvxin
     * @modified  08.06.13
      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     */

    public static function find($findstr)
    {
        global $connect, $base_cn;
        $rv = array("", "", "");
        $attributes = array("mail", "cn");
        $filter = "(|(cn=$findstr)(mail=$findstr@dangdang.com))";
        $result = @ldap_search($connect, $base_cn, $filter, $attributes) or die("服务器忙，请稍候再试！");
        $info = ldap_get_entries($connect, $result);
        if ($info['count'] != 0)
        {
            $username = $info[0]['mail'][0];
            $username = substr($username, 0, strpos($username, "@"));
            $truename = $info[0]['cn'][0];
            $dn = $info[0]['dn'];
            $dn_arr = explode(",", $dn);
            array_pop($dn_arr);
            array_pop($dn_arr);
            array_pop($dn_arr);
            $depart = substr($dn_arr[count($dn_arr) - 1], 3);
            $rv[0] = $truename;
            $rv[1] = $username;
            $rv[2] = $depart;
        }
        return $rv;
    }

}

?>
