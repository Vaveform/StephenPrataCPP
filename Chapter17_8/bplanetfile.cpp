#include "bplanetfile.h"
// This class working with fstream object(aggregation) and fstream
// should be opened with ios_base::in, ios_base::out and ios_base::binary
size_t BinaryPlanetFile::CountRecords(){
	last_number_records = 0;
	file.seekg(0);
	Planet buffer_planet;
	while(buffer_planet.BinaryIn(file)){
		last_number_records++;
	};
	file.clear();
	return last_number_records;
}
BinaryPlanetFile::BinaryPlanetFile(const char* filen) : file_path(filen)
{
	file.open(file_path.c_str(), std::ios_base::out | std::ios_base::app);
	file.close();
	file.open(file_path.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::binary);
	if(!file.is_open())
		throw std::invalid_argument("File was not opened");
	// badbid and failbit of basic_istream will be generate exceptions
	// file.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	CountRecords();
}
void BinaryPlanetFile::CurrentContent(){
	if(last_number_records == 0){ return; }
	last_number_records = 0;
	// seekg method to set pointer 
	// of basic_isream (file) for reading
	file.seekp(0); // reading from the beggining of the file with data
	// Cycle for reading data from binary file
	Planet buffer_planet;
	// seekg automatically goes to eof
	while(buffer_planet.BinaryIn(file))
	{
		std::cout << ++last_number_records << ": ";
		Planet::SetUserFriendly();
		buffer_planet.TextOut(std::cout) << std::endl;			
	}
	if(file.eof()) file.clear();
	else{
		throw "Something goes wrong";
	}
}
void BinaryPlanetFile::AppendRecord(){
	file.seekg(last_number_records * sizeof(Planet));
	Planet::SetUserFriendly();
	Planet inserted_planet;
	inserted_planet.TextIn(std::cin);
	inserted_planet.BinaryOut(file).clear();
	last_number_records++;
}
void BinaryPlanetFile::ChangeRecord(size_t Record_Num){
	if(Record_Num > 0 && Record_Num <= last_number_records)
	{
		std::cout << "Enter data for changing record " << Record_Num << std::endl;
		file.seekg((Record_Num - 1) * sizeof(Planet)); // seekg - setting position for writing to basic_ostream
		Planet changed_record;
		Planet::SetUserFriendly();
		changed_record.TextIn(std::cin);
		changed_record.BinaryOut(file).clear();
	}
}
void BinaryPlanetFile::ClearFile(){
	file.close();
	file.open(file_path.c_str(), 
			std::ios_base::in | std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
	if(!file.is_open()){
		std::cerr << "Cannot to clear file" << std::endl;
		throw std::invalid_argument("File not found");
	}
}

