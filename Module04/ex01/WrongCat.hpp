#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    ~WrongCat(); // ⚠️ pas virtual, exprès
    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);

    void makeSound() const; // ⚠️ pas virtual, exprès
};

#endif
