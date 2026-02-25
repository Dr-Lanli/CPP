#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _stack;
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
		void printStack();

		// Algo
		void fordJohnson(std::vector<int> &array);
		//std::vector<int> fordJohnsonRec(const std::vector<int> &array);
		std::vector<size_t> jacobsthalOrder(size_t n);
		void jacobsthalInserting();
		void sortingInserting();
};
