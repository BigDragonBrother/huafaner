<?php

include_once (PATH_LIB . "/myPDO.inc");
include_once (PATH_DAL . "/db.inc");
include_once(PATH_SMS."/sms.php");

class orderDal {

    static function orderok($user_id,$cust_name,$cust_title,$cust_province,$cust_city,$cust_town,
                $cust_address,$cust_mobile,$book_date,$book_card,$book_card_content,$payment,
                $prod_id,$order_quantity,$total,$coupon_id,$coupon_amount,$remarks,$only_order_id) 
    {
        $return="";
        $sql = "insert into hua_order 
        (user_id,cust_name,cust_title,cust_province,cust_city,cust_town,cust_address,cust_mobile,
        book_date,book_card,book_card_content,payment,prod_id,
        order_quantity,total,order_status,coupon_id,coupon_amount,remarks,only_order_id,cdate,udate)
        values ($user_id,'$cust_name','$cust_title','$cust_province','$cust_city','$cust_town',
            '$cust_address','$cust_mobile','$book_date','$book_card','$book_card_content','$payment',
            $prod_id,$order_quantity,$total,10,$coupon_id,$coupon_amount,'$remarks',
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
 
    static function orderop($newstatus,$order_id)
    {
        $sql="update hua_order set order_status=$newstatus where order_id=$order_id";
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
                huafaner_sendSMS($sms_type,$order['order_name'],$order_id,$order['order_mobile']);    
            }
        } 
        return $row;
    }

    static function order_update($order_id,$cust_name,$cust_mobile,$cust_province,$cust_city,$cust_town,$cust_address,
        $cust_zip,$order_name,$order_mobile,$book_date,$book_time,$book_card,$payment,$total,$shipping_type,$shipping_fee)
    {
        $sql="update hua_order set 
            cust_name='$cust_name',cust_mobile='$cust_mobile',cust_province='$cust_province',
            cust_city='$cust_city',cust_town='$cust_town',cust_address='$cust_address',
            cust_zip='$cust_zip',order_name='$order_name',order_mobile='$order_mobile',book_date='$book_date',
            book_time='$book_time',book_card='$book_card',payment='$payment',total=$total,shipping_type='$shipping_type',
            shipping_fee=$shipping_fee,udate=now() where order_id=$order_id";
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
        $sql = "select a.*,b.prod_name,b.prod_origin_price,b.prod_sale_price
        from hua_order a
        left join hua_prod b on a.prod_id=b.prod_id
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

    static function getOrders() {
        $sql = "select a.*,b.prod_name,b.prod_origin_price,b.prod_sale_price
            from hua_order a left join hua_prod b on a.prod_id=b.prod_id
            order by a.cdate desc
            ";
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