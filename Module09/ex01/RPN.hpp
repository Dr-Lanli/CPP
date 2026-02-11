#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
		std::stack<int> _stack;
		std::string _rpnStr;

    public:
        RPN();
		RPN(std::string rpnStr);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

		bool parseRpn();
		void executeRpn();
		void read_stack();

		std::string get_rpnStr();



};

#endif