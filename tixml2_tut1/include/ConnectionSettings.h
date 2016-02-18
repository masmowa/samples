#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H
#include <string>

class ConnectionSettings
{
    public:
        /** Default constructor */
        ConnectionSettings(std::string ip="127.0.0.1", const double to=123.456);
        /** Default destructor */
        virtual ~ConnectionSettings();

        /** Access _ip
         * \return The current value of _ip
         */
        std::string get_ip() { return _ip; }
        /** Set _ip
         * \param val New value to set
         */
        void Set_ip(std::string val) { _ip = val; }
        /** Access _timeout
         * \return The current value of _timeout
         */
        double get_timeout() { return _timeout; }
        /** Set _timeout
         * \param val New value to set
         */
        void Set_timeout(double val) { _timeout = val; }

    protected:

    private:
        std::string _ip; //!< Member variable "_ip"
        double _timeout; //!< Member variable "_timeout"
};

#endif // CONNECTIONSETTINGS_H
