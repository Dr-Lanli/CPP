#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
    std::string _name;
    bool _isSigned;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExec;
public:
    Form(const std::string &name, const int gradeRequiredToSign, const int gradeRequiredToExec);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExec() const;

    void setName(const std::string &name);
    void setIsSigned(bool isSigned);

    void beSigned(Bureaucrat &b);

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
