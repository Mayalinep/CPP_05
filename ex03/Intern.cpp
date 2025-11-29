#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){

}
Intern::Intern(const Intern& rhs){
    (void)rhs;
}

Intern& Intern::operator=(const Intern& rhs){
    if(this != &rhs){
        (void)rhs;
    }
    return *this;
}

AForm* Intern::createShrubbery(const std::string &target){
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string &target){
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidential(const std::string &target){
    return new PresidentialPardonForm(target);
}
const Intern::FormType Intern::_formTypes[3] = {
    {"shrubbery creation", &Intern::createShrubbery},
    {"robotomy request", &Intern::createRobotomy},
    {"presidential pardon", &Intern::createPresidential}
};

AForm* Intern::makeForm(std::string formName, std::string target){
    for(int i = 0; i < 3; i++){
        if(_formTypes[i].name == formName){
            std::cout << "Intern creates "<< formName << std::endl;
            return _formTypes[i].createFunction(target);
        }
    }
    std::cout <<"Error: form doesn't exist" << std::endl;
    return NULL;
}

Intern::~Intern(){

}