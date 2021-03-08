#include "FileHandler.hh"
#include "BinFileHandler.hh"
#include "TextFileHandler.hh"

void demoHandleFile(IO::FileHandler* f, IO::Type t)
{
	switch (t)
	{
	case IO::TXT:
	{
		std::string test("test string");
		int         number = 5;
		float      floatNumber = 4.58;
		std::stringstream buffer;
		IO::TextFileHandler* textFile = reinterpret_cast<IO::TextFileHandler*>(f);
		
		textFile->Print();
		buffer << test << std::endl << number << std::endl << floatNumber << std::endl;
		
		textFile->Open("data.txt", IO::OpenMode::WRITE);
		textFile->Write(buffer);
		textFile->Close();
		break;
	}
	case IO::BIN:
	{
		std::string test("test string");
		int         number = 5;
		float       floatNumber = 4.58;
		std::stringstream buffer;
		IO::BinFileHandler* binFile = reinterpret_cast<IO::BinFileHandler*>(f);

		buffer << test << std::endl << number << std::endl << floatNumber << std::endl;

		binFile->Open("data.bin", IO::OpenMode::WRITE);
		binFile->Write(buffer);
		binFile->Write(reinterpret_cast<char*>(&number), sizeof(int)); 
		binFile->Write(reinterpret_cast<char*>(&floatNumber), sizeof(int));
		binFile->Close();
		break;
	}
	default: {
		;
	}
	}
}

int main()
{
	IO::TextFileHandler textFile("P.TXT",IO::READ);
	IO::BinFileHandler  binFile;

	demoHandleFile(&textFile, IO::FileFormat::TXT);
	demoHandleFile(&binFile, IO::FileFormat::BIN);
	
	int a[5];
	
	IO::TextFileHandler* tomb;
	tomb = new IO::TextFileHandler[5]();
	
	delete [] tomb;
	return 0;
}