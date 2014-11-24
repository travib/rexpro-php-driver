
extern zend_class_entry *rexpro_message_body_response_error_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response_Error);

PHP_METHOD(Rexpro_Message_Body_Response_Error, getErrorMessage);
PHP_METHOD(Rexpro_Message_Body_Response_Error, setErrorMessage);
PHP_METHOD(Rexpro_Message_Body_Response_Error, toArray);
PHP_METHOD(Rexpro_Message_Body_Response_Error, hydrate);
PHP_METHOD(Rexpro_Message_Body_Response_Error, getMetaAttributes);
PHP_METHOD(Rexpro_Message_Body_Response_Error, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_error_seterrormessage, 0, 0, 1)
	ZEND_ARG_INFO(0, errorMessage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_error_hydrate, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_error___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_body_response_error_method_entry) {
	PHP_ME(Rexpro_Message_Body_Response_Error, getErrorMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Error, setErrorMessage, arginfo_rexpro_message_body_response_error_seterrormessage, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Error, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Error, hydrate, arginfo_rexpro_message_body_response_error_hydrate, ZEND_ACC_PROTECTED)
	PHP_ME(Rexpro_Message_Body_Response_Error, getMetaAttributes, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Rexpro_Message_Body_Response_Error, __construct, arginfo_rexpro_message_body_response_error___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
