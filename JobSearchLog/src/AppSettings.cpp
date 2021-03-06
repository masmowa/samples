#include <iostream>
#include "tinyxml2.h"
#include "AppSettings.h"
#include "dbg_Utility.h"
#include "UserInfo.h"
#include "PrimaryKey.h"
#include "StorageDataPath.h"

const char* AppSettings::DEFAULT_NAME="Settings";
const char* AppSettings::DEFAULT_EXT="xml";

const char* AppSettings::xml_section_name                    = "Application-Settings";


AppSettings::AppSettings(const char* filepath)
: basic_STORAGE(AppSettings::xml_section_name)
, m_filepath(filepath)
, m_force_save(false)
{
    //ctor
}

AppSettings::~AppSettings()
{
    //dtor
}

bool AppSettings::Save(const char* filepath)
{
    //dtor
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "TO: " << this->m_filepath << std::endl;
    tinyxml2::XMLError xmlResult = tinyxml2::XML_SUCCESS;

    tinyxml2::XMLDocument doc;

    xmlResult = doc.SaveFile(this->m_filepath.c_str());

    if (xmlResult != tinyxml2::XML_SUCCESS) {
        this->SaveDefault();
    }

    return (xmlResult == tinyxml2::XML_SUCCESS);
}

bool AppSettings::Load(const char* filepath)
{
    //dtor
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "TO: " << this->m_filepath << std::endl;
    tinyxml2::XMLError xmlResult = tinyxml2::XML_SUCCESS;

    tinyxml2::XMLDocument doc;

    xmlResult = doc.LoadFile(this->m_filepath.c_str());

    return (xmlResult == tinyxml2::XML_SUCCESS);
}

tinyxml2::XMLError AppSettings::SaveDefault(const char* filepath)
{
    //
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "TO: " << this->m_filepath << std::endl;
    tinyxml2::XMLError xmlResult = tinyxml2::XML_SUCCESS;
    tinyxml2::XMLDocument doc;

    tinyxml2::XMLDeclaration* decl = doc.NewDeclaration();
    doc.InsertEndChild(decl);
    tinyxml2::XMLElement* root = doc.NewElement(this->m_name.c_str());
    doc.InsertEndChild(root);
	// add a comment, for fun.
	std::string s = " Settings for "+m_name+" ";
	tinyxml2::XMLComment* comment = doc.NewComment(s.c_str());
	root->LinkEndChild( comment );

	dbg_Utility::print_xml_element("befor user data", root);

	m_user_info.ToXML(&doc, root);

    dbg_Utility::print_xml_element("after user data", root);

    this->m_primary_key.ToXML(&doc, root);
    dbg_Utility::print_xml_element("after Primary key", root);

    this->m_storage_data_path.ToXML(&doc, root);
    dbg_Utility::print_xml_element("after Storage Data Path", root);

    xmlResult = doc.SaveFile(this->m_filepath.c_str());

    return (xmlResult); // == tinyxml2::XML_SUCCESS);
}

