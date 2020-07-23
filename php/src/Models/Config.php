<?php

// This file is auto-generated, don't edit it. Thanks.
namespace AlibabaCloud\SDK\IotApiGateway\Models;

use AlibabaCloud\Tea\Model;

class Config extends Model {
    public function validate() {
        Model::validateRequired('domain', $this->domain, true);
        Model::validateRequired('appKey', $this->appKey, true);
        Model::validateRequired('appSecret', $this->appSecret, true);
    }
    public function toMap() {
        $res = [];
        if (null !== $this->domain) {
            $res['domain'] = $this->domain;
        }
        if (null !== $this->protocol) {
            $res['protocol'] = $this->protocol;
        }
        if (null !== $this->appKey) {
            $res['appKey'] = $this->appKey;
        }
        if (null !== $this->appSecret) {
            $res['appSecret'] = $this->appSecret;
        }
        if (null !== $this->token) {
            $res['token'] = $this->token;
        }
        if (null !== $this->regionId) {
            $res['regionId'] = $this->regionId;
        }
        if (null !== $this->readTimeout) {
            $res['readTimeout'] = $this->readTimeout;
        }
        if (null !== $this->connectTimeout) {
            $res['connectTimeout'] = $this->connectTimeout;
        }
        if (null !== $this->localAddr) {
            $res['localAddr'] = $this->localAddr;
        }
        if (null !== $this->httpProxy) {
            $res['httpProxy'] = $this->httpProxy;
        }
        if (null !== $this->httpsProxy) {
            $res['httpsProxy'] = $this->httpsProxy;
        }
        if (null !== $this->noProxy) {
            $res['noProxy'] = $this->noProxy;
        }
        if (null !== $this->maxIdleConns) {
            $res['maxIdleConns'] = $this->maxIdleConns;
        }
        return $res;
    }
    /**
     * @param array $map
     * @return Config
     */
    public static function fromMap($map = []) {
        $model = new self();
        if(isset($map['domain'])){
            $model->domain = $map['domain'];
        }
        if(isset($map['protocol'])){
            $model->protocol = $map['protocol'];
        }
        if(isset($map['appKey'])){
            $model->appKey = $map['appKey'];
        }
        if(isset($map['appSecret'])){
            $model->appSecret = $map['appSecret'];
        }
        if(isset($map['token'])){
            $model->token = $map['token'];
        }
        if(isset($map['regionId'])){
            $model->regionId = $map['regionId'];
        }
        if(isset($map['readTimeout'])){
            $model->readTimeout = $map['readTimeout'];
        }
        if(isset($map['connectTimeout'])){
            $model->connectTimeout = $map['connectTimeout'];
        }
        if(isset($map['localAddr'])){
            $model->localAddr = $map['localAddr'];
        }
        if(isset($map['httpProxy'])){
            $model->httpProxy = $map['httpProxy'];
        }
        if(isset($map['httpsProxy'])){
            $model->httpsProxy = $map['httpsProxy'];
        }
        if(isset($map['noProxy'])){
            $model->noProxy = $map['noProxy'];
        }
        if(isset($map['maxIdleConns'])){
            $model->maxIdleConns = $map['maxIdleConns'];
        }
        return $model;
    }
    /**
     * @var string
     */
    public $domain;

    public $protocol;

    /**
     * @var string
     */
    public $appKey;

    /**
     * @var string
     */
    public $appSecret;

    public $token;

    public $regionId;

    public $readTimeout;

    public $connectTimeout;

    public $localAddr;

    public $httpProxy;

    public $httpsProxy;

    public $noProxy;

    public $maxIdleConns;

}
