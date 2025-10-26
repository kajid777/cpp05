#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {

private:
	const std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	
	// Getter
	const std::string getTarget() const;
	
	// Override execute method
	virtual void execute(const Bureaucrat& executor) const;
};


