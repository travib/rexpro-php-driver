
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


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
ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Rexpro\\Message\\Body, Request, rexpro, message_body_request, rexpro_message_body_ce, rexpro_message_body_request_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_string(rexpro_message_body_request_ce, SL("default_uuid"), "00000000-0000-0000-0000-000000000000", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message_Body_Request, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("default_uuid"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsession", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "createuuid", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequest", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Rexpro_Message_Body_Request, createUuid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_12 = NULL;
	zval _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, _11;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0xffff);
	ZEPHIR_CALL_FUNCTION(&_2, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0xffff);
	ZEPHIR_CALL_FUNCTION(&_4, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0xffff);
	ZEPHIR_CALL_FUNCTION(&_5, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0x0fff);
	ZEPHIR_CALL_FUNCTION(&_6, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0x3fff);
	ZEPHIR_CALL_FUNCTION(&_7, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0xffff);
	ZEPHIR_CALL_FUNCTION(&_8, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0xffff);
	ZEPHIR_CALL_FUNCTION(&_9, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0xffff);
	ZEPHIR_CALL_FUNCTION(&_10, "mt_rand", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "%04x%04x-%04x-%04x-%04x-%04x%04x%04x", 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, ((int) (zephir_get_numberval(_6)) | 0x4000));
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, ((int) (zephir_get_numberval(_7)) | 0x8000));
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_12, &_0, _2, _4, _5, &_1, &_11, _8, _9, _10);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Rexpro_Message_Body_Request, toArray) {

}

