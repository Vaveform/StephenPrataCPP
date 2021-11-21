#include "stonewt.h"

int main()
{
	using namespace std;
	//// Default constructor
	//Stonewt first;
	//// Constructor with one parametr
	//Stonewt second = Stonewt(12.1);
	//// Constructor with three parametrs
	//Stonewt third = Stonewt(150, 5.1);
	//// Sum of two objects;
	//first = second + third;
	//cout << second  << " + "<< third << " = " << first << endl;
	//// Diff if two objects;
	//cout << third << " - " << second << " = "  << third - second << endl;
	//// Bad diff
	//cout << second << " - " << third << " = "  << second - third << endl;
	//// Multiply of objects
	//cout << second << " * " << third << " = " << second * third << endl;
	//// Multiply with n
	//double n = 1.5;
	//cout << second << " * " << n << " = " << second * n << endl;
	//// Multiply n on second
	//cout << n << " * " << second << " = " << n * second << endl;
	//cout << "First: " << first << endl;
	//cout << "Second: " << second << endl;
	//cout << "Third: " << third << endl;
	//first.Stone_mode();
	//cout  << "First in stone mode: " << first << endl;
	//first.Int_lbs();
	//cout << "First in int lbs mode: " << first << endl;
	//first.Double_lbs();
	//cout << "First in double lbs mode: " << first << endl;
	

	const int number_of_objects = 6;
	double lbs;
	int min_i = 0, max_i = 0; 
	int count = 0;
	int number_of_stones = 11;
	Stonewt model(number_of_stones, 0.0);
	// Creating automatic array - calling 6 constructors: for first three with one parametr
	// and with 0 parametrs for other three objects.
	Stonewt objects[number_of_objects] = {Stonewt(124.0), Stonewt(32.0), Stonewt(65.12)};
	for(int i = 3; i < number_of_objects; i++){
		cout << "Enter number of pounds: ";
		cin >> lbs;
		objects[i] = lbs; // Here calling constructor with one parametrs like Stonewwt(lbs) 
				  // and creating temporary object , if we using explicit keyword, 
				  // we cannot make this. After constructor
				  // calling default assignment operator (operator=), which copy all fields
				  // from temporary object to element of array and calling destructor of temporary
				  // object.
	}
	for(int i = 0; i < number_of_objects; ++i){
		// Calling overloaded operators >= > <
		if(objects[i] >= model) count++;
		if(objects[min_i] > objects[i]) min_i = i;
		if(objects[max_i] < objects[i]) max_i = i; 
	}
	cout << "Number of objects which bigger or equal " 
		<< number_of_stones << ": " << count << endl;
	cout << "Max weight: " << objects[max_i] << endl;
	cout << "Min weight: " << objects[min_i] << endl;







	return 0;
}
