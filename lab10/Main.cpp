#include <iostream>
#include <list>

#include "Document.hh"

int main() {
	std::list<int> l;

	l.push_back(5);
	l.push_back(3);
	l.push_back(2);
	l.push_front(4);

	for (auto element : l) {
		std::cout << element << std::endl;
	}

	Document d;
	d.read("inputtext");

	std::cout << d << std::endl;

	d.swapLines(2, 3);
	std::cout << d << std::endl;

	return 0;
}