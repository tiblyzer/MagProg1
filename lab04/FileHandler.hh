#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

namespace IO {

	typedef unsigned char Mode;
	typedef unsigned char Type;
	typedef char          FileFlag;
	typedef int           DWord;

	typedef std::ifstream inputfile;
	typedef std::ofstream outputfile;
	typedef std::fstream  iofile;

	enum FileFormat {
		TXT,
		BIN
	};

	enum OpenMode {
		READ,
		WRITE,
		READWRITE
	};

	class FileHandler
	{
	public:
		FileHandler() = default;
		FileHandler(const FileHandler&) = delete;

		void Open(std::string path, Mode fMode);
		void Close();

		virtual void Read(std::stringstream& data, unsigned long int numberofBytes) = 0;
		virtual void Write(std::stringstream& data) = 0;


		virtual ~FileHandler() { if (used) Close(); }
	protected:
		FileFlag used;
		iofile   file;
	};

}