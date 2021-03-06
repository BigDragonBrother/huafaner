<?php
include_once (PATH_DAL."/blogDal.inc");

class blogBll
{
    static function add_blog($blog_id,$blog_title,$blog_index,$blog_sum,$blog_content)
    {
        if($blog_id=="undefined")
        {
            return blogDal::add_blog($blog_title,$blog_index,$blog_sum,$blog_content);
        }
        else
        {
            return blogDal::update_blog($blog_id,$blog_title,$blog_index,$blog_sum,$blog_content);
        }
    }

    static function get_blog($blog_id)
    {
        return blogDal::get_blog($blog_id)->data[0];
    }

    static function getList()
    {
        return blogDal::getList()->data;
    }

    static function getTopN($n)
    {
        return blogDal::getTopN($n)->data;
    }

    static function addView($blog_id)
    {
        return blogDal::addView($blog_id);
    }

    static function blog_del($blog_id)
    {
        return blogDal::blog_del($blog_id);
    }    
}
?>