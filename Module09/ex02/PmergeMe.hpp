#include <iostream>
#include <vector>

class PmergeMe
{
    private:
        std::vector<int> _stack;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool parsing(std::string &nbrStr);
        bool postParsing();
        void printStack();
};
