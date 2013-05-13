<?php
include_once PATH_DAL."/orderDal.inc";
include_once PATH_BLL.'/prodBll.inc';
include_once PATH_BLL.'/userBll.inc';
include_once PATH_SMS."/sms.php";

class orderBll
{
    static function orderok($user_id,$order_info,$book_card,$book_card_content,$book_date,
            $payment,$prod_id,$order_quantity,$coupon_id,$coupon_amount,$remarks,$only_order_id)
    {
        $order_info_arr = split(',',$order_info);
        $cust_name=$order_info_arr[0];
        $cust_title=$order_info_arr[1];
        $cust_province=$order_info_arr[2];
        $cust_city=$order_info_arr[3];
        $cust_town=$order_info_arr[4];
        $cust_address=$order_info_arr[5];
        $cust_mobile=$order_info_arr[6];

        $prod=prodBll::getProdByid($prod_id);
        $total=$prod['prod_sale_price']*$order_quantity-$coupon_amount;
        
        if($only_order_id=='')
        {
            $only_order_id=0;
        }
        
        userBll::addCust($user_id, $cust_title,$cust_name, $cust_province, $cust_city, $cust_town, $cust_address, $cust_mobile, 1);

        $return = orderDal::orderok($user_id,
                $cust_name,
                $cust_title,
                $cust_province,
                $cust_city,
                $cust_town,
                $cust_address,
                $cust_mobile,
                $book_date,
                $book_card,
                $book_card_content,
                $payment,
                $prod_id,
                $order_quantity,
                $total,
                $coupon_id,
                $coupon_amount,
                $remarks,
                $only_order_id);

        if($return!=0)
        {
            $user = userBll::getUserByid($user_id);
            $smsCode=huafaner_sendSMS(1,$user['user_name'],$return,$user['user_mobile'],$total,$payment);
        }
            

        return $return;
    }

    static function orderop($newstatus,$order_id,$order_cancel_desc)
    {
        $row = orderDal::orderop($newstatus,$order_id,$order_cancel_desc);
        if (!$row->isEmpty()) 
        {
            $order=self::getOrder($order_id);
            $user = userBll::getUserByid($order['user_id']);
            $sms_type=0;
            if($newstatus==50)
            {
                $sms_type=2;
            }
            if($newstatus==60)
            {
                $sms_type=3;
            }
            if($sms_type!=0)
            {
                huafaner_sendSMS($sms_type,$user['user_name'],$order_id,$user['user_mobile'],0,0);    
            }
        } 
        return $row->data;
    }
    
    static function order_update($order_id,$cust_name,$cust_province,
$cust_city,$cust_town,$cust_address,$cust_mobile,$book_date,
$book_card,$book_card_content,$order_sign,$remarks,$total_pay)
    {
        return orderDal::order_update(
$order_id,$cust_name,$cust_province,$cust_city,$cust_town,$cust_address,$cust_mobile,$book_date,
$book_card,$book_card_content,$order_sign,$remarks,$total_pay)->data;
    }

    static function getOrder($order_id)
    {
        return orderDal::getOrder($order_id);
    }

    static function getOnlyOrder($order_id)
    {
        return orderDal::getOnlyOrder($order_id);
    }
    
    static function getOrders($where,$page_num,$page_size)
    {
        return orderDal::getOrders($where,$page_num,$page_size)->data;
    }
    
    static function getOrdersByUserid($user_id,$page_num,$page_size)
    {
        return orderDal::getOrdersByUserid($user_id, $page_num, $page_size);
    }
    
    static function getOrderCntByUserid($user_id)
    {
        return orderDal::getOrderCntByUserid($user_id);
    }
    
    static function update_order_info($order_id,$order_info)
    {
        $order_info_arr = split(',',$order_info);
        $cust_name=$order_info_arr[0];
        $cust_province=$order_info_arr[1];
        $cust_city=$order_info_arr[2];
        $cust_town=$order_info_arr[3];
        $cust_address=$order_info_arr[4];
        $cust_zip=$order_info_arr[5];
        $cust_mobile=$order_info_arr[6];
        
        return orderDal::update_order_info($order_id,
                $cust_name,
                $cust_province,
                $cust_city,
                $cust_town,
                $cust_address,
                $cust_zip,
                $cust_mobile);
    }
    
    static function update_payment($order_id,$payment)
    {
        return orderDal::update_payment($order_id,$payment);
    }
    
    static function only_ok($user_id,$only_cust,$only_style,$only_emotion,$only_prod_id)
    {
        return orderDal::only_ok($user_id,
                $only_cust,
                $only_style,
                $only_emotion,
                $only_prod_id);
    }

    static function order_pay($order_id)
    {
        return orderDal::order_pay($order_id);
    }

    static function yeepay_log($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType)
    {
        return orderDal::yeepay_log($r0_Cmd,$r1_Code,$r2_TrxId,$r3_Amt,$r4_Cur,$r5_Pid,$r6_Order,$r7_Uid,$r8_MP,$r9_BType);
    }

    static function getLastOrderByUserid($user_id)
    {
        return orderDal::getLastOrderByUserid($user_id);
    }
}