#include "AForm.hpp"
#include "Bureaucrat.hpp"


//constructors
AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {};

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): 
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
};

AForm::AForm(const AForm &other): 
	_name(other.getName()), 
	_isSigned(other.getIsSigned()), 
	_gradeToSign(other.getGradeToSign()), 
	_gradeToExecute(other.getGradeToExecute()) {};

AForm::~AForm() {};

AForm& AForm::operator=(const AForm &other) {
	// self-assignment check
	if (this != &other) {
		// _name, _gradeToSign, _gradeToExecute are const and cannot be reassigned.
		this->_isSigned = other.getIsSigned();
	}
	return *this;
}

// getters
const std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// Methods
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high! (must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low! (must be <= 150)";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed! Cannot execute unsigned form.";
}

const char* AForm::ExecuteGradeTooLowException::what() const throw() {
	return "Bureaucrat grade is too low to execute this form!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form " << form.getName() 
	   << " (signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute() << ")";
	return os;
}


