namespace Rexpro\Message\Body\Response;

class Error extends \Rexpro\Message\Body\Response
{
    private errorMessage {
        get, set
    };
    private meta_attributes = [
        "flag"
    ];

    public function toArray()
    {
        var message;
        let message = [];
        let message["session"]       = this->getSession();
        let message["request"]       = this->getRequest();
        let message["meta"]          = this->getMeta();
        let message["error_message"] = this->getErrorMessage();

        return message;
    }

    protected function hydrate(raw)
    {
        this->setSession(raw[0]);
        this->setRequest(raw[1]);
        this->setMeta(raw[2]);
        this->setErrorMessage(raw[3]);

        return this;
    }

    protected function getMetaAttributes()
    {
        return this->meta_attributes;
    }
}