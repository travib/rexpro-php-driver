
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
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response_Error) {

	ZEPHIR_REGISTER_CLASS_EX(Rexpro\\Message\\Body\\Response, Error, rexpro, message_body_response_error, rexpro_message_body_response_ce, rexpro_message_body_response_error_method_entry, 0);

	zend_declare_property_null(rexpro_message_body_response_error_ce, SL("errorMessage"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_body_response_error_ce, SL("meta_attributes"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message_Body_Response_Error, getErrorMessage) {


	RETURN_MEMBER(this_ptr, "errorMessage");

}

PHP_METHOD(Rexpro_Message_Body_Response_Error, setErrorMessage) {

	zval *errorMessage;

	zephir_fetch_params(0, 1, 0, &errorMessage);



	zephir_update_property_this(this_ptr, SL("errorMessage"), errorMessage TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body_Response_Error, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "geterrormessage", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&message, SL("error_message"), &_3, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(message);

}

PHP_METHOD(Rexpro_Message_Body_Response_Error, hydrate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw);



	zephir_array_fetch_long(&_0, raw, 0, PH_NOISY | PH_READONLY, "rexpro/message/body/response/error.zep", 44 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsession", NULL, _0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, raw, 1, PH_NOISY | PH_READONLY, "rexpro/message/body/response/error.zep", 45 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequest", NULL, _1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, raw, 2, PH_NOISY | PH_READONLY, "rexpro/message/body/response/error.zep", 46 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmeta", NULL, _2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, raw, 3, PH_NOISY | PH_READONLY, "rexpro/message/body/response/error.zep", 47 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seterrormessage", NULL, _3);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Rexpro_Message_Body_Response_Error, getMetaAttributes) {


	RETURN_MEMBER(this_ptr, "meta_attributes");

}

PHP_METHOD(Rexpro_Message_Body_Response_Error, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *raw = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &raw);

	if (!raw) {
		ZEPHIR_CPY_WRT(raw, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(raw);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "flag", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("meta_attributes"), _0 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(raw))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "hydrate", NULL, raw);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

