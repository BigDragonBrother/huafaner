
function isZip(str)
{
    var reg=/^[0-9]{6}$/;
    return reg.test(str);
}

function getCookie(objName){//获取指定名称的cookie的值
    var arrStr = document.cookie.split("; ");
    for(var i = 0;i < arrStr.length;i ++){
        var temp = arrStr[i].split("=");
        if(temp[0] == objName) return unescape(temp[1]);
    } 
} 
function setCopy(){
    var txt=$('#user_url').val();
if(window.clipboardData){
        window.clipboardData.clearData();
        window.clipboardData.setData("Text",txt);
    }
    else if(navigator.userAgent.indexOf("Opera")!=-1){
        window.location=txt;
    }
    else if(window.netscape){
        try{
            netscape.security.PrivilegeManager.enablePrivilege("UniversalXPConnect");
        }
        catch(e){
            alert("您的firefox安全限制限制您进行剪贴板操作，请打开’about:config’将signed.applets.codebase_principal_support’设置为true’之后重试，相对路径为firefox根目录/greprefs/all.js");
            return false;
        }
        var clip=Components.classes['@mozilla.org/widget/clipboard;1'].createInstance(Components.interfaces.nsIClipboard);
        if(!clip)return;
        var trans=Components.classes['@mozilla.org/widget/transferable;1'].createInstance(Components.interfaces.nsITransferable);
        if(!trans)return;
        trans.addDataFlavor('text/unicode');
        var str=new Object();
        var len=new Object();
        var str=Components.classes["@mozilla.org/supports-string;1"].createInstance(Components.interfaces.nsISupportsString);
        var copytext=txt;str.data=copytext;
        trans.setTransferData("text/unicode",str,copytext.length*2);
        var clipid=Components.interfaces.nsIClipboard;
        if(!clip)return false;
        clip.setData(trans,null,clipid.kGlobalClipboard);
    }
    
}
function sendMail(user_id)
{
    $.ajax({
            url:"dbport.php",
            data:{
            action:'sendMail',
            user_id:user_id
            },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
        }
    });
}

function forgetpwd(type)
{
    if(type==0)
    {
        $('.error').hide();
        if($('#user_name').val().trim()==''||(!isEmail($('#user_name').val().trim())&!isMobile($('#user_name').val().trim())))
        {
            $('#user_name_error').show();
            return;
        }
        $.ajax({
            url:"dbport.php",
            data:{
            action:'getUserByusername',
            user_name:$('#user_name').val().trim()
            },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            alert(data);
            if(data)
            {
                if(isEmail($('#user_name').val().trim()))
                {
                    sendMail(data);
                    $('#forgetpwd').hide();
                    $('#forgetpwd1').show();
                    $('#user_email').text('确认邮件已经发送至邮箱：'+$('#user_name').val().trim());
                    $('#user_email').val(data);    
                }
                if(isMobile($('#user_name').val().trim()))
                {
                    $('#user_name_error2').show();
                    //$('#forgetpwd').hide();
                    //$('#forgetpwd2').show();
                }
            }
            else
            {
                $('#user_name_error1').show();
            }
        }
        });
        
    }

    if(type==3)
    {
        $('.error').hide();
        if($('#user_pwd').val().trim()=="")
        {
            $('#user_pwd_error').show();
            return 0;
        }
        if($('#user_pwd').val().trim().length<6)
        {
            $('#user_pwd_error1').show();
            return 0;
        }
        if($('#user_pwd_con').val().trim()!=$('#user_pwd').val().trim())
        {
            $('#user_pwd_con_error').show();
            return 0;
        }
        $.ajax({
        url:"dbport.php",
        data:{
            action:'reset_pwd',
            user_pwd:$('#user_pwd').val(),
            user_id:$('#user_id_reset').val(),
            user_link:$('#user_link_reset').val(),
            user_name:$('#user_name').val()
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            $('#forgetpwd3').hide();
            $('#forgetpwd4').show();
            if(data)
            {
                $('#reset_success').show();
                $('#reset_fail').hide();
            }
            else
            {
                $('#reset_fail').show();
                $('#reset_success').hide();
            }
        }
    });
    }
}

