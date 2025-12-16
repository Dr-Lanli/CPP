#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    // Test with vector
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "vector : find 2 -> "
              << (::easyfind(v, 2) ? "found" : "not found") << std::endl;

    std::cout << "vector : find 5 -> "
              << (::easyfind(v, 5) ? "found" : "not found") << std::endl;

    // Test with list
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    std::cout << "list : find 20 -> "
              << (::easyfind(l, 20) ? "found" : "not found") << std::endl;

    // Test with deque (container wwith double entry)
    std::deque<int> d;
    d.push_back(79);
    d.push_back(99);

    std::cout << "deque : chercher 100 -> "
              << (::easyfind(d, 100) ? "found" : "not found") << std::endl;

    // Test with const container
    std::vector<int> v2;
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);

    const std::vector<int> cv(v2);

    std::cout << "const vector : find 8 -> "
              << (::easyfind(cv, 8) ? "found" : "not found") << std::endl;

    return (0);
}