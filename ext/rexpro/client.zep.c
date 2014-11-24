
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
	object_init_ex(script, rexpro_message_body_request_script_ce);
	ZEPHIR_CALL_METHOD(NULL, script, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, script, "setscript", NULL, query);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, script, "setbindings", NULL, bindings);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, script, "setmeta", NULL, meta);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(message);
	object_init_ex(message, rexpro_message_ce);
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

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *stream = NULL, *protocol_version = NULL, *serializer_type = NULL, *reserved = NULL, *message_type = NULL, *message_size = NULL, *message_body_serialized = NULL, *_0, _1 = zval_used_for_init, _3 = zval_used_for_init, *_4 = NULL, *_6 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(message);
	object_init_ex(message, rexpro_message_ce);
	if (zephir_has_constructor(message TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, message, "__construct", NULL);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 11);
	ZEPHIR_CALL_FUNCTION(&stream, "stream_get_contents", &_2, _0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "substr", &_5, stream, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "bin2hex", &_7, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&protocol_version, "hexdec", &_8, _6);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_9, "substr", &_5, stream, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_10, "bin2hex", &_7, _9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&serializer_type, "hexdec", &_8, _10);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 4);
	ZEPHIR_CALL_FUNCTION(&_11, "substr", &_5, stream, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_12, "bin2hex", &_7, _11);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&reserved, "hexdec", &_8, _12);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 6);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_13, "substr", &_5, stream, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_14, "bin2hex", &_7, _13);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&message_type, "hexdec", &_8, _14);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 7);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 4);
	ZEPHIR_CALL_FUNCTION(&_15, "substr", &_5, stream, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_16, "bin2hex", &_7, _15);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&message_size, "hexdec", &_8, _16);
	zephir_check_call_status();
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 11);
	ZEPHIR_CALL_FUNCTION(&message_body_serialized, "stream_get_contents", &_2, _17, message_size, &_1);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroysocket", &_18);
	zephir_check_call_status();
	RETURN_CCTOR(message);

}

PHP_METHOD(Rexpro_Client, send) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *packed = NULL, *write, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	if (!(zephir_instance_of_ev(message, rexpro_message_ce TSRMLS_CC))) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(rexpro_exception_socket_ce, "Rexpro was not able to send your request to the server.", "rexpro/client.zep", 78);
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Rexpro_Client, connectSocket) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("host_uri"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "stream_socket_client", &_2, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("socket"), _1 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	if (!(zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(rexpro_exception_socket_ce, "Unable to connect to socket.", "rexpro/client.zep", 90);
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

