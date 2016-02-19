#ifndef EMPLOYERCONTACT_H
#define EMPLOYERCONTACT_H
#include <string>


class EmployerContact
{
    public:
        EmployerContact(unsigned int type=0, const char* position="", unsigned int howcontacted=0, const char* employername="");
        EmployerContact(const EmployerContact &other);
        EmployerContact& operator=(const EmployerContact &other);
        virtual ~EmployerContact();

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }
        unsigned int Gettype() { return m_type; }
        void Settype(unsigned int val) { m_type = val; }
        unsigned int Gethowcontacted() { return m_howcontacted; }
        void Sethowcontacted(unsigned int val) { m_howcontacted = val; }
        std::string Getposition() { return m_position; }
        void Setposition(std::string val) { m_position = val; }
        std::string Getemployername() { return m_employername; }
        void Setemployername(std::string val) { m_employername = val; }
        std::string Getaddress() { return m_address; }
        void Setaddress(std::string val) { m_address = val; }
        std::string Getstate() { return m_state; }
        void Setstate(std::string val) { m_state = val; }
        std::string Getcity() { return m_city; }
        void Setcity(std::string val) { m_city = val; }
        std::string Gettelephone() { return m_telephone; }
        void Settelephone(std::string val) { m_telephone = val; }
        std::string Getfax() { return m_fax; }
        void Setfax(std::string val) { m_fax = val; }
        std::string Getname_or_position_of_person_contacted() { return m_name_or_position_of_person_contacted; }
        void Setname_or_position_of_person_contacted(std::string val) { m_name_or_position_of_person_contacted = val; }
        std::string Getemail() { return m_email; }
        void Setemail(std::string val) { m_email = val; }
        std::string Getweb_site() { return m_web_site; }
        void Setweb_site(std::string val) { m_web_site = val; }
        std::string Getjob_reference_number() { return m_job_reference_number; }
        void Setjob_reference_number(std::string val) { m_job_reference_number = val; }
        std::string Getagency_name() { return m_agency_name; }
        void Setagency_name(std::string val) { m_agency_name = val; }
        std::string Getagency_contact() { return m_agency_contact; }
        void Setagency_contact(std::string val) { m_agency_contact = val; }
        std::string Getnews_paper_name() { return m_news_paper_name; }
        void Setnews_paper_name(std::string val) { m_news_paper_name = val; }

    protected:

    private:
        unsigned int m_Counter;
        unsigned int m_type;
        unsigned int m_howcontacted;
        std::string m_position;
        std::string m_employername;
        std::string m_address;
        std::string m_state;
        std::string m_city;
        std::string m_telephone;
        std::string m_fax;
        std::string m_name_or_position_of_person_contacted;
        std::string m_email;
        std::string m_web_site;
        std::string m_job_reference_number;
        std::string m_agency_name;
        std::string m_agency_contact;
        std::string m_news_paper_name;
};

#endif // EMPLOYERCONTACT_H
