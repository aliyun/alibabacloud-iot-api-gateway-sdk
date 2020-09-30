// This file is auto-generated, don't edit it
/**
 * test
 */
import Util, * as $Util from '@alicloud/tea-util';
import APIGatewayUtil from '@alicloud/api-gateway-baseclient';
import * as $tea from '@alicloud/tea-typescript';

export class Config extends $tea.Model {
  domain: string;
  protocol?: string;
  appKey: string;
  appSecret: string;
  token?: string;
  regionId?: string;
  readTimeout?: number;
  connectTimeout?: number;
  localAddr?: string;
  httpProxy?: string;
  httpsProxy?: string;
  userAgent?: string;
  noProxy?: string;
  maxIdleConns?: number;
  static names(): { [key: string]: string } {
    return {
      domain: 'domain',
      protocol: 'protocol',
      appKey: 'appKey',
      appSecret: 'appSecret',
      token: 'token',
      regionId: 'regionId',
      readTimeout: 'readTimeout',
      connectTimeout: 'connectTimeout',
      localAddr: 'localAddr',
      httpProxy: 'httpProxy',
      httpsProxy: 'httpsProxy',
      userAgent: 'userAgent',
      noProxy: 'noProxy',
      maxIdleConns: 'maxIdleConns',
    };
  }

  static types(): { [key: string]: any } {
    return {
      domain: 'string',
      protocol: 'string',
      appKey: 'string',
      appSecret: 'string',
      token: 'string',
      regionId: 'string',
      readTimeout: 'number',
      connectTimeout: 'number',
      localAddr: 'string',
      httpProxy: 'string',
      httpsProxy: 'string',
      userAgent: 'string',
      noProxy: 'string',
      maxIdleConns: 'number',
    };
  }

  constructor(map?: { [key: string]: any }) {
    super(map);
  }
}

export class CommonParams extends $tea.Model {
  apiVer: string;
  iotToken?: string;
  cloudToken?: string;
  language?: string;
  locale?: string;
  static names(): { [key: string]: string } {
    return {
      apiVer: 'apiVer',
      iotToken: 'iotToken',
      cloudToken: 'cloudToken',
      language: 'language',
      locale: 'locale',
    };
  }

  static types(): { [key: string]: any } {
    return {
      apiVer: 'string',
      iotToken: 'string',
      cloudToken: 'string',
      language: 'string',
      locale: 'string',
    };
  }

  constructor(map?: { [key: string]: any }) {
    super(map);
  }
}

export class IoTApiRequest extends $tea.Model {
  id?: string;
  version?: string;
  params?: { [key: string]: any };
  request: CommonParams;
  static names(): { [key: string]: string } {
    return {
      id: 'id',
      version: 'version',
      params: 'params',
      request: 'request',
    };
  }

  static types(): { [key: string]: any } {
    return {
      id: 'string',
      version: 'string',
      params: { 'type': 'map', 'keyType': 'string', 'valueType': 'any' },
      request: CommonParams,
    };
  }

  constructor(map?: { [key: string]: any }) {
    super(map);
  }
}


export default class Client {
  _appKey: string;
  _appSecret: string;
  _protocol: string;
  _userAgent: string;
  _readTimeout: number;
  _connectTimeout: number;
  _httpProxy: string;
  _httpsProxy: string;
  _noProxy: string;
  _maxIdleConns: number;
  _domain: string;

  constructor(config: Config) {
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
  async doRequest(pathname: string, protocol: string, method: string, header: {[key: string ]: string}, body: IoTApiRequest, runtime: $Util.RuntimeOptions): Promise<$tea.Response> {
    let _runtime: { [key: string]: any } = {
      timeouted: "retry",
      readTimeout: Util.defaultNumber(runtime.readTimeout, this._readTimeout),
      connectTimeout: Util.defaultNumber(runtime.connectTimeout, this._connectTimeout),
      httpProxy: Util.defaultString(runtime.httpProxy, this._httpProxy),
      httpsProxy: Util.defaultString(runtime.httpsProxy, this._httpsProxy),
      noProxy: Util.defaultString(runtime.noProxy, this._noProxy),
      maxIdleConns: Util.defaultNumber(runtime.maxIdleConns, this._maxIdleConns),
      retry: {
        retryable: runtime.autoretry,
        maxAttempts: Util.defaultNumber(runtime.maxAttempts, 3),
      },
      backoff: {
        policy: Util.defaultString(runtime.backoffPolicy, "no"),
        period: Util.defaultNumber(runtime.backoffPeriod, 1),
      },
      ignoreSSL: runtime.ignoreSSL,
    }

    let _lastRequest = null;
    let _now = Date.now();
    let _retryTimes = 0;
    while ($tea.allowRetry(_runtime['retry'], _retryTimes, _now)) {
      if (_retryTimes > 0) {
        let _backoffTime = $tea.getBackoffTime(_runtime['backoff'], _retryTimes);
        if (_backoffTime > 0) {
          await $tea.sleep(_backoffTime);
        }
      }

      _retryTimes = _retryTimes + 1;
      try {
        let request_ = new $tea.Request();
        request_.protocol = Util.defaultString(this._protocol, protocol);
        request_.method = Util.defaultString(method, "POST");
        request_.pathname = pathname;
        request_.headers = {
          host: this._domain,
          date: Util.getDateUTCString(),
          'x-ca-nonce': Util.getNonce(),
          'x-ca-key': this._appKey,
          'x-ca-signaturemethod': "HmacSHA256",
          accept: "application/json",
          'user-agent': this.getUserAgent(),
          ...header,
        };
        if (Util.empty(body.id)) {
          body.id = Util.getNonce();
        }

        if (!Util.isUnset($tea.toMap(body))) {
          request_.headers["content-type"] = "application/octet-stream";
          request_.headers["content-md5"] = APIGatewayUtil.getContentMD5(Util.toJSONString($tea.toMap(body)));
          request_.body = new $tea.BytesReadable(Util.toJSONString($tea.toMap(body)));
        }

        request_.headers["x-ca-signature"] = APIGatewayUtil.getSignature(request_, this._appSecret);
        _lastRequest = request_;
        let response_ = await $tea.doAction(request_, _runtime);

        return response_;
      } catch (ex) {
        if ($tea.isRetryable(ex)) {
          continue;
        }
        throw ex;
      }
    }

    throw $tea.newUnretryableError(_lastRequest);
  }

  /**
   * Get user agent
   * @return user agent
   */
  getUserAgent(): string {
    let userAgent = Util.getUserAgent(this._userAgent);
    return userAgent;
  }

}
