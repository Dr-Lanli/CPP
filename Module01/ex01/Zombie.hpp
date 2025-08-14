#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	~Zombie();
	Zombie* zombieHorde(int N, std::string name);
	void setName(std::string& name);
	std::string getName() const;
	void announce(void);
};

#endif