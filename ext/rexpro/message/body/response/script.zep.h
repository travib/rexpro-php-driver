
extern zend_class_entry *rexpro_message_body_response_script_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body_Response_Script);

PHP_METHOD(Rexpro_Message_Body_Response_Script, getResults);
PHP_METHOD(Rexpro_Message_Body_Response_Script, setResults);
PHP_METHOD(Rexpro_Message_Body_Response_Script, getBindings);
PHP_METHOD(Rexpro_Message_Body_Response_Script, setBindings);
PHP_METHOD(Rexpro_Message_Body_Response_Script, toArray);
PHP_METHOD(Rexpro_Message_Body_Response_Script, hydrate);
PHP_METHOD(Rexpro_Message_Body_Response_Script, getMetaAttributes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_script_setresults, 0, 0, 1)
	ZEND_ARG_INFO(0, results)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_script_setbindings, 0, 0, 1)
	ZEND_ARG_INFO(0, bindings)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_response_script_hydrate, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_body_response_script_method_entry) {
	PHP_ME(Rexpro_Message_Body_Response_Script, getResults, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Script, setResults, arginfo_rexpro_message_body_response_script_setresults, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Script, getBindings, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Script, setBindings, arginfo_rexpro_message_body_response_script_setbindings, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Script, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body_Response_Script, hydrate, arginfo_rexpro_message_body_response_script_hydrate, ZEND_ACC_PROTECTED)
	PHP_ME(Rexpro_Message_Body_Response_Script, getMetaAttributes, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
