#include "dma.h"
#include <cstring>

DMA::DMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
DMA::DMA(const DMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
DMA::~DMA()
{
	std::cout << "Working destructor of abstract class DMA" << std::endl;
	delete [] label;
}
DMA& DMA::operator=(const DMA& rs)
{
	if(this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}


// Pure virtual method makes DMA abstract base class
// but pure virtual method declarated with =0 can have definition
void DMA::View() const{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

std::ostream& operator<<(std::ostream& os, const DMA& rs){
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}


baseDMA::baseDMA(const char* l, int r) : DMA::DMA(l, r){}
baseDMA::~baseDMA() {
	std::cout << "Working destructor of class baseDMA" << std::endl;
}

void baseDMA::View() const{
	std::cout << "baseDMA view: " << std::endl;
	DMA::View();
}


std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "baseDMA output operator: " << std::endl;
	// Caling operator<< for DMA by C-style casting to reference on base class 
	// (abstract class)
	os << (const DMA& )rs;
	return os;
}

lacksDMA::lacksDMA(const char* c, const char * l, int r) : DMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char * c, const DMA& rs) : DMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
lacksDMA::~lacksDMA(){
	std::cout << "Working destructor of class lacksDMA" << std::endl;
}

void lacksDMA::View() const {
	std::cout << "lacksDMA view: " << std::endl;
	DMA::View();
	std::cout << "Color: " << color << std::endl;
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << "baseDMA output operator: " << std::endl;
	os << dynamic_cast<const DMA &>(ls);
	os << "Color: " << ls.color << std::endl;
	return os;
}
hasDMA::hasDMA(const char * s, const char * l, int r) : DMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const char * s, const DMA& rs) : DMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA& hs) : DMA(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
	std::cout << "Working destructor of class hasDMA" << std::endl;
	delete [] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if(this == &hs)
		return *this;
	DMA::operator=(hs);
	delete [] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}

void hasDMA::View() const{
	std::cout << "hasDMA view: " << std::endl;
	DMA::View();
	std::cout << "Style: " << style << std::endl;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << "hasDMA output operator: " << std::endl;
	os << dynamic_cast<const DMA&>(hs);
	os << "Style: " << hs.style << std::endl;
	return os;
}
