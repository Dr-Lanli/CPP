#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::getFirstName() const
{
    return (_first_name);
}
std::string Contact::getLastName() const
{
    return (_last_name);
}
std::string Contact::getNickName() const
{
    return (_nick_name);
}
std::string Contact::getPhoneNumber() const
{
    return (_phone_number);
}
std::string Contact::getDarkSecret() const
{
    return (_dark_secret);
}

void Contact::setFirstName(std::string &first_name)
{
    _first_name = first_name;
}
void Contact::setLastName(std::string &last_name)
{
    _last_name = last_name;
}
void Contact::setNickName(std::string &nick_name)
{
    _nick_name = nick_name;
}
void Contact::setPhoneNumber(std::string &phone_number)
{
    _phone_number = phone_number;
}
void Contact::setDarkSecret(std::string &dark_secret)
{
    _dark_secret = dark_secret;
}

void Contact::setting_inputs(std::string inputs[5])
{
    setFirstName(inputs[0]);
    setLastName(inputs[1]);
    setNickName(inputs[2]);
    setPhoneNumber(inputs[3]);
    setDarkSecret(inputs[4]);
    std::cout << "Contact added" << std::endl;
}

void Contact::getting_name_inputs(std::string inputs[3])
{
    inputs[0] = getFirstName();
    inputs[1] = getLastName();
    inputs[2] = getNickName();
}

void Contact::getting_all_inputs(std::string inputs[5])
{
    inputs[0] = getFirstName();
    inputs[1] = getLastName();
    inputs[2] = getNickName();
	inputs[3] = getPhoneNumber();
	inputs[4] = getDarkSecret();
}