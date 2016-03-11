#include "FileUtility.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <stdexcept>

#include <boost/filesystem.hpp>

using namespace std;
namespace bfs = boost::filesystem;

FileUtility::FileUtility()
{
    //ctor
}

FileUtility::~FileUtility()
{
    //dtor
}

/** \brief wrapper for boost/filesystem/path.current_path()
 *
 * \return std::string : copy of the path as a std::string
 *
 */
std::string FileUtility::get_CWD()
{
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;

    std::cout << "path::current_path [" << bfs::current_path() << std::endl;

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
    return bfs::current_path().string();
}

std::string FileUtility::BaseFileNameFromExePath(const char * in_path)
{
    std::cout << "++" << __PRETTY_FUNCTION__ << "\nin_path     : " << in_path << std::endl;
    if (!in_path) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'in_path' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    bfs::path exe_path(in_path);
    bfs::path fn_base = exe_path.stem();
    bfs::path fn_ext  = exe_path.filename();
    std::cout << "path::exe_path [" << exe_path << "]" << std::endl;

    std::cout << "path::basename [" << fn_base.string() << "]" << std::endl;

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
    return fn_base.string();
}

std::string FileUtility::FileNameFromParts(const char * base, const char* suffix, const char* ext)
{
    std::stringstream ss_name;
    std::cout << "\n++" << __PRETTY_FUNCTION__ << "" << std::endl;

    if (!base) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'base' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    if (!suffix) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'suffix' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    if (!suffix) {
        std::stringstream msg;
        msg << __PRETTY_FUNCTION__ << " invalid parameter 'ext' ";
        std::cerr << " !! ERROR " << msg.str() << endl;
        throw std::invalid_argument(msg.str());
    }
    char underscore = ((suffix[0] == '_') ? '\0' : '_');

    ss_name << base << underscore << suffix;
    bfs::path file = ss_name.str().c_str();
    file.replace_extension(ext);
    std::cout << "file name [ " << file.string() << " ]" << std::endl;

    std::cout <<   "--" << __PRETTY_FUNCTION__ << "\n" << std::endl;
    return file.string();
}

