English | [简体中文](README-CN.md)

![](https://aliyunsdk-pages.alicdn.com/icons/AlibabaCloud.svg)

## Alibaba Cloud IotApiGateway SDK Library for Go

## Installation

```bash
go get github.com/alibabacloud-go/iot-api-gateway
```

## Demo

```go
package main

import (
	"fmt"

	iot "github.com/alibabacloud-go/iot-api-gateway/client"
	util "github.com/alibabacloud-go/tea-utils/service"
	"github.com/alibabacloud-go/tea/tea"
)

func main() {
    //Step1: 初始化 client
	config := new(iot.Config).
		SetAppKey("IOT_APP_KEY").
		SetAppSecret("IOT_APP_SECRET").
		SetDomain("api.link.aliyun.com")

	client, err := iot.NewClient(config)
	if err != nil {
		panic(err)
	}

    //Step2: 构建请求
	params := map[string]interface{}{
		"input": "gotest",
	}
	req := new(iot.CommonParams).
		SetApiVer("1.0.0")

	body := new(iot.IoTApiRequest).
		SetParams(params).
		SetRequest(req)

	runtime := new(util.RuntimeOptions)
    //Step3: 发送请求
	resp, err := client.DoRequest(tea.String("/kit/debug/ping"), tea.String("HTTPS"), tea.String("POST"), nil, body, runtime)
	fmt.Println(err)
	fmt.Println(resp)
}
```

## Issues

[Opening an Issue](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk/issues/new), Issues not conforming to the guidelines may be closed immediately.

## References

* [Latest Release](https://github.com/aliyun/alibabacloud-iot-api-gateway-sdk)

## License

[Apache-2.0](http://www.apache.org/licenses/LICENSE-2.0)

Copyright (c) 2009-present, Alibaba Cloud All rights reserved.
