#include "queue2.h"
#include "people.h"
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
	QueueTp<shared_ptr<Person>> qs(max_size); // QueueTp<Worker*> - bad!!! - memory leaks!!!
	int ct;
	shared_ptr<Person> inserter;
	for(ct = 0; ct < max_size; ++ct)
	{
		char choice;
		cout << "Enter the employee category:\n" 
			<< "g: gunslinger p: pokerplayer "
			<< "b: baddude q: quit\n";
		cin >> choice;
		while(strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter a g, p, b, or q: ";
			cin >> choice;
		}
		if(choice == 'q')
			break;
		switch(choice)
		{

			case 'g': qs.enqueue(inserter = make_shared<Gunslinger>());
				  break;
			case 'p': qs.enqueue(inserter = make_shared<PokerPlayer>());
				  break;
			case 'b': qs.enqueue(inserter = make_shared<BadDude>());
				  break;
		}
		cin.get();
		if(inserter != nullptr) 
		{
			inserter->Set();
		}

	}
	cout << "\nHere is your staff(queue):\n";
	shared_ptr<Person> tmp;
	while(qs.dequeue(tmp)){
		tmp->Show();
	}
	BadDude test("Aboba", "Loh", 12, 0.15);
	test.Show();
	Gunslinger p = test;
	p.Show();
	cout << "Testing card and time:" << endl;
	cout << test.Cdraw() << endl;
	cout << test.Gdraw() << endl;

	// test.Draw() - now allowed!!!
	
	cout << "Bye.\n";
	return 0;
}
