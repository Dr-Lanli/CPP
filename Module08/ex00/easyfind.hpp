#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> bool easyfind(const T &container, int n)
{
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == n)
            return (true);
    }
    return (false);
}


#endif