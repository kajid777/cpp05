#include "Form.hpp"
#include "Bureaucrat.hpp"


//constructors
Form::Form(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {};

Form::Form(std::string name, int gradeToSign, int gradeToExecute): 
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
};

Form::Form(const Form &other): 
	_name(other.getName()), 
	_isSigned(other.getIsSigned()), 
	_gradeToSign(other.getGradeToSign()), 
	_gradeToExecute(other.getGradeToExecute()) {};

Form::~Form() {};

Form& Form::operator=(const Form &other) {
	// self-assignment check
	if (this != &other) {
		// _name, _gradeToSign, _gradeToExecute are const and cannot be reassigned.
		this->_isSigned = other.getIsSigned();
	}
	return *this;
}

// getters
const std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// Methods
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

// Exception implementations
const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high! (must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low! (must be <= 150)";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form " << form.getName() 
	   << " (signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute() << ")";
	return os;
}

