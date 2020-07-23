<?php

// This file is auto-generated, don't edit it. Thanks.

namespace AlibabaCloud\SDK\IotApiGateway\Models;

use AlibabaCloud\Tea\Model;

class CommonParams extends Model
{
    /**
     * @description API版本
     *
     * @var string
     */
    public $apiVer;

    /**
     * @description 登录用户的token(客户端)
     *
     * @var string
     */
    public $iotToken;

    /**
     * @description 云端资源token（云端)
     *
     * @var string
     */
    public $cloudToken;

    /**
     * @description 国际化扩展，语言
     *
     * @var string
     */
    public $language;

    /**
     * @description 国际化扩展，地理位置、ip
     *
     * @var string
     */
    public $locale;
    protected $_name = [
        'apiVer'     => 'apiVer',
        'iotToken'   => 'iotToken',
        'cloudToken' => 'cloudToken',
        'language'   => 'language',
        'locale'     => 'locale',
    ];

    public function validate()
    {
        Model::validateRequired('apiVer', $this->apiVer, true);
    }

    public function toMap()
    {
        $res = [];
        if (null !== $this->apiVer) {
            $res['apiVer'] = $this->apiVer;
        }
        if (null !== $this->iotToken) {
            $res['iotToken'] = $this->iotToken;
        }
        if (null !== $this->cloudToken) {
            $res['cloudToken'] = $this->cloudToken;
        }
        if (null !== $this->language) {
            $res['language'] = $this->language;
        }
        if (null !== $this->locale) {
            $res['locale'] = $this->locale;
        }

        return $res;
    }

    /**
     * @param array $map
     *
     * @return CommonParams
     */
    public static function fromMap($map = [])
    {
        $model = new self();
        if (isset($map['apiVer'])) {
            $model->apiVer = $map['apiVer'];
        }
        if (isset($map['iotToken'])) {
            $model->iotToken = $map['iotToken'];
        }
        if (isset($map['cloudToken'])) {
            $model->cloudToken = $map['cloudToken'];
        }
        if (isset($map['language'])) {
            $model->language = $map['language'];
        }
        if (isset($map['locale'])) {
            $model->locale = $map['locale'];
        }

        return $model;
    }
}
