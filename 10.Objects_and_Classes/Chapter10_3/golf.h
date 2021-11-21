#ifndef GOLF_H_
#define GOLF_H_

class GolfPlayer{
	private:
		static const int Len = 40;
		char fullname[Len];
		int handicap;
		void setFullName(const char* name);
	public:
		GolfPlayer(const char* name = "NULL", int hc = 0);
		int setGolf();
		void setHandicap(int hc);
		void showInfo() const;
		~GolfPlayer();
};


#endif
