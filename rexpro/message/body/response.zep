namespace Rexpro\Message\Body;

abstract class Response extends \Rexpro\Message\Body
{
    public function __construct(raw = null)
    {
        if !empty raw {
            this->hydrate(raw);
        }
    }

    abstract public function toArray();
    abstract protected function hydrate(raw);
}
