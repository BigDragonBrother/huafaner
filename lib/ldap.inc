<?php

class LDAP
{
    /* ---------------------------------------------------------*\
      | ldap_link($user,$pass)��ͨ���û������������Ƿ�Ϊ�����û�|
      | ldap_find($findstr):ͨ���������ߵ�¼�������û���Ϣ        |
      \*--------------------------------------------------------- */


    /* @ͨ��user��pass�ж��Ƿ�Ϊ����Ա��������¼��Ϣ
     * @param user ����Ա���û�������ʽΪ��xxx@dangdang.com
     * @param pass �û�����
     * @back ����boolֵ
     * @author Lvxin
     * @modified  08.06.13
      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     */

    public static function link($server, $user, $pass)
    {
        global $connect, $base_cn;
        $LDAP_SERVER = $server;
        $base_cn = "ou=KeWenDangDang,dc=dangdang,dc=com";
        $connect = ldap_connect($LDAP_SERVER) or die("������æ�����Ժ����ԣ�");
        return @ldap_bind($connect, $user, $pass);
    }

    /*
      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     */

    /* @ͨ��$findstr�����û���Ϣ
     * @param findstr ����Ա���û���������������ʽΪ��xxx@dangdang.com���ߺ���
     * @back �������飬0Ϊ������1Ϊ�û�����2Ϊ����
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
        $result = @ldap_search($connect, $base_cn, $filter, $attributes) or die("������æ�����Ժ����ԣ�");
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