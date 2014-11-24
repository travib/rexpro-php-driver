namespace Rexpro\Message\Body\Request;


class Script extends \Rexpro\Message\Body\Request
{

    private languageName = "groovy" {
        set, get
    };
    private script {
        set, get
    };
    private bindings {
        set, get
    };
    private meta_attributes = [
        "inSession",
        "isolate",
        "transaction",
        "graphName",
        "graphObjName",
        "console"
    ];

    public function __construct() {
        parent::__construct();
    }

    public function toArray()
    {
        var bindings;
        var meta;

        let bindings = this->getBindings();
        let meta     = this->getMeta();

        var message;

        let message = [
            this->getSession(),
            this->getRequest(),
            ((is_array(meta) && !empty(meta)) ? meta : new \stdClass),
            this->getLanguageName(),
            this->getScript(),
            ((is_array(bindings) && !empty(bindings)) ? bindings : new \stdClass)
        ];

        return message;
    }

    protected function getMetaAttributes()
    {
        return this->meta_attributes;
    }
}