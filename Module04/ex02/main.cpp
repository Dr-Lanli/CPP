#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void)
{
	// Ne fonctionne pas en class abstraite
	//Animal test_abstract = new Dog();
	
	std::cout << "===== Test Cat & Dog =====" << std::endl;
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    cat->makeSound();
    dog->makeSound();

    delete cat;
    delete dog;

    std::cout << "\n===== Test Brain with Cat =====" << std::endl;
    Cat garfield;
    garfield.getBrain()->setIdea(0, "eat a pizza");
    garfield.getBrain()->setIdea(1, "watch TV");

    std::cout << "Idea[0]: " << garfield.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea[1]: " << garfield.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n===== Test Deep Copy (Cat) =====" << std::endl;
    Cat garfieldCopy(garfield); // constructeur de copie
    std::cout << "garfieldCopy Idea[0]: " << garfieldCopy.getBrain()->getIdea(0) << std::endl;
    std::cout << "garfieldCopy Idea[1]: " << garfieldCopy.getBrain()->getIdea(1) << std::endl;

    // On modifie l'original -> la copie ne doit pas changer
    garfield.getBrain()->setIdea(0, "being annoying");
    std::cout << "garfield Idea[0]: " << garfield.getBrain()->getIdea(0) << std::endl;
    std::cout << "garfieldCopy Idea[0]: " << garfieldCopy.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== Test Deep Copy (Dog) =====" << std::endl;
    Dog snoopy;
    snoopy.getBrain()->setIdea(0, "Thinking about life");
    snoopy.getBrain()->setIdea(1, "Chilling on the roof");

    Dog snoopyCopy;
    snoopyCopy = snoopy; // opérateur =

    std::cout << "snoopyCopy Idea[0]: " << snoopyCopy.getBrain()->getIdea(0) << std::endl;
    std::cout << "snoopyCopy Idea[1]: " << snoopyCopy.getBrain()->getIdea(1) << std::endl;

    // On modifie l'original -> la copie ne doit pas changer
    snoopy.getBrain()->setIdea(0, "Going on the moon");
    std::cout << "snoopy Idea[0]: " << snoopy.getBrain()->getIdea(0) << std::endl;
    std::cout << "snoopyCopy Idea[0]: " << snoopyCopy.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== Polymorphism array test =====" << std::endl;
    Animal* animals[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }
    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "\n==========" << std::endl;

	return (0);
}