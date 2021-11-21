#include <iostream>
#include "golf.h"

using namespace std;

int main(){
	GolfPlayer p;
	p.setGolf();
	p.showInfo();
	// If write long name (10 symbols) and then name for example 5 symbols
	// Ok working because im private method setFullName algorithm
	// works correct and in last symbol exist '\0' and cout print before
	// symbol '\0'. Test below showing this
	// p.setGolf(); // was fffffffffffffffff input aaaa
	// p.showInfo(); // output aaaa


	// Example from 9_1 task
	
        string number_of_players;
        cout << "Input number players of golf:\n";
        getline(cin, number_of_players);
        int size_pl = atol(number_of_players.c_str());
        GolfPlayer* ptr_players = new GolfPlayer[size_pl];
        for(size_t i = 0l; i < size_pl; ++i){
        	if(!ptr_players[i].setGolf()){
			size_pl = i;
			break;
		}
    	}
    

    	cout << "All players: " << endl;
    	for(size_t i = 0; i  < size_pl; ++i){
        	ptr_players[i].showInfo();
    	}
	// delete ptr_players; // bad - calling destructor for first element (in gcc Ubuntu - 
	// error - munmap_chunk(): invalid pointer - Аварийный останов)
    	delete[] ptr_players;



	return 0;
}
