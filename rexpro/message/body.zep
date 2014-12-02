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
namespace Rexpro\Message;

abstract class Body
{
    protected session {
        set, get
    };
    protected request {
        set, get
    };
    protected meta {
        get
    };

    public function setMeta(array meta)
    {
        var invalid_keys;

        let invalid_keys = [];
        var attribute;
        var value;

        for attribute, value in meta {
            if (!in_array(attribute, this->getMetaAttributes())) {
                let invalid_keys[] = attribute;
            }
        }

        if (count(invalid_keys)) {
            throw new \InvalidArgumentException(
                sprintf("%s doesn\'t accept the meta data %s",
                get_called_class(),
                implode(", ", invalid_keys)
            ));
        }

        let this->meta = meta;

        return this;
    }

    abstract protected function getMetaAttributes();
}
