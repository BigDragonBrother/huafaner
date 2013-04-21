<?php
include_once PATH_DAL.'/subDal.inc';

class subBll
{
    static function sub_add($sub_type,$sub_name,$sub_desc,$sub_on,$sub_start,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list)
    {
        if($sub_start=="")
            $sub_start=date("Y-m-d");
        
        $prod_ids="";
        foreach (split(',', $prod_id_list) as $k => $v) {
            if($v!='')
                $prod_ids=$prod_ids.$v.',';
        }
        $prod_ids=substr($prod_ids, 0,strlen($prod_ids)-1);

        $sub_id =  subDal::sub_add($sub_type,$sub_name,$sub_desc,$sub_on,$sub_start,$sub_pic_list,$sub_pic,$sub_tag,$prod_ids);
        if(!$sub_id)
        {
            return false;
        }
        //subDal::addSubTag($sub_tag,$sub_id);
        return true;
    }
    
    static function sub_update($sub_id,$sub_name,$sub_desc,$sub_on,$sub_start,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list)
    {
        if($sub_start=="")
            $sub_start=date("Y-m-d");

        $prod_ids="";
        foreach (split(',', $prod_id_list) as $k => $v) {
            if($v!='')
                $prod_ids=$prod_ids.$v.',';
        }
        $prod_ids=substr($prod_ids, 0,strlen($prod_ids)-1);

        $result = subDal::sub_update($sub_id,$sub_name,$sub_desc,$sub_on,$sub_start,$sub_pic_list,$sub_pic,$sub_tag,$prod_ids);
        if(!$result)
        {
            return false;
        }
        //subDal::updateSubTag($sub_tag,$sub_id);
        return true;
    }

    static function getAllSub()
    {
        return subDal::getAllSub()->data;
    }
    
    static function getList($sub_type)
    {
        return subDal::getList($sub_type)->data;
    }
    
    static function getBigSubs($n)
    {
        return subDal::getBigSubs($n)->data;
    }
    
    static function getSmallSubs($n)
    {
        return subDal::getSmallSubs($n)->data;
    }
    
    static function getByid($sub_id)
    {
        return subDal::getByid($sub_id)->data[0];
    }

    static function getSubTagBySubid($sub_id)
    {
        return subDal::getSubTagBySubid($sub_id)->data;
    }

    static function getTagsBysubid($sub_id)
    {
        $return=array();
        foreach(subDal::getTagsBysubid($sub_id)->data as $k=>$v)
        {
            $return[]=$v['tag_id'];
        }
        return $return;
    }
}
?>

