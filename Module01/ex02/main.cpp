#include <iostream>
#include <string.h>

int main (void)
{
    std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "memory address of 'brain' variable: " << &brain << std::endl;
	std::cout << "memory address of 'stringPTR' variable: " << &stringPTR << std::endl;
	std::cout << "memory address of 'stringREF' variable: " << &stringREF << std::endl << std::endl;

	std::cout << "value of 'brain' variable: " << brain << std::endl;
	std::cout << "value of 'stringPTR' variable: " << stringPTR << std::endl;
	std::cout << "value of 'stringREF' variable: " << stringREF << std::endl;

    return (0);
}