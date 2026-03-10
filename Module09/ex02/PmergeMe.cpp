#include "PmergeMe.hpp"
#include <string>
#include <sstream>

PmergeMe::PmergeMe()// : _odd(0), _hasOdd(false)
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    _stack = other._stack;
	_stackDeque = other._stackDeque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this->_stack != other._stack)
    {
        _stack = other._stack;
		_stackDeque = other._stackDeque;
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

void PmergeMe::checkStackDeq()
{
	for (size_t i = 0; i < _stackDeque.size() - 1; i++)
	{
		if (_stackDeque[i] > _stackDeque[i + 1])
		{
			std::cerr << "Stack unsorted: \n" << "_stack[i]: " << _stackDeque[i] << "\n" << "_stack[i + 1]: " << _stackDeque[i + 1] << std::endl;
			
			return ;
		}
	}
	std::cout << "Stack sorted" << std::endl;
}

void PmergeMe::checkStackVect()
{
	for (size_t i = 0; i < _stack.size() - 1; i++)
	{
		if (_stack[i] > _stack[i + 1])
		{
			std::cerr << "Stack unsorted: \n" << "_stack[i]: " << _stack[i] << "\n" << "_stack[i + 1]: " << _stack[i + 1] << std::endl;
			
			return ;
		}
	}
	std::cout << "Stack sorted" << std::endl;
}

void PmergeMe::printStackDeq()
{
	std::cout << "After: ";
    for (size_t i = 0; i < _stackDeque.size(); i++)
    {
        std::cout << _stackDeque[i] << " ";
		if (i == _stackDeque.size() - 1)
			std::cout << std::endl;
    }
    
}

void PmergeMe::printStackVect()
{
	std::cout << "After: ";
    for (size_t i = 0; i < _stack.size(); i++)
    {
        std::cout << _stack[i] << " ";
		if (i == _stack.size() - 1)
			std::cout << std::endl;
    }
    
}

bool PmergeMe::postParsing()
{
    for (size_t i = 1; i < _stack.size(); i++)
    {
        int prevNbr = _stack[i - 1];


        if (prevNbr == _stack[i])
        {
            std::cerr << "Error: Duplicate numbers: " << prevNbr << " " << _stack[i] << std::endl;
            return (false);
        }
    }

    return (true);
}

size_t PmergeMe::getStackSizeVect()
{
	return (_stack.size());
}

size_t PmergeMe::getStackSizeDeq()
{
	return (_stackDeque.size());
}

bool PmergeMe::parsing(std::string &nbrStr)
{
    size_t i = 0;
	bool endOfString = false;

    while (i < nbrStr.size())
    {
        std::string subStr;
        int currentNbr = 0;
		// Recherche l'espace à partir de la position actuelle 'i'
        size_t nextSpace = nbrStr.find(' ', i);

		// Pas d'espace au dernier nombre donc end of string
		if (nextSpace == std::string::npos)
		{
			subStr = nbrStr.substr(i);
			endOfString = true;
		}
		// Extrait la substr jusqu'à l'espace
		subStr = nbrStr.substr(i, nextSpace - i);
		std::stringstream ss(subStr);
		if (ss >> currentNbr)
		{
			if (currentNbr <= 0 || !ss.eof())
			{
				std::cerr << "Error" << std::endl;
				return (false);
			}
			_stack.push_back(currentNbr);
			_stackDeque.push_back(currentNbr);
			//std::cout << "Input: " << subStr << std::endl;
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return (false);
		}
		if (endOfString == true)
			break ;

		// Correspond au charactere suivant après le space
        i = nextSpace + 1; 
    }

	std::cout << "Before: " << nbrStr << std::endl << std::endl;
    return (true);
}

std::deque<size_t> PmergeMe::jacobsthalOrderDeq(size_t n)
{
    std::deque<size_t> order;
    if (n == 0) 
		return (order);

    std::deque<size_t> jacob;
	// "0" et "1" de la suite ne necessite pas d'optimisation donc on peut les skip et insérer "1" et "3" de la suite
    jacob.push_back(1);
    jacob.push_back(3);

    // Generer les nombres
    while (jacob.back() < n)
    {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }

    size_t last_processed = 0;

    // 2. Parcourir les paliers de Jacobsthal
    for (size_t i = 0; i < jacob.size(); i++)
    {
        size_t target = jacob[i];
        if (target > n) 
			target = n;

        // On insère en décroissant de 'target' jusqu'à 'last_processed + 1'
        for (size_t j = target; j > last_processed; j--)
        {
            order.push_back(j - 1); // -1 si tu travailles avec des index 0-based
			//std::cout << "Order: " << j - 1 << std::endl;
        }
        
        if (target == n) 
			break ;
        last_processed = target;
    }

    return (order);
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> order;
    if (n == 0) 
		return (order);

    std::vector<size_t> jacob;
	// "0" et "1" de la suite ne necessite pas d'optimisation donc on peut les skip et insérer "1" et "3" de la suite
    jacob.push_back(1);
    jacob.push_back(3);

    // Generer les nombres
    while (jacob.back() < n)
    {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }

    size_t last_processed = 0;

    // Parcourir les paliers de Jacobsthal
    for (size_t i = 0; i < jacob.size(); i++)
    {
        size_t target = jacob[i];
        if (target > n) 
			target = n;

        // On insère en décroissant de 'target' jusqu'à 'last_processed'
        for (size_t j = target; j > last_processed; j--)
        {
            order.push_back(j - 1); // index 0-based
			//std::cout << "Order: " << j - 1 << std::endl;
        }
        
        if (target == n) 
			break ;
        last_processed = target;
    }

    return (order);
}

void PmergeMe::jacobsthalInsertingDeq(std::deque<int> &processingStack, std::deque<int> &pendingStack, std::deque<Pair> &pairs, int odd, bool hasOdd)
{
    std::deque<size_t> jacobOrder;

    jacobOrder = jacobsthalOrderDeq(pendingStack.size());

	for (size_t k = 0; k < jacobOrder.size(); k++)
	{
        size_t i = jacobOrder[k];
        if (i >= pendingStack.size() || i >= pairs.size())
            continue ;
		int currentValue = pendingStack[i];

        std::deque<int>::iterator maxPos = std::lower_bound(processingStack.begin(), processingStack.end(), pairs[i].max);
		std::deque<int>::iterator insertPos = std::lower_bound(processingStack.begin(), maxPos, currentValue);

		processingStack.insert(insertPos, currentValue);
	}

	if (hasOdd)
	{
		std::deque<int>::iterator minPos = std::lower_bound(processingStack.begin(), processingStack.end(), odd);
		processingStack.insert(minPos, odd);
	}

}

void PmergeMe::jacobsthalInserting(std::vector<int> &processingStack, std::vector<int> &pendingStack, std::vector<Pair> &pairs, int odd, bool hasOdd)
{
    std::vector<size_t> jacobOrder;

    jacobOrder = jacobsthalOrder(pendingStack.size());

	for (size_t k = 0; k < jacobOrder.size(); k++)
	{
        size_t i = jacobOrder[k];
        if (i >= pendingStack.size() || i >= pairs.size())
            continue ;
		int currentValue = pendingStack[i];

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

std::deque<int> PmergeMe::fordJohnsonDeq(std::deque<int> &array)
{
    std::deque<int> processingStack;
    std::deque<int> pendingStack;
    std::deque<int> maxIndexes;
    std::deque<Pair> pairs;
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

	processingStack = fordJohnsonDeq(processingStack);
	jacobsthalInsertingDeq(processingStack, pendingStack, pairs, odd, hasOdd);

    return (processingStack);
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
	jacobsthalInserting(processingStack, pendingStack, pairs, odd, hasOdd);

    return (processingStack);
}

void PmergeMe::sortingInsertingDeq()
{
	std::deque<int> result = fordJohnsonDeq(_stackDeque);
	_stackDeque = result;
}

void PmergeMe::sortingInserting()
{
	std::vector<int> result = fordJohnson(_stack);
	_stack = result;
}