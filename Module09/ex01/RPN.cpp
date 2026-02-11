#include "RPN.hpp"

RPN::RPN()
{
	_res = 0;
}

RPN::RPN(std::string rpnStr)
{
	_rpnStr = rpnStr;
	_res = 0;
}

RPN::RPN(const RPN &other)
{
    _stack = other._stack;
	_rpnStr = other._rpnStr;
	_res = other._res;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this->_stack != other._stack)
    {
        _stack = other._stack;
		_rpnStr = other._rpnStr;
		_res = other._res;
    }

    return (*this);
}

RPN::~RPN()
{

}

std::string RPN::get_rpnStr()
{
	return (_rpnStr);
}

void RPN::read_stack()
{
	while (!_stack.empty())
	{
		std::cout << "STACK: " << _stack.top() << std::endl;
		_stack.pop();
	}
}

static bool isSign(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	
	return (false);
}

static bool isValidNbr(char c)
{
	if (c >= 48 && c <= 57)
		return (true);

	return (false);
}

static bool isValidChar(char c)
{
	if (isSign(c))
		return (true);
	if (isValidNbr(c))
		return (true);

	return (false);
}

static std::string trimRpn(std::string &str)
{
	std::string::size_type pos;

	while ((pos = str.find_first_of(" \n\r\t")) != std::string::npos)
	{
		str.erase(pos, 1);
	}
	//std::cout << "TEST TRIM: " << str << std::endl;
	return (str);
}

static bool validatingChar(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isValidChar(str[i]))
		{
			//std::cout << "TEST validatingStr: " << str[i] << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool validatingSign(std::string &str)
{
	int nbrSign = 0;
	int nbrInt = 0;

	if (isSign(str[0]))
		return (false);

	for (size_t i = 0; i < str.size(); i++)
	{
		char c = str[i];

		if (isSign(c))
			nbrSign++;
		if (c >= 48 && c <= 57)
			nbrInt++;
	}
	if (nbrInt != nbrSign + 1)
		return (false);
	
	return (true);
}

static bool validatingNbr(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isValidChar(str[i]))
        {
            if (i + 1 < str.size() && isValidChar(str[i + 1]))
                return (false);
        }
    }
    return (true);
}

bool RPN::parseRpn()
{
	if (_rpnStr.empty())
	{
		std::cout << "Error: RPN is empty" << std::endl;
		return (false);
	}
	if (!validatingNbr(_rpnStr))
	{
		std::cout << "Error: RPN contains numbers exceeding 9: " << _rpnStr << std::endl;
		return (false);
	}
	trimRpn(_rpnStr);
	if (!validatingChar(_rpnStr))
	{
		std::cout << "Error: RPN contains unauthorized character: " << _rpnStr << std::endl;
		return (false);
	}
	if (!validatingSign(_rpnStr))
	{
		std::cout << "Error: Not an RPN expression: " << _rpnStr << std::endl;
		return (false);
	}
	
	return (true);
}

bool RPN::switchOnSign(char sign, int a, int b)
{
	switch (sign)
	{
	case '-':
		_res = a - b;
		return (true);
	case '+':
		_res = a + b;
		return (true);
	case '*':
		_res = a * b;
		return (true);
	case '/':
		if (b == 0)
		{
			std::cout << "Error: division by 0: " << a << " / " << b << std::endl;
			return (false);
		}
		_res = a / b;
		return (true);
	default:
		return (true);
	}

	return (true);
}

bool RPN::executeRpn()
{
	for (size_t i = 0; i < _rpnStr.size(); i++)
	{
		for ( ; !isSign(_rpnStr[i]); i++)
		{
			//std::cout << "stack to push: " << _rpnStr[i] << std::endl;
			// Push les valeur en int au lieu d'ASCII par défaut
			_stack.push(_rpnStr[i] - '0');
		}
		if (isSign(_rpnStr[i]))
		{
			int a = 0;
			int b = 0;
			
			b = _stack.top();
			//std::cout << "stack elmt b: " << b << std::endl;
			_stack.pop();
			a = _stack.top();
			//std::cout << "stack elmt a: " << a << std::endl;
			_stack.pop();
	
			if (!switchOnSign(_rpnStr[i], a, b))
				return (false);

			_stack.push(_res);
		}
	}
	std::cout << _res << std::endl;
	
	return (true);
}
