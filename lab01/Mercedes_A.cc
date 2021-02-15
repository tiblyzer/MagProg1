#include "Mercedes_A.hh"


//konstruktor, hosszabb alak kulon forrasfajlban, default kezdoertekadas nelkul
Mercedes_A::Mercedes_A(std::string r, int l, int u, std::string m, std::string f)
{
	rendszam = r;
	loero = l;
	ulesszam = u;
	marka = m;
	fajta = f;
}