#pragma once

#include <string>

class Bureaucrat {

private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	//getters
	const std::string getName() const;
	int getGrade() const;
	//setters
	void setGrade(int grade);
	void setName(std::string name);
};