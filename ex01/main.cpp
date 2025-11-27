#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try {
		Bureaucrat Manager("Manager relou", 6);
		Form form1("Demande de congés", 10, 5);
		
		std::cout << Manager << std::endl;
		std::cout << form1 << std::endl;
		
		Manager.signForm(form1);
		std::cout << form1 << std::endl;
		
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
	try {
	
		Bureaucrat stagiaire("Miskine", 50);
		Form form2("Document confidentiel", 5, 3);
		
		std::cout << stagiaire << std::endl;
		std::cout << form2 << std::endl;
		
		stagiaire.signForm(form2);
		std::cout << form2 << std::endl;
		
	}
		catch (std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		return 0;
}
