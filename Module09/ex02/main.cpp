#include "PmergeMe.hpp"

#include <ctime>

std::string ToString(char *argv[])
{
    size_t len = 0;
    std::string nbrStr;

    while (argv[len])
        len++;

    for (size_t i = 1; i < len; i++)
    {
        nbrStr.append(argv[i]);
        if (i + 1 < len)
            nbrStr.append(" ");
    }
    
    //std::cout << "test nbrstr: " << NbrStr << std::endl;

    return (nbrStr);
}

int main(int argc, char *argv[])
{
    PmergeMe pme;
    std::string nbrStr;


    if (argc < 3)
    {
        std::cout << "Error: Not enough arguments" << std::endl;
        return (1);
    }
    
    nbrStr = ToString(argv);
    if (!pme.parsing(nbrStr))
    {
        return (1);
    }
	
	std::cout << "---- Using Vector<int> ----" <<std::endl;
    
	clock_t t_start_v = clock();

	pme.sortingInserting();
	pme.printStackVect();
	pme.checkStackVect();

	clock_t t_end_v = clock();
	double elapsed_v = static_cast<double>(t_end_v - t_start_v) / CLOCKS_PER_SEC;
	std::cout << std::fixed;
	std::cout << "Clock time passed: " << elapsed_v << " second" << std::endl << std::endl;

	std::cout << "---- Using Deque<int> ----" <<std::endl;

	clock_t t_start_d = clock();

	pme.sortingInsertingDeq();
	pme.printStackDeq();
	pme.checkStackDeq();

	clock_t t_end_d = clock();
	double elapsed_d = static_cast<double>(t_end_d - t_start_d) / CLOCKS_PER_SEC;
	std::cout << std::fixed;
	std::cout << "Clock time passed: " << elapsed_d << " second" << std::endl;

    return (0);
}