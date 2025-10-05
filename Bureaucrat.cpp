#include "Bureaucrat.hpp"


//constructors
Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {};
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {};

Bureaucrat::~Bureaucrat() {};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	// self-assignment check
    if (this != &other) {
        // _name is const and cannot be reassigned.
        // const_cast<std::string&>(this->_name) = other.getName(); // This would be bad practice.
        this->_grade = other.getGrade();
		this->_name = other.getName();
    }
    return *this;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
};
const std::string Bureaucrat::getName() const {
	return this->_name;
};

void Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
};
