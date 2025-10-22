#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {

private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	
	//getters
	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	
	//methods
	void beSigned(const Bureaucrat& bureaucrat);
	
	//exceptions
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

