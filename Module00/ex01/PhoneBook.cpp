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
            return (1); 
        }
    }
    

    for (size_t i = 0; i < input[3].size(); i++)
    {
        if (!std::isdigit(input[3][i]) && input[3][i] != '+')
        {
            std::cout << "phone number is not coherent, contact not saved" << std::endl;
            return (1); 
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

    if (parsing_add_input(book, contact, inputs) == 0)
    {
        if (book.nb_contacts == 8)
            book.nb_contacts = 0;
        contact[book.nb_contacts++].setting_inputs(inputs);
        std::cout << "Contact added successfully!" << std::endl;
    }
}

void list_contacts(PhoneBook &book, Contact contact[8])
{
    std::string inputs[3];

    std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  " << std::endl;
    std::cout << "----------|----------|----------|----------" << std::endl;
    
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

    if (index >= book.nb_contacts || index < 0)
    {
        std::cout << "contact: " << index << " doesn't exist" << std::endl;
        return ();
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
    bool valid_input = true;

            if (book.command.length() != 1)
        {
            std::cout << "SEARCH index is not coherent" << std::endl;
            std::cout << "must be a digit between 0 to 7" << std::endl;
            return (-1); 
        }

            if (!std::isdigit(book.command[0]))
        {
            std::cout << "SEARCH index is not coherent" << std::endl;
            std::cout << "must be a digit between 0 to 7" << std::endl;
            return (-1);
        }

    index = book.command[0] - '0';
    

            if (index < 0 || index > 7)
        {
            std::cout << "SEARCH index is not coherent" << std::endl;
            std::cout << "must be a digit between 0 to 7" << std::endl;
            return (-1);
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
        
        if (index != -1)
        {
            search_cmd_index(book, contact, index);
        }
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
        return search_cmd(book, contact);
    }
    else if (book.command == "EXIT")
    {
        return (1);
    }
    else
    {
        std::cout << "Please write a command: (ADD, SEARCH, EXIT)" << std::endl;
        std::getline(std::cin, book.command);
        return (0);
    }
    return (0);
}