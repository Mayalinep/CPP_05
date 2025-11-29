#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
			};
		class GradeTooLowException : public std::exception {
				public:
					const char* what() const throw();
			};
		void signForm(AForm& aform);
		void executeForm(AForm& aform);
		~Bureaucrat();
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);