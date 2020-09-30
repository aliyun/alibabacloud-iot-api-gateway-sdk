// This file is auto-generated, don't edit it. Thanks.

using System;
using System.Collections.Generic;
using System.IO;

using Tea;

namespace AlibabaCloud.SDK.IotApiGateway.Models
{
    public class IoTApiRequest : TeaModel {
        /// <summary>
        /// 一次请求的标示，用于请求跟踪问题排查
        /// </summary>
        [NameInMap("id")]
        [Validation(Required=false)]
        public string Id { get; set; }

        /// <summary>
        /// 协议版本
        /// </summary>
        [NameInMap("version")]
        [Validation(Required=false)]
        public string Version { get; set; }

        /// <summary>
        /// JSON对象，访问指定api的业务参数
        /// </summary>
        [NameInMap("params")]
        [Validation(Required=false)]
        public Dictionary<string, object> Params { get; set; }

        /// <summary>
        /// JSON对象，与业务无关的通用参数
        /// </summary>
        [NameInMap("request")]
        [Validation(Required=true)]
        public CommonParams Request { get; set; }

    }

}
