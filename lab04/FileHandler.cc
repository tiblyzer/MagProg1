#include "FileHandler.hh"


void IO::FileHandler::Open(std::string path, IO::Mode fMode)
{
	switch (fMode)
	{
	case READ: {
		file.open(path.c_str(), std::ios::in);
		used = true;
		break;
	}
	case WRITE: {
		file.open(path.c_str(), std::ios::out);
		used = true;
		break;
	}
	case READWRITE: {
		file.open(path.c_str());
		used = true;
		break;
	}
	default: {
		;
	}
	}
}
void IO::FileHandler::Close()
{
	if (used == 1) {
		file.close();
		used = false;
	}
}