#include <iostream>

using namespace std;

const int SLEN = 30;

struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};


int getinfo(student pa[], int n);

void display1(student st);

void display2(const student * ps);

void display3(const student pa[], int n);


int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while(cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for(int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;
}


int getinfo(student pa[], int n)
{
	int read_student;
	for(read_student = 0; read_student < n; ++read_student)
	{
		cout << "Enter #" << read_student + 1 << " name: ";
		cin.get(pa[read_student].fullname, SLEN);
		if(!cin | cin.gcount() == 0)
			break;
		while(cin.get() != '\n') continue;
		cout << "Enter " << pa[read_student].fullname << " hobby: ";
		cin.get(pa[read_student].hobby, SLEN);
		if(!cin | cin.gcount() == 0)
			break;
		while(cin.get() != '\n') continue;
		cout << "Enter " << pa[read_student].fullname << " ooplevel: ";
		cin >> pa[read_student].ooplevel;
		while(cin.get() != '\n') continue;
	}
	return read_student;
}

void display1(student st)
{
	cout << "Student " << st.fullname 
		<< " has hobby " << st.hobby 
		<< " and ooplevel " << st.ooplevel << endl;
}
void display2(const student* ps)
{
	cout << "Student " << ps->fullname 
		<< " has hobby " << ps->hobby 
		<< " and ooplevel " << ps->ooplevel << endl;
}
void display3(const student pa[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		display2(pa + i);
	}
}
