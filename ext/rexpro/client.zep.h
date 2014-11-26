
extern zend_class_entry *rexpro_client_ce;

ZEPHIR_INIT_CLASS(Rexpro_Client);

PHP_METHOD(Rexpro_Client, __construct);
PHP_METHOD(Rexpro_Client, executeScript);
PHP_METHOD(Rexpro_Client, startSession);
PHP_METHOD(Rexpro_Client, destroySession);
PHP_METHOD(Rexpro_Client, getResponse);
PHP_METHOD(Rexpro_Client, send);
PHP_METHOD(Rexpro_Client, connectSocket);
PHP_METHOD(Rexpro_Client, __destruct);
PHP_METHOD(Rexpro_Client, destroySocket);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_client___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, host_uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_client_executescript, 0, 0, 2)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, graph_name)
	ZEND_ARG_ARRAY_INFO(0, bindings, 1)
	ZEND_ARG_INFO(0, session)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_client_startsession, 0, 0, 3)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, graph_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_client_destroysession, 0, 0, 4)
	ZEND_ARG_INFO(0, session_id)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, graph_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_client_send, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Rexpro\\Message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_client_method_entry) {
	PHP_ME(Rexpro_Client, __construct, arginfo_rexpro_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Rexpro_Client, executeScript, arginfo_rexpro_client_executescript, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Client, startSession, arginfo_rexpro_client_startsession, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Client, destroySession, arginfo_rexpro_client_destroysession, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Client, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Client, send, arginfo_rexpro_client_send, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Client, connectSocket, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Rexpro_Client, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Rexpro_Client, destroySocket, NULL, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
