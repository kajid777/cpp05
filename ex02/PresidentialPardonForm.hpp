#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {

private:
	const std::string _target;
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();
	
	// Getter
	const std::string getTarget() const;
	
	// Override execute method
	virtual void execute(const Bureaucrat& executor) const;
};


