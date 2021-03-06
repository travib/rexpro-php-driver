/* -*- Mode: C; tab-width: 4 -*- */
/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2009 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Travis Black <travisb@vrazzle.com>                           |
  +----------------------------------------------------------------------+
*/
namespace Rexpro;

/**
 * Wrapper class for Binary interface to RexPro
 *
 * Wraps RexPro Messages in a reusable PHP Object
 * @see https://github.com/tinkerpop/rexster/wiki/RexPro-Messages
 */
class Message
{
    /**
     * The JSON serializer identifier for RexPro
     */
    const SERIALIZER_TYPE_JSON    = 1;

    /**
     * The MsgPack serializer identifier for RexPro
     */
    const SERIALIZER_TYPE_MSGPACK = 0;

    /**
     * The current RexPro version
     */
    private protocolVersion = 1 {
        set, get
    };

    /**
     * The type of serializer used in messages to Rexster
     */
    private serializerType  = self::SERIALIZER_TYPE_JSON {
        get
    };

    /**
     * RexPro messages require these empty bits
     */
    private reserved         = [0,0,0,0] {
        set, get
    };

    /**
     * ID of message type
     */
    private message_type;

    /**
     * Length of the serialized message body
     */
    private messageSize {
        set
    };

    /**
     * The main contents of the message
     */
    private messageBody {
        set
    };

    /**
     * The serialized message body (what is actually communicated to/from Rexster)
     */
    private messageBodySerialized {
        set
    };

    /**
     * A mapping of Rexster Message type ids to classes
     */
    private message_types    = [
        1: "Rexpro\\Message\\Body\\Request\\Session",
        2: "Rexpro\\Message\\Body\\Response\\Session",
        3: "Rexpro\\Message\\Body\\Request\\Script",
        5: "Rexpro\\Message\\Body\\Response\\Script",
        0: "Rexpro\\Message\\Body\\Response\\Error"
    ];

    /**
     * All possible Rexster serializer types
     */
    private serializer_types = [
        self::SERIALIZER_TYPE_JSON,
        self::SERIALIZER_TYPE_MSGPACK
    ];

    public function setSerializerType(int type) -> <\Rexpro\Message>
    {
        /**
         * Validate serializer type
         */
        if (in_array(type, this->serializer_types)) {
            let this->serializerType = type;

            return this;
        }

        throw new \Rexpro\Exception(sprintf("%s is not a valid type", type));
    }

    public function getMessageSize() -> int
    {
        /**
         * Return messageSize member variable if set
         */
        if !empty this->messageSize
        {
            return this->messageSize;
        }

        /**
         * Determine Message size from the serialized body
         */
        if (!empty this->messageBodySerialized)
        {
            let this->messageSize = mb_strlen(this->messageBodySerialized, "ISO-8859-1");
        } elseif (!empty this->messageBody)
        {
            /**
             * We need the length of the serialized body
             */
            this->serializeBody();
            let this->messageSize = mb_strlen(this->messageBodySerialized, "ISO-8859-1");
        }

        return this->messageSize;
    }

    public function setMessageType(type) -> <\Rexpro\Message>
    {
        /**
         * Validate the message type
         */
        if (array_key_exists(type, this->message_types)) {
            let this->message_type = type;

            return this;
        }

        throw new \Rexpro\Exception(sprintf("%s is not a valid type", type));
    }


    public function getMessageType()
    {
        /**
         * If message type member variable is valid, return it.
         */
        if (is_int(this->message_type)) {
            return this->message_type;
        }

        /**
         * If there is a message body, get the type from it.
         */
        if (!empty this->messageBody)
        {
            let this->message_type = this->getMessageKeyFromType(this->messageBody);

            return this->message_type;
        }

        return null;
    }


    public function getMessageBody()
    {
        if (!empty this->messageBody) {
            return this->messageBody;
        }

        if !empty this->messageBodySerialized {
            let this->messageBody = this->unpack();

            return this->messageBody;
        }

        return null;
    }

