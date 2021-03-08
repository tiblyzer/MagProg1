#include "BinFileHandler.hh"

void IO::BinFileHandler::Read(char* data, unsigned long int numberofBytes)
{
	if (used == 1) {
		file.read(data, numberofBytes);
	}
}

void IO::BinFileHandler::Read(std::stringstream& data, unsigned long int numberofBytes)
{
	if (used == 1) {
		char* buff = nullptr;
		file.read(buff, numberofBytes);
		data.str(std::string(buff));
		
		if (buff) delete [] buff;
	}
}

void IO::BinFileHandler::Write(std::stringstream& data)
{
	if (used == 1) {
		file.write(data.str().c_str(), data.str().size());
	}
}

void IO::BinFileHandler::Write(const char* data, unsigned long int numberofBytes)
{
	file.write(data, numberofBytes);
}