#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <stdint.h>
#include "data.h"

class Serializer
{
    
private:
    Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    

public:
    ~Serializer();
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

    class CreatingFileException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
    class ReadingFileException : public std::exception 
    {
        public:
        const char* what() const throw();
    };

};


#endif