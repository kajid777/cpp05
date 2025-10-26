#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {

private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	
	//getters
	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	
	//methods
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;
	
	//exceptions
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
	
	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
	
	class ExecuteGradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);


