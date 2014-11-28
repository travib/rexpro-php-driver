
extern zend_class_entry *rexpro_message_body_request_session_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Request_Session);

PHP_METHOD(Rexpro_Message_Body_Request_Session, setUsername);
PHP_METHOD(Rexpro_Message_Body_Request_Session, getUsername);
PHP_METHOD(Rexpro_Message_Body_Request_Session, setPassword);
PHP_METHOD(Rexpro_Message_Body_Request_Session, getPassword);
PHP_METHOD(Rexpro_Message_Body_Request_Session, __construct);
PHP_METHOD(Rexpro_Message_Body_Request_Session, toArray);
PHP_METHOD(Rexpro_Message_Body_Request_Session, getMetaAttributes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_request_session_setusername, 0, 0, 1)
	ZEND_ARG_INFO(0, username)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_request_session_setpassword, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_body_request_session_method_entry) {
	PHP_ME(Rexpro_Message_Body_Request_Session, setUsername, arginfo_rexpro_message_body_request_session_setusername, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Session, getUsername, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Session, setPassword, arginfo_rexpro_message_body_request_session_setpassword, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Session, getPassword, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Session, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Rexpro_Message_Body_Request_Session, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Session, getMetaAttributes, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
