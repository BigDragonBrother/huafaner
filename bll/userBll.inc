<?php

include_once PATH_DAL . "/userDal.inc";
include_once PATH_BLL . '/cookieBll.inc';

class userBll {

    static function Register($reg_email, $reg_pwd,$reg_name,$reg_mobile,$reg_invite) {
        $result = userDal::Register($reg_email, $reg_pwd,$reg_name,$reg_mobile,$reg_invite);
        if($result==1)
        {
            self::Login($reg_email, $reg_pwd);
            return 1;
        }
        return $result;
    }

    public static function Login($user_email, $user_pwd) {
        $user = userDal::Login($user_email, $user_pwd);
        if (!empty($user)) {
            cookieBll::setLoginCookie($user['user_id'], $user['user_name']);
            return 1;
        } else {
            return 0;
        }
    }
    
    public static function confirmUser($user_name,$user_pwd)
    {
        $user=userDal::Login($user_name, $user_pwd);
        if (!empty($user)) {
            return 1;
        } else {
            return 0;
        }
    }
    public static function getUserByid($user_id)
    {
        return userDal::getUserByid($user_id);
    }
    public static function doLogout() {
        cookieBll::Logout();
    }

    public static function getCustByuserid($user_id) {
        $cust_list = userDal::getCustByuserid($user_id);
        return $cust_list;
    }

    public static function getCustByid($cust_id) {
        return userDal::getCustByid($cust_id);
    }

    public static function getMiniCust($cust_list) {
        $return = array();
        foreach ($cust_list as $k => $v) {
            $return[$v['cust_id']] = array($v['cust_default'],
                implode(',', array($v['cust_name'],$v['cust_title'], $v['cust_province'], $v['cust_city'], $v['cust_town'], $v['cust_address'],  $v['cust_tel'])));
        }
        return $return;
    }

    public static function addCust($user_id, $cust_title,$cust_name, $cust_province, $cust_city, $cust_town, $cust_address, $cust_tel, $cust_default) {
        return userDal::addCust($user_id, $cust_title,$cust_name,  $cust_province, $cust_city, $cust_town, $cust_address, $cust_tel, $cust_default);
    }

    public static function updateCust($user_id,$cust_id, $cust_title,$cust_name, $cust_province, $cust_city, $cust_town, $cust_address, $cust_tel, $cust_default) {
        return userDal::updateCust($user_id,$cust_id, $cust_title,$cust_name, $cust_province, $cust_city, $cust_town, $cust_address, $cust_tel, $cust_default);
    }
    
    public static function delCust($cust_id) {
        return userDal::delCust($cust_id);
    }

    public static function setDefaultCust($cust_id,$user_id)
    {
        return userDal::setDefaultCust($cust_id,$user_id);
    }
    
    public static function searchUsername($user_name)
    {
        return userDal::searchUsername($user_name)->data[0];
    }
    
    public static function Edit_userinfo($user_name,$user_pwd,$newinfo,$type)
    {
        $return = userDal::Edit_userinfo($user_name,$user_pwd,$newinfo,$type);
        if($type=='user_name'&$return)
        {
            cookieBll::setUsername($newinfo);
        }
        return $return;
    }
    
    public static function Edit_inform($user_id,$inform_order,$inform_newprod,$inform_web)
    {
        $return = userDal::Edit_inform($user_id,$inform_order,$inform_newprod,$inform_web);
        return $return;
    }
    
    public static function getCouponByuserid($user_id)
    {
        return userDal::getCouponByuserid($user_id);
    }
    
    public static function getValidCouponByuserid($user_id,$coupon_status=1)
    {
        return userDal::getValidCouponByuserid($user_id, $coupon_status);
    }

    public static function reset_pwd($user_pwd,$user_id,$user_invite,$user_name)
    {
        return userDal::reset_pwd($user_pwd,$user_id,$user_invite,$user_name)->data;
    }
}

?>