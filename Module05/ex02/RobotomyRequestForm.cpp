#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    srand(time(0));

    int n = rand() % 1;
    if (this->getIsSigned() == 0)
        throw NotSignedException();
    if (executor.getGrade() <= this->getGradeRequiredToSign())
    {

        std::cout << "*some drilling noises* ... *some drilling noises* ..." << std::endl;
        sleep(2);
        std::cout << "*some drilling noises* ... *some drilling noises* ..." << std::endl;
        sleep(2);
        
        if (n == 1)
            std::cout << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << _target << "'s robotomy failed" << std::endl;
        
    }
    else
    {
        throw GradeTooLowException();
    }
    
    
}