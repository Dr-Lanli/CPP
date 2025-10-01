#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExec) : _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExec(gradeRequiredToExec)
{
    _isSigned = false;
    if (_gradeRequiredToSign < 1)
        throw GradeTooHighException();
    if (_gradeRequiredToExec < 1)
        throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExec(other._gradeRequiredToExec)
{
    this->_isSigned = other._isSigned;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_isSigned = other._isSigned;
    }
    return (*this);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too Low");
}

std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getIsSigned() const
{
    return (_isSigned);
}

int AForm::getGradeRequiredToSign() const
{
    return (_gradeRequiredToSign);
}

int AForm::getGradeRequiredToExec() const
{
    return (_gradeRequiredToExec);
}

void AForm::setName(const std::string &name)
{
    _name = name;
}

void AForm::setIsSigned(bool isSigned)
{
    _isSigned = isSigned;
}

void AForm::beSigned(Bureaucrat &b)
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

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName() << ": " << std::endl;
    os << "is signed: " << f.getIsSigned() << std::endl;
    os << "grade required to sign: " << f.getGradeRequiredToSign() << std::endl;
    os << "grade required to exec: " << f.getGradeRequiredToExec() << std::endl;
    return (os);
}