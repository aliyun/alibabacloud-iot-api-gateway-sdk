// This file is auto-generated, don't edit it. Thanks.
/**
 * test
 */
package client

import (
	apigatewayutil "github.com/alibabacloud-go/apigateway-util/service"
	util "github.com/alibabacloud-go/tea-utils/service"
	"github.com/alibabacloud-go/tea/tea"
)

type Config struct {
	Domain         *string `json:"domain,omitempty" xml:"domain,omitempty" require:"true"`
	Protocol       *string `json:"protocol,omitempty" xml:"protocol,omitempty"`
	AppKey         *string `json:"appKey,omitempty" xml:"appKey,omitempty" require:"true"`
	AppSecret      *string `json:"appSecret,omitempty" xml:"appSecret,omitempty" require:"true"`
	Token          *string `json:"token,omitempty" xml:"token,omitempty"`
	RegionId       *string `json:"regionId,omitempty" xml:"regionId,omitempty"`
	ReadTimeout    *int    `json:"readTimeout,omitempty" xml:"readTimeout,omitempty"`
	ConnectTimeout *int    `json:"connectTimeout,omitempty" xml:"connectTimeout,omitempty"`
	LocalAddr      *string `json:"localAddr,omitempty" xml:"localAddr,omitempty"`
	HttpProxy      *string `json:"httpProxy,omitempty" xml:"httpProxy,omitempty"`
	HttpsProxy     *string `json:"httpsProxy,omitempty" xml:"httpsProxy,omitempty"`
	UserAgent      *string `json:"userAgent,omitempty" xml:"userAgent,omitempty"`
	NoProxy        *string `json:"noProxy,omitempty" xml:"noProxy,omitempty"`
	MaxIdleConns   *int    `json:"maxIdleConns,omitempty" xml:"maxIdleConns,omitempty"`
}

func (s Config) String() string {
	return tea.Prettify(s)
}

func (s Config) GoString() string {
	return s.String()
}

func (s *Config) SetDomain(v string) *Config {
	s.Domain = &v
	return s
}

func (s *Config) SetProtocol(v string) *Config {
	s.Protocol = &v
	return s
}

func (s *Config) SetAppKey(v string) *Config {
	s.AppKey = &v
	return s
}

func (s *Config) SetAppSecret(v string) *Config {
	s.AppSecret = &v
	return s
}

func (s *Config) SetToken(v string) *Config {
	s.Token = &v
	return s
}

func (s *Config) SetRegionId(v string) *Config {
	s.RegionId = &v
	return s
}

func (s *Config) SetReadTimeout(v int) *Config {
	s.ReadTimeout = &v
	return s
}

func (s *Config) SetConnectTimeout(v int) *Config {
	s.ConnectTimeout = &v
	return s
}

func (s *Config) SetLocalAddr(v string) *Config {
	s.LocalAddr = &v
	return s
}

func (s *Config) SetHttpProxy(v string) *Config {
	s.HttpProxy = &v
	return s
}

func (s *Config) SetHttpsProxy(v string) *Config {
	s.HttpsProxy = &v
	return s
}

func (s *Config) SetUserAgent(v string) *Config {
	s.UserAgent = &v
	return s
}

func (s *Config) SetNoProxy(v string) *Config {
	s.NoProxy = &v
	return s
}

func (s *Config) SetMaxIdleConns(v int) *Config {
	s.MaxIdleConns = &v
	return s
}

type CommonParams struct {
	// API版本
	ApiVer *string `json:"apiVer,omitempty" xml:"apiVer,omitempty" require:"true"`
	// 登录用户的token(客户端)
	IotToken *string `json:"iotToken,omitempty" xml:"iotToken,omitempty"`
	// 云端资源token（云端)
	CloudToken *string `json:"cloudToken,omitempty" xml:"cloudToken,omitempty"`
	// 国际化扩展，语言
	Language *string `json:"language,omitempty" xml:"language,omitempty"`
	// 国际化扩展，地理位置、ip
	Locale *string `json:"locale,omitempty" xml:"locale,omitempty"`
}

func (s CommonParams) String() string {
	return tea.Prettify(s)
}

func (s CommonParams) GoString() string {
	return s.String()
}

func (s *CommonParams) SetApiVer(v string) *CommonParams {
	s.ApiVer = &v
	return s
}

func (s *CommonParams) SetIotToken(v string) *CommonParams {
	s.IotToken = &v
	return s
}

func (s *CommonParams) SetCloudToken(v string) *CommonParams {
	s.CloudToken = &v
	return s
}

func (s *CommonParams) SetLanguage(v string) *CommonParams {
	s.Language = &v
	return s
}

func (s *CommonParams) SetLocale(v string) *CommonParams {
	s.Locale = &v
	return s
}

type IoTApiRequest struct {
	// 一次请求的标示，用于请求跟踪问题排查
	Id *string `json:"id,omitempty" xml:"id,omitempty"`
	// 协议版本
	Version *string `json:"version,omitempty" xml:"version,omitempty"`
	// JSON对象，访问指定api的业务参数
	Params map[string]interface{} `json:"params,omitempty" xml:"params,omitempty"`
	// JSON对象，与业务无关的通用参数
	Request *CommonParams `json:"request,omitempty" xml:"request,omitempty" require:"true"`
}

func (s IoTApiRequest) String() string {
	return tea.Prettify(s)
}

func (s IoTApiRequest) GoString() string {
	return s.String()
}

