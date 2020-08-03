using System;
using System.Collections.Generic;
using AlibabaCloud.SDK.IotApiGateway;
using AlibabaCloud.SDK.IotApiGateway.Models;
using AlibabaCloud.TeaUtil;
using AlibabaCloud.TeaUtil.Models;
using Tea.Utils;
using Xunit;

namespace tests
{
    public class ClientTest
    {
        [Fact]
        public void TestApi()
        {
            var config = new Config
            { 
                AppKey = Environment.GetEnvironmentVariable("IOT_APP_KEY"),
                AppSecret = Environment.GetEnvironmentVariable("IOT_APP_SECRET"),
                Domain = "api.link.aliyun.com"
            };

            var client = new Client(config);

            var param = new Dictionary<string, string>
            {
                { "input", "test" }
            };

            var req = new CommonParams
            {
                ApiVer = "1.0.0"
            };

            var body = new IoTApiRequest
            {
                Params = param,
                Request = req
            };

            var runtime = new RuntimeOptions();

            var resp = client.DoRequest("/kit/debug/ping", "HTTPS", "POST", null, body, runtime);

            var obj = AlibabaCloud.TeaUtil.Common.ReadAsJSON(resp.Body);

            var map = AlibabaCloud.TeaUtil.Common.AssertAsMap(obj);

            Assert.Contains("test", map.Get("data").ToSafeString());
        }
    }
}
