#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
#include <cctype>
#include <cstring>

using std::ostream;
using std::istream;

class String
{
	private:
		char* str;
		int len;
		int capacity;
		// Only const static can be define in declarartion
		// of class (in header). Static should be define
		// in cpp file
		static int num_strings;
	public: 
		String(const char*);
		String();
		String(const String&);
		~String();
		int length () const { return len - 1; }

		String & operator= (const String&);
		String & operator= (const char *);
		char & operator[] (int i);
		const char & operator[] (int i) const;
		String& operator+= (char);
		String operator+(const String&) const;
		void stringlow();
		void stringup();
		int has(char) const;
		String operator+(const char*) const;


		friend bool operator<(const String& st1, const String& st2);
		friend bool operator>(const String& st1, const String& st2);
		friend bool operator==(const String& st1, const String& st2);
		friend ostream& operator<<(ostream& os, const String& st);
		friend istream& operator>>(istream& is, String& st);
		friend String operator+(const char* , const String&);
		static int HowMany();
};

#endif
