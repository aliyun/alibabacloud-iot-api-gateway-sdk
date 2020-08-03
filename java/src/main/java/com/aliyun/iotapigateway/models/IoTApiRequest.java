// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.iotapigateway.models;

import com.aliyun.tea.*;

public class IoTApiRequest extends TeaModel {
    // 一次请求的标示，用于请求跟踪问题排查
    @NameInMap("id")
    public String id;

    // 协议版本
    @NameInMap("version")
    public String version;

    // JSON对象，访问指定api的业务参数
    @NameInMap("params")
    public java.util.Map<String, ?> params;

    // JSON对象，与业务无关的通用参数
    @NameInMap("request")
    @Validation(required = true)
    public CommonParams request;

    public static IoTApiRequest build(java.util.Map<String, ?> map) throws Exception {
        IoTApiRequest self = new IoTApiRequest();
        return TeaModel.build(map, self);
    }

}
