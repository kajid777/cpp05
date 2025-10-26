#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {

private:
	const std::string _target;
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();
	
	// Getter
	const std::string getTarget() const;
	
	// Override execute method
	virtual void execute(const Bureaucrat& executor) const;
};


