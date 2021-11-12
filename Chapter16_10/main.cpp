#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>
#include <cstring>

struct Review
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);
bool cheaperThan(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);

// Shared pointer version
bool operator<(std::shared_ptr<Review> r1, 
		std::shared_ptr<Review> r2);

bool worseThanPtr(std::shared_ptr<Review> r1,
		std::shared_ptr<Review> r2);

bool cheaperThanPtr(std::shared_ptr<Review> r1,
		std::shared_ptr<Review> r2);

bool FillReviewPtr(std::shared_ptr<Review> rr);

void ShowReviewPtr(std::shared_ptr<Review> rr);

int main()
{
	using namespace std;
	// We saving more memeory, by using vectors with shareed_ptrs 
	// overloading operator
	// for shared_ptr and some operations.
	// Attention!!! Overloading function can not be used!!!!
	// because we passed by pointer function to for_each function
	// and compiler can not recognized (unresolved overloaded function)
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp(new Review);
	while(FillReviewPtr(temp)){
		books.push_back(temp);
		temp = make_shared<Review>();
	}
	vector<shared_ptr<Review>> sorted_by_titles;
	vector<shared_ptr<Review>> sorted_by_rating;
	vector<shared_ptr<Review>> sorted_by_price;
	if(books.size() > 0)
	{
		copy(books.begin(), books.end(), back_inserter(sorted_by_titles));
		sort(sorted_by_titles.begin(), sorted_by_titles.end());

		copy(books.begin(), books.end(), back_inserter(sorted_by_rating));
		sort(sorted_by_rating.begin(), sorted_by_rating.end(), worseThanPtr);

		copy(books.begin(), books.end(), back_inserter(sorted_by_price));
		sort(sorted_by_price.begin(), sorted_by_price.end(), cheaperThanPtr);

		cout << "Thank you. You entered the following "
			<< books.size() << " ratings:\n";
		//for_each(books.begin(), books.end(), ShowReview);
		//sort(books.begin(), books.end());
		//cout << "Sorted by title:\nPrice\tRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);
		//sort(books.begin(), books.end(), worseThan);
		//cout << "Sorted by rating:\nPrice\tRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);
		//random_shuffle(books.begin(), books.end());
		//cout << "After shuffling:\nPrice\tRating\tBook\n";
		//for_each(books.begin(), books.end(), ShowReview);
		while(true){
			char choice;
			cout << "Enter information representation:\n"
				<< "c: original order\n"
				<< "t: sorting by title(ascending order)\n"
				<< "y: sorting by title(descending order)\n"
				<< "u: sorting by rating(ascending order)\n"
				<< "i: sorting by rating(descending order)\n"
				<< "g: sorting by price(ascending order)\n"
				<< "r: sorting by price(descending order)\n"
				<< "q: for quit\n";
			cin >> choice;
			while(strchr("ctyuigrq", choice) == NULL)
			{
				cout << "Please enter a t,y,u,i,g,r or q: ";
				cin >> choice;
			}
			if(choice == 'q')
				break;
			switch(choice)
			{
				case 'c':cout << "Original order:\nPrice\tRating\tBook\n";
					 for_each(books.begin(),
							 books.end(),
							 ShowReviewPtr);
					 break;
				case 't':cout << "Sorted by title(ascending order):\nPrice\tRating\tBook\n";
					for_each(sorted_by_titles.begin(),
							  sorted_by_titles.end(),
							  ShowReviewPtr);
					break;
				case 'y': cout << "Sorted by title(descending order):\nPrice\tRating\tBook\n";
					for_each(sorted_by_titles.rbegin(),
							  sorted_by_titles.rend(),
							  ShowReviewPtr);
					break;
				case 'u': cout << "Sorted by rating(ascending order):\nPrice\tRating\tBook\n";
					for_each(sorted_by_rating.begin(),
							  sorted_by_rating.end(),
							  ShowReviewPtr);
					break;
				case 'i': cout << "Sorted by rating(descending order):\nPrice\tRating\tBook\n";
					for_each(sorted_by_rating.rbegin(),
							  sorted_by_rating.rend(),
							  ShowReviewPtr);
					break;
				case 'g':cout << "Sorted by price(ascending order):\nPrice\tRating\tBook\n";
					for_each(sorted_by_price.begin(),
							  sorted_by_price.end(),
							  ShowReviewPtr);
					break;
				case 'r':cout << "Sorted by price(descending order):\nPrice\tRating\tBook\n";
					for_each(sorted_by_price.rbegin(),
							  sorted_by_price.rend(),
							  ShowReviewPtr);
					break;
			}
		}

	}
	else
		cout << "No entries. ";
	cout << "Bye.\n";
	return 0;
}

bool operator<(const Review& r1, const Review& r2)
{
	if(r1.title < r2.title)
		return true;
	else if(r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else if(r1.title == r2.title && r1.rating == r2.rating && r1.price < r2.price)
		return true;
	else
		return false;
}

bool worseThan(const Review& r1, const Review& r2)
{
	if(r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool cheaperThan(const Review& r1, const Review& r2)
{
	if(r1.price < r2.price)
		return true;
	else
		return false;
}

bool FillReview(Review& rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if(rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if(!std::cin)
		return false;

	while(std::cin.get() != '\n')
		continue;
	std::cout << "Enter book price: ";
	std::cin >> rr.price;
	if(!std::cin)
		return false;

	while(std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review& rr)
{
	std::cout << rr.price << "\t" << rr.rating << "\t" << rr.title << std::endl;
}



bool operator<(std::shared_ptr<Review> r1, 
		std::shared_ptr<Review> r2)
{
	return operator<(*r1.get(), *r2.get());
}


bool worseThanPtr(std::shared_ptr<Review> r1,
		std::shared_ptr<Review> r2)
{
	return worseThan(*r1.get(), *r2.get());
}

bool cheaperThanPtr(std::shared_ptr<Review> r1,
		std::shared_ptr<Review> r2)
{
	return cheaperThan(*r1.get(), *r2.get());
}


bool FillReviewPtr(std::shared_ptr<Review> rr)
{
	return FillReview(*rr.get());
}

void ShowReviewPtr(std::shared_ptr<Review> rr)
{
	ShowReview(*rr.get());
}


