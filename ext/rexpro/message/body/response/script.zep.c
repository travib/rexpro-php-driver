
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
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response_Script) {

	ZEPHIR_REGISTER_CLASS_EX(Rexpro\\Message\\Body\\Response, Script, rexpro, message_body_response_script, rexpro_message_body_response_ce, rexpro_message_body_response_script_method_entry, 0);

	zend_declare_property_null(rexpro_message_body_response_script_ce, SL("results"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_body_response_script_ce, SL("bindings"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message_Body_Response_Script, getResults) {


	RETURN_MEMBER(this_ptr, "results");

}

PHP_METHOD(Rexpro_Message_Body_Response_Script, setResults) {

	zval *results;

	zephir_fetch_params(0, 1, 0, &results);



	zephir_update_property_this(this_ptr, SL("results"), results TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body_Response_Script, getBindings) {


	RETURN_MEMBER(this_ptr, "bindings");

}

PHP_METHOD(Rexpro_Message_Body_Response_Script, setBindings) {

	zval *bindings;

	zephir_fetch_params(0, 1, 0, &bindings);



	zephir_update_property_this(this_ptr, SL("bindings"), bindings TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body_Response_Script, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(message);
	array_init(message);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsession", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&message, SL("session"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getrequest", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&message, SL("request"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmeta", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&message, SL("meta"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getresults", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&message, SL("results"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getbindings", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&message, SL("bindings"), &_4, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(message);

}

PHP_METHOD(Rexpro_Message_Body_Response_Script, hydrate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw, *_0, *_1, *_2, *_3 = NULL, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw);



	zephir_array_fetch_long(&_0, raw, 0, PH_NOISY | PH_READONLY, "rexpro/message/body/response/script.zep", 28 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsession", NULL, _0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, raw, 1, PH_NOISY | PH_READONLY, "rexpro/message/body/response/script.zep", 29 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequest", NULL, _1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, raw, 2, PH_NOISY | PH_READONLY, "rexpro/message/body/response/script.zep", 30 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmeta", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_array_fetch_long(&_4, raw, 3, PH_NOISY | PH_READONLY, "rexpro/message/body/response/script.zep", 31 TSRMLS_CC);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(_3);
		zephir_array_fetch_long(&_3, raw, 3, PH_NOISY, "rexpro/message/body/response/script.zep", 31 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_3);
		array_init_size(_3, 2);
		ZEPHIR_OBS_VAR(_5);
		zephir_array_fetch_long(&_5, raw, 3, PH_NOISY, "rexpro/message/body/response/script.zep", 31 TSRMLS_CC);
		zephir_array_fast_append(_3, _5);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setresults", NULL, _3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_6, raw, 4, PH_NOISY | PH_READONLY, "rexpro/message/body/response/script.zep", 32 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setbindings", NULL, _6);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Rexpro_Message_Body_Response_Script, getMetaAttributes) {


	array_init(return_value);
	return;

}

