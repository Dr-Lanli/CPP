#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145 ,137)
{
    _target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned() == 0)
        throw NotSignedException();
    if (executor.getGrade() <= this->getGradeRequiredToSign())
    {
        std::ofstream outfile((_target + "_shrubbery").c_str());
        outfile << "       _-_" << std::endl;
        outfile << "    /~~   ~~\\" << std::endl;
        outfile << " /~~         ~~\\" << std::endl;
        outfile << "{               }" << std::endl;
        outfile << " \\  _-     -_  /" << std::endl;
        outfile << "   ~  \\\\ /  ~" << std::endl;
        outfile << "_- -   | | _- _" << std::endl;
        outfile << "  _ -  | |   -_" << std::endl;
        outfile << "      // \\" << std::endl;
        outfile.close();
    }
    else
    {
        throw GradeTooLowException();
    }
    
    
}