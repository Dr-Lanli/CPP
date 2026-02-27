#include "PmergeMe.hpp"
#include <string>
#include <sstream>

PmergeMe::PmergeMe()// : _odd(0), _hasOdd(false)
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

void PmergeMe::printStack(std::vector<int> &stack)
{
    for (size_t i = 0; i < stack.size(); i++)
    {
        std::cout << "stack" << "[" << i << "] :" << stack[i] << std::endl; 
    }
    
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
    //printStack();
    return (true);
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> order;
    std::vector<size_t> jacob;

    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

    size_t prev = 0;

    for (size_t k = 2; k < jacob.size(); k++)
    {
        size_t curr = std::min(jacob[k], n);
        for (size_t i = curr; i > prev; i--)
            order.push_back(i - 1);

        prev = curr;
    }

    // if any indices were skipped (happens when n is small) append them
    // in increasing order so they will be inserted eventually.
    for (size_t i = 0; i < n; i++)
    {
        if (std::find(order.begin(), order.end(), i) == order.end())
            order.push_back(i);
    }

    return (order);
}

std::vector<int> PmergeMe::fordJohnson(std::vector<int> &array)
{
    std::vector<int> processingStack;
    std::vector<int> pendingStack;
    std::vector<int> maxIndexes;
    std::vector<Pair> pairs;
    int odd;
    bool hasOdd = false;

	if (array.size() <= 1)
		return (array);

	// insertion des pairs de manière trié
	for (size_t i = 0; i + 1 < array.size(); i += 2)
	{
		Pair p;

		if (array[i] < array[i + 1])
		{
			p.min = array[i];
			p.max = array[i + 1];
		}
		else
		{
			p.min = array[i + 1];
			p.max = array[i];
		}

		pairs.push_back(p);
	}

	// si array impair stocker l'impair
	if (array.size() % 2 != 0)
	{
		odd = array.back();
		hasOdd = true;
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		processingStack.push_back(pairs[i].max);
		pendingStack.push_back(pairs[i].min);
	}

	processingStack = fordJohnson(processingStack);
	jacobsthalInserting(processingStack, pendingStack, pairs, maxIndexes, odd, hasOdd);

    return (processingStack);
}

void PmergeMe::jacobsthalInserting(std::vector<int> &processingStack, std::vector<int> &pendingStack, std::vector<Pair> &pairs, std::vector<int> maxIndexes, int odd, bool hasOdd)
{
    std::vector<size_t> jacobOrder;

    jacobOrder = jacobsthalOrder(pendingStack.size());

	for (size_t k = 0; k < jacobOrder.size(); k++)
	{
        size_t i = jacobOrder[k];
        if (i >= pendingStack.size() || i >= pairs.size())
            continue ;
		int currentValue = pendingStack[i];

		// retrouver la position du max associé
		int maxValue = pairs[i].max;
		//std::vector<int>::iterator maxPos = std::find(processingStack.begin(), processingStack.end(), maxValue);
        //std::vector<int>::iterator maxPos = maxIndexes.begin() + maxIndexes[i];
        std::vector<int>::iterator maxPos = std::lower_bound(processingStack.begin(), processingStack.end(), pairs[i].max);
		std::vector<int>::iterator insertPos = std::lower_bound(processingStack.begin(), maxPos, currentValue);

		processingStack.insert(insertPos, currentValue);
	}

	if (hasOdd)
	{
		std::vector<int>::iterator minPos = std::lower_bound(processingStack.begin(), processingStack.end(), odd);
		processingStack.insert(minPos, odd);
	}

}

//TODO: remplacer find() par un binary search et adapter le code en fonction

void PmergeMe::sortingInserting()
{
	std::vector<int> result = fordJohnson(_stack);
	_stack = result;
}