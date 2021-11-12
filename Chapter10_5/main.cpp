#include <iostream>
#include <cctype>
#include "customer.h"
#include "stack.h"

int main(){
	using namespace std;
	Stack st; // creating empty stack
	char ch;
	double total = 0;
	customer po;
	// A - добавить заказ, P - обработка заказа, Q - завершение
	cout << "Please enter A to add a customer,\n"
		<< "P to process a PO, or Q to quit.\n";
	while(cin >> ch && toupper(ch) != 'Q')
	{
		// Skiping extra symbols
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a': cout << "Enter fullname of customer: " << endl;
				  // Reading 34 symbols from cin to po.fullname;
				  cin.get(po.fullname, 35);
				  // Skiping extra symbols
				  cout << "Enter payment of customer " << po.fullname << ":" << endl;
				  cin >> po.payment;
				  if(st.isfull()){
					  cout << "Can not to add new customer - stack full" << endl;
				  }
				  else{
					  st.push(po);
				  }
				  break;
			case 'P':
			case 'p': if(st.isempty()){
					  cout << "Stack already empty\n";
				  }
				  else{
					  st.pop(po);
					  cout << "Customer " << po.fullname << " popped\n";
					  total+= po.payment;
					  cout << "Total popped: " << total << endl;
				  }

		}
		cout << "Please enter A to add a customer,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	return 0;
}
