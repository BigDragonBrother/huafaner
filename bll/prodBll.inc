<?php
include_once (PATH_DAL."/prodDal.inc");

class prodBll
{
    static function getDict($type='all')
    {
        return prodDal::getDict($type)->data;
    }
    
    static function addDict($type,$dict_name,$dict_desc="")
    {
        return prodDal::addDict($type,$dict_name,$dict_desc);
    }
    
    static function delDict($dict_id)
    {
        return prodDal::delDict($dict_id);
    }
    
    static function addProd($prod_name,$prod_title,$prod_type,$prod_sale_price,$pic_arr,
        $prod_word,$prod_medium,$standards,$prod_care_desc,$prod_order_desc,$prod_tag,
        $prod_stock_up,$prod_date_range,$prod_onshelf_type,$prod_onshelf_time)
    {
        //if(count(self::getProdByname($prod_name))>0)
        //{
        //    return 0;
        //}
        $prod_id = prodDal::addProd(
                $prod_name,
                $prod_title,
                $prod_type,
                $prod_sale_price,
                $prod_word,
                $prod_medium,
                $standards,
                $prod_care_desc,
                $prod_order_desc,
                $prod_stock_up,
                $prod_date_range,
                $prod_onshelf_type,
                $prod_onshelf_time);
        if(!$prod_id)
        {
            return false;
        }
        prodDal::addProdTag($prod_tag,$prod_id);
        prodDal::addProdPic($pic_arr, $prod_id);
        return true;
    }
    
    static function updateProd($prod_id,$prod_name,$prod_title,$prod_type,$prod_sale_price,$pic_arr,
        $prod_word,$prod_medium,$standards,$prod_care_desc,$prod_order_desc,$prod_tag,
        $prod_stock_up,$prod_date_range,$prod_onshelf_type,$prod_onshelf_time)
    {
        $result = prodDal::updateProd(
                $prod_id,
                $prod_name,
                $prod_title,
                $prod_type,
                $prod_sale_price,
                $prod_word,
                $prod_medium,
                $standards,
                $prod_care_desc,
                $prod_order_desc,
                $prod_stock_up,
                $prod_date_range,
                $prod_onshelf_type,
                $prod_onshelf_time);
        if(!$result)
        {
            return false;
        }
        prodDal::updateProdPic($pic_arr, $prod_id);
        prodDal::updateProdTag($prod_tag,$prod_id);
        return true;
    }
            
            
    static function getProdByid($prod_id)
    {
        return prodDal::getProdByid($prod_id);
    }
    
    static function getProdByids($prod_id_list)
    {
        return prodDal::getProdByids($prod_id_list);
    }
    
    static function getProdByname($prod_name)
    {
        return prodDal::getProdByname($prod_name);
        
    }
    
    static function getProdPicByprodid($prod_id)
    {
        return prodDal::getProdPicByprodid($prod_id)->data;
    }

    static function getProdTagByprodid($prod_id)
    {
        return prodDal::getProdTagByprodid($prod_id)->data;
    }

    static function getTagsByprodid($prod_id)
    {
        $return=array();
        foreach(prodDal::getTagsByprodid($prod_id)->data as $k=>$v)
        {
            $return[]=$v['tag_id'];
        }
        return $return;
    }
    
    static function getProdTopN($n=50)
    {
        return prodDal::getProdTopN($n)->data;
    }

    static function getProdByType($prod_type)
    {
        return prodDal::getProdByType($prod_type)->data;   
    }
    
    static function getProdByTag($prod_tag)
    {
        return prodDal::listSearch($prod_tag)->data;   
    }

    static function getProdTag($prod_tag)
    {
        return prodDal::getProdTagName($prod_tag)->data;   
    }

    static function getProds($where,$page_num,$page_size)
    {
        return prodDal::getProds($where,$page_num,$page_size)->data;
    }
    
    static function prodLike($user_id,$prod_id)
    {
        return prodDal::prodLike($user_id,$prod_id);
    }
    
    static function getLike($user_id,$prod_id)
    {
        return prodDal::getLike($user_id,$prod_id)->data;
    }
    
    static function getLikeByuserid($user_id)
    {
        return prodDal::getLikeByuserid($user_id)->data;
    }
    
    static function prodOnshelf($prod_id,$prod_onshelf_status)
    {
        if($prod_onshelf_status!=1)
        {
            $prod_onshelf_status=1;
        }
        else
        {
            $prod_onshelf_status=3;
        }
        return prodDal::prodOnshelf($prod_id,$prod_onshelf_status);
    }

    static function getOnlyprods($n)
    {
        return prodDal::getOnlyprods($n)->data;
    }

    static function getallOnlyprods()
    {
        return prodDal::getallOnlyprods()->data;
    }

    static function prodAlsoTag($prod_id)
    {
        return prodDal::prodAlsoTag($prod_id)->data;
    }

    static function getProdPic($prod_id,$pic_seq)
    {
        //pic_seq的枚举值 1是列表页的图，2是缩略图，3是商品详情图
        return prodDal::getProdPic($prod_id,$pic_seq)->data;
    }

    static function listSearch($dict_list)
    {
        $str="";
        $dict_arr=split(',',$dict_list);
        foreach ($dict_arr as $key => $value) {
            if($value!="")
            {
                $str=$str.$value.",";
            }
        }
        $str=substr($str, 0,strlen($str)-1);

        $result = prodDal::listSearch($str)->data;
        if(count($result)==0)
        {
            return "";
        }
        $return="";

        foreach ($result as $k => $v) {
            $return=$return.'<dd><p><a href="prod.php?id='.$v['prod_id'].'" target="_blank"><img src="'.$v['pic_path'].'" title="'.$v['prod_title'].'" style="width:310px;height:296px;"/></a></p><div class="title"><div class="tit_price"><h3><a href="prod.php?id='.$v['prod_id'].'" target="_blank">'.$v['prod_name'].'</a></h3><p class="price_con">¥ '.number_format($v['prod_sale_price'], 1).'</p></div><div class="btn_y"><a href="prod.php?id='.$v['prod_id'].'" target="_blank">立即购买</a></div><a class="full"></a></div></dd>';
        }
        return $return;
    }
}
?>