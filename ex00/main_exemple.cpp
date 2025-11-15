#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1 : Construction valide ===" << std::endl;
    Bureaucrat b1("Alice", 50);  // Pas d'exception, donc pas besoin de try/catch
    std::cout << b1 << std::endl;
    
    std::cout << "\n=== Test 2 : Construction invalide (note trop haute) ===" << std::endl;
    try {
        // On essaie de créer un Bureaucrat avec note = 0 (invalide)
        Bureaucrat b2("Bob", 0);
        // Cette ligne ne sera JAMAIS exécutée car l'exception sera levée
        std::cout << b2 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        // On "attrape" l'exception ici
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 3 : Construction invalide (note trop basse) ===" << std::endl;
    try {
        Bureaucrat b3("Charlie", 200);  // Note trop basse
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 4 : Capturer n'importe quelle exception ===" << std::endl;
    try {
        Bureaucrat b4("David", -5);  // Note invalide
    }
    catch (std::exception& e) {
        // std::exception est la classe de base, donc ça attrape TOUTES les exceptions
        std::cout << "Exception générique : " << e.what() << std::endl;
    }
    
    return 0;
}

