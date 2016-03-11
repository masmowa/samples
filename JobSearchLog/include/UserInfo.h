#ifndef USERINFO_H
#define USERINFO_H

#include <basic_STORAGE.h>


class UserInfo : public basic_STORAGE
{
public:
    static const char* xml_section_name;
public:
    UserInfo();
    virtual ~UserInfo();

    unsigned int GetCounter() { return m_Counter; }
    void SetCounter(unsigned int val) { m_Counter = val; }

    std::string Getname() { return m_name; }
    void Setname(std::string val) { m_name = val; }

    virtual std::string& get_value(const std::string& key) { return m_data[key]; }
    virtual void set_value(const std::string& key, const std::string& val) { m_data[key] = val; }


    virtual void Init() { InitKeys(); }
    virtual void InitKeys() {
        std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
        boost::assign::push_back(m_keys)(this->m_name);
    }
    virtual bool Load(const char* filepath=nullptr) { return false; };
    virtual bool Save(const char* filepath=nullptr) { return false; };

    bool ToXML(tinyxml2::XMLDocument* pdoc, tinyxml2::XMLElement * proot);

    protected:
        void TestDataInit() {
            this->set_value("name", "john Doe");
            this->set_value("address", "123 Main");
            this->set_value("city", "Monroe");
            this->set_value("state", "WA");
            this->set_value("ZIP", "98272");
        }

    private:
        unsigned int m_Counter;
};

#endif // USERINFO_H
