#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void)
{
    std::cout << "===== Constructor testing =====" << std::endl;
    Animal a1("Lion");
    Animal a2;
    Cat c1;
    Dog d1;

    std::cout << "\n===== Sound testing =====" << std::endl;
    a1.makeSound();  // son aléatoire
    a2.makeSound();  // son aléatoire
    c1.makeSound();  // Miaou!
    d1.makeSound();  // Woof!

    std::cout << "\n===== Copy constructor testing =====" << std::endl;
    Cat c2(c1);
    Dog d2(d1);
    Animal a3(a1);

    c2.makeSound();
    d2.makeSound();
    a3.makeSound();

    std::cout << "\n===== Operator test =====" << std::endl;
    Cat c3;
    Dog d3;
    Animal a4;

    c3 = c1;
    d3 = d1;
    a4 = a1;

    c3.makeSound();
    d3.makeSound();
    a4.makeSound();

    std::cout << "\n===== Polymorphism test =====" << std::endl;
    Animal* animals[3];
    animals[0] = new Cat();
    animals[1] = new Dog();
    animals[2] = new Animal("Elephant");

    for (int i = 0; i < 3; i++)
	{
		animals[i]->makeSound();
	}
    for (int i = 0; i < 3; i++)
	{
    	delete animals[i];
	}

	std::cout << "\n===== Test WrongAnimal vs WrongCat =====" << std::endl;
    WrongAnimal* wa = new WrongAnimal();
    WrongAnimal* wc = new WrongCat();

    std::cout << "wa->getType(): " << wa->getType() << std::endl;
    std::cout << "wc->getType(): " << wc->getType() << std::endl;

    wa->makeSound();
    wc->makeSound(); // WrongAnimal::makeSound() car pas virtual

    delete wa;
    delete wc;

    std::cout << "\n==========" << std::endl;
}