#include "BankFacade.h"


BankFacade::BankFacade(int number_of_ATM, int max_size_every_line, int _cyclelimit) : cyclelimit(_cyclelimit), size(number_of_ATM){
			row = new ATM_Machine*[number_of_ATM];
			for(int i = 0; i < size; ++i){
				row[i] = new ATM_Machine(max_size_every_line);
			}

		}
BankFacade::~BankFacade(){
	for(int i = 0; i < size; ++i)
	{
		delete row[i];
	}
	delete[] row;
}
long BankFacade::SumOfTurnAways() const 
{ 
	return sum_of_turnaways; 
}
long BankFacade::SumOfCustomers() const 
{ 
	return sum_of_customers; 
}
long BankFacade::SumOfSurvedCustomers() const 
{ 
	return sum_of_served; 
}
long BankFacade::SumOfLineWaits() const 
{ 
	return sum_line_wait; 
}
double BankFacade::AvarageQueueLength() const {
	double result;
	for(int i = 0; i < size; ++i){
		// Sum of avaraged by length of ATM's machines queues
		result += (double)row[i]->line_length / cyclelimit;
	} 
	// Returning avaraged by number of ATM Machines
	return result / size;
}
bool BankFacade::AddCustomer(int simulation_unit){
	int min_i = 0;
	for(int i = 1; i < size; ++i){
		if(row[min_i]->queue.queuecount() > row[i]->queue.queuecount())
		{
			min_i = i;
		}
	}
	if(row[min_i]->queue.isfull()){
		sum_of_turnaways++;
		return false;
	}
	else{
		sum_of_customers++;
		Item added_customer;
		added_customer.set(simulation_unit);
		row[min_i]->queue.enqueue(added_customer);
	}
	return true;
}
void BankFacade::SimulationStep(int simulation_unit){
	for(int i = 0; i < size; ++i){
		if(row[i]->wait_time == 0 && !row[i]->queue.isempty()){
			Item tmp;
			row[i]->queue.dequeue(tmp);
			row[i]->wait_time = tmp.ptime();
			sum_line_wait += simulation_unit - tmp.when();
			sum_of_served++;
		}
		if(row[i]->wait_time > 0){
			row[i]->wait_time--;
		}
		row[i]->line_length += row[i]->queue.queuecount();
	}
}

