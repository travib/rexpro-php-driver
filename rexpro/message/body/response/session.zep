namespace Rexpro\Message\Body\Response;

class Session extends \Rexpro\Message\Body\Response
{
    private languages{
        get, set    
    };    

    public function toArray()
    {
        var message;

        let message              = [];
        let message["session"]   = this->getSession();
        let message["request"]   = this->getRequest();
        let message["meta"]      = this->getMeta();
        let message["languages"] = this->getLanguages();

        return message;
    }

    protected function hydrate(raw)
    {
        this->setSession(raw[0]);
        this->setRequest(raw[1]);
        this->setMeta(raw[2]);
        this->setLanguages(raw[3]);

        return this;
    }

    protected function getMetaAttributes()
    {
        return [];
    }
}