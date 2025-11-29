#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    
        public:
        RobotomyRequestForm( std::string target);
        std::string getTarget() const;
        void execute(const Bureaucrat& executor) const;
        ~RobotomyRequestForm();

};