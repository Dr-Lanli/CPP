#include "PmergeMe.hpp"
#include <string>
#include <sstream>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    _stack = other._stack;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this->_stack != other._stack)
    {
        _stack = other._stack;
    }

    return (*this);
}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::printStack()
{
    for (size_t i = 0; i < _stack.size(); i++)
    {
        std::cout << "stack" << "[" << i << "] :" << _stack[i] << std::endl; 
    }
    
}

bool PmergeMe::postParsing()
{
    for (size_t i = 1; i < _stack.size(); i++)
    {
        int prevNbr = _stack[i - 1];


        if (prevNbr == _stack[i])
        {
            std::cout << "Error: Duplicate numbers: " << prevNbr << " " << _stack[i] << std::endl;
            return (false);
        }
    }

    return (true);
}

bool PmergeMe::parsing(std::string &nbrStr)
{
    for (size_t i = 0; i < nbrStr.size(); i++)
    {
        std::string subStr;
        int currentNbr = 0;
        size_t nextSpace = nbrStr.find(' ');

        subStr = nbrStr.substr(i, nextSpace);
        std::stringstream ss(subStr);
        if (ss >> currentNbr)
        {
            _stack.push_back(currentNbr);
        }
        else
        {
            std::cout << "Error: Invalid input" << std::endl;
            return (false);
        }
        i += nextSpace;
    }
    
    return (true);
}