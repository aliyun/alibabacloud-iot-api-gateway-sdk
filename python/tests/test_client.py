import unittest
import json
import os

from alibabacloud_iot_api_gateway.models import Config, IoTApiRequest, CommonParams
from alibabacloud_iot_api_gateway.client import Client
from alibabacloud_tea_util.models import RuntimeOptions


class TestClient(unittest.TestCase):
    def test_client(self):
        config = Config(
            app_key=os.environ['IOT_APP_KEY'],
            app_secret=os.environ['IOT_APP_SECRET'],
            domain='api.link.aliyun.com'
        )
        client = Client(config)
        request = CommonParams(
            api_ver='1.0.0'
        )
        body = IoTApiRequest(
            params={
                'input': 'test'
            },
            request=request
        )
        res = client.do_request(
            '/kit/debug/ping',
            'https',
            'POST',
            None,
            body,
            RuntimeOptions()
        )
        print(res.body.decode('utf-8'))
        data = json.loads(res.body.decode('utf-8'))
        self.assertEqual(200, data['code'])
        self.assertEqual('test', data['data'])
