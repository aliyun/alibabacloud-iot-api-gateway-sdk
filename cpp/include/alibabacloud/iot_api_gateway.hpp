// This file is auto-generated, don't edit it. Thanks.

#ifndef ALIBABACLOUD_IOTAPIGATEWAY_H_
#define ALIBABACLOUD_IOTAPIGATEWAY_H_

#include <alibabacloud/apigateway_util.hpp>
#include <boost/any.hpp>
#include <boost/throw_exception.hpp>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace std;

namespace Alibabacloud_IotApiGateway {
class Config : public Darabonba::Model {
public:
  Config() {}
  explicit Config(const std::map<string, boost::any> &config)
      : Darabonba::Model(config) {
    fromMap(config);
  };

  void validate() override {
    if (!domain) {
      BOOST_THROW_EXCEPTION(
          boost::enable_error_info(std::runtime_error("domain is required.")));
    }
    if (!appKey) {
      BOOST_THROW_EXCEPTION(
          boost::enable_error_info(std::runtime_error("appKey is required.")));
    }
    if (!appSecret) {
      BOOST_THROW_EXCEPTION(boost::enable_error_info(
          std::runtime_error("appSecret is required.")));
    }
  }

  map<string, boost::any> toMap() override {
    map<string, boost::any> res;
    if (domain) {
      res["domain"] = boost::any(*domain);
    }
    if (protocol) {
      res["protocol"] = boost::any(*protocol);
    }
    if (appKey) {
      res["appKey"] = boost::any(*appKey);
    }
    if (appSecret) {
      res["appSecret"] = boost::any(*appSecret);
    }
    if (token) {
      res["token"] = boost::any(*token);
    }
    if (regionId) {
      res["regionId"] = boost::any(*regionId);
    }
    if (readTimeout) {
      res["readTimeout"] = boost::any(*readTimeout);
    }
    if (connectTimeout) {
      res["connectTimeout"] = boost::any(*connectTimeout);
    }
    if (localAddr) {
      res["localAddr"] = boost::any(*localAddr);
    }
    if (httpProxy) {
      res["httpProxy"] = boost::any(*httpProxy);
    }
    if (httpsProxy) {
      res["httpsProxy"] = boost::any(*httpsProxy);
    }
    if (userAgent) {
      res["userAgent"] = boost::any(*userAgent);
    }
    if (noProxy) {
      res["noProxy"] = boost::any(*noProxy);
    }
    if (maxIdleConns) {
      res["maxIdleConns"] = boost::any(*maxIdleConns);
    }
    return res;
  }

  void fromMap(map<string, boost::any> m) override {
    if (m.find("domain") != m.end() && !m["domain"].empty()) {
      domain = make_shared<string>(boost::any_cast<string>(m["domain"]));
    }
    if (m.find("protocol") != m.end() && !m["protocol"].empty()) {
      protocol = make_shared<string>(boost::any_cast<string>(m["protocol"]));
    }
    if (m.find("appKey") != m.end() && !m["appKey"].empty()) {
      appKey = make_shared<string>(boost::any_cast<string>(m["appKey"]));
    }
    if (m.find("appSecret") != m.end() && !m["appSecret"].empty()) {
      appSecret = make_shared<string>(boost::any_cast<string>(m["appSecret"]));
    }
    if (m.find("token") != m.end() && !m["token"].empty()) {
      token = make_shared<string>(boost::any_cast<string>(m["token"]));
    }
    if (m.find("regionId") != m.end() && !m["regionId"].empty()) {
      regionId = make_shared<string>(boost::any_cast<string>(m["regionId"]));
    }
    if (m.find("readTimeout") != m.end() && !m["readTimeout"].empty()) {
      readTimeout = make_shared<int>(boost::any_cast<int>(m["readTimeout"]));
    }
    if (m.find("connectTimeout") != m.end() && !m["connectTimeout"].empty()) {
      connectTimeout =
          make_shared<int>(boost::any_cast<int>(m["connectTimeout"]));
    }
    if (m.find("localAddr") != m.end() && !m["localAddr"].empty()) {
      localAddr = make_shared<string>(boost::any_cast<string>(m["localAddr"]));
    }
    if (m.find("httpProxy") != m.end() && !m["httpProxy"].empty()) {
      httpProxy = make_shared<string>(boost::any_cast<string>(m["httpProxy"]));
    }
    if (m.find("httpsProxy") != m.end() && !m["httpsProxy"].empty()) {
      httpsProxy =
          make_shared<string>(boost::any_cast<string>(m["httpsProxy"]));
    }
    if (m.find("userAgent") != m.end() && !m["userAgent"].empty()) {
      userAgent = make_shared<string>(boost::any_cast<string>(m["userAgent"]));
    }
    if (m.find("noProxy") != m.end() && !m["noProxy"].empty()) {
      noProxy = make_shared<string>(boost::any_cast<string>(m["noProxy"]));
    }
    if (m.find("maxIdleConns") != m.end() && !m["maxIdleConns"].empty()) {
      maxIdleConns = make_shared<int>(boost::any_cast<int>(m["maxIdleConns"]));
    }
  }

  shared_ptr<string> domain{};
  shared_ptr<string> protocol{};
  shared_ptr<string> appKey{};
  shared_ptr<string> appSecret{};
  shared_ptr<string> token{};
  shared_ptr<string> regionId{};
  shared_ptr<int> readTimeout{};
  shared_ptr<int> connectTimeout{};
  shared_ptr<string> localAddr{};
  shared_ptr<string> httpProxy{};
  shared_ptr<string> httpsProxy{};
  shared_ptr<string> userAgent{};
  shared_ptr<string> noProxy{};
  shared_ptr<int> maxIdleConns{};

