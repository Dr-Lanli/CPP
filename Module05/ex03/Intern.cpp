#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
}

Intern &Intern::operator=(const Intern &other)
{
    return (*this);
}

enum string_forms {
    eShrubberyCreationForm,
    eRobotomyRequestForm,
    ePresidentialPardonForm,
    eUnknown
};

string_forms hashit (std::string const& inString) {
    if (inString == "ShrubberyCreationForm")
        return (eShrubberyCreationForm);
    if (inString == "RobotomyRequestForm")
        return (eRobotomyRequestForm);
    if (inString == "PresidentialPardonForm")
        return (ePresidentialPardonForm);
    return eUnknown;
}

AForm *Intern::makeForm(std::string formName, std::string targetForm)
{
    //AForm *form = new form(formName);
    switch (formName)
    {
    case constant expression:
        /* code */
        break;
    case 
    default:
        break;
    }
    std::cout << "Intern creates " << formName << std::endl;
}