namespace Rexpro\Message\Body\Request;


class Session extends \Rexpro\Message\Body\Request
{
    private username {
        set, get
    };
    private password {
        set, get
    };
    
    private meta_attributes = [
        "killSession",
        "graphName",
        "graphObjName"
    ];

    public function __construct() {
        parent::__construct();
    }

    public function toArray()
    {
        var meta;
        let meta = this->getMeta();

        var message;

        let message = [
            this->getSession(),
            this->getRequest(),
            ((is_array(meta) && !empty(meta)) ? meta : new \stdClass),
            this->getUsername(),
            this->getPassword()
        ];

        return message;
    }

    protected function getMetaAttributes()
    {
        return this->meta_attributes;
    }
}