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
	for (size_t i = 0; i < jacobOrder.size(); i++)
	{
		int currentValue = _pendingStack[i];
		// retrouver la position du max associé
		int maxValue = _pairs[i].max;
		std::vector<int>::iterator maxPos = std::find(_processingStack.begin(), _processingStack.end(), maxValue);
		std::vector<int>::iterator insertPos = std::lower_bound(_processingStack.begin(), maxPos, currentValue);

		_processingStack.insert(insertPos, currentValue);
	}

	if (_hasOdd)
	{
		std::vector<int>::iterator minPos = std::lower_bound(_processingStack.begin(), _processingStack.end(), _odd);
		_processingStack.insert(minPos, _odd);
	}

	_stack = _processingStack;
}

// TODO: passer les variables partagé dans la classe en local, possible struct local ? evite la corruption ?

void PmergeMe::sortingInserting()
{
	std::vector<size_t> jacobOrder;
	fordJohnson(_stack);
	jacobOrder = jacobsthalOrder(_stack.size());
	printStack(_processingStack);
	jacobsthalInserting(jacobOrder);
	std::cout << "\n";
	printStack(_stack);

}