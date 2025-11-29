#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){
}
std::string ShrubberyCreationForm::getTarget() const{
    return _target;
}
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
    if(getIsSigned() && executor.getGrade() <= getGradeExec()){
        std::cout << executor.getName() << " executed " << getName() << std::endl;
        std::ofstream file(getTarget() + "_shrubbery");
        if(file.is_open()){
        file << "     *" << std::endl;
        file << "    ***" << std::endl;
        file << "   *****" << std::endl;
        file << "  *******" << std::endl;
        file << " *********" << std::endl;
        file << "***********" << std::endl;
        file << "   |   |" << std::endl;
        file << "   |   |" << std::endl;
        file << "   |   |" << std::endl;
        file << "   |   |" << std::endl;
        file << " ===   ===" << std::endl;
        file.close();
        }
        else{
            throw std::runtime_error("Failed to open file");
        }
    }
    else if(!getIsSigned()){
        throw AForm::NotSignedYet();
    }
    else{
        throw AForm::GradeTooLowException();
    }
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
}