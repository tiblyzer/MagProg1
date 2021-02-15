#pragma once

#include <iostream>
#include <string>

class Mercedes_A   //osztalynev
{
public:  //lathatosag beallitasa, ami public, az elerheto osztalyon kivul is
	Mercedes_A() = default; // a fordito altal felkinalt konstruktor definiciot jelenti, amit elfogadunk 
	Mercedes_A(std::string r, int l, int u, std::string m, std::string f); // konstruktor, hosszabb alak, amelyet mi irunk meg kulon forrasfajlban
	~Mercedes_A() = default; // a fordito altal felkinalt destruktor definiciot jelenti, amit elfogadunk 

	//a this onmagara mutato mutatot jelent. Lenyege, hogy a peldanyositott osztalyra mutat, ezzel erjuk el a letrehozott objektumunk elemeit.
	std::string getRendszam() const { return this->rendszam; } //lekerdezo metodus, get-tel jelezzuk a neveben, visszaadja a rendszam erteket
	int         getLoero() const { return this->loero; }       //lekerdezo metodus, get-tel jelezzuk a neveben, visszaadja a rloero erteket

	void setRendszam(std::string r) { //beallito metodus, set-tel kezdjuk a nevet, beallitja a rendszam erteket
		this->rendszam = r;
	}

	//pelda egy osztalymetodusra
	void modifyValue(int& n) {
		n *= 2;
	}

	// pelda operatortulterhelesre; a kiiro operatornak irtuk meg a sajat valtozatat a Mercedes osztalyra
	// friend: azert szukseges, mert mas az operatorunk tipusa mint az osztaly, es osztalydefinicion belul vagyunk.
	//         Megmondjuk a forditonak, hogy nem tipushiba es eliras tortent, fogadja el.
	// referenciatipus: azert fontos, hogy az eredeti stream-be irjuk bele az ertekeket, ne egy lokalis masolt verzioba.
	friend std::ostream& operator << (std::ostream& s, const Mercedes_A& M) {
		s << M.getRendszam() << " " << M.getLoero() << std::endl;
		return s;
	}


private: //lathatosag, a private jelentese, hogy csak osztalyon belul erjuk el ezeket a reszeket!
	std::string rendszam;
	int loero;
	int ulesszam;
	std::string marka;
	std::string fajta;
};

