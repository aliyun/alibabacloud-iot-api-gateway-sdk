// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.iotapigateway;

import com.aliyun.tea.*;
import com.aliyun.iotapigateway.models.*;

public class Client {

    public String _appKey;
    public String _appSecret;
    public String _protocol;
    public String _userAgent;
    public Integer _readTimeout;
    public Integer _connectTimeout;
    public String _httpProxy;
    public String _httpsProxy;
    public String _noProxy;
    public Integer _maxIdleConns;
    public String _domain;
    public Client(Config config) throws Exception {
        this._domain = config.domain;
        this._appKey = config.appKey;
        this._appSecret = config.appSecret;
        this._protocol = config.protocol;
        this._readTimeout = config.readTimeout;
        this._connectTimeout = config.connectTimeout;
        this._httpProxy = config.httpProxy;
        this._httpsProxy = config.httpsProxy;
        this._noProxy = config.noProxy;
        this._maxIdleConns = config.maxIdleConns;
    }

    public TeaResponse doRequest(String pathname, String protocol, String method, java.util.Map<String, String> header, IoTApiRequest body, com.aliyun.teautil.models.RuntimeOptions runtime) throws Exception {
        TeaModel.validateParams(body, "body");
        java.util.Map<String, Object> runtime_ = TeaConverter.buildMap(
            new TeaPair("timeouted", "retry"),
            new TeaPair("readTimeout", com.aliyun.teautil.Common.defaultNumber(runtime.readTimeout, _readTimeout)),
            new TeaPair("connectTimeout", com.aliyun.teautil.Common.defaultNumber(runtime.connectTimeout, _connectTimeout)),
            new TeaPair("httpProxy", com.aliyun.teautil.Common.defaultString(runtime.httpProxy, _httpProxy)),
            new TeaPair("httpsProxy", com.aliyun.teautil.Common.defaultString(runtime.httpsProxy, _httpsProxy)),
            new TeaPair("noProxy", com.aliyun.teautil.Common.defaultString(runtime.noProxy, _noProxy)),
            new TeaPair("maxIdleConns", com.aliyun.teautil.Common.defaultNumber(runtime.maxIdleConns, _maxIdleConns)),
            new TeaPair("retry", TeaConverter.buildMap(
                new TeaPair("retryable", runtime.autoretry),
                new TeaPair("maxAttempts", com.aliyun.teautil.Common.defaultNumber(runtime.maxAttempts, 3))
            )),
            new TeaPair("backoff", TeaConverter.buildMap(
                new TeaPair("policy", com.aliyun.teautil.Common.defaultString(runtime.backoffPolicy, "no")),
                new TeaPair("period", com.aliyun.teautil.Common.defaultNumber(runtime.backoffPeriod, 1))
            )),
            new TeaPair("ignoreSSL", runtime.ignoreSSL)
        );

        TeaRequest _lastRequest = null;
        long _now = System.currentTimeMillis();
        int _retryTimes = 0;
        while (Tea.allowRetry((java.util.Map<String, Object>) runtime_.get("retry"), _retryTimes, _now)) {
            if (_retryTimes > 0) {
                int backoffTime = Tea.getBackoffTime(runtime_.get("backoff"), _retryTimes);
                if (backoffTime > 0) {
                    Tea.sleep(backoffTime);
                }
            }
            _retryTimes = _retryTimes + 1;
            try {
                TeaRequest request_ = new TeaRequest();
                request_.protocol = com.aliyun.teautil.Common.defaultString(_protocol, protocol);
                request_.method = com.aliyun.teautil.Common.defaultString(method, "POST");
                request_.pathname = pathname;
                request_.headers = TeaConverter.merge(String.class,
                    TeaConverter.buildMap(
                        new TeaPair("host", _domain),
                        new TeaPair("date", com.aliyun.teautil.Common.getDateUTCString()),
                        new TeaPair("x-ca-nonce", com.aliyun.teautil.Common.getNonce()),
                        new TeaPair("x-ca-key", _appKey),
                        new TeaPair("x-ca-signaturemethod", "HmacSHA256"),
                        new TeaPair("accept", "application/json"),
                        new TeaPair("user-agent", this.getUserAgent())
                    ),
                    header
                );
                if (com.aliyun.teautil.Common.empty(body.id)) {
                    body.id = com.aliyun.teautil.Common.getNonce();
                }

                if (!com.aliyun.teautil.Common.isUnset(TeaModel.buildMap(body))) {
                    request_.headers.put("content-type", "application/octet-stream");
                    request_.headers.put("content-md5", com.aliyun.api_gateway_baseclient.Client.getContentMD5(com.aliyun.teautil.Common.toJSONString(TeaModel.buildMap(body))));
                    request_.body = Tea.toReadable(com.aliyun.teautil.Common.toJSONString(TeaModel.buildMap(body)));
                }

                request_.headers.put("x-ca-signature", com.aliyun.api_gateway_baseclient.Client.getSignature(request_, _appSecret));
                _lastRequest = request_;
                TeaResponse response_ = Tea.doAction(request_, runtime_);

                return response_;
            } catch (Exception e) {
                if (Tea.isRetryable(e)) {
                    continue;
                }
                throw e;
            }
        }

        throw new TeaUnretryableException(_lastRequest);
    }

    /**
     * Get user agent
     * @return user agent
     */
    public String getUserAgent() throws Exception {
        String userAgent = com.aliyun.teautil.Common.getUserAgent(_userAgent);
        return userAgent;
    }
}
