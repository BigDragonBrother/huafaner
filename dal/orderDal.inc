<?php
include_once (PATH_LIB . "/myPDO.inc");
include_once (PATH_DAL . "/db.inc");
//include_once(PATH_SMS."/sms.php");

class orderDal {

    static function orderok($user_id,$cust_name,$cust_title,$cust_province,$cust_city,$cust_town,
                $cust_address,$cust_mobile,$book_date,$book_card,$book_card_content,$payment,
                $prod_id,$order_quantity,$total,$coupon_id,$coupon_amount,$remarks,$only_order_id) 
    {
        $return="";
        $sql = "insert into hua_order 
        (user_id,cust_name,cust_title,cust_province,cust_city,cust_town,cust_address,cust_mobile,
        book_date,book_card,book_card_content,payment,prod_id,
        order_quantity,total,total_pay,order_status,coupon_id,coupon_amount,remarks,only_order_id,cdate,udate)
        values ($user_id,'$cust_name','$cust_title','$cust_province','$cust_city','$cust_town',
            '$cust_address','$cust_mobile','$book_date','$book_card','$book_card_content','$payment',
            $prod_id,$order_quantity,$total,$total,10,$coupon_id,$coupon_amount,'$remarks',
            $only_order_id,now(),now())";

        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            $return = DB::huaDB()->lastInsertId();
        } else {
            return 0;
        }

        //$sql="update hua_user set user_last_name='$order_name', user_last_mobile='$order_mobile'
        //    where user_id=$user_id";
        //DB::huaDB()->simplePrepare($sql);
        
        if ($coupon_id != "") {
            $sql = "update hua_coupon set coupon_status=2 where coupon_id=$coupon_id";
            DB::huaDB()->simplePrepare($sql);
        }
        
