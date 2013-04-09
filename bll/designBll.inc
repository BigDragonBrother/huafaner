<?php
include_once (PATH_DAL."/designDal.inc");

class designBll
{
    static function design_index($design_var)
    {
    	return designDal::design_index($design_var)->data;
    }

    static function get_design($d_page)
    {
    	return designDal::get_design($d_page);
    }
}
?>