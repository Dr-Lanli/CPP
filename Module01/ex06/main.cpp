#include "harlFilter.hpp"

static int enum_setup(std::string level)
{
	std::string new_str;
	for (size_t i = 0; i < level.size(); i++)
	{
		new_str += toupper(level[i]);
	}
	if (new_str == "DEBUG")
	{
		return (DEBUG);
	}
	else if (new_str == "INFO")
	{
		return (INFO);
	}
	else if (new_str == "WARNING")
	{
		return (WARNING);
	}
	else if (new_str == "ERROR")
	{
		return (ERROR);
	}
	return (-1);
}

int main (int argc, char *argv[])
{
	Harl harl;

	if (argc != 2)
		return (std::cout << "required only 1 argument" << std::endl && 1);
	
	harl.complain(enum_setup(argv[1]));

	return (0);
}