function dict_add(dict_type)
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'dict_add',
            dict_type:dict_type,
            dict_name:$('#dict_name').val(),
            dict_desc:$('#dict_desc').val(),
        },
        type: "POST",
        dataType: "json",
        success: function()
        {
            location.reload();
        }
    });
}
function Prod_type_add()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'dict_add',
            dict_type:'prod_type',
            dict_name:$('#dict_prod_type').val()
        },
        type: "POST",
        dataType: "json",
        success: function()
        {
            location.reload();
        }
    });
}
function Prod_tag_add()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'dict_add',
            dict_type:'prod_tag',
            dict_name:$('#dict_prod_tag').val()
        },
        type: "POST",
        dataType: "json",
        success: function()
        {
            location.reload();
        }
    });
}
function dict_del()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'dict_del',
            value:$('#dict_del_id').val()
        },
        type: "POST",
        dataType: "json",
        success: function()
        {
            location.reload();
        }
    });
}
function Prod_add(prod_id)
{
    if($('#prod_name').val().trim().length==0)
    {
        alert('商品名称不能为空');
        return;
    }
    
    if(prod_id==undefined)
    {
        action="prod_add";
        succ="商品添加成功";
    }
    else
    {
        action="prod_update";
        succ="商品更新成功";
    }
    var str="";
    $("input[name='prod_tag']:checkbox:checked").each(function(){ //由于复选框一般选中的是多个,所以可以循环输出
        str+=$(this).val()+",";
    }); 

    $.ajax({
        url:"dbport.php",
        data:{
            action:action,
            prod_id:prod_id,
            prod_name:$('#prod_name').val().trim(),
            prod_title:$('#prod_title').val().trim(),
            prod_type:$('#prod_type').val(),
            prod_sale_price:$('#prod_sale_price').val(),
            pic0:$('#pic0').attr('src'),
            pic1:$('#pic1').attr('src'),
            pic2:$('#pic2').attr('src'),
            prod_word:$('#prod_word').val().trim(),
            prod_medium:$('#prod_medium').val().trim(),
            standards:$('#standards').val().trim(),
            prod_care_desc:$('#prod_care_desc').val(),
            prod_order_desc:$('#prod_order_desc').val(),
            prod_tag:str,
            prod_stock_up:$('#prod_stock_up').val().trim(),
            prod_date_range:$('#prod_date_range').val().trim(),
            prod_onshelf_type:$('input:radio[name="prod_onshelf_type"]:checked').val(),
            prod_onshelf_time:$('#prod_onshelf_time').val().trim()
        },
        type: "POST",
        dataType: "json",
        success: function(dbdata)
        {
            if(dbdata==0)
            {
                alert('此商品名称已存在');
                return;
            }
            if(dbdata<0)
            {
                alert('商品添加失败');
                return;
            }
            alert(succ);
            location.reload();
            //window.location.href='admin.php?k=prodlist';
        }
    });
}

function Only_add(prod_id)
{
    if($('#prod_name').val().trim().length==0)
    {
        alert('商品名称不能为空');
        return;
    }
    
    if(prod_id==undefined)
    {
        action="prod_add";
        succ="商品添加成功";
    }
    else
    {
        action="prod_update";
        succ="商品更新成功";
    }
    
     $.ajax({
        url:"dbport.php",
        data:{
            action:action,
            prod_id:prod_id,
            prod_show_seq:$('#prod_show_seq').val().trim(),
            prod_index_show:0,
            prod_name:$('#prod_name').val().trim(),
            prod_origin_price:$('#prod_origin_price').val(),
            prod_sale_price:$('#prod_origin_price').val(),
            prod_type:0,
            prod_date_range:0,
            prod_onshelf_type:$('input[@name="prod_onshelf_type"][checked]').val(),
            prod_onshelf_time:'',//$('#datepicker').val().trim()+" "+$('#datet').val()+":00:00",
            pic0:$('#pic0').find('#pic_path').val(),
            prod_cat:2
        },
        type: "POST",
        dataType: "json",
        success: function(dbdata)
        {
            if(dbdata==0)
            {
                alert('此商品名称已存在');
                return;
            }
            if(dbdata<0)
            {
                alert('商品添加失败');
                return;
            }
            alert(succ);
            window.location.href='admin.php?k=adminonlyprodlist';
        }
    });
}

