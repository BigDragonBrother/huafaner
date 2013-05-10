CREATE TABLE `hua_blog` (
  `blog_id` int(11) NOT NULL AUTO_INCREMENT,
  `blog_title` varchar(500) DEFAULT NULL,
  `blog_index` varchar(500) DEFAULT NULL,
  `blog_content` text,
  `blog_view` int(11) DEFAULT '0',
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  `blog_sum` text,
  PRIMARY KEY (`blog_id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=gbk

CREATE TABLE `hua_coupon` (
  `coupon_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `coupon_name` varchar(50) DEFAULT NULL,
  `coupon_amount` decimal(18,2) DEFAULT NULL,
  `coupon_valid` datetime DEFAULT NULL,
  `coupon_desc` varchar(500) DEFAULT NULL,
  `coupon_status` int(11) DEFAULT '1',
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`coupon_id`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=gbk 

CREATE TABLE `hua_cust` (
  `cust_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `cust_name` varchar(500) NOT NULL,
  `cust_province` varchar(300) NOT NULL,
  `cust_city` varchar(300) NOT NULL,
  `cust_town` varchar(300) NOT NULL,
  `cust_address` varchar(500) NOT NULL,
  `cust_zip` varchar(100) DEFAULT NULL,
  `cust_tel` varchar(100) NOT NULL,
  `cust_default` int(11) NOT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  `cust_title` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cust_id`)
) ENGINE=MyISAM AUTO_INCREMENT=25 DEFAULT CHARSET=gbk

CREATE TABLE `hua_design` (
  `d_id` int(11) NOT NULL AUTO_INCREMENT,
  `d_page` varchar(200) DEFAULT NULL,
  `d_var` varchar(1000) DEFAULT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`d_id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=gbk

CREATE TABLE `hua_dict` (
  `dict_id` int(11) NOT NULL AUTO_INCREMENT,
  `dict_type` varchar(100) DEFAULT NULL,
  `dict_name` varchar(500) DEFAULT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  `dict_desc` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`dict_id`)
) ENGINE=MyISAM AUTO_INCREMENT=82 DEFAULT CHARSET=gbk 

CREATE TABLE `hua_like` (
  `like_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `prod_id` int(11) NOT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`like_id`)
) ENGINE=MyISAM AUTO_INCREMENT=20 DEFAULT CHARSET=gbk 

 CREATE TABLE `hua_only` (
  `only_order_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) DEFAULT NULL,
  `only_cust` varchar(500) DEFAULT NULL,
  `only_style` varchar(300) DEFAULT NULL,
  `only_emotion` varchar(1000) DEFAULT NULL,
  `only_prod_id` int(11) DEFAULT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`only_order_id`)
) ENGINE=MyISAM AUTO_INCREMENT=10017 DEFAULT CHARSET=gbk

 CREATE TABLE `hua_order` (
  `order_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `cust_name` varchar(100) DEFAULT NULL,
  `cust_province` varchar(100) DEFAULT NULL,
  `cust_city` varchar(100) DEFAULT NULL,
  `cust_town` varchar(100) DEFAULT NULL,
  `cust_address` varchar(500) DEFAULT NULL,
  `cust_zip` varchar(20) DEFAULT NULL,
  `cust_mobile` varchar(50) DEFAULT NULL,
  `order_name` varchar(100) DEFAULT NULL,
  `order_mobile` varchar(50) DEFAULT NULL,
  `book_date` varchar(100) DEFAULT NULL,
  `book_time` varchar(100) DEFAULT NULL,
  `book_card` varchar(500) DEFAULT NULL,
  `payment` varchar(100) DEFAULT NULL,
  `shipping_type` varchar(100) DEFAULT NULL,
  `prod_id` int(11) DEFAULT NULL,
  `order_quantity` int(11) DEFAULT NULL,
  `total` decimal(18,0) DEFAULT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  `payment_status` int(11) DEFAULT NULL,
  `order_status` int(11) NOT NULL DEFAULT '1',
  `coupon_id` int(11) DEFAULT NULL,
  `coupon_amount` decimal(18,0) DEFAULT NULL,
  `shipping_fee` decimal(18,2) DEFAULT NULL,
  `only_order_id` int(11) DEFAULT NULL,
  `remarks` varchar(200) DEFAULT NULL,
  `book_card_content` varchar(500) DEFAULT NULL,
  `cust_title` varchar(100) DEFAULT NULL,
  `pay_date` datetime DEFAULT NULL,
  `confirm_date` datetime DEFAULT NULL,
  `send_date` datetime DEFAULT NULL,
  `cancel_date` datetime DEFAULT NULL,
  `finish_date` datetime DEFAULT NULL,
  `order_sign` varchar(100) DEFAULT NULL,
  `total_pay` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`order_id`)
) ENGINE=MyISAM AUTO_INCREMENT=10027 DEFAULT CHARSET=gbk 

