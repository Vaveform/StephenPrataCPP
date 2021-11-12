#include <iostream>
#include <string>
#include "golf.h"


GolfPlayer::GolfPlayer(const char* name, int hc){
	using std::cout;
	using std::endl;
	cout << "Working constructor with parametrs " << name << " and " << hc << endl;
	setFullName(name);
	setHandicap(hc);
}

void GolfPlayer::setFullName(const char* name){
	char* iterator = this->fullname;
	while(*name != '\0' && iterator - this->fullname < Len - 1){
		*iterator = *name;
		++iterator;
		++name;
	}
	*iterator = '\0';
}

void GolfPlayer::setHandicap(int hc){
	this->handicap = hc;
}

void GolfPlayer::showInfo() const {
	using std::cout;
	using std::endl;
	cout << "Fullname of player: " << this->fullname << endl;
	cout << "His handicap: " << this->handicap << endl;
}

int GolfPlayer::setGolf(){
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
	cout << "Input fullname of player (no more 39 symbols):\n";
	string fname;
	string hcap;
	getline(cin, fname);
	if(fname == ""){
		return 0;
	}
	cout << "Input handicap of player " << fname << ":\n";
	getline(cin, hcap);
	int hc = atoi(hcap.c_str());
	// Calls additional constructor for temporary object
	GolfPlayer tmp(fname.c_str(), hc);
	// Working default operator= (assignment operator) - copy all fields to caller
	*this = tmp;
	// In the end of block this function tmp object destroying and calling 
	// destructor GolfPlayer::~GolfPlayer() and tmp automatical variable
	//
	// Attention - default assign operator copy all elements of automatic 
	// fields-arrays, because compiler should know at compile time what
	// size of automatic array (here difference between array and pointer). 
	// In contrast of dynamic array - default operator copy only pointer (8 bytes if x64)
	// And here can be problem to deallocate dynamic array, because 2 object will
	// have pointer on the same block of heap data
	return 1;
}

GolfPlayer::~GolfPlayer(){
	std::cout << "Working destructor of " << this->fullname << std::endl; 
}
