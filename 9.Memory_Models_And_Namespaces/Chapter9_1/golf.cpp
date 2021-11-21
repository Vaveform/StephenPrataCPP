
#include <iostream>
#include <string>
#include "golf.h"

void handicap(golf& g, int hc){
    g.handicap = hc;
}

static void fullname(golf& g, const char* name){
    char* iterator = g.fullname;
    while(*name != '\0' && iterator - g.fullname < Len - 1){
        *iterator = *name;
        iterator++;
        name++;
    }
    *iterator = '\0';
}

void setgolf(golf& g, const char * name , int hc){
    handicap(g, hc);
    fullname(g, name);
    
}

int setgolf(golf& g){
    using std::cout;
    using std::endl;
    using std::cin;
    using std::string;
    cout << "Input fullname of player (no more 39 symbols):\n";
    string fname;
    string hcap;
    getline(cin, fname);
    if(fname == ""){ cout << "BAD name" << endl; return 0;} // BAD name
    cout << "Input handicap of player " << fname << ":\n";
    getline(cin, hcap);
    int hc = atoi(hcap.c_str());
    setgolf(g, fname.c_str(), hc);
    return 1; // input OK
}

void showgolf(const golf& g){
    using std::cout;
    using std::endl;
    cout << "Fullname of player: " << g.fullname << endl;
    cout << "His handicap: " << g.handicap << endl;
}
