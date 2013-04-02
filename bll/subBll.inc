<?php
include_once PATH_DAL.'/subDal.inc';

class subBll
{
    static function sub_add($sub_name,$sub_desc,$sub_show_seq,$sub_start,$sub_end,$sub_pic_main,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list)
    {
        $sub_id =  subDal::sub_add($sub_name,$sub_desc,$sub_show_seq,$sub_start,$sub_end,$sub_pic_main,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list);
        if(!$sub_id)
        {
            return false;
        }
        subDal::addSubTag($sub_tag,$sub_id);
        return true;
    }
    
    static function sub_update($sub_id,$sub_name,$sub_desc,$sub_show_seq,$sub_start,$sub_end,$sub_pic_main,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list)
    {
        $result = subDal::sub_update($sub_id,$sub_name,$sub_desc,$sub_show_seq,$sub_start,$sub_end,$sub_pic_main,$sub_pic_list,$sub_pic,$sub_tag,$prod_id_list);
        if(!$result)
        {
            return false;
        }
        subDal::updateSubTag($sub_tag,$sub_id);
        return true;
    }
    
    static function getAllSub()
    {
        return subDal::getAllSub()->data;
    }
    
    static function getSubList()
    {
        return subDal::getSubList()->data;
    }
    
    static function getBigSubs($n)
    {
        return subDal::getBigSubs($n)->data;
    }
    
    static function getSmallSubs($n)
    {
        return subDal::getSmallSubs($n)->data;
    }
    
    static function getSubByid($sub_id)
    {
        return subDal::getSubByid($sub_id)->data[0];
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

