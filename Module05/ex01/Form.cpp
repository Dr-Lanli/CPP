#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExec) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExec(gradeRequiredToExec)
{
    _isSigned = false;
    if (_gradeRequiredToSign < 1)
        throw GradeTooHighException();
    if (_gradeRequiredToExec < 1)
        throw GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &other) : _name(other._name), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExec(other._gradeRequiredToExec)
{
    this->_isSigned = other._isSigned;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_isSigned = other._isSigned;
    }
    return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too Low");
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getIsSigned() const
{
    return (_isSigned);
}

int Form::getGradeRequiredToSign() const
{
    return (_gradeRequiredToSign);
}

int Form::getGradeRequiredToExec() const
{
    return (_gradeRequiredToExec);
}

void Form::setName(const std::string &name)
{
    _name = name;
}

void Form::setIsSigned(bool isSigned)
{
    _isSigned = isSigned;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= _gradeRequiredToSign)
    {
        std::cout << b.getName() << ", signed " << _name << std::endl;
        _isSigned = true;
    }
    else
    {
        throw GradeTooLowException();
        std::cout << b.getName() << ", couldn' sign " << _name << "because his grade: " << b.getGrade() << " is lower than the form grade: " << _gradeRequiredToSign << std::endl;
    }
    
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName() << ": " << std::endl;
    os << "is signed: " << f.getIsSigned() << std::endl;
    os << "grade required to sign: " << f.getGradeRequiredToSign() << std::endl;
    os << "grade required to exec: " << f.getGradeRequiredToExec() << std::endl;
    return (os);
}