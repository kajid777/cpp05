#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructors
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		// _target is const and cannot be reassigned
	}
	return *this;
}

// Getter
const std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

// Execute method
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	// Check if form is signed
	if (!this->getIsSigned()) {
		throw FormNotSignedException();
	}
	
	// Check if executor has sufficient grade
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw ExecuteGradeTooLowException();
	}
	
	// Make some drilling noises
	std::cout << "* Drilling noises *" << std::endl;
	std::cout << "Bzzzzzz... Whirrrrr... Clank clank..." << std::endl;
	
	// 50% chance of success	
	if (std::rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
	}
}


