<?php
include_once (PATH_LIB . "/myPDO.inc");
include_once (PATH_DAL . "/db.inc");

class subDal
{
    static function sub_add($sub_type,$sub_name,$sub_desc,$sub_on,$sub_start,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list)
    {
        $sql = "insert into hua_sub(sub_type,sub_name,sub_desc,sub_on,sub_start,sub_pic_list,sub_pic,sub_tag,prod_id_list,cdate,udate)
            values
            ('$sub_type','$sub_name','$sub_desc','$sub_on','$sub_start','$sub_pic_list','$sub_pic','$sub_tag',
                '$prod_id_list',now(),now())";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return DB::huaDB()->lastInsertId();
        }
    }
    static function sub_update($sub_id,$sub_name,$sub_desc,$sub_on,$sub_start,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list)
    {
        $sql = "update hua_sub set sub_name='$sub_name',
            sub_desc='$sub_desc',
            sub_on='$sub_on',
            sub_start='$sub_start',
            sub_pic_list='$sub_pic_list',
            sub_pic='$sub_pic',
            sub_tag='$sub_tag',
            prod_id_list='$prod_id_list',
            udate=now()
            where sub_id=$sub_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        return $row;
    }
    
    static function getAllSub()
    {
        $sql="select * from hua_sub";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }
    
    static function getList($sub_type)
    {
        $sql="select * from hua_sub where sub_type='$sub_type'";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getBigSubs($n)
    {
        $sql="select * from hua_sub 
            where sub_start<=now() and sub_end>=now()
            and POSITION(',' in prod_id_list)<LENGTH(prod_id_list) limit $n";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }
    
    static function getSmallSubs($n)
    {
        $sql="select * from hua_sub 
            where sub_start<=now() and sub_end>=now()
            and POSITION(',' in prod_id_list)>=LENGTH(prod_id_list) limit $n";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }
    
    static function getByid($sub_id)
    {
        $sql="select * from hua_sub where sub_id=$sub_id";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getSubTagBySubid($sub_id)
    {
        $sql="select * from hua_sub_tag a
            join hua_dict b on a.tag_id=b.dict_id
            where a.sub_id=$sub_id";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);   
    }

    static function getTagsBysubid($sub_id)
    {
        $sql="select tag_id
            from hua_sub_tag
            where sub_id='$sub_id'";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function addSubTag($sub_tag,$sub_id)
    {
        $sub_tag_arr=explode(",",$sub_tag);
        foreach ($sub_tag_arr as $k => $v) {
            if($v!="")
            {
                $sql = "insert into hua_sub_tag (tag_id,sub_id,cdate,udate)
                    values ($v,$sub_id,now(),now())";
                if (!is_object(DB::huaDB()))
                    return array();
                DB::huaDB()->simplePrepare($sql);
            }
        }
    }

    static function updateSubTag($sub_tag,$sub_id)
    {
        $sql="delete from hua_sub_tag where sub_id=$sub_id";
        if (!is_object(DB::huaDB()))
            return array();
        DB::huaDB()->simplePrepare($sql);
        self::addSubTag($sub_tag,$sub_id);
    }
}
?>
