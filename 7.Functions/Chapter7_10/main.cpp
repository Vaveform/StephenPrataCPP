#include <iostream>

using namespace std;


// Available operations

double Add(double a, double b)
{
	cout << a << " + " << b << " = ";
	return a + b;
}

double Multiply(double a, double b)
{
	cout << a << " * " << b << " = ";
	return a * b;
}

double Divide(double a, double b)
{
	cout << a << " / " << b << " = ";
	return a / b;
}

double Minus(double a, double b)
{
	cout << a << " - " << b << " = ";
	return a - b;
}


double calculate(double a, double b, double (*math_op)(double, double))
{
	return math_op(a, b);
}

int main()
{
	// Array of pointers to ariphmetical functions
	double (*operations[4])(double, double) = {Add, Minus, Multiply, Divide};
	cout << "Enter two values to calculate operation: ";
	double a, b;
	while(cin >> a >> b)
	{
		while(cin.get() != '\n') continue;
		cout << "Enter ariphmetical operation (available +, -, *, /) or q to quit: ";
		char symbol = cin.get();
		while(cin.get() != '\n') continue;
		switch(symbol)
		{
			case '+': cout << calculate(a, b, operations[0]) << endl;
				  break;
			case '-': cout << calculate(a, b, operations[1]) << endl;
				  break;
			case '*': cout << calculate(a, b, operations[2]) << endl;
				  break;
			case '/': cout << calculate(a, b, operations[3]) << endl;
				  break;
			case 'q': cout << "Bye!\n";
				  return EXIT_SUCCESS;
			default:
				  continue;
		}
		cout << "Enter two values to calculate operation: ";
	}
	cout << "Bye!\n";

	return 0;
}
