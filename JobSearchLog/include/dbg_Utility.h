#ifndef DBG_UTILITY_H
#define DBG_UTILITY_H
#include <iostream>
#include "tinyxml2.h"
#include <string>


class dbg_Utility
{
    public:
        dbg_Utility();
        virtual ~dbg_Utility();
        static void print_xml_element(tinyxml2::XMLElement* proot);
        static void print_xml_element(const char* message, tinyxml2::XMLElement* proot);
        static void print_xml_element(const std::string& message, tinyxml2::XMLElement* proot);

    protected:

    private:
};

#endif // DBG_UTILITY_H
