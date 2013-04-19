<?php
include_once (PATH_LIB . "/myPDO.inc");
include_once (PATH_DAL . "/db.inc");

class designDal 
{
	static function design_index($design_var)
    {
    	$sql="update hua_design set d_var='$design_var' where d_page='index'";
    	if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        return $row;
    }

    static function design_sublist($design_var)
    {
        $sql="update hua_design set d_var='$design_var' where d_page='sublist'";
        if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->simplePrepare($sql);
        return $row;
    }

    static function get_design($d_page)
    {
    	$sql="select * from hua_design where d_page='$d_page'";
    	if (!is_object(DB::huaDB()))
            return array();
        $row = DB::huaDB()->allPrepare($sql);
        if (count($row->data) == 0) {
            return array();
        } else {
            return $row->data[0];
        }
    }
}
?>