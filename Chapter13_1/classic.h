#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd
{
	private:
		char main_composition[50];
	public:
		Classic(const char* s1 = "No performers", 
				const char* s2 = "No label", 
				const char* s3 = "No composition",
				int n = 0, 
				double x = 0);
		Classic(const char* s3, const Cd& other);
		virtual ~Classic();
		virtual void Report() const;
};

#endif
