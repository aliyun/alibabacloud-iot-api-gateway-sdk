// This file is auto-generated, don't edit it. Thanks.

using System;
using System.Collections.Generic;
using System.IO;

using Tea;

namespace AlibabaCloud.SDK.IotApiGateway.Models
{
    public class CommonParams : TeaModel {
        /// <summary>
        /// API版本
        /// </summary>
        [NameInMap("apiVer")]
        [Validation(Required=true)]
        public string ApiVer { get; set; }

        /// <summary>
        /// 登录用户的token(客户端)
        /// </summary>
        [NameInMap("iotToken")]
        [Validation(Required=false)]
        public string IotToken { get; set; }

        /// <summary>
        /// 云端资源token（云端)
        /// </summary>
        [NameInMap("cloudToken")]
        [Validation(Required=false)]
        public string CloudToken { get; set; }

        /// <summary>
        /// 国际化扩展，语言
        /// </summary>
        [NameInMap("language")]
        [Validation(Required=false)]
        public string Language { get; set; }

        /// <summary>
        /// 国际化扩展，地理位置、ip
        /// </summary>
        [NameInMap("locale")]
        [Validation(Required=false)]
        public string Locale { get; set; }

    }

}
