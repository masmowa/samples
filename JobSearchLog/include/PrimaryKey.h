#ifndef PRIMARYKEY_H
#define PRIMARYKEY_H

#include <basic_STORAGE.h>


class PrimaryKey : public basic_STORAGE
{
 public:
    static const char* xml_section_name;
   public:
        PrimaryKey();
        virtual ~PrimaryKey();

        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }

        virtual std::string& get_value(const std::string& key) { return m_data[key]; }
        virtual void set_value(const std::string& key, const std::string& val) { m_data[key] = val; }


        virtual void Init() { InitKeys(); }
        virtual void InitKeys() {
            std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
            boost::assign::push_back(m_keys)(this->m_name)("Next-Key-Value");
        }
        virtual bool Load(const char* filepath=nullptr) { return false; };
        virtual bool Save(const char* filepath=nullptr) { return false; };

        bool ToXML(tinyxml2::XMLDocument* pdoc, tinyxml2::XMLElement * proot);

    protected:
        void TestDataInit() {
            this->set_value("Next-Key-Value", "1234");
        }

    private:
};

#endif // PRIMARYKEY_H
