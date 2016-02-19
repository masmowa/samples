#ifndef JOBSEARCHLOG_H
#define JOBSEARCHLOG_H
#include <string>
#include <map>

#include "ContactOrJobSearchActivity.h"
#include "EmployerContact.h"
#include "WorksourceActivity.h"

class JobSearchLog
{
    public:
        JobSearchLog();
        JobSearchLog(const JobSearchLog& other);
        JobSearchLog& operator=(const JobSearchLog& other);
        virtual ~JobSearchLog();

        unsigned int GetActivityCount() { return m_ActivityCount; }
        void SetActivityCount(unsigned int val) { m_ActivityCount = val; }
        std::string& GetWeekEnding() { return m_WeekEnding; }
        void SetWeekEnding(std::string &val ) { SetWeekEnding(val.c_str()); }
        void SetWeekEnding( const char* val ) { m_WeekEnding = val; }
        std::string& GetSocialSecurityNumber() { return m_SSN; }
        void SetSocialSecurityNumber(std::string &val ) { SetSocialSecurityNumber(val.c_str()); }
        void SetSocialSecurityNumber( const char* val ) { m_SSN = val; }

        void WriteToLogAsXml() {}

        void WriteHTMLFile() {}

    protected:

    private:
        unsigned int m_ActivityCount;
        std::string m_WeekEnding;
        std::string m_SSN;
};

#endif // JOBSEARCHLOG_H
