#include "Bureaucrat.hpp"



int main(){
	try{

	Bureaucrat ax("Bigboss relou", 1);
	std::cout << ax << std::endl;
	std::cout << "Bunshin no Jutsu "<< ax.getName() << std::endl;
	Bureaucrat ay(ax);
	std::cout << ay << std::endl;
	ay.decrementGrade();
	std::cout << ay << std::endl;
	std::cout << std::endl;
	Bureaucrat aw( "stagiaire relou", 150);
	std::cout << aw << std::endl;
	aw = ax;
	std::cout << std::endl;
	std::cout << "Henge no Jutsu - Superfilon pour " << aw.getName() << std::endl;
	std::cout << aw << std::endl;
	std::cout << "stagiaire relou souhaite devenir le nouveau Bigboss" << std::endl;
	aw. incrementGrade();
	std::cout << aw << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "Exception capturée : " << e.what() << std::endl;
	}
	std::cout<<std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << " Deux tests de construction invalide" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	try{
		Bureaucrat a("Bidouchou", 151);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "Exception capturée : " << e.what() << std::endl;
	}
	try{
		Bureaucrat b("Choubidou", 0);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "Exception capturée : " << e.what() << std::endl;
	}
	return 0;
}