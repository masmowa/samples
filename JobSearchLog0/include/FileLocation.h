#ifndef FILELOCATION_H
#define FILELOCATION_H
#include <string>

class FileUtility
{
    public:
        FileUtility();
        virtual ~FileUtility();


        static std::string BaseFileNameFromExePath(const char * in_path);
        static std::string FileNameFromParts(const char * base, const char* suffix, const char* ext);
        static std::string get_CWD();
    protected:

    private:
};

#endif // FILELOCATION_H
