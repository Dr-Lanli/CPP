#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
	/* data */
public:
	Dog();
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
};




#endif