#include <iostream>

#include "bank_account.h"

using namespace std;

int main(){
	// Dynamic variables
	// Calling constructor with parametrs
	BankAccount* acc_ptr1 = new BankAccount("Alex", "0x12345", 12000);
	BankAccount* acc_ptr2 = new BankAccount("Max", "0x43123", 50000);
	// Calling constructor with all default parametrs - for caller it mean default constructor (BankAccount())
	// If we have not constructor with all default parametrs
	// The code below will not compile.
	BankAccount* acc_ptr3 = new BankAccount;
	// Automatic  variable.	
	BankAccount test = BankAccount();

	// Methods a the same between objects - calling the same code when we invoke method from object.
	// Access in method code to fields of object achived by passing implicitly pointer to caller object (structure with fields).
	// Method of class have the same address between two different objects. Methods do not
	// locate in every object of class. Class - user defined type, 
	// but object is instance of class. But to call
	// not static methods, we should apply operator . for concrete object
	// ISO C++ forbids getting address of methods from concrete object as it shown below:
	//
	// auto address_1 = &acc_ptr1->Show; // error
	// void(*address_2)(void) = &acc_ptr2->Show; // error
	// void(*address_3)(void) = &acc_ptr3->Show; // error
	// We only can get address if we call &BankAccount::Show - right 
	// (method from BankAccount namespace or field of view)
	void(BankAccount::*ptr_method1)() const = &BankAccount::Show; 	
	// Calling of methods looks like sending message to object if saying in OOP terms.


	std::cout << "Address of method Show: " << (void*)ptr_method1 << std::endl;
	bool(BankAccount::*ptr_method2)(unsigned long long) = &BankAccount::AddMoney;
	std::cout << "Address of method AddMoney: " << (void*)ptr_method2 << std::endl;
	bool(BankAccount::*ptr_method3)(unsigned long long) = &BankAccount::WithdrawMoney;
	std::cout << "Address of method WithdrawMoney: " << (void*)ptr_method3 << std::endl;

	// Let's call Show, AddMoney, WithdrawMoney.
	acc_ptr1->AddMoney(1000);
	acc_ptr1->WithdrawMoney(13000);
	acc_ptr1->Show();
	acc_ptr2->Show();
	acc_ptr1->WithdrawMoney(11000);
	acc_ptr1->Show();


	delete acc_ptr1;
	delete acc_ptr2;
	delete acc_ptr3;
	return 0;
}
