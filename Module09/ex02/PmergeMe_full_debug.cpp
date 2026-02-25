#include "PmergeMe.hpp"
#include <string>
#include <sstream>

PmergeMe::PmergeMe() : _odd(0), _hasOdd(false)
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
        jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);

    size_t prev = 1;

    for (size_t k = 2; k < jacob.size(); k++)
    {
        size_t curr = std::min(jacob[k], n);
        for (size_t i = curr; i > prev; i--)
            order.push_back(i - 1);

        prev = curr;
    }

    return (order);
}

void PmergeMe::fordJohnson(std::vector<int> &array)
{
	bool hasOdd = false;

    _pairs.clear();
    _processingStack.clear();
    _pendingStack.clear();  
	if (array.size() <= 1)
		return ;

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

		_pairs.push_back(p);
	}

	// si array impair stocker l'impair
	if (array.size() % 2 != 0)
	{
		_odd = array.back();
		_hasOdd = true;
	}

	for (size_t i = 0; i < _pairs.size(); i++)
	{
		_processingStack.push_back(_pairs[i].max);
		_pendingStack.push_back(_pairs[i].min);
	}

	fordJohnson(_processingStack);

}

void PmergeMe::jacobsthalInserting(std::vector<size_t> &jacobOrder)
{
    std::cout << "DEBUG: jacobsthalInserting() start\n";
    std::cout << "  jacobOrder size=" << jacobOrder.size() << " pendingSize=" << _pendingStack.size()
              << " processingSize=" << _processingStack.size() << " pairsSize=" << _pairs.size() << "\n";
    std::cout << "  jacobOrder: ";
    for (size_t k = 0; k < jacobOrder.size(); ++k)
        std::cout << jacobOrder[k] << (k + 1 < jacobOrder.size() ? " " : "\n");

    std::cout << "  _pendingStack: ";
    for (size_t k = 0; k < _pendingStack.size(); ++k)
        std::cout << _pendingStack[k] << (k + 1 < _pendingStack.size() ? " " : "\n");

    std::cout << "  _processingStack (before): ";
    for (size_t k = 0; k < _processingStack.size(); ++k)
        std::cout << _processingStack[k] << (k + 1 < _processingStack.size() ? " " : "\n");

    for (size_t step = 0; step < jacobOrder.size(); ++step)
    {
        size_t jIndex = jacobOrder[step];
        if (jIndex >= _pendingStack.size() || jIndex >= _pairs.size())
        {
            std::cout << "  WARNING: jacob index out of range: " << jIndex << "\n";
            continue;
        }

        int currentValue = _pendingStack[jIndex];
        // retrouver la position du max associé (utiliser le même index que pour pending)
        int maxValue = _pairs[jIndex].max;
        std::vector<int>::iterator maxPos = std::find(_processingStack.begin(), _processingStack.end(), maxValue);
        size_t maxPosIndex = (maxPos == _processingStack.end()) ? std::string::npos : static_cast<size_t>(maxPos - _processingStack.begin());
        std::vector<int>::iterator insertPos = std::lower_bound(_processingStack.begin(), maxPos, currentValue);
        size_t insertPosIndex = static_cast<size_t>(insertPos - _processingStack.begin());

        std::cout << "  step=" << step << " (jIndex=" << jIndex << ") current=" << currentValue
                  << " max=" << maxValue << " maxPos=" << (maxPosIndex == std::string::npos ? -1 : (int)maxPosIndex)
                  << " insertPos=" << insertPosIndex << "\n";

        _processingStack.insert(insertPos, currentValue);

        std::cout << "  _processingStack (after step " << step << "): ";
        for (size_t k = 0; k < _processingStack.size(); ++k)
            std::cout << _processingStack[k] << (k + 1 < _processingStack.size() ? " " : "\n");
    }

    if (_hasOdd)
    {
        std::vector<int>::iterator minPos = std::lower_bound(_processingStack.begin(), _processingStack.end(), _odd);
        std::cout << "  inserting odd value=" << _odd << " at pos=" << (minPos - _processingStack.begin()) << "\n";
        _processingStack.insert(minPos, _odd);
    }

    _stack = _processingStack;
    std::cout << "DEBUG: jacobsthalInserting() end -> _stack size=" << _stack.size() << "\n";
}

void PmergeMe::sortingInserting()
{
	std::vector<size_t> jacobOrder;

	// use recursive local implementation to avoid shared-member corruption
	std::vector<int> result = fordJohnsonRec(_stack);

	_stack = result;
	printStack(_stack);

}


std::vector<int> PmergeMe::fordJohnsonRec(const std::vector<int> &array)
{
    if (array.size() <= 1)
        return array;

    std::vector<Pair> pairsLocal;
    std::vector<int> processingLocal;
    std::vector<int> pendingLocal;
    int oddLocal = 0;
    bool hasOddLocal = false;

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
        pairsLocal.push_back(p);
    }

    if (array.size() % 2 != 0)
    {
        oddLocal = array.back();
        hasOddLocal = true;
    }

    for (size_t i = 0; i < pairsLocal.size(); ++i)
    {
        processingLocal.push_back(pairsLocal[i].max);
        pendingLocal.push_back(pairsLocal[i].min);
    }

    // recursive sort of processingLocal
    processingLocal = fordJohnsonRec(processingLocal);

    // jacobsthal insertion order for pending elements
    std::vector<size_t> jacOrder = jacobsthalOrder(pendingLocal.size());

    // insert pending values following jacobsthal order
    for (size_t step = 0; step < jacOrder.size(); ++step)
    {
        size_t jIndex = jacOrder[step];
        if (jIndex >= pendingLocal.size() || jIndex >= pairsLocal.size())
            continue;

        int currentValue = pendingLocal[jIndex];
        int maxValue = pairsLocal[jIndex].max;
        std::vector<int>::iterator maxPos = std::find(processingLocal.begin(), processingLocal.end(), maxValue);
        std::vector<int>::iterator insertPos = std::lower_bound(processingLocal.begin(), maxPos, currentValue);
        processingLocal.insert(insertPos, currentValue);
    }

    if (hasOddLocal)
    {
        std::vector<int>::iterator minPos = std::lower_bound(processingLocal.begin(), processingLocal.end(), oddLocal);
        processingLocal.insert(minPos, oddLocal);
    }

    return processingLocal;
}