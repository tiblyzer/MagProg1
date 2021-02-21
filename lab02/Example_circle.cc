/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
	//using namespace Graph_lib;
	Graph_lib::Point tl{ 500,100 };// to become top left corner of window
	Simple_window win{ tl,1280,800,"Test" };// make a simple window

	//kor peldanyositasa
	//az elso ket parameter a kor kozeppontja
	//a hamradik  parameter a sugara lesz
	Graph_lib::Circle c(Point{ 100,100 }, 50);

	//a kor kitoltesi szinenek megadasa
	poly.set_fill_color(Color::green);

	win.attach(c);	
	
	win.wait_for_button();
	
	return 0;
}
