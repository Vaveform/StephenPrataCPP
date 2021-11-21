#include "people.h"
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;


Person::Person() : name("Null"), surname("Null"){
}

Person::~Person()
{
	//cout << "Person destroyed" << endl;
}

Person::Person(const std::string& n, const std::string& s) : name(n), surname(s){
}

void Person::Data() const
{
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
}

void Person::GetName(){
	getline(cin, name);
	//while(cin.get() != '\n')
	//	continue;
}

void Person::GetSurname(){
	getline(cin, surname);
	//while(cin.get() != '\n')
	//	continue;
}

void Person::Get()
{
	cout << "Enter person name: ";
	GetName();
	cout << "Enter person surname: ";
	GetSurname();
}

Gunslinger::Gunslinger() : Person() {
}

Gunslinger::Gunslinger(const std::string& n, const std::string& s, 
		int notch, double t_r) : Person(n,s), notches(notch), time_ready(t_r)
{
}

Gunslinger::Gunslinger(const Person& p, int notch, double t_r) : Person(p), notches(notch), time_ready(t_r)
{
}

Gunslinger::~Gunslinger() 
{
	//cout << "Gunslinger destroyed" << endl;
}

void Gunslinger::Show() const
{
	cout << "Category: Gunslinger\n";
	Person::Data();
	Data();
}

void Gunslinger::Set()
{
	cout << "Enter gunslinger's name: ";
	GetName();
	cout << "Enter gunslinger's surname: ";
	GetSurname();
	Get();
}

double Gunslinger::Draw() const
{
	return time_ready;
}

void Gunslinger::Get(){
	cout << "Enter number of notches on sniper rifle: ";
	cin >> notches;
	cout << "Enter time ready for strike: ";
	cin >> time_ready;
	while(cin.get() != '\n')
		continue;
}

void Gunslinger::Data() const
{
	cout << "Number of notches on sniper rifle: " << notches << endl;
	cout << "Time ready for strike: " << Draw() << endl;
}


Card::Card(){
	std::srand(std::time(0));
	suit = std::rand() % 3;
	number = std::rand() % 52 + 1;
}

Card::Card(int _suit, int _number) : suit(_suit), number(_number)
{
	if(_suit > 4 || _suit < 0)
	{
		suit = spades;
	}
	if(_number > 52 || _number < 1)
	{
		number = 1;
	}
}

std::string Card::Suits[Card::NumberTypes] = {
                        "spades",
                        "hearts",
                        "diamonds",
                        "clubs",
                        "other"};

std::ostream& operator<<(std::ostream& os, const Card& c)
{
	os << "Card suit: " << Card::Suits[c.suit] << endl;
	os << "Card value: " << c.number << endl;
	return os;
}


PokerPlayer::PokerPlayer() : Person()
{
}

PokerPlayer::PokerPlayer(const std::string& n, const std::string& s) : Person(n,s)
{
}

PokerPlayer::PokerPlayer(const Person& p) : Person(p)
{
}


// Empty methods for avoiding double Get and Data in BadDude methods
void PokerPlayer::Data() const
{
}

void PokerPlayer::Get()
{
}

void PokerPlayer::Set()
{
	cout << "Enter pokerplayer's name: ";
	GetName();
	cout << "Enter pokerplayer's surname: ";
	GetSurname();
	Get();
}

void PokerPlayer::Show() const
{
	cout << "Category: PokerPlayer\n";
	Person::Data();
	Data();
}

Card PokerPlayer::Draw() const
{
	return Card();
}

PokerPlayer::~PokerPlayer()
{
	//cout << "PokerPlayer destroyed" << endl;
}

BadDude::BadDude() : Person(), Gunslinger(), PokerPlayer()
{

}

BadDude::BadDude(const std::string& n, const std::string& s,
	       	int notch, double t_r) : Person(n, s), Gunslinger(n,s,notch, t_r), PokerPlayer(n, s)
{

}

BadDude::BadDude(const Person& p, int notch, double t_r) : Person(p), Gunslinger(p, notch, t_r), PokerPlayer(p)
{

}

BadDude::BadDude(const Gunslinger& g) : Person(g), Gunslinger(g), PokerPlayer(g){
}

BadDude::BadDude(const PokerPlayer& p_p, 
		int notch, double t_r) : Person(p_p), Gunslinger(p_p, notch, t_r), PokerPlayer(p_p)
{
}

BadDude::~BadDude()
{
	//cout << "BadDude destroyed" << endl;
}

void BadDude::Draw() const
{
}

Card BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

double BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
}

void BadDude::Get()
{
	Gunslinger::Get();
	PokerPlayer::Get();
}

void BadDude::Show() const
{
	cout << "Category: BadDude\n";
	Person::Data();
	Data();
}

void BadDude::Set()
{

	cout << "Enter baddude's name: ";
	GetName();
	cout << "Enter baddude's surname: ";
	GetSurname();
	Get();
}
