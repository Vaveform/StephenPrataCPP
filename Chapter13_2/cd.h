#ifndef CD_H_
#define CD_H_

#include <cstring>

class Cd
{
	private:
		char* performers;
		char* label;
		int selections;
		double playtime;
	public:
		Cd(const char* s1 = "No performers", 
				const char* s2 = "No label", 
				int n = 0, 
				double x = 0.0);
		Cd(const Cd& other);
		Cd& operator=(const Cd& other);
		virtual ~Cd();
		virtual void Report() const;
};



#endif