        //$smsCode=huafaner_sendSMS(1,$order_name,trim($return),$order_mobile,$total,$payment);
        return $return;
    }
 
    static function orderop($newstatus,$order_id,$order_cancel_desc)
    {
        $a="";
        switch ($newstatus) {
            case 0:
                $a=",cancel_date=now()";
                break;
            case 20:
                $a=",pay_date=now()";
                break;
            case 30:
                $a=",confirm_date=now()";
                break;
            case 50:
                $a=",send_date=now()";
                break;
            case 60:
                $a=",finish_date=now()";
                break;
            default:
                break;
        }
        if($newstatus==0)
        {
            $sql="update hua_order set order_status=$newstatus,
        order_cancel_desc='$order_cancel_desc',udate=now() $a
        where order_id=$order_id";
        }
        else
        {
            $sql="update hua_order set order_status=$newstatus,udate=now() $a where order_id=$order_id";
        }
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) 
        {
            $order=self::getOrder($order_id);
            $sms_type=0;
            if($newstatus==40)
            {
                $sms_type=2;
            }
            if($newstatus==50)
            {
                $sms_type=3;
            }
            if($sms_type!=0)
            {
                //huafaner_sendSMS($sms_type,$order['order_name'],$order_id,$order['order_mobile']);    
            }
        } 
        return $row;
    }

    static function order_update($order_id,$cust_name,$cust_province,$cust_city,$cust_town,$cust_address,$cust_mobile,$book_date,$book_card,$book_card_content,$order_sign,$remarks,$total_pay)
    {
        if($total_pay=="")
            $total_pay=0;
        $sql="update hua_order set 
            cust_name='$cust_name',cust_province='$cust_province',cust_city='$cust_city',
            cust_town='$cust_town',cust_address='$cust_address',cust_mobile='$cust_mobile',
            book_date='$book_date',book_card='$book_card',book_card_content='$book_card_content',
            order_sign='$order_sign',remarks='$remarks',total_pay=$total_pay,udate=now() 
            where order_id=$order_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        return $row;
    }

    static function update_order_info($order_id, $cust_name, $cust_province, $cust_city, $cust_town, $cust_address, $cust_zip, $cust_mobile) {
        $sql = "update hua_order set 
            cust_name='$cust_name',cust_province='$cust_province',cust_city='$cust_city',cust_town='$cust_town',
            cust_address='$cust_address',cust_zip='$cust_zip',cust_mobile='$cust_mobile'
        where order_id=$order_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function update_payment($order_id, $payment) {
        $sql = "update hua_order set payment='$payment' where order_id=$order_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return 1;
        } else {
            return 0;
        }
    }

    static function getOrder($order_id) {
        $sql = "select a.*,b.prod_name,b.prod_sale_price,c.dict_name,d.user_name,
        d.user_email,d.user_mobile,e.pic_path
        from hua_order a
        left join hua_prod b on a.prod_id=b.prod_id
        left join hua_prod_pic e on b.prod_id=e.prod_id and e.pic_seq=1
        left join hua_dict c on b.prod_type=c.dict_id
        left join hua_user d on a.user_id=d.user_id
        where order_id=$order_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->allPrepare($sql);
        if (count($row->data) == 0) {
            return array();
        } else {
            return $row->data[0];
        }
    }

    static function getOnlyOrder($order_id) {
        $sql = "select a.*,b.prod_name,b.prod_origin_price,b.prod_sale_price
        from hua_only a
        left join hua_prod b on a.only_prod_id=b.prod_id
        where a.only_order_id=$order_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->allPrepare($sql);
        if (count($row->data) == 0) {
            return array();
        } else {
            return $row->data[0];
        }
    }

    static function getOrders($where,$page_num=1,$page_size=10) {
        $start = $page_size*($page_num-1);
        $sql = "select a.*,b.prod_name,b.prod_sale_price,c.dict_name
            from hua_order a 
            left join hua_prod b on a.prod_id=b.prod_id
            left join hua_dict c on b.prod_type=c.dict_id
            $where order by a.cdate desc limit $start,$page_size";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getOrdersByUserid($user_id, $page_num, $page_size) {
        $start = $page_size * ($page_num - 1);
        $sql = "select a.*,b.prod_name
            from hua_order a left join hua_prod b on a.prod_id=b.prod_id
            where a.user_id=$user_id
            order by a.cdate desc
            limit $start,$page_size";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->allPrepare($sql);
        if (count($row->data) == 0) {
            return array();
        } else {
            return $row->data;
        }
    }

    static function getOrderCntByUserid($user_id) {
        $sql = "select count(1) from hua_order where user_id=$user_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->rowPrepare($sql);
        return $row->data[0];
    }

    static function only_ok($user_id, $only_cust, $only_style, $only_emotion, $only_prod_id) {
        $sql="insert into hua_only (user_id,only_cust,only_style,only_emotion,only_prod_id,cdate,udate)
            values ($user_id, '$only_cust', '$only_style', '$only_emotion', $only_prod_id,now(),now())";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return DB::huaDB()->lastInsertId();
        } else {
            return 0;
        }
    }

    static function order_pay($order_id)
    {
        $order=self::getOrder($order_id);
        if(empty($order))
            return 0;
        if($order['order_status']<=10)
        {
            $sql="update hua_order set order_status=20 where order_id=$order_id";
            if (!is_object(DB::huaDB()))
                return array();
            $row = DB::huaDB()->simplePrepare($sql);
        }
        return 1;
    }

    static function yeepay_log($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType)
    {
        $content=$r0_Cmd.'_'.$r1_Code.'_'.$r2_TrxId.'_'.$r3_Amt.'_'.$r4_Cur.'_'.$r5_Pid.'_'.$r6_Order.'_'.$r7_Uid.'_'.$r8_MP.'_'.$r9_BType;
        $sql="insert into yeepay_log (cdate,content) values (now(),'$content')";
        if (!is_object(DB::huaDB()))
                return array();
        $row = DB::huaDB()->simplePrepare($sql);
    }

    static function getLastOrderByUserid($user_id)
    {
        $sql="select * from hua_order where user_id=$user_id order by cdate desc limit 1";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->allPrepare($sql);
        if (count($row->data) == 0) {
            return array();
        } else {
            return $row->data[0];
        }
    }
}