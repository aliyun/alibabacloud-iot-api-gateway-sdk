package client

import (
	"os"
	"testing"

	util "github.com/alibabacloud-go/tea-utils/service"
	"github.com/alibabacloud-go/tea/tea"
	"github.com/alibabacloud-go/tea/utils"
)

func Test_Api(t *testing.T) {
	config := &Config{
		AppKey:    tea.String(os.Getenv("IOT_APP_KEY")),
		AppSecret: tea.String(os.Getenv("IOT_APP_SECRET")),
		Domain:    tea.String("api.link.aliyun.com"),
	}
	client, err := NewClient(config)
	utils.AssertNil(t, err)

	params := map[string]interface{}{
		"input": "test",
	}
	req := &CommonParams{
		ApiVer: tea.String("1.0.0"),
	}
	body := &IoTApiRequest{
		Params:  params,
		Request: req,
	}
	runtime := &util.RuntimeOptions{}
	resp, err := client.DoRequest(tea.String("/kit/debug/ping"), tea.String("HTTPS"), tea.String("POST"), nil, body, runtime)
	utils.AssertNil(t, err)

	obj, err := util.ReadAsJSON(resp.Body)
	utils.AssertNil(t, err)

	m := util.AssertAsMap(obj)
	utils.AssertContains(t, "test", m["data"].(string))
}
