
extern zend_class_entry *rexpro_message_body_request_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Request);

PHP_METHOD(Rexpro_Message_Body_Request, __construct);
PHP_METHOD(Rexpro_Message_Body_Request, createUuid);
PHP_METHOD(Rexpro_Message_Body_Request, toArray);

ZEPHIR_INIT_FUNCS(rexpro_message_body_request_method_entry) {
	PHP_ME(Rexpro_Message_Body_Request, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Rexpro_Message_Body_Request, createUuid, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Rexpro_Message_Body_Request, toArray, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
