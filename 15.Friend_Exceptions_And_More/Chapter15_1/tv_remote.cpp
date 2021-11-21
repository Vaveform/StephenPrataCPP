#include <iostream>
#include "tv_remote.h"

bool Tv::volup()
{
	if(volume < MaxVal)
	{
		++volume;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if(volume > MinVal)
	{
		--volume;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if(channel < maxchannel)
		++channel;
	else
		channel = 1;
}

void Tv::chandown()
{
	if(channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;

	cout << "TV is " << (state == Off ? "Off" : "On") << endl;

	if(state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = "
			<< (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = "
			<< (input == TV ? "TV" : "DVD") << endl;
	}
}

bool Tv::set_remote_distance_mode(Remote& r)
{
	if(state == On)
	{
		r.distance_mode = (r.distance_mode == Remote::Normal) ? 
			Remote::Interactive : Remote::Normal;
		// r.distance_mode ^= 1;
		return true;
	}
	return false;
}

void Remote::remote() const
{
	using std::cout;
	using std::endl;

	cout << "Remote mode is: " 
		<< (distance_mode == Normal ? "normal" : "interactive") << endl;
}
