#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tinyxml2.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "AppSettings.h"
#include "tinyxml2.h"
#include "FileLocation.h"

#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;
namespace tx = tinyxml2;

const char * AppSettings::m_user_info_keys[] = {
    "UserName",
    "SSN",
    "Address",
    "City",
    "State",
    "ZIP",
    "Home-phone",
    "Mobile-phone",
    ""
};
const char* AppSettings::m_app_settings_block_name = "WorksourceActivityUser";
const char* AppSettings::m_app_settings_next_primary_key_val = "NextPrimaryKeyValue";
const char* AppSettings::m_worksource_log_path_key = "WorksourceLogPath";

AppSettings::AppSettings(const char* settings_path, const char* settings_file_name)
: m_settings_path(settings_path)
, m_settings_file_name(settings_file_name)
, m_NextPrimaryKeyValue(0)
, m_name(AppSettings::m_app_settings_block_name)

{
    //ctor
}

AppSettings::~AppSettings()
{
    //dtor
}

AppSettings::AppSettings(const AppSettings& other)
{
    //copy ctor
}

AppSettings& AppSettings::operator=(const AppSettings& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
std::string& AppSettings::PathToSettingsFile()
{
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;

    {
        fs::path dir(this->GetSettingsPath().c_str());
        fs::path file(this->GetSettingsFileName().c_str());
        fs::path full_path = dir / file;

        std::cout << "dir      : " << this->GetSettingsPath().c_str() << std::endl;
        std::cout << "file     : " << this->GetSettingsFileName().c_str() << std::endl;
        std::cout << "full_path: " << full_path.string().c_str() << std::endl;

        m_settings_file_path = full_path.string();
    }
    {
        std::cout << "path      [ " << this->GetSettingsPath().c_str() << " ] file [ " << m_settings_file_name  << " ]" << std::endl;
        std::cout << "file_path [ " << this->m_settings_file_path.c_str() << " ]" << std::endl;

    }
    return m_settings_file_path;
}

void AppSettings::PathFromExePath(AppSettings& context, const char* in_path)
{
    std::cout << "++" << __PRETTY_FUNCTION__ << " in_path     : " << in_path << std::endl;
    fs::path exe_path(in_path);
    std::cout << "path::exe_path [" << exe_path << "]" << std::endl;

    fs::path dir(exe_path.branch_path());
    std::cout << "path::branch_path [" << dir << "]" << std::endl;
    fs::path cur_dir( fs::current_path() );
    std::cout << "path::current_path [" << fs::current_path() << std::endl;
    context.SetSettingsPath(fs::current_path().string().c_str());

    fs::path filename(fs::basename(exe_path));
    std::stringstream fnAppSettings;
    fnAppSettings << filename.string().c_str()<< "_AppSettings";
    std::cout << "path::filename [" << filename << "]" << std::endl;
    std::cout << "str:filename_AppSettings [" << fnAppSettings.str().c_str() << "]" << std::endl;
    filename = fnAppSettings.str().c_str();
    fs::path ext(exe_path.extension());
    std::cout << "path::extension [" << ext << "]" << std::endl;

    context.SetSettingsFileName(filename.replace_extension(context.default_ext).string().c_str());

    std::cout << "path::filename_with_extension [ " << filename << " ]\n" << std::endl;

}
void AppSettings::BuildFullFilePath(const char* suffix, const char* in_path)
{
    if (!suffix) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'suffix' "
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    std::string filename = FileLocation::FileNameFromBaseSuffix(
                                                                FileLocation::BaseFileNameFromExePath(in_path))
}
bool AppSettings::Load(const char* in_path)
{
    bool result = false;

    fs::path full_path(in_path);
    tx::XMLDocument doc;
    if (fs::exists(in_path)) {
        if (doc.LoadFile((in_path)) != tx::XML_SUCCESS) {
            std:cerr << "ERROR while loading [" << in_path << "]" << std::endl;
            return false;
        }
        tx::XMLHandle hDoc(&doc);
        tx::XMLElement* pElem;
        tx::XMLHandle hRoot(0);

        // block: name
        {
            pElem=hDoc.FirstChildElement().ToElement();
            // should always have a valid root but handle gracefully if it does
            if (!pElem) return result;
            m_name=pElem->Value();

            // save this for later
            hRoot = tx::XMLHandle(pElem);
        }

        // block: string table
        {
            m_user_info_map.clear(); // trash existing table

            pElem=hRoot.FirstChildElement( "UserInformation" ).FirstChild().ToElement();
            for( pElem; pElem; pElem=pElem->NextSiblingElement())
            {
                const char *pKey=pElem->Value();
                const char *pText=pElem->GetText();
                if (pKey && pText)
                {
                    m_user_info_map[pKey]=pText;
                }
            }
            result = (m_user_info_map.size() > 0);
        }
        {
            pElem = hRoot.FirstChildElement( "NextPrimaryKeyValue" ).ToElement();

            if (!pElem) {
                std::cerr << "WARNING: did not find element [" << "NextPrimaryKeyValue" << "]" << std::endl;
                return false;
            }

            if (pElem->QueryUnsignedText(&m_NextPrimaryKeyValue) != tx::XML_SUCCESS) {
                std::cerr << "ERROR unable to get unsigned int value [" << pElem->Value() << "] text[" << pElem->GetText() << "]" << std::endl;
                return false;
            }
        }

    }
    else {
        std::cout << "WARNING: NO settings file [" << in_path << "]" << std::endl;
        return false;
    }

    return true;
}

void AppSettings::Save()
{
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
//    return m_settings_file_path;
	tx::XMLDocument doc;
	tx::XMLElement* msg;
	tx::XMLComment * comment;
	string s;

 	tx::XMLDeclaration* decl = doc.NewDeclaration();
	doc.LinkEndChild( decl );

	tx::XMLElement * root = doc.NewElement(m_name.c_str());
	doc.LinkEndChild( root );

	s=" Settings for "+m_name+" ";
	comment = doc.NewComment(s.c_str());
	root->LinkEndChild( comment );

	// block: UserData
    //USER_INFO_MAP::iterator iter;
	{

		tx::XMLElement * msgs = doc.NewElement( "UserInformation" );
		root->LinkEndChild( msgs );

//		for (auto& iter=m_user_info_map.begin(); iter != m_user_info_map.end(); iter++)
		for (auto& iter : m_user_info_map)
		{
			const std::string & key=iter.first;
			const std::string & value=iter.second;
			msg = doc.NewElement(key.c_str());
			msg->LinkEndChild( doc.NewText(value.c_str()));
			msgs->LinkEndChild( msg );
		}
	}
	{
	    // container XML ELEMENT <name> ... </name>
	    tx::XMLElement * mkey = doc.NewElement( "NextPrimaryKeyValue" );
	    // first convert numeric value to "text"
	    //std::stringstream ss;
	    //ss << this->GetNextPrimaryKeyValue();
	    auto autoVal = this->GetNextPrimaryKeyValue();
	    // inner-text <e>inner-text</e>
	    mkey->SetText(autoVal);
	    // add to list in proper place
	    root->LinkEndChild( mkey );
	}
    std::string filepath = PathToSettingsFile();

	std::cout << "writing document to " << this->m_settings_file_path << std::endl;
	doc.SaveFile(this->m_settings_file_path.c_str());

}

void AppSettings::PromptForUserData()
{
    std::string in_str;
    std::string item_str;
    for ( size_t i = 0; AppSettings::m_user_info_keys[i] != ""; ++i ) {
        std::cout << "Enter a value for " << AppSettings::m_user_info_keys[i] << " : ";
        getline (cin, in_str);
        this->m_user_info_map[AppSettings::m_user_info_keys[i]] = in_str;
        //std::cout << std::endl;
    }
}

void AppSettings::DumpUserData(std::ostream &os)
{
    AppSettings::USER_INFO_MAP::iterator iter;
    for (iter = this->Getuser_info_map().begin(); iter != this->Getuser_info_map().end(); ++iter ) {
        os << iter->first << ": [ " << iter->second << " ]" << std::endl;
    }
}
void AppSettings::DumpAppSettings(std::ostream &os)
{
    AppSettings::USER_INFO_MAP::iterator iter;
    os << this->m_app_settings_next_primary_key_val << " : [ " << this->GetNextPrimaryKeyValue() << " ]" << std::endl;
    os << this->m_worksource_log_path_key  << " : [ " << this->m_worksource_log_path << " ]" << std::endl;
}
void AppSettings::Dump(std::ostream &os)
{
    os << "\nvalues currently stored in " << this->get_name() << std::endl;

    this->DumpUserData(os);
    this->DumpAppSettings(os);
}
