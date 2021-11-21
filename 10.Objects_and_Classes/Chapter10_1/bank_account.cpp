#include "bank_account.h"

#include <iostream>

BankAccount::BankAccount(const std::string& name, 
		const std::string& account_number, 
		unsigned long long balance ){
	// Compiler default constructor deleting if we write constructor!!!
std::cout << "Working constructor with parametrs " << name << " " << account_number << " " << balance  << std::endl;
	name_ = name;
	account_number_ = account_number;
	balance_ = balance;
}

BankAccount::~BankAccount(){
	std::cout << "Working destructor" << std::endl;
}
void BankAccount::Show() const {
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Account_number: " << account_number_ << std::endl;
	std::cout << "Balance: " << balance_ << std::endl;
}
bool BankAccount::AddMoney(unsigned long long cash){
	this->balance_ += cash;
	std::cout << "Balance of " << this->account_number_ << " increased by " << cash << std::endl; 
	return true;
}
bool BankAccount::WithdrawMoney(unsigned long long cash){
	if(this->balance_ < cash){
		std::cout << "On " << this->account_number_ << " not enough money to withdraw " << cash << std::endl;
		return false;
	}
	this->balance_ -= cash;
	std::cout << "Balance of " << this->account_number_ << " decreased by " << cash << std::endl; 
	return true;
}

