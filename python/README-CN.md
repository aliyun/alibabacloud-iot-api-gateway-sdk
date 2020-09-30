[English](README.md) | 简体中文

![](https://aliyunsdk-pages.alicdn.com/icons/AlibabaCloud.svg)

## Alibaba Cloud IotApiGateway SDK for Python


## 安装

- **使用 pip 安装(推荐)**

如未安装 `pip`, 请先至pip官网 [pip user guide](https://pip.pypa.io/en/stable/installing/ "pip User Guide") 安装pip .

```bash
# 安装 IotApiGateway SDK
pip install alibabacloud_iot_api_gateway
```

## 使用

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


## 问题
[提交 Issue](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk/issues/new)，不符合指南的问题可能会立即关闭。

## 发行说明
每个版本的详细更改记录在[发行说明](./ChangeLog.md)中。

## 相关
* [最新源码](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk)

## 许可证
[Apache-2.0](http://www.apache.org/licenses/LICENSE-2.0)

Copyright (c) 2009-present, Alibaba Cloud All rights reserved.

