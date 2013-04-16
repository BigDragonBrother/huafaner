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
    $(".form_error").hide();
    if($('#cust_title').val()==0)
    {
        $('#cust_title_error').show();
        return 0;
    }
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
            cust_title:$('#cust_title').val(),
            cust_name:$('#cust_name').val(),
            cust_province:$('#cust_province').val(),
            cust_city:$('#cust_city').val(),
            cust_town:$('#cust_town').val(),
            cust_address:$('#cust_address').val(),
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
