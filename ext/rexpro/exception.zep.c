
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Rexpro_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Rexpro, Exception, rexpro, exception, zend_exception_get_default(TSRMLS_C), rexpro_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Rexpro_Exception, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *message, *code = NULL, *previous = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &message, &code, &previous);

	if (!code) {
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 0);
	}
	if (!previous) {
		previous = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(previous) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(previous, zend_exception_get_default(TSRMLS_C) TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'previous' must be an instance of 'Exception'", "", 0);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, rexpro_exception_ce, this_ptr, "__construct", NULL, message, code, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