//修改用户登录名
function Edit_name()
{
    $(".error").hide();
    if($('#user_pwd').val().trim()=="")
    {
        $('#user_pwd_error').show();
        return 0;
    }
    if($('#user_name_new').val().trim()=="")
    {
        $('#user_name_new_error').show();
        return 0;
    }
    if(!isEmail($('#user_name_new').val().trim())&!isMobile($('#user_name_new').val().trim()))
    {
        $('#user_name_new_error2').show();
        return 0;
    }


    $.ajax({
        url:"dbport.php",
        data:{
            action:'Edit_name',
            user_name:$('#user_name').text(),
            user_name_new:$('#user_name_new').val(),
            user_pwd:$('#user_pwd').val()
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data=="2")
            {
                $('#user_name_new_error1').show();
            }
            if(data=="0")
            {
                $('#user_name_new_error3').show();
            }
            if(data=="1")
            {
                window.location.href="user.php?m=user_info";
            }
        }
    });
}
//修改密码
function Edit_pwd()
{
    $(".error").hide();
    if($('#user_pwd').val().trim()=="")
    {
        $('#user_pwd_error').show();
        return 0;
    }
    if($('#user_pwd_new').val().trim()=="")
    {
        $('#user_pwd_new_error').show();
        return 0;
    }
    if($('#user_pwd_new').val().trim().length<6)
    {
        $('#user_pwd_new_error1').show();
        return 0;
    }
    if($('#user_pwd_con').val().trim()=="")
    {
        $('#user_pwd_con_error').show();
        return 0;
    }
    if($('#user_pwd_con').val().trim()!=$('#user_pwd_new').val().trim())
    {
        $('#user_pwd_con_error1').show();
        return 0;
    }
    $.ajax({
        url:"dbport.php",
        data:{
            action:'Edit_pwd',
            user_name:getCookie('user_name'),
            user_pwd:$('#user_pwd').val(),
            user_pwd_new:$('#user_pwd_new').val()
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data=="2")
            {
                $('#user_pwd_result').show();
            }
            if(data=="0")
            {
                $('#user_pwd_result1').show();
            }
            if(data=="1")
            {
                window.location.href="user.php?m=user_info";
            }
        }
    });
}
//编辑通知选项
function Edit_inform()
{
    var inform_order=0;
    var inform_newprod=0;
    var inform_web=0;
    if($('#inform_order').attr('checked'))
    {
        inform_order=1;
    }
    if($('#inform_newprod').attr('checked'))
    {
        inform_newprod=1;
    }
    if($('#inform_web').attr('checked'))
    {
        inform_web=1;
    }
    $.ajax({
        url:"dbport.php",
        data:{
            action:'Edit_inform',
            user_id:getCookie('user_id'),
            inform_order:inform_order,
            inform_newprod:inform_newprod,
            inform_web:inform_web
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data=="0")
            {
                $('#inform_result').show();
            }
            if(data=="1")
            {
                $('#inform_result1').show();
            }
        }
    });  
}
//添加收货地址
function CustAdd()
{
    $(".error").hide();
    if($('#cust_name').val().trim()=="")
    {
        $('#cust_name_error').show();
        return 0;
    }
    if($('#cust_province').val()=="0"||$('#cust_city').val()=="0"||$('#cust_town').val()=="0")
    {
        $('#cust_province_error').show();
        return 0;
    }
    if($('#cust_address').val().trim()=="")
    {
        $('#cust_address_error').show();
        return 0;
    }
    if($('#cust_zip').val().trim()=="")
    {
        $('#cust_zip_error').show();
        return 0;
    }
    if(!isZip($('#cust_zip').val().trim()))
    {
        $('#cust_zip_error1').show();
        return 0;
    }
    if($('#cust_tel').val().trim()=="")
    {
        $('#cust_tel_error').show();
        return 0;
    }
    if(!isMobile($('#cust_tel').val().trim()))
    {
        $('#cust_tel_error1').show();
        return 0;
    }
    
    var cust_default=0;
    if($('#cust_default').is(':checked'))
    {
        cust_default=1;
    }
    
    if($('#cust_id').val()!='')
    {
        action="cust_update";
    }
    else
    {
        action="cust_add";
    }
    
    $.ajax({
        url:"dbport.php",
        data:{
            action:action,
            user_id:$('#user_id').val(),
            cust_id:$('#cust_id').val(),
            cust_name:$('#cust_name').val(),
            cust_province:$('#cust_province').val(),
            cust_city:$('#cust_city').val(),
            cust_town:$('#cust_town').val(),
            cust_address:$('#cust_address').val(),
            cust_zip:$('#cust_zip').val(),
            cust_tel:$('#cust_tel').val(),
            cust_default:cust_default
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data)
            {
                window.location.reload();    
            }
            else
            {
                $('#cust_error1').show();
            }
        }
    });
}
//删除收获地址
function delCust(id)
{
    $.get(
        'dbport.php',
        {
            action:"cust_del",
            cust_id:id
        }, 
        function(data){ 
            if(data)
            {
                window.location.reload();    
            }
        }); 
}
//设置默认收货地址
function setDefaultCust(cust_id,user_id)
{
    $.get(
        'dbport.php',
        {
            action:"setDefaultCust",
            cust_id:cust_id,
            user_id:user_id
        }, 
        function(data){ 
            if(data)
            {
                window.location.reload();    
            }
        }
        );
    
}

