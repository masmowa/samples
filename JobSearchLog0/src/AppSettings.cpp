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
#include "FileUtility.h"

#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;
namespace tx = tinyxml2;

const char* AppSettings::m_app_settings_block_name           = "WorksourceActivityUser";
const char* AppSettings::m_app_settings_next_primary_key_val = "NextPrimaryKeyValue";
const char* AppSettings::m_worksource_log_path_key           = "WorksourceLogPath";

const char* AppSettings::DEFAULT_EXT="xml";
const char* AppSettings::DEFAULT_NAME="Settings";

AppSettings::AppSettings(const char* settings_path, const char* settings_file_name, const char* ext)
: m_settings_path(settings_path)
, m_settings_file_name(settings_file_name)
, m_NextPrimaryKeyValue(0)
, m_name(AppSettings::m_app_settings_block_name)

{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;

    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
    // initialize vectors of names for prompting
    this->InitializeKeysPersonalInfo();
    this->InitializeKeysDataStoragePathKeys();
    this->InitializeDataPrimarytKeysKeys();
    this->InitializeDataMapCategoryDataKeys();

    m_map_category_keys["User-Information"] = m_personal_info_keys;
    m_map_category_keys["Primary-Key"] = m_data_primary_key_keys;
    m_map_category_keys["Data-Storage-Path"] = m_data_storage_path_keys;

    this->m_map_category_data["User-Information"] = this->m_map_user_info;
    this->m_map_category_data["Primary-Key"] = this->m_map_data_primary_key;
    this->m_map_category_data["Data-Storage-Path"] = this->m_map_data_storage_path;

    fs::path filename(m_settings_file_name);
    filename.replace_extension(ext);

    m_settings_file_name = filename.string();
    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
}

AppSettings::~AppSettings()
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;
    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
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

void AppSettings::set_data_storage_path_value(const char* key, const char* val)
{
    if (!key) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'key' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());

    }
    if (!val) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'val' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());

    }
    m_map_data_storage_path[key] = val;
}

std::string& AppSettings::PathToSettingsFile()
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << std::endl;

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
    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
    return m_settings_file_path;
}

