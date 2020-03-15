#ifndef EXAMPLEWITHCOPYCONSTRUCTOR_H
#define EXAMPLEWITHCOPYCONSTRUCTOR_H
#include <string>


class exampleWithCopyConstructor
{
    public:
        exampleWithCopyConstructor();
        virtual ~exampleWithCopyConstructor();
        exampleWithCopyConstructor(const exampleWithCopyConstructor& other);
        exampleWithCopyConstructor& operator=(const exampleWithCopyConstructor& other);

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }
        std::string& Getname() { return m_name; }
        void Setname(std::string val) { m_name = val.c_str(); }
        std::string& Getdate() { return m_date; }
        void Setdate(std::string val) { m_date = val.c_str(); }
        std::string& Gettime() { return m_time; }
        void Settime(std::string& val) { m_time = val.c_str(); }

    protected:

    private:
        unsigned int m_Counter;
        std::string m_name;
        std::string m_date;
        std::string m_time;
};

#endif // EXAMPLEWITHCOPYCONSTRUCTOR_H
