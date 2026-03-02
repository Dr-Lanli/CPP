#include "PmergeMe.hpp"

#include <ctime>

std::string ToString(char *argv[])
{
    int len = 0;
    std::string nbrStr;

    while (argv[len])
        len++;          

    for (size_t i = 1; i < len; i++)
    {
        nbrStr.append(argv[i]);
        if (i < len - 1)
            nbrStr.append(" ");
    }
    
    //std::cout << "test nbrstr: " << NbrStr << std::endl;

    return (nbrStr);
}

int main(int argc, char *argv[])
{
    PmergeMe pme;
    std::string nbrStr;
	clock_t t_start = clock();


    if (argc < 3)
    {
        std::cout << "Error: Not enough arguments" << std::endl;
        return (1);
    }
    
    nbrStr = ToString(argv);
    if (!pme.parsing(nbrStr))
        return (1);
    //if (!pme.postParsing())
        //return (1);
    
	pme.sortingInserting();
	pme.printStack();
	pme.checkStack();

	clock_t t_end = clock();
	double elapsed = static_cast<double>(t_end - t_start) / CLOCKS_PER_SEC;
	std::cout << "Clock time passed: " << elapsed << std::endl;
    return (0);
}