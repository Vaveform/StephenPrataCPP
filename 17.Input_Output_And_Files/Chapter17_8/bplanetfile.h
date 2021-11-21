#ifndef BPLANETFILE_H_
#define BPLANETFILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <iomanip>
#include "planet.h"

class BinaryPlanetFile
{
	private:
		std::string file_path;
		std::fstream file;
		size_t last_number_records = 0;
		size_t CountRecords();	
	public:
	BinaryPlanetFile(const char* filen); 
	void CurrentContent();	
	void AppendRecord();
	void ChangeRecord(size_t Record_Num);
	void ClearFile();
};

#endif
