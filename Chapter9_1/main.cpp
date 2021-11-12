#include <iostream>
#include <string>

#include "golf.h"

using namespace std;

int main()
{
    string number_of_players;
    cout << "Input number players of golf:\n";
    getline(cin, number_of_players);
    int size_pl = atol(number_of_players.c_str());
    golf* ptr_players = new golf[size_pl];
    for(size_t i = 0l; i < size_pl; ++i){
        if(!setgolf(ptr_players[i])){
		size_pl = i;
		break;
	}
    }
    

    cout << "All players: " << endl;
    for(size_t i = 0; i  < size_pl; ++i){
        showgolf(ptr_players[i]);
    }
    delete[] ptr_players;

    return 0;
}
