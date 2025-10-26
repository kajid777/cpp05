#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

	// RobotomyRequestForm Test
	std::cout << "\n\n=== RobotomyRequestForm Test ===" << std::endl;
	
	// Test 1: Create and execute successfully
	std::cout << "\n[Test 1] Create RobotomyRequestForm and execute..." << std::endl;
	RobotomyRequestForm robotForm1("Bender");
	Bureaucrat robotBureaucrat1("Jane", 40);
	
	std::cout << robotForm1 << std::endl;
	std::cout << "Signing form..." << std::endl;
	robotBureaucrat1.signForm(robotForm1);
	std::cout << "Executing form..." << std::endl;
	robotForm1.execute(robotBureaucrat1);
	
	// Test 2: Try multiple times to see 50% chance
	std::cout << "\n[Test 2] Execute multiple times to see randomness..." << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "\nAttempt " << (i + 1) << ":" << std::endl;
		robotForm1.execute(robotBureaucrat1);
	}
	
	// Test 3: Try to execute without signing
	std::cout << "\n[Test 3] Try to execute unsigned form..." << std::endl;
	RobotomyRequestForm robotForm2("Marvin");
	Bureaucrat robotBureaucrat2("Bob", 30);
	
	std::cout << robotForm2 << std::endl;
	std::cout << "Executing form without signing..." << std::endl;
	robotForm2.execute(robotBureaucrat2);
	
	// Test 4: Try to execute with insufficient grade
	std::cout << "\n[Test 4] Try to execute with insufficient grade..." << std::endl;
	RobotomyRequestForm robotForm3("C-3PO");
	Bureaucrat robotSigner("Manager", 1);
	Bureaucrat robotExecutor("Trainee", 100);
	
	std::cout << robotForm3 << std::endl;
	std::cout << "Signing form..." << std::endl;
	robotSigner.signForm(robotForm3);
	std::cout << "Trying to execute with low grade bureaucrat..." << std::endl;
	robotForm3.execute(robotExecutor);

	// PresidentialPardonForm Test
	std::cout << "\n\n=== PresidentialPardonForm Test ===" << std::endl;
	
	// Test 1: Create and execute successfully
	std::cout << "\n[Test 1] Create PresidentialPardonForm and execute..." << std::endl;
	PresidentialPardonForm pardonForm1("Arthur Dent");
	Bureaucrat pardonBureaucrat1("President", 1);
	
	std::cout << pardonForm1 << std::endl;
	std::cout << "Signing form..." << std::endl;
	pardonBureaucrat1.signForm(pardonForm1);
	std::cout << "Executing form..." << std::endl;
	pardonForm1.execute(pardonBureaucrat1);
	
	// Test 2: Try to execute without signing
	std::cout << "\n[Test 2] Try to execute unsigned form..." << std::endl;
	PresidentialPardonForm pardonForm2("Ford Prefect");
	Bureaucrat pardonBureaucrat2("Vice President", 3);
	
	std::cout << pardonForm2 << std::endl;
	std::cout << "Executing form without signing..." << std::endl;
	pardonForm2.execute(pardonBureaucrat2);
	
	// Test 3: Try to execute with insufficient grade
	std::cout << "\n[Test 3] Try to execute with insufficient grade..." << std::endl;
	PresidentialPardonForm pardonForm3("Trillian");
	Bureaucrat pardonSigner("President", 1);
	Bureaucrat pardonExecutor("Assistant", 10);
	
	std::cout << pardonForm3 << std::endl;
	std::cout << "Signing form..." << std::endl;
	pardonSigner.signForm(pardonForm3);
	std::cout << "Trying to execute with low grade bureaucrat..." << std::endl;
	pardonForm3.execute(pardonExecutor);
	
	// Test 4: Try to sign with insufficient grade
	std::cout << "\n[Test 4] Try to sign with insufficient grade..." << std::endl;
	PresidentialPardonForm pardonForm4("Zaphod");
	Bureaucrat pardonBureaucrat4("Secretary", 50);
	
	std::cout << pardonForm4 << std::endl;
	std::cout << "Trying to sign with low grade bureaucrat..." << std::endl;
	pardonBureaucrat4.signForm(pardonForm4);

	return 0;
}


