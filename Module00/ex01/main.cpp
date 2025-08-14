#include "PhoneBook.hpp"
#include "Contact.hpp"


int main (void)
{
    PhoneBook book;
    Contact contact[8];

    book.nb_contacts = 0;
    while (true)
    {
        std::cout << "Please write a command: (ADD, SEARCH, EXIT)" << std::endl;
        std::getline(std::cin, book.command);
        if (book.parsing(book, contact) == 1)
            return (0);
    }
    return (0);
} 