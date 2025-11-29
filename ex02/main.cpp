#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
    try {
    Bureaucrat bureaucrat("John", 1);
    ShrubberyCreationForm form("home");
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    try {
        Bureaucrat bureaucrat("Pere Noel", 150);
        PresidentialPardonForm test("prisonner");
            bureaucrat.signForm(test);
            bureaucrat.executeForm(test);
        }
        catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    std::cout << "--------------------------------" << std::endl;
    try {
        Bureaucrat bureaucrat("Frankenstein", 150);
        RobotomyRequestForm loboto("Monster's Frankenstein");
            bureaucrat.signForm(loboto);
            bureaucrat.executeForm(loboto);
        }
        catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        }
        return 0;
}