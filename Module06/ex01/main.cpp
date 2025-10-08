#include "Serializer.hpp"

int main (void)
{
    try
    {
        Data* ptr = new Data;

        // utiliser strcpy pour les char[] de la data structure

        std::strcpy(ptr->name, "Valentin");
        ptr->age = 25;
        std::strcpy(ptr->gender, "M");

        uintptr_t raw = Serializer::serialize(ptr);
        Data* recovered = Serializer::deserialize(raw);

        std::cout << recovered->name << std::endl;
        std::cout << recovered->age << std::endl;
        std::cout << recovered->gender << std::endl;

        delete ptr;
        delete recovered;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}