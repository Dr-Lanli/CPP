
#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    try 
    {
        // Test with integers
        Array<int> numbers(5);
        for (size_t i = 0; i < numbers.size(); ++i)
            numbers[i] = static_cast<int>(i) * 2;

        std::cout << "numbers:";
        for (size_t i = 0; i < numbers.size(); ++i)
            std::cout << ' ' << numbers[i];
        std::cout << '\n';

        // Test copy constructor (deep copy)
        Array<int> copy = numbers;
        numbers[0] = 99;
        std::cout << "After modification: numbers[0] = " << numbers[0]
                  << ", copy[0] = " << copy[0] << '\n';

        // Test assignment operator with strings
        Array<std::string> words(3);
        words[0] = "hello";
        words[1] = "world";
        words[2] = "!";

        // Test assignment operator with strings (out of range)
        try 
        {
            words[4] = "?"; // out of range
        } catch (const std::exception &e) 
        {
            std::cout << "caught exception: " << e.what() << '\n';
        }

        Array<std::string> assigned;
        assigned = words;
        std::cout << "assigned:";
        for (size_t i = 0; i < assigned.size(); ++i)
            std::cout << ' ' << assigned[i];
        std::cout << '\n';

        // Test const
        const Array<int> constNumbers = numbers;
        std::cout << "constNumbers[2] = " << constNumbers[2] << '\n';
        std::cout << "constNumbers = ";
        for (size_t i = 0; i < constNumbers.size(); ++i)
            std::cout << ' ' << constNumbers[i];
        std::cout << '\n';

        // Test default (empty) array size
        Array<double> empty;
        std::cout << "empty size = " << empty.size() << '\n';
        if (empty.size() == 0)
            std::cout << "empty is empty, skipping access\n";
        else
            std::cout << "empty[0] = " << empty[0] << '\n';

    } catch (const std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return (1);
    }

    return (0);
}