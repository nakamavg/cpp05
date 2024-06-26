#include "ShrubberyCreationForm.hpp"
#include <fstream>

#include "ShrubberyCreationForm.hpp"

class ShrubberyCreationForm::FileError : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Cannot open file\n"); }
};

std::string ShrubberyCreationForm::asciiTree =
"       _-_\n"	
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
;

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("ShrubberyCreationForm", 145, 137), target (target) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src )
    : AForm(src.name,src.gradeToSign, src.gradeToExecute) {
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src ) {
    if (this != &src) {
        this->target = src.target;
		this->asciiTree = src.asciiTree;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
}

std::string ShrubberyCreationForm::getTarget( void ) {
	return (this->target);
}

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
    AForm::execute(executor);
    try {
        writeFile();
        std::cout << executor.getName() << " successfully executed " << this->getName() << " form." << std::endl;
    } catch(std::exception &e) {
        std::cout << e.what() << " to execute" << std::endl;
    }
}

void ShrubberyCreationForm::writeFile( void ) const {
    std::ofstream outFile;
    std::string filename = target + "_shrubbery";
	outFile.open(filename.c_str());
	
	if (!outFile.is_open())
		throw ShrubberyCreationForm::FileError();
	outFile << asciiTree;
    outFile.close();
}
