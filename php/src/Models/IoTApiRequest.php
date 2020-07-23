<?php

// This file is auto-generated, don't edit it. Thanks.

namespace AlibabaCloud\SDK\IotApiGateway\Models;

use AlibabaCloud\Tea\Model;

class IoTApiRequest extends Model
{
    /**
     * @description 一次请求的标示，用于请求跟踪问题排查
     *
     * @var string
     */
    public $id;

    /**
     * @description 协议版本
     *
     * @var string
     */
    public $version;

    /**
     * @description JSON对象，访问指定api的业务参数
     *
     * @var array
     */
    public $params;

    /**
     * @description JSON对象，与业务无关的通用参数
     *
     * @var CommonParams
     */
    public $request;
    protected $_name = [
        'id'      => 'id',
        'version' => 'version',
        'params'  => 'params',
        'request' => 'request',
    ];

    public function validate()
    {
        Model::validateRequired('request', $this->request, true);
    }

    public function toMap()
    {
        $res = [];
        if (null !== $this->id) {
            $res['id'] = $this->id;
        }
        if (null !== $this->version) {
            $res['version'] = $this->version;
        }
        if (null !== $this->params) {
            $res['params'] = $this->params;
        }
        if (null !== $this->request) {
            $res['request'] = null !== $this->request ? $this->request->toMap() : null;
        }

        return $res;
    }

    /**
     * @param array $map
     *
     * @return IoTApiRequest
     */
    public static function fromMap($map = [])
    {
        $model = new self();
        if (isset($map['id'])) {
            $model->id = $map['id'];
        }
        if (isset($map['version'])) {
            $model->version = $map['version'];
        }
        if (isset($map['params'])) {
            $model->params = $map['params'];
        }
        if (isset($map['request'])) {
            $model->request = CommonParams::fromMap($map['request']);
        }

        return $model;
    }
}
