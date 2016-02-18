#include "ConnectionSettings.h"

ConnectionSettings::ConnectionSettings(std::string ip, const double to)
: _ip(ip)
, _timeout(to)
{
    //ctor
}

ConnectionSettings::~ConnectionSettings()
{
    //dtor
}
