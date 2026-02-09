#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &other)
{
    _stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this->_stack != other._stack)
    {
        _stack = other._stack;
    }

    return (*this);
}

RPN::~RPN()
{

}

bool RPN::parseRpn(std::string rpnStr)
{
	if (rpnStr.empty())
	{
		std::cout << "Error: RPN is empty" << std::endl;
		return (false);
	}
}

void RPN::executeRpn()
{

}