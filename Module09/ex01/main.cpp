#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
    {
        std::cout << "Usage: ./RPN <inverted Polish mathematical expression>" << std::endl;
        return (1);
    }

	RPN rpn(argv[1]);

	//std::cout << "TEST before parsing: " << rpn.get_rpnStr() << std::endl;
	if (!rpn.parseRpn())
		return (1);
	//std::cout << "TEST after parsing: " << rpn.get_rpnStr() << std::endl;
	if (!rpn.executeRpn())
		return (1);

	return (0);
}