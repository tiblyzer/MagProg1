#pragma once
#include <iostream>
#include <string>

namespace MagProg1 { //sajat nevteret hozunk letre
	class Mercedes_B //osztalynev
	{
	public: //lathatosag beallitasa, ami public, az elerheto osztalyon kivul is
		// konstruktor, rövidebb alak default értékadással, amelyet itt irunk meg a definicioban.
		Mercedes_B(std::string a = "", std::string r = "", int l = 0, bool enable = false, bool t = false) : alvazszam(a), rendszam(r), loero(l), isEnable(enable), turbo(t) {}
		~Mercedes_B() = default; // a fordito altal felkinalt destruktor definiciot jelenti, amit elfogadunk 

		std::string getAlvazszam()              const { return alvazszam; } //lekerdezo metodus, get-tel jelezzuk a neveben, visszaadja az alvazszamm erteket
		void        setAlvazszam(std::string a)       { alvazszam = a; }    // beallito metodus, set-tel kezdjuk a nevet, beallitja az alvazszam erteket

	private: //lathatosag, a private jelentese, hogy csak osztalyon belul erjuk el ezeket a reszeket!
		std::string alvazszam;
		std::string rendszam;
		int loero;
		bool isEnable;
		bool turbo;
	};
}


