#include "TextFileHandler.hh"

void IO::TextFileHandler::Read(std::stringstream& data, unsigned long int numberofBytes)
{
	if (used == 1) {
		std::string buff;
		std::getline(file, buff);
		data.str("");
		data.str(buff);

		//file >> buff;
		//data.str(buff);
	}
}

void IO::TextFileHandler::Write(std::stringstream& data)
{
	if (used == 1) {
		file << data.str();
	}
}
