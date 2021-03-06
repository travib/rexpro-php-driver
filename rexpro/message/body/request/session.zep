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
namespace Rexpro\Message\Body\Request;


class Session extends \Rexpro\Message\Body\Request
{
    private username {
        set, get
    };
    private password {
        set, get
    };

    private meta_attributes = [
        "killSession",
        "graphName",
        "graphObjName"
    ];

    public function __construct() {
        parent::__construct();
    }

    public function toArray()
    {
        var meta;
        let meta = this->getMeta();

        var message;

        let message = [
            this->getSession(),
            this->getRequest(),
            ((is_array(meta) && !empty(meta)) ? meta : new \stdClass),
            this->getUsername(),
            this->getPassword()
        ];

        return message;
    }

    protected function getMetaAttributes()
    {
        return this->meta_attributes;
    }
}