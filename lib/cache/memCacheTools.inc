<?php

include_once(PATH_LIB . '/cache/memCache.inc');
//include_once('./memCache.inc');

class memCacheTools
{

    private static $instance;
    private $paramArr = array();
    private $cacheHost = array();

    public static function getInstance()
    {
        if (self::$instance === null)
        {
            self::$instance = new self();
        }
        return self::$instance;
    }

    private function _setParamArr($paramArr)
    {
        $this->paramArr = $paramArr;
    }

    private function _setCacheHost($cacheHost)
    {
        $this->cacheHost = $cacheHost;
    }

    private function _getParamArr()
    {
        return $this->paramArr;
    }

    private function _getCacheHost()
    {
        return $this->cacheHost;
    }

    private function _getId()
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

    public static function setCacheHost($cacheHost)
    {
        $instance = self::getInstance();
        $instance->_setCacheHost($cacheHost);
    }

    public static function set($paramArr = array(), $priKey = array(), $content = array(), $lifeTime = 0)
    {
        $instance = self::getInstance();
        $instance->_setParamArr($paramArr);
        $cacheHost = $instance->_getCacheHost();
        memCache::setCacheHost($cacheHost);
        $id = $instance->_getId();
        if ($id)
        {
            $result = memCache::set($id, $content, $lifeTime);
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
        $instance->_setParamArr($paramArr);
        $cacheHost = $instance->_getCacheHost();
        memCache::setCacheHost($cacheHost);
        $id = $instance->_getId();
        if ($id)
        {
            $result = memCache::get($id);
        }
        else
        {
            $result = false;
        }
        return $result;
    }

}

?>