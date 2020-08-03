// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.iotapigateway.models;

import com.aliyun.tea.*;

public class CommonParams extends TeaModel {
    // API版本
    @NameInMap("apiVer")
    @Validation(required = true)
    public String apiVer;

    // 登录用户的token(客户端)
    @NameInMap("iotToken")
    public String iotToken;

    // 云端资源token（云端)
    @NameInMap("cloudToken")
    public String cloudToken;

    // 国际化扩展，语言
    @NameInMap("language")
    public String language;

    // 国际化扩展，地理位置、ip
    @NameInMap("locale")
    public String locale;

    public static CommonParams build(java.util.Map<String, ?> map) throws Exception {
        CommonParams self = new CommonParams();
        return TeaModel.build(map, self);
    }

}
