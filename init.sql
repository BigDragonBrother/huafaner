创建用户表
create table hua_user
(
user_id int not null auto_increment primary key,
user_name varchar(500) ,
user_mobile varchar(200),
user_email varchar(500),
user_pwd varchar(100) not null,
cdate datetime,
udate datetime
)default charset=GBK;

创建商品信息表
create table hua_prod
(
prod_id int not null auto_increment primary key,
prod_name varchar(500) not null,
prod_origin_price decimal(18,2),
prod_sale_price decimal(18,2),
prod_discount decimal(10,2),
prod_type int,
prod_medium varchar(100),
prod_word varchar(1000),
prod_date_range int,
prod_area_range varchar(100),
prod_freight varchar(100),
prod_desc varchar(500),
prod_onshelf_type int,
prod_onshelf_time datetime,
prod_like int ,
cdate datetime,
udate datetime
)

prod_name,prod_title,prod_type,prod_sale_price,prod_word,
                prod_medium,standards,prod_care_desc,prod_order_desc,prod_stock_up,
                prod_date_range,prod_onshelf_type,prod_onshelf_time,cdate,udate
创建商品信息表
create table hua_prod
(
prod_id int not null auto_increment primary key,
prod_name varchar(500) not null,
prod_title varchar(500),
prod_type int,
prod_sale_price decimal(18,2),
prod_word varchar(500),
prod_medium varchar(500),
standards varchar(500),
prod_care_desc int,
prod_order_desc int,
prod_stock_up int,
prod_date_range int,
prod_onshelf_type int,
prod_onshelf_time varchar(100),
prod_like int,
cdate datetime,
udate datetime
)

创建商品图片表
create table hua_prod_pic
(
pic_id int not null auto_increment primary key,
pic_path varchar(500) not null,
pic_seq int,
prod_id int not null,
cdate datetime,
udate datetime
)default charset=GBK;

sophie   15:28:51
原图大小：430*410
sophie   15:29:26
缩略图：95*90

创建字典表
create table hua_dict
(
dict_id int not null auto_increment primary key,
dict_type varchar(100),
dict_name varchar(500),
cdate datetime,
udate datetime
)default charset=GBK;

create table hua_cust
(
cust_id int not null auto_increment primary key,
user_id int not null,
cust_name varchar(500) not null,
cust_province varchar(300) not null,
cust_city varchar(300) not null,
cust_town varchar(300) not null,
cust_address varchar(500) not null,
cust_zip varchar(100) not null,
cust_tel varchar(100) not null,
cust_default int not null,
cdate datetime,
udate datetime
) default charset=GBK;

create table hua_order
(
order_id int not null auto_increment primary key,
user_id int not null,
cust_name varchar(100),
cust_province varchar(100),
cust_city varchar(100),
cust_town varchar(100),
cust_address varchar(500),
cust_zip varchar(20),
cust_mobile varchar(50),
order_name varchar(100),
order_mobile varchar(50),
book_date varchar(100),
book_time varchar(100),
book_card varchar(500),
payment varchar(100),
shipping_type varchar(100),
prod_id int,
order_quantity int,
total decimal(18,0),
payment_status int default 0,
cdate datetime,
udate datetime
)
auto_increment=10000
default charset=GBK;
用户收藏表
create table hua_like
(
like_id int not null auto_increment primary key,
user_id int not null,
prod_id int not null,
cdate datetime,
udate datetime
)default charset=GBK;
用户礼券表
create table hua_coupon
(
coupon_id int not null auto_increment primary key,
user_id int not null,
coupon_name varchar(50),
coupon_amount decimal(18,2),
coupon_valid datetime,
coupon_desc varchar(500),
coupon_status int default 1,
cdate datetime,
udate datetime
)default charset=GBK;
独一无二表
create table hua_only
(
only_order_id int not null auto_increment primary key,
user_id int,
only_cust varchar(500),
only_style varchar(300),
only_emotion varchar(1000),
only_prod_id int,
cdate datetime,
udate datetime
) 
auto_increment=10000
default charset=GBK;
商品标签表
create table hua_prod_tag
(
prod_tag_id int not null auto_increment primary key,
tag_id int,
prod_id int,
cdate datetime,
udate datetime
)default charset=GBK;
修改收获地址表
alter table hua_cust modify cust_zip varchar(100) default null;
alter table hua_cust add cust_title varchar(100);
alter table hua_order add remarks varchar(200);

专题标签表
create table hua_sub_tag
(
sub_tag_id int not null auto_increment primary key,
tag_id int,
sub_id int,
cdate datetime,
udate datetime
)default charset=GBK;
alter table hua_sub add sub_pic_list varchar(500);
alter table hua_sub add sub_pic_main varchar(500);
alter table hua_sub add sub_desc varchar(500);

页面设计表
create table hua_design
(
d_id int not null auto_increment primary key,
d_page varchar(200),
d_var varchar(1000),
cdate datetime,
udate datetime
)


