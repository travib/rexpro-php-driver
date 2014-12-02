/* -*- Mode: C; tab-width: 4 -*- */
/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2009 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Travis Black <travisb@vrazzle.com>                           |
  +----------------------------------------------------------------------+
*/
namespace Rexpro\Message\Body\Response;

class Session extends \Rexpro\Message\Body\Response
{
    private languages{
        get, set
    };

    public function toArray()
    {
        var message;

        let message              = [];
        let message["session"]   = this->getSession();
        let message["request"]   = this->getRequest();
        let message["meta"]      = this->getMeta();
        let message["languages"] = this->getLanguages();

        return message;
    }

    protected function hydrate(raw)
    {
        this->setSession(raw[0]);
        this->setRequest(raw[1]);
        this->setMeta(raw[2]);
        this->setLanguages(raw[3]);

        return this;
    }

    protected function getMetaAttributes()
    {
        return [];
    }
}