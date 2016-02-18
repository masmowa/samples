#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <map>
#include <list>

#include "WindowSettings.h"
#include "ConnectionSettings.h"

typedef std::map<std::string, std::string> MessageMap;

class AppSettings
{
    public:

        /** Default constructor */
        AppSettings();
        /** Default destructor */
        virtual ~AppSettings();

        /** Access m_name
         * \return The current value of m_name
         */
        std::string get_name() { return m_name; }
        /** Set m_name
         * \param val New value to set
         */
        void set_name(std::string val) { m_name = val; }
        /** Access m_messages
         * \return The current value of m_messages
         */
        MessageMap& get_messages() { return m_messages; }
        /**set_ m_messages
         * \param val New value to set
         */
        void set_messages(MessageMap val) { m_messages = val; }
        /**set_ m_messages
         * \param val New value to set
         */
        void set_message(const std::string& name,const std::string& val) { m_messages[name.c_str()] = val.c_str(); }
        /** Access m_windows
         * \return The current value of m_windows
         */
        std::list<WindowSettings>& get_windows() { return m_windows; }
        /** Set m_windows
         * \param val New value to set
         */
        void set_windows(std::list<WindowSettings>& val) { m_windows = val; }
        /** Access m_connection
         * \return The current value of m_connection
         */
        ConnectionSettings& get_connection() { return m_connection; }
        /** Set m_connection
         * \param val New value to set
         */
        void set_connection(ConnectionSettings val) { m_connection = val; }

        void save(const char* pFilename);
        void load(const char* pFilename);

        // just to show how to do it
        void setDemoValues()
        {
            m_name="MyApp";
            m_messages.clear();
            m_messages["Welcome"]="Welcome to "+m_name;
            m_messages["Farewell"]="Thank you for using "+m_name;
            m_windows.clear();
            m_windows.push_back(WindowSettings("Main",15,15,400,250));
            m_connection.Set_ip("Unknown");
            m_connection.Set_timeout(123.456);
        }
    protected:

    private:
        std::string m_name; //!< Member variable "m_name"
        MessageMap m_messages; //!< Member variable "m_messages"
        std::list<WindowSettings> m_windows; //!< Member variable "m_windows"
        ConnectionSettings m_connection; //!< Member variable "m_connection"
};

#endif // APPSETTINGS_H
