<?php

include_once (PATH_LIB . "/myPDO.inc");
include_once (PATH_DAL . "/db.inc");

class prodDal {

    static function addDict($type, $dict_name,$dict_desc) {
        $sql = "insert into hua_dict (dict_type,dict_name,dict_desc,cdate,udate)
            values ('$type','$dict_name','$dict_desc',now(),now())";

        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return DB::huaDB()->lastInsertId();
        }
    }

    static function updateDict($dict_edit_id,$dict_edit_name,$dict_edit_desc)
    {
        $sql="update hua_dict set dict_name='$dict_edit_name',dict_desc='$dict_edit_desc' where dict_id=$dict_edit_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return TRUE;
        }
        else
        {
            return false;
        }
    }

    static function getDict($type) {
        $sql = "select * from hua_dict where dict_type='$type'";
        if($type=="all")
        {
            $sql="select * from hua_dict";
        }
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getDictbyname($type,$dict_name){
        $sql = "select * from hua_dict where dict_type='$type' and dict_name='$dict_name'";
        if($type=="all")
        {
            $sql="select * from hua_dict where dict_name='$dict_name'";
        }
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }
    }

    static function delDict($dict_id) {
        $sql = "delete from hua_dict where dict_id=$dict_id";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->simplePrepare($sql);
    }

    static function addProd($prod_name,$prod_title,$prod_type,$prod_sale_price,$prod_word,
                $prod_medium,$standards,$prod_care_desc,$prod_order_desc,$prod_stock_up,
                $prod_date_range,$prod_onshelf_type,$prod_onshelf_time) 
    {
        $sql = "insert into hua_prod(prod_name,prod_title,prod_type,prod_sale_price,prod_word,
                prod_medium,standards,prod_care_desc,prod_order_desc,prod_stock_up,
                prod_date_range,prod_onshelf_type,prod_onshelf_time,cdate,udate)
            values
            ('$prod_name','$prod_title',$prod_type,$prod_sale_price,'$prod_word',
                '$prod_medium','$standards',$prod_care_desc,$prod_order_desc,$prod_stock_up,
                $prod_date_range,$prod_onshelf_type,'$prod_onshelf_time',now(),now())";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return DB::huaDB()->lastInsertId();
        }
    }
    
    static function updateProd($prod_id,$prod_name,$prod_title,$prod_type,$prod_sale_price,$prod_word,
                $prod_medium,$standards,$prod_care_desc,$prod_order_desc,$prod_stock_up,
                $prod_date_range,$prod_onshelf_type,$prod_onshelf_time) 
    {
        $sql = "update hua_prod set 
            prod_name='$prod_name',prod_title ='$prod_title',prod_type=$prod_type,prod_sale_price=$prod_sale_price,   
            prod_word='$prod_word',prod_medium='$prod_medium',standards='$standards',
            prod_care_desc=$prod_care_desc,prod_order_desc=$prod_order_desc,
            prod_stock_up=$prod_stock_up,prod_date_range=$prod_date_range,prod_onshelf_type=$prod_onshelf_type,
            prod_onshelf_time='$prod_onshelf_time',udate=now()
            where prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return TRUE;
        }
        else
        {
            return false;
        }
    }
    static function addProdTag($prod_tag,$prod_id)
    {
        $prod_tag_arr=explode(",",$prod_tag);
        foreach ($prod_tag_arr as $k => $v) {
            if($v!="")
            {
                $sql = "insert into hua_prod_tag (tag_id,prod_id,cdate,udate)
                    values ($v,$prod_id,now(),now())";
                if (!is_object(DB::huaDB()))
                    return array();
                DB::huaDB()->simplePrepare($sql);
            }
        }
    }
    static function updateProdTag($prod_tag,$prod_id)
    {
        $sql="delete from hua_prod_tag where prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        DB::huaDB()->simplePrepare($sql);
        $prod_tag_arr=explode(",",$prod_tag);
        foreach ($prod_tag_arr as $k => $v) {
            if($v!="")
            {
                $sql = "insert into hua_prod_tag (tag_id,prod_id,cdate,udate)
                    values ($v,$prod_id,now(),now())";
                if (!is_object(DB::huaDB()))
                    return array();
                DB::huaDB()->simplePrepare($sql);
            }
        }
    }
    static function addProdPic($pic_arr, $prod_id) {
        foreach ($pic_arr as $k => $v) {
            if ($v) {
                $sql = "insert into hua_prod_pic (pic_path,pic_seq,prod_id,cdate,udate)
                    values ('$v',$k,$prod_id,now(),now())";
                if (!is_object(DB::huaDB()))
                    return array();
                DB::huaDB()->simplePrepare($sql);
            }
        }
    }
    
    static function updateProdPic($pic_arr, $prod_id) {
        $sql="delete from hua_prod_pic where prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        DB::huaDB()->simplePrepare($sql);
        foreach ($pic_arr as $k => $v) {
            if ($v) {
                $sql = "insert into hua_prod_pic (pic_path,pic_seq,prod_id,cdate,udate)
                    values ('$v',$k,$prod_id,now(),now())";
                DB::huaDB()->simplePrepare($sql);
            }
        }
    }
    
    static function getProdByname($prod_name) {
        $sql = "select * from hua_prod where prod_name='$prod_name'";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }
    }

    static function getProdByid($prod_id) {
        $sql = "select a.*,b.dict_name prod_type_dict,
            c.dict_desc prod_care_desc_dict,d.dict_desc prod_order_desc_dict,
            e.pic_path
            from hua_prod a
            left join hua_dict b on a.prod_type=b.dict_id
            left join hua_dict c on a.prod_care_desc=c.dict_id
            left join hua_dict d on a.prod_order_desc=d.dict_id
            left join hua_prod_pic e on a.prod_id=e.prod_id and e.pic_seq=0
            where a.prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }
    }

    static function getProdPicByid($prod_id){
        $sql = "select a.*,b.pic_path list_pic,c.pic_path small_pic,d.pic_path big_pic
            from hua_prod a
            left join hua_prod_pic b on a.prod_id=b.prod_id and b.pic_seq=0
            left join hua_prod_pic c on a.prod_id=c.prod_id and c.pic_seq=1
            left join hua_prod_pic d on a.prod_id=d.prod_id and d.pic_seq=2
            where a.prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data[0];
        } else {
            return array();
        }   
    }

    static function getOnlyprods($n)
    {
        $sql="select a.*,b.pic_path 
        from hua_prod a 
        left join hua_prod_pic b on a.prod_id=b.prod_id and b.pic_seq=0
        where a.prod_cat=2 and a.prod_onshelf_type=1
        order by a.prod_show_seq desc limit $n";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

   static function getallOnlyprods()
    {
        $sql="select a.*,b.pic_path 
        from hua_prod a 
        left join hua_prod_pic b on a.prod_id=b.prod_id and b.pic_seq=0
        where a.prod_cat=2 
        order by a.prod_id desc";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getProdByids($prod_id_list) {
        $sql = "select a.*,b.* from hua_prod a
            left join hua_prod_pic b on a.prod_id=b.prod_id and b.pic_seq=0
            where a.prod_id in ($prod_id_list)";
        if (!is_object(DB::huaDB()))
            return array();
        $result = DB::huaDB()->allPrepare($sql);
        if ($result->data) {
            return $result->data;
        } else {
            return array();
        }
    }
    
    static function getProdPicByprodid($prod_id) {
        $sql = "select * from hua_prod_pic where prod_id='$prod_id' order by pic_seq asc";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getProdTagByprodid($prod_id)
    {
        $sql="select a.prod_id,a.tag_id,b.dict_type,b.dict_name 
        from hua_prod_tag a
            left join hua_dict b on a.tag_id=b.dict_id
            where a.prod_id='$prod_id'";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }
    
    static function getTagsByprodid($prod_id)
    {
        $sql="select tag_id
            from hua_prod_tag
            where prod_id='$prod_id'";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }
    static function getProdTopN($n) {
        $sql = "select 
            a.prod_id,a.prod_name,a.prod_title,
            a.prod_sale_price,a.prod_onshelf_type,b.pic_path
            from hua_prod a
            left join hua_prod_pic b on a.prod_id=b.prod_id and b.pic_seq=0
            where 
            prod_onshelf_type=1
            order by a.prod_id desc limit $n";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }
    static function getProdByType($prod_type) {
        $sql = "select 
            a.prod_id,a.prod_name,a.prod_title,
            a.prod_sale_price,a.prod_onshelf_type,b.pic_path
            from hua_prod a
            left join hua_prod_pic b on a.prod_id=b.prod_id and b.pic_seq=0
            where 
            prod_onshelf_type=1
            and prod_type=$prod_type
            order by a.prod_id desc";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }


    static function getProds($where,$page_num=1,$page_size=10) {
        $start = $page_size*($page_num-1);
        $sql = "select a.*,b.dict_name 
            from hua_prod a
            left join hua_dict b on a.prod_type=b.dict_id
            $where
            order by prod_id desc limit $start,$page_size";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function prodLike($user_id, $prod_id) {
        $sql = "update hua_prod set prod_like=prod_like+1,udate=now() where prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        DB::huaDB()->simplePrepare($sql);

        if ($user_id != "") {
            $sql = "insert into hua_like (user_id,prod_id,cdate,udate)
                values ($user_id,$prod_id,now(),now())";
            DB::huaDB()->simplePrepare($sql);
        }
    }

    static function getLike($user_id, $prod_id) {
        $sql = "select * from hua_like where user_id=$user_id and prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getLikeByuserid($user_id)
    {
        $sql="select a.prod_id,b.prod_name,b.prod_like,c.pic_path
            from hua_like a 
            left join hua_prod b on a.prod_id=b.prod_id
            left join hua_prod_pic c on c.prod_id=b.prod_id and c.pic_seq=0
            where a.user_id=$user_id";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }
    
    static function prodOnshelf($prod_id, $prod_onshelf_status) {
        $sql = "update hua_prod set prod_onshelf_type=$prod_onshelf_status where prod_id=$prod_id";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->simplePrepare($sql);
    }

    static function prodAlsoTag($prod_id)
    {
        $sql="
            select distinct a.prod_id,b.pic_path,c.prod_name 
            from hua_prod_tag a
            join hua_prod_pic b on a.prod_id=b.prod_id and pic_seq=0
            join hua_prod c on a.prod_id=c.prod_id
            where a.prod_id<>$prod_id and a.tag_id in
            (
                select tag_id from hua_prod_tag where prod_id=$prod_id
            ) order by c.prod_sale_price desc limit 4";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);   
    }

    static function getProdPic($prod_id,$pic_seq)
    {
        $sql="select prod_id,pic_path from hua_prod_pic where prod_id=$prod_id and pic_seq=$pic_seq";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql); 
    }

    static function listSearch($dict_list)
    {
        $sql="select * from hua_prod a
        left join hua_prod_pic b on a.prod_id=b.prod_id and b.pic_seq=0
        where 
        a.prod_onshelf_type=1
        and a.prod_id in
        (
            select prod_id 
            from hua_prod_tag
            where tag_id in ($dict_list)
        )";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql); 
    }

    static function getProdTagName($prod_tag)
    {
        $sql="select * from hua_dict where dict_id=$prod_tag";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql); 
    }
}

?>
