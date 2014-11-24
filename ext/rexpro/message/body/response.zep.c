
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response) {

	ZEPHIR_REGISTER_CLASS_EX(Rexpro\\Message\\Body, Response, rexpro, message_body_response, rexpro_message_body_ce, rexpro_message_body_response_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Message_Body_Response, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &raw);

	if (!raw) {
		raw = ZEPHIR_GLOBAL(global_null);
	}


	if (!(ZEPHIR_IS_EMPTY(raw))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "hydrate", NULL, raw);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Rexpro_Message_Body_Response, toArray) {

}

PHP_METHOD(Rexpro_Message_Body_Response, hydrate) {

}

