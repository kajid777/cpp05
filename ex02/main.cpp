#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	
	// ShrubberyCreationForm Test
	std::cout << "\n=== ShrubberyCreationForm Test ===" << std::endl;
	
	// Test 1: Create and execute successfully
	std::cout << "\n[Test 1] Create ShrubberyCreationForm and execute..." << std::endl;
	ShrubberyCreationForm formA("home");
	Bureaucrat bureaucratA("John", 130);
	
	std::cout << formA << std::endl;
	std::cout << "Signing form..." << std::endl;
	bureaucratA.signForm(formA);
	std::cout << "Executing form..." << std::endl;
	formA.execute(bureaucratA);
	std::cout << "Successfully created home_shrubbery file!" << std::endl;

	
	// Test 2: Try to execute without signing
	std::cout << "\n[Test 2] Try to execute unsigned form..." << std::endl;
	ShrubberyCreationForm formB("garden");
	Bureaucrat bureaucratB("Alice", 100);
	
	std::cout << formB << std::endl;
	std::cout << "Executing form without signing..." << std::endl;
	formB.execute(bureaucratB);
	
	// Test 3: Try to execute with insufficient grade
	std::cout << "\n[Test 3] Try to execute with insufficient grade..." << std::endl;
	ShrubberyCreationForm formC("park");
	Bureaucrat signer("Boss", 1);
	Bureaucrat executor("Intern", 150);
	
	std::cout << formC << std::endl;
	std::cout << "Signing form..." << std::endl;
	signer.signForm(formC);
	std::cout << "Trying to execute with low grade bureaucrat..." << std::endl;
	formC.execute(executor);

	
	// Test 4: Try to sign with insufficient grade
	std::cout << "\n[Test 4] Try to sign with insufficient grade..." << std::endl;
	ShrubberyCreationForm formD("office");
	Bureaucrat bureaucratD("LowRank", 150);
	
	std::cout << formD << std::endl;
	std::cout << "Trying to sign with low grade bureaucrat..." << std::endl;
	bureaucratD.signForm(formD);

	return 0;
}


