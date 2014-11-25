namespace Rexpro;

class Client
{
    private socket;
    private host_uri;

    public function __construct(string host_uri)
    {
        let this->host_uri = host_uri;
    }

    public function executeScript(string query, string graph_name, array bindings = []) -> <\Rexpro\Message>
    {
        var script;
        var message;
        var meta;
        let meta = ["graphName": graph_name];

        let script = new \Rexpro\Message\Body\Request\Script;
        script->setScript(query);
        script->setBindings(bindings);
        script->setMeta(meta);

        let message = new Message;
        message->setMessageBody(script);

        this->send(message);

        return this->getResponse();
    }

    public function startSession(string username, string password, string graph_name) -> <\Rexpro\Message>
    {
        var session;
        var message;
        var meta;

        let meta    = ["graphName": graph_name];
        let session = new Message\Body\Request\Session;

        session->setUsername(username);
        session->setPassword(password);
        session->setMeta(meta);

        let message = new Message;
        message->setMessageBody(session);

        this->send(message);

        return this->getResponse();
    }

     public function destroySession(string session_id, string username, string password, string graph_name)-> <\Rexpro\Message>
     {
        var session;
        var message;        
        var meta;
        
        let session = new Message\Body\Request\Session;
        let meta    = ["graphName": graph_name, "killSession" : true];

        session->setSession(session_id);
        session->setUsername(username);
        session->setPassword(password);
        session->setMeta(meta);

        let message = new Message;
        message->setMessageBody(session);

        this->send(message);

        return this->getResponse();
    }    

    public function getResponse() -> <\Rexpro\Message>
    {
        var message;
        var stream;
        var protocol_version;
        var serializer_type;
        var reserved;
        var message_type;
        var message_size;
        var message_body_serialized;

        let message                 = new \Rexpro\Message();
        let stream                  = stream_get_contents(this->socket, 11);
        let protocol_version        = hexdec(bin2hex(substr(stream, 0, 1)));
        let serializer_type         = hexdec(bin2hex(substr(stream, 1, 1)));
        let reserved                = hexdec(bin2hex(substr(stream, 2, 4)));
        let message_type            = hexdec(bin2hex(substr(stream, 6, 1)));
        let message_size            = hexdec(bin2hex(substr(stream, 7, 4)));
        let message_body_serialized = stream_get_contents(this->socket, message_size, 11);

        message->setProtocolVersion(protocol_version);
        message->setSerializerType(serializer_type);
        message->setReserved(reserved);
        message->setMessageType(message_type);
        message->setMessageSize(message_size);
        message->setMessageBodySerialized(message_body_serialized);

        message->unpack();

        this->destroySocket();

        return message;
    }

    public function send(<\Rexpro\Message> message) -> boolean
    {
        var packed;
        var write;

        this->connectSocket();
        let packed = message->pack();
        let write  = fwrite(this->socket, packed);

        if write === false
        {
            throw new \Rexpro\Exception\Socket("Rexpro was not able to send your request to the server.");
        }

        return true;
    }

    private function connectSocket() -> boolean
    {
        let this->socket = stream_socket_client(this->host_uri);

        if !this->socket
        {
            throw new \Rexpro\Exception\Socket("Unable to connect to socket.");
        }

        return true;
    }

    public function __destruct() -> boolean
    {
        this->destroySocket();

        return true;
    }

    private function destroySocket() -> boolean
    {
        if this->socket !== null
        {
            stream_socket_shutdown(this->socket, STREAM_SHUT_RDWR);
            let this->socket = null;
        }

        return true;
    }

}