#pragma once

#include "FileHandler.hh"

namespace IO {
	class BinFileHandler : public FileHandler
	{
	public:
		BinFileHandler() = default;
		BinFileHandler(const std::string path, Mode m) : FileHandler() { Open(path, m); }

		void Read(std::stringstream& data, unsigned long int numberofBytes);
		void Read(char* data, unsigned long int numberofBytes);
		void Write(std::stringstream& data);
		void Write(const char* data, unsigned long int numberofBytes);

		~BinFileHandler() = default;
	};
}

