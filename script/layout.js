// JavaScript Document
$(document).ready(function () {

/*************************************去掉超链接和按钮点击时生成的虚线框*******************************************************************/
	/*$('a,input[type="button"],input[type="submit"]').bind('focus',function(){
		if(this.blur){
			this.blur();
		};
	});
	*/

/*****  二期 **************************************/

/************************************** 列表 **************************************/
$('dl.list_con dd').hover(function(){
		$(this).addClass('list_conhover');
	},function(){
		$(this).removeClass('list_conhover');
	});

/*************************************Tab标签切换********************************************************************/	
	$('.ind_share ul li').mouseover(
	 	function(){
			if($(this).hasClass('martop')){
				//$('.ind_share li').addClass('');
				//$('.ind_share li').removeClass('');
				//$(this).addClass('');
				//$(this).removeClass('');
			}
			$('.infolist').hide().eq($(this).index()).show();
		})
	
/************************************** 点击卡片右侧显示层 **************************************/
$('.greet_n').click(
	 function(){
		 $(".greeting_n").show();
		 $(".greeting_replace").hide();
		 }
	);
	$('.greet_replace').click(
	 function(){
		 $(".greeting_replace").show();
		 $(".greeting_n").hide();
		 }
	);

/*****  二期结束 **************************************/


/************************************** 首页产品展示 **************************************/
	$('.prod').hover(function(){
		$(this).addClass('prod_infohover');
	},function(){
		$(this).removeClass('prod_infohover');
	});
/************************************** 专题产品展示 **************************************/
	$('.prod_zt').hover(function(){
		$(this).addClass('prod_zthover');
	},function(){
		$(this).removeClass('prod_zthover');
	});
/************************************** 专题产品展示 **************************************/
	$('.pic_zt').hover(function(){
		$(this).addClass('pic_zthover');
	},function(){
		$(this).removeClass('pic_zthover');
	});
/************************************** 我的最爱 **************************************/
	$('.love_box').hover(function(){
		$(this).addClass('love_boxhover');
	},function(){
		$(this).removeClass('love_boxhover');
	});

/************************************** 商品预览 **************************************/	
	$(".imgList li").mouseenter(function(){
			$(this).addClass("hover");
			$(".bigImg")[0].src=$(this).children("img").attr("src");
			$(".imgList li").not(this).removeClass("hover")
	   });	

/************************************** 输入框 **************************************/
  $("input.inputtext").hover(function () {
    $(this).addClass('inputtext_hover').css("color", "#475e6d");
  }, function () {
  	//$(this).addClass('inputtext_hover').css("color", "");
    $(this).removeClass('inputtext_hover').css("color", "#475e6d");
  });
  $("textarea.inputtext").hover(function () {
    $(this).addClass('inputtext_hover').css("color", "#475e6d");
  }, function () {
  	//$(this).addClass('inputtext_hover').css("color", "");
    $(this).removeClass('inputtext_hover').css("color", "#475e6d");
  });

  $("input.login_input").hover(function () {
    $(this).addClass('login_inputhover');
  }, function () {
    $(this).removeClass('login_inputhover');
  });
/***** 二期登录注册输入框 ***/  
    $("input.rl_input").hover(function () {
    $(this).addClass('rl_input_hover');
  }, function () {
    $(this).removeClass('rl_input_hover');
  });

/************************************** 点击radio显示层 **************************************/
$('.bank_list').click(
	 function(){
		 $(".bankpays").show();
		 $(".bankpay_con").hide();
		 }
	);
$('.bankpay_list').click(
	 function(){
		 $(".bankpay_con").show();
		 $(".bankpays").hide();
		 }
);
$('.nobanks').click(
	function(){
	 $(".bankpays").hide();
	 $(".bankpay_con").hide();
	 }
	);


/************************************** 点击修改 **************************************/
$('.modify').click(
	 function(){
		 $(".info_content").show();
		 }
	);

/************************************** 另类radio样式 **************************************/
	$(".seltectradio").click(function(){
			$('.seltectradio').removeClass('selectCurre')
			$(this).addClass('selectCurre')
			
		})

/************************************** 银行图标与支付平台图标交互样式 **************************************/
	$('li.bankpay').click(
	 function(){
		 	$('.bankpay').removeClass('bank_cardhover')
		  	$(this).addClass('bank_cardhover')
		  }
	);
	
/************************************** 划过 **************************************/
$(document).ready(function() {
	$(".logins").click(function(e) {          
		e.preventDefault();
		$(".logininfo").toggle();
	});
//以下代码可以实现点击空白处层消失
$(document).mouseup(function(e) {
		if($(e.target).parent(".logins").length==0) {
			$(".logininfo").hide();
		}
	});	
});


/************************************** 首页海报 **************************************/
	var sw = 0;
	$(".demo .num a").mouseover(function(){
		sw = $(".num a").index(this);
		myShow(sw);
	});
	function myShow(i){
		$(".demo .num a").eq(i).addClass("cur").siblings("a").removeClass("cur");
		$(".demo ul li").eq(i).stop(true,true).fadeIn(600).siblings("li").fadeOut(600);
	}
	//滑入停止动画，滑出开始动画
	$(".demo").hover(function(){
		if(myTime){
		   clearInterval(myTime);
		}
	},function(){
		myTime = setInterval(function(){
		  myShow(sw)
		  sw++;
		  if(sw==5){sw=0;}
		} , 3000);
	});
	//自动开始
	var myTime = setInterval(function(){
	   myShow(sw)
	   sw++;
	   if(sw==5){sw=0;}
	} , 3000);

/************************************** 列表样式 **************************************/	
	$(".List tr.lr_color:odd").addClass('even');
	$("")
	$(".List tr").hover(
		function(){
			
			$(this).addClass('current')
			$('tr.show').removeClass('current');
			},
		function(){
			$(this).removeClass('current')
	})
	$(".List tr:contains('异常')").addClass('error');
	//$(".subMenu dl dt").hover()
	
/************************************** 独一无二 选择花 **************************************/
	$('.selhua').click(
	 function(){
		 	$('.selhua').removeClass('selecthua')
		  	$(this).addClass('selecthua')
		  }
	);
	
/************************************** 清空表单内的信息 **************************************/
	$(".inputtext").focus(function(){
	var txt_value = $(this).val();
	if(txt_value==this.defaultValue){
		$(this).val("");
		}
	});
	$(".inputtext").blur(function(){
		var txt_value = $(this).val();
		if(txt_value==""){
			$(this).val(this.defaultValue);	
		}
	})

/************************************** 独一无二订制 **************************************/	
	$('.custom').hover(function(){
		$(this).addClass('custom_infohover');
	},function(){
		$(this).removeClass('custom_infohover');
	});



})

