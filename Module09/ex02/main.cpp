#include "PmergeMe.hpp"

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

    if (argc < 3)
    {
        std::cout << "Error: Not enough arguments" << std::endl;
        return (1);
    }
    
    nbrStr = ToString(argv);
    if (!pme.parsing(nbrStr))
        return (1);
    if (!pme.postParsing())
        return (1);
    
	pme.sortingInserting();
	//pme.printStack();

    return (0);
}