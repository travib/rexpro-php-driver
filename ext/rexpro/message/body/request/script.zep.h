
extern zend_class_entry *rexpro_message_body_request_script_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Request_Script);

PHP_METHOD(Rexpro_Message_Body_Request_Script, setLanguageName);
PHP_METHOD(Rexpro_Message_Body_Request_Script, getLanguageName);
PHP_METHOD(Rexpro_Message_Body_Request_Script, setScript);
PHP_METHOD(Rexpro_Message_Body_Request_Script, getScript);
PHP_METHOD(Rexpro_Message_Body_Request_Script, setBindings);
PHP_METHOD(Rexpro_Message_Body_Request_Script, getBindings);
PHP_METHOD(Rexpro_Message_Body_Request_Script, __construct);
PHP_METHOD(Rexpro_Message_Body_Request_Script, toArray);
PHP_METHOD(Rexpro_Message_Body_Request_Script, getMetaAttributes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_request_script_setlanguagename, 0, 0, 1)
	ZEND_ARG_INFO(0, languageName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_request_script_setscript, 0, 0, 1)
	ZEND_ARG_INFO(0, script)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_request_script_setbindings, 0, 0, 1)
	ZEND_ARG_INFO(0, bindings)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_body_request_script_method_entry) {
	PHP_ME(Rexpro_Message_Body_Request_Script, setLanguageName, arginfo_rexpro_message_body_request_script_setlanguagename, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Script, getLanguageName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Script, setScript, arginfo_rexpro_message_body_request_script_setscript, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Script, getScript, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Script, setBindings, arginfo_rexpro_message_body_request_script_setbindings, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Script, getBindings, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Script, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Rexpro_Message_Body_Request_Script, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Request_Script, getMetaAttributes, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
