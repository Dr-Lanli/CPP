#include <iostream>

class PmergeMe
{
    private:
        /* data */
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
};
