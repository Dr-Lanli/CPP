#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
}

Base::~Base()
{
}

Base *Base::generate(void)
{
    int randomNum = rand() % 3;

    switch (randomNum)
    {
    case 0:
    {
        //std::cout << "New: A" << std::endl;
        return (new A());
    }
    case 1:
    {
        //std::cout << "New: B" << std::endl;
        return (new B());
    }
    case 2:
    {
        //std::cout << "New: C" << std::endl;
        return (new C());
    }
    default:
        return (NULL);
    }
}

void Base::identify(Base *p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void Base::identify(Base &p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } 
    catch (...) 
    {
    }
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } 
    catch (...) 
    {
    }
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } 
    catch (...) 
    {
    }
}