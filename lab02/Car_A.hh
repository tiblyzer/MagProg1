#pragma once
#include <string>
#include <iostream>

//ősosztály
class Car {
public:
	std::string getRendszam() const { return this->rendszam; }
	int         getLoero() const { return this->loero; }

	void setRendszam(std::string r) {
		this->rendszam = r;
	}

	void setLoero(int l) {
		this->loero = l;
	}

	friend std::ostream& operator << (std::ostream& s, const Car& A) {
		s << A.getRendszam() << " " << A.getLoero() << std::endl;
		return s;
	}
//a származtatott osztályok számára hozzáférhetővé tesszük ezeket a változokat protected-del.
protected:
	std::string rendszam;
	int loero;
	int ulesszam;
	std::string marka;
	std::string fajta;
};

//származtatott osztály
class Mercedes : public Car { //fontos hogy az ősosztály elé megadjuk a láthatóságot; itt public lesz. 
public:
	Mercedes(bool s = true, bool u = true, bool sz = true) : savtarto(s), ulesfutes(u), szivargyujto(sz) {}
	void PrintAdvancedFeatures();
private:
	bool savtarto;
	bool ulesfutes;
	bool szivargyujto;
};

//származtatott osztály
class Audi : public Car {
public:
	Audi(bool p = true, bool h = true) : pohartarto(p), holtter_figyelo(h) {}
	void PrintAdvancedFeatures();
private:
	bool pohartarto;
	bool holtter_figyelo;
};


