#include <iostream>
#include "move.h"


int main()
{
	Move first(2.4, 1.3);
	Move second(-1.3, 5.3);
	first.showmove();
	second.showmove();
	Move result = first.add(second);
	result.showmove();
	result.reset(-5.0, -5.0);
	result.showmove();
	return 0;
}
