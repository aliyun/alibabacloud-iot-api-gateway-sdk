// This file is auto-generated, don't edit it. Thanks.

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

using Tea;
using Tea.Utils;

using AlibabaCloud.SDK.IotApiGateway.Models;

namespace AlibabaCloud.SDK.IotApiGateway
{
    public class Client 
    {
        protected string _appKey;
        protected string _appSecret;
        protected string _protocol;
        protected string _userAgent;
        protected int? _readTimeout;
        protected int? _connectTimeout;
        protected string _httpProxy;
        protected string _httpsProxy;
        protected string _noProxy;
        protected int? _maxIdleConns;
        protected string _domain;

        public Client(Config config)
        {
            this._domain = config.Domain;
            this._appKey = config.AppKey;
            this._appSecret = config.AppSecret;
            this._protocol = config.Protocol;
            this._readTimeout = config.ReadTimeout;
            this._connectTimeout = config.ConnectTimeout;
            this._httpProxy = config.HttpProxy;
            this._httpsProxy = config.HttpsProxy;
            this._noProxy = config.NoProxy;
            this._maxIdleConns = config.MaxIdleConns;
        }

        /**
         * Send request
         * @param pathname the url path
         * @param protocol http or https
         * @param method example GET
         * @param header request header
         * @param body the object of IoTApiRequest
         * @param runtime which controls some details of call api, such as retry times
         * @return the response
         */
        public TeaResponse DoRequest(string pathname, string protocol, string method, Dictionary<string, string> header, IoTApiRequest body, AlibabaCloud.TeaUtil.Models.RuntimeOptions runtime)
        {
            body.Validate();
            Dictionary<string, object> runtime_ = new Dictionary<string, object>
            {
                {"timeouted", "retry"},
                {"readTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ReadTimeout, _readTimeout)},
                {"connectTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ConnectTimeout, _connectTimeout)},
                {"httpProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpProxy, _httpProxy)},
                {"httpsProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpsProxy, _httpsProxy)},
                {"noProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.NoProxy, _noProxy)},
                {"maxIdleConns", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxIdleConns, _maxIdleConns)},
                {"retry", new Dictionary<string, object>
                {
                    {"retryable", runtime.Autoretry},
                    {"maxAttempts", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxAttempts, 3)},
                }},
                {"backoff", new Dictionary<string, object>
                {
                    {"policy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.BackoffPolicy, "no")},
                    {"period", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.BackoffPeriod, 1)},
                }},
                {"ignoreSSL", runtime.IgnoreSSL},
            };

            TeaRequest _lastRequest = null;
            Exception _lastException = null;
            long _now = System.DateTime.Now.Millisecond;
            int _retryTimes = 0;
            while (TeaCore.AllowRetry((IDictionary) runtime_["retry"], _retryTimes, _now))
            {
                if (_retryTimes > 0)
                {
                    int backoffTime = TeaCore.GetBackoffTime((IDictionary)runtime_["backoff"], _retryTimes);
                    if (backoffTime > 0)
                    {
                        TeaCore.Sleep(backoffTime);
                    }
                }
                _retryTimes = _retryTimes + 1;
                try
                {
                    TeaRequest request_ = new TeaRequest();
                    request_.Protocol = AlibabaCloud.TeaUtil.Common.DefaultString(_protocol, protocol);
                    request_.Method = AlibabaCloud.TeaUtil.Common.DefaultString(method, "POST");
                    request_.Pathname = pathname;
                    request_.Headers = TeaConverter.merge<string>
                    (
                        new Dictionary<string, string>()
                        {
                            {"host", _domain},
                            {"date", AlibabaCloud.TeaUtil.Common.GetDateUTCString()},
                            {"x-ca-nonce", AlibabaCloud.TeaUtil.Common.GetNonce()},
                            {"x-ca-key", _appKey},
                            {"x-ca-signaturemethod", "HmacSHA256"},
                            {"accept", "application/json"},
                            {"user-agent", GetUserAgent()},
                        },
                        header
                    );
                    if (AlibabaCloud.TeaUtil.Common.Empty(body.Id))
                    {
                        body.Id = AlibabaCloud.TeaUtil.Common.GetNonce();
                    }
                    if (!AlibabaCloud.TeaUtil.Common.IsUnset(body.ToMap()))
                    {
                        request_.Headers["content-type"] = "application/octet-stream";
                        request_.Headers["content-md5"] = AlibabaCloud.APIGatewayUtil.Common.GetContentMD5(AlibabaCloud.TeaUtil.Common.ToJSONString(body.ToMap()));
                        request_.Body = TeaCore.BytesReadable(AlibabaCloud.TeaUtil.Common.ToJSONString(body.ToMap()));
                    }
                    request_.Headers["x-ca-signature"] = AlibabaCloud.APIGatewayUtil.Common.GetSignature(request_, _appSecret);
                    _lastRequest = request_;
                    TeaResponse response_ = TeaCore.DoAction(request_, runtime_);

                    return response_;
                }
                catch (Exception e)
                {
                    if (TeaCore.IsRetryable(e))
                    {
                        _lastException = e;
                        continue;
                    }
                    throw e;
                }
            }

            throw new TeaUnretryableException(_lastRequest, _lastException);
        }

        /**
         * Send request
         * @param pathname the url path
         * @param protocol http or https
         * @param method example GET
         * @param header request header
         * @param body the object of IoTApiRequest
         * @param runtime which controls some details of call api, such as retry times
         * @return the response
         */
        public async Task<TeaResponse> DoRequestAsync(string pathname, string protocol, string method, Dictionary<string, string> header, IoTApiRequest body, AlibabaCloud.TeaUtil.Models.RuntimeOptions runtime)
        {
            body.Validate();
            Dictionary<string, object> runtime_ = new Dictionary<string, object>
            {
                {"timeouted", "retry"},
                {"readTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ReadTimeout, _readTimeout)},
                {"connectTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ConnectTimeout, _connectTimeout)},
                {"httpProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpProxy, _httpProxy)},
                {"httpsProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpsProxy, _httpsProxy)},
                {"noProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.NoProxy, _noProxy)},
                {"maxIdleConns", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxIdleConns, _maxIdleConns)},
                {"retry", new Dictionary<string, object>
                {
                    {"retryable", runtime.Autoretry},
                    {"maxAttempts", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxAttempts, 3)},
                }},
                {"backoff", new Dictionary<string, object>
                {
                    {"policy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.BackoffPolicy, "no")},
                    {"period", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.BackoffPeriod, 1)},
                }},
                {"ignoreSSL", runtime.IgnoreSSL},
            };

            TeaRequest _lastRequest = null;
            Exception _lastException = null;
            long _now = System.DateTime.Now.Millisecond;
            int _retryTimes = 0;
            while (TeaCore.AllowRetry((IDictionary) runtime_["retry"], _retryTimes, _now))
            {
                if (_retryTimes > 0)
                {
                    int backoffTime = TeaCore.GetBackoffTime((IDictionary)runtime_["backoff"], _retryTimes);
                    if (backoffTime > 0)
                    {
                        TeaCore.Sleep(backoffTime);
                    }
                }
                _retryTimes = _retryTimes + 1;
                try
                {
                    TeaRequest request_ = new TeaRequest();
                    request_.Protocol = AlibabaCloud.TeaUtil.Common.DefaultString(_protocol, protocol);
                    request_.Method = AlibabaCloud.TeaUtil.Common.DefaultString(method, "POST");
                    request_.Pathname = pathname;
                    request_.Headers = TeaConverter.merge<string>
                    (
                        new Dictionary<string, string>()
                        {
                            {"host", _domain},
                            {"date", AlibabaCloud.TeaUtil.Common.GetDateUTCString()},
                            {"x-ca-nonce", AlibabaCloud.TeaUtil.Common.GetNonce()},
                            {"x-ca-key", _appKey},
                            {"x-ca-signaturemethod", "HmacSHA256"},
                            {"accept", "application/json"},
                            {"user-agent", GetUserAgent()},
                        },
                        header
                    );
                    if (AlibabaCloud.TeaUtil.Common.Empty(body.Id))
                    {
                        body.Id = AlibabaCloud.TeaUtil.Common.GetNonce();
                    }
                    if (!AlibabaCloud.TeaUtil.Common.IsUnset(body.ToMap()))
                    {
                        request_.Headers["content-type"] = "application/octet-stream";
                        request_.Headers["content-md5"] = AlibabaCloud.APIGatewayUtil.Common.GetContentMD5(AlibabaCloud.TeaUtil.Common.ToJSONString(body.ToMap()));
                        request_.Body = TeaCore.BytesReadable(AlibabaCloud.TeaUtil.Common.ToJSONString(body.ToMap()));
                    }
                    request_.Headers["x-ca-signature"] = AlibabaCloud.APIGatewayUtil.Common.GetSignature(request_, _appSecret);
                    _lastRequest = request_;
                    TeaResponse response_ = await TeaCore.DoActionAsync(request_, runtime_);

                    return response_;
                }
                catch (Exception e)
                {
                    if (TeaCore.IsRetryable(e))
                    {
                        _lastException = e;
                        continue;
                    }
                    throw e;
                }
            }

            throw new TeaUnretryableException(_lastRequest, _lastException);
        }

        /**
         * Get user agent
         * @return user agent
         */
        public string GetUserAgent()
        {
            string userAgent = AlibabaCloud.TeaUtil.Common.GetUserAgent(_userAgent);
            return userAgent;
        }

    }
}
