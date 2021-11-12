#ifndef BANK_FACADE
#define BANK_FACADE

#include "ATM_machine.h"

class BankFacade{
	private:
		ATM_Machine** row;
		const int size;
		const int cyclelimit;
		long sum_of_turnaways = 0;
		long sum_of_customers = 0;
		long sum_of_served = 0;
		long sum_line_wait = 0;
		long sum_of_legnth = 0;
	public:
		BankFacade(const BankFacade& other) = delete;
		BankFacade& operator=(const BankFacade& other) = delete;
		BankFacade(int number_of_ATM = 2, int max_size_every_line = 10, int _cyclelimit = 0);
		~BankFacade();
		long SumOfTurnAways() const; 
		long SumOfCustomers() const;
		long SumOfSurvedCustomers() const;
		long SumOfLineWaits() const;
		double AvarageQueueLength() const;
		bool AddCustomer(int cycle);		
		void SimulationStep(int simulation_unit);

};
#endif
