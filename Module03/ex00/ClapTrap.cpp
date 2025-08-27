#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor called" << std::endl;
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage." << std::endl;
		_energy_points--;
	}
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > amount || _hit_points == amount)
	{
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage." << std::endl;
		_hit_points -= amount;
	}
	else if (_hit_points < amount)
	{
		std::cout << "ClapTrap " << _name << " took " << amount << " points of damage." << std::endl;
		_hit_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _name << " repaired itself by " << amount << " points." << std::endl;
		_hit_points += amount;
		_energy_points--;
	}
}

int ClapTrap::getAttackDamage()
{
	return (_attack_damage);
}

int ClapTrap::getHitPoints()
{
	return (_hit_points);
}