void AppSettings::BuildFullFilePath(const char* in_path, const char* suffix, const char* ext)
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;
    if (!suffix) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'suffix' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    if (!in_path) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'in_path' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    if (!ext) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'ext' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    std::string filename = FileUtility::FileNameFromParts(
                                                       FileUtility::BaseFileNameFromExePath(in_path).c_str(),
                                                       suffix,
                                                       AppSettings::DEFAULT_EXT
                                                       );
    this->SetSettingsFileName(filename.c_str());
    this->SetSettingsPath(fs::current_path().string().c_str());

    fs::path full_path = fs::current_path() / filename;

    std::cout << "full path " << full_path.string() << std::endl;

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
}
bool AppSettings::Load()
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;
    bool result = false;

    std::string filepath = this->PathToSettingsFile();

    tx::XMLDocument doc;
    if (fs::exists(filepath.c_str())) {
        if (doc.LoadFile((filepath.c_str())) != tx::XML_SUCCESS) {
            std:cerr << "ERROR while loading [" << filepath << "]" << std::endl;
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
            m_map_user_info.clear(); // trash existing table

            pElem=hRoot.FirstChildElement( "User-Information" ).FirstChild().ToElement();
            for( pElem; pElem; pElem=pElem->NextSiblingElement())
            {
                const char *pKey=pElem->Value();
                const char *pText=pElem->GetText();
                if (pKey && pText)
                {
                    m_map_user_info[pKey]=pText;
                }
            }
            result = (m_map_user_info.size() > 0);
        }
        {
            pElem = hRoot.FirstChildElement( "Next-Primary-Key" ).ToElement();

            if (!pElem) {
                std::cerr << "WARNING: did not find element [" << "Next-Primary-Key" << "]" << std::endl;
                return false;
            }

            if (pElem->QueryUnsignedText(&m_NextPrimaryKeyValue) != tx::XML_SUCCESS) {
                std::cerr << "ERROR unable to get unsigned int value [" << pElem->Value() << "] text[" << pElem->GetText() << "]" << std::endl;
                return false;
            }
        }
        {
            pElem = hRoot.FirstChildElement( "Data-Storage-Path" ).ToElement();

            if (!pElem) {
                std::cerr << "WARNING: did not find element [" << "Data-Storage-Path" << "]" << std::endl;
                return false;
            }
            std::string txt = pElem->GetText();
            const char *pKey=pElem->Value();
                const char *pText=pElem->GetText();
            try {
                set_data_storage_path_value( pKey, pText );
            }
            catch (std::invalid_argument & e) {
                std::cerr << e.what();
                return false;
            }
        }

    }
    else {
        std::cout << "WARNING: NO settings file [" << filepath << "]" << std::endl;
        return false;
    }

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
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

	// create the container element
	tx::XMLElement * root = doc.NewElement(m_name.c_str());
	doc.LinkEndChild( root );

	// add a comment, for fun.
	s=" Settings for "+m_name+" ";
	comment = doc.NewComment(s.c_str());
	root->LinkEndChild( comment );

	// block: UserData
    //USER_INFO_MAP::iterator iter;
	{

		tx::XMLElement * usr_info = doc.NewElement( "User-Information" );
		root->LinkEndChild( usr_info );

//		for (auto& iter=m_user_info_map.begin(); iter != m_user_info_map.end(); iter++)
		for (auto& iter : m_map_user_info)
		{
			const std::string & key=iter.first;
			const std::string & value=iter.second;
			tx::XMLElement * data = doc.NewElement(key.c_str());
			data->LinkEndChild( doc.NewText(value.c_str()));
			usr_info->LinkEndChild( data );
		}
		root->LinkEndChild(usr_info);
	}
	{
	    // container XML ELEMENT <name> ... </name>
	    tx::XMLElement * mkey = doc.NewElement( "Next-Primary-Key" );
	    // first convert numeric value to "text"
	    //std::stringstream ss;
	    //ss << this->GetNextPrimaryKeyValue();
	    AppSettings::DATA_MAP& map_pkv = this->get_map_primary_key();
	    for (auto & kv : map_pkv) {
			const std::string & key=kv.first;
			const std::string & value=kv.second;
			tx::XMLElement * npke = doc.NewElement(key.c_str());
            npke->LinkEndChild(doc.NewText(value.c_str()));
            mkey->LinkEndChild(npke);
	    }
	    //auto autoVal = this->GetNextPrimaryKeyValue();
	    // inner-text <e>inner-text</e>
	    //mkey->SetText(autoVal);
	    // add to list in proper place
	    //root->LinkEndChild( mkey );
	    {
	        DATA_MAP& dspm = this->get_map_data_storage_path();
	        // create the element container
	        tx::XMLElement * xtel = doc.NewElement("Data-Storage-Path");
	        for (auto & dspi : dspm) {
                // create the new wlement
                tx::XMLElement* dspme = doc.NewElement(dspi.first.c_str());
                // add text to new data-storage-path element
                dspme->LinkEndChild(doc.NewText(dspi.second.c_str()));
                // add new child element to "data-storage-element
                xtel->LinkEndChild(dspme);
	        }
	    }
	}
    std::string filepath = PathToSettingsFile();

	std::cout << "writing document to " << this->m_settings_file_path << std::endl;
	doc.SaveFile(this->m_settings_file_path.c_str());

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
}

void AppSettings::DumpUserData(std::ostream &os)
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;

    AppSettings::DATA_MAP::iterator iter;
    for (iter = this->get_user_info_map().begin(); iter != this->get_user_info_map().end(); ++iter ) {
        os << iter->first << ": [ " << iter->second << " ]" << std::endl;
    }

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
}
void AppSettings::DumpAppSettings(std::ostream &os)
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;

    AppSettings::DATA_MAP::iterator iter;
    os << this->m_app_settings_next_primary_key_val << " : [ " << this->GetNextPrimaryKeyValue() << " ]" << std::endl;
    os << this->m_worksource_log_path_key  << " : [ " << this->m_worksource_log_path << " ]" << std::endl;

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
}
void AppSettings::Dump(std::ostream &os)
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;

    os << "\nvalues currently stored in " << this->get_name() << std::endl;
    for (auto& cat_kv : m_map_category_data) {
        os << "category key [" << cat_kv.first << "]" << std::endl;
        DATA_MAP dm = cat_kv.second;

        os << "map for category:len [" << cat_kv.first << " : " << dm.size() << "]" << std::endl;
        for (auto& dm_kv : dm) {
            os << "key:val [" << dm_kv.first << " : " << dm_kv.second << "]" << std::endl;
            //DumpValuesFromUser(os, category_key, key);
        }
    }

    this->DumpUserData(os);
    this->DumpAppSettings(os);

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
}
