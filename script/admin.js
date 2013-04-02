function dict_add()
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'dict_add',
            dict_type:$("#dict_type").find('option:selected').attr('value'),
            dict_name:$('#dict_name').val()
        },
        type: "POST",
        dataType: "json",
        success: function()
        {
            location.reload();
        }
    });
}
function Prod_type_del(dict_id)
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'prod_type_del',
            value:dict_id
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

    $prod_index_show=0;
    if($('#prod_index_show').attr('checked')==true)
    {
        $prod_index_show=1;
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
            prod_show_seq:$('#prod_show_seq').val().trim(),
            prod_index_show:$prod_index_show,
            prod_name:$('#prod_name').val().trim(),
            prod_title:$('#prod_title').val().trim(),
            prod_origin_price:$('#prod_origin_price').val(),
            prod_sale_price:$('#prod_sale_price').val(),
            prod_type:$('#prod_type').val(),
            prod_medium:$('#prod_medium').val().trim(),
            prod_word:$('#prod_word').val().trim(),
            prod_date_range:$('#prod_date_range').val().trim(),
            prod_area_range:$('#prod_area_range').val().trim(),
            prod_freight:$('#prod_freight').val().trim(),
            prod_desc:$('#prod_desc').val().trim(),
            prod_onshelf_type:$('input:radio[name="prod_onshelf_type"]:checked').val(),
            prod_onshelf_time:'',//$('#prod_onshelf_time').val().trim()
            standards:$('#standards').val().trim(),
            pic0:$('#pic0').find('#pic_path').val(),
            pic1:$('#pic1').find('#pic_path').val(),
            pic2:$('#pic2').find('#pic_path').val(),
            prod_tag:str,
            prod_cat:1,
            prod_stock_up:$('#prod_stock_up').val().trim()
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
            window.location.href='admin.php?k=adminprodlist';
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
    pic=obj;
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
    $('#'+pic).find('#pic_path').val(data);   
    $('#'+pic).find('#pic_yulan').attr("src",data);
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

function order_op(type,order_id)
{
    $.ajax({
        url:"dbport.php",
        data:{
            action:'orderop',
            newstatus:type,
            order_id:order_id
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
            cust_mobile:$('#cust_mobile').val(),
            cust_province:$('#cust_province').val(),
            cust_city:$('#cust_city').val(),
            cust_town:$('#cust_town').val(),
            cust_address:$('#cust_address').val(),
            cust_zip:$('#cust_zip').val(),
            order_name:$('#order_name').val(),
            order_mobile:$('#order_mobile').val(),
            book_date:$('#book_date').val(),
            book_time:$('#book_time').val(),
            book_card:$('#book_card').val(),
            payment:$('#payment').val(),
            total:$('#total').val(),
            shipping_type:$('#shipping_type').val(),
            shipping_fee:$('#shipping_fee').val()
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
    $where = "prod_name="+$('#prod_name').val()+"&prod_cat="+$('#prod_cat').val()
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