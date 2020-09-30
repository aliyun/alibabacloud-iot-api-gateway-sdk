/**
 * test
 */
// This file is auto-generated, don't edit it. Thanks.

using System;
using System.Collections.Generic;
using System.IO;

using Tea;

namespace AlibabaCloud.SDK.IotApiGateway.Models
{
    public class Config : TeaModel {
        [NameInMap("domain")]
        [Validation(Required=true)]
        public string Domain { get; set; }

        [NameInMap("protocol")]
        [Validation(Required=false)]
        public string Protocol { get; set; }

        [NameInMap("appKey")]
        [Validation(Required=true)]
        public string AppKey { get; set; }

        [NameInMap("appSecret")]
        [Validation(Required=true)]
        public string AppSecret { get; set; }

        [NameInMap("token")]
        [Validation(Required=false)]
        public string Token { get; set; }

        [NameInMap("regionId")]
        [Validation(Required=false)]
        public string RegionId { get; set; }

        [NameInMap("readTimeout")]
        [Validation(Required=false)]
        public int? ReadTimeout { get; set; }

        [NameInMap("connectTimeout")]
        [Validation(Required=false)]
        public int? ConnectTimeout { get; set; }

        [NameInMap("localAddr")]
        [Validation(Required=false)]
        public string LocalAddr { get; set; }

        [NameInMap("httpProxy")]
        [Validation(Required=false)]
        public string HttpProxy { get; set; }

        [NameInMap("httpsProxy")]
        [Validation(Required=false)]
        public string HttpsProxy { get; set; }

        [NameInMap("userAgent")]
        [Validation(Required=false)]
        public string UserAgent { get; set; }

        [NameInMap("noProxy")]
        [Validation(Required=false)]
        public string NoProxy { get; set; }

        [NameInMap("maxIdleConns")]
        [Validation(Required=false)]
        public int? MaxIdleConns { get; set; }

    }

}
