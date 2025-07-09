#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
private:
public:
    PhoneBook();
    ~PhoneBook();
    int parsing(PhoneBook book, Contact contact[8]);
    std::string command;
    int nb_contacts;
};

#endif