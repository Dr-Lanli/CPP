#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(std::string type);
    ~WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);

    std::string getType() const;
    void makeSound() const;
};

#endif
