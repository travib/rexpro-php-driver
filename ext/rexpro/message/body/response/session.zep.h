
extern zend_class_entry *rexpro_message_body_response_session_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response_Session);

PHP_METHOD(Rexpro_Message_Body_Response_Session, getLanguages);
PHP_METHOD(Rexpro_Message_Body_Response_Session, setLanguages);
PHP_METHOD(Rexpro_Message_Body_Response_Session, toArray);
PHP_METHOD(Rexpro_Message_Body_Response_Session, hydrate);
PHP_METHOD(Rexpro_Message_Body_Response_Session, getMetaAttributes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_session_setlanguages, 0, 0, 1)
	ZEND_ARG_INFO(0, languages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_session_hydrate, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_body_response_session_method_entry) {
	PHP_ME(Rexpro_Message_Body_Response_Session, getLanguages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Session, setLanguages, arginfo_rexpro_message_body_response_session_setlanguages, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Session, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Session, hydrate, arginfo_rexpro_message_body_response_session_hydrate, ZEND_ACC_PROTECTED)
	PHP_ME(Rexpro_Message_Body_Response_Session, getMetaAttributes, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
