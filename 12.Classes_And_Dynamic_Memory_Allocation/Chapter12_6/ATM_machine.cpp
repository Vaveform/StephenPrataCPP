#include "ATM_machine.h"


ATM_Machine::ATM_Machine(int qs) : queue(qs){
	line_length = 0;
	wait_time = 0;
}
