#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
    try
    {
        // Cas classique
        Bureaucrat worker("Elena", 15);
        std::cout << worker << std::endl;

        ShrubberyCreationForm form1("home");
        std::cout << form1 << std::endl;

        worker.signForm(form1);
        std::cout << form1 << std::endl;
        worker.executeForm(form1);

        // Robotomy request
        RobotomyRequestForm form2("random human");
        std::cout << form2 << std::endl;

        worker.signForm(form2);
        std::cout << form2 << std::endl;
        worker.executeForm(form2);

        // Presidential pardon
        PresidentialPardonForm form3("random worker");
        std::cout << form3 << std::endl;

        worker.signForm(form3);
        std::cout << form3 << std::endl;
        worker.executeForm(form3);

        std::cout << "\n===== TESTS ERRORS =====" << std::endl;

        // 1. Essayer d'exécuter sans avoir signé
        try 
        {
            ShrubberyCreationForm form4("garden");
            std::cout << form4 << std::endl;
            worker.executeForm(form4);
        } 
        catch (const std::exception &e) 
        {
            std::cerr << "Error expected (form not signed) : " << e.what() << std::endl;
        }

        // 2. Bureaucrat trop bas pour signer
        try 
        {
            Bureaucrat low("Intern", 150);
            RobotomyRequestForm form5("victim");
            std::cout << form5 << std::endl;
            low.signForm(form5);
        } 
        catch (const std::exception &e) 
        {
            std::cerr << "Error expected (grade too low to signed) : " << e.what() << std::endl;
        }

        // 3. Bureaucrat peut signer mais pas exécuter
        try 
        {
            Bureaucrat mid("Louis", 140);
            ShrubberyCreationForm form6("park");
            mid.signForm(form6);
            mid.executeForm(form6);
        } 
        catch (const std::exception &e) 
        {
            std::cerr << "Error expected (grade) : " << e.what() << std::endl;
        }

        // 4. Test polymorphisme
        try 
        {
            Bureaucrat boss("Alicia", 1);
            AForm *polyForm = new PresidentialPardonForm("VIP");
            std::cout << *polyForm << std::endl;

            boss.signForm(*polyForm);
            boss.executeForm(*polyForm);

            delete polyForm;
        } 
        catch (const std::exception &e) 
        {
            std::cerr << "Error unexpected : " << e.what() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Critical error : " << e.what() << std::endl;
    }
    return 0;
}