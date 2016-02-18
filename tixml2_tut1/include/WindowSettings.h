#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H
#include <string>

class WindowSettings
{
    public:
        /** Default constructor */
        WindowSettings( const std::string& name="", unsigned int x=0, unsigned int y=0, unsigned int cx=100, unsigned int cy=100);
        /** Default destructor */
        virtual ~WindowSettings();

        /** Access _x
         * \return The current value of _x
         */
        unsigned int get_x() const { return _x; }
        /** Set _x
         * \param val New value to set
         */
        void Set_x(unsigned int val) { _x = val; }
        /** Access _y
         * \return The current value of _y
         */
        unsigned int get_y() const { return _y; }
        /** Set _y
         * \param val New value to set
         */
        void Set_y(unsigned int val) { _y = val; }
        /** Access _cx
         * \return The current value of _cx
         */
        unsigned int get_cx() const { return _cx; }
        /** Set _cx
         * \param val New value to set
         */
        void Set_cx(unsigned int val) { _cx = val; }
        /** Access _cy
         * \return The current value of _cy
         */
        unsigned int get_cy() const { return _cy; }
        /** Set _cy
         * \param val New value to set
         */
        void Set_cy(unsigned int val) { _cy = val; }
        /** Access _name
         * \return The current value of _name
         */
        std::string& get_name() { return _name; }
        const char* get_name_cs() const { return _name.c_str(); }
        /** Set _name
         * \param val New value to set
         */
        void Set_name(std::string val) { _name = val; }

    protected:

    private:
        unsigned int _x; //!< Member variable "_x"
        unsigned int _y; //!< Member variable "_y"
        unsigned int _cx; //!< Member variable "_cx"
        unsigned int _cy; //!< Member variable "_cy"
        std::string _name; //!< Member variable "_name"
};

#endif // WINDOWSETTINGS_H
