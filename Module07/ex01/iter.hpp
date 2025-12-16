#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T>
void increment(T &nbr)
{
    nbr += 1;
}

template <typename T>
void decrement(T &nbr)
{
    nbr -= 1;
}

template <typename T>
void isPositive(T &nbr)
{
    if (nbr > 0)
    {
        std::cout << nbr << ": is positive" << std::endl;
    }
    else
    {
        std::cout << nbr << std::endl;
    }
}

template <typename T, typename Func>
void iter(T *array, const size_t len, Func f)
{
    for (size_t i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

template <typename T, typename Func>
void iter(const T *array, const size_t len, Func f)
{
    for (size_t i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

#endif