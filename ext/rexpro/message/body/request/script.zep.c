
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Request_Script) {

	ZEPHIR_REGISTER_CLASS_EX(Rexpro\\Message\\Body\\Request, Script, rexpro, message_body_request_script, rexpro_message_body_request_ce, rexpro_message_body_request_script_method_entry, 0);

	zend_declare_property_string(rexpro_message_body_request_script_ce, SL("languageName"), "groovy", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_body_request_script_ce, SL("script"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_body_request_script_ce, SL("bindings"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_body_request_script_ce, SL("meta_attributes"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, setLanguageName) {

	zval *languageName;

	zephir_fetch_params(0, 1, 0, &languageName);



	zephir_update_property_this(this_ptr, SL("languageName"), languageName TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, getLanguageName) {


	RETURN_MEMBER(this_ptr, "languageName");

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, setScript) {

	zval *script;

	zephir_fetch_params(0, 1, 0, &script);



	zephir_update_property_this(this_ptr, SL("script"), script TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, getScript) {


	RETURN_MEMBER(this_ptr, "script");

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, setBindings) {

	zval *bindings;

	zephir_fetch_params(0, 1, 0, &bindings);



	zephir_update_property_this(this_ptr, SL("bindings"), bindings TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, getBindings) {


	RETURN_MEMBER(this_ptr, "bindings");

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 11);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "inSession", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "isolate", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "transaction", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "graphName", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "graphObjName", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "console", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("meta_attributes"), _0 TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, rexpro_message_body_request_script_ce, this_ptr, "__construct", &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, toArray) {

	zend_bool _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *bindings = NULL, *meta = NULL, *message, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&bindings, this_ptr, "getbindings", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&meta, this_ptr, "getmeta", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(message);
	array_init_size(message, 11);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsession", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(message, _0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getrequest", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(message, _0);
	ZEPHIR_INIT_VAR(_1);
	_2 = Z_TYPE_P(meta) == IS_ARRAY;
	if (_2) {
		_2 = !ZEPHIR_IS_EMPTY(meta);
	}
	if (_2) {
		ZEPHIR_CPY_WRT(_1, meta);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		object_init(_1);
	}
	zephir_array_fast_append(message, _1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlanguagename", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(message, _0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscript", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(message, _0);
	ZEPHIR_INIT_LNVAR(_1);
	_3 = Z_TYPE_P(bindings) == IS_ARRAY;
	if (_3) {
		_3 = !ZEPHIR_IS_EMPTY(bindings);
	}
	if (_3) {
		ZEPHIR_CPY_WRT(_1, bindings);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		object_init(_1);
	}
	zephir_array_fast_append(message, _1);
	RETURN_CCTOR(message);

}

PHP_METHOD(Rexpro_Message_Body_Request_Script, getMetaAttributes) {


	RETURN_MEMBER(this_ptr, "meta_attributes");

}

