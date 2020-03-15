#ifndef JOBSEARCHLOGFORWEEKENDING_H
#define JOBSEARCHLOGFORWEEKENDING_H
#include <string>


class JobSearchLogForWeekEnding
{
    public:
        JobSearchLogForWeekEnding();
        virtual ~JobSearchLogForWeekEnding();

        std::string GetWeekEnding() { return m_WeekEnding; }
        void SetWeekEnding(std::string val) { m_WeekEnding = val; }

    protected:
        std::string& WeekEnding();

    private:
        std::string m_WeekEnding;
};

#endif // JOBSEARCHLOGFORWEEKENDING_H
