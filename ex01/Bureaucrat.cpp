#include "Bureaucrat.hpp"
#include "Form.hpp"


//constructors
Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
};

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other.getName()), _grade(other.getGrade()) {};

Bureaucrat::~Bureaucrat() {};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	// self-assignment check
    if (this != &other) {
        // _name is const and cannot be reassigned.
        this->_grade = other.getGrade();
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
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
};

// Methods
void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() 
		          << " because bureaucrat's grade is too low." << std::endl;
	}
}

// Exception implementations
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high! (must be >= 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low! (must be <= 150)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

