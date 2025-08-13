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
        if (!std::isdigit(input[3][i]) && input[3][i] != '+')
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
	if (book.nb_contacts == 8)
		book.nb_contacts = 0;
    contact[book.nb_contacts++].setting_inputs(inputs);
	std::cout << "add_cmd: " << book.nb_contacts << std::endl;
}

void list_contacts(PhoneBook &book, Contact contact[8])
{
    int i = 0;
	std::string inputs[3];

    std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  " << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++)
	{
		contact[i].getting_name_inputs(inputs);
		if (inputs[0].empty())
			break;
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

void search_cmd_index(PhoneBook &book, Contact contact[8], int index)
{
	std::string inputs[5];

	if (index > book.nb_contacts)
	{
		std::cout << "contact: " << index << " doesn't exist" << std::endl;
		return ;
	}
	contact[index].getting_all_inputs(inputs);
	std::cout << "FirstName: " << inputs[0] << std::endl;
	std::cout << "LastName: " << inputs[1] << std::endl;
	std::cout << "NickName: " << inputs[2] << std::endl;
	std::cout << "PhoneNumber: " << inputs[3] << std::endl;
	std::cout << "DarkSecret: " << inputs[4] << std::endl;
}

int search_index(PhoneBook &book, Contact contact[8])
{
	int index = 0;
	int flag = 0;

	index = book.command[0] - '0';
	for (size_t j = 0; j < book.command.length(); j++)
	{
		if (std::isdigit(book.command[j]))
		{
			if (++flag > 1 
				|| !std::isdigit(book.command[j]) 
				|| (book.command[j] - '0') < 0 
				|| (book.command[j] - '0') > 7)
			{
				std::cout << "SEARCH index is not coherent" << std::endl;
				std::cout << "must be a digit between 0 to 7" << std::endl;
				return(book.search_cmd(book, contact));
			}
			//std::cout << "index :" << index << std::endl;
		}
		else
		{
			std::cout << "SEARCH index is not coherent" << std::endl;
			std::cout << "must be a digit between 0 to 7" << std::endl;
			return(book.search_cmd(book, contact));
		}
		
	}
	return (index);
}

int PhoneBook::search_cmd(PhoneBook &book, Contact contact[8])
{
	std::string inputs[3];
	int index = 0;

	list_contacts(book, contact);
	contact[0].getting_name_inputs(inputs);
	if (inputs[0] != "")
	{
		std::cout << "Enter a contact index:" << std::endl;
		std::getline(std::cin, book.command);
		index = search_index(book, contact);
		search_cmd_index(book, contact, index);
	}
	return (0);
}

int PhoneBook::parsing(PhoneBook &book, Contact contact[8])
{
    if (book.command == "ADD")
    {
        add_cmd(book, contact);
    }
    else if (book.command == "SEARCH")
    {
		return (search_cmd(book, contact));
    }
    else if (book.command == "EXIT")
    {
        return (1);
    }
    else
    {
        std::cout << "Please write a command: (ADD, SEARCH, EXIT)" << std::endl;
        std::getline(std::cin, book.command);
        return (parsing(book, contact));
    }
    return (0);
}

/* PROBLEME DE CREATION DE CONTACT LORS D'ERREURS */