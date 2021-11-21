#include "queue2.h"
#include "worker.h"
#include <iostream>
#include <cstring>
#include <memory>


int main()
{
//	QueueTp<Worker*> qs(2);
//	qs.enqueue(new SingingWaiter);

	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	// Here we should using wrappers for row pointers
	// or smart pointers to avoid memory leaks - 
	// if we concretize template data structure by row pointer,
	// especially pointer which ref to heap memory - pointers
	// will be destroyed, but heap memory no!!! If we want using
	// polymorphism and templates we should use smart pointers!!!
	using std::shared_ptr;
	using std::make_shared;
	int max_size;
	cout << "Input max size of the queue of workers: ";
	cin >> max_size;
	QueueTp<shared_ptr<Worker>> qs(max_size); // QueueTp<Worker*> - bad!!! - memory leaks!!!
	int ct;
	shared_ptr<Worker> inserter;
	for(ct = 0; ct < max_size; ++ct)
	{
		char choice;
		cout << "Enter the employee category:\n" 
			<< "w: waiter s: singer "
			<< "t: singing waiter q: quit\n";
		cin >> choice;
		while(strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if(choice == 'q')
			break;
		switch(choice)
		{

			case 'w': qs.enqueue(inserter = make_shared<Waiter>());
				  break;
			case 's': qs.enqueue(inserter = make_shared<Singer>());
				  break;
			case 't': qs.enqueue(inserter = make_shared<SingingWaiter>());
				  break;
		}
		cin.get();
		if(inserter != nullptr) 
		{
			inserter->Set();
		}

	}
	cout << "\nHere is your staff(queue):\n";
	shared_ptr<Worker> tmp;
	while(qs.dequeue(tmp)){
		tmp->Show();
	}
	cout << "Bye.\n";
	return 0;
}
