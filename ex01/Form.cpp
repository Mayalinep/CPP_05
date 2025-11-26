#include "Form.hpp"


Form::Form(): _name("Default"), _gradeSign(150), _gradeExec(150), isSigned(false){
}
		Form::Form(const std::string& name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), isSigned(false){
			if(gradeSign < 1 || gradeExec < 1){
				throw GradeTooHighException();
			}
			if(gradeSign > 150 || gradeExec > 150){
				throw GradeTooLowException();
			}
			isSigned = false;
		}
		Form::Form(const Form& rhs);
		Form& Form::operator=(const Form& rhs);
		Form::~Form();

		GradeTooHighException Form::GradeTooHighException(){
		};
		GradeTooLowException Form::GradeTooLowException(){
		};

		std::string Form::getName() const;
		bool Form::getIsSigned() const;
		int Form::getGradeSign() const;
		int Form::getGradeExec() const;
		void Form::beSigned(const Bureaucrat& bu);

std::ostream& operator<<(std::ostream& os, const Form& f){
	os << f.getName() << ", form grade " << f.getGradeSign() << " to sign, grade " << f.getGradeExec() << " to execute, is signed: " << f.getIsSigned() << ".";
	return os;
}
