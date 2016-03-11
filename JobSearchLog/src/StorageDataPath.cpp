#include "StorageDataPath.h"
#include "dbg_Utility.h"

// path to where the XML files are stored
const char* StorageDataPath::xml_section_name = "Data-Storage-Path";

StorageDataPath::StorageDataPath()
: basic_STORAGE(xml_section_name)
{
    //ctor
    this->Init();
    this->TestDataInit();
}

StorageDataPath::~StorageDataPath()
{
    //dtor
}

bool StorageDataPath::ToXML(tinyxml2::XMLDocument* pdoc, tinyxml2::XMLElement * proot)
{
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
    bool result=false;

    tinyxml2::XMLElement* pElem = pdoc->NewElement(this->m_name.c_str());

    // add comment about contents
    std::string s = " Elements of " + m_keys[0] + " ";
    tinyxml2::XMLComment * comment = pdoc->NewComment(s.c_str());
    pElem->LinkEndChild(comment);

    // add items from dictionary
    for (auto & iter : this->m_data) {
        tinyxml2::XMLElement* pData = pdoc->NewElement(iter.first.c_str());
        pData->LinkEndChild(pdoc->NewText(iter.second.c_str()));
        pElem->LinkEndChild(pData);
    }
    comment = pdoc->NewComment(" End of Element ");
    pElem->LinkEndChild(comment);

    dbg_Utility::print_xml_element(pElem);

	(proot)->LinkEndChild(pElem);

    dbg_Utility::print_xml_element(pElem);

    return result;
}
