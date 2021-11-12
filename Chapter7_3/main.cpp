#include <iostream>

using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};


void show_box(box box_value)
{
	cout << "Maker: " << box_value.maker << endl;
	cout << "Height: " << box_value.height << endl;
	cout << "Width: " << box_value.width << endl;
	cout << "Length: " << box_value.length << endl;
	cout << "Volume: " << box_value.volume << endl;
}

void change_box(box* box_ptr)
{
	box_ptr->volume = box_ptr->height 
		* box_ptr->width 
		* box_ptr->length;
}

void eat_line()
{
	while(cin && cin.get() != '\n') continue;
}


int main()
{
	box created_box;
	cout << "Enter maker: ";
	cin.get(created_box.maker, 40);
	if(cin.peek() != '\n'){
		eat_line();
	}
	cout << "Enter width: ";
	cin >> created_box.width;
	eat_line();
	cout << "Enter height: ";
	cin >> created_box.height;
	eat_line();
	cout << "Enter length: ";
	cin >> created_box.length;
	eat_line();
	cout << "Enter volume: ";
	cin >> created_box.volume;
	eat_line();

	cout << "Entered box " << endl;
	show_box(created_box);
	change_box(&created_box);
	cout << "Box after change function" << endl;
	show_box(created_box);

}
