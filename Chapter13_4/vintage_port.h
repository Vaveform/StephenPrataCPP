#ifndef VINTAGE_PORT_H_
#define VINTAGE_PORT_H_

#include "port.h"
#include <cstring>
class VintagePort : public Port
{
	private:
		char * nickname;
		int year;
	public:
		VintagePort();
		VintagePort(const char * br, int b, const char * nn, int y);
		VintagePort(const VintagePort& vp);
		~VintagePort();
		VintagePort& operator=(const VintagePort & vp);
		void Show() const;
		friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};


#endif
