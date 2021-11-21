#ifndef PLORG_H_
#define PLORG_H_

class Plorg{
	private:
		static const int Len = 19;
		char name[Len];
		int contentment_index;
	public:
		Plorg(const char* _name = "Plorga", int CI = 50);
		void ChangeCI(int CI);
		void Info() const;
};

#endif
