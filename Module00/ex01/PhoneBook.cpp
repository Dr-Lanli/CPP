#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}


int parsing_add_input(PhoneBook &book, Contact contact[8], std::string input[5])
{
    for (size_t i = 0; i < 5; ++i)
    {
        if (input[i] == "")
        {
            std::cout << "field cannot be empty, contact not saved" << std::endl;
            std::cout << "Please write a command: (ADD, SEARCH, EXIT)" << std::endl;
            std::getline(std::cin, book.command);
            return (book.parsing(book, contact));
        }
    }
    for (size_t i = 0; i < input[3].size(); i++)
    {
        if (std::isalpha(input[3][i]))
        {
            std::cout << "phone number is not coherent, contact not saved" << std::endl;
            std::cout << "Please write a command: (ADD, SEARCH, EXIT)" << std::endl;
            std::getline(std::cin, book.command);
            return (book.parsing(book, contact));
        }
    }
    return (0);
}

void add_cmd(PhoneBook &book, Contact contact[8])
{
    std::string inputs[5];
    const std::string prompts[5] = {
        "write a first name : ",
        "write a last name : ",
        "write a nick name : ",
        "write a phone number : ",
        "write a dark secret : "
    };

    for (int i = 0; i < 5; ++i) 
    {
        std::cout << prompts[i];
        std::getline(std::cin, inputs[i]);
    }

    parsing_add_input(book, contact, inputs);
	//if (book.nb_contacts == 8)
		//book.nb_contacts = 0;
    contact[book.nb_contacts++].setting_inputs(inputs);
	std::cout << "add_cmd: " << book.nb_contacts << std::endl;
}

void search_cmd(PhoneBook &book, Contact contact[8])
{
    int i = 0;
	std::string inputs[3];

    std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  " << std::endl;
	for (int i = 0; i < book.nb_contacts; i++)
	{
		contact[i].getting_inputs(inputs);
		std::cout << std::setw(10) << std::right << i;
		for (int j = 0; j < 3; j++)
		{
			std::string truncated = inputs[j];
			if (truncated.length() > 10) 
				truncated = truncated.substr(0, 9) + ".";
			std::cout << "|" << std::setw(10) << std::right << truncated;
		}
		std::cout << std::endl;
	}
}

int PhoneBook::parsing(PhoneBook &book, Contact contact[8])
{
    if (book.command == "ADD")
    {
        add_cmd(book, contact);
    }
    else if (book.command == "SEARCH")
    {
        search_cmd(book, contact);
    }
    else if (book.command == "EXIT")
    {
        return (1);
    }
    else
    {
        std::cout << "Please write a command: (ADD, SEARCH, EXIT)" << std::endl;
        std::getline(std::cin, book.command);
        parsing(book, contact);
    }
    return (0);
}
