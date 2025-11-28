#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

enum string_forms {
    eShrubberyCreationForm,
    eRobotomyRequestForm,
    ePresidentialPardonForm,
    eUnknown
};

string_forms hashstr(std::string &inString) 
{
    std::transform(inString.begin(), inString.end(), inString.begin(), ::tolower);
    if (inString == "shrubbery creation")
        return (eShrubberyCreationForm);
    if (inString == "robotomy request")
        return (eRobotomyRequestForm);
    if (inString == "presidential pardon")
        return (ePresidentialPardonForm);
    return (eUnknown);
}

AForm *Intern::makeForm(std::string formName, std::string targetForm)
{
     AForm *form = NULL;
    switch (hashstr(formName))
    {
    case eShrubberyCreationForm:
        form = new ShrubberyCreationForm(targetForm);
        break ;
    case eRobotomyRequestForm:
        form = new RobotomyRequestForm(targetForm);
        break ;
    case ePresidentialPardonForm:
        form = new PresidentialPardonForm(targetForm);
        break ;
    default:
        return (NULL);
    }
    std::cout << "Intern creates " << formName << std::endl;
    return (form);
}