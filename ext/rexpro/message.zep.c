
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

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	zval *type_param = NULL, *_0, _1, *_2, *_3, _4, _5, *_6 = NULL;
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
	object_init_ex(_3, rexpro_exception_ce);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "%s is not a valid type", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, type);
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_7, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _6);
	zephir_check_call_status();
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
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *type, *_0, *_1, _2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("message_types"), PH_NOISY_CC);
	if (zephir_array_key_exists(_0, type TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("message_type"), type TSRMLS_CC);
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, rexpro_exception_ce);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "%s is not a valid type", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", &_4, &_2, type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "rexpro/message.zep", 77 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, getMessageType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zval *_0, *_1 = NULL, *_3, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("message_type"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "is_int", &_2, _0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		RETURN_MM_MEMBER(this_ptr, "message_type");
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
	if (!ZEPHIR_IS_EMPTY(_3)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("messageBody"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getmessagekeyfromtype", &_6, _5);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("message_type"), _4 TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(rexpro_exception_ce, "There is currently no serialized message body. Nothing to unpack.", "rexpro/message.zep", 175);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "deserializebody", &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmessagetypefromkey", &_4, _2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("messageBody"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("messageBodySerialized"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Rexpro_Message, getMessageTypeFromKey) {

	zend_class_entry *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw = NULL, *_0 = NULL, *message_type, *_1, *_2 = NULL, *_3 = NULL;

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
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(rexpro_exception_ce, "The given MessageType id doesn\"t map to a message type class.", "rexpro/message.zep", 192);
	return;

}

PHP_METHOD(Rexpro_Message, getMessageKeyFromType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zval *body, *key = NULL, *class_name, *_0, *_1, *_3, _4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	if (!(zephir_instance_of_ev(body, rexpro_message_body_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'body' must be an instance of 'Rexpro\\Message\\Body'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(class_name);
	zephir_get_class(class_name, body, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, body, 0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("message_types"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&key, "array_search", &_2, _0, _1);
	zephir_check_call_status();
	if (zephir_is_true(key)) {
		RETURN_CCTOR(key);
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, rexpro_exception_ce);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "Message type not found for this instance of Message\\Body. %s", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, &_4, class_name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _5);
	zephir_check_call_status();
	zephir_throw_exception_debug(_3, "rexpro/message.zep", 206 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Rexpro_Message, serializeBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3 = NULL, _4;

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
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(rexpro_exception_ce, "Message::serializeBody() doesn't recognize the given serializer type.", "rexpro/message.zep", 221);
	return;

}

PHP_METHOD(Rexpro_Message, deserializeBody) {

	zval *_0, *_1, *_2, _3;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(rexpro_exception_ce, "Message::deserializeBody requires Message::_message_body_serialized to be set.", "rexpro/message.zep", 228);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serializerType"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_1, 1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("messageBodySerialized"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, 256);
		zephir_json_decode(return_value, &(return_value), _2, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		return;
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(rexpro_exception_ce, "Message::deserializeBody doesn't recognize the given serializer type.", "rexpro/message.zep", 235);
	return;

}

PHP_METHOD(Rexpro_Message, convertIntTo32BitBinaryString) {

	zend_bool _7;
	int ZEPHIR_LAST_CALL_STATUS, _8, _9, _13;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_11 = NULL, *_12 = NULL;
	zval *raw_int = NULL, *_0 = NULL, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *result, *i = NULL, _10 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw_int);

	ZEPHIR_SEPARATE_PARAM(raw_int);


	ZEPHIR_CALL_FUNCTION(&_0, "is_int", &_1, raw_int);
	zephir_check_call_status();
	if (!zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, rexpro_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		zephir_gettype(_3, raw_int TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "Message::convertIntTo32BitBinaryString requires an int. %s given.", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, &_4, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "rexpro/message.zep", 241 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(result);
	array_init(result);
	_9 = 3;
	_8 = 0;
	_7 = 0;
	if (_8 <= _9) {
		while (1) {
			if (_7) {
				_8++;
				if (!(_8 <= _9)) {
					break;
				}
			} else {
				_7 = 1;
			}
			ZEPHIR_INIT_NVAR(i);
			ZVAL_LONG(i, _8);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "C*", 0);
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, ((int) (zephir_get_numberval(raw_int)) & 0xff));
			ZEPHIR_CALL_FUNCTION(&_5, "pack", &_11, &_4, &_10);
			zephir_check_call_status();
			Z_SET_ISREF_P(result);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_12, result, _5);
			Z_UNSET_ISREF_P(result);
			zephir_check_call_status();
			_13 = ((int) (zephir_get_numberval(raw_int)) >> 8);
			ZEPHIR_INIT_NVAR(raw_int);
			ZVAL_LONG(raw_int, _13);
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
	add_index_stringl(_2, 1, SL("Rexpro\\Message\\Body\\Request\\Session"), 1);
	add_index_stringl(_2, 2, SL("Rexpro\\Message\\Body\\Response\\Session"), 1);
	add_index_stringl(_2, 3, SL("Rexpro\\Message\\Body\\Request\\Script"), 1);
	add_index_stringl(_2, 5, SL("Rexpro\\Message\\Body\\Response\\Script"), 1);
	add_index_stringl(_2, 0, SL("Rexpro\\Message\\Body\\Response\\Error"), 1);
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

