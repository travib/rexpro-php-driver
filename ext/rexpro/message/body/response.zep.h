
extern zend_class_entry *rexpro_message_body_response_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response);

PHP_METHOD(Rexpro_Message_Body_Response, __construct);
PHP_METHOD(Rexpro_Message_Body_Response, toArray);
PHP_METHOD(Rexpro_Message_Body_Response, hydrate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_hydrate, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_body_response_method_entry) {
	PHP_ME(Rexpro_Message_Body_Response, __construct, arginfo_rexpro_message_body_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Rexpro_Message_Body_Response, toArray, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response, hydrate, arginfo_rexpro_message_body_response_hydrate, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
  PHP_FE_END
};
