#include "stack2.h"

int main(){
	using namespace std;
	Stack first(5);
	long value = 10;
	while(first.push(value+= 10)){
		cout << "To first stack insert value " << value << endl;
	}
	cout << "First created and filled" << endl;
	cout << "First stack is full? " << first.isfull() << endl;
	cout << "First stack is empty? " << first.isempty() << endl;
	Stack second(first);
	cout << "Second stack created by copy constructor (first)" << endl;
	cout << "Second stack is full? " << second.isfull() << endl;
	cout << "Second stack is empty? " << second.isempty() << endl;
	Stack third;
	for(int i = 0; i < 5; i++){
		cout << "Pushed to third stack value: " << i << endl;
		third.push(i);
	}
	Item val_for_print;
	while(third.pop(val_for_print)){
		cout << "From third stack popped: " << val_for_print << endl;
	}
	third = second;
	cout << "Third stack after assignment second: " << endl;

	while(!third.isempty()){
		Item val;
		third.pop(val);
		cout << "From third stack popped: " << val << endl;
	}
	return 0;
}
