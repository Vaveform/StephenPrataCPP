#include "customer.h"
#include <cstdlib>

Customer::Customer() {
	arrive = processtime = 0;
}

long Customer::when() const
{
	return arrive;
}

int Customer::ptime() const
{
	return processtime;
}

void Customer::set(long when){
	// Random number from 1 to 3 simulation units (here in minutes)
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

