<?php

include_once (PATH_LIB . "/myPDO.inc");
include_once (PATH_DAL . "/db.inc");

class userDal {

    static function Register($reg_email, $reg_pwd, $reg_name,$reg_mobile, $reg_invite) {
        $verify = self::searchUsername($reg_email);
        if (!empty($verify->data[0])) {
            return 2;
        }
        $user_id=0;
        if($reg_invite != '')
        {
            $sql="select user_id from hua_user where user_link='$reg_invite'";
            $row = DB::huaDB()->rowPrepare($sql);
            if (!is_object(DB::huaDB()))
                return array();
            $user_id=$row->data['user_id'];
        }

        $user_link = md5($reg_email);

        $sql = "insert into hua_user (user_email,user_pwd,user_name,user_mobile,user_link,user_from,cdate,udate)
            values ('$reg_email','$reg_pwd','$reg_name','$reg_mobile','$user_link',$user_id,now(),now())";
        $row = DB::huaDB()->simplePrepare($sql);
        if ($row->data) 
        {
            $return = 1;

            if ($reg_invite != '')
            {
                $sql = "update hua_user set user_invite=user_invite+1 where user_id=$user_id";
                DB::huaDB()->simplePrepare($sql);

                $sql="select user_invite from hua_user where user_id=$user_id";
                $row = DB::huaDB()->rowPrepare($sql);

                $coupon_amount=0;
                if($row->data['user_invite']=='5')
                {
                    $coupon_amount=20;
                }
                if($row->data['user_invite']=='10')
                {
                    $coupon_amount=50;
                }
                $coupon_name="花友会".$coupon_amount."元礼券";
                $coupon_valid=date("Y-m-d H:i:s", strtotime("+1 month"));
                
                if($coupon_amount>0)
                {
                    $sql="insert into hua_coupon (user_id,coupon_name,coupon_amount,coupon_valid,coupon_desc,coupon_status,cdate,udate)
                    values ($user_id,'$coupon_name',$coupon_amount,'$coupon_valid','全场任意消费可使用',1,now(),now())";
                    DB::huaDB()->simplePrepare($sql);
                }
            }
        } 
        else 
        {
            $return = 0;
        }

        return $return;
    }

    static function Login($user_email, $user_pwd) {
        $sql = "select * from hua_user 
            where (user_email='$user_email' or user_name='$user_email') and user_pwd='$user_pwd'";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }
    }

    static function getUser($user_email, $user_mobile) {
        $sql = "select * from hua_user 
            where user_mobile='$user_mobile' and user_email='$user_email'";
        if (empty($user_email) & !empty($user_mobile)) {
            $sql = "select * from hua_user 
            where user_mobile='$user_mobile'";
        }
        if (empty($user_mobile) & !empty($user_email)) {
            $sql = "select * from hua_user 
            where user_email='$user_email'";
        }
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }
    }

    static function getUserByid($user_id) {
        $sql = "select * from hua_user where user_id=$user_id";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }
    }

    static function getCustByuserid($user_id) {
        $sql = "select * from hua_cust where user_id=$user_id";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data;
        } else {
            return array();
        }
    }

    static function getCustByid($cust_id) {
        $sql = "select * from hua_cust where cust_id=$cust_id";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }
    }

    static function addCust($user_id, $cust_title,$cust_name, $cust_province, $cust_city, $cust_town, $cust_address, $cust_tel, $cust_default) {
        $sql="select count(1) from hua_cust 
        where user_id=$user_id and cust_title='$cust_title' and cust_name='$cust_name' and cust_province='$cust_province' and cust_city='$cust_city' and cust_town='$cust_town' and cust_address='$cust_address' and cust_tel='$cust_tel'";
        if (!is_object(DB::huaDB()))
                return array();
        $row = DB::huaDB()->rowPrepare($sql);
        if($row->data[0]>0)
        {
            return 1;
        }

        if ($cust_default) {
            $sql = "update hua_cust set cust_default=0 where user_id =$user_id";
            $row = DB::huaDB()->simplePrepare($sql);
        }
        $sql = "insert into hua_cust
            (user_id,cust_title,cust_name,cust_province,cust_city,cust_town,cust_address,cust_tel,cust_default,cdate,udate)
            values
            (
            $user_id,'$cust_title','$cust_name','$cust_province','$cust_city','$cust_town','$cust_address','$cust_tel',$cust_default,
            now(),now()
            )";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function updateCust($user_id, $cust_id, $cust_title,$cust_name, $cust_province, $cust_city, $cust_town, $cust_address, $cust_tel, $cust_default) {
        if ($cust_default) {
            $sql = "update hua_cust set cust_default=0 where user_id =$user_id";
            if (!is_object(DB::huaDB()))
                return array();
            $row = DB::huaDB()->simplePrepare($sql);
        }
        $sql = "update hua_cust set
        cust_title='$cust_title',cust_name='$cust_name',cust_province='$cust_province',
        cust_city='$cust_city',
        cust_town='$cust_town',cust_address='$cust_address',
        cust_tel='$cust_tel',cust_default=$cust_default,udate=now()
        where cust_id=$cust_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function delCust($cust_id) {
        $sql = "delete from hua_cust where cust_id=$cust_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function setDefaultCust($cust_id, $user_id) {
        $sql = "update hua_cust set cust_default=0 
        where user_id =$user_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        $sql = "update hua_cust set cust_default=1
            where cust_id=$cust_id";
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function searchUsername($user_email) {
        $sql = "select user_id from hua_user where user_email='$user_email'";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->rowPrepare($sql);
        return $row;
    }

    static function Edit_userinfo($user_name, $user_pwd, $newinfo, $type) {
        $sql = "update hua_user set $type='$newinfo'
            where user_name='$user_name' and $user_pwd='$user_pwd'";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function Edit_inform($user_id, $inform_order, $inform_newprod, $inform_web) {
        $sql = "update hua_user set inform_order=$inform_order,
                inform_newprod=$inform_newprod,inform_web=$inform_web
                where user_id=$user_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function getCouponByuserid($user_id) {
        $sql = "select * from hua_coupon where user_id=$user_id";
        $row = DB::huaDB()->allPrepare($sql);
        if (count($row->data) == 0) {
            return array();
        } else {
            return $row->data;
        }
    }

    static function getValidCouponByuserid($user_id, $coupon_status) {
        $sql = "select * from hua_coupon where user_id=$user_id and coupon_status=$coupon_status";
        $row = DB::huaDB()->allPrepare($sql);
        if (count($row->data) == 0) {
            return array();
        } else {
            return $row->data;
        }
    }

    static function reset_pwd($user_pwd,$user_id,$user_invite,$user_name)
    {
        if($user_name=="")
        {
            $sql="update hua_user set user_pwd='$user_pwd' where user_id=$user_id and user_link='$user_invite'";
        }
        else
        {
            $sql="update hua_user set user_pwd='$user_pwd' where user_name='$user_name'";
        }
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        return $row;
    }

}

?>