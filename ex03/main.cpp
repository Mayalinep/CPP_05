#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main(){
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotoy request", "Bender");
    if (rrf) {
        std::cout << "Form successfully created!" << std::endl;
        delete rrf;
    } else {
        std::cout << "Form creation failed" << std::endl;
    }
    return 0;
}