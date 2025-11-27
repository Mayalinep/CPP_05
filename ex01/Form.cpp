#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(): _name("Default"), _isSigned(false), _gradeSign(150), _gradeExec(150){
}
		Form::Form(const std::string& name, int gradeSign, int gradeExec): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec){
			if(gradeSign < 1 || gradeExec < 1){
				throw GradeTooHighException();
			}
			if(gradeSign > 150 || gradeExec > 150){
				throw GradeTooLowException();
			}
			_isSigned = false;
		}
Form::Form(const Form& rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeSign(rhs._gradeSign), _gradeExec(rhs._gradeExec){
}
Form& Form::operator=(const Form& rhs){
	if(this != &rhs){
		_isSigned = rhs._isSigned;
	}
	return *this;
}
Form::~Form(){
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high";
};
const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too low";
};

std::string Form::getName() const{
	return _name;
}
bool Form::getIsSigned() const{
	return _isSigned;
}
int Form::getGradeSign() const{
	return _gradeSign;
}
int Form::getGradeExec() const{
	return _gradeExec;
}
void Form::beSigned(const Bureaucrat& bu){
	if(bu.getGrade() > _gradeSign){
		throw GradeTooLowException();
	}
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f){
	os << f.getName() << ", form grade " << f.getGradeSign() << " to sign, grade " << f.getGradeExec() << " to execute, is signed: " << f.getIsSigned() << ".";
	return os;
}
