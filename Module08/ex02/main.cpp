#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "right way: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "reverse way: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    const MutantStack<int> cm(mstack);
    std::cout << "const iter: ";
    for (MutantStack<int>::const_iterator cit = cm.begin(); cit != cm.end(); ++cit)
        std::cout << *cit << " ";
    std::cout << std::endl;

    std::stack<int> s(mstack);
    std::cout << "popping from copy: ";
    while (!s.empty()) 
	{
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

	return (0);
}