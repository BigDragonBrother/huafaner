<?php

class memCache
{

    private static $instance;
    private $memInstance;
    private $cacheHost = array();

    private function _setCacheHost($cacheHost)
    {
        $this->cacheHost = $cacheHost;
    }

    private function _getCacheHost()
    {
        return $this->cacheHost;
    }

    private function _getMemInstance()
    {
        return $this->memInstance;
    }

    private function _setMemInstance()
    {
        $this->memInstance = new Memcached();
        $this->memInstance->addServers($this->_getCacheHost());
    }

    public static function getInstance()
    {
        if (self::$instance == null)
        {
            self::$instance = new self();
        }
        return self::$instance;
    }

    public static function setCacheHost($cacheHost)
    {
        $instance = self::getInstance();
        $instance->_setCacheHost($cacheHost);
    }

    public static function getMemcached()
    {
        $instance = self::getInstance();
        if (!is_object($instance->_getMemInstance()))
        {
            $instance->_setMemInstance();
        }
        return $instance->_getMemInstance();
    }

    public static function set($key, $value, $expiration=300)
    {
        $instance = self::getInstance();
		return $instance->getMemcached()->set($key, $value, $expiration);;
    }

    public static function get($key)
    {
        $instance = self::getInstance();
        return $instance->getMemcached()->get($key);
    }

    public static function delete($key)
    {
        $instance = self::getInstance();
        return $instance->getMemcached()->delete($key);
    }

    public static function flush()
    {
        $instance = self::getInstance();
        return $instance->getMemcached()->flush();
    }

}

?>