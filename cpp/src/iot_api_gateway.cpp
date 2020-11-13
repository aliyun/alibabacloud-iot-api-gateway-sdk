// This file is auto-generated, don't edit it. Thanks.

#include <alibabacloud/apigateway_util.hpp>
#include <alibabacloud/iot_api_gateway.hpp>
#include <boost/any.hpp>
#include <boost/throw_exception.hpp>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace std;

using namespace Alibabacloud_IotApiGateway;

Alibabacloud_IotApiGateway::Client::Client(const shared_ptr<Config> &config) {
  _domain = config->domain;
  _appKey = config->appKey;
  _appSecret = config->appSecret;
  _protocol = config->protocol;
  _readTimeout = config->readTimeout;
  _connectTimeout = config->connectTimeout;
  _httpProxy = config->httpProxy;
  _httpsProxy = config->httpsProxy;
  _noProxy = config->noProxy;
  _maxIdleConns = config->maxIdleConns;
};

Darabonba::Response Alibabacloud_IotApiGateway::Client::doRequest(
    shared_ptr<string> pathname, shared_ptr<string> protocol,
    shared_ptr<string> method, shared_ptr<map<string, string>> header,
    shared_ptr<IoTApiRequest> body,
    shared_ptr<Darabonba_Util::RuntimeOptions> runtime) {
  body->validate();
  runtime->validate();
  shared_ptr<map<string, boost::any>> runtime_ = make_shared<
      map<string, boost::any>>(map<string, boost::any>(
      {{"timeouted", boost::any(string("retry"))},
       {"readTimeout", boost::any(Darabonba_Util::Client::defaultNumber(
                           runtime->readTimeout, _readTimeout))},
       {"connectTimeout", boost::any(Darabonba_Util::Client::defaultNumber(
                              runtime->connectTimeout, _connectTimeout))},
       {"httpProxy", boost::any(string(Darabonba_Util::Client::defaultString(
                         runtime->httpProxy, _httpProxy)))},
       {"httpsProxy", boost::any(string(Darabonba_Util::Client::defaultString(
                          runtime->httpsProxy, _httpsProxy)))},
       {"noProxy", boost::any(string(Darabonba_Util::Client::defaultString(
                       runtime->noProxy, _noProxy)))},
       {"maxIdleConns", boost::any(Darabonba_Util::Client::defaultNumber(
                            runtime->maxIdleConns, _maxIdleConns))},
       {"retry", boost::any(map<string, boost::any>(
                     {{"retryable", !runtime->autoretry
                                        ? boost::any()
                                        : boost::any(*runtime->autoretry)},
                      {"maxAttempts",
                       boost::any(Darabonba_Util::Client::defaultNumber(
                           runtime->maxAttempts, make_shared<int>(3)))}}))},
       {"backoff",
        boost::any(map<string, boost::any>(
            {{"policy",
              boost::any(string(Darabonba_Util::Client::defaultString(
                  runtime->backoffPolicy, make_shared<string>("no"))))},
             {"period", boost::any(Darabonba_Util::Client::defaultNumber(
                            runtime->backoffPeriod, make_shared<int>(1)))}}))},
       {"ignoreSSL", !runtime->ignoreSSL ? boost::any()
                                         : boost::any(*runtime->ignoreSSL)}}));
  shared_ptr<Darabonba::Request> _lastRequest;
  shared_ptr<std::exception> _lastException;
  shared_ptr<int> _now = make_shared<int>(0);
  shared_ptr<int> _retryTimes = make_shared<int>(0);
  while (Darabonba::Core::allowRetry(
      make_shared<boost::any>((*runtime_)["retry"]), _retryTimes, _now)) {
    if (*_retryTimes > 0) {
      shared_ptr<int> _backoffTime =
          make_shared<int>(Darabonba::Core::getBackoffTime(
              make_shared<boost::any>((*runtime_)["backoff"]), _retryTimes));
      if (*_backoffTime > 0) {
        Darabonba::Core::sleep(_backoffTime);
      }
    }
    _retryTimes = make_shared<int>(*_retryTimes + 1);
    try {
      shared_ptr<Darabonba::Request> request_ =
          make_shared<Darabonba::Request>();
      request_->protocol =
          Darabonba_Util::Client::defaultString(_protocol, protocol);
      request_->method = Darabonba_Util::Client::defaultString(
          method, make_shared<string>("POST"));
      request_->pathname = *pathname;
      request_->headers = Darabonba::Converter::merge(
          map<string, string>(
              {{"host", !_domain ? string() : *_domain},
               {"date", Darabonba_Util::Client::getDateUTCString()},
               {"x-ca-nonce", Darabonba_Util::Client::getNonce()},
               {"x-ca-key", !_appKey ? string() : *_appKey},
               {"x-ca-signaturemethod", "HmacSHA256"},
               {"accept", "application/json"},
               {"user-agent", getUserAgent()}}),
          !header ? map<string, string>() : *header);
      if (Darabonba_Util::Client::empty(body->id)) {
        body->id = make_shared<string>(Darabonba_Util::Client::getNonce());
      }
      if (!Darabonba_Util::Client::isUnset<IoTApiRequest>(body)) {
        request_->headers.insert(
            pair<string, string>("content-type", "application/octet-stream"));
        request_->headers.insert(pair<string, string>(
            "content-md5",
            Alibabacloud_APIGatewayUtil::Client::getContentMD5(
                make_shared<string>(Darabonba_Util::Client::toJSONString(
                    make_shared<map<string, boost::any>>(body->toMap()))))));
        request_->body =
            Darabonba::Converter::toStream(Darabonba_Util::Client::toJSONString(
                make_shared<map<string, boost::any>>(body->toMap())));
      }
      request_->headers.insert(pair<string, string>(
          "x-ca-signature", Alibabacloud_APIGatewayUtil::Client::getSignature(
                                request_, _appSecret)));
      _lastRequest = request_;
      shared_ptr<Darabonba::Response> response_ =
          make_shared<Darabonba::Response>(
              Darabonba::Core::doAction(request_, runtime_));
      return *response_;
    } catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(e)) {
        _lastException = make_shared<std::exception>(e);
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(
      Darabonba::UnretryableError(_lastRequest, _lastException));
}

string Alibabacloud_IotApiGateway::Client::getUserAgent() {
  shared_ptr<string> userAgent =
      make_shared<string>(Darabonba_Util::Client::getUserAgent(_userAgent));
  return *userAgent;
}
