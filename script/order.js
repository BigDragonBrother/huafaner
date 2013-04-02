//confirm页面确认收货人地址
function order_confirm(order_id)
{
    if($(':radio[name="custlist"]:checked').val()=="0")
    {
        $(".form_error").hide();
        if($('#cust_title').val()=="0")
        {
            $('#cust_title_error').show();
            window.location.href='#order_info_btn';
            return 0;
        }
        if($('#cust_name').val().trim()=="")
        {
            $('#cust_name_error').show();
            window.location.href='#order_info_btn';
            return 0;
        }
        if($('#cust_province').val()=="0"||$('#cust_city').val()=="0"||$('#cust_town').val()=="0")
        {
            $('#cust_province_error').show();
            window.location.href='#order_info_btn';
            return 0;
        }
        if($('#cust_address').val().trim()=="")
        {
            $('#cust_address_error').show();
            window.location.href='#order_info_btn';
            return 0;
        }
        if($('#cust_tel').val().trim()=="")
        {
            $('#cust_tel_error').show();
            window.location.href='#order_info_btn';
            return 0;
        }
        if(!isMobile($('#cust_tel').val().trim()))
        {
            $('#cust_tel_error1').show();
            window.location.href='#order_info_btn';
            return 0;
        }
        
        $('#order_info').val($('#cust_name').val().trim()+','+$('#cust_title').val().trim()+','
            +$('#cust_province').val()+','+$('#cust_city').val()
            +','+$('#cust_town').val()+','+$('#cust_address').val().trim()+','+$('#cust_tel').val().trim());
    }
    else
    {
        $('#order_info').val($(':radio[name="custlist"]:checked').parent().parent().children("label").text());
    }
    
    if(order_id!=undefined)
    {
        $.ajax({
            url:"dbport.php",
            data:{
                action:'update_order_info',
                order_id:order_id,
                order_info:$('#order_info').val()
            },
            type: "POST",
            dataType: "json",
            success: function()
            {
            }
        });
    }
    return 1;
}
//confirm页面确认支付方式
function payment_confirm(order_id)
{
    if($(':radio[name="pay_type"]:checked').val()==undefined)
    {
        window.location.href='#payment_btn';
        $('#payment_error').show();
        return 0;
    }
    if($(':radio[name="pay_type"]:checked').val()=="0")
    {
        if($('.bank_cardhover').attr('title')==undefined)
        {
            window.location.href='#payment_btn';
            $('#payment_error1').show();
            return 0;
        }
        $('#payment_detail').val('网银支付，'+$('.bank_cardhover').attr('title'));
    }
    if($(':radio[name="pay_type"]:checked').val()=="1")
    {
        $('#payment_detail').val('货到付款');
    }
    if($(':radio[name="pay_type"]:checked').val()=="2")
    {
        $('#payment_detail').val('银行转账');
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
    return 1;
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
    $('.error').hide();
    if(!order_confirm())
    {
        return 0;
    }

    if($(':radio[name="book_card"]:checked').val()=="我要一张代写卡片"&$('#book_card_content').val()=="")
    {
        window.location.href='#card_btn';
        $('#book_card_error').show();
        return 0;
    }

    if(!payment_confirm())
    {
        return 0;
    }
    
    if($('#datepicker').val()=="")
    {
        window.location.href='#datepicker_btn';
        $('#datepicker_error').show();
        return 0;
    }
    
    $.ajax({
        url:"dbport.php",
        data:{
            action:'orderok',
            user_id:$('#user_id').attr('value'),
            order_info:$('#order_info').val(),
            book_card:$(':radio[name="book_card"]:checked').val(),
            book_card_content:$('#book_card_content').val(),
            book_date:$('#datepicker').val(),
            payment:$('#payment_detail').val(),
            prod_id:$('#prod_id').attr('value'),
            order_quantity:$('#prod_cnt').attr('value'),
            coupon_id:$("#coupons").find('option:selected').attr('value'),
            coupon_amount:$("#coupons").find('option:selected').attr('name'),
            remarks:$('#remarks').val(),
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
//confirm页面礼券选择
function coupon_select()
{
    coupon_amount=$("#coupons").find('option:selected').attr('name');
    $('#coupon_amount').text("￥-"+parseFloat(coupon_amount).toFixed(1));
    total_price=(parseFloat($('#bargin_price').attr("value"))-parseFloat(coupon_amount)).toFixed(1);
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