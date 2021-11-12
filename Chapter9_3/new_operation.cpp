#include <iostream>
#include <new>
#include <cstring>

using namespace std;

struct chaff{
	char dross[20];
	int slag;
};

void FillChaffStruct(chaff& element, const char* str, int slag){

	strcpy(element.dross, str);
	element.slag = slag;
}

void ShowChaffStruct(chaff& element){
	cout << "Chaff with dross: " 
		<< element.dross 
		<< " and slag: " 
		<< element.slag << endl;
}


const int NumberOfElements = 2;

int main(){
	// Static array buffer;
	const int bufferSize = sizeof(chaff) * NumberOfElements;
	char ptr[bufferSize];
	chaff* arr_ptr = new (ptr) chaff[NumberOfElements];
	// Deleting not needed, because buffer static array(automatic) 
	// - free automatically. If call delete with arr_ptr- compiler says - unknown address
	// or double free or corruption;
	for(size_t i = 0; i < NumberOfElements; ++i){
		FillChaffStruct(arr_ptr[i], "static buffer", 12);
		ShowChaffStruct(arr_ptr[i]);
	}
	
	// Dynamic array buffer
	char* new_ptr = new char[bufferSize];
       	arr_ptr = new(new_ptr) chaff[NumberOfElements];
	for(size_t i = 0; i < NumberOfElements; ++i){
		FillChaffStruct(arr_ptr[i], "dynamic buffer", 11);
		ShowChaffStruct(arr_ptr[i]);
	}
	// Delete works with addresses - we can delete arr_ptr or new_ptr, because new for arr_ptr and new for new_ptr
	// returns the same address. Using delete[] for deleting array essential, because in C++ if we use array of
	// objects, if we allocate array of objects new T[N] and deallocate delete arrayName - calls destructor for first
	// element. But for array with simple types (char, bool, int, float, double) works ok - because delete works
	// with addresses -> allocating array of int with new int[size] and deallocte with delete - freeing 
	// all block(not the first int). But delete[] - better.
	

	// We cannot use to delete: delete[] arr_ptr and delete[] new_ptr the same time;
	delete[] new_ptr;
}