func (s *IoTApiRequest) SetId(v string) *IoTApiRequest {
	s.Id = &v
	return s
}

func (s *IoTApiRequest) SetVersion(v string) *IoTApiRequest {
	s.Version = &v
	return s
}

func (s *IoTApiRequest) SetParams(v map[string]interface{}) *IoTApiRequest {
	s.Params = v
	return s
}

func (s *IoTApiRequest) SetRequest(v *CommonParams) *IoTApiRequest {
	s.Request = v
	return s
}

type Client struct {
	AppKey         *string
	AppSecret      *string
	Protocol       *string
	UserAgent      *string
	ReadTimeout    *int
	ConnectTimeout *int
	HttpProxy      *string
	HttpsProxy     *string
	NoProxy        *string
	MaxIdleConns   *int
	Domain         *string
}

func NewClient(config *Config) (*Client, error) {
	client := new(Client)
	err := client.Init(config)
	return client, err
}

func (client *Client) Init(config *Config) (_err error) {
	client.Domain = config.Domain
	client.AppKey = config.AppKey
	client.AppSecret = config.AppSecret
	client.Protocol = config.Protocol
	client.ReadTimeout = config.ReadTimeout
	client.ConnectTimeout = config.ConnectTimeout
	client.HttpProxy = config.HttpProxy
	client.HttpsProxy = config.HttpsProxy
	client.NoProxy = config.NoProxy
	client.MaxIdleConns = config.MaxIdleConns
	return nil
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
func (client *Client) DoRequest(pathname *string, protocol *string, method *string, header map[string]*string, body *IoTApiRequest, runtime *util.RuntimeOptions) (_result *tea.Response, _err error) {
	_err = tea.Validate(body)
	if _err != nil {
		return _result, _err
	}
	_err = tea.Validate(runtime)
	if _err != nil {
		return _result, _err
	}
	_runtime := map[string]interface{}{
		"timeouted":      "retry",
		"readTimeout":    tea.IntValue(util.DefaultNumber(runtime.ReadTimeout, client.ReadTimeout)),
		"connectTimeout": tea.IntValue(util.DefaultNumber(runtime.ConnectTimeout, client.ConnectTimeout)),
		"httpProxy":      tea.StringValue(util.DefaultString(runtime.HttpProxy, client.HttpProxy)),
		"httpsProxy":     tea.StringValue(util.DefaultString(runtime.HttpsProxy, client.HttpsProxy)),
		"noProxy":        tea.StringValue(util.DefaultString(runtime.NoProxy, client.NoProxy)),
		"maxIdleConns":   tea.IntValue(util.DefaultNumber(runtime.MaxIdleConns, client.MaxIdleConns)),
		"retry": map[string]interface{}{
			"retryable":   tea.BoolValue(runtime.Autoretry),
			"maxAttempts": tea.IntValue(util.DefaultNumber(runtime.MaxAttempts, tea.Int(3))),
		},
		"backoff": map[string]interface{}{
			"policy": tea.StringValue(util.DefaultString(runtime.BackoffPolicy, tea.String("no"))),
			"period": tea.IntValue(util.DefaultNumber(runtime.BackoffPeriod, tea.Int(1))),
		},
		"ignoreSSL": tea.BoolValue(runtime.IgnoreSSL),
	}

	_resp := &tea.Response{}
	for _retryTimes := 0; tea.BoolValue(tea.AllowRetry(_runtime["retry"], tea.Int(_retryTimes))); _retryTimes++ {
		if _retryTimes > 0 {
			_backoffTime := tea.GetBackoffTime(_runtime["backoff"], tea.Int(_retryTimes))
			if tea.IntValue(_backoffTime) > 0 {
				tea.Sleep(_backoffTime)
			}
		}

		_resp, _err = func() (*tea.Response, error) {
			request_ := tea.NewRequest()
			request_.Protocol = util.DefaultString(client.Protocol, protocol)
			request_.Method = util.DefaultString(method, tea.String("POST"))
			request_.Pathname = pathname
			request_.Headers = tea.Merge(map[string]*string{
				"host":                 client.Domain,
				"date":                 util.GetDateUTCString(),
				"x-ca-nonce":           util.GetNonce(),
				"x-ca-key":             client.AppKey,
				"x-ca-signaturemethod": tea.String("HmacSHA256"),
				"accept":               tea.String("application/json"),
				"user-agent":           client.GetUserAgent(),
			}, header)
			if tea.BoolValue(util.Empty(body.Id)) {
				body.Id = util.GetNonce()
			}

			if !tea.BoolValue(util.IsUnset(tea.ToMap(body))) {
				request_.Headers["content-type"] = tea.String("application/octet-stream")
				request_.Headers["content-md5"] = apigatewayutil.GetContentMD5(util.ToJSONString(tea.ToMap(body)))
				request_.Body = tea.ToReader(util.ToJSONString(tea.ToMap(body)))
			}

			request_.Headers["x-ca-signature"] = apigatewayutil.GetSignature(request_, client.AppSecret)
			response_, _err := tea.DoRequest(request_, _runtime)
			if _err != nil {
				return _result, _err
			}
			_result = response_
			return _result, _err
		}()
		if !tea.BoolValue(tea.Retryable(_err)) {
			break
		}
	}

	return _resp, _err
}

/**
 * Get user agent
 * @return user agent
 */
func (client *Client) GetUserAgent() (_result *string) {
	userAgent := util.GetUserAgent(client.UserAgent)
	_result = userAgent
	return _result
}
