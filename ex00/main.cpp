#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat David("David", 2);
        std::cout << David << std::endl;

        David.incrementGrade();
        std::cout << David << std::endl;

        David.incrementGrade(); // Debería lanzar GradeTooHighException
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat rigoberta("rigoberta", 150);
        std::cout << rigoberta << std::endl;

        rigoberta.decrementGrade(); // Debería lanzar GradeTooLowException
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
