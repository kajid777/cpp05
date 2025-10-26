#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		// _target is const and cannot be reassigned
	}
	return *this;
}

// Getter
const std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

// Execute method
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	// Check if form is signed
	if (!this->getIsSigned()) {
		std::cout << "ShrubberyCreationForm is not signed!" << std::endl;
        return;
	}
	
	// Check if executor has sufficient grade
	if (executor.getGrade() > this->getGradeToExecute()) {
		std::cout << "Bureaucrat grade is too low to execute ShrubberyCreationForm!" << std::endl;
        return;
	}
	
	// Create file and write ASCII trees
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open()) {
		std::cout << "Failed to create file: " << filename << std::endl;
        return;
	}
	
	// Write ASCII trees

	file << "      ccee88oo" << std::endl;
	file << "  C8O8O8Q8PoOb o8oo" << std::endl;
	file << " dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "      \\\\\\//  /douUP" << std::endl;
	file << "        \\\\\\////" << std::endl;
	file << "         |||/\\" << std::endl;
	file << "         |||\\/\\" << std::endl;
	file << "         |||||\\" << std::endl;
	file << "   .....//||||\\\\....." << std::endl;
	
	file.close();
}


