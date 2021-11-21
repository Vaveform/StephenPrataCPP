#include <iostream>

using namespace std;

const unsigned int INCHES_PER_FEET = 12;
const double METERS_PER_INCHES = 0.0254;
const double POUNDS_PER_KILOGRAM = 2.2;

int main()
{

	cout << "This programm calaculate your body mass index(BMI)" << endl;
	cout << "Please, enter your height (in feets and inches): ";
	unsigned int feets = 0;
	unsigned int inches = 0;
	cin >> feets >> inches;



	//cout << "Entered feets: " << feets << endl;
	//cout << "Entered inches: " << inches << endl;
	feets += ( inches / INCHES_PER_FEET );
	inches %= INCHES_PER_FEET;

	double height = feets * INCHES_PER_FEET + inches;
	cout << "Entered height in inches: " << height << endl;
	height *= METERS_PER_INCHES;
	cout << "Entered heaight in meters: " << height << endl;
	cout << "Please, enter your weight (in pounds): ";
	double pounds = 0;
	cin >> pounds;

	cout << "Weight in kilograms: " << (pounds / POUNDS_PER_KILOGRAM) << endl;

	double bmi = ( pounds / POUNDS_PER_KILOGRAM ) / ( height * height );
	cout << "Your BMI index: " << bmi << endl;
	return 0;
}
