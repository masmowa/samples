#ifndef CONTACTORJOBSEARCHACTIVITY_H
#define CONTACTORJOBSEARCHACTIVITY_H
#include <string>
#include "EmployerContact.h"
#include "WorksourceActivity.h"

class ContactOrJobSearchActivity
{
    public:
        ContactOrJobSearchActivity();
        ContactOrJobSearchActivity(const ContactOrJobSearchActivity &other);
        ContactOrJobSearchActivity& operator=(const ContactOrJobSearchActivity &other);
        virtual ~ContactOrJobSearchActivity();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }
        std::string GetDate() { return m_Date; }
        void SetDate(std::string val) { m_Date = val; }
        unsigned int GetActivityType() { return m_ActivityType; }
        void SetActivityType(unsigned int val) { m_ActivityType = val; }
        unsigned int GetContactActivityType() { return m_ContactActivityType; }
        void SetContactActivityType(unsigned int val) { m_ContactActivityType = val; }
        EmployerContact& GetEmployerContact() { return m_EmployerContact; }
        void SetEmployerContact(EmployerContact& val) { m_EmployerContact = val; }
        WorksourceActivity& GetWorksourceActivity() { return m_WorksourceActivity; }
        void SetWorksourceActivity(WorksourceActivity& val) { m_WorksourceActivity = val; }

    protected:

    private:
        unsigned int m_Counter;
        std::string m_Date;
        unsigned int m_ActivityType;
        unsigned int m_ContactActivityType;
        EmployerContact m_EmployerContact;
        WorksourceActivity m_WorksourceActivity;
};

#endif // CONTACTORJOBSEARCHACTIVITY_H
