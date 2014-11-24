
extern zend_class_entry *rexpro_message_ce;

ZEPHIR_INIT_CLASS(Rexpro_Message);

PHP_METHOD(Rexpro_Message, setProtocolVersion);
PHP_METHOD(Rexpro_Message, getProtocolVersion);
PHP_METHOD(Rexpro_Message, getSerializerType);
PHP_METHOD(Rexpro_Message, setReserved);
PHP_METHOD(Rexpro_Message, getReserved);
PHP_METHOD(Rexpro_Message, setMessageSize);
PHP_METHOD(Rexpro_Message, setMessageBody);
PHP_METHOD(Rexpro_Message, setMessageBodySerialized);
PHP_METHOD(Rexpro_Message, setSerializerType);
PHP_METHOD(Rexpro_Message, getMessageSize);
PHP_METHOD(Rexpro_Message, setMessageType);
PHP_METHOD(Rexpro_Message, getMessageType);
PHP_METHOD(Rexpro_Message, getMessageBody);
PHP_METHOD(Rexpro_Message, getMessageBodySerialized);
PHP_METHOD(Rexpro_Message, pack);
PHP_METHOD(Rexpro_Message, unpack);
PHP_METHOD(Rexpro_Message, getMessageTypeFromKey);
PHP_METHOD(Rexpro_Message, getMessageKeyFromType);
PHP_METHOD(Rexpro_Message, serializeBody);
PHP_METHOD(Rexpro_Message, deserializeBody);
PHP_METHOD(Rexpro_Message, convertIntTo32BitBinaryString);
PHP_METHOD(Rexpro_Message, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_setprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, protocolVersion)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_setreserved, 0, 0, 1)
	ZEND_ARG_INFO(0, reserved)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_setmessagesize, 0, 0, 1)
	ZEND_ARG_INFO(0, messageSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_setmessagebody, 0, 0, 1)
	ZEND_ARG_INFO(0, messageBody)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_setmessagebodyserialized, 0, 0, 1)
	ZEND_ARG_INFO(0, messageBodySerialized)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_setserializertype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_setmessagetype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_getmessagetypefromkey, 0, 0, 0)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_getmessagekeyfromtype, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, body, Rexpro\\Message\\Body, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_rexpro_message_convertintto32bitbinarystring, 0, 0, 1)
	ZEND_ARG_INFO(0, raw_int)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(rexpro_message_method_entry) {
	PHP_ME(Rexpro_Message, setProtocolVersion, arginfo_rexpro_message_setprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getProtocolVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getSerializerType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, setReserved, arginfo_rexpro_message_setreserved, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getReserved, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, setMessageSize, arginfo_rexpro_message_setmessagesize, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, setMessageBody, arginfo_rexpro_message_setmessagebody, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, setMessageBodySerialized, arginfo_rexpro_message_setmessagebodyserialized, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, setSerializerType, arginfo_rexpro_message_setserializertype, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getMessageSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, setMessageType, arginfo_rexpro_message_setmessagetype, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getMessageType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getMessageBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getMessageBodySerialized, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, pack, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, unpack, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Rexpro_Message, getMessageTypeFromKey, arginfo_rexpro_message_getmessagetypefromkey, ZEND_ACC_PRIVATE)
	PHP_ME(Rexpro_Message, getMessageKeyFromType, arginfo_rexpro_message_getmessagekeyfromtype, ZEND_ACC_PRIVATE)
	PHP_ME(Rexpro_Message, serializeBody, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Rexpro_Message, deserializeBody, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Rexpro_Message, convertIntTo32BitBinaryString, arginfo_rexpro_message_convertintto32bitbinarystring, ZEND_ACC_PRIVATE)
	PHP_ME(Rexpro_Message, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
