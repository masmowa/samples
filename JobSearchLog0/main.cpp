#include <iostream>
#include <string>
#include <algorithm>    // transform
#include <ctype.h>      // toupper
#include <string.h>

#include "tinyxml2.h"
#include "JobSearchLog.h"
#include "AppSettings.h"
#include "std_tools.h"

using namespace std;
namespace st = std_tools;
void Verify_Data_Ok(AppSettings& settings)
{
    AppSettings::USER_INFO_MAP::iterator iter;
    std::cout << "\nvalues currently stored in " << settings.get_name() << std::endl;

    for (iter = settings.Getuser_info_map().begin(); iter != settings.Getuser_info_map().end(); ++iter ) {
        std::cout << iter->first << ": [ " << iter->second << " ]" << std::endl;
    }
    std::cout << "Are These Values correct [Y | N] " << " : ";
    std::string in_str;
    getline (cin, in_str);
    std::cout << "you entered " << in_str << std::endl;
    //transform(in_str.begin(), in_str.end(), in_str.begin(), toupper);
    st::makelower(in_str.begin(), in_str.end());

    // allow/force user to enter alues again
    if ("y" != in_str) {
        settings.PromptForUserData();
    }
}

int main(int argc, char* argv[])
{
    cout << "argc : " << argc << " argv[0] : " << argv[0] << endl;
    //cout << "Hello world!" << endl;
    AppSettings settings;
    AppSettings::PathFromExePath(settings, argv[0]);
    if (!settings.Load(settings.GetSettingsFilePath().c_str())) {
        settings.PromptForUserData();

    }
    Verify_Data_Ok(settings);
    settings.Save();

    return 0;
}
