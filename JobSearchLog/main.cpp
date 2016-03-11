#include <iostream>
#include "tinyxml2.h"
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <exception>

#include "dbg_Utility.h"
#include "UserInfo.h"
#include "AppSettings.h"
#include "FileUtility.h"

using namespace std;
#include <boost/program_options.hpp>
namespace bpo = boost::program_options;

#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;
namespace tx2 = tinyxml2;

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
    return full_path.string();
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
