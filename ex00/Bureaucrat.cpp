#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name){
	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs): _name(rhs._name), _grade(rhs._grade){
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
	if(this != &rhs)
		_grade = rhs._grade;
	return *this;
}
std::string Bureaucrat::getName() const{
	return _name;
}
int Bureaucrat::getGrade() const{
	return _grade;
}
void Bureaucrat::incrementGrade(){
	if(_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade(){
	if(_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return os;
}


const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

Bureaucrat::~Bureaucrat(){
}