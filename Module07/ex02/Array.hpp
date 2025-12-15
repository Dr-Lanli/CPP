#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array 
{
private:
    T *_array;
    size_t _size;

public:
    Array()
    {
        _array = NULL;
        _size = 0;
    }

    Array(unsigned int n)
    {
        _size = n;
        if (n > 0)
            _array = new T[n]();
        else
            _array = NULL;
    }

    ~Array()
    {
        delete[] _array;
    }

    Array(const Array &other)
    {
        _array = new T[other._size];
        _size = other._size;
        for (size_t i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }

    Array &operator=(const Array &other) 
    {
        if (this != &other) 
        {
            T* new_array = NULL;
            if (other._size > 0) 
            {
                new_array = new T[other._size];
                for (size_t i = 0; i < other._size; ++i)
                    new_array[i] = other._array[i];
            }
            delete[] _array;
            _array = new_array;
            _size = other._size;
        }
        return (*this);
    }

    T &operator[](size_t i)
    {
        if (i >= _size)
            throw std::out_of_range("Array index out of range");
        return (_array[i]);
    }

    const T &operator[](size_t i) const
    {
        if (i >= _size)
            throw std::out_of_range("Array index out of range");
        return (_array[i]);
    }

    size_t size() const
    {
       return (_size);
    }
};

#endif