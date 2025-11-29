#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(std::string target);
        std::string getTarget() const;
        void execute(const Bureaucrat& executor) const;
        ~ShrubberyCreationForm();
};