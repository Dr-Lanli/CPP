#include "Serializer.hpp"

std::string *Serializer::_sLine = NULL;

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return (*this);
}

const char* Serializer::CreatingFileException::what() const throw()
{
    return ("Error while creating the file");
}

uintptr_t Serializer::serialize(Data *ptr)
{
    std::ofstream write("data.dat");

    if (!write) 
    {
        throw Serializer::CreatingFileException();
    }
    write << "name: " << ptr->name << ", age: " << ptr->age << ", gender: " << ptr->gender << std::endl;

    write.close();

    std::ifstream read("data.dat");
    if (!read) 
    {
        throw Serializer::CreatingFileException();
    }
    Serializer::_sLine = new std::string();
    std::getline(read, *_sLine);
    const char *str = _sLine->c_str();
    uintptr_t raw = reinterpret_cast<uintptr_t>(str);
    
    // delete _sLine a l'extérieur de la fonction

    return (raw);
}

// format : [^,] prend tous les characters jusqu'à une virgule
// sscanf() permet ici de parser et d'extraire correctement les données de str pour remplir la nouvelle struct
Data* Serializer::deserialize(uintptr_t raw)
{
    const char* str = reinterpret_cast<const char*>(raw);
    Data* data = new Data();
    const char *format = "name: %[^,], age: %d, gender: %s";

    std::sscanf(str, format, data->name, &data->age, data->gender);

    delete Serializer::_sLine;
    return (data);
}

/*
uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}*/

/*Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}*/