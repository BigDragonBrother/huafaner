<?php

include_once (PATH_LIB . "/myPDO.inc");
include_once (PATH_DAL . "/db.inc");

class blogDal {

    static function add_blog($blog_title,$blog_index,$blog_content) 
    {
        $sql = "insert into hua_blog (blog_title,blog_index,blog_sum,blog_content,cdate,udate) values ('$blog_title','$blog_index','$blog_sum','$blog_content',now(),now())";

        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return DB::huaDB()->lastInsertId();
        }
    }

    static function update_blog($blog_id,$blog_title,$blog_index,$blog_content)
    {
        $sql="update hua_blog set blog_title='$blog_title',blog_index='$blog_index',blog_sum='$blog_sum',blog_content='$blog_content',udate=now() where blog_id=$blog_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return true;
        }
        else
        {
            return false;
        }
    }

    static function get_blog($blog_id)
    {
        $sql = "select * from hua_blog where blog_id='$blog_id'";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);
    }

    static function getList()
    {
        $sql = "select * from hua_blog order by blog_id desc";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);   
    }

    static function getTopN($n)
    {
        $sql = "select * from hua_blog order by blog_id desc limit $n";
        if (!is_object(DB::huaDB()))
            return array();
        return DB::huaDB()->allPrepare($sql);  
    }

    static function addView($blog_id)
    {
        $sql="update hua_blog set blog_view=blog_view+1 where blog_id=$blog_id";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        if (!$row->isEmpty()) {
            return true;
        }
        else
        {
            return false;
        }
    }
}