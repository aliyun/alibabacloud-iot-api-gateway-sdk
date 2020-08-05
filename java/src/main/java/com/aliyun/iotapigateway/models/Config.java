// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.iotapigateway.models;

import com.aliyun.tea.*;

public class Config extends TeaModel {
    @NameInMap("domain")
    @Validation(required = true)
    public String domain;

    @NameInMap("protocol")
    public String protocol;

    @NameInMap("appKey")
    @Validation(required = true)
    public String appKey;

    @NameInMap("appSecret")
    @Validation(required = true)
    public String appSecret;

    @NameInMap("token")
    public String token;

    @NameInMap("regionId")
    public String regionId;

    @NameInMap("readTimeout")
    public Integer readTimeout;

    @NameInMap("connectTimeout")
    public Integer connectTimeout;

    @NameInMap("localAddr")
    public String localAddr;

    @NameInMap("httpProxy")
    public String httpProxy;

    @NameInMap("httpsProxy")
    public String httpsProxy;

    @NameInMap("noProxy")
    public String noProxy;

    @NameInMap("maxIdleConns")
    public Integer maxIdleConns;

    public static Config build(java.util.Map<String, ?> map) throws Exception {
        Config self = new Config();
        return TeaModel.build(map, self);
    }

}
