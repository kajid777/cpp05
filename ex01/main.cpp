#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	
	// フォームの作成
	std::cout << "\n[Form Test 1] Creating forms..." << std::endl;
	try {
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
		
		Form form2("Contract", 10, 5);
		std::cout << form2 << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// beSigned()のテスト - 成功
	std::cout << "\n[Form Test 2] Bureaucrat with sufficient grade signs form..." << std::endl;
	try {
		Bureaucrat highRankBureaucrat("Boss", 1);
		Form form3("Important Document", 50, 25);
		std::cout << "Before: " << form3 << std::endl;
		form3.beSigned(highRankBureaucrat);
		std::cout << "After: " << form3 << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// beSigned()のテスト - 失敗（グレード不足）
	std::cout << "\n[Form Test 3] Bureaucrat with insufficient grade tries to sign form..." << std::endl;
	try {
		Bureaucrat lowRankBureaucrat("Intern", 100);
		Form form4("Top Secret Document", 10, 5);
		std::cout << "Before: " << form4 << std::endl;
		std::cout << "Bureaucrat " << lowRankBureaucrat.getName() << " (grade " << lowRankBureaucrat.getGrade() << ") tries to sign..." << std::endl;
		form4.beSigned(lowRankBureaucrat);
		std::cout << "After: " << form4 << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// 不正なグレードでフォーム作成
	std::cout << "\n[Form Test 4] Creating form with invalid grade..." << std::endl;
	try {
		Form invalidForm("Invalid", 0, 50);
		std::cout << invalidForm << std::endl;
	} catch (const Form::GradeTooHighException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// signForm()のテスト
	std::cout << "\n\n=== signForm() Test ===" << std::endl;
	
	// 成功するケース
	std::cout << "\n[signForm Test 1] High rank bureaucrat signs form..." << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		Form form("Contract A", 50, 25);
		std::cout << "Before: " << form << std::endl;
		boss.signForm(form);
		std::cout << "After: " << form << std::endl;
	}
	
	// 失敗するケース
	std::cout << "\n[signForm Test 2] Low rank bureaucrat tries to sign form..." << std::endl;
	{
		Bureaucrat intern("Intern", 100);
		Form topSecretForm("Top Secret", 10, 5);
		std::cout << "Before: " << topSecretForm << std::endl;
		intern.signForm(topSecretForm);
		std::cout << "After: " << topSecretForm << std::endl;
	}

	
	return 0;
}


