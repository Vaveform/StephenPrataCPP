#include <iostream>
#include "plorg.h"

using namespace std;

int main(){
	Plorg def;
	Plorg afg("Aboba", 34);
	def.Info();
	afg.Info();
	afg.ChangeCI(100);
	afg.Info();
	return 0;
}
