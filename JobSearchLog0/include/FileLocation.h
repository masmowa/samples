#ifndef FILELOCATION_H
#define FILELOCATION_H


class FileLocation
{
    public:
        FileLocation(const char* base_path="", const char* base_file_name, const char* file_name_suffix, const char* ext);
        virtual ~FileLocation();

        unsigned int get_Counter() { return m_Counter; }
        void set_Counter(unsigned int val) { m_Counter = val; }
        std::string& get_base_path() { return m_base_path; }
        void set_base_path(std::string val) { m_base_path = val; }
        std::string& get_base_file_name() { return m_base_file_name; }
        void set_base_file_name(std::string val) { m_base_file_name = val; }
        std::string& get_file_name_suffix() { return m_file_name_suffix; }
        void set_file_name_suffix(std::string val) { m_file_name_suffix = val; }
        std::string& get_ext() { return m_ext; }
        void set_ext(std::string val) { m_ext = val; }
        std::string& get_full_path() { return m_full_path; }
        void set_full_path(std::string val) { m_full_path = val; }

        static std::string BaseFileNameFromExePath(const char * in_path);
        static std::string FileNameFromBaseSuffix(const char * base, const char* suffix);
        static std::string get_CWD();
    protected:

    private:
        unsigned int m_Counter;
        std::string m_base_path;
        std::string m_base_file_name;
        std::string m_file_name_suffix;
        std::string m_ext;
        std::string m_full_path;
};

#endif // FILELOCATION_H
