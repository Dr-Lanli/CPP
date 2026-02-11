#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
    private:
		std::stack<int> _stack;
		std::string _rpnStr;
		int _res;

    public:
        RPN();
		RPN(std::string rpnStr);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

		bool parseRpn();
		bool executeRpn();
		bool switchOnSign(char sign, int a, int b);
		void read_stack();

		std::string get_rpnStr();



};

#endif