  ~Config() = default;
};
class CommonParams : public Darabonba::Model {
public:
  CommonParams() {}
  explicit CommonParams(const std::map<string, boost::any> &config)
      : Darabonba::Model(config) {
    fromMap(config);
  };

  void validate() override {
    if (!apiVer) {
      BOOST_THROW_EXCEPTION(
          boost::enable_error_info(std::runtime_error("apiVer is required.")));
    }
  }

  map<string, boost::any> toMap() override {
    map<string, boost::any> res;
    if (apiVer) {
      res["apiVer"] = boost::any(*apiVer);
    }
    if (iotToken) {
      res["iotToken"] = boost::any(*iotToken);
    }
    if (cloudToken) {
      res["cloudToken"] = boost::any(*cloudToken);
    }
    if (language) {
      res["language"] = boost::any(*language);
    }
    if (locale) {
      res["locale"] = boost::any(*locale);
    }
    return res;
  }

  void fromMap(map<string, boost::any> m) override {
    if (m.find("apiVer") != m.end() && !m["apiVer"].empty()) {
      apiVer = make_shared<string>(boost::any_cast<string>(m["apiVer"]));
    }
    if (m.find("iotToken") != m.end() && !m["iotToken"].empty()) {
      iotToken = make_shared<string>(boost::any_cast<string>(m["iotToken"]));
    }
    if (m.find("cloudToken") != m.end() && !m["cloudToken"].empty()) {
      cloudToken =
          make_shared<string>(boost::any_cast<string>(m["cloudToken"]));
    }
    if (m.find("language") != m.end() && !m["language"].empty()) {
      language = make_shared<string>(boost::any_cast<string>(m["language"]));
    }
    if (m.find("locale") != m.end() && !m["locale"].empty()) {
      locale = make_shared<string>(boost::any_cast<string>(m["locale"]));
    }
  }

  shared_ptr<string> apiVer{};
  shared_ptr<string> iotToken{};
  shared_ptr<string> cloudToken{};
  shared_ptr<string> language{};
  shared_ptr<string> locale{};

  ~CommonParams() = default;
};
class IoTApiRequest : public Darabonba::Model {
public:
  IoTApiRequest() {}
  explicit IoTApiRequest(const std::map<string, boost::any> &config)
      : Darabonba::Model(config) {
    fromMap(config);
  };

  void validate() override {
    if (!request) {
      BOOST_THROW_EXCEPTION(
          boost::enable_error_info(std::runtime_error("request is required.")));
    }
  }

  map<string, boost::any> toMap() override {
    map<string, boost::any> res;
    if (id) {
      res["id"] = boost::any(*id);
    }
    if (version) {
      res["version"] = boost::any(*version);
    }
    if (params) {
      res["params"] = boost::any(*params);
    }
    if (request) {
      res["request"] = request ? boost::any(request->toMap())
                               : boost::any(map<string, boost::any>({}));
    }
    return res;
  }

  void fromMap(map<string, boost::any> m) override {
    if (m.find("id") != m.end() && !m["id"].empty()) {
      id = make_shared<string>(boost::any_cast<string>(m["id"]));
    }
    if (m.find("version") != m.end() && !m["version"].empty()) {
      version = make_shared<string>(boost::any_cast<string>(m["version"]));
    }
    if (m.find("params") != m.end() && !m["params"].empty()) {
      map<string, boost::any> map1 =
          boost::any_cast<map<string, boost::any>>(m["params"]);
      map<string, boost::any> toMap1;
      for (auto item : map1) {
        toMap1[item.first] = item.second;
      }
      params = make_shared<map<string, boost::any>>(toMap1);
    }
    if (m.find("request") != m.end() && !m["request"].empty()) {
      if (typeid(map<string, boost::any>).name() ==
          m["request"].type().name()) {
        CommonParams model1;
        model1.fromMap(boost::any_cast<map<string, boost::any>>(m["request"]));
        request = make_shared<CommonParams>(model1);
      }
    }
  }

  shared_ptr<string> id{};
  shared_ptr<string> version{};
  shared_ptr<map<string, boost::any>> params{};
  shared_ptr<CommonParams> request{};

  ~IoTApiRequest() = default;
};
class Client {
public:
  shared_ptr<string> _appKey{};
  shared_ptr<string> _appSecret{};
  shared_ptr<string> _protocol{};
  shared_ptr<string> _userAgent{};
  shared_ptr<int> _readTimeout{};
  shared_ptr<int> _connectTimeout{};
  shared_ptr<string> _httpProxy{};
  shared_ptr<string> _httpsProxy{};
  shared_ptr<string> _noProxy{};
  shared_ptr<int> _maxIdleConns{};
  shared_ptr<string> _domain{};
  explicit Client(const shared_ptr<Config> &config);
  Darabonba::Response
  doRequest(shared_ptr<string> pathname, shared_ptr<string> protocol,
            shared_ptr<string> method, shared_ptr<map<string, string>> header,
            shared_ptr<IoTApiRequest> body,
            shared_ptr<Darabonba_Util::RuntimeOptions> runtime);
  string getUserAgent();

  ~Client() = default;
};
} // namespace Alibabacloud_IotApiGateway

#endif
