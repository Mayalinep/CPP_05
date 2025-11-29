#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){
}
std::string RobotomyRequestForm::getTarget() const{
    return _target;
}
void RobotomyRequestForm::execute(const Bureaucrat& executor) const{
    srand(time(NULL));
    int half = rand() % 2;
    if(!(getIsSigned())){
        throw AForm::NotSignedYet();
    }
    else if(executor.getGrade() > getGradeExec()){
        throw AForm::GradeTooLowException();
    }
    else if(getIsSigned() && executor.getGrade() <= getGradeExec()){
        if(half != 0){  
            std::cout << executor.getName() << " executed " << getName() << std::endl;
            std::cout << "*DRILLING NOISES*" << std::endl;
            std::cout << getTarget() << " has been robotomized successfully" << std::endl;
          
        }
        else{
            std::cout << executor.getName() << " executed " << getName() << std::endl;
            std::cout << "The robotomy failed" << std::endl;
        }
    }
}

RobotomyRequestForm::~RobotomyRequestForm(){

}