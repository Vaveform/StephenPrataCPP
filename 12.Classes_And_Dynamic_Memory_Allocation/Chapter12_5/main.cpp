#include <iostream>
#include <ctime>
#include "customer.h"
#include "queue2.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);



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
	// the avarage time wait will be bigger than 1 minute
	double perhour = 60;
	double step_perhour = 0.01;
	double min_per_cust;
	Item temp;
	long turnaways;
	long customers;
	long served;
	long sum_line;
	int wait_time;
	long line_wait;
	// Setting size of queue, when clients never turnaways
	// but we can get max size from user.
	
	int qs = 0; // perhour * hours;
	cout << "Input max size of queue: ";
	cin >> qs;
	cout << "Starting simulation with duration " 
		<< hours << " hours" << endl;
	cout << "Initital number clients per hour: " << perhour << endl;
	cout << "Step of perhour: " << step_perhour << endl;
	cout << "Max size of queue: " << qs << endl;
	
	do{
		
		// random initialization
		std::srand(std::time(0));
		Queue line(qs);
		// For every iteration recalculating minutes per customer
		min_per_cust = MIN_PER_HR / perhour;
		turnaways = 0;
		customers = 0;
		served = 0;
		sum_line = 0;
		wait_time = 0;
		line_wait = 0;
		perhour -= step_perhour;
		
		// One cycle has one second duration
		for(int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if(newcustomer(min_per_cust))
			{
				if(line.isfull())
					turnaways++;
				else{
					customers++;
					temp.set(cycle);
					line.enqueue(temp);
				}
			}
			if(wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);
				wait_time = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}
			if(wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}
		
		if(customers > 0)
		{
			cout << "-------------------------------------------------" << endl;
			cout << "Perhour clients: " << perhour + step_perhour << endl;
			cout << "customers accepted: " << customers << endl;
			cout << " customers served: " << served << endl;
			cout << " turnaways: " << turnaways << endl;
			cout << "average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << (double) sum_line / cyclelimit << endl;
			cout << " average wait time: "
				<< (double) line_wait / served << " minutes\n";
			cout << "-------------------------------------------------" << endl;

		}
		else{
			cout << "No customers!\n";
		}

	}while((double)line_wait / served > 1.0);
	perhour += step_perhour;
	cout << "We see that the avarage wait time is approximately one minute or " 
		<< (double) line_wait / served << " when customers per minute is "
		<< perhour << endl;


	cout << "Done!\n";
	return 0;
}

bool newcustomer(double x){
	return (std::rand() * x / RAND_MAX < 1);
}
