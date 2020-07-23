<?php

// This file is auto-generated, don't edit it. Thanks.

namespace AlibabaCloud\SDK\IotApiGateway;

use AlibabaCloud\ApiGateway\Util\BaseClient;
use AlibabaCloud\SDK\IotApiGateway\Models\IoTApiRequest;
use AlibabaCloud\Tea\Exception\TeaError;
use AlibabaCloud\Tea\Exception\TeaUnableRetryError;
use AlibabaCloud\Tea\Request;
use AlibabaCloud\Tea\Tea;
use AlibabaCloud\Tea\Utils\Utils;
use AlibabaCloud\Tea\Utils\Utils\RuntimeOptions;
use Exception;

/**
 * test.
 */
class Client
{
    protected $_appKey;

    protected $_appSecret;

    protected $_protocol;

    protected $_readTimeout;

    protected $_connectTimeout;

    protected $_httpProxy;

    protected $_httpsProxy;

    protected $_noProxy;

    protected $_maxIdleConns;

    protected $_domain;

    public function __construct($config)
    {
        $this->_domain         = $config->domain;
        $this->_appKey         = $config->appKey;
        $this->_appSecret      = $config->appSecret;
        $this->_protocol       = $config->protocol;
        $this->_readTimeout    = $config->readTimeout;
        $this->_connectTimeout = $config->connectTimeout;
        $this->_httpProxy      = $config->httpProxy;
        $this->_httpsProxy     = $config->httpsProxy;
        $this->_noProxy        = $config->noProxy;
        $this->_maxIdleConns   = $config->maxIdleConns;
    }

    /**
     * Send request.
     *
     * @param string         $pathname the url path
     * @param string         $protocol http or https
     * @param string         $method   example GET
     * @param array          $header   request header
     * @param IoTApiRequest  $body     the object of IoTApiRequest
     * @param RuntimeOptions $runtime  which controls some details of call api, such as retry times
     *
     * @throws Exception
     * @throws TeaUnableRetryError
     */
    public function doRequest($pathname, $protocol, $method, $header, $body, $runtime)
    {
        $body->validate();
        $runtime->validate();
        $_runtime = [
            'timeouted'      => 'retry',
            'readTimeout'    => Utils::defaultNumber($runtime->readTimeout, $this->_readTimeout),
            'connectTimeout' => Utils::defaultNumber($runtime->connectTimeout, $this->_connectTimeout),
            'httpProxy'      => Utils::defaultString($runtime->httpProxy, $this->_httpProxy),
            'httpsProxy'     => Utils::defaultString($runtime->httpsProxy, $this->_httpsProxy),
            'noProxy'        => Utils::defaultString($runtime->noProxy, $this->_noProxy),
            'maxIdleConns'   => Utils::defaultNumber($runtime->maxIdleConns, $this->_maxIdleConns),
            'retry'          => [
                'retryable'   => $runtime->autoretry,
                'maxAttempts' => Utils::defaultNumber($runtime->maxAttempts, 3),
            ],
            'backoff' => [
                'policy' => Utils::defaultString($runtime->backoffPolicy, 'no'),
                'period' => Utils::defaultNumber($runtime->backoffPeriod, 1),
            ],
            'ignoreSSL' => $runtime->ignoreSSL,
        ];
        $_lastRequest   = null;
        $_lastException = null;
        $_now           = time();
        $_retryTimes    = 0;
        while (Tea::allowRetry($_runtime['retry'], $_retryTimes, $_now)) {
            if ($_retryTimes > 0) {
                $_backoffTime = Tea::getBackoffTime($_runtime['backoff'], $_retryTimes);
                if ($_backoffTime > 0) {
                    Tea::sleep($_backoffTime);
                }
            }
            $_retryTimes = $_retryTimes + 1;

            try {
                $_request           = new Request();
                $_request->protocol = Utils::defaultString($this->_protocol, $protocol);
                $_request->method   = Utils::defaultString($method, 'POST');
                $_request->pathname = $pathname;
                $_request->headers  = Tea::merge([
                    'host'                 => $this->_domain,
                    'date'                 => Utils::getDateUTCString(),
                    'x-ca-nonce'           => Utils::getNonce(),
                    'x-ca-key'             => $this->_appKey,
                    'x-ca-signaturemethod' => 'HmacSHA256',
                    'accept'               => 'application/json',
                ], $header);
                if (Utils::empty_($body->id)) {
                    $body->id = Utils::getNonce();
                }
                if (!Utils::isUnset($body)) {
                    $_request->headers['content-type'] = 'application/octet-stream';
                    $_request->headers['content-md5']  = BaseClient::getContentMD5(Utils::toJSONString($body));
                    $_request->body                    = Utils::toJSONString($body);
                }
                $_request->headers['x-ca-signature'] = BaseClient::getSignature($_request, $this->_appSecret);
                $_lastRequest                        = $_request;
                $_response                           = Tea::send($_request, $_runtime);

                return $_response;
            } catch (Exception $e) {
                if (!($e instanceof TeaError)) {
                    $e = new TeaError([], $e->getMessage(), $e->getCode(), $e);
                }
                if (Tea::isRetryable($e)) {
                    $_lastException = $e;

                    continue;
                }

                throw $e;
            }
        }

        throw new TeaUnableRetryError($_lastRequest, $_lastException);
    }
}