function prod_onshelf(prod_id,prod_onshelf_status)
{
     $.ajax({
        url:"dbport.php",
        data:{
            action:'prod_onshelf',
            prod_id:prod_id,
            prod_onshelf_status:prod_onshelf_status
        },
        type: "POST",
        dataType: "json",
        success: function(dbdata)
        {
            location.reload();
        }
    });
}

var pic;
function fileupload(obj)
{
    //pic=obj;
    var options = {
    dataType:'json', 
    type:'post',
    url:'picupload.php',
    beforeSubmit:showRequest,  
    success:showResponse,
    error : function(XMLResponse) {  
                    alert(XMLResponse.responseText);  
                    alert('操作失败！');  
    } 
    };
    $('#'+obj).ajaxSubmit(options);
}

function showRequest() 
{ 
    
}

function showResponse(data)
{
    $('#pic'+pic).attr('src',data);
    $('#desc'+pic).val($('#file_poster_desc').val());
    $('#prod'+pic).val();
}

function deletesubstr(p,s)
{
    indx=p.indexOf(s,0);
    return p.substring(0,indx)+p.substring(indx+s.length,p.length);
}

function selectProd(obj)
{
    if($('#'+obj.id).attr("checked"))
    {
        $('#prod_id_list').text($('#prod_id_list').text()+obj.value+',');
    }
    else
    {
        newlist = deletesubstr($('#prod_id_list').text(),obj.value+',');
        $('#prod_id_list').text(newlist);
    }
}

function sub_add(sub_id)
{
    if(sub_id==undefined)
    {
        action="sub_add";
        succ="主题添加成功";
    }
    else
    {
        action="sub_update";
        succ="主题更新成功";
    }
    var str="";
    $("input[name='sub_tag']:checkbox:checked").each(function(){ //由于复选框一般选中的是多个,所以可以循环输出
        str+=$(this).val()+",";
    }); 
    $.ajax({
        url:"dbport.php",
        data:{
            action:action,
            sub_id:sub_id,
            sub_show_seq:$('#sub_show_seq').val().trim(),
            sub_name:$('#sub_name').val().trim(),
            sub_desc:$('#sub_desc').val().trim(),
            sub_start:$('#sub_start').val(),
            sub_end:$('#sub_end').val(),
            sub_pic_main:$('#pic0').find('#pic_path').val(),
            sub_pic_list:$('#pic1').find('#pic_path').val(),
            sub_pic:$('#pic2').find('#pic_path').val(),
            sub_tag:str,
            prod_id_list:$('#prod_id_list').text()
        },
        type: "POST",
        dataType: "json",
        success: function(dbdata)
        {
            if(!dbdata)
            {
                alert('主题添加失败');
                return;
            }
            alert(succ);
            window.location.href='admin.php?k=adminsublist';
        }
    });
    
}
var order_id_op;
var total_op;
function order_op_pre(order_id,total)
{
    $('.order_id_op').text("订单编号："+order_id);
    $('.total_op').text("金额：￥"+total);
    order_id_op=order_id;
    total_op=total;
}
function order_op_print(order_id)
{
    order_id_op=order_id;
    $.ajax({
        url:"dbport.php",
        data:{
            action:'getorderbyid',
            order_id:order_id
        },
        type: "POST",
        dataType: "json",
        success: function(order)
        {
            $('#print_order_id').text(order['order_id']);
            $('#print_cdate').text(order['cdate']);
            $('#print_cust_name').text(order['cust_name']);
            $('#print_cust_mobile').text(order['cust_mobile']);
            $('#print_cust_address').text(order['cust_city']+order['cust_town']+order['cust_address']);
            $('#print_prod_name').text(order['prod_name']);
            $('#print_book_date').text(order['book_date']);
        }
    }); 
}
function printdiv()
{
    var headstr = "<html><head><title></title></head><body>";
    var footstr = "</body>";
    var newstr = $('#print').html();//document.all.item(printpage).innerHTML;
    var oldstr = document.body.innerHTML;
    document.body.innerHTML = headstr+newstr+footstr;
    window.print();
    document.body.innerHTML = oldstr;
    return false;
}

function order_op(type)
{
    order_cancel_desc=$('#order_cancel_desc').val();
    $.ajax({
        url:"dbport.php",
        data:{
            action:'orderop',
            newstatus:type,
            order_id:order_id_op,
            order_cancel_desc:order_cancel_desc
        },
        type: "POST",
        dataType: "json",
        success: function(dbdata)
        {
            if(dbdata<0)
            {
                alert('操作失败');
            }
            else
            {
                window.location.reload();   
            }
        }
    });
}

