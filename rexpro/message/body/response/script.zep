namespace Rexpro\Message\Body\Response;

class Script extends \Rexpro\Message\Body\Response
{
    private results {
        get, set
    };
    private bindings {
        get, set
    };

    public function toArray()
    {
        var message;

        let message = [];
        let message["session"]  = this->getSession();
        let message["request"]  = this->getRequest();
        let message["meta"]     = this->getMeta();
        let message["results"]  = this->getResults();
        let message["bindings"] = this->getBindings();

        return message;
    }

    protected function hydrate(raw)
    {
        this->setSession(raw[0]);
        this->setRequest(raw[1]);
        this->setMeta(raw[2]);
        this->setResults((is_array(raw[3]) ? raw[3] : [raw[3]]));
        this->setBindings(raw[4]);

        return this;
    }

    protected function getMetaAttributes()
    {
        return [];
    }
}
