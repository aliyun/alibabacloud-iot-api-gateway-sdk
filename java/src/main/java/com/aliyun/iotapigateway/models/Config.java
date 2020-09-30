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

    @NameInMap("userAgent")
    public String userAgent;

    @NameInMap("noProxy")
    public String noProxy;

    @NameInMap("maxIdleConns")
    public Integer maxIdleConns;

    public static Config build(java.util.Map<String, ?> map) throws Exception {
        Config self = new Config();
        return TeaModel.build(map, self);
    }

    public Config setDomain(String domain) {
        this.domain = domain;
        return this;
    }
    public String getDomain() {
        return this.domain;
    }

    public Config setProtocol(String protocol) {
        this.protocol = protocol;
        return this;
    }
    public String getProtocol() {
        return this.protocol;
    }

    public Config setAppKey(String appKey) {
        this.appKey = appKey;
        return this;
    }
    public String getAppKey() {
        return this.appKey;
    }

    public Config setAppSecret(String appSecret) {
        this.appSecret = appSecret;
        return this;
    }
    public String getAppSecret() {
        return this.appSecret;
    }

    public Config setToken(String token) {
        this.token = token;
        return this;
    }
    public String getToken() {
        return this.token;
    }

    public Config setRegionId(String regionId) {
        this.regionId = regionId;
        return this;
    }
    public String getRegionId() {
        return this.regionId;
    }

    public Config setReadTimeout(Integer readTimeout) {
        this.readTimeout = readTimeout;
        return this;
    }
    public Integer getReadTimeout() {
        return this.readTimeout;
    }

    public Config setConnectTimeout(Integer connectTimeout) {
        this.connectTimeout = connectTimeout;
        return this;
    }
    public Integer getConnectTimeout() {
        return this.connectTimeout;
    }

    public Config setLocalAddr(String localAddr) {
        this.localAddr = localAddr;
        return this;
    }
    public String getLocalAddr() {
        return this.localAddr;
    }

    public Config setHttpProxy(String httpProxy) {
        this.httpProxy = httpProxy;
        return this;
    }
    public String getHttpProxy() {
        return this.httpProxy;
    }

    public Config setHttpsProxy(String httpsProxy) {
        this.httpsProxy = httpsProxy;
        return this;
    }
    public String getHttpsProxy() {
        return this.httpsProxy;
    }

    public Config setUserAgent(String userAgent) {
        this.userAgent = userAgent;
        return this;
    }
    public String getUserAgent() {
        return this.userAgent;
    }

    public Config setNoProxy(String noProxy) {
        this.noProxy = noProxy;
        return this;
    }
    public String getNoProxy() {
        return this.noProxy;
    }

    public Config setMaxIdleConns(Integer maxIdleConns) {
        this.maxIdleConns = maxIdleConns;
        return this;
    }
    public Integer getMaxIdleConns() {
        return this.maxIdleConns;
    }

}
