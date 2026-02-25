#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe
{
    private:
		struct Pair
		{
			int min;
			int max;
		};
        std::vector<int> _stack;
		std::vector<int> _processingStack;
		std::vector<int> _pendingStack;
		std::vector<Pair> _pairs;
		int _odd;
		int _hasOdd;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

		// Parsing
        bool parsing(std::string &nbrStr);
        bool postParsing();
        void printStack(std::vector<int> &stack);
		void printStack();

		// Algo
		void fordJohnson(std::vector<int> &array);
		std::vector<int> fordJohnsonRec(const std::vector<int> &array);
		std::vector<size_t> jacobsthalOrder(size_t n);
		void jacobsthalInserting(std::vector<size_t> &jacobOrder);
		void sortingInserting();
};
