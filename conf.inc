<?php
ini_set('display_errors', 1);
define('PATH_ROOT', dirname(__FILE__));
define('PATH_BLL', PATH_ROOT . '/bll');
define('PATH_DAL', PATH_ROOT . '/dal');
define('PATH_LIB', PATH_ROOT . '/lib');
define('PATH_MODEL', PATH_ROOT . '/model');
define('PATH_INC', PATH_ROOT . '/inc');
define('PATH_PIC',PATH_ROOT.'/picture/');
define('PATH_SMS',PATH_ROOT.'/sms');
define('PATH_ADMIN', PATH_ROOT . '/admin');

class Conf
{
    public static $adminuser=array("admin"=>"admin","pwd"=>"123qwe");
    //database  
    public static $huaBase = array("dbtype" => "mysql", "database" => "huafaner", "username" => "root", "password" => "root", "server" => "127.0.0.1"); 
    //cookie
    public static $pageSet = array("page_size" => 10, "cache_time" => 30, "cache_type" => "mem");
    public static $cookieSet = array('domain' => 'huafanerb.com', 'path' => '/', 'lifetime' => 144000, 'numlifetime' => 14400);
    public static $urlSet = array('registerurl'=>'http://huafanerb.com/index.php?t=reg','loginurl' => 'http://huafanerb.com/index.php?t=login', 'homepage' => 'http://huafanerb.com/index.php','domain'=>'http://huafanerb.com/huafaner/');
    
    //memcache
    public static $memCacheHost = array(array('127.0.0.1', 11211, 33), array('127.0.0.1', 11211, 33));
    public static $memCacheTime = 14400; 
    public static $permitInfoMemCacheKey = "p%s";
    //路径
    public static $log_path = '/var/www/huafaner/log/';
    public static $titleArr=array(0=>"后台管理",1=>"");
    public static $picArr=array('jpg','gif','jpeg');
    public static $pic_path="http://huafanerb.com/huafaner/";
   
    //各种状态
    public static $order_status=array("0"=>"交易取消","10"=>"未支付","20"=>"待确认","30"=>"正在配花","40"=>"正在配送","50"=>"交易成功");
    public static $coupon_status=array("0"=>"已过期","1"=>"有效","2"=>"已使用");
    public static $prod_onshelf_status=array(1=>"上架",2=>"定时上架",3=>"仓库中");
    public static $prod_cat=array(1=>"普通商品",2=>"定制商品");
    public static $prod_tag_type=array("分类"=>"tag_1","标签"=>"tag_2");
    public static $prod_pic_seq=array("列表页"=>0,"缩略图"=>1,"详情图"=>2);
    public static $dict_type=array("prod_type"=>"商品类型","tag_2"=>"标签");
    //字典信息
    public static $account=array("name"=>"高玮玮","bank"=>"招商银行","num"=>"6226090102573389");
    public static $appkey=array("sina"=>"3911521136","qq"=>"801215752");
    public static $sinaapp=array("AppKey"=>"2970589134","AppSercet"=>"30121d3fafe43b3b231b1301d06b5c1b");
    public static $mail=array("username"=>"inzaghia5@163.com","pwd"=>"vincent1985","smtp"=>"smtp.163.com");
    public static $sms=array("url"=>"http://sdkhttp.eucp.b2m.cn/sdk/SDKService?wsdl",
        "serialNumber"=>"3SDK-EMY-0130-NITTL",
        "password"=>"481829","sessionkey"=>"abcdefg");

    public static $banks=array("工商银行"=>"ICBC-NET-B2C","建设银行"=>"CCB-NET-B2C","农业银行"=>"ABC-NET-B2C",
        "邮政储蓄"=>"POST-NET-B2C","中国银行"=>"BOC-NET-B2C","交通银行"=>"BOCO-NET-B2C","招商银行"=>"CMBCHINA-NET-B2C",
        "光大银行"=>"CEB-NET-B2C","浦发银行"=>"SPDB-NET-B2C","华夏银行"=>"HXB-NET-B2C","广发银行"=>"GDB-NET-B2C",
        "中信银行"=>"ECITIC-NET-B2C","兴业银行"=>"CIB-NET-B2C","深发银行"=>"SDB-NET-B2C","民生银行"=>"CMBC-NET-B2C",
        "杭州银行"=>"HZBANK-NET-B2C","上海银行"=>"SHB-NET-B2C","宁波银行"=>"NBCB-NET-B2C","平安银行"=>"PINGANBANK-NET");
}
?> 