// Объявления класса BankAccount,
// который представляет банковский счёт
// This file simple declaration of structure and methods (function)
// related with this structure - structure + methods = class
// in this code we can writing parametrs by default, but in 
// defenition (cpp) we can't - compiler says errors

#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

#include <string>

class BankAccount{
	private:
		// Имя вкладчика
		std::string name_;
		// Номер счёта
		std::string account_number_;
		// Баланс счёта
		unsigned long long balance_;
	public:
		// These constructor calling when we calling default constructor
		// (because all parametrs have default values) and when we calling
		// constructor and passing parametrs to him. But default compiler constructor deleted
		// , because we implement one constructor. It is a good, because we not need
		// to overload constructors (writing multiple code for construction objects),
		//  but for inline functions it is bad because we need to recompile source code,
		//  which use inline functions.
		BankAccount(const std::string& name = "No name", 
				const std::string& account_number = "No number", 
				unsigned long long balance = 0);
		~BankAccount();
		void Show() const;
		bool AddMoney(unsigned long long cash);
		bool WithdrawMoney(unsigned long long cash);

};

#endif
