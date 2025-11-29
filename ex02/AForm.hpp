#pragma once

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeSign;
		const int _gradeExec;

	public:
		AForm();
		AForm(const std::string& name, int gradeSign, int gradeExec);
		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);
		~AForm();

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};
		class NotSignedYet : public std::exception{
			public:
				const char* what() const throw();
		};
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& bu);
		virtual void execute(const Bureaucrat& executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm& f);
