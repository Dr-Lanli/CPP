#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

template <typename T>
void print(const T &x)
{
    std::cout << x << ' ';
}

void toupperChar(char &c)
{
    c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

void addPunctuation(std::string &s)
{
    s += "!";
}

int main()
{
    {    
        std::cout << "--- Testing int array ---\n";
        int array[] = {1, 2, 3, 4};
        size_t len = sizeof(array) / sizeof(array[0]);
        std::cout << "Before: ";
        ::iter(array, len, print<int>);
        std::cout << "\n";

        ::iter(array, len, ::increment<int>);
        std::cout << "After +1: ";
        ::iter(array, len, print<int>);
        std::cout << "\n";

        ::iter(array, len, ::decrement<int>);
        std::cout << "After -1: ";
        ::iter(array, len, print<int>);
        std::cout << "\n\n";
    }

    {    
        std::cout << "--- Testing const int array ---\n";
        const int array[] = {1, -2, 3, -4};
        size_t len = sizeof(array) / sizeof(array[0]);
        ::iter(array, len, isPositive<const int>);
        std::cout << "\n\n";
    }

    {
        std::cout << "--- Testing float array ---\n";
        float array[] = {1.5f, 2.5f, 3.5f};
        size_t len = sizeof(array) / sizeof(array[0]);
        std::cout << "Before: ";
        ::iter(array, len, print<float>);
        std::cout << "\n";
        ::iter(array, len, ::increment<float>);
        std::cout << "After +1: ";
        ::iter(array, len, print<float>);
        std::cout << "\n\n";
    }

    {
        std::cout << "--- Testing char array ---\n";
        char array[] = {'a', 'b', 'c'};
        size_t len = sizeof(array) / sizeof(array[0]);
        std::cout << "Before: ";
        ::iter(array, len, print<char>);
        std::cout << "\n";
        ::iter(array, len, toupperChar);
        std::cout << "After toupperChar: ";
        ::iter(array, len, print<char>);
        std::cout << "\n\n";
    }

    {
        std::cout << "--- Testing std::string array ---\n";
        std::string array[] = {"hello", "world"};
        size_t len = sizeof(array) / sizeof(array[0]);
        std::cout << "Before: ";
        ::iter(array, len, print<std::string>);
        std::cout << "\n";
        ::iter(array, len, addPunctuation);
        std::cout << "After addPunctuation: ";
        ::iter(array, len, print<std::string>);
        std::cout << "\n";
    }

    return (0);
}