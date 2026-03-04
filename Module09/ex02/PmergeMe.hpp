#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _stack;
		std::deque<int> _stackDeque;
		struct Pair
		{
			int min;
			int max;
		};

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

		// Parsing
        bool parsing(std::string &nbrStr);
        bool postParsing();
        void printStack(std::vector<int> &stack);
		void printStackVect();
		void checkStackVect();

		void printStackDeq();
		void checkStackDeq();

		// Algo
		std::vector<int> fordJohnson(std::vector<int> &array);
		//std::vector<int> fordJohnsonRec(const std::vector<int> &array);
		std::vector<size_t> jacobsthalOrder(size_t n);
		void jacobsthalInserting(std::vector<int> &processingStack, std::vector<int> &pendingStack, std::vector<Pair> &pairs, std::vector<int> maxIndexes, int odd, bool hasOdd);
		void sortingInserting();

		std::deque<int> fordJohnsonDeq(std::deque<int> &array);
		std::deque<size_t>jacobsthalOrderDeq(size_t n);
		void jacobsthalInsertingDeq(std::deque<int> &processingStack, std::deque<int> &pendingStack, std::deque<Pair> &pairs, std::deque<int> maxIndexes, int odd, bool hasOdd);
		void sortingInsertingDeq();
};
