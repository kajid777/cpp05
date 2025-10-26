#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Constructors
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		// _target is const and cannot be reassigned
	}
	return *this;
}

// Getter
const std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

// Execute method
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	// Check if form is signed
	if (!this->getIsSigned()) {
		throw FormNotSignedException();
	}
	
	// Check if executor has sufficient grade
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw ExecuteGradeTooLowException();
	}
	
	// Inform that target has been pardoned
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


