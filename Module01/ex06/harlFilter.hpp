#ifndef HARL_FILTER_HPP
#define HARL_FILTER_HPP

#include <string>
#include <iostream>

class Harl
{
private:
	void debug (void);
	void info (void);
	void warning (void);
	void error (void);
public:
	Harl(/* args */);
	~Harl();
	void complain (int level);
};

enum levels 
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};


#endif