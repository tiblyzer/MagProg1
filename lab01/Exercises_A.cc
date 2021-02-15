#include <iostream>
#include <sstream>
#include <fstream>

#include "Mercedes.hh"

enum class Test {
	T_CASE1,
	T_CASE2,
	T_CASE3
};

//itt megneztuk, hogy peldanyositottuk a megirt Mercedes osztalyunkat
//lefuttattuk az implementalt metodusokat is.
void demoCreateMercedes()
{
	int n = 1;
	Mercedes M1, M2;
	M2.setRendszam("AHF-076");
	M2.modifyValue(n);
	std::cout << n << std::endl;
	std::cout << M1 << std::endl; //itt teszteltuk az implementalt kiirato operatorunkat
}

//itt demonstraltuk kivételkezeléssel együtt hogyan használható az enum class
void demoEnumClass()
{
	int test_value = 0;
	try {
		if (!test_value) throw Test::T_CASE1;    //throw-val dobunk kivetelt
		if (test_value < 0) throw Test::T_CASE2;
		if (test_value > 0) throw Test::T_CASE3;
	}
	catch (Test& e) { //vizsgaljuk a dobott kivetelt; a tipusa Test, ez az enum class neve
		switch (e) {
		case Test::T_CASE1: { 
			std::cerr << "CASE 1 exception is occured!\n";
			break;
		}
		case Test::T_CASE2: {
			std::cerr << "CASE 2 exception is occured!\n";
			break;
		}
		case Test::T_CASE3: {
			std::cerr << "CASE 3 exception is occured!\n";
			break;
		}
		default: {
			std::cerr << "undefined exception is occured!\n";
		}
		}
	}
}

//itt egy rovid peldat neztunk meg stringstream hasznalatra es fajlkezelesre
void demoIOHandling()
{
	std::ifstream inputfile;
	std::ofstream outputfile;
	std::string input;
	std::stringstream convert;
	inputfile.open("input.txt", std::ios_base::in);

	unsigned char c = 0;
	double value_d = 0.0;
	int value_i1 = 0, value_i2 = 0;
	std::string s1 = "", s2 = "";

	inputfile >> s1 >> value_i1 >> s2 >> value_i2;

	inputfile.seekg(std::ios_base::beg);
	//a getline uj sor karakterig ('\n') olvassa ki az egesz sort a fajlbol
	while (std::getline(inputfile, input)) {
		convert.str(input); //az egeszet berakjuk a streambe

		convert >> s1 >> value_i1 >> s2 >> value_d; // kiolvassuk az egyes valtozokat, a >> operator szokozig olvas, ezert pont megkapjuk a valtozoink erteket
		std::cout << s1 << value_i1 << s2 << value_d;
		convert.str(""); //minden esetben ures sztring-gel felulirjuk a stringstream tartalmat, hogy ne maradjanak benne az elozo ertekek.
	}

}

int main() {
	demoCreateMercedes();
	demoEnumClass();
	demoIOHandling();
	return 0;
}