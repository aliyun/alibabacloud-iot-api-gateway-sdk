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

    public IoTApiRequest setId(String id) {
        this.id = id;
        return this;
    }
    public String getId() {
        return this.id;
    }

    public IoTApiRequest setVersion(String version) {
        this.version = version;
        return this;
    }
    public String getVersion() {
        return this.version;
    }

    public IoTApiRequest setParams(java.util.Map<String, ?> params) {
        this.params = params;
        return this;
    }
    public java.util.Map<String, ?> getParams() {
        return this.params;
    }

    public IoTApiRequest setRequest(CommonParams request) {
        this.request = request;
        return this;
    }
    public CommonParams getRequest() {
        return this.request;
    }

}
