#ifndef CD_H_
#define CD_H_


class Cd
{
	private:
		char performers[50];
		char label[20];
		int selections;
		double playtime;
	public:
		Cd(const char* s1 = "No performers", 
				const char* s2 = "No label", 
				int n = 0, 
				double x = 0.0);
		virtual ~Cd();
		virtual void Report() const;
};



#endif

