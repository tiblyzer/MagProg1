#pragma once

#include "FileHandler.hh"

namespace IO {
	class TextFileHandler: public FileHandler
	{
	public:
		TextFileHandler() = default;
		TextFileHandler(const std::string path, Mode m) : FileHandler() { Open(path, m); }

		void Read(std::stringstream& data, unsigned long int numberofBytes);
		void Write(std::stringstream& data);
		void Print() const { ; }
	};
}



