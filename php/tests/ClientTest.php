<?php

namespace AlibabaCloud\SDK\IotApiGateway\Tests;

use AlibabaCloud\SDK\IotApiGateway\Client;
use AlibabaCloud\SDK\IotApiGateway\Models\CommonParams;
use AlibabaCloud\SDK\IotApiGateway\Models\Config;
use AlibabaCloud\SDK\IotApiGateway\Models\IoTApiRequest;
use AlibabaCloud\Tea\Utils\Utils\RuntimeOptions;
use PHPUnit\Framework\TestCase;

/**
 * @internal
 * @coversNothing
 */
class ClientTest extends TestCase
{
    public function testDoRequest()
    {
        $config            = new Config();
        $config->appKey    = getenv('IOT_APP_KEY');
        $config->appSecret = getenv('IOT_APP_SECRET');
        $config->domain    = 'api.link.aliyun.com';

        $client = new Client($config);

        $params = [
            'input' => 'test',
        ];

        $request                = new CommonParams();
        $request->apiVer        = '1.0.0';
        $iotApiRequest          = new IoTApiRequest();
        $iotApiRequest->request = $request;
        $iotApiRequest->params  = $params;

        $runtime = new RuntimeOptions();

        $res    = $client->doRequest(
            '/kit/debug/ping',
            'HTTPS',
            'POST',
            null,
            $iotApiRequest,
            $runtime
        );
        $result = $res->all();
        $this->assertEquals(200, $result['code']);
        $this->assertEquals('test', $result['data']);
    }
}
