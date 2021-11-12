#include "string2.h"


int String::num_strings = 0;

String::String(){
	this->len = this->capacity = 1;
	this->str = new char[this->capacity];
	this->str[this->len - 1] = '\0';
	++num_strings;
}

String::String(const char* str_){
	this->len = this->capacity = (std::strlen(str_) + 1);
	this->str = new char[this->capacity];
	std::strcpy(this->str, str_);
	++num_strings;
}

String::String(const String& other){
	this->len = other.len;
	this->capacity = other.capacity;
	this->str = new char[this->capacity];
	std::strcpy(this->str, other.str);
	++num_strings;
}

String::~String(){
	delete[] str;
	--num_strings;
}

String& String::operator=(const String& other){
	if(this == &other){
		// Assignment with current object
		return *this;
	}
	delete [] this->str;
	this->capacity = other.capacity;
	this->len = other.len;
	this->str = new char[other.capacity];
	std::strcpy(this->str, other.str);
	return *this;
}

String& String::operator=(const char* ptr){
	if(this->str == ptr){
		return *this;
	}
	delete [] this->str;
	this->len = this->capacity = (std::strlen(ptr) + 1);
	this->str = new char[this->capacity];
	std::strcpy(this->str, ptr);
	return *this;
}

char& String::operator[] (int i){
	return this->str[i];
}

const char& String::operator[] (int i) const {
	return this->str[i];
}

String& String::operator+=(char s){
	if(this->len == this->capacity){
		char* ptr = new char[(this->capacity *= 2)];
		std::strcpy(ptr, this->str);
		delete [] this->str;
		this->str = ptr;
	}
	// len - 1 - null symbol
	this->str[len - 1] = s;
	this->str[len++] = '\0';
	return *this;
}

String String::operator+(const String& other) const{
	String result;
	delete [] result.str;
	result.len = this->len + other.len - 1;
	result.capacity = result.len;
	result.str = new char[result.capacity];
	std::strcpy(result.str, this->str);
	std::strcpy(&result.str[this->len - 1], other.str);
	return result;
}

void String::stringlow(){
	for(int i = 0; i < this->len; ++i){
		this->str[i] = std::tolower(this->str[i]);
	}
}


void String::stringup(){
	for(int i = 0; i < this->len; ++i){
		this->str[i] = std::toupper(this->str[i]);
	}
}

int String::has(char s) const{
	int counter = 0;
	for(int i = 0; i < this->len; ++i){
		if(this->str[i] == s)
			++counter;
	}
	return counter;
}

bool operator<(const String& st1, const String& st2){
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2){
	return (strcmp(st1.str, st2.str) > 0);
}

bool operator==(const String& st1, const String& st2){
	return (strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st){
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st){
	String temp;
	char symbol;
	if(is){
		st = temp;
	} 
	while(is && (symbol = is.get()) != '\n'){
		st += symbol;
	}
	return is;
}

int String::HowMany(){
	return num_strings;
}

String String::operator+(const char * ptr) const {
	String result;
	delete [] result.str;
	result.len = this->len + std::strlen(ptr);
	result.capacity = result.len;
	result.str = new char[result.capacity];
	std::strcpy(result.str, this->str);
	std::strcpy(&result.str[this->len - 1], ptr);
	return result;
}

String operator+(const char* ptr, const String& st){
	String result;
	delete [] result.str;
	int size = std::strlen(ptr);
	result.len = st.len + size;
	result.capacity = result.len;
	result.str = new char[result.capacity];
	std::strcpy(result.str, ptr);
	std::strcpy(&result.str[size], st.str);
	return result;
}
