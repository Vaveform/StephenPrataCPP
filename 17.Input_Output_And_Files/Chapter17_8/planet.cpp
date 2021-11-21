#include "planet.h"

Planet::Planet() : population(0), g(0.0){
	name[0] = '\0';
}
std::ostream& Planet::BinaryOut(std::ostream& os) const {
	os.write(reinterpret_cast<const char*>(this), sizeof(*this));
	return os;
}
std::istream& Planet::BinaryIn(std::istream& is){
	// Checking empty file
	if(is.peek() == EOF) {is.get(); return is;}
	is.read(reinterpret_cast<char*>(this), sizeof(*this));
	return is;
}
std::ostream& Planet::TextOut(std::ostream& os) const
{
	if(is_interface)
	{
		os << "Planet " << std::setw(LIM) << std::left << std::setfill('*') << name;
		os << " has population " 
			<< population 
			<< " and gravity constant " 
			<< std::fixed << std::setprecision(4) << g;
	}
	else{
		os << name << " " << population << " " << g;
	}
	return os;
}
std::istream& Planet::TextIn(std::istream& is){
	if(is_interface) std::cout << "Enter planet name: ";
	// '\n' - delim by default and delim was not throwed from input stream
	char delim = '\n';
	is.get(name, LIM, delim);
	// eat line
	eat_line(is);
	if(is_interface) std::cout << "Enter size of population: ";
	is >> population;
	if(!is){
		population = 0;
		is.clear();
	}
	if(is_interface) std::cout << "Enter gravity constant for this planet: ";
	is >> g;
	if(!is)
	{
		g = 0.0;
		is.clear();
	}
	return is;
}

bool Planet::is_interface = false;

void Planet::SetUserFriendly(){
	is_interface = true;
}

void Planet::UnsetUserFriendly()
{
	is_interface = false;
}

void eat_line(std::istream& is, char delim){
	char readed_byte;
	while(is.get(readed_byte) && readed_byte != delim){}
}
