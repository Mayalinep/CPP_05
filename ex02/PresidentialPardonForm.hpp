#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;

    public:
        PresidentialPardonForm(std::string target);
        std::string getTarget() const;
        void execute(const Bureaucrat& executor) const;
        ~PresidentialPardonForm();
};

