
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Rexpro_Client) {

	ZEPHIR_REGISTER_CLASS(Rexpro, Client, rexpro, client, rexpro_client_method_entry, 0);

	zend_declare_property_null(rexpro_client_ce, SL("socket"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(rexpro_client_ce, SL("host_uri"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Client, __construct) {

	zval *host_uri_param = NULL;
	zval *host_uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host_uri_param);

	zephir_get_strval(host_uri, host_uri_param);


	zephir_update_property_this(this_ptr, SL("host_uri"), host_uri TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Rexpro_Client, executeScript) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_0 = NULL, *_1 = NULL;
	zval *bindings = NULL;
	zval *query_param = NULL, *graph_name_param = NULL, *bindings_param = NULL, *script, *message, *meta;
	zval *query = NULL, *graph_name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &query_param, &graph_name_param, &bindings_param);

	zephir_get_strval(query, query_param);
	zephir_get_strval(graph_name, graph_name_param);
	if (!bindings_param) {
		ZEPHIR_INIT_VAR(bindings);
		array_init(bindings);
	} else {
		zephir_get_arrval(bindings, bindings_param);
	}


	ZEPHIR_INIT_VAR(meta);
	array_init_size(meta, 2);
	zephir_array_update_string(&meta, SL("graphName"), &graph_name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(script);
	if (!_0) {
		_0 = zend_fetch_class(SL("Rexpro\\Message\\Body\\Request\\Script"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(script, _0);
	if (zephir_has_constructor(script TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, script, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, script, "setscript", NULL, query);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, script, "setbindings", NULL, bindings);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, script, "setmeta", NULL, meta);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(message);
	if (!_1) {
		_1 = zend_fetch_class(SL("Rexpro\\Message"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(message, _1);
	if (zephir_has_constructor(message TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, message, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, message, "setmessagebody", NULL, script);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "send", NULL, message);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getresponse", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Rexpro_Client, getResponse) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_20 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_0 = NULL;
	zval *message, *stream = NULL, *protocol_version = NULL, *serializer_type = NULL, *reserved = NULL, *message_type = NULL, *message_size = NULL, *message_body_serialized = NULL, *_1, _2 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL, *_7 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18, *_19 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(message);
	if (!_0) {
		_0 = zend_fetch_class(SL("Rexpro\\Message"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(message, _0);
	if (zephir_has_constructor(message TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, message, "__construct", NULL);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 11);
	ZEPHIR_CALL_FUNCTION(&stream, "stream_get_contents", &_3, _1, &_2);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_5, "substr", &_6, stream, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "bin2hex", &_8, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&protocol_version, "hexdec", &_9, _7);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_10, "substr", &_6, stream, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_11, "bin2hex", &_8, _10);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&serializer_type, "hexdec", &_9, _11);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_CALL_FUNCTION(&_12, "substr", &_6, stream, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_13, "bin2hex", &_8, _12);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&reserved, "hexdec", &_9, _13);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 6);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_14, "substr", &_6, stream, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_15, "bin2hex", &_8, _14);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&message_type, "hexdec", &_9, _15);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 7);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_CALL_FUNCTION(&_16, "substr", &_6, stream, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_17, "bin2hex", &_8, _16);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&message_size, "hexdec", &_9, _17);
	zephir_check_call_status();
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_19, message, "getmessagesize", NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 11);
	ZEPHIR_CALL_FUNCTION(&message_body_serialized, "stream_get_contents", &_3, _18, _19, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, message, "setprotocolversion", NULL, protocol_version);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, message, "setserializertype", NULL, serializer_type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, message, "setreserved", NULL, reserved);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, message, "setmessagetype", NULL, message_type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, message, "setmessagesize", NULL, message_size);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, message, "setmessagebodyserialized", NULL, message_body_serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, message, "unpack", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroysocket", &_20);
	zephir_check_call_status();
	RETURN_CCTOR(message);

}

PHP_METHOD(Rexpro_Client, send) {

	zephir_nts_static zend_class_entry *_3 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *packed = NULL, *write, *_1, *_2, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	if (!(zephir_is_instance_of(message, SL("Rexpro\\Message") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'message' must be an instance of 'Rexpro\\Message'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connectsocket", &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&packed, message, "pack", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(write);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	zephir_fwrite(write, _1, packed TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(write)) {
		ZEPHIR_INIT_VAR(_2);
		if (!_3) {
			_3 = zend_fetch_class(SL("Rexpro\\Exception\\Socket"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_2, _3);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "Rexpro was not able to send your request to the server.", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_2, "rexpro/client.zep", 77 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Rexpro_Client, connectSocket) {

	zephir_nts_static zend_class_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *errno, *errorMessage, *_0, _1, *_2 = NULL, *_4 = NULL, *_6, *_7;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(errno);
	ZVAL_NULL(errno);
	ZEPHIR_INIT_VAR(errorMessage);
	ZVAL_NULL(errorMessage);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("host_uri"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "default_socket_timeout", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "ini_get", &_3, &_1);
	zephir_check_call_status();
	Z_SET_ISREF_P(errno);
	ZEPHIR_CALL_FUNCTION(&_4, "stream_socket_client", &_5, _0, errno, errorMessage, _2);
	Z_UNSET_ISREF_P(errno);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("socket"), _4 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	if (!(zephir_is_true(_6))) {
		ZEPHIR_INIT_VAR(_7);
		if (!_8) {
			_8 = zend_fetch_class(SL("Rexpro\\Exception\\Socket"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_7, _8);
		if (zephir_has_constructor(_7 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, errorMessage, errno);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_7, "rexpro/client.zep", 100 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Rexpro_Client, __destruct) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroysocket", &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Rexpro_Client, destroySocket) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0, *_1, _2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 2);
		ZEPHIR_CALL_FUNCTION(NULL, "stream_socket_shutdown", &_3, _1, &_2);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("socket"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	RETURN_MM_BOOL(1);

}

