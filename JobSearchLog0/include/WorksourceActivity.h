#ifndef WORKSOURCEACTIVITY_H
#define WORKSOURCEACTIVITY_H
#include <string>


class WorksourceActivity
{
    public:
        WorksourceActivity();
        WorksourceActivity(const WorksourceActivity &other);
        WorksourceActivity& operator=(const WorksourceActivity &other);
        virtual ~WorksourceActivity();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }
        std::string GetActivityName() { return m_ActivityName; }
        void SetActivityName(std::string val) { m_ActivityName = val; }
        std::string GetInstructor() { return m_Instructor; }
        void SetInstructor(std::string val) { m_Instructor = val; }
        std::string GetAddress() { return m_Address; }
        void SetAddress(std::string val) { m_Address = val; }
        std::string Getcity() { return m_city; }
        void Setcity(std::string val) { m_city = val; }
        std::string Getstate() { return m_state; }
        void Setstate(std::string val) { m_state = val; }
        std::string Getzip() { return m_zip; }
        void Setzip(std::string val) { m_zip = val; }
        unsigned int Gettype() { return m_type; }
        void Settype(unsigned int val) { m_type = val; }

    protected:

    private:
        unsigned int m_Counter;
        std::string m_ActivityName;
        std::string m_Instructor;
        std::string m_Address;
        std::string m_city;
        std::string m_state;
        std::string m_zip;
        unsigned int m_type;
};

#endif // WORKSOURCEACTIVITY_H
