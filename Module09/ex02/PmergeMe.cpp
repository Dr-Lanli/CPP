#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    /*if (this->_stack != other._stack)
    {
        _stack = other._stack;
		_rpnStr = other._rpnStr;
		_res = other._res;
    }*/

    return (*this);
}

PmergeMe::~PmergeMe()
{
    
}