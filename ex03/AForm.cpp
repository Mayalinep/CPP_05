#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(): _name("Default"), _isSigned(false), _gradeSign(150), _gradeExec(150){
}
		AForm::AForm(const std::string& name, int gradeSign, int gradeExec): _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec){
			if(gradeSign < 1 || gradeExec < 1){
				throw GradeTooHighException();
			}
			if(gradeSign > 150 || gradeExec > 150){
				throw GradeTooLowException();
			}
			_isSigned = false;
		}
AForm::AForm(const AForm& rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeSign(rhs._gradeSign), _gradeExec(rhs._gradeExec){
}
AForm& AForm::operator=(const AForm& rhs){
	if(this != &rhs){
		_isSigned = rhs._isSigned;
	}
	return *this;
}
AForm::~AForm(){
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade too high";
};
const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade too low";
};
const char* AForm::NotSignedYet::what() const throw(){
	return "Form is not signed yet or grade is too low to sign";
};

std::string AForm::getName() const{
	return _name;
}
bool AForm::getIsSigned() const{
	return _isSigned;
}
int AForm::getGradeSign() const{
	return _gradeSign;
}
int AForm::getGradeExec() const{
	return _gradeExec;
}
void AForm::beSigned(const Bureaucrat& bu){
	if(bu.getGrade() > _gradeSign){
		throw GradeTooLowException();
	}
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os << f.getName() << ", form grade " << f.getGradeSign() << " to sign, grade " << f.getGradeExec() << " to execute, is signed: " << f.getIsSigned() << ".";
	return os;
}
