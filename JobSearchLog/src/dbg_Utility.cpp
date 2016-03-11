#include "dbg_Utility.h"

dbg_Utility::dbg_Utility()
{
    //ctor
}

dbg_Utility::~dbg_Utility()
{
    //dtor
}

void dbg_Utility::print_xml_element(const std::string& message, tinyxml2::XMLElement* proot)
{
    if (!message.empty()) {
        std::cout << message << std::endl;
    }
    tinyxml2::XMLPrinter printer;
    proot->Accept(&printer);
    std::cout << printer.CStr() << std::endl;
}
void dbg_Utility::print_xml_element(tinyxml2::XMLElement* proot)
{
    dbg_Utility::print_xml_element(std::string(""), proot);
}
void dbg_Utility::print_xml_element(const char* message, tinyxml2::XMLElement* proot)
{
    dbg_Utility::print_xml_element(std::string(message), proot);
}
