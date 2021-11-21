#ifndef PEOPLE_H_
#define PEOPLE_H_

#include <string>
#include <iostream>

// Abstract class Person
class Person
{
	private:
		std::string name;
		std::string surname;
	protected:
		virtual void Data() const;
		virtual void Get() = 0;
		void GetName();
		void GetSurname();
	public:
		Person();
		Person(const std::string& n, const std::string& s);
		// Pure virtual methods
		virtual ~Person();
		virtual void Show() const = 0;
		virtual void Set() = 0;
};

class Gunslinger : virtual public Person
{
	private:
		int notches;
		double time_ready;
	protected:
		void Data() const;
		void Get();
	public:
		Gunslinger();
		Gunslinger(const std::string& n, const std::string& s, 
				int notch, double t_r);
		Gunslinger(const Person& p, int notch = 0, double t_r = 0.0);
		~Gunslinger();
		void Show() const;
		void Set();
		// Draw return time_ready 
		double Draw() const;
};

class Card
{
	public:
		enum{spades, hearts, diamonds, clubs, other};
		Card();
		Card(int _suit, int _number);
		friend std::ostream& operator<<(std::ostream& os, const Card& c);
	private:
		// String representation
		static const int NumberTypes = 5;
		static std::string Suits[NumberTypes];
		int suit;
		int number;
};

class PokerPlayer : virtual public Person
{
	protected:
		void Data() const;
		void Get();
	public:
		PokerPlayer();
		PokerPlayer(const std::string& n, const std::string& s);
		PokerPlayer(const Person& p);
		Card Draw() const;
		void Show() const;
		void Set();
		~PokerPlayer();
};

class BadDude : public Gunslinger, public PokerPlayer
{
	private:
		// Domination rule - hidding parent methods 
		// Card PokerPlayer::Draw() const
		// and double Ganslinger::Draw() const to
		// prevent ambiguity
		void Draw() const;
	protected:
		void Data() const;
		void Get();
	public:
		BadDude();
		~BadDude();
		BadDude(const std::string& n, const std::string& s, 
				int notch, double t_r);
		BadDude(const Person& p, int notch = 0, double t_r = 0.0);
		BadDude(const Gunslinger& g);
		BadDude(const PokerPlayer& p_p, int notch = 0, double t_r = 0.0);
		Card Cdraw() const;
		double Gdraw() const;
		void Show() const;
		void Set();


};


#endif
