#include <iostream>
#include <ctime>
#include "customer.h"
#include "queue2.h"
#include "BankFacade.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);


//class ATM_Machine{
//	private:
//		Queue queue;
//		int wait_time;
//		long line_length;
//		friend class BankFacade;
//	public:
//		ATM_Machine(const ATM_Machine& other) = delete;
//		ATM_Machine& operator=(const ATM_MAchine& other) = delete;
//		ATM_Machine(int qs = 10) : queue(qs){
//			line_length = 0;
//			wait_time = 0;
//		}
//
//	
//};
//
//class BankFacade{
//	private:
//		ATM_Machine** row;
//		const int size;
//		const int cyclelimit;
//		long sum_of_turnaways = 0;
//		long sum_of_customers = 0;
//		long sum_of_served = 0;
//		long sum_line_wait = 0;
//		long sum_of_legnth = 0;
//	public:
//		BankFacade(const BankFacade& other) = delete;
//		BankFacade& operator=(const BankFacade& other) = delete;
//		BankFacade(int number_of_ATM = 2, int max_size_every_line = 10, int _cyclelimit = 0) : cyclelimit(_cyclelimit), size(number_of_ATM){
//			row = new ATM_Machine*[number_of_ATM];
//			for(int i = 0; i < size; ++i){
//				row[i] = new ATM_Machine(max_size_every_line);
//			}
//
//		}
//		~BankFacade(){
//			for(int i = 0; i < size; ++i)
//			{
//				delete row[i];
//			}
//			delete[] row;
//		}
//		long SumOfTurnAways() const { return sum_of_turnaways; }
//		long SumOfCustomers() const { return sum_of_customers; }
//		long SumOfSurvedCustomers() const { return sum_of_served; }
//		long SumOfLineWaits() const { return sum_line_wait; }
//		double AvarageQueueLength() const {
//		        double result;
//			for(int i = 0; i < size; ++i){
//				// Sum of avaraged by length of ATM's machines queues
//				result += (double)row[i]->line_length / cyclelimit;
//			} 
//			// Returning avaraged by number of ATM Machines
//			return result / size;
//		}
//		bool AddCustomer(int simulation_unit){
//			int min_i = 0;
//			for(int i = 1; i < size; ++i){
//				if(row[min_i]->queue.queuecount() > row[i]->queue.queuecount())
//				{
//					min_i = i;
//				}
//			}
//			if(row[min_i]->queue.isfull()){
//				sum_of_turnaways++;
//			}
//			else{
//				sum_of_customers++;
//				Item added_customer;
//				added_customer.set(simulation_unit);
//				row[min_i]->queue.enqueue(added_customer);
//			}
//		}
//		void SimulationStep(int simulation_unit){
//			for(int i = 0; i < size; ++i){
//				if(row[i]->wait_time == 0 && !row[i]->queue.isempty()){
//					Item tmp;
//					row[i]->queue.dequeue(tmp);
//					row[i]->wait_time = tmp.ptime();
//					sum_line_wait += simulation_unit - tmp.when();
//				        sum_of_served++;
//				}
//				if(row[i]->wait_time > 0){
//					row[i]->wait_time--;
//				}
//				row[i]->line_length += row[i]->queue.queuecount();
//			}
//		}
//
//
//};

int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	// Saying in task to using 100 hours simulation
	int hours = 100;
	
	long cyclelimit = MIN_PER_HR * hours;
	// We start from 60 person in avarage appear for using ATM
	// in this initial value we will have 100% chance that
	// the avarage time wait will be bigger than 1 minute for 1 ATM
	double perhour = 60;
	double step_perhour = 0.01;
	double min_per_cust;
	// Setting size of queue, when clients never turnaways
	// but we can get max size from user.
	
	int qs = 0; // perhour * hours;
	int atm_numbers = 0;
	cout << "Input max size of queue: ";
	cin >> qs;
	cout << "Input number of ATM machines: ";
	cin >> atm_numbers;

	perhour *= atm_numbers;
	cout << "Starting simulation with duration " 
		<< hours << " hours" << endl;
	cout << "Initital number clients per hour: " << perhour << endl;
	cout << "Step of perhour: " << step_perhour << endl;
	cout << "Max size of queue: " << qs << endl;
	cout << "Number of ATM: " << atm_numbers << endl;

	double avarage_wait_time;
	
	do{
		
		// random initialization
		std::srand(std::time(0));
		BankFacade facade(atm_numbers, qs, cyclelimit);
		// For every iteration recalculating minutes per customer
		min_per_cust = MIN_PER_HR / perhour;
		perhour -= step_perhour;
		
		// One cycle has one second duration
		for(int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if(newcustomer(min_per_cust))
			{
				facade.AddCustomer(cycle);
			}
			facade.SimulationStep(cycle);
		}
		
		avarage_wait_time = (double) facade.SumOfLineWaits() / facade.SumOfSurvedCustomers();
		if(facade.SumOfCustomers() > 0)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "Perhour clients: " << perhour + step_perhour << endl;
			cout << "customers accepted: " << facade.SumOfCustomers() << endl;
			cout << " customers served: " << facade.SumOfSurvedCustomers() << endl;
			cout << " turnaways: " << facade.SumOfTurnAways() << endl;
			cout << "average queue size: ";
			cout.precision(10);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << facade.AvarageQueueLength() << endl;
			cout << " average wait time: "
				<< avarage_wait_time << " minutes\n";
			cout << "-------------------------------------------------" << endl;

		}
		else{
			cout << "No customers!\n";
		}

	}while(avarage_wait_time > 1.0);
	perhour += step_perhour;
	cout << "We see that the avarage wait time is approximately one minute or " 
		<< avarage_wait_time << " when customers per minute is "
		<< perhour << endl;


	cout << "Done!\n";
	return 0;
}

bool newcustomer(double x){
	return (std::rand() * x / RAND_MAX < 1);
}
