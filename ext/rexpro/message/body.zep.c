
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Rexpro_Message_Body) {

	ZEPHIR_REGISTER_CLASS(Rexpro\\Message, Body, rexpro, message_body, rexpro_message_body_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(rexpro_message_body_ce, SL("session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(rexpro_message_body_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(rexpro_message_body_ce, SL("meta"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message_Body, setSession) {

	zval *session;

	zephir_fetch_params(0, 1, 0, &session);



	zephir_update_property_this(this_ptr, SL("session"), session TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body, getSession) {


	RETURN_MEMBER(this_ptr, "session");

}

PHP_METHOD(Rexpro_Message_Body, setRequest) {

	zval *request;

	zephir_fetch_params(0, 1, 0, &request);



	zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message_Body, getRequest) {


	RETURN_MEMBER(this_ptr, "request");

}

PHP_METHOD(Rexpro_Message_Body, getMeta) {


	RETURN_MEMBER(this_ptr, "meta");

}

PHP_METHOD(Rexpro_Message_Body, setMeta) {

	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *meta_param = NULL, *invalid_keys, *attribute = NULL, *value = NULL, **_2, *_3 = NULL, *_5, *_6, *_7, _8;
	zval *meta = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &meta_param);

	zephir_get_arrval(meta, meta_param);


	ZEPHIR_INIT_VAR(invalid_keys);
	array_init(invalid_keys);
	zephir_is_iterable(meta, &_1, &_0, 0, 0, "rexpro/message/body.zep", 29);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(attribute, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmetaattributes", &_4);
		zephir_check_call_status();
		if (!zephir_fast_in_array(attribute, _3 TSRMLS_CC)) {
			zephir_array_append(&invalid_keys, attribute, PH_SEPARATE, "rexpro/message/body.zep", 25);
		}
	}
	if (zephir_fast_count_int(invalid_keys TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5);
		object_init_ex(_5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_6);
		zephir_get_called_class(_6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		zephir_fast_join_str(_7, SL(", "), invalid_keys TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_STRING(&_8, "%s doesn\\'t accept the meta data %s", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_9, &_8, _6, _7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "rexpro/message/body.zep", 34 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("meta"), meta TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Rexpro_Message_Body, getMetaAttributes) {

}

