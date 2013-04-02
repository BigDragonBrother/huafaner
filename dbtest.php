<?php
if (!defined("ROOT")) define("ROOT", dirname(__FILE__));
include(ROOT."/conf.inc");
function getDataBases($className)
{
    $va = array();
    $obj = new ReflectionClass($className);
    $arr = $obj->getProperties();
    foreach($arr as $a=>$ab){
        $name = $ab->name;
        if(strpos($name, "Base") > 0 ){
           $va[$name] =  $obj->getStaticPropertyValue($name);
        }
    }
    return $va;
}

/*
 * $address =" trap17.com"; //Here you can specify the address you want to check ports
 * $port = "80"; //Here you can specify the port you want to check from $address
 */
function socketVisit($dbType,$host) {

    $hostArr = explode(':',$host);
    $address = $hostArr[0];
    if(isset($hostArr[1])) {         
        $port = $hostArr[1];
        }
    else
    {
        if($dbType=='oci') { $port = 1521;}
        if($dbType=='mysql') { $port = 3306;}
        else
        { $port = 1433;}
    }
    
   $checkport = @fsockopen($address, $port, $errnum, $errstr, 2); //The 2 is the time of ping in secs
 
    if(!$checkport) {
         echo "\n连接服务器 ".$host." 连接失败！".var_dump($checkport)."";
         echo "errorNum: ".$errnum ." , errorMessage: ". $errstr;
        return false;
    }else {
         echo "\n连接服务器 ".$host." 连接成功！".var_dump($checkport)."\n";
         return true;
    }
}

function checkDb($data){

    $dbType = $data['dbtype'];
    $user = $data["username"];
    $pass = $data["password"];
    $host = $data["server"];
    $dbname = $data["database"];

      if($dbType=='oci') {
        //连接oracle
            putenv("ORACLE_HOME=/usr/lib/oracle/11.1/client64/lib");
            $dsn = "$dbType:dbname=//$host/$dbname;charset=ZHS16GBK";
        }else {
            $dsn="$dbType:host=$host;dbname=$dbname";
        }

        try {
            $db= new PDO($dsn,$user,$pass);
            $db->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
        }catch(PDOException $e) {
            echo"\n连接数据库".$host."失败！" ."<br/>";
            print"异常信息: ".$e->getMessage() ."<br/>";
            print"异常文件: ".$e->getFile() ."<br/>";
            print"异常行号: ".$e->getLine() ."<br/>";
            return;
        }
           echo"\n连接数据库".$host."成功！" ."<br/>";
    
}

// print_r(getDataBases('COMMConf')). "<br/>";

//echo "本服务器:".substr($_ENV['SERVER_ADDR'], -7);
$dbArray = getDataBases('Conf');
$i=1;
foreach($dbArray as $name=>$value){
    echo "\n".$i++.".数据库连接串名: ".$name."\n";
    if(socketVisit($value["dbtype"],$value['server']))   checkDb($value);
    echo "\n\n";
   
}

?>