//confirm页面,关闭/修改按钮切换
function div_toggle(a,b,c)
{
    $('#'+a).toggle();
    $('#'+b).toggle();
    if($('#'+c).text()=='[修改]')
    {
        $('#'+c).text('[关闭]');
    }
    else
    {
        $('#'+c).text('[修改]');
    }
    
}

//confirm页面确认收货人地址
function order_info_confirm(order_id)
{
    if($(':radio[name="custlist"]:checked').val()=="0")
    {
        $(".error").hide();
        if($('#cust_name').val().trim()=="")
        {
            $('#cust_name_error').show();
            return 0;
        }
        if($('#cust_province').val()=="0"||$('#cust_city').val()=="0"||$('#cust_town').val()=="0")
        {
            $('#cust_province_error').show();
            return 0;
        }
        if($('#cust_address').val().trim()=="")
        {
            $('#cust_address_error').show();
            return 0;
        }
        if($('#cust_zip').val().trim()=="")
        {
            $('#cust_zip_error').show();
            return 0;
        }
        if(!isZip($('#cust_zip').val().trim()))
        {
            $('#cust_zip_error1').show();
            return 0;
        }
        if($('#cust_tel').val().trim()=="")
        {
            $('#cust_tel_error').show();
            return 0;
        }
        if(!isMobile($('#cust_tel').val().trim()))
        {
            $('#cust_tel_error1').show();
            return 0;
        }
        
        $('#order_info').text($('#cust_name').val().trim()+','+$('#cust_province').val()+','+$('#cust_city').val()
            +','+$('#cust_town').val()+','+$('#cust_address').val().trim()+','+$('#cust_zip').val().trim()
            +','+$('#cust_tel').val().trim());
    }
    else
    {
        $('#order_info').text($(':radio[name="custlist"]:checked').parent().parent().children("label").text());
    }
    
    if(order_id!=undefined)
    {
        $.ajax({
            url:"dbport.php",
            data:{
                action:'update_order_info',
                order_id:order_id,
                order_info:$('#order_info').text()
            },
            type: "POST",
            dataType: "json",
            success: function()
            {
            }
        });
    }
    
    div_toggle('order_info','order_info_detail','order_info_btn');
}
//confirm页面确认订花人信息
function ord_info_confirm()
{
    $(".error").hide();
    if($('#ord_name').val().trim()=='')
    {
        $('#ord_name_error').show();
        return 0;
    }
    if($('#ord_mobile').val().trim()=='')
    {
        $('#ord_mobile_error').show();
        return 0;
    }
    if(!isMobile($('#ord_mobile').val().trim()))
    {
        $('#ord_mobile_error1').show();
        return 0;
    }
    
    $('#ord_info').text($('#ord_name').val().trim()+','+$('#ord_mobile').val().trim());
    div_toggle('ord_info','ord_info_detail','ord_info_btn');  
}
//confirm页面确认送花信息
function book_info_confirm()
{
    $(".error").hide();
    if($('#datepicker').val()=='')
    {
        $('#datepicker_error').show();
        return 0;
    }
    $('#book_date').text($('#datepicker').val());
    $('#book_time').text($('#book_time_edit').val());
    $('#book_card').text($('#book_card_edit').val().trim());
    div_toggle('book_info','book_info_detail','book_info_btn')
}
//confirm页面确认送货方式和运费
function shipping_type_confirm()
{
    if($(':radio[name="shipping"]:checked').val()=='1')
    {
        shipping_fee="20.0";
        $('#shipping_type_detail').text("普通快递送货上门,￥20元");
    }
    if($(':radio[name="shipping"]:checked').val()=='2')
    {
        shipping_fee="200.0";
        $('#shipping_type_detail').text("UPS送货上门,￥200元");
    }
    if($(':radio[name="shipping"]:checked').val()=='3')
    {
        shipping_fee="0.0";
        $('#shipping_type_detail').text("免费");
    }
    $('#shipping_fee').text('￥'+shipping_fee);
    $('#shipping_fee').val(shipping_fee);
    total_price=(parseFloat($('#bargin_price').attr("value"))+parseFloat(shipping_fee)-parseFloat($("#coupons").find('option:selected').attr('name'))).toFixed(1);
    $('#total_price').text('￥'+total_price);
    div_toggle('shipping_type','shipping_type_detail','shipping_type_btn')
}
//confirm页面确认支付方式
function payment_confirm(order_id)
{
    $('#bank_error').hide();
    if($(':radio[name="pay_type"]:checked').val()=="0")
    {
        if($('.bank_cardhover').attr('title')==undefined)
        {
            $('#bank_error').show();
            return 0;
        }
        $('#payment_detail').text('网银支付，'+$('.bank_cardhover').attr('title'));
    }
    if($(':radio[name="pay_type"]:checked').val()=="1")
    {
        $('#payment_detail').text('银行转账');
    }
    
    if(order_id!=undefined)
    {
        $.ajax({
            url:"dbport.php",
            data:{
                action:'update_payment',
                order_id:order_id,
                payment:$('#payment_detail').text()
            },
            type: "POST",
            dataType: "json",
            success: function()
            {
            }
        });
    }
    
    div_toggle('payment','payment_detail','payment_btn');
}

