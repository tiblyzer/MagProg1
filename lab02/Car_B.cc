#include "Car_B.hh"

Car::Car(std::string r, int l, int u, std::string m, std::string f)
{
	std::cout << "Car constructor has been called.\n";
	rendszam = r;
	loero = l;
	ulesszam = u;
	marka = m;
	fajta = f;
}