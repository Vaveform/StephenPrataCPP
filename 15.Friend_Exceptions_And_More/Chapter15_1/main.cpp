#include <iostream>
#include "tv_remote.h"

int main()
{
	using std::cout;
	using std::endl;
	Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";

	s42.settings();
	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";

	s42.settings();

	cout << "Changing remote distance mode:  " << endl;
	cout << "Remote settings before: " << endl;
	grey.remote();
	s42.set_remote_distance_mode(grey);
	cout << "Remote settings after: " << endl;
	grey.remote();
	return 0;
}
