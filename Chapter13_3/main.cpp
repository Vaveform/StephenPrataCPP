#include "dma.h"
#include <iostream>
#include <string>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	// DMA t; - we can not craete - it is abstract class, because he has pure
	// virtual method
	DMA** p_dma;
	size_t length;
	cout << "Input number of objects: ";
	cin >> length;
	// reading from cin buffer \n symbol after entred length
	p_dma = new DMA*[length];
	std::string temp;
	char kind;
	int rating;
	for(int i = 0; i < length; ++i)
	{
		cout << "Enter label: ";
		cin >> temp;
		cout << "Enter dma rating: ";
		cin >> rating;
		cout << "Enter 1 - for baseDMA\n";
		cout << "Enter 2 - for lacksDMA\n";
		cout << "Enter 3 - for hasDMA\n";
		while(cin >> kind && (kind != '1' && kind != '2' && kind != '3')){
			cout << "Enter either 1, 2 or 3: ";
		}
		if(kind == '1'){
			p_dma[i] = new baseDMA(temp.c_str(), rating);
		}
		else if(kind == '2'){
			std::string colr;
			cout << "Enter color: ";
			cin.get();
			cin >> colr;
			p_dma[i] = new lacksDMA(colr.c_str(), temp.c_str(), rating);
		}
		else{
			cout << "Enter style: ";
			std::string style;
			cin >> style;
			p_dma[i] = new hasDMA(style.c_str(), temp.c_str(), rating);
		}
		while(cin.get() != '\n')
			continue;
	}
	cout << endl;
	for(int i = 0; i < length; ++i){
		p_dma[i]->View();
		// Every time will calling 
		// ostream& operator<<(ostream& os, const DMA& rs)
		// in string of code near:
		// cout << *(p_dma[i]);
	}
	for(int i = 0; i < length; ++i)
	{
		delete p_dma[i];
	}
	delete[] p_dma;
	return 0;
}
