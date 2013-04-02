<?php

include_once(PATH_LIB . '/cache/fileCache.inc');

class fileCacheTools
{

    private static $instance;
    private $priKey = array();
    private $paramArr = array();
    private $cacheDir = './';

    public static function getInstance()
    {
        if (self::$instance === null)
        {
            self::$instance = new self();
        }
        return self::$instance;
    }

    private function _setPriKey($priKey)
    {

        $this->priKey = $priKey;
    }

    private function _setParamArr($paramArr)
    {
        $this->paramArr = $paramArr;
    }

    private function _getPriKey()
    {
        return $this->priKey;
    }

    private function _getParamArr()
    {
        return $this->paramArr;
    }

    private function _fileToId()
    {
        if (is_array($this->paramArr))
        {
            $id = '';
            foreach ($this->paramArr as $key => $val)
            {
                $id .= $key . '=' . $val . '&';
            }
            return md5($id);
        }
        else
        {
            return false;
        }
    }

    private function _priKeyToDir()
    {
        if (is_array($this->priKey))
        {
            $id = '';
            foreach ($this->priKey as $val)
            {
                $id .= $val . '&';
            }
            $dir = md5($id);
            $dir = $this->cacheDir . '/' . $dir;
            return $dir;
        }
        else
        {
            return false;
        }
    }

    public static function setCacheDir($cacheDir)
    {
        $instance = self::getInstance();
        $instance->cacheDir = $cacheDir;
    }

    public static function set($paramArr = array(), $priKey = array(), $content = array(), $lifeTime = 0)
    {
        $instance = self::getInstance();
        $instance->_setPriKey($priKey);
        $instance->_setParamArr($paramArr);
        $cacheDir = $instance->_priKeyToDir();
        fileCache::setCacheDir($cacheDir);
        $id = $instance->_fileToId();
        if ($id)
        {
            $result = fileCache::set($id, $content, $lifeTime);
        }
        else
        {
            $result = false;
        }
        return $result;
    }

    public static function get($paramArr = array(), $priKey = array())
    {
        $instance = self::getInstance();
        $instance->_setPriKey($priKey);
        $instance->_setParamArr($paramArr);
        $cacheDir = $instance->_priKeyToDir();
        fileCache::setCacheDir($cacheDir);
        $id = $instance->_fileToId();
        if ($id)
        {
            $result = fileCache::get($id);
        }
        else
        {
            $result = false;
        }
        return $result;
    }

}

?>