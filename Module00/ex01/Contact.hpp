#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>


class Contact
{
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    std::string _phone_number;
    std::string _dark_secret;
public:
    Contact();
    ~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkSecret() const;

    void setFirstName(std::string& first_name);
    void setLastName(std::string& last_name);
    void setNickName(std::string& nick_name);
    void setPhoneNumber(std::string& phone_number);
    void setDarkSecret(std::string& dark_secret);
    void setting_inputs(std::string inputs[5]);
	void getting_name_inputs(std::string inputs[3]);
	void getting_all_inputs(std::string inputs[5]);
};


#endif