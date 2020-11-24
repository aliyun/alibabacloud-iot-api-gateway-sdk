# -*- coding: utf-8 -*-
# This file is auto-generated, don't edit it. Thanks.
from Tea.model import TeaModel
try:
    from typing import Dict, Any
except ImportError:
    pass


class Config(TeaModel):
    def __init__(self, domain=None, protocol=None, app_key=None, app_secret=None, token=None, region_id=None,
                 read_timeout=None, connect_timeout=None, local_addr=None, http_proxy=None, https_proxy=None, user_agent=None,
                 no_proxy=None, max_idle_conns=None):
        self.domain = domain            # type: str
        self.protocol = protocol        # type: str
        self.app_key = app_key          # type: str
        self.app_secret = app_secret    # type: str
        self.token = token              # type: str
        self.region_id = region_id      # type: str
        self.read_timeout = read_timeout  # type: int
        self.connect_timeout = connect_timeout  # type: int
        self.local_addr = local_addr    # type: str
        self.http_proxy = http_proxy    # type: str
        self.https_proxy = https_proxy  # type: str
        self.user_agent = user_agent    # type: str
        self.no_proxy = no_proxy        # type: str
        self.max_idle_conns = max_idle_conns  # type: int

    def validate(self):
        self.validate_required(self.domain, 'domain')
        self.validate_required(self.app_key, 'app_key')
        self.validate_required(self.app_secret, 'app_secret')

    def to_map(self):
        result = {}
        if self.domain is not None:
            result['domain'] = self.domain
        if self.protocol is not None:
            result['protocol'] = self.protocol
        if self.app_key is not None:
            result['appKey'] = self.app_key
        if self.app_secret is not None:
            result['appSecret'] = self.app_secret
        if self.token is not None:
            result['token'] = self.token
        if self.region_id is not None:
            result['regionId'] = self.region_id
        if self.read_timeout is not None:
            result['readTimeout'] = self.read_timeout
        if self.connect_timeout is not None:
            result['connectTimeout'] = self.connect_timeout
        if self.local_addr is not None:
            result['localAddr'] = self.local_addr
        if self.http_proxy is not None:
            result['httpProxy'] = self.http_proxy
        if self.https_proxy is not None:
            result['httpsProxy'] = self.https_proxy
        if self.user_agent is not None:
            result['userAgent'] = self.user_agent
        if self.no_proxy is not None:
            result['noProxy'] = self.no_proxy
        if self.max_idle_conns is not None:
            result['maxIdleConns'] = self.max_idle_conns
        return result

    def from_map(self, map={}):
        if map.get('domain') is not None:
            self.domain = map.get('domain')
        if map.get('protocol') is not None:
            self.protocol = map.get('protocol')
        if map.get('appKey') is not None:
            self.app_key = map.get('appKey')
        if map.get('appSecret') is not None:
            self.app_secret = map.get('appSecret')
        if map.get('token') is not None:
            self.token = map.get('token')
        if map.get('regionId') is not None:
            self.region_id = map.get('regionId')
        if map.get('readTimeout') is not None:
            self.read_timeout = map.get('readTimeout')
        if map.get('connectTimeout') is not None:
            self.connect_timeout = map.get('connectTimeout')
        if map.get('localAddr') is not None:
            self.local_addr = map.get('localAddr')
        if map.get('httpProxy') is not None:
            self.http_proxy = map.get('httpProxy')
        if map.get('httpsProxy') is not None:
            self.https_proxy = map.get('httpsProxy')
        if map.get('userAgent') is not None:
            self.user_agent = map.get('userAgent')
        if map.get('noProxy') is not None:
            self.no_proxy = map.get('noProxy')
        if map.get('maxIdleConns') is not None:
            self.max_idle_conns = map.get('maxIdleConns')
        return self


class CommonParams(TeaModel):
    def __init__(self, api_ver=None, iot_token=None, cloud_token=None, language=None, locale=None):
        # API版本
        self.api_ver = api_ver          # type: str
        # 登录用户的token(客户端)
        self.iot_token = iot_token      # type: str
        # 云端资源token（云端)
        self.cloud_token = cloud_token  # type: str
        # 国际化扩展，语言
        self.language = language        # type: str
        # 国际化扩展，地理位置、ip
        self.locale = locale            # type: str

    def validate(self):
        self.validate_required(self.api_ver, 'api_ver')

    def to_map(self):
        result = {}
        if self.api_ver is not None:
            result['apiVer'] = self.api_ver
        if self.iot_token is not None:
            result['iotToken'] = self.iot_token
        if self.cloud_token is not None:
            result['cloudToken'] = self.cloud_token
        if self.language is not None:
            result['language'] = self.language
        if self.locale is not None:
            result['locale'] = self.locale
        return result

    def from_map(self, map={}):
        if map.get('apiVer') is not None:
            self.api_ver = map.get('apiVer')
        if map.get('iotToken') is not None:
            self.iot_token = map.get('iotToken')
        if map.get('cloudToken') is not None:
            self.cloud_token = map.get('cloudToken')
        if map.get('language') is not None:
            self.language = map.get('language')
        if map.get('locale') is not None:
            self.locale = map.get('locale')
        return self


class IoTApiRequest(TeaModel):
    def __init__(self, id=None, version=None, params=None, request=None):
        # 一次请求的标示，用于请求跟踪问题排查
        self.id = id                    # type: str
        # 协议版本
        self.version = version          # type: str
        # JSON对象，访问指定api的业务参数
        self.params = params            # type: Dict[str, Any]
        # JSON对象，与业务无关的通用参数
        self.request = request          # type: CommonParams

    def validate(self):
        self.validate_required(self.request, 'request')
        if self.request:
            self.request.validate()

    def to_map(self):
        result = {}
        if self.id is not None:
            result['id'] = self.id
        if self.version is not None:
            result['version'] = self.version
        if self.params is not None:
            result['params'] = self.params
        if self.request is not None:
            result['request'] = self.request.to_map()
        return result

    def from_map(self, map={}):
        if map.get('id') is not None:
            self.id = map.get('id')
        if map.get('version') is not None:
            self.version = map.get('version')
        if map.get('params') is not None:
            self.params = map.get('params')
        if map.get('request') is not None:
            temp_model = CommonParams()
            self.request = temp_model.from_map(map['request'])
        return self
