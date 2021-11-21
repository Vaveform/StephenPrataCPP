#ifndef WINE_H_
#define WINE_H_

#include <string>
#include <valarray>
#include <iostream>
#include <utility>

template<typename Class1, typename Class2>
struct Pair
{
	// Array of years;
	Class1 first;
	// Array of number of bottles;
	Class2 second;
};



// Explicit specialization of the template
// Definition of the methods should be in .h
template<>
struct Pair<std::valarray<int>, std::valarray<int>>
{
	std::valarray<int> first;
	std::valarray<int> second;
	size_t Size() const { return first.size();}
	int sum() const { return second.sum(); }
	Pair(){};
	Pair(int y, const int yr[], const int bot[]) : first(yr, y), second(bot, y){}
	explicit Pair(int y) : first(y), second(y){}
};

//Pair<std::valarray<int>, std::valarray<int>>::Pair(){
//}
//
//Pair<std::valarray<int>, std::valarray<int>>::Pair(int y, const int yr[], const int bot[]) : first(yr, y), second(bot, y){}
//
//Pair<std::valarray<int>, std::valarray<int>>::Pair(int y) : first(y), second(y){}



namespace {
	using ArrayInt = std::valarray<int>;
	using PairArray = Pair<ArrayInt, ArrayInt>;
	//typedef std::valarray<int> ArrayInt;
	//typedef Pair<ArrayInt, ArrayInt> PairArray;
};



class Wine : private std::string, private PairArray
{
	public:
		// Using sum method of PairArray
		using PairArray::sum;
		Wine();
		Wine(const char* l, int y, const int yr[], const int bot[]);
		Wine(const char*l, int y);
		~Wine();
		const std::string& Label() const;
		//int sum() const;
		void GetBottles();
		void Show() const;
};




#endif
