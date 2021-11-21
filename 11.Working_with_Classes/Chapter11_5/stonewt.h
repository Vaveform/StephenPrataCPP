#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

class Stonewt{
	private:
		static const int Lbs_per_stn = 14;
		enum Mode { STONES = 0, ILBS = 1, FLBS = 2};
		int stone;
		double pds_left;
		double pounds;
		Mode _mode;
	public:
		Stonewt(double lbs);
		Stonewt(int stn, double lbs, Mode mode = STONES);
		Stonewt();
		void Stone_mode();
		void Int_lbs();
		void Double_lbs();
		~Stonewt();
		Stonewt operator*(double n) const;
		Stonewt operator*(const Stonewt&) const;
		Stonewt operator+(const Stonewt&) const;
		Stonewt operator-(const Stonewt&) const;
		friend std::ostream& operator<<(std::ostream&, const Stonewt&);
		friend Stonewt operator*(double, const Stonewt&);
};


#endif
