function getCookie(objName){//获取指定名称的cookie的值
    var arrStr = document.cookie.split("; ");
    for(var i = 0;i < arrStr.length;i ++){
        var temp = arrStr[i].split("=");
        if(temp[0] == objName) return unescape(temp[1]);
    } 
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
    $('#prod_like').parent().children('a').attr('class','fav_y');
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
        window.location.href="login.php?prod_id="+prod_id;
    }
    else
    {
        window.location.href="confirm.php?id="+prod_id;
    }
}