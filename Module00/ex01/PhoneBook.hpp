#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

#define MAX_CONTACT 8

class PhoneBook
{
private:
public:
    PhoneBook();
    ~PhoneBook();
    int parsing(PhoneBook &book, Contact contact[8]);
	int search_cmd(PhoneBook &book, Contact contact[8]);
    std::string command;
    int nb_contacts;
};

#endif