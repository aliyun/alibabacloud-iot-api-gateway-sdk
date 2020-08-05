package com.aliyun.iotapigateway;

import com.aliyun.iotapigateway.models.CommonParams;
import com.aliyun.iotapigateway.models.Config;
import com.aliyun.iotapigateway.models.IoTApiRequest;
import com.aliyun.tea.TeaResponse;
import com.aliyun.teautil.Common;
import com.aliyun.teautil.models.RuntimeOptions;
import org.junit.Assert;
import org.junit.Test;

import java.util.HashMap;
import java.util.Map;

public class ClientTest {

    @Test
    public void apiTest() throws Exception{
        Config config = new Config();
        config.appKey = System.getenv("IOT_APP_KEY");
        config.appSecret = System.getenv("IOT_APP_SECRET");
        config.domain = "api.link.aliyun.com";

        Client client = new Client(config);

        Map<String, Object> params = new HashMap<>();
        params.put("input", "test");

        CommonParams req = new CommonParams();
        req.apiVer = "1.0.0";

        IoTApiRequest body = new IoTApiRequest();
        body.params = params;
        body.request = req;

        RuntimeOptions runtime = new RuntimeOptions();

        TeaResponse teaResponse = client.doRequest("/kit/debug/ping", "HTTPS",
                "POST", null, body, runtime);

        Object obj = Common.readAsJSON(teaResponse.body);

        Map<String, Object> result = Common.assertAsMap(obj);
        Assert.assertEquals("test", result.get("data"));
    }
}