//confirm页面弹出添加功能               
function custlist_add(e)
{
    if(e.value=="0")
    {
        $('#custlist_add').show();
    }
    else
    {
        $('#custlist_add').hide();
    }
                    
}

//confirm页面提交订单
function orderok()
{
    $('#order_error').hide();
    if($('#order_info').text()=='暂无收货地址')
    {
        window.location.href='#order_info_btn';
        $('#order_info').hide();
        $('#order_info_detail').show();
        $('#order_info_btn').text('[关闭]');
        $('#custlist').attr('checked','checked');
        $('#custlist_add').show();
        return 0;
    }
    if($('#ord_info').text()=='暂无订花人信息')
    {
        window.location.href='#ord_info_btn';
        $('#ord_info_detail').show();
        $('#ord_info').hide();
        $('#ord_info_btn').text('[关闭]');
        return 0;
    }
    if($('#book_date').text()==''||$('#book_time').text()=='')
    {
        window.location.href='#book_info_btn';
        $('#book_info').show();
        $('#book_info_detail').hide();
        $('#book_info_btn').text('[关闭]');
        return 0;
    }
    if($('#payment_detail').text()=='')
    {
        window.location.href='#payment_btn';
        $('#payment').show();
        $('#payment_detail').hide();
        $('#payment_btn').text('[关闭]');
        return 0;
    }
    
    $.ajax({
        url:"dbport.php",
        data:{
            action:'orderok',
            user_id:$('#user_id').attr('value'),
            order_info:$('#order_info').text(),
            ord_info:$('#ord_info').text(),
            book_date:$('#book_date').text(),
            book_time:$('#book_time').text(),
            book_card:$('#book_card').text(),
            shipping_type:$('#shipping_type_detail').text(),
            shipping_fee:$('#shipping_fee').attr('value'),
            payment:$('#payment_detail').text(),
            prod_id:$('#prod_id').attr('value'),
            order_quantity:$('#order_quantity').attr('value'),
            coupon_id:$("#coupons").find('option:selected').attr('value'),
            coupon_amount:$("#coupons").find('option:selected').attr('name'),
            only_order_id:$("#only_order_id").attr('value')
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data!=0)
            {
                window.location.href="orderok.php?id="+data;
            }
            else
            {
                $('#order_error').text('订单提交失败');
                $('#order_error').show();
            }
        }
    });
}

function order_cancel(order_id)
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'orderop',
            newstatus:0,
            order_id:order_id
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data)
            {
                window.location.reload();
            }
            else
            {
                alert('订单取消失败');
            }
        }
    });
}

function prod_like(prod_id,prod_like)
{
    if($('#prod_like').attr('value')=="1")
    {
        return 0;
    }
    prod_like=prod_like+1;
    $('#prod_like').attr('value',"1");
    $('#prod_like').text(prod_like+"人");
    $('#prod_like').parent().children('a').attr('class','plus plus_select');
    $.ajax({
        url:"dbport.php",
        data:{
            action:'prod_like',
            user_id:getCookie('user_id'),
            prod_id:prod_id
        },
        type: "POST",
        dataType: "json"
    });
}
//prod页面点击购买按钮，跳转到订单确认页，如果未登陆就弹出登陆框
function buy(prod_id)
{
    if(!getCookie('user_id'))
    {
        Popup.popping('boolean_login',true);
        $('#buyafterlogin').val(prod_id);
    }
    else
    {
        window.location.href="confirm.php?id="+prod_id;
    }
}
//orderok页面点击支付
function gotopay()
{
    
}

