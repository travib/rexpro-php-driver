
extern zend_class_entry *rexpro_message_body_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message_Body);

PHP_METHOD(Rexpro_Message_Body, setSession);
PHP_METHOD(Rexpro_Message_Body, getSession);
PHP_METHOD(Rexpro_Message_Body, setRequest);
PHP_METHOD(Rexpro_Message_Body, getRequest);
PHP_METHOD(Rexpro_Message_Body, getMeta);
PHP_METHOD(Rexpro_Message_Body, setMeta);
PHP_METHOD(Rexpro_Message_Body, getMetaAttributes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_setsession, 0, 0, 1)
	ZEND_ARG_INFO(0, session)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_setrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_body_setmeta, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, meta, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_body_method_entry) {
	PHP_ME(Rexpro_Message_Body, setSession, arginfo_rexpro_message_body_setsession, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body, getSession, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body, setRequest, arginfo_rexpro_message_body_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body, getMeta, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body, setMeta, arginfo_rexpro_message_body_setmeta, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message_Body, getMetaAttributes, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
  PHP_FE_END
};