CREATE TABLE `hua_prod` (
  `prod_id` int(11) NOT NULL AUTO_INCREMENT,
  `prod_name` varchar(500) NOT NULL,
  `prod_title` varchar(500) DEFAULT NULL,
  `prod_type` int(11) DEFAULT NULL,
  `prod_sale_price` decimal(18,2) DEFAULT NULL,
  `prod_word` varchar(500) DEFAULT NULL,
  `prod_medium` varchar(500) DEFAULT NULL,
  `standards` varchar(500) DEFAULT NULL,
  `prod_care_desc` int(11) DEFAULT NULL,
  `prod_order_desc` int(11) DEFAULT NULL,
  `prod_stock_up` int(11) DEFAULT NULL,
  `prod_date_range` int(11) DEFAULT NULL,
  `prod_onshelf_type` int(11) DEFAULT NULL,
  `prod_onshelf_time` varchar(100) DEFAULT NULL,
  `prod_like` int(11) DEFAULT '0',
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`prod_id`)
) ENGINE=MyISAM AUTO_INCREMENT=36 DEFAULT CHARSET=utf8

CREATE TABLE `hua_prod_pic` (
  `pic_id` int(11) NOT NULL AUTO_INCREMENT,
  `pic_path` varchar(500) NOT NULL,
  `pic_seq` int(11) DEFAULT NULL,
  `prod_id` int(11) NOT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`pic_id`)
) ENGINE=MyISAM AUTO_INCREMENT=479 DEFAULT CHARSET=gbk 

CREATE TABLE `hua_prod_tag` (
  `prod_tag_id` int(11) NOT NULL AUTO_INCREMENT,
  `tag_id` int(11) DEFAULT NULL,
  `prod_id` int(11) DEFAULT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`prod_tag_id`)
) ENGINE=MyISAM AUTO_INCREMENT=149 DEFAULT CHARSET=gbk

CREATE TABLE `hua_sub` (
  `sub_id` int(11) NOT NULL AUTO_INCREMENT,
  `sub_type` varchar(10) DEFAULT NULL,
  `sub_name` varchar(100) DEFAULT NULL,
  `sub_desc` varchar(1000) DEFAULT NULL,
  `sub_on` varchar(5) DEFAULT NULL,
  `sub_start` varchar(100) DEFAULT NULL,
  `sub_pic_list` varchar(50) DEFAULT NULL,
  `sub_pic` varchar(50) DEFAULT NULL,
  `sub_tag` varchar(100) DEFAULT NULL,
  `prod_id_list` varchar(500) DEFAULT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`sub_id`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=gbk 

CREATE TABLE `hua_sub_tag` (
  `sub_tag_id` int(11) NOT NULL AUTO_INCREMENT,
  `tag_id` int(11) DEFAULT NULL,
  `sub_id` int(11) DEFAULT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  PRIMARY KEY (`sub_tag_id`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=gbk

CREATE TABLE `hua_user` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_name` varchar(500) DEFAULT NULL,
  `user_mobile` varchar(200) DEFAULT NULL,
  `user_email` varchar(500) DEFAULT NULL,
  `user_pwd` varchar(100) NOT NULL,
  `cdate` datetime DEFAULT NULL,
  `udate` datetime DEFAULT NULL,
  `inform_order` int(11) DEFAULT '1',
  `inform_newprod` int(11) DEFAULT '1',
  `inform_web` int(11) DEFAULT '1',
  `user_link` varchar(200) DEFAULT NULL,
  `user_invite` int(11) DEFAULT '0',
  `user_last_name` varchar(100) DEFAULT NULL,
  `user_last_mobile` varchar(100) DEFAULT NULL,
  `user_from` int(11) DEFAULT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=MyISAM AUTO_INCREMENT=62 DEFAULT CHARSET=gbk 