function order_update()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'order_update',
            order_id:$('#order_id').val(),
            cust_name:$('#cust_name').val(),
            cust_province:$('#cust_province').val(),
            cust_city:$('#cust_city').val(),
            cust_town:$('#cust_town').val(),
            cust_address:$('#cust_address').val(),
            cust_mobile:$('#cust_mobile').val(),
            book_date:$('#book_date').val(),
            book_card:$('#book_card').val(),
            book_card_content:$('#book_card_content').val(),
            order_sign:$('#order_sign').val(),
            remarks:$('#remarks').text(),
            total_pay:$('#total_pay').val()
        },
        type: "POST",
        dataType: "json",
        success: function(dbdata)
        {
            if(dbdata<0)
            {
                alert('更新失败');
            }
            else
            {
                alert('更新成功');
                window.location.reload();   
            }
        }
    });
}

function adminlogin()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'admin_login',
            adminuser:$("#adminlogin").val(),
            adminpwd:$('#adminpwd').val()
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data==1)
            {
                window.location.reload();
            }
            if(data==0)
            {
                alert('登录失败');   
            }
        }
    });
}

function adminlogout()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'admin_logout'
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            window.location.reload();
        }
    });
}

function prodlistsearch()
{
    $where = "prod_name="+$('#prod_name').val()+"&prod_type="+$('#prod_type').val()
    +"&prod_onshelf_time_low="+$('#prod_onshelf_time_low').val()+"&prod_onshelf_time_high="+$('#prod_onshelf_time_high').val()
    +"&prod_sale_price_low="+$('#prod_sale_price_low').val()+"&prod_sale_price_high="+$('#prod_sale_price_high').val();
    window.location.href='admin.php?k=prodlist&'+$where;
}

function prodlistclean()
{
    $('#prod_name').val('');
    $('#prod_onshelf_time_low').val('');
    $('#prod_onshelf_time_high').val('');
    $('#prod_sale_price_low').val('');
    $('#prod_sale_price_high').val('');
}

function orderlistsearch()
{
    $where = "order_id="+$('#order_id').val()+"&cust_id="+$('#cust_id').val()
    +"&order_mobile="+$('#order_mobile').val()+"&cust_mobile="+$('#cust_mobile').val()
    +"&order_status="+$('#order_status').val()+"&book_date_low="+$('#book_date_low').val()
    +"&book_date_high="+$('#book_date_high').val();
    window.location.href='admin.php?k=orderlist&'+$where;
}

function orderlistclean()
{
    $('#order_id').val('');
    $('#cust_id').val('');
    $('#order_mobile').val('');
    $('#cust_mobile').val('');
    $('#book_date_low').val('');
    $('#book_date_high').val('');
}

function design_index_commit()
{
    design_string = 'pic_nav:'+$('#pic_nav').attr('src')
        +';pic_poster1:'+$('#pic_poster1').attr('src')
        +';pic_poster2:'+$('#pic_poster2').attr('src')
        +';pic_file_poster1:'+$('#pic_file_poster1').attr('src')
        +';pic_file_poster2:'+$('#pic_file_poster2').attr('src')
        +';pic_file_poster3:'+$('#pic_file_poster3').attr('src')
        +';pic_file_poster4:'+$('#pic_file_poster4').attr('src')
        +';desc_file_poster1:'+$('#desc_file_poster1').attr('src')
        +';desc_file_poster2:'+$('#desc_file_poster2').attr('src')
        +';desc_file_poster3:'+$('#desc_file_poster3').attr('src')
        +';desc_file_poster4:'+$('#desc_file_poster4').attr('src')
        +';prod_file_poster1:'+$('#prod_file_poster1').attr('src')
        +';prod_file_poster2:'+$('#prod_file_poster2').attr('src')
        +';prod_file_poster3:'+$('#prod_file_poster3').attr('src')
        +';prod_file_poster4:'+$('#prod_file_poster4').attr('src');
    $.ajax({
        url:"dbport.php",
        data:{
            action:"design_index",
            design_var:design_string
        },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
            if(data)
            {
                alert('首页更新成功');
            };
        }
    });
}