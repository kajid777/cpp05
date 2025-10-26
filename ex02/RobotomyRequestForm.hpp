#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {

private:
	const std::string _target;
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();
	
	// Getter
	const std::string getTarget() const;
	
	// Override execute method
	virtual void execute(const Bureaucrat& executor) const;
};