/************************************** 显示TR内容 **************************************/
$(function() {
		$(".btn_close").toggle(
		function(){
			$(this).addClass('btn_open')
			$('.current').addClass('tit_bj')
			},
		function(){
			$(this).removeClass('btn_open')
			$('.current').removeClass('tit_bj')
			})
});

function showTr(ObjId){
	//$(this).css("background", 'red')
		//alert($("#"+ObjId).hasClass('hid'))
		if($("#"+ObjId).hasClass('hid')){
			$(this).addClass('btn_open');
			
		    $("#"+ObjId).removeClass('hid');
			$("#"+ObjId).addClass('show');
		  
		}else{
		   $("#"+ObjId).addClass('hid');
		}
	
		return false;
	}

$(function() {
		$(".btn_col").toggle(
		function(){
			$('.current').addClass('tit_bj')
			},
		function(){
			$('.current').removeClass('tit_bj')
			})
});


/************************************** PNG 图片透明 **************************************/
function correctPNG () {
  for ( var i = 0; i < document.images.length; i++) {
    var img = document.images[i];
    var imgName = img.src.toUpperCase();
    if (imgName.substring(imgName.length - 3, imgName.length) == "PNG") {
      var imgID = (img.id) ? "id='" + img.id + "' " : "";
      var imgClass = (img.className) ? "class='" + img.className + "' " : "";
      var imgTitle = (img.title) ? "title='" + img.title + "' " : "title='"
          + img.alt + "' ";
      var imgStyle = "display:inline-block;" + img.style.cssText;
      if (img.align == "left") {
        imgStyle = "float:left;" + imgStyle;
      }
      if (img.align == "right") {
        imgStyle = "float:right;" + imgStyle;
      }
      if (img.parentElement.href) {
        imgStyle = "cursor:hand;" + imgStyle;
      }
      var strNewHTML = "<span " + imgID + imgClass + imgTitle + " style=\""
          + "width:" + img.width + "px; height:" + img.height + "px;"
          + imgStyle + ";"
          + "filter:progid:DXImageTransform.Microsoft.AlphaImageLoader"
          + "(src=\'" + img.src + "\', sizingMethod='scale');\"></span>";
      img.outerHTML = strNewHTML;
    }
  }
}
/************************************** 独一无二左右滚动 **************************************/
ph$ = {
	bindEvt : function() {
		var o = {};
		o.btn_sell_l = $("#pageLeft");
		if (o.btn_sell_l.length > 0) {
			o.btn_sell_l.bind("click", function() {
				ph$.scrollLveSell('right');
			});
		}
		o.btn_sell_r = $("#pageRight");
		if (o.btn_sell_r.length > 0) {
			o.btn_sell_r.bind("click", function() {
				ph$.scrollLveSell('left');
			});
		}

	},
	scrollLveSell : function(o) {
		if (this.cfg.lv_flag == 0)
			return false;
		var tar = $("#customcon");
		var tar2 = $("#customcon_t");
		tar.stop();
		tar2.stop();
		var max_num = $("#customcon>dd").length;
		var width = 230;
		var left = 0;
		var pos = tar.position();
		//alert(pos.left + "|" + width);
		if (o == "left") {
			if (Math.abs(pos.left)+width > width*(max_num-4)) {
				return false;
			}
			left = pos.left - width;
		} else if (o == "right") {
			if (pos.left >= 0) {
				return false;
			}
			left = pos.left + width;
		}
		left = left + "px";
		//alert(left);
		ph$.cfg.lv_flag = 0;
		tar.animate({
			left: left
		}, 600);
		tar2.animate({
			left: left
		}, 600, function() {
			ph$.cfg.lv_flag = 1;
			//alert(pos.left);
		});
	},

	cfg : {

	},
	init : function() {
		this.bindEvt();
	}
};
$(function($) {
	ph$.init();
});
//edit by vincent
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
function isMobile(str)
{
    var reg=/^1[0-9]{2}[0-9]{8}$/;
    return reg.test(str);
}
String.prototype.trim = function()
{
    return this.replace(/(^\s*)|(\s*$)/g, "");
}


