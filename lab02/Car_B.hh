#pragma once

#include <string>
#include <iostream>

class Car
{
public:
	//a this onmagara mutato mutatot jelent. Lenyege, hogy a peldanyositott osztalyra mutat, ezzel erjuk el a letrehozott objektumunk elemeit.
	Car(std::string r="", int l=0, int u=0, std::string m ="", std::string f=""); // konstruktor, hosszabb alak, amelyet mi irunk meg kulon forrasfajlban
	~Car() = default; // a fordito altal felkinalt destruktor definiciot jelenti, amit elfogadunk 

	std::string getRendszam() const { return this->rendszam; } //lekerdezo metodus, get-tel jelezzuk a neveben, visszaadja a rendszam erteket
	int         getLoero() const { return this->loero; }       //lekerdezo metodus, get-tel jelezzuk a neveben, visszaadja a rloero erteket

	void setRendszam(std::string r) { //beallito metodus, set-tel kezdjuk a nevet, beallitja a rendszam erteket
		this->rendszam = r;
	}

	void setLoero(int l) {
		this->loero = l;
	}

	friend std::ostream& operator << (std::ostream& s, const Car& A) {
		s << A.getRendszam() << " " << A.getLoero() << std::endl;
		return s;
	}

protected:
	std::string rendszam;
	int loero;
	int ulesszam;
	std::string marka;
	std::string fajta;
};

class Audi : public Car {
public:
	Audi(bool t = true, bool p = true) : tolatoradar(t), panoramaablak(p) { std::cout << "Audi constructor has been called.\n"; }

	void PrintFeatures() {
		std::cout << "Basic attributes: \n"
			<< "loero: " << loero
			<< "\nAdditional attributes: \n"
			<< "tolatoradar: " << tolatoradar
			<< "\npanoramaablak: " << panoramaablak
			<< std::endl;
	}
private:
	bool tolatoradar;
	bool panoramaablak;
};

class Mercedes: public Car {
public:
	Mercedes(bool u = true, bool o = true) : ulesfutes(u), osszkerekhajtas(o) { std::cout << "Mercedes constructor has been called.\n"; }

	void PrintFeatures() {
		std::cout << "Basic attributes: \n"
			<< "loero: " << loero
			<< "\nAdditional attributes: \n"
			<< "ulesfutes: " << ulesfutes
			<< "\nosszkerekhajtas: " << osszkerekhajtas
			<< std::endl;
	}
private:
	bool ulesfutes;
	bool osszkerekhajtas;
};

