#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    _name = name;
    _grade = grade;
    if (_grade < 1)
    {
        throw GradeTooHighException();
    }
    if (_grade > 150)
    {
        throw GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    this->_grade = other._grade;
    this->_name = other._name;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
        this->_name = other._name;   
    }
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

void Bureaucrat::setName(const std::string &name)
{
    _name = name;
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::setGrade(const int &grade) 
{
    if (grade < 1) 
        throw GradeTooHighException();
    if (grade > 150) 
        throw GradeTooLowException();
    _grade = grade;
}

void Bureaucrat::signForm(Form &f)
{
    f.beSigned(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}