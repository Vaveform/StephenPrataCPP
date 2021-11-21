#include "stonewt.h"
using std::cout;

// Конструирует объект Stonewt из значения типа double
Stonewt::Stonewt(double lbs)
{
	this->_mode = STONES;
	this->stone = int (lbs) / Lbs_per_stn;
	// Представление веса в фунтах с плавающей точкой (lbs - int(lbs)) -
	// дробная часть переданного параметра. int (lbs) % Lbs_per_stn -
	// остаток от перевода в Stones
	this->pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	this->pounds = lbs;
}
// Конструирует объект Stonewt из стоунов и значения типа double
Stonewt::Stonewt(int stn, double lbs, Mode mode)
{
	this->_mode = mode;
	if(mode == STONES || mode == ILBS || mode == FLBS){
		this->stone = stn + lbs / Lbs_per_stn;
		this->pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
		this->pounds = stn * Lbs_per_stn + this->pds_left;
	}
	else{
		cout << "Incorrect 3rd argument in constructor" << std::endl;
		cout << "Pounds and stoned set to 0" << std::endl;
		this->stone = this->pds_left = this->pounds = 0;
		this->_mode = STONES;
	}
}

// Конструктор по умолчанию
Stonewt::Stonewt()
{
	this->_mode = STONES;
	this->stone = this->pounds = this->pds_left = 0;
}
void Stonewt::Stone_mode(){
	this->_mode = STONES;
}
void Stonewt::Int_lbs(){
	this->_mode = ILBS;
}
void Stonewt::Double_lbs(){
	this->_mode = FLBS;
}

// Деструктор
Stonewt::~Stonewt()
{
}

std::ostream& operator<<(std::ostream& os, const Stonewt& obj){
	if(obj._mode == Stonewt::STONES){
		cout << obj.stone << " stone, " << obj.pds_left << " pounds";
	}
	else if(obj._mode == Stonewt::ILBS){
		cout << (int)(obj.pounds + 0.5) << " pounds in integer format";
	}
	else if(obj._mode == Stonewt::FLBS){
		cout << obj.pounds << " pounds in double format";
	}
}

Stonewt Stonewt::operator*(double n) const {
	return Stonewt(this->pounds * n);
}

Stonewt Stonewt::operator+(const Stonewt& r) const {
	return Stonewt(this->pounds + r.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& r) const {
	if(this->pounds < r.pounds){
		cout << "Warning! Left hand operand smaller than right hand!\n";
		return Stonewt();
	}
	return Stonewt(this->pounds - r.pounds);
}

Stonewt Stonewt::operator*(const Stonewt& r) const{
	return Stonewt(this->pounds * r.pounds);
}

Stonewt operator*(double n, const Stonewt& r){
	return Stonewt(n * r.pounds);
}


bool Stonewt::operator>(const Stonewt& r_h) const{
	return this->pounds > r_h.pounds;
}

bool Stonewt::operator<(const Stonewt& r_h) const{
	return this->pounds < r_h.pounds;
}

bool Stonewt::operator!=(const Stonewt& r_h) const{
	return this->pounds != r_h.pounds;
}

bool Stonewt::operator<=(const Stonewt& r_h) const{
	return this->pounds <= r_h.pounds;
}

bool Stonewt::operator>=(const Stonewt& r_h) const{
	return this->pounds >= r_h.pounds;
}
