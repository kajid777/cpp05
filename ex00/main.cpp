#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Bureaucrat Test ===" << std::endl;
	
	// デフォルトコンストラクタでインスタンス化
	Bureaucrat b1;
	std::cout << "Bureaucrat 1: " << b1 << std::endl;
	
	// パラメータ付きコンストラクタでインスタンス化
	Bureaucrat b2("John", 50);
	std::cout << "Bureaucrat 2: " << b2 << std::endl;

    Bureaucrat b3(b2);
    std::cout << "Bureaucrat 3: " << b3 << std::endl;

    Bureaucrat b4 = b2;
    std::cout << "Bureaucrat 4: " << b4 << std::endl;
	
	// 例外処理のテスト 
	std::cout << "\n=== Exception Test ===" << std::endl;
	
	// GradeTooHighException のテスト（grade < 1）
	std::cout << "\n[Test 1] Trying to create bureaucrat with grade 0..." << std::endl;
	try {
		Bureaucrat b5("Alice", 0);
		std::cout << b5 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	// GradeTooLowException のテスト（grade > 150）
	std::cout << "\n[Test 2] Trying to create bureaucrat with grade 151..." << std::endl;
	try {
		Bureaucrat b6("Charlie", 151);
		std::cout << b6 << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// 正常なケース
	std::cout << "\n[Test 3] Creating bureaucrat with valid grade 1..." << std::endl;
	try {
		Bureaucrat b7("Diana", 1);
		std::cout << "Success: " << b7 << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// 正常なケース - 最大値
	std::cout << "\n[Test 4] Creating bureaucrat with valid grade 150..." << std::endl;
	try {
		Bureaucrat b8("Frank", 150);
		std::cout << "Success: " << b8 << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}

