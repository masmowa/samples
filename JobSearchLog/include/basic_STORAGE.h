#ifndef BASIC_STORAGE_H
#define BASIC_STORAGE_H

#include <iostream>
#include <string>
#include <tinyxml2.h>
#include <map>
#include <vector>
#include <boost/assign.hpp>


class basic_STORAGE
{
public:
    typedef std::map<std::string, std::string> DATA_MAP;
    typedef std::vector<std::string> KEY_VECTOR;

public:
    basic_STORAGE(const char* name) : m_name(name) {

        std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
        std::cout << "  name: " << this->m_name << std::endl;
        std::cout << "--" << __PRETTY_FUNCTION__ << std::endl;
    }
    virtual ~basic_STORAGE() {
        std::cout << "++" << __PRETTY_FUNCTION__ << std::endl;
    }
    DATA_MAP Getdata() { return m_data; }
    KEY_VECTOR Getkeys() { return m_keys; }
    std::string Getname() { return m_name; }

    virtual void Setname(std::string& val) { m_name = val; }
    virtual std::string& get_value(const std::string& key) = 0;
    virtual void set_value(const std::string& key, const std::string& val) = 0;

    virtual void Init() = 0;
    virtual void InitKeys() = 0;
    virtual bool ToXML(tinyxml2::XMLDocument* pdoc, tinyxml2::XMLElement* proot) = 0;

    virtual bool Load(const char* filepath=nullptr) = 0;
    virtual bool Save(const char* filepath=nullptr) = 0;


protected:
    DATA_MAP m_data;
    KEY_VECTOR m_keys;
    std::string m_name;

    private:
};

#endif // BASIC_STORAGE_H
