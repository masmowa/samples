#ifndef FILEUTILITY_H
#define FILEUTILITY_H
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

#endif // FILEUTILITY_H
