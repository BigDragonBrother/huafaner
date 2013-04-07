<?php
include_once 'conf.inc';
include_once PATH_LIB.'/tools.inc';
include_once PATH_BLL.'/prodBll.inc';
include_once PATH_BLL.'/userBll.inc';
include_once PATH_BLL.'/orderBll.inc';
include_once PATH_BLL.'/subBll.inc';
include_once PATH_LIB.'/mail.inc';
include_once PATH_LIB."/cookie.inc";

$action=  Tools::getValue('action');

$return='';
switch ($action)
{
    case 'dict_add':
        $return =  prodBll::addDict(Tools::getValue('dict_type'), Tools::getValue('dict_name'),Tools::getValue('dict_desc'));
        break;
    case 'prod_type_get':
        $return=prodBll::getDict('prod_type');
        break;
    case 'dict_del':
        $return =  prodBll::delDict(Tools::getValue('value'));
        break;
    case 'prod_add':
        $pic_arr=array(0=>Tools::getValue('pic0'),1=>Tools::getValue('pic1'),2=>Tools::getValue('pic2'));
        $return = prodBll::addProd(
                    Tools::getValue('prod_name'),
                    str_replace("'","\\'",Tools::getValue('prod_title')),
                    Tools::getValue('prod_type'),
                    Tools::getValue('prod_sale_price'),
                    $pic_arr,
                    str_replace("'","\\'",Tools::getValue('prod_word')),
                    str_replace("'","\\'",Tools::getValue('prod_medium')),
                    str_replace("'","\\'",Tools::getValue('standards')),
                    Tools::getValue('prod_care_desc'),
                    Tools::getValue('prod_order_desc'),
                    Tools::getValue('prod_tag'),
                    Tools::getValue('prod_stock_up'),
                    Tools::getValue('prod_date_range'),
                    Tools::getValue('prod_onshelf_type'),
                    Tools::getValue('prod_onshelf_time'));
        break;
    case 'prod_update':
        $pic_arr=array(0=>Tools::getValue('pic0'),1=>Tools::getValue('pic1'),2=>Tools::getValue('pic2'));
        $return 
           = prodBll::updateProd(
                    Tools::getValue('prod_id'),
                    Tools::getValue('prod_name'),
                    str_replace("'","\\'",Tools::getValue('prod_title')),
                    Tools::getValue('prod_type'),
                    Tools::getValue('prod_sale_price'),
                    $pic_arr,
                    str_replace("'","\\'",Tools::getValue('prod_word')),
                    str_replace("'","\\'",Tools::getValue('prod_medium')),
                    str_replace("'","\\'",Tools::getValue('standards')),
                    Tools::getValue('prod_care_desc'),
                    Tools::getValue('prod_order_desc'),
                    Tools::getValue('prod_tag'),
                    Tools::getValue('prod_stock_up'),
                    Tools::getValue('prod_date_range'),
                    Tools::getValue('prod_onshelf_type'),
                    Tools::getValue('prod_onshelf_time'));
        break;
    case 'prod_onshelf':
        $return =  prodBll::prodOnshelf(Tools::getValue('prod_id'),Tools::getValue('prod_onshelf_status'));
        break;
    case 'list_search':
        $return=prodBll::listSearch(Tools::getValue('dict_list'));
        break;
    case 'register':
        $return =  userBll::Register(
            Tools::getValue('reg_email'), 
            Tools::getValue('reg_pwd'),
            Tools::getValue('reg_name'),
            Tools::getValue('reg_mobile'),
            Tools::getValue('reg_invite'));
        break;
    case 'login':
        $return = userBll::Login(Tools::getValue('login_email'), Tools::getValue('login_pwd'));
        break;
    case 'logout':
        userBll::doLogout();
        break;
    case 'cust_add':
        $return =  userBll::addCust(
                Tools::getValue('user_id'),
                Tools::getValue('cust_title'),
                Tools::getValue('cust_name'),
                Tools::getValue('cust_province'),
                Tools::getValue('cust_city'),
                Tools::getValue('cust_town'),
                Tools::getValue('cust_address'),
                Tools::getValue('cust_tel'),
                Tools::getValue('cust_default'));
        break;
    case 'cust_update':
        $return=userBll::updateCust(
                Tools::getValue('user_id'),
                Tools::getValue('cust_id'),
                Tools::getValue('cust_title'),
                Tools::getValue('cust_name'),
                Tools::getValue('cust_province'),
                Tools::getValue('cust_city'),
                Tools::getValue('cust_town'),
                Tools::getValue('cust_address'),
                Tools::getValue('cust_tel'),
                Tools::getValue('cust_default'));
        break;
    case 'cust_del':
        $return=userBll::delCust(Tools::getValue('cust_id'));
        break;
    case 'setDefaultCust':
        $return=  userBll::setDefaultCust(Tools::getValue('cust_id'),Tools::getValue('user_id'));
        break;
    case 'orderok':
        $return =  orderBll::orderok(
                Tools::getValue('user_id'),
                Tools::getValue('order_info'),
                Tools::getValue('book_card'),
                Tools::getValue('book_card_content'),
                Tools::getValue('book_date'),
                Tools::getValue('payment'),
                Tools::getValue('prod_id'),
                Tools::getValue('order_quantity'),
                Tools::getValue('coupon_id'),
                Tools::getValue('coupon_amount'),
                Tools::getValue('remarks'),
                Tools::getValue('only_order_id')
                );
        break;
    case 'order_cancel':
        $return = orderBll::order_cancel(Tools::getValue('order_id'));
        break;
    case 'prod_like':
        $return =  prodBll::prodLike(Tools::getValue('user_id'),Tools::getValue('prod_id'));
        break;
    case 'Edit_name':
        if(userBll::searchUsername(Tools::getValue('user_name_new'))>0)
        {
            $return=2;
        }
        
        $return = userBll::Edit_userinfo(Tools::getValue('user_name'),
                Tools::getValue('user_pwd'),
                Tools::getValue('user_name_new'),
                'user_name');
        break;
    case 'Edit_pwd':
        if(userBll::confirmUser(Tools::getValue('user_name'),Tools::getValue('user_pwd')))
        {
            $return = userBll::Edit_userinfo(Tools::getValue('user_name'),
                    Tools::getValue('user_pwd'),
                    Tools::getValue('user_pwd_new'),
                    'user_pwd');
        }
        else
        {
            $return = 2;
        }
        break;
    case "reset_pwd":
        $return=userBll::reset_pwd(Tools::getValue('user_pwd'),Tools::getValue('user_id'),Tools::getValue('user_link'),Tools::getValue('user_name'));
        break;
    case 'Edit_inform':
        $return = userBll::Edit_inform(Tools::getValue('user_id'),Tools::getValue('inform_order'),Tools::getValue('inform_newprod'),Tools::getValue('inform_web'));
        break;
    case 'update_order_info':
        $return = orderBll::update_order_info(Tools::getValue('order_id'),Tools::getValue('order_info'));
        break;
    case 'update_payment':
        $return =orderBll::update_payment(Tools::getValue('order_id'),Tools::getValue('payment'));
        break;
    case 'only_ok':
        $return = orderBll::only_ok(Tools::getValue('user_id'),Tools::getValue('only_cust'),Tools::getValue('only_style'),Tools::getValue('only_emotion'),Tools::getValue('only_prod_id'));
        break;
    case 'sub_add':
        $return = subBll::sub_add(
                Tools::getValue('sub_name'),
                Tools::getValue('sub_desc'),
                Tools::getValue('sub_show_seq'),
                Tools::getValue('sub_start'),
                Tools::getValue('sub_end'),
                Tools::getValue('sub_pic_main'),
                Tools::getValue('sub_pic_list'),
                Tools::getValue('sub_pic'),
                Tools::getValue('sub_tag'),
                Tools::getValue('prod_id_list'));
        break;
    case 'sub_update':
        $return = subBll::sub_update(
                Tools::getValue('sub_id'),
                Tools::getValue('sub_name'),
                Tools::getValue('sub_desc'),
                Tools::getValue('sub_show_seq'),
                Tools::getValue('sub_start'),
                Tools::getValue('sub_end'),
                Tools::getValue('sub_pic_main'),
                Tools::getValue('sub_pic_list'),
                Tools::getValue('sub_pic'),
                Tools::getValue('sub_tag'),
                Tools::getValue('prod_id_list'));
        break;
    case 'orderop':
        $return =orderBll::orderop(Tools::getValue('newstatus'),Tools::getValue('order_id'),Tools::getValue('order_cancel_desc'));
        break;
    case 'getorderbyid':
        $return =orderBll::getOrder(Tools::getValue('order_id'));
        break;
    case 'order_update':
        $return=orderBll::order_update(
            Tools::getValue('order_id'),
            Tools::getValue('cust_name'),
            Tools::getValue('cust_province'),
            Tools::getValue('cust_city'),
            Tools::getValue('cust_town'),
            Tools::getValue('cust_address'),
            Tools::getValue('cust_mobile'),
            Tools::getValue('book_date'),
            Tools::getValue('book_card'),
            Tools::getValue('book_card_content'),
            Tools::getValue('order_sign'),
            Tools::getValue('remarks'),
            Tools::getValue('total_pay')
            );
        break;
    case 'getUserByusername':
        $return = userBll::searchUsername(Tools::getValue('user_name'));
        break;
    case 'sendMail':
        $user =userBll::getUserByid(Tools::getValue('user_id'));
        $content="HI，".$user['user_name'].
        "\r\n您使用了忘记密码功能，请在24小时内点击下面的链接，然后根据页面提示完成重置密码的设置：\r\n".
        Conf::$urlSet['domain']."user.php?m=user_forgetpwd&user_id=".$user['user_id']."&user_link=".$user['user_link'].
        "\r\n如果链接无法点击，请直接将链接拷贝至浏览器地址栏里直接访问。\r\n
        花范儿";
        //$content="您好，请点击以下链接找回密码：\r\n".Conf::$urlSet['domain']."user.php?m=user_forgetpwd&user_id=".$user['user_id']."&user_link=".$user['user_link'];
        $sm=new smail(Conf::$mail['username'],Conf::$mail['pwd'],Conf::$mail['smtp']);
        $return = $sm->send($user['user_name'],Conf::$mail['username'],'忘记花范儿密码',$content);
        break;
    case 'admin_login':
        if(Tools::getValue('adminuser')==Conf::$adminuser['admin']&Tools::getValue('adminpwd')==Conf::$adminuser['pwd'])
        {
            $cookieSet = Conf::$cookieSet;
            $_COOKIE['adminuser'] = Tools::getValue('adminuser');
            $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
            setcookie("adminuser", $_COOKIE['adminuser'], 0, $cookieSet["path"], $cookieSet["domain"], $secure);
            $return=1;
        }
        else
        {
            $return= 0;
        }
        break;
    case 'admin_logout':
        $cookieSet = Conf::$cookieSet;
        $secure = $_SERVER['SERVER_PORT'] == 443 ? 1 : 0;
        $expire = time() - 3600;
        setcookie("adminuser", 0, $expire, $cookieSet["path"], $cookieSet["domain"], $secure);
        break;
    default:
}

echo json_encode($return);
?>

