#include "gtest/gtest.h"
#include <alibabacloud/iot_api_gateway.hpp>
#include <darabonba/util.hpp>

using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(tests_Client, test_doRequest)
{
  Alibabacloud_IotApiGateway::Config config;
  config.appKey = make_shared<string>(getenv("IOT_APP_KEY"));
  config.appSecret = make_shared<string>(getenv("IOT_APP_SECRET"));
  config.domain = make_shared<string>("api.link.aliyun.com");

  Alibabacloud_IotApiGateway::CommonParams request;
  request.apiVer = make_shared<string>("1.0.0");

  Alibabacloud_IotApiGateway::IoTApiRequest body;
  body.params = make_shared<map<string, boost::any>>(
      map<string, boost::any>({
                                  {"input", "test"}
      })
    );
  body.request = make_shared<Alibabacloud_IotApiGateway::CommonParams>(request);
  Alibabacloud_IotApiGateway::Client client(make_shared<Alibabacloud_IotApiGateway::Config>(config));

  Darabonba::Response response = client.doRequest(
      make_shared<string>("/kit/debug/ping"),
          make_shared<string>("https"),
              make_shared<string>("POST"),
                  make_shared<map<string,string>>(),
                  make_shared<Alibabacloud_IotApiGateway::IoTApiRequest>(body),
                      make_shared<Darabonba_Util::RuntimeOptions>()
  );
  map<string, boost::any> res = boost::any_cast<map<string, boost::any>>(
      Darabonba_Util::Client::parseJSON(make_shared<string>(response.body->read()))
  );

  ASSERT_EQ(200,boost::any_cast<int>(res["code"]));
  ASSERT_EQ("test",boost::any_cast<string>(res["data"]));
}

