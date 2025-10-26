#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <new>

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern::~Intern() {
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	
	// フォーム名を検索
	int index = -1;
	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			index = i;
			break;
		}
	}
	
	// フォーム名が見つからない場合
	if (index == -1) {
		std::cerr << "Error: Form name \"" << formName << "\" does not exist" << std::endl;
		return NULL;
	}
	
	// 適切なフォームを作成
	try {
		switch (index) {
			case 0:
				std::cout << "Intern creates presidential pardon" << std::endl;
				return new PresidentialPardonForm(target);
			case 1:
				std::cout << "Intern creates robotomy request" << std::endl;
				return new RobotomyRequestForm(target);
			case 2:
				std::cout << "Intern creates shrubbery creation" << std::endl;
				return new ShrubberyCreationForm(target);
			default:
				return NULL;
		}
	} catch (const std::bad_alloc& e) {
		std::cerr << "Error: Memory allocation failed: " << e.what() << std::endl;
		return NULL;
	}
}

