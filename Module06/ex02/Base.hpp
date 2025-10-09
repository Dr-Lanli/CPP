#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class A;
class B;
class C;

class Base
{
private:

public:
    Base();
    virtual ~Base();
    static Base *generate(void);
    static void identify(Base *p);
    static void identify(Base &p);
};

#endif