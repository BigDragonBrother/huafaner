$(function() {
	$('#reg_email').focus();
	$('#login_email').focus();
});

function isEmail(str){
    var reg = /^([a-zA-Z0-9_-_.])+@([a-zA-Z0-9_-])+((\.[a-zA-Z0-9_-]{2,3}){1,2})$/;
    return reg.test(str);
}
function isMobile(str)
{
    var reg=/^1[0-9]{2}[0-9]{8}$/;
    return reg.test(str);
}
function EnterReg(event,inviteid)
{
    if(event.keyCode==13)
    {
        if(inviteid=="0")
        {
            Register();
        }
        else
        {
            Register(inviteid);
        }
    }
}
function Register(inviteid)
{
    $(".reg_error").hide();
    if(!isEmail($('#reg_email').val().trim())||$('#reg_email').val().trim()=="")
    {
        $('#reg_email_error').show();
        return 0;
    }

    if($('#reg_pwd').val().trim().length<6)
    {
        //$('.strength').children("em").attr('class','str_0');
        $('#reg_pwd_error').show();
        return 0;
    }
    if($('#reg_name').val().trim()=="")
    {
        $('#reg_name_error').show();
        return 0;
    }
    if(!isMobile($('#reg_mobile').val().trim())||$('#reg_mobile').val().trim()=="")
    {
        $('#reg_mobile_error').show();
        return 0;
    }
    if($('#reg_license').attr('checked')!="checked")
    {
        return 0;
    }


    $.ajax({
        url:"dbport.php",
        data:{
            action:'register',
            reg_email:$('#reg_email').val(),
            reg_pwd:$('#reg_pwd').val(),
            reg_name:$('#reg_name').val(),
            reg_mobile:$('#reg_mobile').val(),
            reg_invite:inviteid
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data==1)
            {
                window.location.href='index.php';
            }
            if(data==0)
            {
                $('#reg_error1').show();
            }
            if(data==2)
            {
                $('#reg_error2').show();
            }
        }
    });
}
function EnterLogin(event,prod_id)
{
    if(event.keyCode==13)
    {
        if(prod_id=="0")
        {
            Login();
        }
        else
        {
            Login(prod_id);
        }
    }
}
//登陆
function Login(prod_id)
{
    $(".reg_error").hide();
    if($('#login_email').val().trim()=="")
    {
        $('#login_email_error').show();
        return 0;
    }
    if($('#login_pwd').val().trim()=="")
    {
        $('#login_pwd_error').show();
        return 0;
    }
    $.ajax({
        url:"dbport.php",
        data:{
            action:'login',
            login_email:$('#login_email').val(),
            login_pwd:$('#login_pwd').val()
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data)
            {
                if(prod_id!="")
                {
                    window.location.href='confirm.php?id='+prod_id;
                }
                else
                {
                    window.location.href='index.php';    
                }
            }
            else
            {
                $('#login_error').show();
            }
        }
    });
}
//注销
function Logout()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'logout'
        },
        type: "POST",
        dataType: "json",
        success: function()
        {
            window.location.reload();
        }
    });
}
