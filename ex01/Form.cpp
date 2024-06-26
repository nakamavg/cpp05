#include "Form.hpp"

class Form::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Grade too low"); } 
};

class Form::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return ("Grade too high"); }
};

Form::Form( void )
	: name ("Unnamed"), isSigned (false), signGrade(0), execGrade(0) {
}

Form::Form ( std::string n, int gts, int gte )
	: name (n), isSigned (false), signGrade(gts), execGrade(gte) {
	if (this->signGrade < 1 || this->execGrade < 1)
        throw Form::GradeTooHighException();
    if (this->signGrade > 150 || this->execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form( const Form &src )
	: name (src.name), isSigned (src.isSigned), signGrade(src.signGrade), execGrade(src.execGrade) {
	*this = src;
}

Form &Form::operator=( const Form &src ) {
	if (this == &src)
		return (*this);
	return (*this);
}

Form::~Form( void ) {
}

std::string Form::getName( void ) const {
	return (this->name);
}

bool Form::getIsSigned( void ) {
	return (this->isSigned);
}

void Form::setIsSigned( bool state ) {
	this->isSigned = state;
}


int Form::getSignGrade( void ) const {
	return (this->signGrade);
}

int Form::getExecGrade( void ) const {
	return (this->execGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream &operator<<( std::ostream &os, Form &f ) {
	os << "Form name: " << f.getName() 
	<< ".\nsigned state: " << f.getIsSigned() 
	<< ".\ngrade required to sign: " << f.getSignGrade()
	<< ".\ngrade required to execute: "
	<< f.getExecGrade() << ".\n";
	return (os);
}