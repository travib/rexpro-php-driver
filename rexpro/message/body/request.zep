namespace Rexpro\Message\Body;

abstract class Request extends \Rexpro\Message\Body
{
    protected default_uuid = "00000000-0000-0000-0000-000000000000";

    public function __construct()
    {
        this->setSession(this->default_uuid);
        this->setRequest(this->createUuid());
    }

    protected function createUuid()
    {
        return sprintf( "%04x%04x-%04x-%04x-%04x-%04x%04x%04x",
            mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ),
            mt_rand( 0, 0xffff ),
            mt_rand( 0, 0x0fff ) | 0x4000,
            mt_rand( 0, 0x3fff ) | 0x8000,
            mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff )
        );
    }

    abstract public function toArray();
}
