#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>


class Document
{
public:
	void read(std::string path);
	void swapLines(int n1, int n2);
	std::list<std::string> getLines() const { return lines; }
	
	friend std::ostream& operator << (std::ostream& s, const Document d) {
		for (auto line : d.getLines()) {
			s << line << std::endl;
		}

		return s;
	}
private:
	std::list<std::string> lines;
};

