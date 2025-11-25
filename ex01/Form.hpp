#pragma once

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		bool isSigned;
		coonst int _gradeSign;
		cont int _gradeExec;

	public:
		Form();
		Form(const std::string& name, int gradeSign, int gradeExec);
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		~Form();

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& bu);
};
std::ostream& operator<<(std::ostream& os, const Form& f);