    public function getMessageBodySerialized()
    {
        if !empty this->messageBodySerialized {
            return this->messageBodySerialized;
        }

        if !empty this->messageBody {
            this->serializeBody();

            return this->messageBodySerialized;
        }

        return null;
    }

    public function pack()
    {
        // Add this back later. Haven"t implemented body yet.
        // if !(typeof this->messageBody == "\Rexpro\Message\Body")
        // {
        //     throw new \Rexpro\Exception("Message::_message_body is invalid type.");
        // }

        let this->messageSize = null;
        let this->messageBodySerialized = null;
        let this->message_type = null;

        var protocol_version;
        var serializer_type;
        var message_type;

        let protocol_version= this->getProtocolVersion();
        let serializer_type = this->getSerializerType();
        let message_type   = this->getMessageType();

        var pack;

        let pack = pack(
            "C*",
            protocol_version,
            serializer_type,
            this->reserved[0],
            this->reserved[1],
            this->reserved[2],
            this->reserved[3],
            message_type
        );

        var message_size;
        var message_body_serialized;

        let message_size = this->getMessageSize();
        let message_body_serialized = this->getMessageBodySerialized();

        let pack .= this->convertIntTo32BitBinaryString(message_size).message_body_serialized;;

        return pack;
    }

    public function unpack()
    {
        if (empty this->messageBodySerialized) {
            throw new \Rexpro\Exception("There is currently no serialized message body. Nothing to unpack.");
        }

        let this->messageBody           = this->getMessageTypeFromKey(this->deserializeBody());
        let this->messageBodySerialized = null;

        return this;
    }

    private function getMessageTypeFromKey(raw = false)
    {
        if (this->getMessageType() !== false) {
            var message_type;
            let message_type  = this->message_types[this->getMessageType()];
            return new {message_type}(raw);
        }

        throw new \Rexpro\Exception("The given MessageType id doesn\"t map to a message type class.");
    }

    private function getMessageKeyFromType(<\Rexpro\Message\Body> body)
    {
        var key;
        var class_name;
        let class_name = get_class(body);
        let key = array_search(get_class(body), this->message_types);

        if key {
            return key;
        }

        throw new \Rexpro\Exception(sprintf("Message type not found for this instance of Message\Body. %s", class_name));
    }

    private function serializeBody()
    {
        // if !(typeof this->messageBody == "\Rexpro\Message\Body") {
        //     throw new \Rexpro\Exception(sprintf("Message::_message_body must be an instance of Message\Body. %s given.", gettype(this->messageBody)));
        // }

        if(this->serializerType == self::SERIALIZER_TYPE_JSON) {
            let this->messageBodySerialized = json_encode(this->messageBody->toArray(), JSON_UNESCAPED_UNICODE);

            return this;
        }

        throw new \Rexpro\Exception("Message::serializeBody() doesn't recognize the given serializer type.");
    }

    private function deserializeBody()
    {
        if empty this->messageBodySerialized
        {
            throw new Exception("Message::deserializeBody requires Message::_message_body_serialized to be set.");
        }

        if this->serializerType == self::SERIALIZER_TYPE_JSON {
            return json_decode(this->messageBodySerialized, true, JSON_UNESCAPED_UNICODE);
        }

        throw new \Rexpro\Exception("Message::deserializeBody doesn't recognize the given serializer type.");
    }

    private function convertIntTo32BitBinaryString(raw_int)
    {
        if (!is_int(raw_int)) {
            throw new Exception(sprintf("Message::convertIntTo32BitBinaryString requires an int. %s given.", gettype(raw_int)));
        }

        var result;
        let result = [];
        var i;
        for i in range(0, 3) {
            array_unshift(result, pack("C*", raw_int & 0xff));
            let raw_int = raw_int >> 8;
        }

        return implode("", result);
    }
}