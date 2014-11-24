
extern zend_class_entry *rexpro_exception_ce;

ZEPHIR_INIT_CLASS(Rexpro_Exception);

PHP_METHOD(Rexpro_Exception, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_exception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_OBJ_INFO(0, previous, Exception, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_exception_method_entry) {
	PHP_ME(Rexpro_Exception, __construct, arginfo_rexpro_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
