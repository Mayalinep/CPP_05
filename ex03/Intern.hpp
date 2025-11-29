#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    private:
        struct FormType{
            std::string name;
            AForm* (*createFunction)(const std::string&);
        };

        static AForm* createShrubbery(const std::string &target);
        static AForm* createRobotomy(const std::string &target);
        static AForm* createPresidential(const std::string &target);

        static const FormType _formTypes[3];

    public:
        Intern();
        Intern(const Intern& rhs);
        Intern& operator=(const Intern& rhs);

        AForm* makeForm(std::string formName, std::string target);

        ~Intern();

};