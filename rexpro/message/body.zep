namespace Rexpro\Message;

abstract class Body
{
    protected session {
        set, get
    };
    protected request {
        set, get
    };
    protected meta {
        get
    };

    public function setMeta(array meta)
    {
        var invalid_keys;

        let invalid_keys = [];
        var attribute;
        var value;

        for attribute, value in meta {
            if (!in_array(attribute, this->getMetaAttributes())) {
                let invalid_keys[] = attribute;
            }
        }

        if (count(invalid_keys)) {
            throw new \InvalidArgumentException(
                sprintf("%s doesn\'t accept the meta data %s",
                get_called_class(),
                implode(", ", invalid_keys)
            ));
        }

        let this->meta = meta;

        return this;
    }

    abstract protected function getMetaAttributes();
}
