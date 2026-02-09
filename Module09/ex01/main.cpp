#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
    {
        std::cout << "Usage: ./RPN <inverted Polish mathematical expression>" << std::endl;
        return (1);
    }

	std::string rpnStr = argv[1];
	RPN rpn;

	rpn.parseRpn(rpnStr);
	rpn.executeRpn();


	return (0);
}