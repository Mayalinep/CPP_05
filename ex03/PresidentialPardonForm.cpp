#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){}

std::string PresidentialPardonForm::getTarget() const{
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
    if(getIsSigned() && executor.getGrade() <= getGradeExec()){
        std::cout << executor.getName() << " executed " << getName() << std::endl;
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"<< std::endl;
    }
    else if(!(getIsSigned())){
        throw AForm::NotSignedYet();
    }
    else
        throw AForm::GradeTooLowException();
}

PresidentialPardonForm::~PresidentialPardonForm(){

}
