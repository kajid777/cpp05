#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {

private:
	const std::string _name;
	int _grade;
	//setters (private)
	void setGrade(int grade);
	void setName(std::string name);
	
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	//getters
	const std::string getName() const;
	int getGrade() const;
	
	//methods
	void signForm(AForm& form);
	void executeForm(AForm const & form) const;
	
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

