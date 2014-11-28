
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


ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Rexpro\\Message\\Body\\Response, Session, rexpro, message_body_response_session, rexpro_message_body_response_ce, rexpro_message_body_response_session_method_entry, 0);

	zend_declare_property_null(rexpro_message_body_response_session_ce, SL("languages"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message_Body_Response_Session, getLanguages) {


	RETURN_MEMBER(this_ptr, "languages");

}

PHP_METHOD(Rexpro_Message_Body_Response_Session, setLanguages) {

	zval *languages;

	zephir_fetch_params(0, 1, 0, &languages);



	zephir_update_property_this(this_ptr, SL("languages"), languages TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body_Response_Session, toArray) {

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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getlanguages", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&message, SL("languages"), &_3, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(message);

}

PHP_METHOD(Rexpro_Message_Body_Response_Session, hydrate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw);



	zephir_array_fetch_long(&_0, raw, 0, PH_NOISY | PH_READONLY, "rexpro/message/body/response/session.zep", 24 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsession", NULL, _0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, raw, 1, PH_NOISY | PH_READONLY, "rexpro/message/body/response/session.zep", 25 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrequest", NULL, _1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, raw, 2, PH_NOISY | PH_READONLY, "rexpro/message/body/response/session.zep", 26 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmeta", NULL, _2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, raw, 3, PH_NOISY | PH_READONLY, "rexpro/message/body/response/session.zep", 27 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlanguages", NULL, _3);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Rexpro_Message_Body_Response_Session, getMetaAttributes) {


	array_init(return_value);
	return;

}

