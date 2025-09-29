#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
    std::string _name;
    int _grade;
public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    
    
    std::string getName() const;
    void setName(const std::string &name);
    int getGrade() const;
    void setGrade(const int &grade);
    
    class GradeTooHighException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception 
    {
        public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif