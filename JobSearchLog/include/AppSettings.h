#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <basic_STORAGE.h>
#include <string>
#include <map>
#include <list>
#include <boost/assign.hpp>
#include <algorithm>    // std::copy

#include "UserInfo.h"


class AppSettings : public basic_STORAGE
{
public:
    static const char* DEFAULT_EXT;
    static const char* DEFAULT_NAME;

    static const char* m_app_settings_next_primary_key_val;
    static const char* m_worksource_log_path_key;
    static const char* xml_section_name;

    public:
        AppSettings(const char * filepath);
        virtual ~AppSettings();

    virtual std::string& get_value(const std::string& key) { return m_data[key]; }
    virtual void set_value(const std::string& key, const std::string& val) { m_data[key] = val; }


    virtual void Init() { InitKeys(); }
    virtual void InitKeys() {
        std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
        boost::assign::push_back(m_keys)(this->m_name);
    }
    virtual bool ToXML(tinyxml2::XMLDocument* pdoc, tinyxml2::XMLElement* proot) { return false; };

    virtual bool Load(const char* filepath=nullptr);
    virtual bool Save(const char* filepath=nullptr);
    tinyxml2::XMLError SaveDefault(const char* filepath=nullptr);

    void set_force_save(bool val) { this->m_force_save = val; }
    bool get_force_save() { return this->m_force_save; }

    protected:
        void TestDataInit() {
            this->set_value("name", "john Doe");
            this->set_value("address", "123 Main");
            this->set_value("city", "Monroe");
            this->set_value("state", "WA");
            this->set_value("ZIP", "98272");
        }

    private:
        std::string m_filepath;
        bool m_force_save;
};

#endif // APPSETTINGS_H
