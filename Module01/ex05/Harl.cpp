#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug (void)
{
	std::cout << "[ DEBUG ] Variable 'x' initialized correctly, entering main loop..." << std::endl;
}

void Harl::info (void)
{
	std::cout << "[ INFO ] Compilation succeeded, but I still see 42 warnings..." << std::endl;
}

void Harl::warning (void)
{
	std::cout << "[ WARNING ] Memory usage is rising quick... Did you forget to free something?" << std::endl;
}

void Harl::error (void)
{
	std::cout << "[ ERROR ] Segmentation fault (core dumped). I can’t take this anymore!" << std::endl;
}

void Harl::complain (std::string level)
{
	void (Harl::*ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*ptr[i])();
			return ;
		}
	}
}