//confirm页面礼券选择
function coupon_select()
{
    coupon_amount=$("#coupons").find('option:selected').attr('name');
    $('#coupon_amount').text("￥-"+parseFloat(coupon_amount).toFixed(1));
    total_price=(parseFloat($('#bargin_price').attr("value"))+
        parseFloat($('#shipping_fee').attr('value'))-parseFloat(coupon_amount)).toFixed(1);
    $('#total_price').text('￥'+total_price);
}

//only页面提交订单
function onlyok()
{
    $(".error").hide();
    $('.tips red line').hide();
    if($('#only_cust').val().trim()==""||$('#only_cust').val()=="请把答案写在这里（如：一个我暗恋的女孩子或一个我重要客户）")
    {
        $('#only_cust_error').show();
        window.location.href="#only_cust_l";
        return 0;
    }
    if($('#only_cust').val().trim().length>50)
    {
        $('#only_cust_error1').show();
        window.location.href="#only_cust_l";
        return 0;
    }
    if($('#only_style').val().trim()==""||$('#only_style').val()=="请把答案写在这里（如：田园风或欧美绚丽风）")
    {
        $('#only_style_error').show();
        window.location.href="#only_style_l";
        return 0;
    }
    if($('#only_style').val().trim().length>50)
    {
        $('#only_style_error1').show();
        window.location.href="#only_style_l";
        return 0;
    }
    if($('#only_emotion').val().trim()==""||$('#only_emotion').val()=="请把答案写在这里")
    {
        $('#only_emotion_error').show();
        window.location.href="#only_emotion_l";
        return 0;
    }
    if($('#only_emotion').val().trim().length>300)
    {
        $('#only_emotion_error1').show();
        window.location.href="#only_emotion_l";
        return 0;
    }
    if($('.selecthua').attr('value')==undefined)
    {
        $('#only_prod_error').show();
        return 0;
    }

    if(!getCookie('user_id'))
    {
        $('#only_buyafterlogin').val("1");
        Popup.popping('boolean_login',true);
    }
    else
    {
        $.ajax({
            url:"dbport.php",
            data:{
                action:'only_ok',
                user_id:getCookie('user_id'),
                only_cust:$('#only_cust').val(),
                only_style:$('#only_style').val(),
                only_emotion:$('#only_emotion').val(),
                only_prod_id:$('.selecthua').attr('value')
            },
            type: "POST",
            dataType: "json",
            success: function(data)
            {
                if(data=="0")
                {
                    $('#only_ok_error').show();
                }
                else
                {
                    window.location.href="confirm.php?id="+$('.selecthua').attr('value')+"&only_order_id="+data;
                }
            }
        });        
    }
}

//分享到腾讯微博
function postToWb(appkey,url,content,pic){
    if(url==""){
        url=document.location;
    }
    var _url = encodeURIComponent(url);
    var _assname = encodeURI('');//你注册的帐号，不是昵称
    var _appkey = encodeURI(appkey);//你从腾讯获得的appkey
    var _pic = encodeURI(pic);//（例如：var _pic='图片url1|图片url2|图片url3....）
    var _t = '';//标题和描述信息
    var metainfo = document.getElementsByTagName("meta");
    for(var metai = 0;metai < metainfo.length;metai++){
        if((new RegExp('description','gi')).test(metainfo[metai].getAttribute("name"))){
            _t = metainfo[metai].attributes["content"].value;
        }
    }
    if(content==undefined)
    {
        content="";
    }
    _t =  document.title+_t+':'+content;//请在这里添加你自定义的分享内容
    if(_t.length > 120){
        _t= _t.substr(0,117)+'...';
    }
    _t = encodeURI(_t);

    var _u = 'http://share.v.t.qq.com/index.php?c=share&a=index&url='+_url+'&appkey='+_appkey+'&pic='+_pic+'&assname='+_assname+'&title='+_t;
    window.open( _u,'', 'width=700, height=680, top=0, left=0, toolbar=no, menubar=no, scrollbars=no, location=yes, resizable=no, status=no' );
}

