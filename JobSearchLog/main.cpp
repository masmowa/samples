#include <iostream>
#include "tinyxml2.h"
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <iterator>
#include <exception>

#include "dbg_Utility.h"
#include "UserInfo.h"
#include "AppSettings.h"
#include "FileUtility.h"
#include <cstdio>
#include <ctime>
#include <boost/date_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/local_time/local_time.hpp>

using namespace std;
#include <boost/program_options.hpp>
namespace bpo = boost::program_options;

#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;
namespace tx2 = tinyxml2;
namespace blt = boost::local_time;
namespace bpt = boost::posix_time;
namespace bgt = boost::gregorian;

void add_inner_element(tinyxml2::XMLDocument* pdoc, tinyxml2::XMLElement* root)
{
    std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;

}

std::string build_settings_filepath(const char* exe_name)
{
    std::cout <<   "++" << __PRETTY_FUNCTION__ << "\n" << std::endl;
    std::string filename = FileUtility::FileNameFromParts(
                                                       exe_name,
                                                       AppSettings::DEFAULT_NAME,
                                                       AppSettings::DEFAULT_EXT
                                                       );
    bfs::path full_path = bfs::current_path() / filename;

    std::cout << "full path " << full_path.string() << std::endl;

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
//2011-10-20T09:30:10-05:00
    return full_path.string();
}

void show_posix_time()
{
    try {
    std::string ts2("2016-03-29T09:30:10-08:00");
    std::string ts_no_zoff("2016-03-29T09:30:10");
    bgt::date today(bgt::day_clock::local_day());
    time_t x_now = {};
    time_t tt_now = std::time(&x_now);
    struct tm lcl_result = {};
    struct tm *lcl_now   = std::localtime(&tt_now);
    bgt::date today_now(tt_now);
    bpt::ptime today_posix_tm(today);
    bpt::ptime now(bpt::microsec_clock::local_time());

    std::stringstream ss;
    std::cout << "boost.posix time: " << std::endl;
    std::cout << "posix time now to     ISO " << bpt::to_iso_string(now) << std::endl;
    std::cout << "posix time now to ext-ISO " << bpt::to_iso_extended_string(now) << std::endl;
    std::cout << "today from gregorian to posix " << bpt::to_iso_string(today_posix_tm) << std::endl;

    std::cout << "from: " << ts_no_zoff << " ";
//    bpt::ptime leap_noz = bpt::from(ts_no_zoff);
    bpt::ptime leap_noz = bpt::from_iso_string(ts_no_zoff);
    std::cout << "posix ext-ISO " <<bpt::to_iso_extended_string(leap_noz) << std::endl;

    bpt::ptime leap = bpt::from_iso_string(ts2);
    std::cout << "posix ext-ISO " <<bpt::to_iso_extended_string(leap) << std::endl;
    std::cout << "\n";
    }
    catch (std::exception& e) {
        cerr << "ERROR: " << e.what() << "\n";
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }
}
void show_time_yyyymmdd_hhmmss()
{
    std::time_t rawtime;
    std::tm* timeinfo;
    char buffer [BUFSIZ];
    const size_t buf_len = sizeof(buffer)/sizeof(buffer[0]);

    std::cout << "C time : " << std::endl;
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,buf_len,"%Y-%m-%d-T-%H-%M-%S",timeinfo);
    std::puts(buffer);
    std::cout << "\n";

    //return 0;
}
void test_greg_time_ss()
{
    std::string ts0("2011-10-20");
    std::string ts1("2011-10-20T09:30:10-08:00");
    std::string ts2("2016-03-29T09:30:10-08:00");
    std::string ts3("2016-03-30T09:30:10-08:00");

    try {
    std::cout << "boost.Gregorian: " << std::endl;

    bgt::date dt0(bgt::from_simple_string(ts0));
    std::cout << "ts0  : " << ts0 << " is " << bgt::to_iso_extended_string(dt0) <<std::endl;
    bgt::date today = bgt::day_clock::local_day();
    std::cout << "SIMPLE from : " << ts0 << " to: " << bgt::to_simple_string(dt0) << std::endl;
    std::cout << "to simple string today: "  << to_simple_string(today) << std::endl;

    std::cout << "ISO    from : " << ts2 << " ";

    bgt::date from_iso_dt = bgt::from_string(ts2);

    std::cout << " to ISO: " << bgt::to_iso_extended_string(from_iso_dt) <<std::endl;
    std::cout << "from bad ISO: " << ts3 << " ";
    bgt::date from_bad_iso_dt = bgt::from_string(ts3);
    std::cout << " to ISO " << bgt::to_iso_string(from_bad_iso_dt);
    }
    catch (std::exception& e) {
        cerr << "error: " << e.what() << "\n";
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }
}
void test_time()
{
    time_t now = time(NULL);
    struct tm local_date_time = {};

    std::cout << "boost.local_date_time: " << std::endl;
    // convert, then copy internal object to our object
    memcpy (&local_date_time, localtime(&now), sizeof(local_date_time));
    printf ("Year is: %04d\n", local_date_time.tm_year + 1900);
    std::cout << "\n";
    show_time_yyyymmdd_hhmmss();
    test_greg_time_ss();
    show_posix_time();
}
int main(int argc, char* argv[])
{
    try {
        std::string exeFileName = FileUtility::BaseFileNameFromExePath(argv[0]).c_str();
        cout << "EXE: " << exeFileName << ": "<< __PRETTY_FUNCTION__ << " " << endl;

        bpo::options_description desc("Allowed options");
        desc.add_options()
            ("help", "store job search contacts into weekly xml file")
            ("force", "Force saving new set of default values")
        ;

        bpo::variables_map vm;
        bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
        // perform some conversion to the variable-map
        bpo::notify(vm);

        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }

        std::string settings_filepath = build_settings_filepath(exeFileName.c_str());

        AppSettings settings(settings_filepath.c_str());

        if (vm.count("force")) {
            cout << "force saving of App Settings to update storage "
                 << ".\n" << std::endl;
             settings.set_force_save(true);
        } else {
            cout << "force was not set.\n";
        }

        bool bResult = settings.Load(settings_filepath.c_str());


        if (!bResult || settings.get_force_save()) {
            bResult = settings.SaveDefault();
        }

        test_time();
    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }

    return 0;
}
