
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Rexpro_Message) {

	ZEPHIR_REGISTER_CLASS(Rexpro, Message, rexpro, message, rexpro_message_method_entry, 0);

	zend_declare_property_long(rexpro_message_ce, SL("protocolVersion"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(rexpro_message_ce, SL("serializerType"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_ce, SL("reserved"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_ce, SL("message_type"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_ce, SL("messageSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_ce, SL("messageBody"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_ce, SL("messageBodySerialized"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_ce, SL("message_types"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_message_ce, SL("serializer_types"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_long(rexpro_message_ce, SL("SERIALIZER_TYPE_JSON"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(rexpro_message_ce, SL("SERIALIZER_TYPE_MSGPACK"), 0 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message, setProtocolVersion) {

	zval *protocolVersion;

	zephir_fetch_params(0, 1, 0, &protocolVersion);



	zephir_update_property_this(this_ptr, SL("protocolVersion"), protocolVersion TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message, getProtocolVersion) {


	RETURN_MEMBER(this_ptr, "protocolVersion");

}

PHP_METHOD(Rexpro_Message, getSerializerType) {


	RETURN_MEMBER(this_ptr, "serializerType");

}

PHP_METHOD(Rexpro_Message, setReserved) {

	zval *reserved;

	zephir_fetch_params(0, 1, 0, &reserved);



	zephir_update_property_this(this_ptr, SL("reserved"), reserved TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message, getReserved) {


	RETURN_MEMBER(this_ptr, "reserved");

}

PHP_METHOD(Rexpro_Message, setMessageSize) {

	zval *messageSize;

	zephir_fetch_params(0, 1, 0, &messageSize);



	zephir_update_property_this(this_ptr, SL("messageSize"), messageSize TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message, setMessageBody) {

	zval *messageBody;

	zephir_fetch_params(0, 1, 0, &messageBody);



	zephir_update_property_this(this_ptr, SL("messageBody"), messageBody TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message, setMessageBodySerialized) {

	zval *messageBodySerialized;

	zephir_fetch_params(0, 1, 0, &messageBodySerialized);



	zephir_update_property_this(this_ptr, SL("messageBodySerialized"), messageBodySerialized TSRMLS_CC);

}

PHP_METHOD(Rexpro_Message, setSerializerType) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	zephir_nts_static zend_class_entry *_4 = NULL;
	zval *type_param = NULL, *_0, _1, *_2, *_3, _5, _6, *_7 = NULL;
	int type, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	type = zephir_get_intval(type_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("serializer_types"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, type);
	if (zephir_fast_in_array(&_1, _0 TSRMLS_CC)) {
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, type);
		zephir_update_property_this(this_ptr, SL("serializerType"), _2 TSRMLS_CC);
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(_3);
	if (!_4) {
		_4 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_3, _4);
	if (zephir_has_constructor(_3 TSRMLS_CC)) {
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "%s is not a valid type", 0);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, type);
		ZEPHIR_CALL_FUNCTION(&_7, "sprintf", &_8, &_5, &_6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _7);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_3, "rexpro/message.zep", 47 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, getMessageSize) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messageSize"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		RETURN_MM_MEMBER(this_ptr, "messageSize");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
	if (!ZEPHIR_IS_EMPTY(_1)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "ISO-8859-1", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "mb_strlen", NULL, _3, &_4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("messageSize"), _5 TSRMLS_CC);
	} else if (!ZEPHIR_IS_EMPTY(_2)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "serializebody", &_6);
		zephir_check_call_status();
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "ISO-8859-1", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "mb_strlen", NULL, _3, &_4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("messageSize"), _5 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "messageSize");

}

PHP_METHOD(Rexpro_Message, setMessageType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zephir_nts_static zend_class_entry *_2 = NULL;
	zval *type, *_0, *_1, _3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("message_types"), PH_NOISY_CC);
	if (zephir_array_key_exists(_0, type TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("message_type"), type TSRMLS_CC);
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(_1);
	if (!_2) {
		_2 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_1, _2);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "%s is not a valid type", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_5, &_3, type);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _4);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_1, "rexpro/message.zep", 77 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, getMessageType) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("message_type"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_LONG) {
		RETURN_MM_MEMBER(this_ptr, "message_type");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
	if (!ZEPHIR_IS_EMPTY(_1)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmessagekeyfromtype", &_4, _3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("message_type"), _2 TSRMLS_CC);
		RETURN_MM_MEMBER(this_ptr, "message_type");
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Rexpro_Message, getMessageBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
	if (!ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_MEMBER(this_ptr, "messageBody");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_1))) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "unpack", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("messageBody"), _2 TSRMLS_CC);
		RETURN_MM_MEMBER(this_ptr, "messageBody");
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Rexpro_Message, getMessageBodySerialized) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		RETURN_MM_MEMBER(this_ptr, "messageBodySerialized");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_1))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "serializebody", &_2);
		zephir_check_call_status();
		RETURN_MM_MEMBER(this_ptr, "messageBodySerialized");
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Rexpro_Message, pack) {

	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *protocol_version = NULL, *serializer_type = NULL, *message_type = NULL, *pack = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, _8, *message_size = NULL, *message_body_serialized = NULL, *_10 = NULL, *_12;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("messageSize"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("messageBodySerialized"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("message_type"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&protocol_version, this_ptr, "getprotocolversion", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&serializer_type, this_ptr, "getserializertype", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&message_type, this_ptr, "getmessagetype", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("reserved"), PH_NOISY_CC);
	zephir_array_fetch_long(&_1, _0, 0, PH_NOISY | PH_READONLY, "rexpro/message.zep", 154 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("reserved"), PH_NOISY_CC);
	zephir_array_fetch_long(&_3, _2, 1, PH_NOISY | PH_READONLY, "rexpro/message.zep", 155 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("reserved"), PH_NOISY_CC);
	zephir_array_fetch_long(&_5, _4, 2, PH_NOISY | PH_READONLY, "rexpro/message.zep", 156 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("reserved"), PH_NOISY_CC);
	zephir_array_fetch_long(&_7, _6, 3, PH_NOISY | PH_READONLY, "rexpro/message.zep", 157 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "C*", 0);
	ZEPHIR_CALL_FUNCTION(&pack, "pack", &_9, &_8, protocol_version, serializer_type, _1, _3, _5, _7, message_type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&message_size, this_ptr, "getmessagesize", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&message_body_serialized, this_ptr, "getmessagebodyserialized", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "convertintto32bitbinarystring", &_11, message_size);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_VV(_12, _10, message_body_serialized);
	zephir_concat_self(&pack, _12 TSRMLS_CC);
	RETURN_CCTOR(pack);

}

PHP_METHOD(Rexpro_Message, unpack) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_2 = NULL;
	zval *_0, *_1, *_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_INIT_VAR(_1);
		if (!_2) {
			_2 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_1, _2);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "There is currently no serialized message body. Nothing to unpack.", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_1, "rexpro/message.zep", 175 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "deserializebody", &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getmessagetypefromkey", &_7, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("messageBody"), _4 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("messageBodySerialized"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Rexpro_Message, getMessageTypeFromKey) {

	zephir_nts_static zend_class_entry *_6 = NULL;
	zend_class_entry *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw = NULL, *_0 = NULL, *message_type, *_1, *_2 = NULL, *_3 = NULL, *_5, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &raw);

	if (!raw) {
		raw = ZEPHIR_GLOBAL(global_false);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessagetype", NULL);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("message_types"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(message_type);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getmessagetype", NULL);
		zephir_check_call_status();
		zephir_array_fetch(&message_type, _1, _2, PH_NOISY, "rexpro/message.zep", 188 TSRMLS_CC);
		zephir_fetch_safe_class(_3, message_type);
		_4 = zend_fetch_class(Z_STRVAL_P(_3), Z_STRLEN_P(_3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _4);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, raw);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_5);
	if (!_6) {
		_6 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_5, _6);
	if (zephir_has_constructor(_5 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "The given MessageType id doesn\"t map to a message type class.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_5, "rexpro/message.zep", 192 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, getMessageKeyFromType) {

	zephir_nts_static zend_class_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *body, *key = NULL, *_0, *_1, *_3, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	if (!(zephir_is_instance_of(body, SL("Rexpro\\Message\\Body") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'body' must be an instance of 'Rexpro\\Message\\Body'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, body, 0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("message_types"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&key, "array_search", &_2, _0, _1);
	zephir_check_call_status();
	if (zephir_is_true(key)) {
		RETURN_CCTOR(key);
	}
	ZEPHIR_INIT_VAR(_3);
	if (!_4) {
		_4 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_3, _4);
	if (zephir_has_constructor(_3 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "Message type not found for this instance of Message\\Body", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_3, "rexpro/message.zep", 204 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, serializeBody) {

	zephir_nts_static zend_class_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2, *_3 = NULL, _4, *_6;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("serializerType"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 1)) {
		ZEPHIR_INIT_VAR(_1);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3, _2, "toarray", NULL);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, 256);
		zephir_json_encode(_1, &(_1), _3, zephir_get_intval(&_4)  TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("messageBodySerialized"), _1 TSRMLS_CC);
		RETURN_THIS();
	}
	ZEPHIR_INIT_NVAR(_1);
	if (!_5) {
		_5 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_1, _5);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "Message::serializeBody() doesn't recognize the given serializer type.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_1, "rexpro/message.zep", 219 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, deserializeBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_2 = NULL, *_7 = NULL;
	zval *_0, *_1 = NULL, *_3 = NULL, *_4, *_5, _6;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_INIT_VAR(_1);
		if (!_2) {
			_2 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_1, _2);
		if (zephir_has_constructor(_1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "Message::deserializeBody requires Message::_message_body_serialized to be set.", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
			zephir_check_temp_parameter(_3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_1, "rexpro/message.zep", 226 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("serializerType"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_4, 1)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, 256);
		zephir_json_decode(return_value, &(return_value), _5, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	if (!_7) {
		_7 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_1, _7);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Message::deserializeBody doesn't recognize the given serializer type.", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_1, "rexpro/message.zep", 233 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, convertIntTo32BitBinaryString) {

	zend_bool _8;
	zephir_nts_static zend_class_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _9, _10, _14;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL, *_12 = NULL, *_13 = NULL;
	zval *raw_int = NULL, *_0 = NULL, *_2, *_4, _5 = zval_used_for_init, *_6 = NULL, *result, *i = NULL, _11 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw_int);

	ZEPHIR_SEPARATE_PARAM(raw_int);


	ZEPHIR_CALL_FUNCTION(&_0, "is_int", &_1, raw_int);
	zephir_check_call_status();
	if (!zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_2);
		if (!_3) {
			_3 = zend_fetch_class(SL("Rexpro\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_2, _3);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_4);
			zephir_gettype(_4, raw_int TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "Message::convertIntTo32BitBinaryString requires an int. %s given.", 0);
			ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, &_5, _4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _6);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_2, "rexpro/message.zep", 239 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(result);
	array_init(result);
	_10 = 3;
	_9 = 0;
	_8 = 0;
	if (_9 <= _10) {
		while (1) {
			if (_8) {
				_9++;
				if (!(_9 <= _10)) {
					break;
				}
			} else {
				_8 = 1;
			}
			ZEPHIR_INIT_NVAR(i);
			ZVAL_LONG(i, _9);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "C*", 0);
			ZEPHIR_SINIT_NVAR(_11);
			ZVAL_LONG(&_11, ((int) (zephir_get_numberval(raw_int)) & 0xff));
			ZEPHIR_CALL_FUNCTION(&_6, "pack", &_12, &_5, &_11);
			zephir_check_call_status();
			Z_SET_ISREF_P(result);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_13, result, _6);
			Z_UNSET_ISREF_P(result);
			zephir_check_call_status();
			_14 = ((int) (zephir_get_numberval(raw_int)) >> 8);
			ZEPHIR_INIT_NVAR(raw_int);
			ZVAL_LONG(raw_int, _14);
		}
	}
	zephir_fast_join_str(return_value, SL(""), result TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Rexpro_Message, __construct) {

	zval *_1 = NULL;
	zval *_0, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("serializer_types"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 7);
	add_index_stringl(_2, 1, SL("Converge\Dolittle\Message\Body\Request\Session"), 1);
	add_index_stringl(_2, 2, SL("Converge\Dolittle\Message\Body\Response\Session"), 1);
	add_index_stringl(_2, 3, SL("Converge\Dolittle\Message\Body\Request\Script"), 1);
	add_index_stringl(_2, 5, SL("Converge\Dolittle\Message\Body\Response\Script"), 1);
	add_index_stringl(_2, 0, SL("Converge\Dolittle\Message\Body\Response\Error"), 1);
	zephir_update_property_this(this_ptr, SL("message_types"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 7);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_3, _1);
	zephir_update_property_this(this_ptr, SL("reserved"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

