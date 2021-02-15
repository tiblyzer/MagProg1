#include <iostream>

#include "Mercedes.hh"


struct Arucikk{
	unsigned int db;
	 int ar;
};

Arucikk operator + (const Arucikk A1, const Arucikk A2) {
	Arucikk A;
	A.db = A1.db + A2.db;
	A.ar = A1.ar + A2.ar;
	return A;
}

std::ostream& operator << (std::ostream& s, const Arucikk& A) {
	return s << A.db << " " << A.ar << std::endl;
}


enum Arak {
	N1,
	N2 = 8,
	N3,
	N4 = 4,
	N5,
	N6,
	N7,
	A1
};

enum class Test {
	A1,
	N1
};



int main() {
	Arucikk A1, A2;
	MagProg1::Mercedes M();

	A1.db = 3;
	A1.ar = Arak::A1;

	A2.db = 2;
	A2.ar = 1000;

	std::cout << A1 << std::endl;
	std::cout << A1 + A2 << std::endl;
	std::cerr << "Error...";
}

