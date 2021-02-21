/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
	// az ablak kezdopontjainak koordinatai a monitoron
	// elso a vizszintes a masodik a fuggoleges iranyt jelenti.
	Graph_lib::Point tl{ 500,100 };
	
	//parameterek: 
	//kezdopont koordinatakat tartalmazo pont osztaly neve, ami itt t1
	//a masodik és harmadik ertekek az ablak mereteit jelentik vizszintes es fuggoleges iranyban
	//az utolso a cimsorban megjeleno szoveg
	Simple_window win{ tl,1280,800,"Test" };

	//ezzel rajzoltatjuk ki az ablakot
	win.wait_for_button();// give control to the display engine
   
    return 0;
}
