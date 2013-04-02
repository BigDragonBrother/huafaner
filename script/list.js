function list_add(dict_id,dict_name)
{
	dict_list=$('#search_list').val().split(",");
	for (var i in dict_list) {
		if(dict_list[i]==dict_id)
		{
			return 0;
		}
	};
	$('#search_list').val($('#search_list').val()+','+dict_id);
	$('#pick_list').html($('#pick_list').html()+'<dd class="add" value="'+dict_id+'">'+dict_name+'<a href="javascript:void(0)" onclick="list_remove(this);" class="remove"></a></dd>');
	list_search();
}

function list_remove (obj) 
{
	str="";	
	dict_list=$('#search_list').val().split(",");
	for (var i in dict_list) {
		if(dict_list[i]!=$(obj).parent().attr('value')&dict_list[i]!="")
		{
			str+=dict_list[i]+",";
		}
	};
	$('#search_list').val(str);
	$(obj).parent().remove();

	if(str=="")
	{
		window.location.href="list.php";
	}
	else
	{
		list_search();	
	}
}

function list_search()
{
	dict=$('#search_list').val();
	$.ajax({
            url:"dbport.php",
            data:{
            action:'list_search',
            dict_list:dict
            },
        type: "POST",
        dataType: "json",
        success: function(data)
        {
        	if(data=="")
        	{
        		$('.detailed_info').show();
        		$('.list_con').hide();
        	}
        	else
        	{
        		$('.detailed_info').hide();
        		$('.list_con').show();
        		$('.list_con').html(data);	
        	}
		}
    });
}