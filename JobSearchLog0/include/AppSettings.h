#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <string>
#include <map>
#include <list>

class AppSettings
{
public:
        typedef std::map<std::string, std::string> USER_INFO_MAP;
        typedef std::map<std::string, std::string> APP_SETTINGS_MAP;
        const char* default_ext="xml";

        static const char * m_user_info_keys[];
        static const char* m_app_settings_block_name;
    public:
        AppSettings(const char* settings_path="", const char* settings_file_name="AppSettings.xml");
        virtual ~AppSettings();
        AppSettings(const AppSettings& other);
        AppSettings& operator=(const AppSettings& other);

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

        unsigned int GetNextPrimaryKeyValue() { return m_NextPrimaryKeyValue; }
        void SetNextPrimaryKeyValue(unsigned int val) { m_NextPrimaryKeyValue = val; }

        USER_INFO_MAP& Getuser_info_map() { return m_user_info_map; }
        void Setuser_info_map(USER_INFO_MAP& val) { m_user_info_map = val; }

        APP_SETTINGS_MAP& Getapp_settings_map() { return m_app_settings_map; }
        void Setapp_settings_map(APP_SETTINGS_MAP& val) { m_app_settings_map = val; }

        std::string& GetSettingsPath() { return m_settings_path; }
        void SetSettingsPath(const char* path) { m_settings_path = path; }

        std::string& get_name() { return m_settings_path; }
        void set_name(const char* val) { m_settings_path = val; }

        std::string& GetSettingsFileName() { return m_settings_file_name; }
        void SetSettingsFileName(const char* val) { m_settings_file_name = val; }
        void BuildFullFilePath(const char* suffix="_AppSettings", const char* in_path);

        std::string& get_worksource_log_path() { return m_worksource_log_path; }
        void set_worksource_log_path(const char* val) { m_worksource_log_path = val; }

        std::string GetSettingsFilePath() { return PathToSettingsFile(); }

        static void PathFromExePath(AppSettings& context, const char* path);

        bool Load(const char* path);
        void Save();
        void Dump(std::ostream &os);
        void DumpUserData(std::ostream &os);
        void DumpAppSettings(std::ostream &os);

        void PromptForUserData();

    protected:
        std::string& PathToSettingsFile();

        std::string m_settings_file_path;
    private:

        unsigned int m_Counter;
        unsigned int m_NextPrimaryKeyValue;
        USER_INFO_MAP m_user_info_map;
        APP_SETTINGS_MAP m_app_settings_map;
        std::string m_name;
        std::string m_settings_path;
        std::string m_settings_file_name;
        std::string m_worksource_log_path;
};

#endif // APPSETTINGS_H
