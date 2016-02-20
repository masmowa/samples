#include "FileLocation.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <stdexcept>

#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;

/** \brief
 *
 * \param base_path="" const char*
 * \param base_file_name const char*
 * \param file_name_suffix const char*
 * \param ext const char*
 *
 */
FileLocation::FileLocation(const char* base_path="", const char* base_file_name, const char* file_name_suffix, const char* ext)
: m_base_path(base_path)
, m_base_file_name(base_file_name)
, m_file_name_suffix(file_name_suffix)
, m_ext(ext)
{
    //ctor
}

FileLocation::~FileLocation()
{
    //dtor
}

/** \brief wrapper for boost/filesystem/path.current_path()
 *
 * \return std::string : copy of the path as a std::string
 *
 */
std::string FileLocation::get_CWD()
{
    std::cout << "path::current_path [" << fs::current_path() << std::endl;
    return fs::current_path().string();
}

void FileLocation::BaseFileNameFromExePath(const char * in_path)
{
    std::cout << "++" << __PRETTY_FUNCTION__ << " in_path     : " << in_path << std::endl;
    if (!in_path) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'in_path' "
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    fs::path exe_path(in_path);
    fs::path fn_base = exe_path.filename();
    std::cout << "path::exe_path [" << exe_path << "]" << std::endl;

    std::cout << "path::basename [" << fn_base.string() << "]" << std::endl;

    return fn_base.string();
}

std::string FileLocation::FileNameFromBaseSuffix(const char * base, const char* suffix)
{
    std::stringstream ss_name;
    if (!base) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'base' "
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    if (!suffix) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'suffix' "
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    char underscore = ((suffix[0] == '_') ? '\0' : '_');
    ss_name << base << underscore << suffix;
    std::cout << "file name [ " << ss_name.str() << " ]" << std::endl;

    return ss_name.str();
}

