#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>

class Bureaucrat;

class AForm
{
private:
    std::string _name;
    bool _isSigned;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExec;
public:
    AForm(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExec);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExec() const;

    void setName(const std::string &name);
    void setIsSigned(bool isSigned);

    void beSigned(Bureaucrat &b);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    class NotSignedException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
