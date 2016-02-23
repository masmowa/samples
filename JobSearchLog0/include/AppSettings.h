#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <string>
#include <map>
#include <list>
#include <boost/assign.hpp>
#include <algorithm>    // std::copy

namespace basn = boost::assign;

/*!
 * MAP data name (key) to the data value
 */


/** \brief contain steady state settings for the application
 */
class AppSettings
{
public:
        typedef std::map<std::string, std::string> DATA_MAP;
        typedef std::map<std::string, std::map<std::string, std::string> > DATA_MAP_BY_CATAGORY;
        typedef std::vector<std::string> KEY_WORD_VECTOR;
        typedef std::map<std::string, std::vector<std::string> > MAP_KEY_WORD_VECTOR;
        static const char* DEFAULT_EXT;
        static const char* DEFAULT_NAME;

        static const char * m_user_info_keys[];

        static const char* m_app_settings_next_primary_key_val;
        static const char* m_worksource_log_path_key;
        static const char* m_app_settings_block_name;
    public:
        AppSettings(const char* settings_path="", const char* settings_file_name=AppSettings::DEFAULT_NAME, const char* ext=AppSettings::DEFAULT_EXT);
        virtual ~AppSettings();
        AppSettings(const AppSettings& other);
        AppSettings& operator=(const AppSettings& other);

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

        unsigned int GetNextPrimaryKeyValue() { return m_NextPrimaryKeyValue; }
        void SetNextPrimaryKeyValue(unsigned int val) { m_NextPrimaryKeyValue = val; }

        DATA_MAP& Getuser_info_map() { return m_map_user_info; }
        void Setuser_info_map(DATA_MAP& val) { m_map_user_info = val; }

        DATA_MAP& Getapp_settings_map() { return m_app_settings_map; }
        void Setapp_settings_map(DATA_MAP& val) { m_app_settings_map = val; }

        std::string& GetSettingsPath() { return m_settings_path; }
        void SetSettingsPath(const char* path) { m_settings_path = path; }

        std::string& get_name() { return m_settings_path; }
        void set_name(const char* val) { m_settings_path = val; }

        std::string& GetSettingsFileName() { return m_settings_file_name; }
        void SetSettingsFileName(const char* val) { m_settings_file_name = val; }
        void BuildFullFilePath(const char* in_path, const char* suffix=AppSettings::DEFAULT_NAME, const char* ext=AppSettings::DEFAULT_EXT);

        std::string& get_worksource_log_path() { return m_worksource_log_path; }
        void set_worksource_log_path(const char* val) { m_worksource_log_path = val; }

        std::string GetSettingsFilePath() { return PathToSettingsFile(); }

        //static void PathFromExePath(AppSettings& context, const char* path);

        bool Load();
        void Save();
        void Dump(std::ostream &os);
        void DumpUserData(std::ostream &os);
        void DumpAppSettings(std::ostream &os);

        void PromptForUserData();

        std::vector<std::string>& get_keys_for_category(std::string& key) {
            return m_map_category_keys[key];
        }
        void SetValueInCategory(std::string& category_key, std::string& key, std::string& val) {
            std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
            std::cout << "set category value [" << category_key << "][" << key << "] = " << val << std::endl;
            this->m_map_category_data[category_key][key] = val;
        }
    protected:
        std::string& PathToSettingsFile();

        std::string m_settings_file_path;

        void InitializeKeysPersonalInfo() {
            std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
            basn::push_back(m_personal_info_keys)("First-Name")("Last-Name")("Address")("City")("State")("ZIP")("SSN")("Home-Phone");
        }
        void InitializeKeysDataStoragePathKeys() {
            std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
            basn::push_back(m_data_storage_path_keys)("Data-Storage-Path");

        }
        void InitializeDataPrimarytKeysKeys() {
            basn::push_back(m_data_primary_key_keys)("Next-Primary-Key");
        }
        void InitializeDataMapCategoryDataKeys() {
            std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;

            basn::push_back(m_category_keys)("User-Information")("Primary-Key")("Data-Storage-Path");
        }

    private:

        unsigned int m_Counter;
        unsigned int m_NextPrimaryKeyValue;
        DATA_MAP     m_map_user_info;
        DATA_MAP     m_app_settings_map;

        KEY_WORD_VECTOR m_personal_info_keys;       /**< list of keys of personal information */
        KEY_WORD_VECTOR m_data_storage_path_keys;   /**< key-name of the storage path, where to store the job-search action */
        KEY_WORD_VECTOR m_data_primary_key_keys;    /**< name of primary-key, and any other primary keys */
        KEY_WORD_VECTOR m_category_keys;            /**< list of categories */

        MAP_KEY_WORD_VECTOR m_map_category_keys; /**< Associate category_key to item_keys */

        DATA_MAP_BY_CATAGORY m_map_category_data; /**< map of category data map of maps or map of personal data map of string to string */
        DATA_MAP m_map_data_storage_path;           /**< map of path information for storing data files */
        DATA_MAP m_map_data_primary_key;            /**< map of the primary-key */

        std::string m_name;
        std::string m_settings_path;
        std::string m_settings_file_name;
        std::string m_worksource_log_path;
};

#endif // APPSETTINGS_H
