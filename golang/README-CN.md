[English](README.md) | 简体中文

![](https://aliyunsdk-pages.alicdn.com/icons/AlibabaCloud.svg)

## Alibaba Cloud IotApiGateway SDK Library for Go

## 安装

```bash
go get github.com/alibabacloud-go/iot-api-gateway
```

## 使用示例

```go
package main

import (
	"fmt"

	iot "github.com/alibabacloud-go/iot-api-gateway/client"
	util "github.com/alibabacloud-go/tea-utils/service"
	"github.com/alibabacloud-go/tea/tea"
)

func main() {
    //Step1: init client
	config := new(iot.Config).
		SetAppKey("IOT_APP_KEY").
		SetAppSecret("IOT_APP_SECRET").
		SetDomain("api.link.aliyun.com")

	client, err := iot.NewClient(config)
	if err != nil {
		panic(err)
	}

    //Step2: build request
	params := map[string]interface{}{
		"input": "gotest",
	}
	req := new(iot.CommonParams).
		SetApiVer("1.0.0")

	body := new(iot.IoTApiRequest).
		SetParams(params).
		SetRequest(req)

	runtime := new(util.RuntimeOptions)
    //Step3: send request
	resp, err := client.DoRequest(tea.String("/kit/debug/ping"), tea.String("HTTPS"), tea.String("POST"), nil, body, runtime)
	fmt.Println(err)
	fmt.Println(resp)
}
```
## 问题

[提交 Issue](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk/issues/new)，不符合指南的问题可能会立即关闭。


## 相关

* [最新源码](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk)

## 许可证

[Apache-2.0](http://www.apache.org/licenses/LICENSE-2.0)

Copyright (c) 2009-present, Alibaba Cloud All rights reserved.
