#include <iostream>
#include <string>
#include <algorithm>    // transform
#include <ctype.h>      // toupper
#include <string.h>
#include <exception>
#include <stdexcept>

#include "tinyxml2.h"
#include "JobSearchLog.h"
#include "AppSettings.h"
#include "std_tools.h"

using namespace std;
namespace st = std_tools;

void PromptAndFillAppSettingsValuesFormConsole(AppSettings& settings)
{
    std::cout << "++" << __PRETTY_FUNCTION__ << " TODO: NOT YET IMPLEMENTED " << std::endl;
}

void GetValuesFromUser(AppSettings& data, std::string & category_key, std::string & key)
{
    std::string value;
    std::cout << "++" << __PRETTY_FUNCTION__ << " KEY [" << key << "]" << std::endl;

    std::cout << "\n Enter " << key << ": ";
    std::getline(std::cin, value);
    std::cout << "(" << key << " : " << value << ")" << std::endl;
    data.SetValueInCategory(category_key, key, value);
}

void PromptForApplicationSettings(AppSettings& settings)
{
    std::vector<std::string> ck = settings.get_category_keys();
    std::cout << "category keys length [" << ck.size() << "]" << std::endl;

    for (auto category_key : settings.get_category_keys()) {
        std::cout << "category key [" << category_key << "]" << std::endl;
        std::vector<std::string>& vkeys = settings.get_keys_for_category(category_key);
        std::cout << "keys for category [" << category_key << "] len [" << vkeys.size() << "]" << std::endl;
        for (auto key : vkeys) {
            std::cout << "key [" << key << "]" << std::endl;
            GetValuesFromUser(settings, category_key, key);
        }
    }

}

void Verify_Data_Ok(AppSettings& settings)
{
    settings.Dump(std::cout);

    std::cout << "Are These Values correct [Y | N] " << " : ";
    std::string in_str;
    getline (cin, in_str);
    std::cout << "you entered " << in_str << std::endl;

    st::makelower(in_str.begin(), in_str.end());

    // allow/force user to enter alues again
    if ("y" != in_str) {
        std::cout << "++" << __PRETTY_FUNCTION__ << " TODO: NOT YET IMPLEMENTED " << std::endl;
        //settings.PromptForUserData();
        PromptAndFillAppSettingsValuesFormConsole(settings);
    }
}

int main(int argc, char* argv[])
{
    cout << "argc : " << argc << " argv[0] : " << argv[0] << endl;
    try {
    //cout << "Hello world!" << endl;
    AppSettings settings;
    //settings.SetSettingsPath(FileLocation::get_CWD().c_str())
    settings.BuildFullFilePath(argv[0], AppSettings::DEFAULT_NAME);
    // AppSettings::PathFromExePath(settings, argv[0]);

    if (!settings.Load()) {
        PromptForApplicationSettings(settings);

    }
    Verify_Data_Ok(settings);
    settings.Save();
    }
    catch (std::runtime_error& e) {
        std::cout << __PRETTY_FUNCTION__ << " RUNTIME_ERROR caught " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << __PRETTY_FUNCTION__ << " EXCEPTION caught " << e.what() << std::endl;
    }
    return 0;
}
