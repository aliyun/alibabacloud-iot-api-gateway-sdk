English | [简体中文](README-CN.md)
![](https://aliyunsdk-pages.alicdn.com/icons/AlibabaCloud.svg)

## Alibaba Cloud IotApiGateway SDK for Python

## Installation
- **Install with pip**

Python SDK uses a common package management tool named `pip`. If pip is not installed, see the [pip user guide](https://pip.pypa.io/en/stable/installing/ "pip User Guide") to install pip.

```bash
# Install the otApiGateway SDK
pip install alibabacloud_iot_api_gateway
```

## Usage

```python
import os

from alibabacloud_iot_api_gateway.models import Config, IoTApiRequest, CommonParams
from alibabacloud_iot_api_gateway.client import Client
from alibabacloud_tea_util.models import RuntimeOptions

# init client
config = Config(
    app_key=os.environ['IOT_APP_KEY'],
    app_secret=os.environ['IOT_APP_SECRET'],
    domain='api.link.aliyun.com'
)
client = Client(config)

# build request
request = CommonParams(api_ver='1.0.0')
body = IoTApiRequest(
    params={'input': 'test'},
    request=request
)

# send request
response = client.do_request(
    '/kit/debug/ping',
    'https',
    'POST',
    None,
    body,
    RuntimeOptions()
)

print(response.body)
```

## Issues
[Opening an Issue](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk/issues/new), Issues not conforming to the guidelines may be closed immediately.

## Changelog
Detailed changes for each release are documented in the [release notes](./ChangeLog.md).

## References
* [Latest Release](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk)

## License
[Apache-2.0](http://www.apache.org/licenses/LICENSE-2.0)

Copyright (c) 2009-present, Alibaba Cloud All rights reserved.